class Router {
public:
int count=0;
unordered_map<string,vector<int>>packetStore;
unordered_map<int,vector<int>>destinationMap;
queue<string>que;
string makeKey(int s,int d,int t){
    return to_string(s)+"_"+to_string(d)+"_"+to_string(t);
}
    Router(int memoryLimit) {
        count=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key=makeKey(source,destination,timestamp);
        if(packetStore.find(key)!=packetStore.end()){
            return false;
        }
        if(que.size()>=count){
          forwardPacket();
        }
        que.push(key);
        packetStore[key]={source,destination,timestamp};
        destinationMap[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (que.empty()) {
        return {};
            }
       string key = que.front();

        que.pop();
        vector<int> t=packetStore[key];
        packetStore.erase(key);
        int des = t[1];
int time = t[2];
auto& vec = destinationMap[des];
auto it = find(vec.begin(), vec.end(), time);
if (it != vec.end()) vec.erase(it);
   return t;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it=destinationMap.find(destination);
         if (it == destinationMap.end() || it->second.empty())
            return 0;
        int startbound=lower_bound(it->second.begin(),it->second.end(),startTime)-it->second.begin();
        int endbound=upper_bound(it->second.begin(),it->second.end(),endTime)-it->second.begin();
        return endbound-startbound;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */