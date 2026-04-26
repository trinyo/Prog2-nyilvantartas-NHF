#include "../include/Menu.h"
#include "../include/Parser.h"
#include <stdio.h>
#include <iostream>

#include "../include/memtrace.h"
#include <stdio.h>

Menu::Menu(Parser &p) : parser(p) {}

void Menu::start() {
  int valasztas = -1;

  while (valasztas != 0) {
    clearScreen();
    displayMainMenu();
    if (!(std::cin >> valasztas)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      continue;
    }

    switch (valasztas) {
    case 1:
      displayListMenu();
      waitForEnter();
      break;
    case 2:
      displayNewDataMenu();
      waitForEnter();
      break;
    case 3:
      displayDataManagementMenu();
      waitForEnter();
      break;
    case 0:
      printf("\nkozonjuk, hogy hasznalta a programot!\n");
      break;
    default:
      printf("\nervenyten valasztoas. Probalkozzon ujra.\n");
      waitForEnter();
      break;
    }
  }
}

void Menu::displayMainMenu() {
  printf("==========================================\n");
  printf("|       hallgatoi nyilvantartas          |\n");
  printf("==========================================\n\n");

  printf("Valaszon menupontot a szamozott opciok kozul:\n\n");

  printf("[1]  listazas (adatok szurese, ranksorolasa)\n");
  printf("[2]  uj adat felvetele (hallgato/oktato rogzitese)\n");
  printf("[3]  informacio szerkesztese / torlese\n");
  printf("------------------------------------------\n");
  printf("[0]  kilepes a programbol\n\n");

  printf("Adja meg a valasztott szamot: ");
}

void Menu::displayListMenu() {
  printf("\n==========================================\n");
  printf("|            listazas menu               |\n");
  printf("==========================================\n");

  printf("\nvalasszon egy listazasi / elemzesi opciot:\n");

  printf("\n--- alap listak ---\n");
  printf("[11] osszes hallgatoi rekord listazasa\n");
  printf("[12] osszes oktatoi rekord listazasa\n");
  printf("[13] hallgatok listazasa csoport szerint (pl. G01)\n");
  printf("[14] hallgatok listazasa nzh szerint \n");
  printf("[15] hallgatok listazasa kzh szerint \n");
  printf("[16] hallgatok listazasa neptun szerint \n");

  printf("\n--- szures es pótlas ---\n");
  printf("[21] pzh-ra kotelezett hallgatok listaja (pot-zh)\n");

  printf("------------------------------------------\n");
  printf("[9]  vissza a fomenube\n\n");

  printf("Adja meg a valasztott szamot: ");
}

void Menu::displayNewDataMenu() {
  printf("\n==========================================\n");
  printf("|       uj adat felvetele menu           |\n");
  printf("==========================================\n\n");

  printf("Milyen tipusu uj rekordot szeretne felvenni?\n\n");

  printf("[1]  uj hallgato felvetele\n");
  printf("[2]  uj oktato felvetele\n");
  printf("------------------------------------------\n");
  printf("[9]  vissza a fomenube\n\n");

  printf("Adja meg a valasztott szamot: ");
}

void Menu::displayDataManagementMenu() {
  printf("\n==========================================\n");
  printf("|        adatkezelesi menu               |\n");
  printf("==========================================\n\n");

  printf("Milyen tipusu muveletet szeretne vegrehajtani?\n\n");

  printf("--- frissites ---\n");
  printf("[1]   hallgato adatainak frissitese\n");
  printf("[2]   oktato adatainak frissitese\n\n");

  printf("--- torles ---\n");
  printf("[3]   hallgato torlese a listabol\n");
  printf("[4]   oktato torlese a listabol\n");
  printf("------------------------------------------\n");

  printf("[9]  vissza a fomenube\n\n");

  printf("Adja meg a valasztott szamot: ");
}

void Menu::clearScreen() {
  const char *clearSeq = "\033[2J\033[H";
  printf("%s", clearSeq);
  fflush(stdout);
}

void Menu::waitForEnter() {
  printf("\nNyomd meg az ENTER billentyut a tovabblepéshez...");

  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }

  getchar();
}
