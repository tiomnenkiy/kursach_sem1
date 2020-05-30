#include "employee.h"
#include "input.h"
#include <string.h>

Employee::Employee(string data_fio, int data_number, int data_age, int data_stage, int data_experience, int data_department)
            : number(data_number), age(data_age), stage(data_stage), experience(data_experience), department(data_department) {
    fio = data_fio;
    ++Count();
}

using namespace std;

void Employee::InputEmployee(bool lang, vector<string>& lines) {
    cout << lines.at(53);
    cin.ignore(32767, '\n');
    getline(cin, fio);
    while (fio.empty()) {
        cout << lines.at(42) << endl << lines.at(43) << endl;
        getline(cin, fio);
    }
    cout << endl << lines.at(54);
    age = InputInt(lang, lines);
    cout << endl << lines.at(55);
    stage = InputInt(lang, lines);
    cout << endl << lines.at(56);
    experience = InputInt(lang, lines);
    cout << endl;
}

void Employee::OutputEmployee(bool lang, vector<string>& lines) {
    cout << lines.at(57) << fio << endl << lines.at(58) << number << endl << lines.at(59) << age << endl << lines.at(60) << stage
         << endl << lines.at(61) << experience  << endl << lines.at(62) << department << endl;
}