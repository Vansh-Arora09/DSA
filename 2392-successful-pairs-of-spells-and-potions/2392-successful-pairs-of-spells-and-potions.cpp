class Solution {

public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        int n = potions.size();
        
        for (long long spell : spells) {
            long long minPotion = (success + spell - 1) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            int count = potions.end() - it;
            res.push_back(count);
        }
        return res;
    }
};
