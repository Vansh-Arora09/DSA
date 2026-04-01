class Solution {
public:
    int part(vector<int>&arr, int low, int high){
        int random = low + rand() % (high-low+1);
        swap(arr[high], arr[random]);
        int p = arr[high];
        int i=low-1;
        for(int j=low;j<high;j++){
            if(arr[j]<p){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[high]);
        return (i+1);
    }
    void quicksort(vector<int>&arr, int low, int high){
        if(low<high){
            int p = part(arr, low ,high);

            quicksort(arr, low, p-1);
            quicksort(arr, p+1, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quicksort(nums, 0, n-1);

        return nums;
    }
};