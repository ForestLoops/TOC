#include <iostream>
using namespace std;

void state1(const string& w, int i);
void state2(const string& w, int i);
void state3(const string& w, int i);

void state1(const string& w, int i) {
    if (i == w.length()) {
        cout << "String is rejected" << endl;
        return;
    }
    if (w[i] == 'a') 
        state2(w, i + 1);
    else 
        cout << "String is rejected" << endl;
}

void state2(const string& w, int i) {
    if (i == w.length()) {
        cout << "String is rejected" << endl;
        return;
    }
    if (w[i] == 'a')
        state2(w, i + 1);
    else if (w[i] == 'b')
        state3(w, i + 1);
    else
        cout << "String is rejected" << endl;
}

void state3(const string& w, int i) {
    if (i == w.length()) {
        cout << "String is accepted" << endl;
        return;
    }
    if (w[i] == 'a' || w[i] == 'b')
        state3(w, i + 1);
    else
        cout << "String is rejected" << endl;
}

int main() {
    string w;
    cout << "Enter the string that you want to test (a's and b's): ";
    cin >> w;
    state1(w, 0);
    return 0;
}
