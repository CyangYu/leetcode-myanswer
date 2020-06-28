#include "common.h"

USESTD

class MyLinkedList {
public:
    typedef struct Node {
        int val;
        Node *next;

        Node(int v, Node *next) : val(v), next(next) {}
    } Node;

    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new Node(-1, nullptr);
        tail = new Node(-1, nullptr);
        head->next = tail;
        len = 0;
    }
    
    ~MyLinkedList() {
        Node *temp1 = head->next;
        Node *temp2 = head->next;

        while (temp1 != tail) {
            temp2 = temp1->next;
            delete temp1;
            temp1 = temp2;
        }

        delete head;
        delete tail;

        head = nullptr;
        tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (len <= index)
            return -1;

        Node *node = head->next;
        for (int i = 0; i < index; i++)
            node = node->next;
    
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *node = new Node(val, head->next);
        head->next = node;
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *prev = head->next;
        Node *curr = head->next;
        
        while (curr != tail) {
            prev = curr;
            curr = curr->next;
        }
        
        Node *node = new Node(val, tail);
        prev->next = node;
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node *prev = head;
        Node *curr = head->next;

        if (len < index)
            return;
            
        for (int idx = 0; idx < index; idx++) {
            prev = curr;
            curr = curr->next;
        }

        Node *node = new Node(val, nullptr);
        node->next = curr;
        prev->next = node;
        len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node *prev = head;
        Node *curr = head->next;

        if (len <= index)
            return;

        for (int idx = 0; idx < index && curr != tail; idx++) {
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        delete curr;
        len--;
    }

private:
    Node *head;
    Node *tail;
    size_t len;
};