#include "Hallgato.h"

Hallgato::Hallgato(std::string n, std::string k, std::string e, std::string sz, int fv, int zh) : Szemely(n, k, e) {}
Hallgato::Hallgato(std::string sz, int fv, int zh) : Szemely("", "", "") {}
Hallgato::~Hallgato() {}
void Hallgato::kiir() const {}
void Hallgato::addZH(double p) {}
void Hallgato::setOsztondij(bool o) {}
double Hallgato::getNzh() const { return 0; }
bool Hallgato::getOsztondij() const { return false; }
std::string Hallgato::getStatusz() const { return ""; }