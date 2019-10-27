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

    void print()
    {
        int count = 0;
        for (auto iter = m_list.rbegin(); iter != m_list.rend(); iter++) {
            cout << '(' << *iter << ',' << ++count << ')' << ' ';
        }

        cout << endl;
    }

private:
    int m_k;
    int m_size;
    list<int> m_list;
};

int main(int argc, char *argv[])
{
    vector<int> arr = {4, 5, 8, 2};
    KthLargest kthLargest = KthLargest(3, arr);
    kthLargest.print();

    cout << kthLargest.add(3) << endl;
    kthLargest.print();

    cout << kthLargest.add(5) << endl;
    kthLargest.print();

    cout << kthLargest.add(10) << endl;
    kthLargest.print();

    cout << kthLargest.add(9) << endl;
    kthLargest.print();

    cout << kthLargest.add(4) << endl;
    kthLargest.print();
}