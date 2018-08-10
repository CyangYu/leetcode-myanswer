#include "common.h"

USESTD

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        pushQueue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (pushQueue.empty())
            return INT_MIN;

        while (pushQueue.size() > 1) {
            popQueue.push(pushQueue.front());
            pushQueue.pop();
        }

        int elem = pushQueue.front();
        pushQueue.pop();

        while (!popQueue.empty()) {
            pushQueue.push(popQueue.front());
            popQueue.pop();
        }

        return elem;
    }
    
    /** Get the top element. */
    int top() {
        if (pushQueue.empty())
            return INT_MIN;

        return pushQueue.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return pushQueue.empty() && popQueue.empty();
    }

private:
    queue<int> pushQueue;
    queue<int> popQueue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

int main(int argc, char *argv[])
{
    MyStack mystack;

    mystack.push(1);
    mystack.push(2);
    mystack.push(3);

    cout << mystack.pop() << endl;
    cout << mystack.pop() << endl;
    cout << mystack.pop() << endl;
    cout << mystack.empty();
    return 0;
}