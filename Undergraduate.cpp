/* Implementation file for Undergraduate - Assignment 4 by Emma Giacometti (CSS343 B)*/
#include "Undergraduate.h"

Undergraduate::Undergraduate()
{
    type = 'U';
}

Undergraduate::Undergraduate(string n, string m, int id) : Person(n, m), Student(id) 
{
    type = 'U';
}

Undergraduate::~Undergraduate() {clear();}