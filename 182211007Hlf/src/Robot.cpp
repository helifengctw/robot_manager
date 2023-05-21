//
// Created by ckyf2023 on 23-4-17.
//

#include "Robot.h"

Robot::Robot() {}
Robot::Robot(unsigned short time, unsigned short team = 1,
             unsigned short label = 1, unsigned short blood = 100,
             unsigned short heat = 0, unsigned short bloodUpBound = 250)
{
    this -> time = time;
    this -> blood = blood;
    this -> heat = heat;
    this -> team = team;
    this -> label = label;
    this -> bloodUpBound = bloodUpBound;
}
unsigned short Robot::getTeam() const {return team;}
unsigned short Robot::getLabel() const { return label;}
unsigned short Robot::getBlood() const { return blood;}
unsigned short Robot::getHeat() const { return heat;}
unsigned short Robot::getTime() const { return time;}
unsigned short Robot::getBloodUpBound() const {return bloodUpBound;}

void Robot::setTime(unsigned short t) {time = t;}
bool Robot::setBlood(unsigned short bld, bool deduce) {
    bool alive = true;
    if (deduce) {
        if (blood > bld) blood -= bld;
        else alive = false;
    } else {
        if (bld) blood = bld; //(bld % getBloodUpBound());
        else alive = false;
    }
    return alive;
}
void Robot::setHeat(unsigned short ht, bool deduce)
{
    if (deduce)
    {
        if (heat > ht) heat -= ht;
        else heat = 0;
    }
    else heat = ht;
}
void Robot::setBloodUpBound(unsigned short bub) {bloodUpBound = bub;}


