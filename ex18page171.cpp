#include "std_lib_facilities.h"
void get_quadratic_equation_answer(double a, double b, double c);

int main () {
    double a, b, c;
    cout << "Введите значения a, b и c для уравнения \na*b^2 + b*x + c = 0 :\n";
    cin >> a >> b >> c;
    cout << "Полученное уравнение: " << a << "*x^2 + " << b << "*x + " << c << "\n";
    get_quadratic_equation_answer(a, b, c);
}

void get_quadratic_equation_answer(double a, double b, double c) {
    double d = b*b - 4*a*c;
    if (d <= 0) {
        cout << "Решение: " << 
            "Действительных корней нет\n";
            return;
    }
    double sqrt_d = sqrt(d);
    double first_x = ((-1)*b + sqrt_d)/(2*a);
    double second_x = ((-1)*b - sqrt_d)/(2*a);
    cout << "Решение: \n" << 
        "x1 = " << first_x << "; x2 = " << second_x << '\n';
}