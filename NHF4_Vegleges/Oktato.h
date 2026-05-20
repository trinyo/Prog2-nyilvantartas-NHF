#ifndef OKTATO_H
#define OKTATO_H
#include "Szemely.h"
#include <string>
#include <ostream>

class Oktato : public Szemely {
protected:
  std::string titulus;
  std::string tanszek;
  std::string iroda;
  std::string targy;
  std::string konzultacio;
  int maxCsop;

public:
  /**
   * @brief Konstruktor
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
  Oktato(std::string n, std::string k, std::string e, std::string tit, std::string tszk,
       std::string iro, std::string tg, std::string konz, int max);

  /**
   * @brief Konstruktor
   * @param tit Titulus
   * @param tszk Tanszek
   * @param iro Iroda
   * @param tg Targy
   * @param konz Konzultacio
   * @param max Max csoport
   */
  Oktato(std::string tit, std::string tszk, std::string iro,
         std::string tg, std::string konz, int max);
  virtual ~Oktato();
  virtual void kiir() const;
  virtual void kiir(std::ostream& out) const;
  std::string getTanszek() const;

  void setEmail(std::string e);
  void setTanszek(std::string ts);
  void setIroda(std::string i);
  void setTargy(std::string t);
};
#endif