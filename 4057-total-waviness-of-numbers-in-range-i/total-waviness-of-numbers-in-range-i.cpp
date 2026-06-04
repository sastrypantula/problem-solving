class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        if(num2<=100){
            return 0;
        }
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            int n=s.length();
            if(n<3){
                continue;
            }
            int j=1;
            while(j<=n-2){
                if(s[j-1]<s[j] && s[j+1]<s[j]){
                    ans++;
                }
                if(s[j]<s[j-1] && s[j]<s[j+1]){
                    ans++;
                }
                j++;
            }
        }
        return ans;
    }
};