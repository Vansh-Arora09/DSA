class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        arr[0] = 1;
        for(int i=1;i<n;i++){
            if(abs(arr[i])-abs(arr[i-1]) <=1 ) continue;
            else{
                arr[i] = arr[i-1]+1;
            }
        }
        return arr[n-1];

    }
};