#include "std_lib_facilities.h"
string get_string_mode(vector<string> values);
string get_max_string(vector<string> values);
string get_min_string(vector<string> values);

int main() {
    vector<string> values;
    string max_str;
    string min_str;
    string mode;

    cout << "Введите строковые значения: \n";
    for (string temp; cin >> temp;) {
        values.push_back(temp);
    }

    cout << "Вы ввели: ";
    for (string s: values) {
        cout << s << " ";
    }

    mode = get_string_mode(values);
    max_str = get_max_string(values);
    min_str = get_min_string(values);

    cout << "\nМода: " << mode 
        << "\nНаибольшее:" <<  max_str
        << "\nНаименьшее: " << min_str;

}

string get_string_mode(vector<string> values) {
    string mode = "nothing";
    int current_count;
    int max_count = 1;

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


string get_max_string(vector<string> values) {
    string max_str;
    for (int i = 0; i < values.size(); ++i) {
        if (i == 0) {
            max_str = values[i];
            continue;
        }
        if (values[i] > max_str) {
            max_str = values[i];
        }
    }
    return max_str;
}

string get_min_string(vector<string> values) {
    string min_str;
    for (int i = 0; i < values.size(); ++i) {
        if (i == 0) {
            min_str = values[i];
            continue;
        }
        if (values[i] < min_str) {
            min_str = values[i];
        }
    }
    return min_str;
}