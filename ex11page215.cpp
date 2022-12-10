#include "std_lib_facilities.h"

vector<int> get_fibonacci_sequence(int count);

int main() {
    vector<int> result;
    result = get_fibonacci_sequence(10);
    for (int value: result) {
        cout << value << '\n';
    }
}

vector<int> get_fibonacci_sequence(int count) {
    vector<int> fib_vector;
    int inner_counter = 0;
    int previous_num = 1;
    int last_num = 1;
    int num_sum = 0;

    fib_vector.push_back(previous_num); 
    fib_vector.push_back(last_num);

    while (inner_counter < count) {
        num_sum = previous_num + last_num;
        fib_vector.push_back(num_sum);

        previous_num = last_num;
        last_num = num_sum;
        ++inner_counter;
    }

    return fib_vector;
}