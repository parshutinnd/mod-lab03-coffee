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

void Automata::getMenu(){
    for (const auto& element : menu)
    std::cout << element.first << "\t" << element.second << std::endl;
}

void Automata::canscel(){
    this->state = states::Wait;
}

void Automata::coin(int value){
    this->state = states::Accept;
    this->cash += value;
}

void Automata::choise(){
    this->state = states::Check;
    
    std::string name;
    name = "coffee";
    Automata::check(name);
}

void Automata::cook(){
    this->state = states::Cook;
    this->finish();
}

void Automata::check(std::string name){
    if(this->cash >= this->menu[name]){
        this->state = states::Cook;
        this->cash -= this->menu[name];
        this->cook();
    } else {
        this->canscel();
    }
}

void Automata::finish(){
    this->state = states::Wait;
}

void Automata::start(){
    this->on();
    this->coin(10);
    this->choise();
    this->coin(10);
    this->choise();
    this->off();
}
