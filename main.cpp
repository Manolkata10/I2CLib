#include "RelayController.h"
#include <iostream>

int main()
{
        RelayController rc;
        int operation, relayIndex;

        while (true)
        {
                std::cout << "Enter operation; 1 - enable; 0 - disable; 2 - exit" << std::endl;
                std::cin >> operation;

                if (operation == 1 || operation == 0)
                {
                        std::cout << "Enter relay index" << std::endl;
                        std::cin >> relayIndex;

                        if (operation == 0)
                                rc.disableRelayByIndex(relayIndex);
                        else
                                rc.enableRelayByIndex(relayIndex);
                }

                else break;
        }
        return 0;
}
