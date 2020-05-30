#include <string>
#include <vector>

#include "employee.h"
#include "workshop.h"
#include "menu.h"

// Done: вывод работников не мультиязычен!!!
// Done: починить ввод продуктов (добавить проверку, прикрутить файлы)
// Done: использовать шаблоны, чтобы сократить код
// Done: прикрутить проверку на ввод
// Done: доработать методы InputWorkshop и InputEmployee, чтобы не вводились пустые строки и проверка на ввод
// Focking done: прикрутить файлы и конфигурацию
// Done: можно реализовать многоязычие как у овсянки на примере одной функции, которая подставляет либо английскую, либо русскую версию текста
// Done: сделать вывод проги в файл



int main() {
    vector<Workshop> p;
    vector<Turner> t;
    vector<Engineer> e;
    vector<Security> s;
    vector<CEO> c;
    vector<string> lines;
    lines.reserve(90);

    bool lang = 0;
    string eng("/home/merso/CLionProjects/kurs/eng.txt");
    string rus("/home/merso/CLionProjects/kurs/rus.txt");
    string eng_about("/home/merso/CLionProjects/kurs/eng_about.txt");
    string rus_about("/home/merso/CLionProjects/kurs/rus_about.txt");
    string eng_prog("/home/merso/CLionProjects/kurs/eng_prog.txt");
    string rus_prog("/home/merso/CLionProjects/kurs/rus_prog.txt");
    string eng_screen("/home/merso/CLionProjects/kurs/eng_screen.txt");
    string rus_screen("/home/merso/CLionProjects/kurs/rus_screen.txt");
    ifstream file_eng(eng);
    ifstream file_rus(rus);
    //подключаем файлы
    lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus);
    MainMenu(lang, p, t, e, s, c, lines, file_eng, file_rus, eng, rus, eng_about, rus_about, eng_prog, rus_prog, eng_screen, rus_screen);

    return 0;
}