class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;

        int srt = find(nums.begin(), nums.end(),0) - nums.begin();
        bool asc=true;
        bool desc=true;

        for(int i=1;i<n;i++){
            int value = nums[(srt+i)%n];
            if(value!=i) asc=false;
            if(value!=n-i) desc=false;
            if(!asc && !desc) return -1;
        }
        if(asc) return min(srt, n-srt+2);
        return min(n-srt,srt+2);

    }

};