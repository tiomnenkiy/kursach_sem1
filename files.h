#ifndef KURS_FILES_H
#define KURS_FILES_H

#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "input.h"
#include "workshop.h"
#include "employee.h"

using namespace std;

bool FileManager(bool lang, ifstream& file, string name, int stringInFile, vector<string>& lines);

bool ChangeLang(bool lang, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

template<typename T>
bool GetEmployee (bool lang, vector<T>& t, vector<string>& lines, ofstream& file_out, string out);

bool Save (bool lang, vector<Workshop>& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
           vector<CEO>& c, vector<string>& lines, ofstream& file_out, string out);

string Configuration(bool lang, string conf_path, vector<string>& lines);

void PrintFile(string path, vector<string>& lines);

#endif //KURS_FILES_H
