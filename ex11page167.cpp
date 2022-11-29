#include "std_lib_facilities.h"

bool compare_double(double x, double y, double epsilon = 0.01f) {
    if (fabs(x-y) < epsilon) {
        return true;
    }
    return false;
}

double converter_to_cm(double number, string unit) {
    constexpr double m_to_cm = 100;
    constexpr double in_to_cm = 2.54;
    constexpr double ft_to_cm = 12 * in_to_cm;   

    if (unit == "cm") {
        return number;
    } else if (unit == "in") {
        return number * in_to_cm; 
    } else if (unit == "m") {
        return number * m_to_cm;
    } else if (unit == "ft") {
        return number * ft_to_cm;
    } else {
        return -1;
    }
}

double converter_cm_to_m(double number) {
    return number/100.0;
}

int main() {
    double x = -1;
    double y;
    double max_value;
    double min_value; 
    double sum = 0;
    int count = 0;

    string previous_unit;
    string last_unit;
    string max_value_unit;
    string min_value_unit;

    vector<double> v;
    

    cout << "please enter two variables : \n";
    while (cin >> y >> last_unit) { // y - last, x - previous   
        y = converter_to_cm(y, last_unit);  
        last_unit = "cm";
        if (y == -1) continue;

        if (x == -1) {
            cin >> x >> previous_unit;
            x = converter_to_cm(x, previous_unit);
            if (x == -1) continue;

            previous_unit = "cm";
            int temp = y;
            y = x;
            x = temp;
            string temp_unit = last_unit;
            last_unit = previous_unit;
            previous_unit = temp_unit;

            if (y > x) {
                max_value = y;
                max_value_unit = last_unit;

                min_value = x;
                min_value_unit = previous_unit;
            } else {
                max_value = x;
                max_value_unit = previous_unit;

                min_value = y;
                min_value_unit = last_unit;
            }

            sum += x;
            v.push_back(converter_cm_to_m(x));
            ++count;
        }

        if (y > max_value) {
            max_value = y;
            max_value_unit = last_unit;
            cout << "max value now: " << y << last_unit <<  '\n';
        }

        if (y < min_value) {
            min_value = y;
            min_value_unit = last_unit;
            cout << "min value now: " << y << last_unit << '\n';
        }
        
        if (x < y) {
            if (compare_double(x,y) && x!=y) {
                cout << "numbers are ~equals: " << x << previous_unit <<  " = " << y << last_unit << '\n';
            } else {
                cout << "last > previous:\t" << y << last_unit << " > " << x << previous_unit << '\n';
            }
        } else if (x > y) {
            if (compare_double(x,y) && x!=y) {
                cout << "numbers are ~equals: " << x << previous_unit << " = " << y << last_unit << '\n';
            } else {
                cout << "previous > last:\t" << x << previous_unit << " > " << y << last_unit << '\n';
            }
        } else {
            cout << "last = previous:\t" << y << last_unit << " = " << x << previous_unit << '\n';
        }
        cout << '\n';
        
        sum += y;
        v.push_back(converter_cm_to_m(y));
        ++count;
        x = y;
    }

    cout << "MAX_VALUE: " << converter_cm_to_m(max_value) << "m" << '\t'
        << "MIN_VALUE: " << converter_cm_to_m(max_value) << "m" << '\n'
        << "COUNT: " << count << "\n"
        << "SUM: " << converter_cm_to_m(sum) << "\n";
    
    sort(v);
    for (double value: v) {
        cout << value << "m" << '\n';
    }
}