class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int total_len = m+n;

        int p1=0, p2=0;
        int curr=0, prev =0;

        for(int i=0;i<=total_len/2;i++){
            prev = curr;
            // 2 choices->
                //(i):- if nums2 is completely empty
                //(ii):- if both arrays has elements , do norml comparison 
            if(p1<m && (p2>=n || nums1[p1]<=nums2[p2])){
                curr = nums1[p1];
                p1++;
            }
            else{
                curr = nums2[p2];
                p2++;
            }
        }
        if(total_len%2!=0){
            return double(curr);
        }
        return (prev+curr)/2.0;
    }
};