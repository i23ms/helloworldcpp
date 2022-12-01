#include "std_lib_facilities.h"

bool is_simple_number(int value);

int main() {
    int wanted;
    int founded = 0;
    int current_number = 2;
    vector<int> result;
    cout << "Сколько первых простых чисел Вы желаете увидеть?\n";
    cin >> wanted;

    while (founded < wanted) {
        if (is_simple_number(current_number)) {
            result.push_back(current_number);
            ++founded;
        }
        ++current_number;
    }

    cout << "Найдено " << founded << " чисел:\n";
    for (int x: result) {
        cout << x << "\n";
    }
}

bool is_simple_number(int value) {
    int simple_flg = 0;
    for (int i = 1; i < value; ++i) {
        if (value % i == 0)  ++simple_flg;
    }
    if (simple_flg < 2) return true;
    return false;
}