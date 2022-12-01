#include "std_lib_facilities.h"

int main() {

    vector<string> names;
    vector<int> scores;
    string name;
    int score;

    cout << "Введите пару значений: \nName(строка) Score(число): \n";
    while (cin >> name >> score) {
        if (name == "NoName" && score == 0) break;
        if (names.size() == 0) {
            names.push_back(name);
            scores.push_back(score);
            continue;
        }

        for (int i = 0; i < names.size(); ++i) {
            if (name == names[i]) {
                cout << "Ошибка: Имя(" << name << ") уже есть в списке\n";
            }
        }
        names.push_back(name);
        scores.push_back(score);
    }

    // cout << "\n\nСписок:\n";
    // for (int i = 0; i < names.size(); ++i) {
    //     cout << names[i] << " = " << scores[i] << '\n';
    // }

    int num_search_flg;
    cout << "Выберите фильтр поиска (1 или 2):\n"
        << "\t1. По имени\n"
        << "\t2. По количеству баллов\n";
    while (cin >> num_search_flg) {
        if (num_search_flg == 2) {
            vector<string> fouded_students;
            int temp_score;
            bool not_fouded = true;
            cout << "Введите кол-во баллов: \n";
            cin >> temp_score;

            for (int i = 0; i < scores.size(); ++i) {
                if (temp_score == scores[i]) {
                    not_fouded = false;
                    fouded_students.push_back(names[i]);
                }
            }
            if (not_fouded) {
                cout << "Баллы не найдены\n";
                continue;
            }

            cout << "Список студентов: \n";
            for (string name: fouded_students) {
                cout << name << "\n";
            }

            cout << "\nВыберите фильтр поиска (1 или 2):\n"
            << "\t1. По имени\n"
            << "\t2. По количеству баллов\n";
        } 
        else if (num_search_flg == 1) {
            string temp_name;
            bool not_founded = true;
            cout << "Введите имя: \n";
            cin >> temp_name;
            
            for (int i = 0; i < names.size(); ++i) {
                if (temp_name == names[i]) {
                    not_founded = false;
                    cout << names[i] << " = " << scores[i] << '\n';
                }
            }
            if (not_founded) cout << "Имя не найдено\n";

            cout << "\nВыберите фильтр поиска (1 или 2):\n"
            << "\t1. По имени\n"
            << "\t2. По количеству баллов\n";
        } 
        else {
            cout << "\nВыберите фильтр поиска (1 или 2):\n"
            << "\t1. По имени\n"
            << "\t2. По количеству баллов\n";
            continue;
        }
    }
}
