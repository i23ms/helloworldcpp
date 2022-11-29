#include "std_lib_facilities.h"
void calculate_num_fmt(double x, double y, char operation);
void calculate_str_fmt(string x, string y, char operation);
double convert_str_to_double(string value);

int main() {
    double x;
    double y;
    string number_one;
    string number_two;
    char operation;
    char input_type;
    while (true) {
        cout << "Введите тип ввода:\n";
        cin >> input_type;
        if (input_type == 'q') break;

        if (input_type == 'n') {
            cout << "Введите два числа и операцию:\n";
            cin >> x >> y >> operation;
            calculate_num_fmt(x, y, operation);
        } else if (input_type == 's') {
            cout << "Введите два числа и операцию:\n";
            cin >> number_one >> number_two >> operation;
            calculate_str_fmt(number_one,  number_two, operation);
        } else {
            continue;
        }
    }
    
}

void calculate_num_fmt(double x, double y, char operation) {
    double result;

    switch(operation) {
        case '+': 
        {
            result = x + y;
            cout << "Sum of " << x << " and " << y << " equals " << result << '\n';
        }
            break;

        case '-':
        {
            result = x - y;
            cout << "Difference of " << x << " and " << y << " equals " << result << '\n';
        }
            break;

        case '*':
        {
            result = x * y;
            cout << "Multiplication of " << x << " and " << y << " equals " << result << '\n';
        }
            break;

        case '/':
        {
            result = x/y;
            cout << "Division of " << x << " and " << y << " equals " << result << '\n';
        }
            break;
    }
}


void calculate_str_fmt(string x, string y, char operation) {
    double result; 
    double fmtX = convert_str_to_double(x);
    double fmtY = convert_str_to_double(y);
    if (fmtX == -1 && 
         fmtY == -1) return;

    calculate_num_fmt(fmtX, fmtY, operation);
}

double convert_str_to_double(string value) {
   if (value == "zero") return 0;
   else if (value == "one") return 1;
   else if (value == "two") return 2;
   else if (value == "three") return 3;
   else if (value == "four") return 4;
   else if (value == "five") return 5;
   else if (value == "sex") return 6;
   else if (value == "seven") return 7;
   else if (value == "eight") return 8;
   else if (value == "nine") return 9;
   else return -1;
}