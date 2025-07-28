class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right = height.size()-1;
        int max_area=0;

        while(left<right){
            int min_heig = min(height[left],height[right]);
            min_heig*=(right-left);
            max_area = max(max_area,min_heig);

            if(height[left]>height[right]) right--;
            else left++;

            if(min_heig>max_area){
                max_area = min_heig;
            }
        }
        return max_area;
    }
};