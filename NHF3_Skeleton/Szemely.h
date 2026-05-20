#ifndef SZEMELY_H
#define SZEMELY_H
#include <string>

class Szemely {
public:
  Szemely(std::string n, std::string k, std::string e);
  virtual ~Szemely();
  virtual void kiir() const = 0;
  void addCsoport(std::string cs);
  std::string getKod();
  size_t getCsoportSzam();
  std::string getCsoport(size_t i);
};

#endif