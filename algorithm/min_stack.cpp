#include <iostream>

using namespace std;

class MinStack {
public:
    MinStack() : m_size(0) {
        m_stack = new int[m_capacity];
    }

    ~MinStack() {
        delete m_stack;
        m_stack = nullptr;
    }

    void push(int x) {
        m_stack[m_size] = x;
        m_size++;
        this->expand();
    }

    void pop() {
        m_size--;
    }

    int top() {
        return m_stack[m_size - 1];
    }

    int getMin() {
        int x = this->top();
        for (int i = 0; i < m_size; i++) {
            if (m_stack[i] < x) {
                x = m_stack[i];
            }
        }
        return x;
    }
protected:
    void expand() {
        if (m_size == m_capacity) {
            m_capacity *= 2;
            int *new_array = new int[m_capacity];
            
            for (int i = 0; i < m_size; i++)
                new_array[i] = m_stack[i];
            
            delete m_stack;
            m_stack = new_array;
        }
    }
private:
    int   *m_stack;
    size_t m_size;
    size_t m_capacity = 64;
};

int main(int argc, char *argv[])
{
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl;
    minStack->pop();
    cout << minStack->top() << endl;
    minStack->getMin();
    delete minStack;
    minStack = nullptr;
    return 0;
}