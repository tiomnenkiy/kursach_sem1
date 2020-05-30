#include "menu.h"

int& NewDepartmentNum() {static int c = 1; return c;}

template<typename T>
int& NewEmployeeNum(vector<T>& t) {static int e = 1; return e;}
using namespace  std;

template<typename T>
int Search (vector<T>& arr, int left, int right, int key) {
    int mid = 0;
    while (1)
    {
        mid = (left + right) / 2;

        if (key < arr[mid].GetNumber())
            right = mid - 1;
        else if (key > arr[mid].GetNumber())
            left = mid + 1;
        else if (key == arr[mid].GetNumber())
            return mid;

        if (left > right)
            return -1;
    }
}

template<>
int Search (vector<Workshop>& arr, int left, int right, int key) {
    int mid = 0;
    while (1)
    {
        mid = (left + right) / 2;

        if (key < arr[mid].GetDepartment())
            right = mid - 1;
        else if (key > arr[mid].GetDepartment())
            left = mid + 1;
        else
            return mid;

        if (left > right)
            return -1;
    }
}

template <typename T>
bool ShowVec (bool lang, vector<T>& c, vector<string>& lines) {
    bool key = 0;
    for (int i = 0; i < c.size(); ++i) {
        cout << endl;
        c[i].OutputEmployee(lang,lines);
        cout << endl;
        key = 1;
    }
    return key;
}

bool CreateWorkshop (bool lang, vector<Workshop>& c, vector<string>& lines) { //не вводит имя воркшопа
    Workshop p("", NewDepartmentNum());
    lang = p.InputWorkshop(lang, lines);
    if ( p.GetWorkshopName().empty()) {
        return lang;
    }
    ++NewDepartmentNum();
    c.push_back(p);
    return lang;
}

template <typename T>
bool Creating(bool lang, vector<T>& c, vector<string>& lines) {
    T p(string(), NewEmployeeNum(c));
    p.InputEmployee(lang, lines);
    if (p.GetFIO().empty()) {
        return 0;
    }
    ++NewEmployeeNum(c);
    c.push_back(p);
    return 1;
}

bool CreateEmployee (bool lang, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
                     vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {//change lang
    int k;
    do {
        cout << lines.at(24) << endl;
        cout << lines.at(25) << endl;
        cout << lines.at(26) << endl;
        cout << lines.at(27) << endl;
        cout << lines.at(28) << endl;
        cout << lines.at(5) << endl;
        cout << lines.at(6);
        k = InputInt(lang, lines);
        cout << endl;
        if (k == 0) {
            break;
        } else if (k == 1) {
            Creating(lang, t, lines);
        } else if (k == 2) {
            Creating(lang, e, lines);
        } else if (k == 3) {
            Creating(lang, s, lines);
        } else if (k == 4) {
            Creating(lang, c, lines);
        } else if (k == 5) {
            lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus);
        } else {
            cout << lines.at(41) << endl;
        }
    } while (k);

    return lang;
}

template <typename T>
bool Hiring(bool lang, Workshop& p, vector<T>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    int k;
    cout << endl << lines.at(29) << endl;
    bool key = ShowVec(lang, c, lines);
    if (!key) {
        cout << lines.at(38) << endl;
        return 0;
    }
    cout << endl << lines.at(31);
    k = InputInt(lang, lines);
    cout << endl;
    // seek for exact number
    int x = Search(c, 0, c.size()-1, k);
    if (x == -1) {
        cout << lines.at(32) << endl;
        return lang;
    }
    if (c[x].GetDepartment() != 0) {
        cout << lines.at(39) << endl;
        return lang;
    }
    p.Hire(c[x]);
    cout << lines.at(36) << c[x].GetFIO() << lines.at(40) << p.GetWorkshopName() << endl;
    return lang;
}

bool HireEmployee (bool lang, Workshop& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
                   vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    int k;
    do {
        cout << lines.at(24) << endl;
        cout << lines.at(25) << endl;
        cout << lines.at(26) << endl;
        cout << lines.at(27) << endl;
        cout << lines.at(28) << endl;
        cout << lines.at(5) << endl;
        cout << lines.at(6);
        k = InputInt(lang, lines);
        cout << endl;
        if (k == 0) {
            break;
        } else if (k == 1) {
            Hiring(lang, p, t, lines, file_eng, file_rus, eng, rus);
        } else if (k == 2) {
            Hiring(lang, p, e, lines, file_eng, file_rus, eng, rus);
        } else if (k == 3) {
            Hiring(lang, p, s, lines, file_eng, file_rus, eng, rus);
        } else if (k == 4) {
            Hiring(lang, p, c, lines, file_eng, file_rus, eng, rus);
        } else if (k == 5) {
            lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus);
        }
    } while (k);
    return lang;
}

template<typename T>
bool Firing (bool lang, Workshop& p, vector<T>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    int k;
    cout << endl << lines.at(29) << endl;
    bool key = 0;
    for (int i = 0; i < c.size(); ++i) {
        if (c[i].GetDepartment() == p.GetDepartment()) {
            cout << endl;
            c[i].OutputEmployee(lang, lines);
            cout << endl;
            key = 1;
        }
    }
    if (!key) {
        cout << lines.at(35) << endl;
        return lang;
    }
    cout << endl << lines.at(31);
    k = InputInt(lang, lines);
    cout << endl;
    // seek for exact number
    int x = Search(c, 0, c.size() - 1, k);
    if (x == -1) {
        cout << lines.at(32) << endl;
        return lang;
    }
    p.Fire(c[x]);
    cout << lines.at(36) << c[x].GetFIO() << lines.at(37) << p.GetWorkshopName() << endl;
    return lang;
}

bool FireEmployee (bool lang, Workshop& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
                   vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    int k;
    if (p.GetWorkersNum() < 1) {
        cout << lines.at(35) << endl;
        return lang;
    }
    do {
        cout << lines.at(24) << endl;
        cout << lines.at(25) << endl;
        cout << lines.at(26) << endl;
        cout << lines.at(27) << endl;
        cout << lines.at(28) << endl;
        cout << lines.at(5) << endl;
        cout << lines.at(6);
        k = InputInt(lang, lines);
        cout << endl;
        if (k == 0) {
            break;
        } else if (k == 1) {
            Firing(lang, p, t, lines, file_eng, file_rus, eng, rus);
        } else if (k == 2) {
            Firing(lang, p, e, lines, file_eng, file_rus, eng, rus);
        } else if (k == 3) {
            Firing(lang, p, s, lines, file_eng, file_rus, eng, rus);
        } else if (k == 4) {
            Firing(lang, p, c, lines, file_eng, file_rus, eng, rus);
        } else if (k == 5) {
            lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus);
        }
    } while (k);
    return lang;
}

template<typename T>
bool DeletingEmployee(bool lang, vector<Workshop>& p, vector<T>& t, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    int k;
    cout << endl << lines.at(29) << endl;
    bool key = ShowVec(lang, t, lines);
    if (!key) {
        cout << lines.at(30) << endl;
        return lang;
    }
    cout << endl << lines.at(31);
    k = InputInt(lang, lines);
    cout << endl;
    // seek for exact number
    int x = Search(t, 0, t.size()-1, k);
    if (x == -1) {
        cout << lines.at(32) << endl;
        return lang;
    }
    if (t[x].GetDepartment() == 0) {
        cout << lines.at(33) << endl;
    } else {
        int x2 = Search(p, 0, p.size()-1, t[x].GetDepartment());
        if (x2 == -1) {
            cout << lines.at(34) << endl;
        }
        p[x2].Fire(t[x]);
    }
    t.erase(t.begin()+x);
    return lang;
}

bool DeleteEmployee(bool lang, vector<Workshop>& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
                    vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    int k;
    do {
        cout << lines.at(24) << endl;
        cout << lines.at(25) << endl;
        cout << lines.at(26) << endl;
        cout << lines.at(27) << endl;
        cout << lines.at(28) << endl;
        cout << lines.at(5) << endl;
        cout << lines.at(6);
        k = InputInt(lang, lines);
        cout << endl;
        if (k == 0) {
            break;
        } else if (k == 1) {
            DeletingEmployee(lang, p, t, lines, file_eng, file_rus, eng, rus);
        } else if (k == 2) {
            DeletingEmployee(lang, p, e, lines, file_eng, file_rus, eng, rus);
        } else if (k == 3) {
            DeletingEmployee(lang, p, s, lines, file_eng, file_rus, eng, rus);
        } else if (k == 4) {
            DeletingEmployee(lang, p, c, lines, file_eng, file_rus, eng, rus);
        } else if (k == 5) {
            lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus);
        }
    } while (k);
    return lang;
}

// hire/fire
bool Change(bool lang, vector<Workshop>& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
            vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    int k;
    int pos_w;
    Workshop* cur = nullptr;
    do {
        if (cur == nullptr) {
            cout << lines.at(7) << endl << endl;
        } else {
            cout << lines.at(8) << cur->GetWorkshopName() << lines.at(9) << cur->GetDepartment() << endl << endl;
        }
        cout << lines.at(10) << endl;
        cout << lines.at(11) << endl;
        cout << lines.at(12) << endl;
        cout << lines.at(13) << endl;
        cout << lines.at(14) << endl;
        cout << lines.at(15) << endl;
        cout << lines.at(5) << endl;
        cout << lines.at(6);
        k = InputInt(lang, lines);
        cout << endl;
        if (k == 0) {
            break;
        } else if (k == 1) {
            for (int i = 0; i < p.size(); ++i) {
                cout << endl << lines.at(16) <<  p[i].GetWorkshopName() << endl << lines.at(17) << p[i].GetDepartment() <<
                     endl << lines.at(18) << p[i].GetWorkersNum() << endl << lines.at(19) << p[i].GetProductsNum() << endl;
            }
        } else if (k == 2) {
            cout << lines.at(20);
            pos_w = InputInt(lang, lines);
            int x = Search(p, 0, p.size()-1, pos_w);
            if (x == -1) {
                cout << endl << lines.at(21) << endl;
                continue;
            }
            cur = &p[x];
        } else if (k == 3) {
            if (cur == nullptr) {
                cout << endl << lines.at(22) << endl;
                continue;
            }
            lang = HireEmployee(lang, *cur, t, e, s, c, lines, file_eng, file_rus, eng, rus);
        } else if (k == 4) {
            if (cur == nullptr) {
                cout << endl << lines.at(22) << endl;
                continue;
            }
            lang = FireEmployee(lang, *cur, t, e, s, c, lines, file_eng, file_rus, eng, rus);
        } else if (k == 5) {
            if (cur == nullptr) {
                cout << endl << lines.at(22) << endl;
                continue;
            }
            int x = Search(p, 0, p.size()-1, cur->GetDepartment());
            if (p.size() < x+1) {
                cout << lines.at(23) << endl;
            }
            for (int i = 0; i < t.size(); ++i) {
                if (t[i].GetDepartment() == cur->GetDepartment())
                    cur->Fire(t[i]);
            }
            for (int i = 0; i < e.size(); ++i) {
                if (e[i].GetDepartment() == cur->GetDepartment())
                    cur->Fire(e[i]);
            }
            for (int i = 0; i < s.size(); ++i) {
                if (s[i].GetDepartment() == cur->GetDepartment())
                    cur->Fire(s[i]);
            }
            for (int i = 0; i < c.size(); ++i) {
                if (c[i].GetDepartment() == cur->GetDepartment())
                    cur->Fire(c[i]);
            }
            p.erase(p.begin()+x);
            cur = nullptr;
        }  else if (k == 7) {
            lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus);
        }
    } while (k);
    return lang;
}

bool Menu(bool lang, vector<Workshop>& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
          vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus, ofstream& file_out, string out) {
    int k=10;
    do {
        if (k) {
            cout << lines.at(0) << endl;
            cout << lines.at(1) << endl;
            cout << lines.at(2) << endl;
            cout << lines.at(3) << endl;
            cout << lines.at(63) << endl;
            cout << lines.at(64) << endl;
            cout << lines.at(5) << endl;
            cout << lines.at(6);
            k = InputInt(lang, lines);
            cout << endl << endl;
            if (k == 0) {
                continue;
            } else if (k == 1) {
                lang = CreateWorkshop(lang, p, lines);
            } else if (k == 2) {
                lang = CreateEmployee(lang, t, e, s, c, lines, file_eng, file_rus, eng, rus);
            } else if (k == 3) {
                lang = Change(lang, p, t, e, s, c, lines, file_eng, file_rus, eng, rus);
            } else if (k == 4) {
                lang = DeleteEmployee(lang, p, t, e, s, c, lines, file_eng, file_rus, eng, rus);
            } else if (k == 5) {
                lang = Save(lang, p, t, e, s, c, lines, file_out, out);
            } else if (k == 6) {
                lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus);
            }
        }
    } while (k);
    return lang;
}

void MainMenu (bool lang, vector<Workshop>& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
               vector<CEO>& c, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus,
               string& eng_about, string& rus_about, string& eng_prog, string& rus_prog, string& eng_screen, string& rus_screen) {
    PrintFile(eng_screen, lines);
    string out;
    string conf_path("/home/merso/CLionProjects/kurs/config.txt");
    out = Configuration(lang, conf_path, lines);
    ofstream file_out(out);
    int k=10;
    do {
        cout << lines.at(86) << endl;
        cout << lines.at(87) << endl;
        cout << lines.at(88) << endl;
        cout << lines.at(89) << endl;
        cout << lines.at(4) << endl;
        cout << lines.at(5) << endl;
        cout << lines.at(6);
        k = InputInt(lang, lines);
        cout << endl << endl;
        if (k == 0) {
            continue;
        } else if (k == 1) {
            if (lang) {
                PrintFile(eng_screen, lines);
            } else {
                PrintFile(rus_screen, lines);
            }
        } else if (k == 2) {
            if (lang) {
                PrintFile(eng_prog, lines);
            } else {
                PrintFile(rus_prog, lines);
            }
        } else if (k == 3) {
            if (lang) {
                PrintFile(eng_about, lines);
            } else {
                PrintFile(rus_about, lines);
            }
        } else if (k == 4) {
            lang = Menu(lang,p, t, e, s, c, lines, file_eng, file_rus, eng, rus, file_out, out);
        } else if (k == 5) {
            lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus);
        }
    } while (k);
}