class Solution {
public:
    int findClosest(int x, int y, int z) {
        int x_dist_z = abs(x-z);
        int y_dist_z = abs(y-z);
        if(x_dist_z < y_dist_z) return 1;
        else if(y_dist_z < x_dist_z) return 2;
        else return 0;
    }
};