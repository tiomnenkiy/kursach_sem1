#ifndef KURS_MENU_H
#define KURS_MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "employee.h"
#include "workshop.h"
#include "input.h"
#include "files.h"

int& NewDepartmentNum();

template<typename T>
int& NewEmployeeNum(vector<T>& t);

template<typename T>
int Search (vector<T>& arr, int left, int right, int key);

template<>
int Search (vector<Workshop>& arr, int left, int right, int key);

template <typename T>
bool ShowVec (bool lang, vector<T>& c, vector<string>& lines);

bool CreateWorkshop (bool lang, vector<Workshop>& c, vector<string>& lines);

template <typename T>
bool Creating(bool lang, vector<T>& c, vector<string>& lines);

bool CreateEmployee (bool lang, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
                     vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

template <typename T>
bool Hiring(bool lang, Workshop& p, vector<T>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

bool HireEmployee (bool lang, Workshop& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
                   vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

template<typename T>
bool Firing (bool lang, Workshop& p, vector<T>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

bool FireEmployee (bool lang, Workshop& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
                   vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

template<typename T>
bool DeletingEmployee(bool lang, vector<Workshop>& p, vector<T>& t, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

bool DeleteEmployee(bool lang, vector<Workshop>& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
                    vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

bool Change(bool lang, vector<Workshop>& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
            vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

bool Menu(bool lang, vector<Workshop>& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
          vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus, ofstream& file_out, string out);

void MainMenu(bool lang, vector<Workshop>& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
              vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus,
              string& eng_about, string& rus_about, string& eng_prog, string& rus_prog, string& eng_screen, string& rus_screen);
#endif //KURS_MENU_H