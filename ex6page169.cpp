#include "std_lib_facilities.h"

string converter_str_to_num(int value) {
    vector<string> values = {
                            "zero", "one", "two", "three",
                            "four", "five", "six",
                            "seven", "eight", "nine"
                        };
    if (value >= values.size()) return "-1";

    return values[value];
        
}
int main() {
   int x;
   while (cin >> x) {
        cout << converter_str_to_num(x) << "\n";
   }
}