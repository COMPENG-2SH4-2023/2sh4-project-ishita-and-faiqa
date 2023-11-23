#include "GameMechs.h"

GameMechs::GameMechs()
{
    boardSizeX = 30; 
    boardSizeY = 15; 
    exitFlag = false;
    loseFlag = false;  
    score = 0; 
    input = NULL; 

}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX; 
    boardSizeY = boardY; 
    exitFlag = false;
    loseFlag = false;  
    score = 0; 
    input = NULL; 
}

// do you need a destructor?

 GameMechs::~GameMechs()
{
    //NTH YET
} 

bool GameMechs::getExitFlagStatus()
{
    return exitFlag; 
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag; 
}

char GameMechs::getInput()
{
  if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    return input; 
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX; 
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY; 
}

int GameMechs::getScore()
{
    return score; 
}

void GameMechs::setExitTrue()
{
    exitFlag = 1; 
}

void GameMechs::setLoseFlag()
{
    loseFlag = 1; 
}

void GameMechs::setInput(char this_input)
{
    input = this_input; 
}

void GameMechs::clearInput()
{
    input = 0; 
}

void GameMechs::incrementScore()
{
    score += 1; 
}

