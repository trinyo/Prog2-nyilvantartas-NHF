/**
 * @file Oktato.cpp
 * @brief Oktato osztaly tagfuggvenyeinek megvalositasa.
 */

#include "../include/Oktato.h"
#include "../include/memtrace.h"
#include <iostream>

/**
 * @brief Konstruktor - alap konstruktor.
 * @param tit Titulus
 * @param tszk Tanszek
 * @param iro Iroda
 * @param tg Targy
 * @param konz Konzultacio
 * @param max Max csoport
 */
Oktato::Oktato(std::string tit, std::string tszk, std::string iro,
               std::string tg, std::string konz, int max)
    : Szemely("", "", ""), titulus(tit), tanszek(tszk), iroda(iro), targy(tg),
      konzultacio(konz), maxCsop(max) {}

/**
 * @brief Konstruktor - teljes konstruktor.
 * @param n Nev
 * @param k Kod
 * @param e Email
 * @param tit Titulus
 * @param tszk Tanszek
 * @param iro Iroda
 * @param tg Targy
 * @param konz Konzultacio
 * @param max Max csoport
 */
Oktato::Oktato(std::string n, std::string k, std::string e, std::string tit,
               std::string tszk, std::string iro, std::string tg,
               std::string konz, int max)
    : Szemely(n, k, e), titulus(tit), tanszek(tszk), iroda(iro), targy(tg),
      konzultacio(konz), maxCsop(max) {}

/**
 * @brief Destruktor.
 */
Oktato::~Oktato() {}

/**
 * @brief Oktato adatainak kirasa a konzolra.
 */
void Oktato::kiir() const {
  std::cout << "--- Oktato ---" << std::endl;
  std::cout << "Nev: " << nev << std::endl;
  std::cout << "Kod: " << kod << std::endl;
  std::cout << "Email: " << email << std::endl;
  std::cout << "Titulus: " << titulus << std::endl;
  std::cout << "Tanszek: " << tanszek << std::endl;
  std::cout << "Iroda: " << iroda << std::endl;
  std::cout << "Targy: " << targy << std::endl;
  std::cout << "Konzultacio: " << konzultacio << std::endl;
  std::cout << "Csoportok: ";
  for (size_t i = 0; i < csoportok.size(); i++) {
    std::cout << csoportok[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Max csoport: " << maxCsop << std::endl;
  std::cout << std::endl;
}

void Oktato::kiir(std::ostream& out) const {
  out << "Tipus:Oktato;Nev:" << nev << ";Kod:" << kod
      << ";Titulus:" << titulus << ";Tanszek:" << tanszek
      << ";Iroda:" << iroda << ";Targy:" << targy
      << ";Email:" << email << std::endl;
}

/**
 * @brief Tanszek lekerese.
 * @return Tanszek neve
 */
std::string Oktato::getTanszek() const { return tanszek; }

/**
 * @brief Email beállítása.
 */
void Oktato::setEmail(std::string e) { this->email = e; }

/**
 * @brief Tanszek beállítása.
 */
void Oktato::setTanszek(std::string ts) { tanszek = ts; }

/**
 * @brief Iroda beállítása.
 */
void Oktato::setIroda(std::string i) { iroda = i; }

/**
 * @brief Tárgy beállítása.
 */
void Oktato::setTargy(std::string t) { targy = t; }
