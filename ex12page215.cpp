#include "std_lib_facilities.h"

bool is_bull(int element, int position, vector<int> secret_vector);
bool is_cow(int element, int position, vector<int> secret_vector);
bool is_unique_element(int element, vector<int> values);
bool is_valid_number(int element);
bool is_valid_vector(vector<int> values);
vector<int> convert_int_to_vector(int number);
void start_game(int mode);
void print(string str);
string compare_two_vectors(vector<int> first_vector, vector<int> second_vector, int difficult_flg);
void print_try_again();

int main() {
    // start_game(int mode) принимает параметр сложности игры 1 или 2: 
    // 1 - показывает позицию быков, 2 - только сообщает об их наличии
    int mode;
    cout << "Выберите уровень сложности(1 или 2): ";
    cin >> mode;
    cout << '\n';
    start_game(mode);
}

void start_game(int mode) {
    if (mode != 1 && mode != 2) throw runtime_error("Введите корректный режим игры: 1 или 2\n");
    int input;
    const string exit_condition = "bull bull bull bull ";
    vector<int> input_vector;
    vector<int> secret_vector = { 5, 6, 7, 8 };

    cout << "\nДавайте сыграем в игру \"Быки и коровы\".\nВам необходимо отгадать четырёхзначное число, в котором каждая цифра уникальна.\nВаш вариант? \n";
    while (cin >> input) {
        input_vector = convert_int_to_vector(input);
        if (!is_valid_vector(input_vector)) {
            print("Вы ввели некорректное значение.\nПопробуйте еще раз:\n");
            continue;
        } else {
            // print ("Debug: Значение корректно");
        }

        if(compare_two_vectors(input_vector, secret_vector, mode) == exit_condition) {
            print("Игра закончена! Вы выиграли!");
            break;
        }
        
        print_try_again();
    }
}

void print(string str) {
    cout << '\n' << str << '\n';
}

bool is_valid_number(int element) {
    if ((element >= 0) && (element <= 9)) {
        return true;
    } else {
        return false;
    }
}

bool is_unique_element(int element, vector<int> values) {
    int unique_flg = 0;
    string error;
    string str_vector = "";
    for (int value: values) {
        if (element == value) ++unique_flg;
        str_vector += value;
    }

    if (unique_flg > 1) {
        return false;
    } else if (unique_flg == 1) {
        return true;
    } else {
        error = "Элемент " + to_string(element) + " отсутствует в массиве " + str_vector + '\n';
        throw runtime_error(error);
    }

}

bool is_valid_vector(vector<int> values) {
    bool is_valid_flg = true;
    for (int value: values) {
        if ((!is_valid_number) || (!is_unique_element(value, values))) {
            is_valid_flg = false;
        }
    }
    return is_valid_flg;
}

vector<int> convert_int_to_vector(int number) {
    if (number > 9999) throw runtime_error("Вы ввели: " + to_string(number) + ". Необходимо ввести четырехзначное число!\n");
    vector<int> result;
    int first_digit;
    int second_digit;
    int third_digit;
    int fourth_digit;
    
    first_digit = number/1000;
    second_digit = (number/100) % 10;
    third_digit = (number % 100) / 10;
    fourth_digit = (number % 100) % 10;
    // print ("debug: ");
    // print(to_string(first_digit) + " " + to_string(second_digit) + " " + to_string(third_digit) + " " + to_string(fourth_digit));

    result = {first_digit, second_digit, third_digit, fourth_digit};
    return result;
}

string compare_two_vectors(vector<int> first_vector, vector<int> second_vector, int difficult_flg) {
    if (first_vector.size() != second_vector.size()) throw runtime_error("Векторы имеют неодинаковые размеры\n");
    string result = "";
    int bull_counter = 0;
    int cow_counter = 0;

    for (int i = 0; i < first_vector.size(); ++i) {
        if (is_bull(first_vector[i], i, second_vector)) {
            if (difficult_flg == 1) {
                result += "bull ";
            } 
            else if (difficult_flg == 2) {
                ++bull_counter;
            }
            continue;
        }
        else if (is_cow(first_vector[i], i, second_vector)) {
            if (difficult_flg == 1) {
                result += "cow ";
            } else if (difficult_flg == 2) {
                ++cow_counter;
            }
            continue;
        }
        else {
            if (difficult_flg == 1) {
                result = result + to_string(first_vector[i]) + " ";
            }
        }
    }
    if (difficult_flg == 2) result = "Bulls: " + to_string(bull_counter) + ", Cows: " + to_string(cow_counter) + '\n';
    print(result);
    return result;
}

bool is_bull(int element, int position, vector<int> secret_vector) {
    bool result = false;
    if (element == secret_vector[position]) result = true;
    return result;
}


bool is_cow(int element, int position, vector<int> secret_vector) {
    bool result = false;
    for (int value: secret_vector) {
        if (element == value) result = true;
    }
    return result;
}

void print_try_again() {
    cout << "Попробуйте ещё!\n\nВаш вариант?\n";
}