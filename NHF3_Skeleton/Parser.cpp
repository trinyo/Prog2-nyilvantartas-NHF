#include "Parser.h"
#include "Szemely.h"

Parser::Parser() {}
Parser::~Parser() {}
void Parser::beolvas(std::string file) {}
void Parser::mentes(std::string file) {}
void Parser::hozzaad(Szemely* uj) {}
Szemely* Parser::keresKodAlapjan(std::string k) { return 0; }
bool Parser::torol(std::string k) { return false; }
int Parser::getMeret() const { return 0; }
void Parser::listazMindenkit() {}
void Parser::listazHallgatok() {}
void Parser::listazOktatok() {}
void Parser::listazPZH_Kotelezettek() {}
void Parser::listazOsztondijasok() {}
void Parser::listazCsoportAlapjan(std::string cs) {}
void Parser::listazTanszekAlapjan(std::string tszk) {}
void Parser::listazKivaloStatuszuak() {}