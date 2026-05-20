#ifndef HALLGATO_H
#define HALLGATO_H

#include "Szemely.h"
#include <vector>
#include <ostream>

/**
 * @class Hallgato
 * @brief Hallgatoi nyilvantartas adatait kezelo osztaly.
 *
 * Leszarmaztatott osztaly a Szemely alaposztalybol.
 * Tarolja a hallgatoi specifikus adatokat: szak, felev, ZH pontok, stb.
 */
class Hallgato : public Szemely {
protected:
  std::string szak; ///< Szak megnevezese
  int felev; ///< Felev szam
  int hianyzas; ///< Hianyzasok szama
  std::vector<double> zhPontok; ///< ZH pontok listaja
  double nzh; ///< Nelso ZH pontszam
  double vizsga; ///< Vizsgapontszam
  bool osztondij; ///< Jogosult osztondijara
  std::string statusz; ///< Hallgatoi statusz
  int extra_pont; ///< Extra pontok
  std::string megjegyzes; ///< Megjegyzes

public:
  /**
   * @brief Konstruktor
   * @param n Nev
   * @param k Kod
   * @param e Email
   * @param szak Szak megnevezese
   * @param felev Felev szam
   * @param zhSzam ZH-k szama
   */
  Hallgato(std::string n, std::string k, std::string e, std::string sz, int felev, int zhSzam);

  /**
   * @brief Konstruktor
   * @param szak Szak megnevezese
   * @param felev Felev szam
   * @param zhSzam ZH-k szama
   */
  Hallgato(std::string szak, int felev, int zhSzam);

  /// Adatok kiirasa a konzolra
  virtual void kiir() const;
  virtual void kiir(std::ostream& out) const;

  /**
   * @brief ZH pont hozzaadasa
   * @param p Pontszam
   */
  void addZH(double p);

  /// @brief Osztondij beallitasa
  void setOsztondij(bool o);

  /// @return Nelso ZH pontszam
  double getNzh() const;
  void setNzh(double n);

  /// @return Osztondij jogosultsag
  bool getOsztondij() const;

  /// @return Statusz
  std::string getStatusz() const;

  void setEmail(std::string e);
  void setFelev(int f);
  void setStatusz(std::string s);
  void setVizsga(double v);
  void setHianyzas(int h);
};
#endif
