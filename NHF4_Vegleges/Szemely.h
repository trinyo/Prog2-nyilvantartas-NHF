#ifndef SZEMELY_H
#define SZEMELY_H
#include <vector>
#include <string>

/**
 * @class Szemely
 * @brief Alaposztaly a szemelyi adatok tarolasara.
 *
 * Ez az osztaly abstrakt, leszarmaztatott osztalyok (Hallgato, Oktato)
 * adjak meg a konkret megvalositast.
 */
class Szemely {
protected:
  std::string nev;        ///< Szemely neve
  std::string kod;        ///< Egyedi azonosito kod (pl. neptun)
  std::string email;      ///< Email cim
  std::vector<std::string> csoportok; ///< Csoportok listaja

public:
  /**
   * @brief Konstruktor
   * @param n Nev
   * @param k Kod
   * @param e Email
   */
  Szemely(std::string n, std::string k, std::string e);

  /// Destruktor
  virtual ~Szemely();

  /// Adatok kiirasa a konzolra
  virtual void kiir() const = 0;

  /**
   * @brief Uj csoport hozzaadasa
   * @param cs Csoport neve
   */
  void addCsoport(std::string cs);

  /// @return Egyedi kod
  std::string getKod();

  /// @return Csoportok szama
  size_t getCsoportSzam();

  /**
   * @brief Csoport lekerese index alapjan
   * @param i Index
   * @return Csoport neve
   */
  std::string getCsoport(size_t i);
  
  void setNev(std::string n);
  void setEmail(std::string e);
  void setKod(std::string k);
};
#endif
