#include "std_lib_facilities.h"

vector<int> get_simple_num_vector(int maxvalue);

int main() {
    int max_value = 100;
    vector<int> v = get_simple_num_vector(max_value);
    for (int x: v) {
        cout << x << "\n";
    }

    
}


vector<int> get_simple_num_vector(int maxvalue) {
    vector<int> raw;
    vector<int> result;

    for (int i = 0; i <= 100; ++i) {
        raw.push_back(i);
    }

    raw[1] = 0;
    for (int i = 2; i*i <= maxvalue; ++i) {
        if (raw[i] != 0) {
            for (int j = i*i; j <= maxvalue; j+=i) {
                raw[j] = 0;
            }
        }
    }

    for (int i = 0; i <= maxvalue; ++i) {
        if (raw[i] != 0) {
            result.push_back(raw[i]);
        }
    }
    
    return result;
}