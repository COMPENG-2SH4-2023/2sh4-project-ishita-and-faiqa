#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(5,5,'*');
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 

    char input = mainGameMechsRef->getInput(); // idk

    switch(input)
    {
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

    int x = mainGameMechsRef->getBoardSizeX();
    int y = mainGameMechsRef->getBoardSizeY();

    switch(myDir)
    {
        case UP:
            objPos.y--;
            if(objPos.y <= 0)
            {
                objPos.y = y-2;
            }
            break;

        case DOWN:
            objPos.y++;
            if(objPos.y >= y)
            {
                objPos.y = 1;
            }
            break;

        case LEFT:
            objPos.x--;
            if(objPos.x <= 0)
            {
                objPos.x = x-2;
            }
            break;

        case RIGHT:
            objPos.x++;
            if(objPos.x >= x)
            {
                objPos.x = 1;
            }
            break;

        default:
            break;
    }
}

