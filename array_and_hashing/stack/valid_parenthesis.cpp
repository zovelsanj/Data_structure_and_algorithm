/*20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Input: s = "()[]{}", Output: true
Input: s = "(]", Output: false*/
#include<iostream>
#include<stack>
using namespace std;

class Parentheses {
public:
    bool isValid(string s) 
    {
        stack<char> stack;
        for (auto &bracket:s)
        {
            if (bracket=='('|| bracket=='{' || bracket=='[')
                stack.push(bracket);
            
            if (stack.empty())
                return false;

            switch (bracket)
            {
            case ')':
                if (stack.top()=='{'||stack.top()==']')
                    return false;
                stack.pop();
                break;
            case '}':
                if (stack.top()=='('||stack.top()==']')
                    return false;
                stack.pop();
                break;
            case ']':
                if (stack.top()=='{'||stack.top()=='(')
                    return false;
                stack.pop();
                break;
            }
        }
        return (stack.empty());
    }
};

int main()
{
    string s = "()[]{}"; //"(]"
    Parentheses p;
    cout<<p.isValid(s)<<endl;
}
