# Course Management System
CSS 343: Data Structures, Algorithims, and Discrete Mathematics

Initial Design:
![Assignment4UML-1](https://github.com/larcanee/CourseManagementSystem/assets/114949225/8e20471a-595c-4fb3-84c3-d8eed3268bb0)

Implementation notes and assumptions:
The first major change was my singleton design. I originally had the CMS class log all the actions to a file. However, this didn’t require a singleton design because I wasn’t logging actions from the individual class level. I revised my design so that individual classes could access the logger to better utilize my singleton design. The second change I made was breaking my createPerson() method in my PFactory into three methods that returned the individual types instead of groups each person as a Person. This allowed me to access the methods in the respective classes from the start, instead of having to cast the person to the proper type every time I need to use it. I also decided to treat Graduate as a student rather than an Instructor when storing them in the CMS for simplicity’s sake.

The assumptions I made about the program are as followed: Courses have a type so that undergraduates and graduates can take their respective courses. Courses can’t be their own prerequisite. You can’t add courses, students, or faculty that already exist in the system. Students need to complete prerequisites before registering for a course. Students can’t register for courses that they have already taken or are currently taking. Students can’t pass classes they haven’t taken yet nor can they pass the class twice. Courses can’t have two instructors. Graduate students can’t teach graduate courses that they haven't taken yet, but they can teach any undergraduate class in their major. Students and instructors can’t take/teach courses outside their departments. You can’t remove instructors from courses with no instructor. You can’t remove courses or students that don’t exist from the CMS.
