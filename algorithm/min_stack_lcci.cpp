#include "common.h"

USESTD 

class MinStack {
public:
    MinStack() {
        list = vector<int>();
        min = INT_MAX;
        index = -1;
    }
    
    void push(int x) {
        if (x < min) {
            min = x;
        }

        list[++index] = x;
    }
    
    void pop() {
        if (index > -1) {
            index--;
        }
    }
    
    int top() {
        return list[index];
    }
    
    int getMin() {
        return min;
    }
private:
    int min;
    int index;
    vector<int> list;
};
