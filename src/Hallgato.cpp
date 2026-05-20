/**
 * @file Hallgato.cpp
 * @brief Hallgato osztaly tagfuggvenyeinek megvalositasa.
 */

#include "../include/Hallgato.h"
#include "../include/memtrace.h"
#include <iostream>

/**
 * @brief Konstruktor - alap konstruktor.
 * @param sz Szak
 * @param fv Felev szama
 * @param zh ZH-k szama
 */
Hallgato::Hallgato(std::string sz, int fv, int zh)
    : Szemely("", "", ""), szak(sz), felev(fv), hianyzas(0),
      zhPontok(zh, 0.0), nzh(0), vizsga(0), osztondij(false), statusz("aktiv"), extra_pont(0) {
}

/**
 * @brief Konstruktor - teljes konstruktor.
 * @param n Nev
 * @param k Kod
 * @param e Email
 * @param sz Szak
 * @param fv Felev szama
 * @param zh ZH-k szama
 */
Hallgato::Hallgato(std::string n, std::string k, std::string e, std::string sz, int fv, int zh)
    : Szemely(n, k, e), szak(sz), felev(fv), hianyzas(0),
      zhPontok(zh, 0.0), nzh(0), vizsga(0), osztondij(false), statusz("aktiv"), extra_pont(0) {
}

/**
 * @brief Hallgato adatainak kirasa a konzolra.
 */
void Hallgato::kiir() const {
    std::cout << "--- Hallgato ---" << std::endl;
    std::cout << "Nev: " << nev << std::endl;
    std::cout << "Kod: " << kod << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Szak: " << szak << std::endl;
    std::cout << "Felev: " << felev << std::endl;
    std::cout << "Hianyzas: " << hianyzas << std::endl;
    std::cout << "Csoportok: ";
    for (size_t i = 0; i < csoportok.size(); i++) {
        std::cout << csoportok[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "ZH pontok: ";
    for (size_t i = 0; i < zhPontok.size(); i++) {
        std::cout << zhPontok[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "NZH: " << nzh << std::endl;
    std::cout << "Vizsga: " << vizsga << std::endl;
    std::cout << "Osztondij: " << (osztondij ? "Igen" : "Nem") << std::endl;
    std::cout << "Statusz: " << statusz << std::endl;
    std::cout << std::endl;
}

void Hallgato::kiir(std::ostream& out) const {
    out << "Tipus:Hallgato;Nev:" << nev << ";Kod:" << kod
        << ";Szak:" << szak << ";Felev:" << felev
        << ";Email:" << email << ";NZH:" << nzh
        << ";Vizsga:" << vizsga << ";Osztondij:" << (osztondij ? "Igen" : "Nem")
        << ";Statusz:" << statusz << std::endl;
}

/**
 * @brief ZH pont hozzaadasa.
 * @param p Pontszam
 */
void Hallgato::addZH(double p) {
    for (size_t i = 0; i < zhPontok.size(); i++) {
        if (zhPontok[i] == 0) {
            zhPontok[i] = p;
            break;
        }
    }
}

/**
 * @brief NZH pontszam lekerese.
 * @return Nelso ZH pontszam
 */
double Hallgato::getNzh() const {
    return nzh;
}

void Hallgato::setNzh(double n) {
    nzh = n;
}

/**
 * @brief Osztondij jogosultsag lekerese.
 * @return Osztondij jogosultsag (true/false)
 */
bool Hallgato::getOsztondij() const {
    return osztondij;
}

/**
 * @brief Osztondij beallitasa.
 * @param o Osztondij jogosultsag
 */
void Hallgato::setOsztondij(bool o) {
    osztondij = o;
}

/**
 * @brief Statusz lekerese.
 * @return Hallgatoi statusz
 */
std::string Hallgato::getStatusz() const {
    return statusz;
}

/**
 * @brief Email beállítása.
 */
void Hallgato::setEmail(std::string e) { this->email = e; }

/**
 * @brief Felev beállítása.
 */
void Hallgato::setFelev(int f) { felev = f; }

/**
 * @brief Státusz beállítása.
 */
void Hallgato::setStatusz(std::string s) { statusz = s; }

void Hallgato::setVizsga(double v) { vizsga = v; }

void Hallgato::setHianyzas(int h) { hianyzas = h; }