#ifndef MENU_H
#define MENU_H

#include <string>

class Parser;
class Hallgato;
class Oktato;
class Szemely;

/**
 * @class Menu
 * @brief Felhasznaloi felulet kezelo osztaly.
 *
 * A menu rendszert megvalosito osztaly. Bekeri a felhasznalo
 * valaszait es meghivja a megfelelo Parser funkciokat.
 */
class Menu {
  Parser &parser;

  void displayMainMenu();
  void displayListMenu();
  void displayNewDataMenu();
  void displayDataManagementMenu();
  void clearScreen();
  void waitForEnter();

  void listMenuLoop();
  void newDataMenuLoop();
  void dataManagementMenuLoop();
  void fileMenuLoop();

public:
  Menu(Parser &p);
  void start();
};
#endif
