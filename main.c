#include <stdio.h>
#include <stdlib.h>
#include "SNAKE1.h"
extern char name[30];
int main()
{
    //welcomePage();
    CreateMap();
    CreateFood();
    CreatePoison();
    if (ClickControl() == 0) return 0;
    return 0;
}
