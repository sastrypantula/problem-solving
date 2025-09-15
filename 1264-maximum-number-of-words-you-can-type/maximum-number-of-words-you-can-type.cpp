class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool>map(26,false);
        for(char& ch:brokenLetters){
            map[ch-'a']=true;
        }
        int result=0;
        bool cantype=true;
        for(char ch:text){
            if(ch==' '){
                if(cantype){
                    result++;
                }
                cantype=true;
            }
          else   if(map[ch-'a']==true){
                cantype=false;
            }
        }
        if(cantype){
            result++;
        }
        return result;
    }
};