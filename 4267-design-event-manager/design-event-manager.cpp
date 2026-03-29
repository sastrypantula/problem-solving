class EventManager {
public:
unordered_map<int,int> eventlist;
map<int,set<int>> prioritylist;
    EventManager(vector<vector<int>>& events) {
        for(auto it:events){
            int event=it[0];
            int priority=it[1];
            eventlist[event]=priority;
            prioritylist[priority].insert(event);
        }

    }
    
    void updatePriority(int eventId, int newPriority) {
     if(eventlist.find(eventId)!=eventlist.end()){
        int pp=eventlist[eventId];
        eventlist[eventId]=newPriority;
        prioritylist[pp].erase(eventId);
        if(prioritylist[pp].size()==0){
            prioritylist.erase(pp);
        }
        prioritylist[newPriority].insert(eventId);
     }
    }
    
    int pollHighest() {
       if(prioritylist.size()==0){
        return -1;
       } 
       auto it=prioritylist.rbegin();
       int priority=it->first;
       if(it->second.empty()){
        return -1;
       }
       int eventid=*(it->second).begin();
       eventlist.erase(eventid);
       it->second.erase(eventid);
       if(it->second.size()==0){
        prioritylist.erase(priority);
       }
       return eventid;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */