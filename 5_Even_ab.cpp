#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

bool simulate_even_even(const std::string& input_string) {    
    int q0 = 0;  
    int q1 = 1;  
    int q2 = 2;  
    int q3 = 3;      
    int current_state = q0;    
    for (char charac : input_string) {
        if (current_state == q0) {
            if (charac == 'a') {
                current_state = q1;  
            } else if (charac == 'b') {
                current_state = q2;  
            }
        } else if (current_state == q1) {
            if (charac == 'a') {
                current_state = q0;  
            } else if (charac == 'b') {
                current_state = q3;  
            }
        } else if (current_state == q2) {
            if (charac == 'a') {
                current_state = q3;  
            } else if (charac == 'b') {
                current_state = q0;  
            }
        } else if (current_state == q3) {
            if (charac == 'a') {
                current_state = q2;  
            } else if (charac == 'b') {
                current_state = q1;  
            }
        } else {
            std::cerr << "Invalid state." << std::endl;
            return false;
        }
    }    
    return current_state == q0;
}

int main() {
    string input_string;
    cout << "Enter a string of 'a's and 'b's: ";
    cin >> input_string;    
    for (char c : input_string) {
        if (c != 'a' && c != 'b') {
            cout << "Invalid character: only 'a' and 'b' are allowed." << std::endl;
            return 1;
        }
    }
    if (simulate_even_even(input_string)) {
        cout << "Accepted" << std::endl;
    } else {
        cout << "Rejected" << std::endl;
    }
    return 0;
}
