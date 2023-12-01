#include "Player.h"
#include "objPos.h"
#include "objPosArrayList.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                      mainGameMechsRef->getBoardSizeY()/2,
                      '*');

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    // for debugging purposes 
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    
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
            if(currentHead.y >= y)
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
            if(currentHead.x >= x)
            {
                currentHead.x = 1;
            }
            break;

        default:
            break;
    }

    playerPosList->insertHead(currentHead);

    playerPosList->removeTail();
}

