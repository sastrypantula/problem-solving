class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
     int minFinishTime = INT_MAX;

    for (int i = 0; i < landStartTime.size(); ++i) {
        for (int j = 0; j < waterStartTime.size(); ++j) {
        
            int landStart = landStartTime[i];
            int landEnd = landStart + landDuration[i];
            int waterStart = max(waterStartTime[j], landEnd);
            int waterEnd = waterStart + waterDuration[j];
            minFinishTime = min(minFinishTime, waterEnd);

        
            int waterStart2 = waterStartTime[j];
            int waterEnd2 = waterStart2 + waterDuration[j];
            int landStart2 = max(landStartTime[i], waterEnd2);
            int landEnd2 = landStart2 + landDuration[i];
            minFinishTime = min(minFinishTime, landEnd2);
        }
    }

    return minFinishTime;

     
    }
};