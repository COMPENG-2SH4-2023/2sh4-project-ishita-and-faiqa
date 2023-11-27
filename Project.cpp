#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000

//Global Variables 
GameMechs *myGM; 
Player *myPlayer;
Food *genFood; 

bool exitFlag;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM -> getExitFlagStatus() == false)  
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

    myGM = new GameMechs(26,16); 
    myPlayer = new Player(myGM);
    genFood = new Food(); 
        

    objPos returnPlayerPos;
    myPlayer->getPlayerPos(returnPlayerPos);

    genFood -> generateFood(returnPlayerPos); // good for now, i have to wait on ishita

}

void GetInput(void)
{
   myGM -> getInput(); 
}

void RunLogic(void)
{
    myPlayer -> updatePlayerDir(); 
    myPlayer -> movePlayer();
    myGM -> clearInput(); 
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
  
    int y, x; 

    objPos returnPlayerPos;
    myPlayer->getPlayerPos(returnPlayerPos);

   // MacUILib_printf("Board Size %dx%d\n",
                  //  myGM -> getBoardSizeX(),
                  //  myGM -> getBoardSizeY());


    for(y = 0; y < myGM -> getBoardSizeY(); y++)
    {
        for(x = 0; x < myGM -> getBoardSizeX(); x++)
        {
            char printChar = ' ';

            if(y == 0 || x == 0 || x == myGM -> getBoardSizeX() - 1|| y == myGM -> getBoardSizeY() - 1)
            {
                printChar = '#';
            }
            else if(y == returnPlayerPos.y && x == returnPlayerPos.x)
            {
               printChar = returnPlayerPos.symbol;
               
            }
            MacUILib_printf("%c", printChar);
        }
        MacUILib_printf("\n");
    } 


    MacUILib_printf("Welcome to Moving Player: Using 'W' to move UP, 'A' to move LEFT, 'S' to move DOWN, and 'D' to move RIGHT!\n"); 
    MacUILib_printf("To exit the game, press ESC. "); 

}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    
    delete myGM; 
    delete myPlayer; 
    delete genFood; 
  
    MacUILib_uninit();
}
