/* Header file for Undergraduate - Assignment 4 by Emma Giacometti (CSS343 B)*/
#ifndef UNDERGRADUATE_H_
#define UNDERGRADUATE_H_

#include "Student.h"

class Undergraduate : public Student
{
    public:
        /* constructors/destructor */
        Undergraduate();
        Undergraduate(string n, string m, int id);
        ~Undergraduate();
};

#endif