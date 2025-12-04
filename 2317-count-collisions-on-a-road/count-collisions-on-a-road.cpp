class Solution {
public:
    int countCollisions(string directions) {
        int count=0;
        stack<int>s;
        for(char ch:directions){
            if(s.empty()){
                s.push(ch);
                continue;
            }
            else{
                while(!s.empty()){
                    char top=s.top();
                    if(top=='R' && ch=='L'){
                        s.pop();
                        count+=2;
                        ch='S';
                    }
                    else if(top=='R' && ch=='S'){
                        s.pop();
                        count+=1;
                        ch='S';
                    }
                    else if(top=='S' && ch=='L'){
                        s.pop();
                        count+=1;
                        ch='S';
                    }
                    else{
                        break;
                    }
                }
                s.push(ch);
            }
        }
        return count;

    }
};