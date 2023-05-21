//
// Created by ckyf2023 on 23-4-17.
//

#ifndef UNTITLED_ROBOTPROCESS_H
#define UNTITLED_ROBOTPROCESS_H

#endif //UNTITLED_ROBOTPROCESS_H

#include "Engineer.h"
#include "Soldier.h"
#include "order.h"
#include <vector>
#include <memory>
#include <iostream>

class RobotProcess : public Soldier, public Engineer, public Order
{
    std::vector<std::shared_ptr<Robot>>
    std::vector< Soldier > liveSol, diedSol;
    std::vector< Engineer > liveEng, diedEng;
    std::vector< Order > orderList;
public:
    RobotProcess();
    void getOrderList(int n);
    void processOrderList();
    void Append(std::vector< Order >::iterator itOrder);
    void Fight(std::vector< Order >::iterator itOrder);
    void UpGrade(std::vector< Order >::iterator itOrder);
    void Heat(std::vector< Order >::iterator itOrder);
    void printDied();
};

