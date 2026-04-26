#ifndef PARSER_H
#define PARSER_H

#include "Szemely.h"
#include <cstddef>
#include <string>

/**
 * @class Parser
 * @brief Adatbazis kezelo osztaly.
 *
 * Felelos a szemelyi adatok beolvasasaert, tarolasaert, kezeleseert.
 * Dinamikusan kezeli a memoriat, szuk eseten bovit a kapacitason.
 */
class Parser {
  Szemely **adatok; ///< Szemelyek tomble
  size_t kapacitas; ///< Jelenlegi kapacitas
  size_t meret; ///< Tenyleges elemszam

  /// @brief Atmeretezes szukseg eseten
  void atmeretez();

  /// @brief Egy sor feldolgozasa
  /// @param sor Beolvasott sor
  void sorFeldolgoz(std::string sor);

public:
  /// Konstruktor
  Parser();

  /// Destruktor
  ~Parser();

  /**
   * @brief Adatok beolvasasa fajlbol
   * @param file Fajl eleres
   */
  void beolvas(std::string file);

  /**
   * @brief Adatok mentese fajlba
   * @param file Fajl eleres
   */
  void mentes(std::string file);

  /**
   * @brief Uj szemely hozzaadasa
   * @param uj Uj szemely pointer
   */
  void hozzaad(Szemely *uj);

  /**
   * @brief Szemely keresese kod alapjan
   * @param k Keresendo kod
   * @return Sikeres keresules eseten a szemely pointer, egyebkent null
   */
  Szemely *keresKodAlapjan(std::string k);

  /// Osszes szemely listazasa
  void listazasMindenkit();

  /// Csak hallgatok listazasa
  void listazHallgatok();

  /// Csak oktatok listazasa
  void listazOktatok();

  /// PZH-ra kotelezett hallgatok listaja
  void listaPZH_Kotelezettek();

  /// Osztondijas hallgatok listaja
  void listaOsztondijasok();

  /**
   * @brief Hallgatok listazasa csoport alapjan
   * @param cs Csoport neve
   */
  void listazCsoportAlapjan(std::string cs);

  /**
   * @brief Szemelyek listazasa tanszek alapjan
   * @param tszk Tanszek neve
   */
  void listazasTanszekAlapjan(std::string tszk);

  /// Kivalo statuszu hallgatok listaja
  void listazKivaloStatuszuak();
};
#endif // !PARSER_Hn
