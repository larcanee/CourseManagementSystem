/* Header file for PFactory - Assignment 4 by Emma Giacometti (CSS343 B)*/
#ifndef PFACTORY_H_ 
#define PFACTORY_H_ 

#include "Undergraduate.h"
#include "Graduate.h"
#include "Faculty.h"
#include "Course.h"

class PFactory
{
    public:
        //Returns a person of a specific type based on method
        shared_ptr<Undergraduate> createUndergraduate(string n, string m, int id);
        shared_ptr<Graduate> createGraduate(string n, string m, int id);
        shared_ptr<Faculty> createFaculty(string n, string m);

};

#endif
