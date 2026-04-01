class Solution {
public:
    void mergesort(vector<int>&arr, int left, int mid, int high){
        int i=left;
        int j=mid+1;
        vector<int> temp;

        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
        for(int k=0;k<temp.size();k++){
            arr[left+k] = temp[k];
        }

    }
    void merge(vector<int>&arr, int left, int high){

        if(left>=high) return;
        int mid = left+(high-left)/2;

        merge(arr, left, mid);
        merge(arr, mid+1, high);
        mergesort(arr, left, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        merge(nums, 0, n-1);
        return nums;
    }
};