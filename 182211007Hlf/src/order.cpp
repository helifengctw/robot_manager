//
// Created by ckyf2023 on 23-4-22.
//

#include "order.h"

Order::Order() {}
void Order::inputOrder()
{
    char a = 'A';
    unsigned short t = 0, b = 0, c = 0, d = 0;
    std::cin >> t >> a >> b >> c >> d;
    time = t; motion = a; team = b; label = c; arg = d;
}

char Order::getMotion() const {return motion;}
unsigned short Order::getTime() const {return time;}
unsigned short Order::getTeam() const {return team;}
unsigned short Order::getLabel() const {return label;}
unsigned short Order::getArg() const {return arg;}
