/* Implementation file for Instructor - Assignment 4 by Emma Giacometti (CSS343 B)*/
#include "Instructor.h"

Instructor::Instructor() : numCourses(0) {}

Instructor::~Instructor() {clear();}

vector<shared_ptr<Course>> Instructor::getTeaching()
{
    return teaching;
}

int Instructor::getMaxSize()
{
    return maxSize;
}

int Instructor::getNumCourses()
{
    return numCourses;
}

vector<shared_ptr<Course>> Instructor::getTaught()
{
    return taught;
}

void Instructor::addTeaching(shared_ptr<Course> course)
{
    teaching.push_back(course);
    numCourses++;
}

void Instructor::addTaught(shared_ptr<Course> course)
{
    taught.push_back(course);
    numCourses--;
}

void Instructor::clear()
{
    //deletes instructor's information
    teaching.clear();
    taught.clear();
    numCourses = 0;
    Person::clear();
}