/**
 * @file Parser.cpp
 * @brief Parser osztaly tagfuggvenyeinek megvalositasa.
 *        Beolvasas, tarolas, kereses es listazas funkciok.
 */

#include "../include/Parser.h"
#include "../include/Hallgato.h"
#include "../include/Oktato.h"
#include "../include/memtrace.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

/**
 * @brief Segedfv - string feldarabolas kulcs:ertek parokra.
 * @param sor Feldolgozando sor
 * @param parok Kulcs:Ertek parok vektora (kimenet)
 */
void splitSor(const std::string& sor, std::vector<std::pair<std::string, std::string> >& parok) {
    parok.clear();
    std::istringstream ss(sor);
    std::string item;
    while (std::getline(ss, item, ';')) {
        size_t pos = item.find(':');
        if (pos != std::string::npos) {
            parok.push_back(std::make_pair(item.substr(0, pos), item.substr(pos + 1)));
        }
    }
}

/**
 * @brief Ertek keresese kulcs alapjan a parok vektorban.
 * @param parok Kulcs:Ertek parok vektora
 * @param kulcs Keresendo kulcs
 * @return Ertek vagy ures string
 */
std::string getErtek(const std::vector<std::pair<std::string, std::string> >& parok, const std::string& kulcs) {
    for (size_t i = 0; i < parok.size(); i++) {
        if (parok[i].first == kulcs) return parok[i].second;
    }
    return "";
}

/**
 * @brief Sor feldolgozasa - CSV sorbol szemely letrehozasa.
 * @param sor Feldolgozando CSV sor
 */
void Parser::sorFeldolgoz(std::string sor) {
    std::vector<std::pair<std::string, std::string> > parok;
    splitSor(sor, parok);

    std::string tipus = getErtek(parok, "Tipus");
    std::string nev = getErtek(parok, "Nev");
    if (nev.empty()) nev = getErtek(parok, "nev");
    std::string kod = getErtek(parok, "Kod");
    std::string email = getErtek(parok, "Email");
    std::string titulus = getErtek(parok, "Titulus");
    std::string tanszek = getErtek(parok, "Tanszek");
    std::string iroda = getErtek(parok, "Iroda");
    std::string targy = getErtek(parok, "Targy");
    std::string konzultacio = getErtek(parok, "Konzultacio");
    std::string maxCsopStr = getErtek(parok, "Max_Csoport");
    int maxCsop = maxCsopStr.empty() ? 0 : std::atoi(maxCsopStr.c_str());
    std::string szak = getErtek(parok, "Szak");
    std::string felevStr = getErtek(parok, "Felev");
    int felev = felevStr.empty() ? 0 : std::atoi(felevStr.c_str());
    std::string nzhStr = getErtek(parok, "NZH");
    double nzh = nzhStr.empty() ? 0 : std::atof(nzhStr.c_str());
    std::string vizsgaStr = getErtek(parok, "Vizsga");
    double vizsga = vizsgaStr.empty() ? 0 : std::atof(vizsgaStr.c_str());
    std::string hianyzasStr = getErtek(parok, "Hianyzas");
    int hianyzas = hianyzasStr.empty() ? 0 : std::atoi(hianyzasStr.c_str());
    std::string osztondijStr = getErtek(parok, "Osztondij");
    std::string statusz = getErtek(parok, "Statusz");

    if (tipus == "Oktato") {
        Oktato* o = new Oktato(nev, kod, email, titulus, tanszek, iroda, targy, konzultacio, maxCsop);
        for (size_t i = 0; i < parok.size(); i++) {
            if (parok[i].first == "Csoport") {
                o->addCsoport(parok[i].second);
            }
        }
        hozzaad(o);
    } else if (tipus == "Hallgato") {
        if (szak.empty() || felev <= 0) {
            std::cerr << "HIBA: ervenytelen hallgato adatok" << std::endl;
            return;
        }
        int zhSzam = 0;
        for (size_t i = 0; i < parok.size(); i++) {
            if (parok[i].first == "ZH") zhSzam++;
        }
        if (zhSzam == 0) zhSzam = 5;
        Hallgato* h = new Hallgato(nev, kod, email, szak, felev, zhSzam);
        int zhIndex = 0;
        for (size_t i = 0; i < parok.size(); i++) {
            if (parok[i].first == "ZH" && zhIndex < zhSzam) {
                h->addZH(std::atof(parok[i].second.c_str()));
                zhIndex++;
            } else if (parok[i].first == "Csoport") {
                h->addCsoport(parok[i].second);
            }
        }
        h->setNzh(nzh);
        h->setVizsga(vizsga);
        h->setHianyzas(hianyzas);
        if (osztondijStr == "Igen" || osztondijStr == "igen") {
            h->setOsztondij(true);
        }
        if (!statusz.empty()) {
            h->setStatusz(statusz);
        }
        hozzaad(h);
    } else {
        std::cerr << "HIBA: ismeretlen tipus: " << tipus << std::endl;
    }
}

/**
 * @brief Destruktor - memoria felszabaditasa.
 */
Parser::~Parser() {
    for (size_t i = 0; i < adatok.size(); i++) delete adatok[i];
}

/**
 * @brief Fajl beolvasasa.
 * @param file Fajl eleresi utja
 */
void Parser::beolvas(std::string file) {
    std::ifstream in(file.c_str());
    if (!in) {
        std::cerr << "HIBA: A file nem nyithato meg: " << file << std::endl;
        return;
    }
    std::string sor;
    while (std::getline(in, sor)) {
        if (sor.size() > 0) sorFeldolgoz(sor);
    }
    in.close();
}

/**
 * @brief Adatok mentese fajlba.
 * @param file Fajl eleresi utja
 */
void Parser::mentes(std::string file) {
    std::ofstream out(file.c_str());
    if (!out) {
        std::cerr << "HIBA: A file nem nyithato meg irasra: " << file << std::endl;
        return;
    }
    for (size_t i = 0; i < adatok.size(); i++) {
        if (adatok[i]) {
            Hallgato* h = dynamic_cast<Hallgato*>(adatok[i]);
            if (h) {
                h->kiir(out);
            } else {
                Oktato* o = dynamic_cast<Oktato*>(adatok[i]);
                if (o) {
                    o->kiir(out);
                }
            }
        }
    }
    out.close();
}

/**
 * @brief Uj szemely hozzaadasa a listahoz.
 * @param uj Uj szemely pointer
 */
void Parser::hozzaad(Szemely* uj) {
    adatok.push_back(uj);
}

/**
 * @brief Kereses kod alapjan.
 * @param k Keresendo kod
 * @return Talalt szemely pointer vagy 0
 */
Szemely* Parser::keresKodAlapjan(std::string k) {
    for (size_t i = 0; i < adatok.size(); i++) {
        if (adatok[i] && adatok[i]->getKod() == k) return adatok[i];
    }
    return 0;
}

/**
 * @brief Torles kod alapjan.
 * @param k Torlendo kod
 * @return true ha sikerult, false ha nem talalt
 */
bool Parser::torol(std::string k) {
    for (size_t i = 0; i < adatok.size(); i++) {
        if (adatok[i] && adatok[i]->getKod() == k) {
            delete adatok[i];
            adatok.erase(adatok.begin() + i);
            return true;
        }
    }
    return false;
}

/**
 * @brief Osszes rekord listazasa.
 */
void Parser::listazMindenkit() {
    if (adatok.empty()) {
        std::cout << "\nNincs betoltott adat!" << std::endl;
        return;
    }
    for (size_t i = 0; i < adatok.size(); i++) {
        if (adatok[i]) adatok[i]->kiir();
    }
}

/**
 * @brief Osszes hallgato listazasa.
 */
void Parser::listazHallgatok() {
    if (adatok.empty()) {
        std::cout << "\nNincs betoltott adat!" << std::endl;
        return;
    }
    bool van = false;
    for (size_t i = 0; i < adatok.size(); i++) {
        Hallgato* h = dynamic_cast<Hallgato*>(adatok[i]);
        if (h) { h->kiir(); van = true; }
    }
    if (!van) std::cout << "\nNincs hallgato az adatok kozott!" << std::endl;
}

/**
 * @brief Osszes oktato listazasa.
 */
void Parser::listazOktatok() {
    if (adatok.empty()) {
        std::cout << "\nNincs betoltott adat!" << std::endl;
        return;
    }
    bool van = false;
    for (size_t i = 0; i < adatok.size(); i++) {
        Oktato* o = dynamic_cast<Oktato*>(adatok[i]);
        if (o) { o->kiir(); van = true; }
    }
    if (!van) std::cout << "\nNincs oktato az adatok kozott!" << std::endl;
}

/**
 * @brief PZH-ra kotelezett hallgatok listazasa.
 */
void Parser::listazPZH_Kotelezettek() {
    if (adatok.empty()) {
        std::cout << "\nNincs betoltott adat!" << std::endl;
        return;
    }
    bool van = false;
    for (size_t i = 0; i < adatok.size(); i++) {
        Hallgato* h = dynamic_cast<Hallgato*>(adatok[i]);
        if (h && h->getNzh() < 40) { h->kiir(); van = true; }
    }
    if (!van) std::cout << "\nNincs PZH-ra kotelezett hallgato!" << std::endl;
}

/**
 * @brief Osztondijas hallgatok listazasa.
 */
void Parser::listazOsztondijasok() {
    if (adatok.empty()) {
        std::cout << "\nNincs betoltott adat!" << std::endl;
        return;
    }
    bool van = false;
    for (size_t i = 0; i < adatok.size(); i++) {
        Hallgato* h = dynamic_cast<Hallgato*>(adatok[i]);
        if (h && h->getOsztondij()) { h->kiir(); van = true; }
    }
    if (!van) std::cout << "\nNincs osztondijas hallgato!" << std::endl;
}

/**
 * @brief Csoport alapjan szurt hallgatok listazasa.
 * @param cs Csoport szama
 */
void Parser::listazCsoportAlapjan(std::string cs) {
    if (adatok.empty()) {
        std::cout << "\nNincs betoltott adat!" << std::endl;
        return;
    }
    bool van = false;
    for (size_t i = 0; i < adatok.size(); i++) {
        if (adatok[i]) {
            for (size_t j = 0; j < adatok[i]->getCsoportSzam(); j++) {
                if (adatok[i]->getCsoport(j) == cs) {
                    adatok[i]->kiir();
                    van = true;
                    break;
                }
            }
        }
    }
    if (!van) std::cout << "\nNincs ilyen csoport!" << std::endl;
}

/**
 * @brief Tanszek alapjan szurt oktatok listazasa.
 * @param tszk Tanszek neve
 */
void Parser::listazTanszekAlapjan(std::string tszk) {
    if (adatok.empty()) {
        std::cout << "\nNincs betoltott adat!" << std::endl;
        return;
    }
    bool van = false;
    for (size_t i = 0; i < adatok.size(); i++) {
        Oktato* o = dynamic_cast<Oktato*>(adatok[i]);
        if (o && o->getTanszek() == tszk) { o->kiir(); van = true; }
    }
    if (!van) std::cout << "\nNincs ilyen tanszek!" << std::endl;
}

/**
 * @brief Kivalo statuszu hallgatok listazasa.
 */
void Parser::listazKivaloStatuszuak() {
    if (adatok.empty()) {
        std::cout << "\nNincs betoltott adat!" << std::endl;
        return;
    }
    bool van = false;
    for (size_t i = 0; i < adatok.size(); i++) {
        Hallgato* h = dynamic_cast<Hallgato*>(adatok[i]);
        if (h && h->getStatusz() == "kivalo") { h->kiir(); van = true; }
    }
    if (!van) std::cout << "\nNincs kivalo statuszu hallgato!" << std::endl;
}
