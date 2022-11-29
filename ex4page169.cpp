#include "std_lib_facilities.h"

int main() {
    int begin = 1;
    int end = 100;
    int middle;
    char answer;
    int count = 0;
    cout << "Загадайте число от " << begin << " до " << end << ", \nа мы попробуем его отгадать!:\n";
    for (;;) {
        ++count;
        middle = (begin + end) / 2;

        cout << "Вы загадали число " << middle << "?\n(y/n):";
        cin >> answer;
        if (answer == 'y') {
            cout << "Это было легко!"
                << "Всего за " << count << " попыток!\n";
            return 0;
        };

        cout << "Задуманное число меньше " << middle << "?\n(y/n): ";
        cin >> answer;

        if (answer == 'y') {
            end = middle - 1;
        } else if (answer == 'n') {
            begin = middle + 1;
        }
    }
}