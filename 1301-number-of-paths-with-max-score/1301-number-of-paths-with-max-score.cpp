class Solution {
public:
    vector<vector<pair<int,int>>> dp;
    const int mod = 1e9+7;
    vector<int> sum(vector<string>& board, int n){
        dp[n-1][n-1] = {0,1};

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if((i==n-1 && j==n-1) || board[i][j] == 'X'){
                    continue;
                }

                int maxi = -1;
                long long tot=0;

                pair<int,int> direc[] = {{1,0}, {0,1}, {1,1}};

                for(auto dir: direc){
                    int nr = i + dir.first;
                    int nc = j + dir.second;

                    if(nr<n && nc<n && dp[nr][nc].first!=-1){
                        if(dp[nr][nc].first > maxi){
                            maxi = dp[nr][nc].first;
                            tot = dp[nr][nc].second;
                        }
                        else if(dp[nr][nc].first == maxi){
                            tot = (tot + dp[nr][nc].second)%mod;
                        }
                    }
                }
                if(maxi!=-1){
                    int curr = (board[i][j]=='E') ? 0 : (board[i][j]-'0');
                    dp[i][j] = {maxi+curr, tot};
                }
            }
        }

        if(dp[0][0].first==-1){
            return {0,0};
        }
        return {dp[0][0].first, dp[0][0].second};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        dp.resize(board.size(), vector<pair<int,int>>(board.size(),{-1,0}));  // dp[r][c] = {max_sum, path_count};
        return sum(board, board.size());
    }
};