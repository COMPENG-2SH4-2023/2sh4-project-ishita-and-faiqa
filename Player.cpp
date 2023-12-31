#include "Player.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    mainFoodRef = thisFoodRef;

    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                      mainGameMechsRef->getBoardSizeY()/2,
                      '*');

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

/*     // for debugging purposes 
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos); */
    
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    //returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 

    char input = mainGameMechsRef->getInput(); // idk

    switch(input)
    {
        case 27:  // exit
            mainGameMechsRef -> setExitTrue(); 
            break;
        case 'w':
            if(myDir != UP && myDir != DOWN)
                myDir = UP;
            break;

        case 's':
            if(myDir != UP && myDir != DOWN)
                myDir = DOWN;
            break;

        case 'a':
            if(myDir != LEFT && myDir != RIGHT)
                myDir = LEFT;
            break;

        case 'd':
            if(myDir != LEFT && myDir != RIGHT)
                myDir = RIGHT;
            break;
        default:
            break;
    }
}


void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
 
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);

    objPos FoodPosition;
    mainFoodRef->getFoodPos(FoodPosition);

    int x = mainGameMechsRef->getBoardSizeX();
    int y = mainGameMechsRef->getBoardSizeY();

    switch(myDir)
    {
        case UP:
            currentHead.y--;
            if(currentHead.y <= 0)
            {
                currentHead.y = y-2;
            }
            break;

        case DOWN:
            currentHead.y++;
            if(currentHead.y >= y - 1)
            {
                currentHead.y = 1;
            }
            break;

        case LEFT:
            currentHead.x--;
            if(currentHead.x <= 0)
            {
                currentHead.x = x-2;
            }
            break;

        case RIGHT:
            currentHead.x++;
            if(currentHead.x >= x - 1)
            {
                currentHead.x = 1;
            }
            break;

        default:
            break;
    }

 
   // mainFoodRef -> generateFood(playerPosList); 

    if(currentHead.isPosEqual(&FoodPosition))
    {
        playerPosList->insertHead(currentHead);
        mainFoodRef->generateFood(playerPosList);
        mainGameMechsRef->incrementScore();
    }
    else
    {

        playerPosList->insertHead(currentHead);
        playerPosList->removeTail();
    }

    if(checkSelfCollision())
    {
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    }

} 

bool Player::checkSelfCollision()
{
    objPos newHead;
    objPos currentHead; 
    playerPosList->getHeadElement(currentHead);

    for (int i = 1; i < playerPosList->getSize(); i++) 
    {
        playerPosList->getElement(newHead, i);
        if (currentHead.isPosEqual(&newHead))
        {
            return true; 
        }
    }
    return false;
}