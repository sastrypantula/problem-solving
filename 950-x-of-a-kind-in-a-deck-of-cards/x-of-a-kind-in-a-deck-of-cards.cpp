class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for (int card : deck) {
            freq[card]++;
        }

        int gcd = 0;
        for (auto& [card, count] : freq) {
            gcd =__gcd(gcd, count);
        }
  return gcd >= 2;

    }
};