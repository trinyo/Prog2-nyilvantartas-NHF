#ifndef HALLGATO_H
#define HALLGATO_H

#include "Szemely.h"

/**
 * @class Hallgato
 * @brief Hallgatoi nyilvantartas adatait kezelo osztaly.
 *
 * Leszarmaztatott osztaly a Szemely alaposztalybol.
 * Tarolja a hallgatoi specifikus adatokat: szak, felev, ZH pontok, stb.
 */
class Hallgato : public Szemely {
private:
  std::string szak; ///< Szak megnevezese
  int felev; ///< Felev szam
  int hianyzas; ///< Hianyzasok szama
  double *zhPontok; ///< ZH pontok tombje
  int zhSzam; ///< ZH-k szama
  double nzh; ///< Nelso ZH pontszam
  double vizsga; ///< Vizsgapontszam
  bool osztondij; ///< Jogosult osztondijara
  std::string statusz; ///< Hallgatoi statusz
  int extra_pont; ///< Extra pontok
  std::string megjegyzes; ///< Megjegyzes

public:
  /**
   * @brief Konstruktor
   * @param szak Szak megnevezese
   * @param felev Felev szam
   * @param zhSzam ZH-k szama
   */
  Hallgato(std::string szak, int felev, int zhSzam);

  /// Destruktor
  virtual ~Hallgato();

  /// Adatok kiirasa a konzolra
  virtual void kiir();

  /**
   * @brief ZH pont hozzaadasa
   * @param p Pontszam
   */
  void addZH(double p);

  /// @return Nelso ZH pontszam
  double getNzh() const;

  /// @return Osztondij jogosultsag
  bool getOsztondij() const;

  /// @return Statusz
  std::string getStatusz() const;
};
#endif
