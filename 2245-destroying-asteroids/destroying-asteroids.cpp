class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
     
        int n=asteroids.size();
         sort(asteroids.begin(),asteroids.end());
         if(asteroids[0]>mass){
            return false;
         }
            long long nmass=mass;
         for(int i=0;i<n;i++){
             if(nmass>=asteroids[i]){
                nmass+=asteroids[i];
             }
             else{
                return false;
             }
         }
         return true;


    }
};