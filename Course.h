/* Header file for Course - Assignment 4 by Emma Giacometti (CSS343 B)*/
#ifndef COURSE_H_
#define COURSE_H_

#include "Student.h"
#include "Instructor.h"

class Instructor;
class Student;

class Course
{
    friend ostream& operator<<(ostream& out, shared_ptr<Course> course);
    private:
        string title;
        char type;
        string major;
        vector<shared_ptr<Student>> students;
        const int maxSize = 40;
        shared_ptr<Instructor> instructor;
        vector<shared_ptr<Course>> prereqs;

    public:
        /* constructors/destructor */
        Course();
        Course(string t, char ty, string m);
        ~Course();

        /* getters */
        string getTitle();
        vector<shared_ptr<Student>> getStudents();
        int getNumStudents();
        shared_ptr<Instructor> getInstructor();
        vector<shared_ptr<Course>> getPrereqs();
        char getType();
        string getMajor();

        /* setters */
        bool addStudent(shared_ptr<Student> s);
        void setInstructor(shared_ptr<Instructor> i);
        void addPrereq(shared_ptr<Course> p);

        //Unassigns an instructor from the course
        //PRE: The course has an instructor
        //POST: The instructor is removed
        void removeInstructor();

        //Unenrolls student from the course by name
        //PRE: names matches to a student in the CMS
        //     that student is taking the course
        //POST: student is removed from course
        void removeStudent(string name);

        //Removes information from course
        //PRE: course has an instructor and students
        //POST: student and instructor information is removed
        void remove();

        //Deletes course information
        void clear();

};

#endif