class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.length();
        unordered_map<char,int> mymap;
        for(char it:secret){
            mymap[it]++;
        }
        int bulls=0;
        int cows=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bulls++;
                mymap[guess[i]]--;
            }
        }
        for(int i=0;i<n;i++){
            if(secret[i]!=guess[i]){
                if(mymap.count(guess[i]) && mymap[guess[i]]>0){
                    cows++;
                    mymap[guess[i]]--;
                }
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};