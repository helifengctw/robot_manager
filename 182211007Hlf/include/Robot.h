//
// Created by ckyf2023 on 23-4-17.
//

#ifndef UNTITLED_ROBOT_H
#define UNTITLED_ROBOT_H


class Robot
{
    unsigned short time, blood, heat, team, label, bloodUpBound;
public:
    Robot();
    Robot(unsigned short time,unsigned short team, unsigned short label,
          unsigned short blood, unsigned short heat, unsigned short bloodUpBound);
    unsigned short getTeam() const;
    unsigned short getLabel() const;
    unsigned short getBlood() const;
    unsigned short getHeat() const;
    unsigned short getTime() const;
    unsigned short getBloodUpBound() const;
    void setTime(unsigned short t);
    bool setBlood(unsigned short bld, bool deduce) ;
    void setHeat(unsigned short ht, bool deduce) ;
    void setBloodUpBound(unsigned short bub);
};

#endif //UNTITLED_ROBOT_H