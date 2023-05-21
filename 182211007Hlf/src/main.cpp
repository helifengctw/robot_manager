#include <vector>
#include "RobotProcess.h"


int main()
{
    int n = 0; std::cin >> n;

    RobotProcess robotProcess;
    robotProcess.getOrderList(n);
    robotProcess.processOrderList();

    robotProcess.printDied();

    return 0;
}
