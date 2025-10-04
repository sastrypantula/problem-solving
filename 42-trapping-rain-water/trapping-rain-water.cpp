class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i-1]);
        }
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i+1]);
        }
        int result=0;
        for(int i=0;i<n;i++){
            int t=min(left[i],right[i]);
            if(t>height[i]){
                result+=t-height[i];
            }
         
        }
        return result;
    }
};