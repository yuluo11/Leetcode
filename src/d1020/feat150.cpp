#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::vector<int> temp(tokens.size());
        int top = 0;

        for (const std::string& token : tokens) {
            if (token.size() == 1 &&
                (token[0] == '+' || token[0] == '-' ||
                 token[0] == '*' || token[0] == '/')) {
                int tmp = 0;

                switch (token[0]) {
                    case '+':
                        tmp = temp[top - 2] + temp[top - 1];
                        break;
                    case '-':
                        tmp = temp[top - 2] - temp[top - 1];
                        break;
                    case '*':
                        tmp = temp[top - 2] * temp[top - 1];
                        break;
                    case '/':
                        tmp = temp[top - 2] / temp[top - 1];
                        break;
                }

                top -= 2;
                temp[top] = tmp;
                top++;
            } else {
                temp[top] = std::stoi(token);
                top++;
            }
        }

        return temp[top - 1];
    }
};
