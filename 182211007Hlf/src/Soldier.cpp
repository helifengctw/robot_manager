//
// Created by ckyf2023 on 23-4-17.
//

#include "Soldier.h"

Soldier::Soldier() {}
Soldier::Soldier(unsigned short time, unsigned short team, unsigned short label, unsigned short blood,
                 unsigned short heat, unsigned short bloodUpBound, unsigned short heatUpBound)
        : Robot(time, team, label, blood, heat, bloodUpBound)
{
    this-> heatUpBound = heatUpBound;
}

void Soldier::printSoldier()
{
    std::cout << getTime() << " " << getTeam() << "  " << getLabel() << "  blood " << getBlood() << " " << getHeat() << std::endl;
}
bool Soldier::update(unsigned short presentTime)
{
//    std::cout << getTeam() << "  " << getLabel() << " is update" << std::endl;

    if (getHeat() <= heatUpBound)
    {
        setHeat(presentTime-getTime(), 1);
        setTime(presentTime);
        return true;
    }
    else
    {
        unsigned short DTime, DHeat, DBlood;
        DTime = presentTime - getTime();
        DHeat = getHeat() - heatUpBound;
        DBlood = DHeat < DTime ? DHeat : DTime;
        if (setBlood(DBlood, 1))
        {
            setHeat(DBlood, 1);
            setTime(presentTime);
            return true;
        }
        else
        {
            setTime(presentTime);
//            std::cout << getTeam() << "  " << getLabel() << "  died in heat" << std::endl;
            return false;
        }
    }
}
void Soldier::setHUB(unsigned short HUB) {heatUpBound = HUB;}
unsigned short Soldier::getHeatUpBound() const {return heatUpBound;}
