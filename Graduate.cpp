/* Implementation file for Graduate - Assignment 4 by Emma Giacometti (CSS343 B)*/
#include "Graduate.h"

Graduate::Graduate() 
{
    type = 'G';
    maxSize = 1;
}

Graduate::Graduate(string n, string m, int id) : Person(n, m), Student(id) 
{
    type = 'G';
    maxSize = 1;
}

Graduate::~Graduate() {clear();}

void Graduate::clear()
{
    //deletes graduate's information
    Instructor::clear();
    Student::clear();
    Person::clear();
}