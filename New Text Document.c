#include<stdio.h>
#define WINVER 0x0500
#include <windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
void main(void){
    lockOpeningAnimation();
}
int lockOpeningAnimation(){
    consolReSize(250,300);//LOCK
    printf("\n          +--------------+\n          | +----------+ |\n          | |          | |\n        +-*-*----------^-^-+\n        |                  |\n        |        @@        |\n        |        ||        |\n        +________||________+\n\n            > LOCKED");
    Sleep(1000);//requires stdio.h, windows.h, time.h, conio.h;
    system("cls");//UNLOCK
    printf("\n          +--------------+\n          | +----------+ |\n          | |          | |\n          +=+          | | \n        +--------------^-^-+\n        |                  |\n        |        @@        |\n        |        ||        |\n        +________||________+\n        \n            > UNLOCKED\n");
    Sleep(1000);
    consolReSize(500,500);
    printf(R"EOF(

    ---HAVE A BOOK---

        .--------,
       /        / )
      /        / /
     /________/ /
    (_________)/


)EOF");
}

int consolReSize (int height,int width)
{
    // Get console window handle
    HWND wh = GetConsoleWindow();

    MoveWindow(wh, 100, 100, width, height, TRUE);
    //Move window x=^ ,y=^  required position
}
/*
          +--------------+
          | +----------+ |
          | |          | |
          +=+          | |
        +--------------^-^-+
        |                  |
        |        @@        |
        |        ||        |
        +________||________+

            > UNLOCKED


          +--------------+
          | +----------+ |
          | |          | |
        +-*-*----------^-^-+
        |                  |
        |        @@        |
        |        ||        |
        +________||________+

            > LOCKED
*/
