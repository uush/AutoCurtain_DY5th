#include "move.h"

int steps()
{
    int pos_i = extern count;
    int steps = abs(pos_i-extern position);
    return steps;
}

int direct()
{
    direct = (extern position-pos_i > 0) ? HIGH : LOW;
    return direct;
}