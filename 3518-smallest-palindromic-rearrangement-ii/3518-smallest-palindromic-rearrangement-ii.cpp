class Solution {
public:

    long long Comb(const map<char,int>& half, int total, long long k){
        long long ways=1;
        int c=0;

        for(auto curr : half){
            int cnt = curr.second;
            for(int i=1;i<=cnt;i++){
                c++;
                ways = (ways*c)/i;
                if(ways>k) return k+1;
            }
        }
        return ways;
    }
    string smallestPalindrome(string s, int k) {
        map<char, int> mpp;
        int odd=0;
        for(char c: s){
            mpp[c]++;
        }
        char mid='\0';
        map<char, int> half;
        for(auto ent : mpp){
            char ch = ent.first;
            int cnt = ent.second;
            if(cnt%2!=0){
                odd++;
                mid = ch;
            }
            if(cnt/2 >0){
                half[ch] = cnt/2;
            }
        }
        if(odd>1) return "";
        int tot=0;
        for(auto entry : half){
            tot+=entry.second;
        }
        long long ways = Comb(half, tot,k);
        if(k>ways) return "";

        string first = "";
        for(int i=0;i<tot;i++){
            for(auto& entry : half){
                if(entry.second==0) continue;
                
                char ch = entry.first;
                entry.second--;

                int rem = tot-1-i;
                long long perm = Comb(half, rem,k);

                if(k<=perm){
                    first+=ch;
                    break;
                }
                else{
                    k-=perm;
                    entry.second++;
                }
            }
        }
        string sec = first;
        reverse(sec.begin(), sec.end());
        if(mid!='\0'){
            return first+mid+sec;
        }
        return first+sec;
    }
};