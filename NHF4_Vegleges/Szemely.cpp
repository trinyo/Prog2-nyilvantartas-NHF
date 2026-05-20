/**
 * @file Szemely.cpp
 * @brief Szemely osztaly tagfuggvenyeinek megvalositasa.
 */

#include "Szemely.h"
#include <iostream>
#include "memtrace.h"

/**
 * @brief Konstruktor - inicializálja a szemely adatait.
 * @param n Nev
 * @param k Kod
 * @param e Email
 */
Szemely::Szemely(std::string n, std::string k, std::string e)
    : nev(n), kod(k), email(e) {
}

/**
 * @brief Destruktor - felszabadítja a dinamikusan foglalt memóriát.
 */
Szemely::~Szemely() {}

/**
 * @brief Új csoport hozzáadása a személyhez.
 * @param cs Csoport neve
 */
void Szemely::addCsoport(std::string cs) {
  csoportok.push_back(cs);
}

/**
 * @brief Egyedi kód lekérése.
 * @return Egyedi azonosító kód
 */
std::string Szemely::getKod() { return kod; }

/**
 * @brief Csoportok számának lekérése.
 * @return Csoportok száma
 */
size_t Szemely::getCsoportSzam() { return csoportok.size(); }

/**
 * @brief Csoport lekérése index alapján.
 * @param i Index
 * @return Csoport neve vagy üres string
 */
std::string Szemely::getCsoport(size_t i) {
  if (i < csoportok.size())
    return csoportok[i];
  return "";
}

/**
 * @brief Név beállítása.
 */
void Szemely::setNev(std::string n) { nev = n; }

/**
 * @brief Email beállítása.
 */
void Szemely::setEmail(std::string e) { email = e; }

/**
 * @brief Kód beállítása.
 */
void Szemely::setKod(std::string k) { kod = k; }

/**
 * @brief Személy adatainak kiírása a konzolra.
 */
void Szemely::kiir() const {
  std::cout << "Nev: " << nev << std::endl;
  std::cout << "Kod: " << kod << std::endl;
  std::cout << "Email: " << email << std::endl;
  std::cout << "Csoportok: ";
  for (size_t i = 0; i < csoportok.size(); i++) {
    std::cout << csoportok[i] << " ";
  }
  std::cout << std::endl;
}
