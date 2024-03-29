/* Implementation file for Faculty - Assignment 4 by Emma Giacometti (CSS343 B)*/
#include "Faculty.h"

Faculty::Faculty()
{
    maxSize = 3;
}

Faculty::Faculty(string n, string m) : Person(n, m)
{
    maxSize = 3;
}

Faculty::~Faculty() {clear();}