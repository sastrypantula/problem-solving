class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
         vector<string> ans;

        int total = (1 << n);

        for(int mask = 0; mask < total; mask++) {

            string s = "";
            int cost = 0;
            bool ok = true;

            for(int i =0; i <n; i++) {

                if(mask & (1 << i)) {
                    s.push_back('1');
                    cost += i;
                }
                else {
                    s.push_back('0');
                }
            }

            for(int i = 0; i < n - 1; i++) {

                if(s[i] == '1' && s[i + 1] == '1') {
                    ok = false;
                    break;
                }
            }

            if(ok && cost <= k)
                ans.push_back(s);
        }

        return ans; 
    }
};