// class TaskManager {
// public:
// unordered_map<int,pair<int,int>> utp;
// unordered_map<int,pair<int,int>>tpu;
// set<pair<int,int>>pt;
//     TaskManager(vector<vector<int>>& tasks) {
//         int n=tasks.size();
//         for(int i=0;i<n;i++){
//             int userid=tasks[i][0];
//             int task=tasks[i][1];
//             int priority=tasks[i][2];
//             utp[userid].insert({task,priority});
//             tpu[task].insert({priority,userid});
//             pt.insert({priority,task});
//         }
//     }
    
//     void add(int userId, int taskId, int priority) {
//         utp[userId].insert({taskId,priority});
//         tpu[taskId].insert({priority,userId});
//         pt.insert(priority,taskId);
//     }
    
//     void edit(int taskId, int newPriority) {
//         int oldpriority=tpu[taskId].first;
//         int userid=tpu[taskId].second;
//         tpu[taskId].first=newPriority;
//         utp[userId].second=newPriority;
//         pt.erase({oldpriority,taskId});
//         pt.insert({newPriority,taskId});

//     }
    
//     void rmv(int taskId) {
//          int priority=tpu[taskId].first;
//         int userid=tpu[taskId].second;
//         tpu.erase(taskId);
//         utp.erase(userid);
//         pt.erase({priority,taskId});
//     }
    
//     int execTop() {
//        pair<int,int> t=*pt.rbegin();
//       int result= tpu[t.second].second;
//       return result;
//     }
// };


// corrected the syntax for my code but logic is correct 


class TaskManager {
public:
    unordered_map<int, unordered_map<int,int>> utp; // user -> (task -> priority)
    unordered_map<int, pair<int,int>> tpu;          // task -> (priority,user)
    set<pair<int,int>> pt;                          // (priority,task)

    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task : tasks){
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            utp[userId][taskId] = priority;
            tpu[taskId] = {priority,userId};
            pt.insert({priority,taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        utp[userId][taskId] = priority;
        tpu[taskId] = {priority,userId};
        pt.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [oldPriority, userId] = tpu[taskId];
        pt.erase({oldPriority,taskId});
        utp[userId][taskId] = newPriority;
        tpu[taskId] = {newPriority,userId};
        pt.insert({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        auto [priority, userId] = tpu[taskId];
        tpu.erase(taskId);
        utp[userId].erase(taskId);
        if(utp[userId].empty()) utp.erase(userId);
        pt.erase({priority,taskId});
    }
    
    int execTop() {
        if(pt.empty()) return -1;
        auto [priority, taskId] = *pt.rbegin(); // highest priority
        auto [prio,userId] = tpu[taskId];
        rmv(taskId);  // remove everywhere
        return userId;
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