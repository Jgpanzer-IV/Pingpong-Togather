#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void outputStatus(int status);
int cleanBuild();
int buildCMake();
int executeCMake();

int main(int argc, char* argv[])
{
    system("clear");
    int status = 0;
    char command[10];
    while(1){

        printf("###########################\n");
        printf("c. Clean the build directory\n");
        printf("b. Build the game with CMake\n");
        printf("e. Execute the game with CMake\n");
        printf("r. Run the game\n");
        printf("rc. Recompile and Run the game\n");
        printf("q. Quit\n");
        printf("###########################\n");
        printf("  Enter command : ");
        scanf("%s", command);
    system("clear");

        if (strcmp(command, "c") == 0){
            printf("  - Cleaning build directory\n");
            status = cleanBuild();
        }
        else if (strcmp(command,"b") == 0){
            printf("  - Building game\n");
            status = buildCMake();
        }
        else if (strcmp(command,"e") == 0){
            printf("  - Executing game\n");
            status = executeCMake();
        }
        else if (strcmp(command,"rc") == 0){
            printf("  - Recompile and Run the game\n");
            status = cleanBuild();
            status = buildCMake();
            status = executeCMake();
        }
        else if (strcmp(command,"q") == 0){
            printf("  - Exiting\n");
            break;
        }
        else{
            printf("  * Command not found\n");
        }
        outputStatus(status);
        printf("###########################\n");
    }
    
    return 0;
}


void outputStatus(int status)
{
    if (status == -1){
        printf("  * Command failed\n");
    }
    else{
        printf("  * Command executed successfully\n");
    }
}

int cleanBuild()
{
    int status = 0;
    status = system("rm -rf ../build");
    status = system("mkdir ../build");
    return status;
}

int buildCMake()
{
    int status = 0;
    status = system("cmake -S .. -B ../build");
    status = system("cmake --build ../build");
    return status;
}

int executeCMake()
{
    int status = 0;
    status = system("../build/programSDL");
    return status;
}
