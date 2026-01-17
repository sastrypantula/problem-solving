// solved by seeing the solution so pls try the question again next time without seeing the solution 

class Solution {
public:
const int M=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        unordered_set<int>widths;
        unordered_set<int>heights;
        for(int i=0;i<hFences.size()-1;i++){
            for(int j=i+1;j<hFences.size();j++){
                int width=hFences[j]-hFences[i];
                widths.insert(width);
            }
        }
        int maxi=0;
          for(int i=0;i<vFences.size()-1;i++){
            for(int j=i+1;j<vFences.size();j++){
                int height=vFences[j]-vFences[i];
                if(widths.find(height)!=widths.end()){
                maxi=max(maxi,height);
                }
            }
        }
        if(maxi==0){
            return -1;
        }
        return (1LL*maxi*maxi)%M;

    }
};