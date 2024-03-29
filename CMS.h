/* Header file for CMS - Assignment 4 by Emma Giacometti (CSS343 B)*/
#ifndef CMS_H_
#define CMS_H_

#include "Faculty.h"
#include "Undergraduate.h"
#include "Graduate.h"
#include "Course.h"

//class CMSLogger;

class CMS
{
    private:
        vector<shared_ptr<Course>> courses;
        vector<shared_ptr<Student>> students;
        vector<shared_ptr<Faculty>> faculty;

    public:
        /* constructor/destructor */
        CMS();
        ~CMS();

        /* getters */
        vector<shared_ptr<Course>> getCourses();
        vector<shared_ptr<Student>> getStudents();
        vector<shared_ptr<Faculty>> getFaculty();

        //Adds course to CMS
        //PRE: course has add all the necessary prereqs set 
        void addCourse(shared_ptr<Course> c);

        //Adds student to CMS
        //PRE: student has a unique ID
        void addStudent(shared_ptr<Student> s);

        //Adds faculty to CMS
        void addFaculty(shared_ptr<Faculty> f);

        //Removes course from CMS
        void removeCourse(shared_ptr<Course> course);

        //Removes student from CMS
        void removeStudent(shared_ptr<Student> student);

        //Assigns a student to a specified course
        //PRE: undergraduates enroll in undergraduate classes
        //     graduates enroll in graduate classes
        //     student has taken all the necessary prereqs
        //     student cannot enroll in course if they have already taken in
        //     graduates register if they are teaching course
        //     course can have 40 or more students
        //     students are enrolled in at least one course
        void registerStudent(shared_ptr<Student> student, shared_ptr<Course> course);

        //Removes a student from a specified course
        void passStudent(shared_ptr<Student> student, shared_ptr<Course> course);

        //Assigns an instructor to a specified course
        //PRE: faculty and graduates can be assigned as an instructor
        //     graduates can't be assigned to classes they are taking
        //     graduates can teach one course
        ///    faculty can teach three courses
        void assignInstructor(shared_ptr<Instructor> instructor, shared_ptr<Course> course);

        //Removes an instructor from a specified course
        void removeInstructor(shared_ptr<Course> course);

        //Prints all courses a student is taking
        void printSchedule(shared_ptr<Student> student);

        //Prints all students in a course
        void printStudents(shared_ptr<Course> course);

        //Prints all courses an instructor is teaching
        void printTeaching(shared_ptr<Instructor> instructor);

        //Prints all courses a student has taken
        void printTaken(shared_ptr<Student> student);

        //Prints all courses an instructor has taught
        void printTaught(shared_ptr<Instructor> instructor);

        //Prints all courses currently being taught and their information
        void printCourseInfo(bool file);

        //Deletes CMS
        void deleteCMS();
};

#endif