#include "common.h"

USESTD

class MyCircularQueue {
public:
        MyCircularQueue(int k)
        : array(new int[k]),
          front(0),
          rear(-1),  
          capacity(k),
          size(0)
    {
    }
    
    ~MyCircularQueue() {
        delete[] array;
        array = nullptr;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;
        
        rear = (rear + 1) % capacity;
        array[rear] = value;
        size++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;
            
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty())
            return -1;
        
        return array[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;
        
        return array[rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == capacity;
    }

private:
    int *array;
    int front, rear;
    int capacity;
    int size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */

int main(int argc, char *argv[])
{
    MyCircularQueue myqueue(3);
    cout << myqueue.enQueue(1) << endl;
    cout << myqueue.enQueue(2) << endl;
    cout << myqueue.enQueue(3) << endl;
    cout << myqueue.enQueue(4) << endl;
    cout << myqueue.Rear() << endl;
    cout << myqueue.isFull() << endl;
    cout << myqueue.deQueue() << endl;
    cout << myqueue.enQueue(4) << endl;
    cout << myqueue.Rear() << endl;
    return 0;
}