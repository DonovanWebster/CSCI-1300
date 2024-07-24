#include <fstream>
#include "Schedule.h"

using namespace std;

string upper(string str) {
    for (int i = 0; i < str.length(); i++) {
        toupper(str.at(i));
    }
    return str;
}

Schedule::Schedule(string name) {
    studentName = name;
    enrolledHours = 0;
}

string Schedule::getStudentName() {
    return studentName;
}

int Schedule::getEnrolledHours() {
    return enrolledHours;
}

bool Schedule::loadCourses(string filepath) {
    ifstream fin(filepath);
    if (!fin.is_open()) {
        return false;
    }

    string line;
    while (getline(fin, line)) {
        int idx = line.find(',');
        if (idx != string::npos) {
            Course course = {line.substr(0, idx), stoi(line.substr(idx+1))};
            available.push_back(course);
        }
    }

    return true;
}

int Schedule::addCourse(string courseNum) {
    
    bool courseFound;
    Course course;
    int idx = 0;
    for (; idx < available.size(); idx++) {
        if (upper(available.at(idx).number) == upper(courseNum)) {
            course = available.at(idx);
            courseFound = true;
            break;
        }
    }

    if (!courseFound) {
        return -1;
    }

    if (enrolledHours + course.hours >= 15) {
        return 0;
    }

    
    
    return 1;
}