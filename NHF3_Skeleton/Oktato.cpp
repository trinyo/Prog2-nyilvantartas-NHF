#include "Oktato.h"

Oktato::Oktato(std::string n, std::string k, std::string e, std::string tit, std::string tszk,
               std::string iro, std::string tg, std::string konz, int max)
  : Szemely(n, k, e) {}
Oktato::Oktato(std::string tit, std::string tszk, std::string iro,
               std::string tg, std::string konz, int max)
  : Szemely("", "", "") {}
Oktato::~Oktato() {}
void Oktato::kiir() const {}
std::string Oktato::getTanszek() const { return ""; }