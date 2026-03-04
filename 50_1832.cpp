#include <iostream>
#include <unordered_set>
using namespace std;

bool checkIfPangram(string sentence) {
    unordered_set<char> letters;

    for(int i = 0; i < sentence.length(); i++){
        letters.insert(sentence[i]);
    }

    return letters.size() == 26;
}

int main() {
    string sentence;
    cin >> sentence;
    cout << checkIfPangram(sentence);
    return 0;
}