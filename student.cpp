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

Student::Student(const Student& other)
    : name(other.name),
      age(other.age),
      averageGrade(other.averageGrade),
      course(other.course),
      group(other.group)
{
    objectCount++;
}

Student::~Student()
{
    objectCount--;

    cout << "Объект Student уничтожен: " << name << endl;
}

string Student::getName() const
{
    return name;
}

int Student::getAge() const
{
    return age;
}

double Student::getAverageGrade() const
{
    return averageGrade;
}

int Student::getCourse() const
{
    return course;
}

StudyGroup Student::getGroup() const
{
    return group;
}

void Student::addGrade(double grade)
{
    if (grade < 0.0 || grade > 5.0)
    {
        cout << "Ошибка: оценка должна быть от 0 до 5." << endl;
        return;
    }

 
    averageGrade = (averageGrade + grade) / 2.0;
}

void Student::advanceCourse()
{
    if (course < 6)
    {
        course++;
    }
    else
    {
        cout << "Ошибка: студент уже находится на 6 курсе." << endl;
    }
}

void Student::changeGroup(const StudyGroup& newGroup)
{
    if (newGroup.name.empty() || newGroup.number <= 0)
    {
        cout << "Ошибка: некорректная учебная группа." << endl;
        return;
    }

    group = newGroup;
}