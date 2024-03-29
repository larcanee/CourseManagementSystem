/* Driver program for CMS*/
#include "Person.h"
#include "PFactory.h"
#include "CMS.h"

int main()
{
    CMS cms;

    /* course constructors */
    shared_ptr<Course> css142 = make_shared<Course>("CSS142", 'U', "CSSE");
    shared_ptr<Course> css143 = make_shared<Course>("CSS143", 'U', "CSSE");
    shared_ptr<Course> css301 = make_shared<Course>("CSS301", 'U', "CSSE");
    shared_ptr<Course> css342 = make_shared<Course>("CSS342", 'U', "CSSE");
    shared_ptr<Course> css343 = make_shared<Course>("CSS343", 'U', "CSSE");
    shared_ptr<Course> css350 = make_shared<Course>("CSS350", 'U', "CSSE");
    shared_ptr<Course> css360 = make_shared<Course>("CSS360", 'U', "CSSE");
    shared_ptr<Course> css370 = make_shared<Course>("CSS370", 'U', "CSSE");
    shared_ptr<Course> css581 = make_shared<Course>("CSS581", 'G', "CSSE");
    shared_ptr<Course> css586 = make_shared<Course>("CSS586", 'G', "CSSE");
    shared_ptr<Course> me341 = make_shared<Course>("ME341", 'U', "ME");

    /* set prereqs */
    css142->addPrereq(css142); //error: can't be its own prereq
    css143->addPrereq(css142);
    css342->addPrereq(css143);
    css343->addPrereq(css342);
    css343->addPrereq(css301);
    css350->addPrereq(css301);
    css360->addPrereq(css143);
    css370->addPrereq(css301);
    css370->addPrereq(css342);
    css370->addPrereq(css360);
    css586->addPrereq(css581);

    /* add to cms */
    cms.addCourse(css142);
    cms.addCourse(css142); //error: already exists in cms
    cms.addCourse(css143);
    cms.addCourse(css301);
    cms.addCourse(css342);
    cms.addCourse(css343);
    cms.addCourse(css350);
    cms.addCourse(css360);
    cms.addCourse(css370);
    cms.addCourse(css581);
    cms.addCourse(css586);
    cms.addCourse(me341);

    /* create students and faculty - students have unique ids */
    PFactory pF;
    shared_ptr<Undergraduate> emma = pF.createUndergraduate("Emma Giacometti", "CSSE", 1800604);
    shared_ptr<Undergraduate> tanner = pF.createUndergraduate("Tanner Conrad", "CSSE", 3444632);
    shared_ptr<Undergraduate> alex = pF.createUndergraduate("Alex Rangel", "CSSE", 1002354);
    shared_ptr<Graduate> drew = pF.createGraduate("Drew Rigby", "CSSE", 1000638);
    shared_ptr<Graduate> rhia = pF.createGraduate("Rhia Dorrison", "CSSE", 20005061);
    shared_ptr<Graduate> ryan = pF.createGraduate("Ryan Applebee", "CSSE", 48641166);
    shared_ptr<Faculty> susan = pF.createFaculty("Susan Leaman", "CSSE");
    shared_ptr<Faculty> kacper = pF.createFaculty("Kacper Szymanski", "CSSE");
    shared_ptr<Faculty> miles = pF.createFaculty("Miles Upshur", "CSSE");
    shared_ptr<Faculty> ethan = pF.createFaculty("Ethan Winters", "ME");

    /* add to cms */
    cms.addStudent(emma);
    cms.addStudent(emma); //error: already exists in cms
    cms.addStudent(tanner);
    cms.addStudent(alex);
    cms.addStudent(drew);
    cms.addStudent(rhia);
    cms.addStudent(ryan);
    cms.addFaculty(susan);
    cms.addFaculty(susan); //error: already exists in cms
    cms.addFaculty(kacper);
    cms.addFaculty(miles);
    cms.addFaculty(ethan);

    /* assign students to at least one course + test cases */
    cms.registerStudent(emma, css343); //error: need to complete prereqs
    cms.registerStudent(emma, css142); //error: already in class
    cms.registerStudent(ryan, css142); //error: need to take grad classes as a grad student
    cms.registerStudent(emma, css581); //error: need to take undergrad classes as an undergrad student
    cms.registerStudent(tanner, css301);
    for (int i = 0; i < 40; i++) {
        shared_ptr<Undergraduate> test = pF.createUndergraduate("Test", "CSSE", 0);
        cms.registerStudent(test, css301);
    } //error: max size for course reached
    cms.passStudent(emma, css142);
    cms.registerStudent(emma, css142); //error: has already taken the course
    cms.passStudent(emma, css586); //error: hasn't taken the class yet
    cms.registerStudent(emma, css143);
    cms.passStudent(emma, css143);
    cms.registerStudent(emma, css342);
    cms.registerStudent(alex, css142);
    cms.registerStudent(ryan, css581);
    cms.registerStudent(rhia, css581);
    cms.passStudent(rhia, css581);
    cms.registerStudent(rhia, css586);
    cms.registerStudent(drew, css581);
    cms.registerStudent(alex, me341); //error: can't register outside of their major

    /* assign instructors to courses + test cases */
    cms.assignInstructor(susan, css342);
    cms.assignInstructor(susan, css343);
    cms.assignInstructor(susan, css350);
    cms.assignInstructor(susan, css360); //error: already teaching three courses
    cms.assignInstructor(rhia, css142);
    cms.assignInstructor(rhia, css143); //error: already teaching a course
    cms.assignInstructor(drew, css581); //error: is currently taking the course
    cms.assignInstructor(drew, css586); //error: must complete the course before teaching it if grad student
    cms.assignInstructor(drew, css143);
    cms.assignInstructor(ryan, css301);
    cms.assignInstructor(kacper, css142); //error: already has an instructor
    cms.assignInstructor(kacper, css581);
    cms.assignInstructor(kacper, css586);
    cms.assignInstructor(miles, css360);
    cms.assignInstructor(miles, css370);
    cms.assignInstructor(miles, me341); //error: can't teach classes outside of department
    cms.assignInstructor(ethan, me341);

    /* Print the schedule of students of each type in a specific course */
    cms.printSchedule(tanner);
    cout << endl;
    cms.printSchedule(drew);
    cout << endl;

    /* Print all the students of each type in a specific course */
    cms.printStudents(css301);
    cout << endl;
    cms.printStudents(css586);
    cout << endl;

    /*Print all courses a specific instructor of each type is teaching */
    cms.printTeaching(susan);
    cout << endl;
    cms.printTeaching(rhia);
    cout << endl;

    /* Print all courses and their info to console */
    cms.printCourseInfo(false);

    /* Print all courses and their info to txt file */
    cms.printCourseInfo(true);

    /* Remove all instructors from courses */
    cms.removeInstructor(css342);
    cms.removeInstructor(css350);
    cms.removeInstructor(css342); //error: instructor has already been removed
    cms.removeInstructor(css581);

    /* Remove students of each type from courses */
    cms.passStudent(tanner, css301);
    cms.passStudent(tanner, css301); //error: already passed the class
    cms.passStudent(drew, css581);
    
    /* Print all courses a specific student of each type has taken */
    cms.printTaken(emma);
    cms.printTaken(rhia);
    cout << endl;

    /* Print all courses a specific instructor of each type has taught */
    cms.printTaught(susan);
    cms.printTaught(kacper);
    cout << endl;

    /* Remove students of each type from cms */
    cms.removeStudent(alex);
    cms.removeStudent(alex); //error: already removed from cms
    cms.removeStudent(ryan);

    /* Remove courses of each type from cms */
    cms.removeCourse(css143);
    cms.removeCourse(css143); //error: already removed from cms
    cms.removeCourse(css586);
   
    /* Delete course management system */
    cms.deleteCMS();
    cms.printCourseInfo(false);

    return 0;
}