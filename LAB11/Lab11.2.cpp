#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class DynamicStack {
private:
    vector<string> stack;

public:
    void push(string word) {
        stack.push_back(word);
    }

    string pop() {
        if (stack.empty()) {
            return "";
        }
        string word = stack.back();
        stack.pop_back();
        return word;
    }

    string peek() {
        if (stack.empty()) {
            return "";
        }
        return stack.back();
    }

    string reverseSentence(string sentence) {
        stringstream ss(sentence);
        string word, result;
        
        while (ss >> word) {
            push(word);
        }
        
        while (!stack.empty()) {
            string reversedWord;
            string originalWord = pop();
            for (int i = originalWord.length() - 1; i >= 0; i--) {
                reversedWord += originalWord[i];
            }
            result += reversedWord + " ";
        }
        
        return result;
    }
};

int main() {
	cout << " The code is written by MESUM ABBAS CT-238" << endl;
    DynamicStack stack;
    string input;

    cout << "Enter a sentence: ";
    getline(cin, input);

    string reversed = stack.reverseSentence(input);
    cout << "Reversed words: " << reversed << endl;

    return 0;
}
