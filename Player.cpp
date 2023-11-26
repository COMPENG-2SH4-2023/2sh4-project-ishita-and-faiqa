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
            playerPos.y--;
            if(playerPos.y <= 0)
            {
                playerPos.y = y-2;
            }
            break;

        case DOWN:
            playerPos.y++;
            if(playerPos.y >= y)
            {
                playerPos.y = 1;
            }
            break;

        case LEFT:
            playerPos.x--;
            if(playerPos.x <= 0)
            {
                playerPos.x = x-2;
            }
            break;

        case RIGHT:
            playerPos.x++;
            if(playerPos.x >= x)
            {
                playerPos.x = 1;
            }
            break;

        default:
            break;
    }
}

