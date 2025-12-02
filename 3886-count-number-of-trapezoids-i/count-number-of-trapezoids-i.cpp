class Solution {
public:
const long long  MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
     unordered_map<int, int> freq;

        
        for (auto &p : points) {
            freq[p[1]]++;
        }

      
        vector<long long> segCounts;
        for (auto &kv : freq) {
            int n = kv.second;
            if (n >= 2) {
                long long c2 = 1LL * n * (n - 1) / 2; 
                segCounts.push_back(c2 % MOD);        
            }
        }

        long long ans = 0, sum = 0;
        for (long long x : segCounts) {
            ans = (ans + x * sum) % MOD; 
            sum = (sum + x) % MOD;       
        }

        return (int)ans;

     
    
    }
};