#ifndef PARSER_H
#define PARSER_H

#include "Szemely.h"
#include <vector>
#include <string>

class Parser {
  std::vector<Szemely*> adatok;
  void sorFeldolgoz(std::string sor);

public:
  Parser() = default;
  ~Parser();

  void beolvas(std::string file);
  void mentes(std::string file);
  void hozzaad(Szemely* uj);
  Szemely* keresKodAlapjan(std::string k);
  bool torol(std::string k);
  void listazMindenkit();
  void listazHallgatok();
  void listazOktatok();
  void listazPZH_Kotelezettek();
  void listazOsztondijasok();
  void listazCsoportAlapjan(std::string cs);
  void listazTanszekAlapjan(std::string tszk);
  void listazKivaloStatuszuak();

  int getMeret() const { return (int)adatok.size(); }
};
#endif