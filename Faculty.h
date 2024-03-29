/* Header file for Faculty - Assignment 4 by Emma Giacometti (CSS343 B)*/
#ifndef FACULTY_H_
#define FACULTY_H_

#include "Instructor.h"

class Faculty : public Instructor
{
    public:
        /* constructor/destructor */
        Faculty();
        Faculty(string n, string m);
        ~Faculty();
};

#endif
