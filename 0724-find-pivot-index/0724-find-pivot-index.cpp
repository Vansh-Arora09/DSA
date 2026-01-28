class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n,0), right(n,0);
        int sum=0;
        for(int i=1;i<n;i++){
            sum+=arr[i-1];
            left[i] = sum;
        }
        sum=0;
        for(int i=n-2;i>=0;i--){
            sum+=arr[i+1];
            right[i] = sum;
        }
        for(int i=0;i<n;i++){
            if(left[i]==right[i]) return i;
        }
        return -1;
    }
};