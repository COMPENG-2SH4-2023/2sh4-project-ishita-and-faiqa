#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

Player *myPlayer;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;

    //myPos.setObjPos(5,5,'*');
}

void GetInput(void)
{
   myPlayer->updatePlayerDir();
}

void RunLogic(void)
{
    myPlayer->movePlayer();
}

void DrawScreen(void)
{

    int i,j;

    MacUILib_clearScreen();
    for(j = 0; j < b; j++)
    {
        for(i = 0; i < a; i++)
        {
            char printChar = ' ';

            if(j == 0 || i == 0 || j == b-1 || i == a-1)
            {
                printChar = '#';
            }
            else if(j == myPlayer->playerPos.y && i == myPlayer->playerPos.x)
            {
               printChar = myPlayer->playerPos.symbol;
               
            }
            MacUILib_printf("%c", printChar);
        }
        MacUILib_printf("\n");
    } 
   

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}S
