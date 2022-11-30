#include "std_lib_facilities.h"

bool is_simple_number(int value);

int main() {
    vector<int> result;
    int max_value;
    cout << "Введите верхнюю границу простых чисел:\n";
    cin >> max_value;
    cout << "\nПоиск всех простых чисел от 0 до " << max_value << '\n';
    for (int i = 2; i < max_value; ++i) {
        if (is_simple_number(i)) {
            result.push_back(i);
        }
    }

    for (int value: result) {
        cout << value << '\n';
    }

}

bool is_simple_number(int value) {
    bool result = false;
    int simple_flg = 0;
    
    for (int i = 1; i < value; ++i) {
        if (value % i == 0) {
            ++simple_flg;
        }
    }
    if (simple_flg < 2) result = true; 

    return result;
}