#include <iostream>
#include "Game.h"
#include "Field.h"
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

int main()
{
    srand(time(NULL));
    Game g;
    g.play_XO();

    return 0;
}
