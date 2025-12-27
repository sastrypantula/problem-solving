class Solution {
public:
    int mostBooked(int n1, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<long long>AvailableRooms(n1,0);// this is will give the ending time of each room
        vector<int>count(n1,0);// this will give  the count of meeetings held in each room
        for(auto & meeting:meetings){
            long long  start=meeting[0];
            long long  end=meeting[1];
            long long  duration=end-start;
            // first checking avaliable room
            bool available=false;
            for(int i=0;i<n1;i++){
                if(AvailableRooms[i]<=start){
                    available=true;
                    count[i]++;
                    AvailableRooms[i]=end;
                    break;
                }
            }
            if(available==false){
                // checking the room which will complete the meeting early
                int room=-1;
                long long Earlyendtime=LONG_MAX;
                for(int i=0;i<n1;i++){
                    if(AvailableRooms[i]<Earlyendtime){
                        Earlyendtime=AvailableRooms[i];
                        room=i;
                    }
                }
                AvailableRooms[room]+=duration;
                count[room]++;


            }
        }
        // finding the room which has max meetings;
        int ans=-1;
        long long maxi=LONG_MIN;
        for(int i=0;i<n1;i++){
            if(maxi<count[i]){
                maxi=count[i];
                ans=i;
            }
        }
        return ans;
    }
};