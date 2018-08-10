#include "common.h"

USESTD

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> _stack;

        for (int i = 0; i < S.length(); i++) {
            if (isalpha(S[i]))
                _stack.push(S[i]);
            else if (S[i] == '#') {
                if (!_stack.empty())
                    _stack.pop();
            } 
        }

        string s;
        while (!_stack.empty()) {
            s.append(1, _stack.top());
            _stack.pop();
        }

        for (int i = 0; i < T.length(); i++) {
            if (isalpha(T[i]))
                _stack.push(T[i]);
            else if (T[i] == '#') {
                if (!_stack.empty())
                    _stack.pop();
            } 
        }

        string t;
        while (!_stack.empty()) {
            t.append(1, _stack.top());
            _stack.pop();
        }

        return s.compare(t) == 0;
    }
};