#ifndef MENU_H
#define MENU_H

#include <string>

class Parser;

/**
 * @class Menu
 * @brief Felhasznaloi felulet kezelo osztaly.
 *
 * A menu rendszert megvalosito osztaly. Bekeri a felhasznalo
 * valaszait es meghivja a megfelelo Parser funkciokat.
 */
class Menu {
  Parser &parser; ///< Referencia a Parser-re

  /// Fomenu megjelenitese
  void displayMainMenu();

  /// Listazasi menu megjelenitese
  void displayListMenu();

  /// Uj adat felveteli menu megjelenitese
  void displayNewDataMenu();

  /// Adatkezelesi menu megjelenitese
  void displayDataManagementMenu();

  /// Képernyo torles
  void clearScreen();

  /// Enterre varakozas
  void waitForEnter();

public:
  /**
   * @brief Konstruktor
   * @param p Parser referencia
   */
  Menu(Parser &p);

  /// Foprogram inditasa
  void start();
};
#endif
