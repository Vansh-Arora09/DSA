class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = directions.length();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);

        sort(ids.begin(), ids.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });

        stack<int> st;
        
        for(int id : ids){
            if(directions[id]=='R'){
                st.push(id);
            }
            else{
                while(!st.empty() && healths[id]>0){
                    int top = st.top();

                    if(healths[id]> healths[top]){
                        healths[top] = 0;
                        healths[id]-=1;
                        st.pop();
                    }
                    else if(healths[id]<healths[top]){
                        healths[id]=0;
                        healths[top]-=1;
                    }
                    else{
                        healths[id]=0;
                        healths[top]=0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> res;
        for(int i: healths){
            if(i>0){
                res.push_back(i);
            }
        }
        return res;


    }
};