class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int> section;
        int n = baskets.size();
        int m = sqrt(n);

        int cnt=0;
        int mx = 0;
        for(int i=0;i<n;i++){
            if(cnt==m){
                section.push_back(mx);
                mx = baskets[i];cnt=1;
            }
            else{
                cnt++;
                mx = max(mx,baskets[i]);
            }
        }

        section.push_back(mx);
        int remain=0;

        for(int i=0;i<n;i++){
            int k=0;
            int set=1;
            for(int j=0;j<n;j+=m){
                if(section[k]<fruits[i]){
                    k++;
                    continue;
                }

                for(int r=j;r< min(j+m,n);r++){
                    if(baskets[r]>=fruits[i]){
                        set=0;
                        baskets[r] = 0;
                        break;
                    }
                }

                if(set==0){
                    section[k]=0;
                    for(int r=j;r<min(j+m,n);r++){
                        section[k] = max(baskets[r],section[k]);
                    }
                    break;
                }
            }
            remain+=set;
        }
        return remain;
    }
};