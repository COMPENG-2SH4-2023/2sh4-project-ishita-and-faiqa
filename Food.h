#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Player.h"

using namespace std;

class Food 
{
    private: 
    objPos FoodPos; 
    GameMechs *mainGameMechsRef; 

    public: 
    Food(GameMechs* thisGMRef);
    ~Food(); 

    void generateFood(objPosArrayList* playerPosList); 
    objPosArrayList* getFoodPos(); 
}; 

#endif