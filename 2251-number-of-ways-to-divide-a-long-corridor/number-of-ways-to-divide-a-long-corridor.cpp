class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        long long ways = 1;
        int n = corridor.size();
        int seatCount = 0;
        long long plantCount = 0;
        bool countingPlants = false;

        for (char c : corridor) {
            if (c == 'S') {
                seatCount++;
                if (seatCount % 2 == 1) {
                    if (seatCount > 2) {
                        ways = (ways * (plantCount + 1)) % MOD;
                    }
                    plantCount = 0;
                    countingPlants = false;
                } else {
                    countingPlants = true;
                }
            } else if (c == 'P' && countingPlants) {
                plantCount++;
            }
        }

        if (seatCount < 2 || seatCount % 2 == 1) return 0;
        return ways % MOD;

    }
};