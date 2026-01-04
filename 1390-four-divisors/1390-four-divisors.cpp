class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        long long tot=0;
        for(int i=0;i<n;i++){    
            int cnt=0;
            int sum=0;
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    int other = nums[i]/j;

                    if(j==other){
                        cnt++;
                        sum+=j;
                    }
                    else{
                        cnt+=2;
                        sum+=j+other;
                    }
                }
            }
            if(cnt==4) tot+=sum;
        }
        return tot;
    }
};