class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;
        int n = arr.size();
        while(left+1<n && arr[left]<arr[left+1]){
                left++;
        }
        while(right>0 && arr[right]<arr[right-1]){
            right--;
        }
        return (left>0 && left==right && right<n-1);
    }
};