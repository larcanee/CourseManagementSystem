/* Implementation file for Course - Assignment 4 by Emma Giacometti (CSS343 B)*/
#include "Course.h"

ostream& operator<<(ostream& out, shared_ptr<Course> course)
{
    //prints course's information to console or log file
    out << "Title: " << course->title << endl;
    out << "Major: " << course->major << endl;
    out << "Prerequisites: ";
    if (course->prereqs.size() == 0) {
        out << "none";
    } else {
        for (int i = 0; i < course->prereqs.size(); i++) {
            out << course->prereqs[i]->getTitle() << " ";
        }
    }
    out << endl << "Students: ";
    if (course->students.size() == 0) {
        out << "none";
    } else {
        for (int i = 0; i < course->students.size(); i++) {
            out << course->students[i]->getName() << " ";
        }
    }
    out << endl << "Instructor: ";
    if (course->instructor == nullptr) {
        out << "none" << endl;
    } else {
        out << course->instructor->getName() << endl;
    }
    return out;
}

Course::Course() {}

Course::Course(string t, char ty, string m) : title(t), type(ty), major(m) {}

Course::~Course() {}

string Course::getTitle()
{
    return title;
}

vector<shared_ptr<Student>> Course::getStudents()
{
    return students;
}

int Course::getNumStudents()
{
    return students.size();
}

shared_ptr<Instructor> Course::getInstructor()
{
    return instructor;
}

vector<shared_ptr<Course>> Course::getPrereqs()
{
    return prereqs;
}

char Course::getType()
{
    return type;
}

string Course::getMajor()
{
    return major;
}

bool Course::addStudent(shared_ptr<Student> s)
{
    //adds a student to the course
    if (students.size() == maxSize) {
        CMSLogger::getInstance().log("Error: " + s->getName() + " failed to register for " + getTitle() + " because it is at full capacity");
        return false;
    } else if (type != s->getType()) {
        CMSLogger::getInstance().log("Error: " + s->getName() + " must register with courses suitable for their level");
        return false;
    } else {
        students.push_back(s);
        return true;
    }
}

void Course::setInstructor(shared_ptr<Instructor> i)
{
    instructor = i;
}

void Course::addPrereq(shared_ptr<Course> p)
{
    //adds course to prerequisites
    if (p->getTitle() == getTitle()) {
        CMSLogger::getInstance().log("Error: " + p->getTitle() + " can't be its own prerequisite");
    } else {
        CMSLogger::getInstance().log(p->getTitle() + " is now a prereq for " + getTitle());
        prereqs.push_back(p);
    }
}

void Course::removeInstructor()
{
    instructor = nullptr;

}

void Course::removeStudent(string name)
{
    //removes a student from course
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getName() == name) {
            students.erase(students.begin() + i);
        }
    }
}

void Course::remove()
{
    //removes courses information
    for (int i = 0; i < students.size(); i++) {
        students[i]->removeTaking(getTitle()); //removes course from student's schedules
    }
    students.clear();
    instructor = nullptr;
}

void Course::clear()
{
    //deletes course's information
    title = "";
    type = ' ';
    major = "";
    remove();
    prereqs.clear();
}