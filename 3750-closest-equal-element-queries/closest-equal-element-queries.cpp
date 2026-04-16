class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mymap;
        int n=nums.size();
        vector<int> ans(queries.size());
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]].push_back(i);
        }
       
        for(int q=0;q<queries.size();q++){
            int index=queries[q];
            int num=nums[index];
            auto& temp=mymap[num];
            if(temp.size()==1){
                ans[q]=-1;
            }
            else if(temp.size()==2){
                int ind;
                int rem_ind;
                int res;
                if(temp[0]==index){
                    ind=temp[0];
                    rem_ind=temp[1];
                    res=min((rem_ind-ind),((ind-rem_ind+n)%n));
                }
                else{
                    ind=temp[1];
                    rem_ind=temp[0];
                    res=min((ind-rem_ind),(rem_ind-ind+n)%n);
                }
               
                  ans[q]=res;
            }
            else{
                int ind;
                int low=0;
                int high=temp.size()-1;
                while(low<=high){
                    int mid=(low+high)/2;
                    if(temp[mid]==index){
                        ind=mid;
                        break;
                    }
                    else if(temp[mid]>index){
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
                int res=INT_MAX;
                if(ind==0){
                    res=min(abs(temp[ind]-temp[ind+1]),(temp[ind]-temp[temp.size()-1]+n)%n);
                }
                else if(ind==temp.size()-1){
                    res=min(abs(temp[ind]-temp[ind-1]),(temp[0]-temp[ind]+n)%n);
                }
                else{
                    res=min(abs(temp[ind]-temp[ind-1]),abs(temp[ind+1]-temp[ind]));
                }
                 ans[q]=res;
            }
        }
        return ans;
    }
};