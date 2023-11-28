#include "Food.h"
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"


Food::Food(GameMechs *thisGMRef)
{
    FoodPos.setObjPos(-1, -1, 'o'); //intalized outside of the game board
    mainGameMechsRef = thisGMRef; 
}

Food::~Food()
{

}

void Food::generateFood(objPos blockOff)
{
    int x, y; 
    // generate random x and y coord and make sure they are not boarder or block off

    do 
    {
        srand(time(NULL)); 

        FoodPos.x = (rand() % (mainGameMechsRef -> getBoardSizeX() - 2)) + 1; 
        FoodPos.y = (rand() % (mainGameMechsRef -> getBoardSizeY() - 2)) + 1; 
    } while (FoodPos.isPosEqual(&blockOff));

 /*        FoodPos.x = (rand() % (mainGameMechsRef -> getBoardSizeX() - 2)) + 1; 
        FoodPos.y = (rand() % (mainGameMechsRef -> getBoardSizeY() - 2)) + 1; 
 */
    /* int xCandidate = (rand() % (mainGameMechsRef -> getBoardSizeX() - 2)) + 1;
        int yCandidate = (rand() % (mainGameMechsRef -> getBoardSizeY() - 2)) + 1;
    
        if (xCandidate <= 0 || xCandidate >= mainGameMechsRef -> getBoardSizeX() - 1 || yCandidate <= 0 || yCandidate >= mainGameMechsRef -> getBoardSizeY() - 1)
            continue;
   
        objPos candidatePos(xCandidate, yCandidate, 'o');

        if (candidatePos.isPosEqual(&blockOff))
            break; 
        else
            count++;


 */
}
    // Check if the candidate position is equal to the blockOff position

    // check x and y against 0 and board size x/y. 

    // in obj class u have an isPosEqual() method. 


void Food::getFoodPos(objPos &returnPos)
{
    returnPos = FoodPos; 
}