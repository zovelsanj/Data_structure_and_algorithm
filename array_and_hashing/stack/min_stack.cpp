/*Minimum Stack (Medium)
Design a stack class that supports the push, pop, top, and getMin operations.
MinStack() initializes the stack object. void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack. int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
Each function should run in O(1) time.
*/

#include <stack>
#include <iostream>

class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;
public:
    MinStack(){}

    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || minStack.top() >= val) {
            minStack.push(val);
        }
    }
    
    void pop(){
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top(){
    return mainStack.top();
    }

    int getMin(){
        std::cout << "Min Element: " << minStack.top() << std::endl;
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin() << std::endl; // Returns -3
    minStack.pop();
    std::cout << minStack.top() << std::endl;    // Returns 0
    std::cout << minStack.getMin() << std::endl; // Returns -2
    return 0;
}
