#ifndef MENU_H
#define MENU_H

class Parser;

class Menu {
public:
  Menu(Parser& p);
  void start();
};

#endif