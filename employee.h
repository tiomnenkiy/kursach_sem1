/* employee.h
 *
 */
#ifndef KURS_EMPLOYEE_H
#define KURS_EMPLOYEE_H

#include <iostream>
#include <vector>
#include "personality.h"

using namespace std;
class Employee {
    string fio;
    int number;
    int age;
    int stage;
    int experience;
    int department;
    size_t& Count() {static size_t c = 0; return c;}
public:
    Employee(string, int=0, int=0, int=0, int=0, int=0);
    ~Employee() {--Count();};
    //геттеры
    string GetFIO() {return fio;}
    int GetNumber() const {return number;}
    int GetAge() const {return age;}
    int GetStage() const {return stage;}
    int GetExpirience() const {return experience;}
    int GetDepartment() const {return department;}
    size_t GetCount() {return Count();}
    //cеттеры
    string SetFIO(string data) {fio = data; return fio;}
    int SetNumber(int data) {number = data; return number;}
    int SetAge(int data) {age = data; return age;}
    int SetStage(int data) {stage = data; return data;}
    int SetExperience(int data) {experience = data; return experience;}
    int SetDepartment(int data) {department = data; return department;}
    void InputEmployee(bool lang, vector<string>& lines);
    void OutputEmployee(bool lang, vector<string>& lines);
};

class Turner : public Employee, public Thief {
public:
    Turner(string data_fio, int data_number=0,
           int data_age=0, int data_stage=0, int data_experience=0, int data_department=0)
                : Employee(data_fio, data_number, data_age, data_stage, data_experience, data_department){};
    ~Turner() = default;
};

class Engineer : public Employee, public Hobbit {
public:
    Engineer(string data_fio, int data_number=0,
             int data_age=0, int data_stage=0, int data_experience=0, int data_department=0)
                : Employee(data_fio, data_number, data_age, data_stage, data_experience, data_department){};
    ~Engineer() = default;
};

class Security : public Employee, public Warrior {
public:
    Security(string data_fio, int data_number=0,
             int data_age=0, int data_stage=0, int data_experience=0, int data_department=0)
                : Employee(data_fio, data_number, data_age, data_stage, data_experience, data_department){};
    ~Security() = default;
};

class CEO : public Employee, public Mage { ;
public:
    CEO(string data_fio, int data_number=0,
        int data_age=0, int data_stage=0, int data_experience=0, int data_department=0)
                : Employee(data_fio, data_number, data_age, data_stage, data_experience, data_department){}

    ~CEO() = default;
};

#endif //KURS_EMPLOYEE_H