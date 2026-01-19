/*Evaluate Reverse Polish Notation (Medium)
You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.
Return the integer that represents the evaluation of the expression.
The operands may be integers or the results of other operations.
The operators include '+', '-', '*', and '/'.
Assume that division between integers always truncates toward zero.
*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>

class ReversePolish {
public:
    int operation(int x, int y, std::string op){
        switch (op.c_str()[0]){
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        default: throw std::invalid_argument("Invalid operator");
        }
    }

    int evalRPN(std::vector<std::string>& tokens){
        std::stack<int> result;
        for (size_t i = 0; i < tokens.size(); ++i){
            std::string token = tokens[i];
            if (token=="+" || token=="-" || token=="*" || token=="/"){
                int y = result.top();
                result.pop();
                int x = result.top();
                result.pop();
                result.push(operation(x, y, token));
            }
            else
                result.push(std::stoi(token));
        }
        return result.top();
    }
};
int main(){
    std::vector<std::string> tokens = {"2","1","+","3","*"};
    ReversePolish rp;
    std::cout << rp.evalRPN(tokens) << std::endl;
    tokens = {"4","13","5","/","+"};
    std::cout << rp.evalRPN(tokens) << std::endl;
}
