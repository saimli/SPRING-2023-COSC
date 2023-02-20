#include <iostream>
#include <unistd.h>

int main(){

    // fork(); creates a fork -> print twice
    // fork(); creates a child of a child -> prints once more making 3 in total

    std::cout<<"parent"<<std::endl;
int x;
    for(int i=0; i<3; i++)
    {
        x = fork();
        if(x==0){
        std::cout<<"child dad"<<i<<std::endl;
        if(x==0){
            while(i==0 ||i==2)
        std::cout<<"child kid"<<std::endl;
            sleep(5);
            _exit(0);//make sure to break
        }
        wait(nullptr);

        }
        else
        _exit(0);//make sure to break
    }

    //if(x!=0) //we knot its the parent //wont need this since we use _exit(0)

    for(int i=0; i<2; i++){
        wait(nullptr);
    }


    return 0;
}

//ps -f -c in ur terminal
//fix vscode to run in terminal