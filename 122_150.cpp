#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int num1, num2;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                num2 = st.top();
                st.pop(); 
                num1 = st.top();
                st.pop(); 

                if (tokens[i] == "+") {
                    st.push(num1 + num2);
                }
                else if (tokens[i] == "-") {
                    st.push(num1 - num2);
                } 
                else if (tokens[i] == "*") {
                    st.push(num1 * num2);
                } 
                else if (tokens[i] == "/") {
                    st.push(num1 / num2);
                } 
            }
            else {
                st.push(stoi(tokens[i])); 
            }
        }
        return st.top();
    }
};

int main() {
    Solution solver;
    vector<string> test_tokens = {"2", "1", "+", "3", "*"};
    int result = solver.evalRPN(test_tokens);
    cout << "The result of the RPN expression is: " << result << endl;
    return 0;
}