#include "GameMechs.h"
#include "MacUILib.h"

using namespace std;

GameMechs::GameMechs()
{
    boardSizeX = 30; 
    boardSizeY = 15; 
    exitFlag = false;
    loseFlag = false;  
    score = 0; 
    input = 0; 

}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX; 
    boardSizeY = boardY; 
    exitFlag = false;
    loseFlag = false;  
    score = 0; 
    input = 0; 
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
    exitFlag = true; 
}

void GameMechs::setLoseFlag()
{
    loseFlag = true; 
    //cout << "Lose flag set. Game Over" << endl; 
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
    score++;
    //cout << "New Score" << score << endl;  
}

