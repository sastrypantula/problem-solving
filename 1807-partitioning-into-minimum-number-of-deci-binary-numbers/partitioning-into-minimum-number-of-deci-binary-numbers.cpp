class Solution {
public:
    int minPartitions(string n) {
        char maxi='0';
        for(char it:n){
            maxi=max(it,maxi);
        }
        return maxi-'0';
    }
};