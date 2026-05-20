#include "../include/Menu.h"
#include "../include/Parser.h"
#include <iostream>

#include "../include/memtrace.h"

int main() {
  Parser adatbazis;
  std::string projDir = __FILE__;
  projDir = projDir.substr(0, projDir.rfind("/src/main.cpp"));
  adatbazis.beolvas(projDir + "/data/test_data.csv");
  Menu foMenu(adatbazis);
  foMenu.start();
  return 0;
}
