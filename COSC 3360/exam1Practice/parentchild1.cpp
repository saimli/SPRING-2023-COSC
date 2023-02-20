#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    std::cout<<"I am the parent process";
    wait(nullptr);
}