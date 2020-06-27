#include "common.h"

USESTD 

class Solution {
public:
    string decodeString(string s) {
        string result, sub, temp;
        stack<char> chStack;

        char ch = '\0';
        int idx = s.size() - 1;
        
        while (idx >= 0) {
            ch = s[idx]; 
            if (ch >= '0' && ch <= '9') {
                int count = 0;
                if (idx >= 0) {
                    int bit = 1;
                    while (ch >= '0' && ch <= '9' && idx >= 0) {
                        count += (ch - '0') * bit;
                        bit *= 10;
                        idx--;

                        ch = s[idx];
                    }
                }
                for (int j = 0; j < count; j++) {
                    sub.append(temp);
                }
                temp.clear();
                continue;
            } else if (ch >= 'a' && ch <= 'z') {
                chStack.push(ch);
            } else if (ch == '[') {
                while (!chStack.empty()) {
                    ch = chStack.top();
                    chStack.pop();
                    if (ch == ']') {
                        break;
                    }
                    temp.append(1, ch);
                }
                if (!sub.empty()) {
                    temp.append(sub);
                    sub.clear();
                }
            } else if (ch == ']') {
                while (!chStack.empty() && (ch = chStack.top()) != ']') {
                    result.append(1, ch);
                    chStack.pop();
                }
                if (!sub.empty()) {
                    result.insert(0, sub);
                    sub.clear();
                }
                chStack.push(']');
            }
            idx--;
        }

        result.insert(0, sub);
        while (!chStack.empty()) {
            ch = chStack.top();
            temp.append(1, ch);
            chStack.pop();
        }

        result.insert(0, temp);
        return result;
    }   
};

/*
class Solution {
public:
    string src; 
    size_t ptr;

    int getDigits() {
        int ret = 0;
        while (ptr < src.size() && isdigit(src[ptr])) {
            ret = ret * 10 + src[ptr++] - '0';
        }
        return ret;
    }

    string getString() {
        if (ptr == src.size() || src[ptr] == ']') {
            // String -> EPS
            return "";
        }

        char cur = src[ptr]; int repTime = 1;
        string ret;

        if (isdigit(cur)) {
            repTime = getDigits(); 
            ++ptr;
            string str = getString(); 
            ++ptr;
            while (repTime--) ret += str; 
        } else if (isalpha(cur)) {
            ret = string(1, src[ptr++]);
        }
        
        return ret + getString();
    }

    string decodeString(string s) {
        src = s;
        ptr = 0;
        return getString();
    }
};
*/