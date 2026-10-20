#include <string>
#include <vector>

class Solution {
public:
    bool isValid(std::string s) {
        std::vector<char> temp(s.size());
        int top = 0;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                temp[top] = ch;
                top++;
            } else {
                if (top == 0) {
                    return false;
                }

                if (temp[top - 1] == '(' && ch == ')') {
                    top--;
                } else if (temp[top - 1] == '[' && ch == ']') {
                    top--;
                } else if (temp[top - 1] == '{' && ch == '}') {
                    top--;
                } else {
                    return false;
                }
            }
        }

        return top == 0;
    }
};
