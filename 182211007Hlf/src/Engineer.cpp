//
// Created by ckyf2023 on 23-4-17.
//

#include "Engineer.h"

Engineer::Engineer() {}
Engineer::Engineer(unsigned short time, unsigned short team = 0, unsigned short label = 0,
                   unsigned short blood = 300, unsigned short heat = 0, unsigned short bloodUpBound = 300)
        : Robot(time, team, label, blood, heat, bloodUpBound) {}

void Engineer::printEngineer()
{
    std::cout << getTime() << " " << getTeam() << "  blood " << getBlood() << " " << getBloodUpBound() << std::endl;
}

