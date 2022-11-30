#include "std_lib_facilities.h"
#include <limits.h>

int get_cell_count(int number);

int main () {
    int user_input;
    while (true) {
        cout << "Введите желаемое количество риса\n(для выхода введите -1): \n";
        cin >> user_input;
        if (user_input == -1) break;
        cout << "Вам необходимо " << get_cell_count(user_input) << " клеток\n\n";
    }

}

int get_cell_count(int number) {
    int current_cell;
    int current_cell_content;
    int all_cell_sum = 0;
    int multi_step;
    if (number < 1) return -1;

    for (current_cell = 0; all_cell_sum < number; ++current_cell) {   
        current_cell_content = 0;
        multi_step = 1;
        if (current_cell == 0) {
            current_cell_content = 1;
            all_cell_sum += 1;
            // cout    << "current_cell: " << current_cell+1 << '\n'
            //         << "cell_content: " << current_cell_content << '\n'
            //         << "all_cell_sum: " << all_cell_sum << "\n\n";
            if (number == 1) return current_cell+1;
            continue;
        }

        for (int i = 1; i <= current_cell; ++i) {
            multi_step *=2; 
        }
        current_cell_content = multi_step;
        all_cell_sum += current_cell_content;
        
        // cout    << "current_cell: " << current_cell+1 << '\n'
        //         << "cell_content: " << current_cell_content << '\n'
        //         << "all_cell_sum: " << all_cell_sum << "\n\n";

    }

    return current_cell;
}