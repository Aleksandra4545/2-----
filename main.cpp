#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    cout << "===== СОЗДАНИЕ ОБЪЕКТОВ =====" << endl;

    StudyGroup group1 = {"IVT-101", 101};
    StudyGroup group2 = {"IVT-202", 202};
    StudyGroup group3 = {"AI-303", 303};

    Student student1;

    Student student2(
        "Александр",
        20,
        4.5,
        3,
        group1
    );

    Student student3(student2);

    cout << "\nКоличество существующих объектов: "
         << Student::getObjectCount() << endl;

    cout << "\n===== НАЧАЛЬНОЕ СОСТОЯНИЕ =====" << endl;

    cout << "\nСтудент 1:" << endl;
    student1.printInfo();

    cout << "\nСтудент 2:" << endl;
    student2.printInfo();

    cout << "\nСтудент 3:" << endl;
    student3.printInfo();

    cout << "\n===== КОРРЕКТНЫЕ ОПЕРАЦИИ =====" << endl;

    cout << "\nДобавляем оценку студенту 2..." << endl;
    student2.addGrade(5.0);

    cout << "Переводим студента 2 на следующий курс..." << endl;
    student2.advanceCourse();

    cout << "Меняем группу студента 2..." << endl;
    student2.changeGroup(group2);

    cout << "\nСостояние студента 2 после изменений:" << endl;
    student2.printInfo();

    cout << "\n===== НЕКОРРЕКТНЫЕ ОПЕРАЦИИ =====" << endl;

    cout << "\nПопытка добавить оценку 10:" << endl;
    student2.addGrade(10.0);

    cout << "\nПопытка добавить отрицательную оценку:" << endl;
    student2.addGrade(-2.0);

    cout << "\nПопытка установить некорректную группу:" << endl;

    StudyGroup badGroup = {"", -5};
    student2.changeGroup(badGroup);

    cout << "\n===== СОСТОЯНИЕ ПОСЛЕ НЕКОРРЕКТНЫХ ОПЕРАЦИЙ =====" << endl;

    student2.printInfo();

    cout << "\n===== ПРОВЕРКА НЕЗАВИСИМОСТИ ОБЪЕКТОВ =====" << endl;

    cout << "\nСостояние студента 1 до изменения:" << endl;
    student1.printInfo();

    cout << "\nИзменяем только студента 1..." << endl;

    student1.addGrade(4.0);
    student1.advanceCourse();

    cout << "\nСостояние студента 1 после изменения:" << endl;
    student1.printInfo();

    cout << "\nСостояние студента 2:" << endl;
    student2.printInfo();

    cout << "\nСостояние студента 3:" << endl;
    student3.printInfo();

    cout << "\n===== СТАТИСТИЧЕСКИЙ СЧЁТЧИК =====" << endl;

    cout << "Количество существующих объектов: "
         << Student::getObjectCount() << endl;

    cout << "\n===== КОНЕЦ ПРОГРАММЫ =====" << endl;

    return 0;
}