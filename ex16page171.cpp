#include "std_lib_facilities.h"

int get_mode(vector<int> values);
int main () {
    vector<int> values;
    cout << "Пожалуйста введите набор чисел: \n";
    for (int temp; cin >> temp;) {
        values.push_back(temp);
    }
    cout << "Вы ввели: ";
    for (int x: values) cout << x << " ";
    cout << "\nМода для данного набора чисел: " << get_mode(values) << "\n";
}

int get_mode(vector<int> values) {
    int mode = -1;
    int max_count = 1 ;
    int current_count;
    

    for (int i = 0; i < values.size(); ++i) {
        current_count = 0;
        for (int j = 0; j < values.size(); ++j) {
            if (values[i] == values[j]) {
                ++current_count;
            }
        }

        if (current_count > max_count) {
            max_count = current_count;
            mode = values[i];
        }
    }
    return mode;
}