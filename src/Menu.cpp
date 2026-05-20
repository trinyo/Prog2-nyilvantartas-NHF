/**
 * @file Menu.cpp
 * @brief Menu osztaly tagfuggvenyeinek megvalositasa.
 *        Fomenu, listazasi, adatkezelesi es file muveletek.
 */

#include "../include/Menu.h"
#include "../include/Parser.h"
#include "../include/Hallgato.h"
#include "../include/Oktato.h"
#include "../include/Szemely.h"
#include "../include/memtrace.h"
#include <iostream>
#include <stdio.h>

/**
 * @brief Konstruktor.
 * @param p Parser referencia
 */
Menu::Menu(Parser &p) : parser(p) {}

/**
 * @brief Fomenu elinditasa es menu loop.
 */
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
      listMenuLoop();
      break;
    case 2:
      newDataMenuLoop();
      break;
    case 3:
      dataManagementMenuLoop();
      break;
    case 4:
      fileMenuLoop();
      break;
    case 0:
      printf("\nkozonjuk, hogy hasznalta a programot!\n");
      break;
    default:
      printf("\nervenyten valasztas. Probalkozzon ujra.\n");
      waitForEnter();
      break;
    }
  }
}

/**
 * @brief Listazas almenu loop.
 */
void Menu::listMenuLoop() {
  int val = -1;
  while (val != 9) {
    clearScreen();
    displayListMenu();
    if (!(std::cin >> val)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      continue;
    }

    switch (val) {
    case 11:
      parser.listazMindenkit();
      waitForEnter();
      break;
    case 12:
      parser.listazOktatok();
      waitForEnter();
      break;
    case 13:
      parser.listazHallgatok();
      waitForEnter();
      break;
    case 14: {
      printf("\nAdja meg a csoportot: ");
      std::string cs;
      std::cin >> cs;
      parser.listazCsoportAlapjan(cs);
      waitForEnter();
      break;
    }
    case 15: {
      printf("\nAdja meg a tanszeket: ");
      std::string ts;
      std::cin >> ts;
      parser.listazTanszekAlapjan(ts);
      waitForEnter();
      break;
    }
    case 16:
      parser.listazPZH_Kotelezettek();
      waitForEnter();
      break;
    case 17:
      parser.listazOsztondijasok();
      waitForEnter();
      break;
    case 18:
      parser.listazKivaloStatuszuak();
      waitForEnter();
      break;
    case 9:
      break;
    default:
      printf("\nervenyten valasztoas.\n");
      waitForEnter();
      break;
    }
  }
}

/**
 * @brief Uj adat felvetele almenu.
 */
void Menu::newDataMenuLoop() {
  clearScreen();
  displayNewDataMenu();
  int val;
  if (!(std::cin >> val)) {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "\nHIBA: Ervenytelen bemenet." << std::endl;
    waitForEnter();
    return;
  }

  if (val == 9)
    return;

  if (val == 1) {
    clearScreen();
    std::cout << "=== Uj hallgato felvetele ===" << std::endl << std::endl;

    std::string hallgatoNev;
    std::string hallgatoKod;
    std::string hallgatoEmail;
    std::string hallgatoSzak;
    std::string hallgatoCsoport;
    std::string osztondijValasz;
    int hallgatoFelev;
    const int ZH_SZAM = 5;

    std::cout << "Nev: ";
    if (!(std::cin >> hallgatoNev)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen nev." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Kod (neptun): ";
    if (!(std::cin >> hallgatoKod)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen kod." << std::endl;
      waitForEnter();
      return;
    }
    if (hallgatoKod.length() != 6) {
      std::cout << "\nHIBA: a kodnak 6 karakterbol kell allnia." << std::endl;
      waitForEnter();
      return;
    }
    if (parser.keresKodAlapjan(hallgatoKod) != 0) {
      std::cout << "\nHIBA: ez a kod mar letezik." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Email: ";
    if (!(std::cin >> hallgatoEmail)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen email." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Szak: ";
    if (!(std::cin >> hallgatoSzak)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen szak." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Felev (1-8): ";
    if (!(std::cin >> hallgatoFelev)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen felev." << std::endl;
      waitForEnter();
      return;
    }
    if (hallgatoFelev < 1 || hallgatoFelev > 8) {
      std::cout << "\nHIBA: a felev 1 es 8 kozott kell legyen." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Csoport: ";
    if (!(std::cin >> hallgatoCsoport)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen csoport." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Osztondij (Igen/Nem): ";
    if (!(std::cin >> osztondijValasz)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen valasz." << std::endl;
      waitForEnter();
      return;
    }

    Hallgato* ujHallgato = new Hallgato(hallgatoNev, hallgatoKod, hallgatoEmail, hallgatoSzak, hallgatoFelev, ZH_SZAM);
    ujHallgato->addCsoport(hallgatoCsoport);
    if (osztondijValasz == "Igen" || osztondijValasz == "igen") {
      ujHallgato->setOsztondij(true);
    }
    parser.hozzaad(ujHallgato);

    std::cout << "\nSikeres felvetel!" << std::endl;
    waitForEnter();
    return;
  }

  if (val == 2) {
    clearScreen();
    std::cout << "=== Uj oktato felvetele ===" << std::endl << std::endl;

    std::string oktatoNev;
    std::string oktatoKod;
    std::string oktatoEmail;
    std::string oktatoTitulus;
    std::string oktatoTanszek;
    std::string oktatoTargy;
    std::string oktatoIroda;
    std::string oktatoCsoport;
    int oktatoMaxCsoport;

    std::cout << "Nev: ";
    if (!(std::cin >> oktatoNev)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen nev." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Kod: ";
    if (!(std::cin >> oktatoKod)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen kod." << std::endl;
      waitForEnter();
      return;
    }
    if (parser.keresKodAlapjan(oktatoKod) != 0) {
      std::cout << "\nHIBA: ez a kod mar letezik." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Email: ";
    if (!(std::cin >> oktatoEmail)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen email." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Titulus (MSc/PhD): ";
    if (!(std::cin >> oktatoTitulus)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen titulus." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Tanszek: ";
    if (!(std::cin >> oktatoTanszek)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen tanszek." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Targy: ";
    if (!(std::cin >> oktatoTargy)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen targy." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Iroda: ";
    if (!(std::cin >> oktatoIroda)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen iroda." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Csoport: ";
    if (!(std::cin >> oktatoCsoport)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen csoport." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "Max csoport: ";
    if (!(std::cin >> oktatoMaxCsoport)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen ertek." << std::endl;
      waitForEnter();
      return;
    }

    Oktato* ujOktato = new Oktato(oktatoNev, oktatoKod, oktatoEmail, oktatoTitulus, oktatoTanszek, oktatoIroda, oktatoTargy, "", oktatoMaxCsoport);
    ujOktato->addCsoport(oktatoCsoport);
    parser.hozzaad(ujOktato);

    std::cout << "\nSikeres felvetel!" << std::endl;
    waitForEnter();
    return;
  }

  std::cout << "\nHIBA: Ervenytelen menupont." << std::endl;
  waitForEnter();
}

/**
 * @brief Adatkezelesi almenu (szerkesztes/torles).
 */
void Menu::dataManagementMenuLoop() {
  clearScreen();
  displayDataManagementMenu();

  int valasz;
  if (!(std::cin >> valasz)) {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "\nHIBA: ervenytelen bemenet." << std::endl;
    waitForEnter();
    return;
  }

  if (valasz == 9)
    return;

  if (parser.getMeret() == 0) {
    std::cout << "\nHIBA: nincs betoltott adat." << std::endl;
    waitForEnter();
    return;
  }

  if (valasz == 1 || valasz == 2) {
    clearScreen();
    std::cout << "=== Adat szerkesztese ===" << std::endl << std::endl;

    std::string keresendoKod;
    std::cout << "Adja meg a kodot: ";
    if (!(std::cin >> keresendoKod)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen kod." << std::endl;
      waitForEnter();
      return;
    }

    Szemely* talaltSzemely = parser.keresKodAlapjan(keresendoKod);
    if (talaltSzemely == 0) {
      std::cout << "\nHIBA: nem talalt." << std::endl;
      waitForEnter();
      return;
    }

    if (valasz == 1) {
      Hallgato* hallgatoPtr = dynamic_cast<Hallgato*>(talaltSzemely);
      if (hallgatoPtr == 0) {
        std::cout << "\nHIBA: ez nem hallgato." << std::endl;
        waitForEnter();
        return;
      }
      clearScreen();
      hallgatoPtr->kiir();
      std::cout << "=== Hallgato adatainak frissitese ===" << std::endl << std::endl;

      std::string ujEmail, ujCsoport, ujStatusz;
      int ujFelev;

      std::cout << "Uj email: ";
      if (!(std::cin >> ujEmail)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\nHIBA: ervenytelen email." << std::endl;
        waitForEnter();
        return;
      }

      std::cout << "Uj felev (1-8): ";
      if (!(std::cin >> ujFelev)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\nHIBA: ervenytelen felev." << std::endl;
        waitForEnter();
        return;
      }
      if (ujFelev < 1 || ujFelev > 8) {
        std::cout << "\nHIBA: a felev 1 es 8 kozott kell legyen." << std::endl;
        waitForEnter();
        return;
      }

      std::cout << "Uj csoport: ";
      if (!(std::cin >> ujCsoport)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\nHIBA: ervenytelen csoport." << std::endl;
        waitForEnter();
        return;
      }

      std::cout << "Uj statusz (aktiv/passziv/kivalo): ";
      if (!(std::cin >> ujStatusz)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\nHIBA: ervenytelen statusz." << std::endl;
        waitForEnter();
        return;
      }

      hallgatoPtr->setEmail(ujEmail);
      hallgatoPtr->setFelev(ujFelev);
      hallgatoPtr->setStatusz(ujStatusz);

      std::cout << "\nSikeres frissites!" << std::endl;
      waitForEnter();
      return;
    }

    if (valasz == 2) {
      Oktato* oktatoPtr = dynamic_cast<Oktato*>(talaltSzemely);
      if (oktatoPtr == 0) {
        std::cout << "\nHIBA: ez nem oktato." << std::endl;
        waitForEnter();
        return;
      }
      clearScreen();
      oktatoPtr->kiir();
      std::cout << "=== Oktato adatainak frissitese ===" << std::endl << std::endl;

      std::string ujEmail, ujTanszek, ujTargy, ujIroda;
      int ujMaxCsoport;

      std::cout << "Uj email: ";
      if (!(std::cin >> ujEmail)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\nHIBA: ervenytelen email." << std::endl;
        waitForEnter();
        return;
      }

      std::cout << "Uj tanszek: ";
      if (!(std::cin >> ujTanszek)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\nHIBA: ervenytelen tanszek." << std::endl;
        waitForEnter();
        return;
      }

      std::cout << "Uj targy: ";
      if (!(std::cin >> ujTargy)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\nHIBA: ervenytelen targy." << std::endl;
        waitForEnter();
        return;
      }

      std::cout << "Uj iroda: ";
      if (!(std::cin >> ujIroda)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\nHIBA: ervenytelen iroda." << std::endl;
        waitForEnter();
        return;
      }

      std::cout << "Uj max csoport: ";
      if (!(std::cin >> ujMaxCsoport)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\nHIBA: ervenytelen ertek." << std::endl;
        waitForEnter();
        return;
      }

      oktatoPtr->setEmail(ujEmail);
      oktatoPtr->setTanszek(ujTanszek);
      oktatoPtr->setTargy(ujTargy);
      oktatoPtr->setIroda(ujIroda);

      std::cout << "\nSikeres frissites!" << std::endl;
      waitForEnter();
      return;
    }
  }

  if (valasz == 3 || valasz == 4) {
    clearScreen();
    std::cout << "=== Adat torlese ===" << std::endl << std::endl;

    std::string torlendoKod;
    std::cout << "Adja meg a torlendo kodot: ";
    if (!(std::cin >> torlendoKod)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen kod." << std::endl;
      waitForEnter();
      return;
    }

    Szemely* talaltSzemely = parser.keresKodAlapjan(torlendoKod);
    if (talaltSzemely == 0) {
      std::cout << "\nHIBA: nem talalt." << std::endl;
      waitForEnter();
      return;
    }

    bool oktatoE = (dynamic_cast<Oktato*>(talaltSzemely) != 0);
    bool hallgatoE = (dynamic_cast<Hallgato*>(talaltSzemely) != 0);

    if (valasz == 3 && !hallgatoE) {
      std::cout << "\nHIBA: ez nem hallgato." << std::endl;
      waitForEnter();
      return;
    }
    if (valasz == 4 && !oktatoE) {
      std::cout << "\nHIBA: ez nem oktato." << std::endl;
      waitForEnter();
      return;
    }

    std::cout << "\nBiztosan torolja? (Igen/Nem): ";
    std::string megerosites;
    if (!(std::cin >> megerosites)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen valasz." << std::endl;
      waitForEnter();
      return;
    }

    if (megerosites != "Igen" && megerosites != "igen") {
      std::cout << "\nMegszabitva." << std::endl;
      waitForEnter();
      return;
    }

    if (parser.torol(torlendoKod)) {
      std::cout << "\nSikeres torles!" << std::endl;
    } else {
      std::cout << "\nHIBA: a torles nem sikerult." << std::endl;
    }
    waitForEnter();
    return;
  }

  std::cout << "\nHIBA: ervenytelen menupont." << std::endl;
  waitForEnter();
}

/**
 * @brief Fomenu kepernyore irasa.
 */
void Menu::displayMainMenu() {
  printf("==========================================\n");
  printf("|       hallgatoi nyilvantartas          |\n");
  printf("==========================================\n\n");

  printf("Valaszon menupontot a szamozott opciok kozul:\n\n");

  printf("[1]  listazas (adatok szurese, ranksorolasa)\n");
  printf("[2]  uj adat felvetele (hallgato/oktato rogzitese)\n");
  printf("[3]  informacio szerkesztese / torlese\n");
  printf("[4]  file muveletek (betoltes/mentes)\n");
  printf("------------------------------------------\n");
  printf("[0]  kilepes a programbol\n\n");

  printf("Adja meg a valasztott szamot: ");
}

/**
 * @brief Listazas menu kepernyore irasa.
 */
void Menu::displayListMenu() {
  printf("\n==========================================\n");
  printf("|            listazas menu               |\n");
  printf("==========================================\n");

  printf("\nvalasszon egy listazasi / elemzesi opciot:\n");

  printf("\n--- alap listak ---\n");
  printf("[11] osszes rekord\n");
  printf("[12] osszes oktato\n");
  printf("[13] osszes hallgato\n");

  printf("\n--- szures ---\n");
  printf("[14] csoport alapjan (hallgato)\n");
  printf("[15] tanszek alapjan (oktato)\n");
  printf("[16] pzh-ra kotelezett\n");
  printf("[17] osztondijas\n");
  printf("[18] kivalo statuszu\n");

  printf("------------------------------------------\n");
  printf("[9]  vissza a fomenube\n\n");

  printf("Adja meg a valasztott szamot: ");
}

/**
 * @brief Uj adat felvetele menu kepernyore irasa.
 */
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

/**
 * @brief Adatkezelesi menu kepernyore irasa.
 */
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

/**
 * @brief File muveletek almenu (betoltes/mentes).
 */
void Menu::fileMenuLoop() {
  clearScreen();
  std::cout << "=== File muveletek ===" << std::endl << std::endl;
  std::cout << "[1] Adatok betoltese fajlbol" << std::endl;
  std::cout << "[2] Adatok mentese fajlba" << std::endl;
  std::cout << "[9] Vissza" << std::endl << std::endl;

  int valasz;
  std::cout << "Valasztas: ";
  if (!(std::cin >> valasz)) {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "\nHIBA: ervenytelen bemenet." << std::endl;
    waitForEnter();
    return;
  }

  if (valasz == 9)
    return;

  if (valasz == 1) {
    std::string fajlNev;
    std::cout << "\nFajl neve: ";
    if (!(std::cin >> fajlNev)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen fajlnev." << std::endl;
      waitForEnter();
      return;
    }

    std::string projDir = __FILE__;
    projDir = projDir.substr(0, projDir.rfind("/src/main.cpp"));
    parser.beolvas(projDir + "/data/" + fajlNev);
    std::cout << "\nSikeres betoltes!" << std::endl;
    waitForEnter();
    return;
  }

  if (valasz == 2) {
    std::string fajlNev;
    std::cout << "\nFajl neve: ";
    if (!(std::cin >> fajlNev)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "\nHIBA: ervenytelen fajlnev." << std::endl;
      waitForEnter();
      return;
    }

    std::string projDir = __FILE__;
    projDir = projDir.substr(0, projDir.rfind("/src/main.cpp"));
    parser.mentes(projDir + "/data/" + fajlNev);
    std::cout << "\nSikeres mentes!" << std::endl;
    waitForEnter();
    return;
  }

  std::cout << "\nHIBA: ervenytelen menupont." << std::endl;
  waitForEnter();
}

/**
 * @brief Kepernyo torlese (ANSI escape szekvencia).
 */
void Menu::clearScreen() {
  const char *clearSeq = "\033[2J\033[H";
  printf("%s", clearSeq);
  fflush(stdout);
}

/**
 * @brief Billentyuvaras (ENTER) a menu folytatashoz.
 */
void Menu::waitForEnter() {
  printf("\nNyomd meg az ENTER billentyut a tovabblepeshez...");

  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }

  getchar();
}
