#include "Food.h"
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"


Food::Food()
{
    FoodPos.setObjPos(-1, -1, 'o'); //intalized outside of the game board
    srand(time(NULL)); 
}

Food::~Food()
{

}

void Food::generateFood(objPos blockOff)
{
    int count; 
    int i; 
    // generate random x and y coord and make sure they are not boarder or block off
    while (count < 5) // this 5 will change into the objpos arrary list thinggyyy
    {
        int xCandidate = (rand() % (mainGameMechsRef -> getBoardSizeX() - 2)) + 1;
        int yCandidate = (rand() % (mainGameMechsRef -> getBoardSizeY() - 2)) + 1;
    
        if (xCandidate <= 0 || xCandidate >= mainGameMechsRef -> getBoardSizeX() - 1 || yCandidate <= 0 || yCandidate >= mainGameMechsRef -> getBoardSizeY() - 1)
            continue;
   
        objPos candidatePos(xCandidate, yCandidate, 'o');

        if (candidatePos.isPosEqual(&blockOff))
            break; 
        else
            count++;



    }
    // Check if the candidate position is equal to the blockOff position

    // check x and y against 0 and board size x/y. 

    // in obj class u have an isPosEqual() method. 

}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos = FoodPos; 
}