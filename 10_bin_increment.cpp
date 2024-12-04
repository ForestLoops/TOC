#include <iostream>
#include <string>
using namespace std;

enum class State {
    q0,      
    q1,      
    qAccept, 
};

void incrementBinary(string& tape) {
    size_t head = tape.length() - 1; 
    State state = State::q0;          

    while (state != State::qAccept) {
        char currentSymbol = (head < tape.length()) ? tape[head] : '_'; 

        switch (state) {
            case State::q0:
                if (currentSymbol == '0') {
                    tape[head] = '1'; 
                    state = State::qAccept; 
                } else if (currentSymbol == '1') {
                    tape[head] = '0'; 
                    head--; 
                    state = State::q1; 
                } else {
                    state = State::qAccept; 
                }
                break;

            case State::q1:
                if (currentSymbol == '0') {
                    tape[head] = '1'; 
                    state = State::qAccept; 
                } else if (currentSymbol == '1') {
                    tape[head] = '0'; 
                    head--; 
                } else { 
                    
                    tape.insert(tape.begin(), '1'); 
                    state = State::qAccept; 
                }
                break;

            default:
                state = State::qAccept; 
                break;
        }
    }
}

int main() {
    string input;
    cout << "Enter a binary number: ";
    cin >> input;    
    for (char ch : input) {
        if (ch != '0' && ch != '1') {
            cout << "Invalid input! Only binary digits (0 or 1) are allowed." << endl;
            return 1;
        }
    }
    incrementBinary(input);
    cout << "Incremented binary number: " << input << endl;
    return 0;
}