g++ CMS.cpp CMSDriver.cpp Course.cpp Faculty.cpp Graduate.cpp Instructor.cpp PFactory.cpp Student.cpp Undergraduate.cpp -o cms
valgrind --leak-check=yes ./cms
./cms