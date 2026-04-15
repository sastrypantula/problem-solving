class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int i=startIndex;
        if(words[startIndex]==target){
            return 0;
        }
        //left;
        int  n=words.size();
        i=(i-1+n)%n;
        int ans=INT_MAX;
        int count=1;
        while(i!=startIndex){
            if(words[i]==target){
                ans=min(ans,count);
                break;
            }
            i=(i-1+n)%n;
            count++;
        }
        i=startIndex;
        i=(i+1)%n;
        count=1;
        while(i!=startIndex){
            if(words[i]==target){
                ans=min(ans,count);
                break;
            }
            i=(i+1)%n;
            count++;
        }
          if(ans==INT_MAX) return -1;
          return ans;

    }
};