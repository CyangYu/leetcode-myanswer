#include "common.h"

USESTD

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        m_k = k;

        for (int i = 0; i < nums.size(); i++) {
            m_list.push_front(nums[i]);
        }

        m_list.sort();
    }
    
    int add(int val) {
        auto rbegin = m_list.rbegin();

        if (val > *rbegin) {
            m_list.push_back(val);
        }
        else 
        {
            for (auto iter = m_list.begin(); iter != m_list.end(); iter++) {
                if (val <= *iter) {
                    m_list.insert(iter, val);
                    break;
                }
            } 
        }
        
        auto iter = m_list.rbegin();

        int count = 1;
        int last = *iter;

        while (count < m_k) {
            iter++;
            count++;
        }

        return *iter;
    }

private:
    int m_k;
    int m_size;
    list<int> m_list;
};