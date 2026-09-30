#include "Student.h"
#include <iostream>

using namespace std;

int Student::objectCount = 0;

Student::Student()
    : name("Unknown"),
      age(18),
      averageGrade(0.0),
      course(1),
      group({"Unknown", 0})
{
    objectCount++;
}

Student::Student(const string& name, int age, double averageGrade,
                 int course, const StudyGroup& group)
    : name(name),
      age(18),
      averageGrade(0.0),
      course(1),
      group({"Unknown", 0})
{
    if (!name.empty())
    {
        this->name = name;
    }

    if (age >= 16 && age <= 100)
    {
        this->age = age;
    }

    if (averageGrade >= 0.0 && averageGrade <= 5.0)
    {
        this->averageGrade = averageGrade;
    }

    if (course >= 1 && course <= 6)
    {
        this->course = course;
    }

    if (!group.name.empty() && group.number > 0)
    {
        this->group = group;
    }

    objectCount++;
}
