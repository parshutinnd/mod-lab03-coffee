#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <pthread.h>
#include <iostream>
#include <string>
#include <map>

enum class states {
    Off,
    Wait,
    Accept,
    Check,
    Cook,
};


class Automata
{
private:
    int cash;
    std::map<std::string, unsigned> menu;
    states state;   
public:
    Automata();
    Automata(std::map<std::string, unsigned>);

    states getState();
    unsigned getCash();
    void getMenu();
    
    void on();
    void off();
    void coin(int);
    void choise();
    void check(std::string);
    void canscel();
    void cook();
    void finish();

    void start();
};
#endif  // INCLUDE_AUTOMATA_H_