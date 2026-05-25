class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1]=='1') return false;

        queue<int> q;
        q.push(0);

        int maxR = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr==n-1) return true;

            int start=curr+minJump;
            int end = min(n-1, curr + maxJump);

            start = max(start, maxR+1);

            for(int j=start;j<=end;j++){
                if(s[j]=='0') q.push(j);
            }

            maxR = max(maxR,end);
        }
        return false;
    }
};