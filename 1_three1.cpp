#include <iostream>
#include <string>
using namespace std;

bool finite_automaton(const string& input_string) {
    int current_state = 0; // Start at state q0
    for (char charac : input_string) {
        switch (current_state) {
            case 0: // q0
                current_state = (charac == '1') ? 1 : 0;
                break;
            case 1: // q1
                current_state = (charac == '1') ? 2 : 0;
                break;
            case 2: // q2
                current_state = (charac == '1') ? 3 : 0;
                break;
            case 3: // q3
                return true; // Accepted
        }
    }
    return current_state == 3; // Check if we end at q3
}

int main() {
    string input_string;
    cout << "Enter a string of '0's and '1's: ";
    getline(cin, input_string);

    // Validate the input
    for (char c : input_string) {
        if (c != '0' && c != '1') {
            cout << "Invalid input: only '0' and '1' are allowed." << endl;
            return 1;
        }
    }

    // Process the input with the finite automaton
    cout << (finite_automaton(input_string) ? "Accepted" : "Rejected") << endl;
    return 0;
}
