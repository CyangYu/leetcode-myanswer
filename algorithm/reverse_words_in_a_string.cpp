#include "common.h"

USESTD

class Solution {
public:
    string reverseWords(string s) {
		auto size = s.size();
		string result(size, ' ');
		
		size_t idx = 0, wordlen = 0;
		size_t begin = -1, end = -1;
		
		while (idx < size) {
			if (s[idx] != ' ') {
				begin = idx;
				wordlen = 1;
				
				for (int i = begin + 1; i < size && s[i] != ' '; i++)
					wordlen++;	
				end = begin + wordlen - 1;

				for (int j = 0; j < wordlen; j++)
					result[begin + j] = s[end - j];
				
				idx += wordlen;
			} else 
				idx++;
		}
					
		return result;
    }
};