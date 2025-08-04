#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;

        
        for (int val : basket1) freq[val]++;
        for (int val : basket2) freq[val]--;

        vector<int> extra;

        
        for (auto& [num, count] : freq) {
            if (count % 2 != 0) return -1; 
            for (int i = 0; i < abs(count) / 2; ++i)
                extra.push_back(num);
        }

        if (extra.empty()) return 0;

        sort(extra.begin(), extra.end());

        int minVal = min(*min_element(basket1.begin(), basket1.end()),
                         *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        int n = extra.size();

    
        for (int i = 0; i < n / 2; ++i) {
            cost += min(extra[i], 2 * minVal);
        }

        return cost;
    }
};