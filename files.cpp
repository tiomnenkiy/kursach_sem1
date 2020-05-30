#include "files.h"

bool ChangeLang (bool lang, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    lines.clear(); // тут нельзя использовать lines
    string line;

    if (!lang) {
        lang = 1;
        FileManager(lang, file_eng, eng, 90, lines);
        if (!file_eng.is_open()) {
            file_eng.open(eng);
            if(!file_eng.is_open()) {
                cout << "we can't open file " << eng << endl;
                exit(-1);
            }
        }

        while (file_eng) {
            getline(file_eng, line);
            lines.push_back(line);
        }
        file_eng.close();
    } else {
        lang = 0;
        FileManager(lang, file_rus, rus, 90, lines);
        if (!file_rus.is_open()) {
            file_rus.open(rus);
            if(!file_rus.is_open()) {
                cout << "не можем открыть файл " << rus << endl;
                exit(-1);
            }
        }

        while (file_rus) {
            getline(file_rus, line);
            lines.push_back(line);
        }
        file_rus.close();
    }
    return lang;
}

bool FileManager(bool lang, ifstream& file, string name, int stringInFile, vector<string>& lines) {
    if (!file.is_open()) {
        file.open(name);
        if(!file.is_open()) {
            cout << lines.at(77) << name << endl;
            exit(-1);
        }
    }

    string str;
    file.unsetf(std::ios_base::skipws);

    unsigned line_count = count(istream_iterator<char>(file), istream_iterator<char>(), '\n');
    line_count++;
    if (line_count< stringInFile) {
        cout << lines.at(78) << name << lines.at(79) << endl;
        exit(-1);
    }
    if (line_count > stringInFile) {
        cout << lines.at(78) << name << lines.at(80) << endl;
        exit(-1);
    }
    file.close();
    return lang;
}

template<typename T>
bool GetEmployee (bool lang, vector<T>& t, vector<string>& lines, ofstream& file_out, string out) {
    file_out << lines.at(66) << t.size() << endl;
    for (int i = 0; i < t.size(); ++i) {
        file_out << lines.at(57) << t[i].GetFIO() << endl;
        if (t[i].GetDepartment() == 0) {
            file_out << lines.at(72) << endl;
        }
        file_out << lines.at(62) << t[i].GetDepartment() << endl;
        file_out << lines.at(59) << t[i].GetAge() << endl;
        file_out << lines.at(60) << t[i].GetStage() << endl;
        file_out << lines.at(61) << t[i].GetExpirience() << endl;
        file_out << lines.at(73) << t[i].GetHealth() << endl;
        file_out << lines.at(74) << t[i].GetEndurance() << endl;
        file_out << lines.at(75) << t[i].GetAgility() << endl;
        file_out << lines.at(76) << t[i].GetIntellect() << endl << endl;
    }
    return lang;
}

bool Save (bool lang, vector<Workshop>& p, vector<Turner>& t, vector<Engineer>& e, vector<Security>& s,
           vector<CEO>& c, vector<string>& lines, ofstream& file_out, string out) {
    if (!file_out.is_open()) {
        file_out.open(out);
        if(!file_out.is_open()) {
            cout << lines.at(77) << out << endl;
            exit(-1);
        }
    }

    file_out << lines.at(65) << endl;
    file_out << lines.at(66) << p.size() << endl << endl;
    for (int i = 0; i < p.size(); ++i) {
        file_out << lines.at(16) << p[i].GetWorkshopName() << endl;
        file_out << lines.at(17) << p[i].GetDepartment() << endl << lines.at(18) << p[i].GetWorkersNum() << endl << lines.at(52);
        p[i].DisplayProducts(lines, file_out);
        file_out << endl;
    }
    file_out << lines.at(67) << endl << endl;
    file_out << lines.at(68) << endl << endl;
    GetEmployee(lang, t, lines, file_out, out);
    file_out << lines.at(69) << endl << endl;
    GetEmployee(lang, e, lines, file_out, out);
    file_out << lines.at(70) << endl;
    GetEmployee(lang, s, lines, file_out, out);
    file_out << lines.at(71) << endl << endl;
    GetEmployee(lang, c, lines, file_out, out);

    file_out.close();
    return lang;
}

string Configuration(bool lang, string conf_path, vector<string>& lines) { // понятия не имею
    int k;
    string path;
    ifstream conf(conf_path);
    if (!conf.is_open()) {
        conf.open(conf_path);
        if(!conf.is_open()) {
            cout << lines.at(77) << conf_path << endl;
            exit(-1);
        }
    }
    conf >> path;
    cout << lines.at(81) << path << endl << lines.at(82) << endl;
    cout << lines.at(83) << endl;
    cout << lines.at(84) << endl;
    cout << lines.at(6);
    k = InputInt(lang, lines);
    if (k) {
        cout << lines.at(85);
        cin >> path;
        while (path.empty()) {
            cout << lines.at(42) << endl << lines.at(43) << endl;
            cin >> path;
        }
    }
    ofstream file(path);
    if (!file.is_open()) {
        file.open(path);
        if(!file.is_open()) {
            cout << lines.at(77) << path << endl;
            exit(-1);
        }
    }
    file.close();
    ofstream conf2(conf_path);
    if (!conf2.is_open()) {
        conf2.open(conf_path);
        if(!conf2.is_open()) {
            cout << lines.at(77) << conf_path << endl;
            exit(-1);
        }
    }
    conf2 << path;
    conf.close();
    return path;
}

void PrintFile(string path, vector<string>& lines) {
    ifstream file(path);
    if (!file.is_open()) {
        file.open(path);
        if(!file.is_open()) {
            cout << lines.at(77) << path << endl;
            exit(-1);
        }
    }
    string str;
    getline(file, str);
    while (file) {
        cout << str << endl;
        getline(file, str);
    }
    file.close();
}