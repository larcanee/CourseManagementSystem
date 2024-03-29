/* Header file for Graduate - Assignment 4 by Emma Giacometti (CSS343 B)*/
#ifndef GRADUATE_H_
#define GRADUATE_H_

#include "Person.h"
#include "Course.h"

class Graduate : public Student, public Instructor
{
    public:
        /* constructors/destructor */
        Graduate();
        Graduate(string n, string m, int ID);
        ~Graduate();

        //Deletes graduate's information
        void clear();
};

#endif