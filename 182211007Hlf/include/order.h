//
// Created by ckyf2023 on 23-4-22.
//

#ifndef UNTITLED_ORDER_H
#define UNTITLED_ORDER_H

#endif //UNTITLED_ORDER_H

#include <iostream>

class Order
{
    unsigned short time, team, label, arg;
    char motion;
public:
    Order();
    void inputOrder();
    char getMotion() const;
    unsigned short getTime() const;
    unsigned short getTeam() const;
    unsigned short getLabel() const;
    unsigned short getArg() const;

};
