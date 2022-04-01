#include <iostream>
#include "Stack.h"

enum Command
{
    PUSH = 1,
    POP = 2,
    EXIT = 3
};


void PrintInfo()
{
    std::cout << "<DynamicStack>" << std::endl;
    std::cout << "[1] Push" << std::endl;
    std::cout << "[2] Pop" << std::endl;
    std::cout << "[3] exit" << std::endl;
    std::cout << "-------------------" << std::endl;

}


void ProcessUserInput(Stack& stack)
{
    int command{};
    bool isExit{ false };
    while (command != EXIT)
    {
        std::cout << std::endl << ">";
        std::cin >> command;

        switch (command)
        {
        case PUSH:
        {
            int value;
            std::cout << "Push Value >> ";
            std::cin >> value;
            stack.Push(value);
            break;
        }
        case POP:
            stack.Pop();
            break;
        case EXIT:
            isExit = true;
            break;
        default:
            std::cout << "잘못된 명령어 입니다!" << std::endl;
            break;
        }
        stack.PrintAllStackValue();

        if (isExit)
        {
            break;
        }
    }

}
int main()
{
    NodeList list{};
    Stack stack(list);
    PrintInfo();
    ProcessUserInput(stack);
}
