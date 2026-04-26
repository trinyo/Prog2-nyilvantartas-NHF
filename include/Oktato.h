#ifndef OKTATO_H
#define OKTATO_H

#include <string>

/**
 * @class Oktato
 * @brief Oktatoi nyilvantartas adatait kezelo osztaly.
 *
 * Tarolja az oktatoi specifikus adatokat: titulus, tanszek, iroda, stb.
 */
class Oktato {
private:
  std::string titulus; ///< Oktatoi titulus (pl. Dr., Prof.)
  std::string tanszek; ///< Tanszek neve
  std::string iroda; ///< Iroda szama
  std::string targy; ///< Oktatott targy
  std::string konzultacio; ///< Konzultacios ido
  int maxCsop; ///< Max csoportszam

public:
  /**
   * @brief Konstruktor
   * @param titulus Oktatoi titulus
   * @param tanszek Tanszek neve
   * @param iroda Iroda szama
   * @param targy Oktatott targy
   * @param konzultacio Konzultacios ido
   * @param maxCsop Max csoportszam
   */
  Oktato(std::string titulus, std::string tanszek, std::string iroda,
         std::string targy, std::string konzultacio, int maxCsop);

  /// Destruktor
  virtual ~Oktato();

  /// Adatok kiirasa a konzolra
  virtual void kiir();

  /// @return Tanszek neve
  std::string getTanszek() const;
};
#endif
