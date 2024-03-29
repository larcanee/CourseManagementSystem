/* Header file for Instructor - Assignment 4 by Emma Giacometti (CSS343 B)*/
#ifndef INSTRUCTOR_H_ 
#define INSTRUCTOR_H_

#include "Person.h"
#include "Course.h"

class Course;
class CMSLogger;

class Instructor : virtual public Person
{
    protected:
        vector<shared_ptr<Course>> teaching;
        int maxSize;
        int numCourses;
        vector<shared_ptr<Course>> taught;
    
    public:
        /* constructor/destructor */
        Instructor();
        ~Instructor();

        /* getters */
        vector<shared_ptr<Course>> getTeaching();
        int getMaxSize();
        int getNumCourses();
        vector<shared_ptr<Course>> getTaught();

        //Adds a course to instructor's current teaching schedule
        //PRE: course is a valid course in the CMS
        //     instructor has space to teach
        //POST: course is added to instructor's schedule
        void addTeaching(shared_ptr<Course> course);

        //Adds a course to an instructor's previously taught classes
        //PRE: course is a valid course in the CMS
        //     instructor has taught this course
        //POST: course is added to previously taught classes
        void addTaught(shared_ptr<Course> course);

        //Deletes instructor's information
        virtual void clear();
};

#endif