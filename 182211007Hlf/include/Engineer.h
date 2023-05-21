//
// Created by ckyf2023 on 23-4-17.
//

#ifndef UNTITLED_ENGINEER_H
#define UNTITLED_ENGINEER_H

#include <iostream>
#include "Robot.h"

class Engineer : public Robot
{
public:
    Engineer();
    Engineer(unsigned short time, unsigned short team, unsigned short label,
             unsigned short blood, unsigned short heat, unsigned short bloodUpBound);
    void printEngineer();
};

#endif //UNTITLED_ENGINEER_H
