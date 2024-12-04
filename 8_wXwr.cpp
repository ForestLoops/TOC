#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isAccepted(const string& input) {
    stack<char> pdaStack;
    int i = 0;    
    while (i < input.length() && input[i] != 'X') {
        pdaStack.push(input[i]);
        i++;
    } 

    if (i >= input.length() || input[i] != 'X') {
        return false;
    }
    i++; 

    while (i < input.length()) {
        if (pdaStack.empty() || pdaStack.top() != input[i]) {
            return false;  
        }
        pdaStack.pop();
        i++;
    }    
    return pdaStack.empty();
}

int main() {
    string input;
    cout << "Enter a string to test (wXwr pattern): ";
    cin >> input;
    if (isAccepted(input)) {
        cout << "The string is accepted by the PDA." << endl;
    } else {
        cout << "The string is rejected by the PDA." << endl;
    }
    return 0;
}
