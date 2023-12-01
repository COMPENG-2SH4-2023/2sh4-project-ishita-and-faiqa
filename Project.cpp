#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"


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
    genFood = new Food(myGM); 
    
    srand(time(NULL)); 


    objPos tempPos{1, 1, 'o'}; // we need to randomize later
    genFood -> generateFood(tempPos);
 // good for now, i have to wait on ishita

}

void GetInput(void)
{
   myGM -> getInput(); 
}

void RunLogic(void)
{
    myPlayer -> updatePlayerDir(); 
    myPlayer -> movePlayer();
    
    // objPos returnPlayerPos;
    // myPlayer->getPlayerPos(returnPlayerPos);

    // objPos FoodPos;
    // genFood->getFoodPos(FoodPos);

    // if (returnPlayerPos.isPosEqual(&FoodPos))
    // {
    //     genFood->generateFood(returnPlayerPos);
    //     myGM->incrementScore(); 
    // }
// THIS IS FOR DEBUGGING PURPOSES KEEP HERE! 

/*     switch (myGM -> getInput())
    {
    case ' ':
        myGM->incrementScore();
        break;
    case 'l':
        myGM->setLoseFlag();
        break;
    default:
        break;
    } */  


    myGM -> clearInput(); 

}


void DrawScreen(void)
{
    MacUILib_clearScreen();    
  
    int y, x; 

    bool drawn;

    objPosArrayList* playerBody= myPlayer->getPlayerPos();
    objPos tempBody;

    objPos FoodPos; 
    genFood -> getFoodPos(FoodPos); 


    for(y = 0; y < myGM -> getBoardSizeY(); y++)
    {
        for(x = 0; x < myGM -> getBoardSizeX(); x++)
        {
            drawn = false;

            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody,k);
                if(tempBody.x == x && tempBody.y == y)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if(drawn) continue;


            char printChar = ' ';

            if(y == 0 || x == 0 || x == myGM -> getBoardSizeX() - 1|| y == myGM -> getBoardSizeY() - 1)
            {
                printChar = '#';
            }
            else if(x == FoodPos.x && y == FoodPos.y)
            {
                printChar = FoodPos.symbol; 
            }
        
            MacUILib_printf("%c", printChar);
        }
        MacUILib_printf("\n");
    } 


    MacUILib_printf("Welcome to Moving Player: Using 'W' to move UP, 'A' to move LEFT, 'S' to move DOWN, and 'D' to move RIGHT!\n"); 
    MacUILib_printf("To exit the game, press ESC. \n"); 
    MacUILib_printf("Score: %d\n\n",myGM -> getScore());
    MacUILib_printf("Lose Flag is: %d\n\n",myGM -> getLoseFlagStatus());
   



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
