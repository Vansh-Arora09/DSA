class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();

        vector<bool> valid(n,false);

        for(int i = 0;i<n;i++){
            if(nums[i]==key){

                int start = max(0,i-k);
                int end = min(n-1,i+k);

                for(int j=start;j<=end;j++){
                    valid[j] = true;
                }
            }
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(valid[i]==true){
                res.push_back(i);
            }
        }
        return res;
    }
};