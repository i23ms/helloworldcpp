#include "std_lib_facilities.h"

const string paper = "бумага";
const string rock = "камень";
const string scissors = "ножницы";
const string player = "Вы";
const string computer = "Компьютер";

char get_symbol_from_action(string action);
string get_winner(char first, char second);

int main() {

    const vector<string> answers = {
                                    rock, paper, scissors,
                                    scissors, paper, rock
                                    };

    int answers_size = answers.size();
    int answers_counter = 0;
    string current_winner;
    char your_action;
    char computer_action;
    int player_win = 0;
    int computer_win = 0;
    
    cout << "Введите значение: \n";
    for (string temp; cin >> temp;) {
        cout    << "Ваш ход: " << temp 
                << "\nХод компьютера: " <<  answers[answers_counter] << '\n';
            
        your_action = get_symbol_from_action(temp);
        if (your_action == '-') {
            cout << "Ваш ход не распознан. Попробуйте еще\n\n";
            continue;
        }
        computer_action = get_symbol_from_action(answers[answers_counter]);
        current_winner = get_winner(your_action, computer_action);

        if (current_winner == player) {
            ++player_win;
        } else if (current_winner == computer) {
            ++computer_win;
        } else {
            ++computer_win;
            ++player_win;
        }
        
        cout << "Победитель: " << current_winner << "\n";
        cout << "Счёт " << player_win << ':' << computer_win << "\n";
        cout << "Сыграем еще?\n\n";

        ++answers_counter;
        if (answers_counter == answers.size()) answers_counter = 0;
    }
    
}

char get_symbol_from_action(string action) {
    if (action == rock) {
        return 'r';
    } else if (action == paper) {
        return 'p';
    } else if (action == scissors) {
        return 's';
    } else {
        return '-';
    }
}

string get_winner(char first, char second) {
    if (first == second) return "Ничья!";

    switch (first) {
        case 'r': 
            {
                if (second == 'p') return computer;
                else if (second == 's') return player;
                break;
            }
        case 'p':
            {
                if (second == 'r') return player;
                else if (second == 's') return computer;
                break;
            }
        case 's':
            {
                if (second == 'p') return player;
                else if (second == 'r') return computer;
                break;
            }
        default:
            return "Nothing";
    }
    return "Nothing";
}