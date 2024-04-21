#include <iostream>
#include <gtest/gtest.h>
#include <Automata.h>

int main() {

    std::map<std::string,unsigned> menu;

    menu["coffee"] = 20;
    menu["tea"] = 15;

    Automata CoffeeMachine = Automata(menu);

    CoffeeMachine.start();
    

    return 0;
}