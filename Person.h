/* Header file for Person - Assignment 4 by Emma Giacometti (CSS343B)*/
#ifndef PERSON_H_
#define PERSON_H_

#include <vector>
#include <memory>

#include "CMSLogger.h"

using namespace std;

class Person
{
    protected:
        string name;
        string major;

    public:
        /* constructors/destructor */
        Person() {}
        Person(string n, string m) : name(n), major(m) {}
        ~Person() {clear();}

        /* getter/setter */
        string getName() {return name;}
        string getMajor() {return major;}

        //Deletes person's information
        virtual void clear() {name = ""; major = "";}

};

#endif