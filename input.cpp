#include "input.h"

int InputInt (bool lang, vector<string>& lines) {
    while (true) {
        int a;
        cin >> a;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << lines.at(42) << endl << lines.at(43);
        } else {
            return a;
        }
    }
}