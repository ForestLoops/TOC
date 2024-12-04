#include <iostream>
#include <string>
using namespace std;

class FA_L1 {
public:
    bool accepts(const string& input) {
        return input.length() >= 4 && input.substr(0, 2) == input.substr(input.length() - 2);
    }
};

class FA_L2 {
public:
    bool accepts(const string& input) {
        return input.length() >= 2 && input[0] == 'a' && input.back() == 'b';
    }
};

bool unionFA(FA_L1& fa1, FA_L2& fa2, const string& input) {
    return fa1.accepts(input) || fa2.accepts(input);
}

bool intersectionFA(FA_L1& fa1, FA_L2& fa2, const string& input) {
    return fa1.accepts(input) && fa2.accepts(input);
}

bool concatenationFA(FA_L1& fa1, FA_L2& fa2, const string& input) {
    for (size_t i = 1; i < input.length(); ++i) {
        if (fa1.accepts(input.substr(0, i)) && fa2.accepts(input.substr(i))) {
            return true;
        }
    }
    return false;
}

int main() {
    FA_L1 fa1;
    FA_L2 fa2;
    string user_input;

    while (true) {
        cout << "Enter a string over the alphabet {a, b} (or type 'exit' to quit): ";
        getline(cin, user_input);

        if (user_input == "exit") break;

        if (user_input.find_first_not_of("ab") == string::npos) {
            cout << "\nAnalyzing string: '" << user_input << "'\n";
            cout << (unionFA(fa1, fa2, user_input) ? "Union: Accepted by L1 or L2.\n" : "Union: Rejected by both L1 and L2.\n");
            cout << (intersectionFA(fa1, fa2, user_input) ? "Intersection: Accepted by both L1 and L2.\n" : "Intersection: Rejected by at least one.\n");
            cout << (concatenationFA(fa1, fa2, user_input) ? "Concatenation: Can be split into L1 and L2 parts.\n" : "Concatenation: Cannot be split into L1 and L2 parts.\n");
        } else {
            cout << "Invalid input. Please enter only 'a' and 'b'.\n";
        }
    }
    return 0;
}
