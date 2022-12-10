#include "std_lib_facilities.h"

double get_sum_from_n_numbers(vector<double> values, int n);
int main() {
    vector<double> values;
    int n;
    double previous_num;
    double last_num;
    vector<double> substaction_vector;
    double substraction_for_two_elements;

    cout << "Введите целочисленные значения: \n";
    for (double temp; cin >> temp;) {
        values.push_back(temp);
    }
    cin.clear();
    
    cout << "\nВведите число N, чтобы посчитать сумму первых N чисел:\n";
    cin >> n; 
    try {
        cout << "\nРезультат: " << get_sum_from_n_numbers(values, n) << "\n\n";
    }
    catch (runtime_error& e) {
        cout << "Runtime custom info: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        cout << "something error\n";
    }
    cin.clear();    

    if (values.size() > 1) {
        for (int i = 1; i < values.size(); ++i) {
            previous_num = values[i-1];
            last_num = values[i];
            substraction_for_two_elements = last_num - previous_num;
            if (substraction_for_two_elements < 0) substraction_for_two_elements *= -1;
            substaction_vector.push_back(substraction_for_two_elements);
        }
        cout << "substraciont vector: \n";
        for (double value: substaction_vector) {
            cout << value << '\n';
        }
    }

}

double get_sum_from_n_numbers(vector<double> values, int n) {
    if (n > values.size()) throw runtime_error("Out of vector: " + n + '\n');
    double d_sum = 0;
    for (int i = 0; i < n; ++i) {
        d_sum += values[i];
    }
    return d_sum;
}


