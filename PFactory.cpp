/* Implementation file for PFactory - Assignment 4 by Emma Giacometti (CSS343 B)*/
#include "PFactory.h"

shared_ptr<Undergraduate> PFactory::createUndergraduate(string n, string m, int id)
{
    return make_shared<Undergraduate>(n, m, id);
}

shared_ptr<Graduate> PFactory::createGraduate(string n, string m, int id)
{
    return make_shared<Graduate>(n, m, id);
}

shared_ptr<Faculty> PFactory::createFaculty(string n, string m)
{
    return make_shared<Faculty>(n, m);
}