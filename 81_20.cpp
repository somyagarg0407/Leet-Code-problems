#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } 
        else {
            if(st.empty()) return false;

            if((st.top() == '(' && c == ')') ||
               (st.top() == '{' && c == '}') ||
               (st.top() == '[' && c == ']')) {
                st.pop();
            } 
            else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string s;

    cout << "Enter expression: ";
    cin >> s;

    if(isValid(s)) {
        cout << "Expression is balanced :)";
    } else {
        cout << "Expression is not balanced :(";
    }

    return 0;
}