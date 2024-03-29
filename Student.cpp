/* Implementation file for Student - Assignment 4 by Emma Giacometti (CSS343 B)*/
#include "Student.h"

Student::Student() {}

Student::Student(int id) : ID(id) {}

Student::~Student() {clear();}

int Student::getID()
{
    return ID;
}

char Student::getType()
{
    return type;
}

vector<shared_ptr<Course>> Student::getTaken()
{
    return taken;
}

vector<shared_ptr<Course>> Student::getSchedule()
{
    return schedule;
}

bool Student::checkPrereqs(shared_ptr<Course> course)
{
    //checks if student has completed the necessary prereqs
    bool completePrereqs;
    if (course->getPrereqs().size() == 0) {
        completePrereqs = true;
    } else {
        for (int i = 0; i < course->getPrereqs().size(); i++) {
            if (hasTaken(course->getPrereqs()[i])) {
                completePrereqs = true;
            } else {
                completePrereqs = false;
                break;
            }
        }
    }
    return completePrereqs;
}

bool Student::hasTaken(shared_ptr<Course> course)
{
    //checks if course has been taken
    for (int i = 0; i < taken.size(); i++) {
        if (taken[i] == course) {
            return true;
        }
    }
    return false;
}

bool Student::isTaking(shared_ptr<Course> course)
{
    //checks if course is in current schedule
    for (int i = 0; i < schedule.size(); i++) {
        if (schedule[i] == course) {
            return true;
        }
    }
    return false;
}

void Student::addTaking(shared_ptr<Course> course)
{
    schedule.push_back(course);
}

void Student::addTaken(shared_ptr<Course> course)
{
    taken.push_back(course);
}

void Student::removeTaking(string title)
{
    //removes course from student's schedule
    for (int i = 0; i < schedule.size(); i++) {
        if (schedule[i]->getTitle() == title) {
            schedule.erase(schedule.begin() + i);
        }
    }
}

void Student::unenroll()
{
    //clears student's current schedule
    for (int i = 0; i < schedule.size(); i++) {
        removeTaking(schedule[i]->getTitle());
    }
    schedule.clear();
}

void Student::clear()
{
    //deletes student's information
    ID = 0;
    type = ' ';
    taken.clear();
    if (schedule.size() != 0) {
        unenroll();
    }
    Person::clear();
}