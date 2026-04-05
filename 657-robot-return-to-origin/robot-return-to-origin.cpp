class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0;
        int y=0;
       for(char ch:moves){
        if(ch=='U'){
            x=x+0;
            y=y+1;
        }
        if(ch=='R'){
            x=x+1;
            y=y+0;
        }
        if(ch=='L'){
            x=x-1;
            y=y+0;
        }
        if(ch=='D'){
            x=x+0;
            y=y-1;
        }
       }
        if(x==0 && y==0){
            return  true;
        }
        return false;
    }
};