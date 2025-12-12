class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> count(numberOfUsers);
        vector<int> online(numberOfUsers);
        sort(events.begin(),events.end(),[&](const vector<string>lth,const vector<string>rth){
            int lth_stamp = stoi(lth[1]);
            int rth_stamp = stoi(rth[1]);
            if(lth_stamp != rth_stamp){
                return lth_stamp < rth_stamp;
            }
            if(rth[0]=="OFFLINE"){
                return false;
            }
            return true;
        });

        for(auto evnt : events){
            int cur_time = stoi(evnt[1]);
            if(evnt[0]=="MESSAGE"){
                if(evnt[2]=="ALL"){
                    for(int i=0;i<numberOfUsers;i++){
                        count[i]++;
                    }
                }
                else if(evnt[2]=="HERE"){
                    for(int i=0;i<numberOfUsers;i++){
                        if(online[i]<=cur_time){
                            count[i]++;
                        }
                    }
                }
                else{
                    int idx=0;
                    for(int i=0;i<evnt[2].size();i++){
                        if(isdigit(evnt[2][i])){
                            idx = idx * 10 + (evnt[2][i] - '0');
                        }
                        if(i+1 == evnt[2].size() || evnt[2][i+1]==' '){
                            count[idx]++;
                            idx=0;
                        }
                    }
                }
            }
            else{
                int idx=stoi(evnt[2]);
                online[idx] = cur_time+60;
            }
        }
        return count;
    }
};