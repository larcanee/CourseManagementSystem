/* Header file for Student - Assignment 4 by Emma Giacometti (CSS343 B)*/
#ifndef STUDENT_H_
#define STUDENT_H_

#include "Person.h"
#include "Course.h"

class Course;

class Student : virtual public Person
{
    protected:
        int ID;
        char type;
        vector<shared_ptr<Course>> taken;
        vector<shared_ptr<Course>> schedule;
    
    public:
        /* constructor/destructor */
        Student();
        Student(int id);
        ~Student();

        /* getters */
        int getID();
        char getType();
        vector<shared_ptr<Course>> getTaken();
        vector<shared_ptr<Course>> getSchedule();

        //Checks if student has taken all the necessary prereqs
        //PRE: course has prereqs
        //POST: Returns true if all prereqs are completed, false if otherwise
        bool checkPrereqs(shared_ptr<Course> course);

        //Checks if a student has taken a specific course
        //PRE: course is a valid course in the CMS
        //POST: Returns true if student has taken it, false if otherwise
        bool hasTaken(shared_ptr<Course> course);

        //Checks if a student is currently taking the course
        //PRE: course is a valid course in the CMS
        //POST: Returns true if student is currently taken it, false if otherwise
        bool isTaking(shared_ptr<Course> course);

        //Adds course to the student's current schedule
        //PRE: course is a valid course in the CMS
        //     student is registered for the course
        //POST: course is added to schedule
        void addTaking(shared_ptr<Course> course);

        //Adds course to the student's previously taken courses
        //PRE: course is a valid course in the CMS
        //     student has taken the course
        //POST: course is added previously taken courses
        void addTaken(shared_ptr<Course> course);

        //Removes course from the student's current schedule
        //PRE: course is a valid course in the CMS
        //     student is registered for the course
        //POST: course is removed from schedule
        void removeTaking(string title);

        //Removes student's information
        //PRE: student has courses in schedule
        //POST: schedule is cleared
        void unenroll();

        //Deletes information about the student
        virtual void clear();
};

#endif