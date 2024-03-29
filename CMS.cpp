/* Implementation file for CMS - Assignment 4 by Emma Giacometti (CSS343 B)*/
#include "CMS.h"

CMS::CMS() {}

CMS::~CMS() {}

vector<shared_ptr<Course>> CMS::getCourses()
{
    return courses;
}

vector<shared_ptr<Student>> CMS::getStudents()
{
    return students;
}

vector<shared_ptr<Faculty>> CMS::getFaculty()
{
    return faculty;
}

void CMS::addCourse(shared_ptr<Course> c)
{
    //adds course to cms - first checks to see if already added
    bool found = false;
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i] == c) {
            found = true;
        }
    }
    if (!found) {
        courses.push_back(c);
        CMSLogger::getInstance().log("Adding " + c->getTitle() + " to CMS");
    } else {
        CMSLogger::getInstance().log("Error: " + c->getTitle() + " already exists in CMS");
    }
}

void CMS::addStudent(shared_ptr<Student> s)
{
    //adds student to cms - first checks to see if already added
    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        if (students[i] == s) {
            found = true;
        }
    }
    if (!found) {
        students.push_back(s);
        CMSLogger::getInstance().log("Adding " + s->getName() + " to CMS as a student");
    } else {
        CMSLogger::getInstance().log("Error: " + s->getName() + " already exists in the CMS");
    }
}

void CMS::addFaculty(shared_ptr<Faculty> f)
{
    //adds faculty to cms - first checks to see if already added
    bool found = false;
    for (int i = 0; i < faculty.size(); i++) {
        if (faculty[i] == f) {
            found = true;
        }
    }
    if (!found) {
        faculty.push_back(f);
        CMSLogger::getInstance().log("Adding " + f->getName() + " to CMS as a faculty member");
    } else {
        CMSLogger::getInstance().log("Error: " + f->getName() + " already exists in the CMS");
    }
}

void CMS::removeCourse(shared_ptr<Course> course)
{
    //removes course from cms - checks if already removed
    bool found = false;
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i] == course) {
            found = true;
            course->remove(); //removes all course information
            courses.erase(courses.begin() + i);
            CMSLogger::getInstance().log("Removing " + course->getTitle() + " from CMS");
        }
    }
    if (!found) {
        CMSLogger::getInstance().log("Error: " + course->getTitle() + " doesn't exist in CMS");
    }
}

void CMS::removeStudent(shared_ptr<Student> student)
{
    //removes student from cms - checks if already removed
    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        if (students[i] == student) {
            found = true;
            student->unenroll(); //removes all student information
            students.erase(students.begin() + i);
            CMSLogger::getInstance().log(student->getName() + " has been unenrolled");
        }
    }
    if (!found) {
        CMSLogger::getInstance().log("Error: " + student->getName() + " doesn't exist in CMS");
    }
}

void CMS::registerStudent(shared_ptr<Student> student, shared_ptr<Course> course)
{
    //adds a student to a specified course
    if (student->hasTaken(course)) {
        CMSLogger::getInstance().log("Error: " + student->getName() + " has already taken " + course->getTitle());
    } else if (student->isTaking(course)) {
        CMSLogger::getInstance().log("Error: " + student->getName() + " is currently in " + course->getTitle());
    } else if (student->getMajor() != course->getMajor()) {
        CMSLogger::getInstance().log("Error: " + student->getName() + " must register for courses in their major");
    } else {
        if (student->checkPrereqs(course)) {
            if (course->addStudent(student)) { //if student can be added
                student->addTaking(course); //adds to student's schedule
                CMSLogger::getInstance().log("Registration complete for " + student->getName() + " in " + course->getTitle());
            }
        } else {
            CMSLogger::getInstance().log("Error: " + student->getName() + " must complete the preqrequisites before registering for " + course->getTitle());
        }
    }
}

void CMS::passStudent(shared_ptr<Student> student, shared_ptr<Course> course)
{
    //moves course from student's current schedule to classes previously taken
    if (student->hasTaken(course)) {
        CMSLogger::getInstance().log("Error: " + student->getName() + " has already received a passing grade for this class");
    } else if (!(student->hasTaken(course)) && !(student->isTaking(course))) { //if student hasn't interacted with this course
        CMSLogger::getInstance().log("Error: " + student->getName() + " hasn't taken this class yet");
    } else { 
        course->removeStudent(student->getName()); //removes student from course
        student->removeTaking(course->getTitle()); //removes course from student's current schedule
        student->addTaken(course); //adds to student's previously taken courses
        CMSLogger::getInstance().log(student->getName() + " has successfully completed " + course->getTitle());
    }
}

void CMS::assignInstructor(shared_ptr<Instructor> instructor, shared_ptr<Course> course)
{
    //assigns an instructor to the specified course based
    if (course->getInstructor() != nullptr) {
        CMSLogger::getInstance().log("Error: " + course->getTitle() + " already has an instructor");
    } else {
        if (instructor->getMaxSize() == 1) { //if instructor is a graduate student
            Graduate* temp = dynamic_cast<Graduate*>(instructor.get());
            if (temp) { //if cast was successful
                if (temp->isTaking(course)) {
                    CMSLogger::getInstance().log("Error: " + instructor->getName() + " is currently taking " + course->getTitle());
                } else if (temp->hasTaken(course) == false && course->getType() == 'G') { //if graduate hasn't completed the graduate class yet
                    CMSLogger::getInstance().log("Error: " + instructor->getName() + " must complete " + course->getTitle() + " before teaching it");
                } else if (temp->getMajor() != course->getMajor()) { 
                    CMSLogger::getInstance().log("Error: " + instructor->getName() + " must teach courses in their major");
                } else {
                    if (instructor->getNumCourses() < instructor->getMaxSize()) { //if graduate has space to teach
                        course->setInstructor(instructor); //adds instructor to course
                        instructor->addTeaching(course); //adds course to instructor's currently teaching courses
                        CMSLogger::getInstance().log(instructor->getName() + " is now teaching " + course->getTitle());
                    } else {
                        CMSLogger::getInstance().log("Error: " + instructor->getName() + " is already teaching their max number of courses");
                    }
                }
            } else {
                cerr << "Type casting error" << endl;
            }
        } else { //if instructor is faculty
            if (instructor->getNumCourses() < instructor->getMaxSize()) { //if instructor has space to teach
                if (instructor->getMajor() != course->getMajor()) {
                    CMSLogger::getInstance().log("Error: " + instructor->getName() + " must teach courses in their department");
                } else {
                    course->setInstructor(instructor); //adds instructor to course
                    instructor->addTeaching(course); //adds course to instructor's currently teaching courses
                    CMSLogger::getInstance().log(instructor->getName() + " is now teaching " + course->getTitle());
                }
            } else {
                CMSLogger::getInstance().log("Error: " + instructor->getName() + " is already teaching their max number of courses");
            }
        }
    }
}

void CMS::removeInstructor(shared_ptr<Course> course)
{
    //removes an instructor from a course
    if (course->getInstructor() != nullptr) {
        CMSLogger::getInstance().log(course->getInstructor()->getName() + " is no longer teaching " + course->getTitle());
        course->getInstructor()->addTaught(course); //moves course from instructor's currently teaching to previously taught
        course->removeInstructor();
    } else {
        CMSLogger::getInstance().log("Error: " + course->getTitle() + " doesn't have an instructor to remove");
    }
}

void CMS::printSchedule(shared_ptr<Student> student)
{
    //prints student's current schedule
    cout << student->getName() << "'s schedule: ";
    for (int i = 0; i < student->getSchedule().size(); i++) {
        cout << student->getSchedule()[i]->getTitle() << " ";
    }
    cout << endl;
    CMSLogger::getInstance().log(student->getName() + "'s schedule was retrieved");
}

void CMS::printStudents(shared_ptr<Course> course)
{
    //prints course's current students
    cout << course->getTitle() << "'s students: ";
    for (int i = 0; i < course->getStudents().size(); i++) {
        cout << course->getStudents()[i]->getName() << " ";
    }
    cout << endl;
    CMSLogger::getInstance().log(course->getTitle() + "'s students were retrieved");
}

void CMS::printTeaching(shared_ptr<Instructor> instructor)
{
    //prints the classes the instructor is currently teaching
    cout << instructor->getName() << "'s classes: ";
    for (int i = 0; i < instructor->getTeaching().size(); i++) {
        cout << instructor->getTeaching()[i]->getTitle() << " ";
    }
    cout << endl;
    CMSLogger::getInstance().log(instructor->getName() + "'s teaching schedule was retrieved");
}

void CMS::printTaken(shared_ptr<Student> student)
{
    //prints the classes the student has previously taken
    cout << student->getName() << "'s previously taken classes: ";
    for (int i = 0; i < student->getTaken().size(); i++) {
        cout << student->getTaken()[i]->getTitle() << " ";
    }
    cout << endl;
    CMSLogger::getInstance().log(student->getName() + "'s past classes were retrieved");
}

void CMS::printTaught(shared_ptr<Instructor> instructor)
{
    //prints the classes that the instructor has previously taught
    cout << instructor->getName() << "'s previously taught classes: ";
    for (int i = 0; i < instructor->getTaught().size(); i++) {
        cout << instructor->getTaught()[i]->getTitle() << " ";
    }
    cout << endl;
    CMSLogger::getInstance().log(instructor->getName() + "'s past classes were retrieved");
}

void CMS::printCourseInfo(bool file)
{
    //prints all courses that are currently being taught
    if (courses.size() == 0) {
        cout << "There are no courses in the CMS" << endl;
    } else {
        if (file) { //print to log file
            fstream f;
            f.open("CourseInfo.txt", ios::out);
            if (!f.is_open()) {
                cerr << "Failed to open course info file" << endl;
            } else {
                f << "Course Information:" << endl;
                for (int i = 0; i < courses.size(); i++) {
                    if (courses[i]->getInstructor() != nullptr) { //only print classes currently being taught
                        f << courses[i] << endl;
                    }
                }
            }
        } else { //print to console
            cout << "Course Information:" << endl;
            for (int i = 0; i < courses.size(); i++) {
                if (courses[i]->getInstructor() != nullptr) { //only print classes currently being taught
                    cout << courses[i] << endl;
                }
            }
        }
    }
    CMSLogger::getInstance().log("All information on courses that are currently being taught was retrieved");
}

void CMS::deleteCMS()
{
    //deletes all information in cms
    for (int i = 0; i < courses.size(); i++) {
        courses[i]->clear();
    }
    courses.clear();
    for (int i = 0; i < students.size(); i++) {
        students[i]->clear();
    }
    students.clear();
    for (int i = 0; i < faculty.size(); i++) {
        faculty[i]->clear();
    }
    faculty.clear();
    CMSLogger::getInstance().log("The CMS has been deleted");
}