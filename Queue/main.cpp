#include <iostream>
#include "queue.h"

enum Command
{
    ENQUEUE = 1,
    DEQUEUE = 2,
    EXIT = 3
};


void PrintInfo()
{
    std::cout << "<DynamicQueue>" << std::endl;
    std::cout << "[1] Enqueue" << std::endl;
    std::cout << "[2] Dequeue" << std::endl;
    std::cout << "[3] exit" << std::endl;
    std::cout << "-------------------" << std::endl;

}


void ProcessUserInput(nodeList& queue)
{
    int command{};
    bool isExit{ false };
    while (command != EXIT)
    {
        std::cout << std::endl << ">";
        std::cin >> command;

        switch (command)
        {
        case ENQUEUE:
        {
            int value;
            std::cout << "Queue Value >> ";
            std::cin >> value;
            Enqueue(queue, value);
            break;
        }
        case DEQUEUE:
            Dequeue(queue);
            break;
        case EXIT:
            isExit = true;
            break;
        default:
            std::cout << "잘못된 명령어 입니다!" << std::endl;
            break;
        }
        PrintAllQueueValue(queue);

        if (isExit)
        {
            break;
        }
    }

}
int main()
{
    nodeList list{};
    PrintInfo();
    ProcessUserInput(list);
    DestoryQueue(list);
}
