class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> gain;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+= reward2[i];

            gain.push_back(reward1[i]-reward2[i]);
        }
        sort(gain.rbegin(), gain.rend());

        for(int i=0;i<k;i++){
            sum+= gain[i];
        }
        return sum;

    }
};