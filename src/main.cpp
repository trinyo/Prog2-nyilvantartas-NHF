#include <iostream>
#include "Menu.h"
#include "Parser.h"

int main() {
    Parser adatbazis;
    Menu foMenu(adatbazis);
    foMenu.start();
    return 0;
}
