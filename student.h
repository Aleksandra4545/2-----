#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

struct StudyGroup {
    string name;
    int number;
};

class Student
{
private:
    string name;              
    int age;                  
    double averageGrade;      
    int course;               
    StudyGroup group;        

   
    static int objectCount;

public:
    
    Student();

    
    Student(const string& name, int age, double averageGrade,
            int course, const StudyGroup& group);

   
    Student(const Student& other);

    
    ~Student();

   
    string getName() const;
    int getAge() const;
    double getAverageGrade() const;
    int getCourse() const;
    StudyGroup getGroup() const;

    
    void addGrade(double grade);
    void advanceCourse();
    void changeGroup(const StudyGroup& newGroup);

   
    void printInfo() const;

    
    static int getObjectCount();
};

#endif
// 1