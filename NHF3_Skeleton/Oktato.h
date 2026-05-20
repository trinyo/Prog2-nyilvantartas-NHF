#ifndef OKTATO_H
#define OKTATO_H
#include "Szemely.h"

class Oktato : public Szemely {
public:
  Oktato(std::string n, std::string k, std::string e, std::string tit, std::string tszk,
         std::string iro, std::string tg, std::string konz, int max);
  Oktato(std::string tit, std::string tszk, std::string iro,
         std::string tg, std::string konz, int max);
  virtual ~Oktato();
  virtual void kiir() const;
  std::string getTanszek() const;
};

#endif