#include <iostream>
#include <vector>
using namespace std;

void state2(vector<char> &, int);
void state3(vector<char> &, int);
void state4(vector<char> &, int);
void state5(vector<char> &, int);

void reject() {
    cout << "String is Rejected";
}

void state1(vector<char> &tape, int i)
{
    if (i >= tape.size()) { reject(); return; }
    if (tape[i] == 'a') { tape[i] = 'A'; state2(tape, i + 1); }
    else if (tape[i] == 'B') { state5(tape, i + 1); }
    else { reject(); }
}

void state2(vector<char> &tape, int i)
{
    if (i >= tape.size()) { reject(); return; }
    if (tape[i] == 'b') { tape[i] = 'B'; state3(tape, i + 1); }
    else if (tape[i] == 'a' || tape[i] == 'B') { state2(tape, i + 1); }
    else { reject(); }
}

void state3(vector<char> &tape, int i)
{
    if (i >= tape.size()) { reject(); return; }
    if (tape[i] == 'c') { tape[i] = 'C'; state4(tape, i - 1); }
    else if (tape[i] == 'b' || tape[i] == 'C') { state3(tape, i + 1); }
    else { reject(); }
}

void state4(vector<char> &tape, int i)
{
    if (i >= tape.size()) { reject(); return; }
    if (tape[i] == 'A') { state1(tape, i + 1); }
    else if (tape[i] == 'b' || tape[i] == 'C' || tape[i] == 'B' || tape[i] == 'a') { state4(tape, i - 1); }
    else { reject(); }
}

void state5(vector<char> &tape, int i)
{
    if (i >= tape.size()) { cout << "String is Accepted"; return; }
    if (tape[i] == 'B' || tape[i] == 'C') { state5(tape, i + 1); }
    else { reject(); }
}

int main()
{
    string w;
    vector<char> tape;
    cout << "Enter the string that you want to test (a's and b's): ";
    cin >> w;
    for (char ch : w) { tape.push_back(ch); }
    state1(tape, 0);
    return 0;
}
