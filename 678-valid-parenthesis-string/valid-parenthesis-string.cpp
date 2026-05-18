class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool func(int i, int count, string &s) {
        if (count < 0) return false; 
        if (i == n) return count == 0; 

        if (dp[i][count] != -1) return dp[i][count];

        bool ans = false;
        if (s[i] == '(') {
            ans = func(i+1, count+1, s);
        } else if (s[i] == ')') {
            ans = func(i+1, count-1, s);
        } else { 
            ans = func(i+1, count+1, s) || func(i+1, count-1, s) || func(i+1, count, s);
        }

        return dp[i][count] = ans;
    }

    bool checkValidString(string s) {
        n = s.length();
        dp.assign(n+1, vector<int>(n+1, -1));
        return func(0, 0, s);
    }
};