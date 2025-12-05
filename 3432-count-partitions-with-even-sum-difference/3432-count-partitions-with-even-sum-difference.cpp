class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n);
        arr[0] = nums[0];
        for(int i=1;i<n;i++){
            arr[i] = arr[i-1] + nums[i];
        }

        long long total=arr[n-1];
        int cnt=0;
        for(int i=0;i<n-1;i++){
            long long left = arr[i];
            long long right = total - left;
            if((abs(left-right))%2==0){
                cnt++;
            }
        }
        return cnt;
    }
};