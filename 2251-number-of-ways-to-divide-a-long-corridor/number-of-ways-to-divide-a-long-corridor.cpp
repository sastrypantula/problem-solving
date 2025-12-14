class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        int n = corridor.size();
        // int seatCount = 0;
        // long long plantCount = 0;
        // bool countingPlants = false;

        // for (char c : corridor) {
        //     if (c == 'S') {
        //         seatCount++;
        //         if (seatCount % 2 == 1) {
        //             if (seatCount > 2) {
        //                 ways = (ways * (plantCount + 1)) % MOD;
        //             }
        //             plantCount = 0;
        //             countingPlants = false;
        //         } 
        //         else {
        //             countingPlants = true;
        //         }
        //     } else if (c == 'P' && countingPlants) {
        //         plantCount++;
        //     }
        // }

        // if (seatCount < 2 || seatCount % 2 == 1) return 0;
        // return ways % MOD;
        int count=0;
           vector<int> temp;
        for(int i=0;i<n;i++){
            if(corridor[i]=='S'){
                count++;
                temp.push_back(i);
            }
        }
        if(count==0 || count==1 || count%2==1){
            return 0;
        }
        long long ways=1;
        int prev=temp[1];
        for(int j=2;j<temp.size();j=j+2){
            ways=((ways)*(temp[j]-prev)%MOD);
            prev=temp[j+1];

        }
    
    return ways;
    }
};