#include "../include/Menu.h"
#include "../include/Parser.h"
#include <iostream>

#include "../include/memtrace.h"

int main() {
  Parser adatbazis;
  Menu foMenu(adatbazis);
  foMenu.start();
  return 0;
}
