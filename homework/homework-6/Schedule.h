#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>

using namespace std;

struct Course {
    string number;
    int hours;
};

class Schedule {
    private:
        string studentName;
        int enrolledHours;
        vector<Course> available;
        vector<Course> enrolled;
    
    public:
        Schedule(string);

        string getStudentName();
        int getEnrolledHours();
        bool loadCourses(string);
        void displayAvailableCourses();
        int addCourse(string);
        bool dropCourse(string);
        bool writeSchedule(string);

};

#endif