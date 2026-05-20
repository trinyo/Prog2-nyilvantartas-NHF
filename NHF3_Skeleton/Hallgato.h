#ifndef HALLGATO_H
#define HALLGATO_H
#include "Szemely.h"

class Hallgato : public Szemely {
public:
  Hallgato(std::string n, std::string k, std::string e, std::string sz, int felev, int zhSzam);
  Hallgato(std::string szak, int felev, int zhSzam);
  virtual ~Hallgato();
  virtual void kiir() const;
  void addZH(double p);
  void setOsztondij(bool o);
  double getNzh() const;
  bool getOsztondij() const;
  std::string getStatusz() const;
};

#endif