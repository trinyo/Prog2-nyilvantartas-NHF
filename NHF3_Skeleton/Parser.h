#ifndef PARSER_H
#define PARSER_H
#include <string>
#include "Szemely.h"

class Parser {
public:
  Parser();
  ~Parser();
  void beolvas(std::string file);
  void mentes(std::string file);
  void hozzaad(Szemely* uj);
  Szemely* keresKodAlapjan(std::string k);
  bool torol(std::string k);
  int getMeret() const;
  void listazMindenkit();
  void listazHallgatok();
  void listazOktatok();
  void listazPZH_Kotelezettek();
  void listazOsztondijasok();
  void listazCsoportAlapjan(std::string cs);
  void listazTanszekAlapjan(std::string tszk);
  void listazKivaloStatuszuak();
};

#endif