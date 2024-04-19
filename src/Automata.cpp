#include "Automata.h"

Automata::Automata()
{
    this->cash = 0;
    this->state = states::Off;
}

Automata::Automata(std::map<std::string, unsigned> map)
{
    this->cash = 0;
    this->state = states::Off;
    this->menu = map;
}

void Automata::on()
{
    this->state = states::Wait;
}

void Automata::off(){
    this->state = states::Off;
}

states Automata::getState(){
    return this->state;
}

unsigned Automata::getCash(){
    return this->cash;
}

void Automata::canscel(){
    this->state = states::Wait;
}

void Automata::coin(int value){
    this->state = states::Accept;
    this->cash += value;
}

void Automata::choise(std::string name){
    this->state = states::Check;
    Automata::check(name);
}

void Automata::cook(){
    this->state = states::Cook;
    this->finish();
}

void Automata::check(std::string name){
    if(this->cash >= this->menu[name]){
        this->state = states::Cook;
        this->cook();
    } else {
        this->canscel();
    }
}

void Automata::finish(){
    this->state = states::Wait;
}

