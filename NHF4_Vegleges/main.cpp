#include "Menu.h"
#include "Parser.h"
#include <iostream>

#include "memtrace.h"

#ifndef CPORTA
int main() {
  Parser adatbazis;
  adatbazis.beolvas("test_data.csv");
  Menu foMenu(adatbazis);
  foMenu.start();
  return 0;
}
#endif
