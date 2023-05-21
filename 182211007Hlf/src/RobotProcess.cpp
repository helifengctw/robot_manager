//
// Created by ckyf2023 on 23-4-17.
//

#include "RobotProcess.h"

RobotProcess::RobotProcess() {};

void RobotProcess::getOrderList(int n)
{
    for (int i = 0; i < n; i++)
    {
        Order tempOrder{};
        tempOrder.inputOrder();
        orderList.push_back(tempOrder);
    }
}

void RobotProcess::processOrderList()
{
    std::vector< Order >::iterator it;
    for (it = orderList.begin(); it != orderList.end(); it++)
    {
        switch (it->getMotion())
        {
            case 'A' : Append(it); break;
            case 'F' : Fight(it); break;
            case 'H' : Heat(it); break;
            case 'U' : UpGrade(it); break;
        }
    }
    it--;
    unsigned short presentTime = it->getTime();
    std::vector< Soldier >::iterator itLive;
    for (itLive = liveSol.begin(); itLive != liveSol.end(); itLive++)
    {
        if (itLive->getHeat() >= 0)
        {
            if (!(itLive->update(presentTime)))
            {
                Soldier tempSol(itLive->getTime(), itLive->getTeam(), itLive->getLabel(), 0, 0, 0, 0);
                diedSol.push_back(tempSol);
//                liveSol.erase(itLive, itLive+1);
            }
        }
    }
//    std::cout << liveSol.end() - liveSol.begin() << " live ; died " << diedSol.end() - diedSol.begin() << std::endl;
//    for (auto i : liveSol) i.printSoldier();
}

void RobotProcess::Append(std::vector< Order >::iterator itOrder)
{
    if (!itOrder->getArg())
    {
        bool over = false;
        for (auto i : diedSol)
        {
            if (i.getTeam() == itOrder->getTeam() && i.getLabel() == itOrder->getLabel())
            {
                Soldier tempSol = i;
                tempSol.setBlood(100, 0);
                tempSol.setHeat(0, 0);
                tempSol.setBloodUpBound(100);
                tempSol.setHUB(100);
                liveSol.push_back(tempSol);
                over = true;
                break;
            }
        }
        if (!over)
        {
            bool find = 0;
            for (auto i : liveSol)
            {
                if (i.getTeam() == itOrder->getTeam() && i.getLabel() == itOrder->getLabel())
                {
                    find = 1;
                    break;
                }
            }
            if (!find) {liveSol.emplace_back(itOrder->getTime(), itOrder->getTeam(), itOrder->getLabel(), 100, 0, 100, 100);}
        }
    }
    else
    {
        bool over = false;
        for (auto i : diedEng)
        {
            if (i.getTeam() == itOrder->getTeam() && i.getLabel() == itOrder->getLabel())
            {
                Engineer tempEng = i;
                tempEng.setBlood(300, 0);
                tempEng.setTime(itOrder->getTime());
                liveEng.push_back(tempEng);
                over = true;
                break;
            }
        }
        if (!over)
        {
            bool find = 0;
            for (auto i : liveEng)
            {
                if (i.getTeam() == itOrder->getTeam() && i.getLabel() == itOrder->getLabel())
                {
                    find = 1;
                    break;
                }
            }
            if (!find) {liveEng.emplace_back(itOrder->getTime(), itOrder->getTeam(), itOrder->getLabel(), 300, 0, 300);}
        }
    }
}

void RobotProcess::Fight(std::vector< Order >::iterator itOrder)
{
    bool find = false;
    std::vector< Soldier >::iterator it;
    for (it = liveSol.begin(); it != liveSol.end(); it++)
    {
        if (it->getTeam() == itOrder->getTeam() && it->getLabel() == itOrder->getLabel())
        {
            if (it->update( itOrder->getTime()))
            {
                if(!it->setBlood(itOrder->getArg(), 1))
                {
                   Soldier tempSol(it->getTime(), it->getTeam(), it->getLabel(), 0, 0, 0, 0);
                   diedSol.push_back(tempSol);
                   liveSol.erase(it, it+1);
                }
            }
            else
            {
                Soldier tempSol(itOrder->getTime(), it->getTeam(), it->getLabel(), 0, 0, 0, 0);
                diedSol.push_back(tempSol);
                liveSol.erase(it, it+1);
            }
            find = true;
            break;
        }
    }
    if (!find)
    {
        std::vector< Engineer >::iterator ita;
        for (ita = liveEng.begin(); ita != liveEng.end(); ita++)
        {
            if (ita->getTeam() == itOrder->getTeam() && ita->getLabel() == itOrder->getLabel())
            {
//                ita->printEngineer();
                if(!ita->setBlood(itOrder->getArg(), 1))
                {
                    Engineer tempEng(itOrder->getTime(), ita->getTeam(), ita->getLabel(), 300, 0, 300);
                    diedEng.push_back(tempEng);
                    liveEng.erase(ita, ita+1);
                }
                break;
            }
        }
    }
}

void RobotProcess::UpGrade(std::vector< Order >::iterator itOrder)
{
    std::vector< Soldier >::iterator it;
    for (it = liveSol.begin(); it != liveSol.end(); it++)
    {
        if (it->getTeam() == itOrder->getTeam() && it->getLabel() == itOrder->getLabel())
        {
            if (!it->update( itOrder->getTime()))
            {
                Soldier tempSol(itOrder->getTime(), it->getTeam(), it->getLabel(), 0, 0, 0, 0);
                diedSol.push_back(tempSol);
                liveSol.erase(it, it+1);
            }
            else
            {
                if (itOrder->getArg() * 100 > it->getHeatUpBound())
                {
                    switch (itOrder->getArg())
                    {
                        case 2: it->setBloodUpBound(150); it->setHUB(200); it->setBlood(150, 0); break;
                        case 3: it->setBloodUpBound(250); it->setHUB(300); it->setBlood(250, 0);
                    }
                }
                break;
            }
        }
    }
}

void RobotProcess::Heat(std::vector< Order >::iterator itOrder)
{
    std::vector< Soldier >::iterator it;
    for (it = liveSol.begin(); it != liveSol.end(); it++)
    {
        if (it->getTeam() == itOrder->getTeam() && it->getLabel() == itOrder->getLabel())
        {
            if (!it->update( itOrder->getTime()))
            {
                Soldier tempSol(itOrder->getTime(), it->getTeam(), it->getLabel(), 0, 0, 0, 0);
                diedSol.push_back(tempSol);
                liveSol.erase(it, it+1);
            }
            else
            {
                it->setHeat(itOrder->getArg(), 0);
                break;
            }
        }
    }
}

void RobotProcess::printDied()
{
    std::vector< Soldier >::iterator itDiedSol;
    std::vector< Engineer >::iterator itDiedEng;
    for (itDiedSol = diedSol.begin(); itDiedSol != diedSol.end(); itDiedSol++)
    {
        std::cout << "D " << itDiedSol->getTeam() << " " << itDiedSol->getLabel() << std::endl;
    }
    for (itDiedEng = diedEng.begin(); itDiedEng != diedEng.end(); itDiedEng++)
    {
        std::cout << "D " << itDiedEng->getTeam() << " " << itDiedEng->getLabel() << std::endl;
    }
}
