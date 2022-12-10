#include "std_lib_facilities.h"
const string MONDAY = "monday";
const string TUESDAY = "tuesday";
const string WEDNESDAY = "wednesday";
const string THURSDAY = "thursday";
const string FRIDAY = "friday";
const string SATURDAY = "saturday";
const string SUNDAY = "sunday";
const vector<string> days = {
        MONDAY, TUESDAY, WEDNESDAY, THURSDAY,
        FRIDAY, SATURDAY, SUNDAY
};
vector <vector<int>> day_values (7);


bool add_value_to_day_map(int value, string day);
void print_all_days();
void print_day_sum();

int main() {
    string day;
    int value;
    
    cout << "Введите пары (день недели значение):\n" ;
    while (cin >> day >> value) {
        add_value_to_day_map(value, day);
    }
    // print_all_days();
    print_day_sum();
}

bool add_value_to_day_map(int value, string day) {
    bool is_success = true;
    if (day == MONDAY) {
            day_values[0].push_back(value);
        }
        else if (day == TUESDAY) {
            day_values[1].push_back(value);
        }
        else if (day == WEDNESDAY) {
            day_values[2].push_back(value);
        }
        else if (day == THURSDAY) {
            day_values[3].push_back(value);
        }
        else if (day == FRIDAY) {
            day_values[4].push_back(value);
        }
        else if (day == SATURDAY) {
            day_values[5].push_back(value);
        }
        else if (day == SUNDAY) {
            day_values[6].push_back(value);
        } else {
            is_success = false;
        }
    return is_success;
}

void print_all_days() {
    cout << '\n';
    for (int i = 0; i < day_values.size(); ++i) {
        if (day_values[i].size() == 0) continue;
        cout << days[i] << ": ";
        for (int value: day_values[i]) {
            cout << value << " ";
        }
        cout << "\n\n";
    }
}

void print_day_sum() {
    vector<int> day_sum;

    cout << '\n';
    for (int i = 0; i < day_values.size(); ++i) {
        if (day_values[i].size() == 0) continue;
        int sum = 0;
        cout << days[i] << ": ";
        for (int value: day_values[i]) {
            sum += value;
        }
        cout << sum;
        cout << "\n\n";
    }
}