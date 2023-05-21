//
// Created by ckyf2023 on 23-4-17.
//

#ifndef UNTITLED_SOLDIER_H
#define UNTITLED_SOLDIER_H

#include <iostream>
#include "Robot.h"

class Soldier : public Robot
{
    unsigned short heatUpBound{};
public:
    Soldier();
    Soldier(unsigned short time, unsigned short team, unsigned short label,
            unsigned short blood, unsigned short heat,
            unsigned short bloodUpBound, unsigned short heatUpBound);

    void printSoldier();
    bool update(unsigned short presentTime);
    void setHUB(unsigned short HUB);
    [[nodiscard]] unsigned short getHeatUpBound() const;
};


#endif //UNTITLED_SOLDIER_H
