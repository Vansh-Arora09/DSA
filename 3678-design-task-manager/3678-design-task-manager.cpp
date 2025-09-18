class TaskManager {
private:

    priority_queue<pair<int,int>> tasks;
    unordered_map<int,int> tskprio;
    unordered_map<int,int> tskown;
    public:
    TaskManager(vector<vector<int>>& tasks) {
        for(const auto task : tasks){
            add(task[0],task[1],task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tasks.push({priority,taskId});
        tskprio[taskId] = priority;
        tskown[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        tasks.push({newPriority,taskId});
        tskprio[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        tskprio[taskId] = -1;
    }
    
    int execTop() {
        while(!tasks.empty()){
            const auto task = tasks.top();
            tasks.pop();
            if(task.first==tskprio[task.second]){
                tskprio[task.second] = -1;
                return tskown[task.second];
                
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */