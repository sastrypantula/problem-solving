class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<vector<int>> temp;
        for(int i = 0; i < n; i++){
            int t = (directions[i] == 'R') ? 1 : -1;
            temp.push_back({positions[i], healths[i], t, i});
        }

        sort(temp.begin(), temp.end());

        stack<vector<int>> st;

        for(int i = 0; i < n; i++){
            vector<int> curr = temp[i];

            bool flag=true;
            while(!st.empty() && st.top()[2] == 1 && curr[2] == -1){
                
                if(st.top()[1] < curr[1]){
                    curr[1]--;   
                    st.pop();
                }
                else if(st.top()[1] > curr[1]){
                    st.top()[1]--; 
                     flag=false;
                    break;
                }
                else{
                    st.pop();     
                    flag=false;
                    break;
                }
            }

            if(flag){
                st.push(curr);
            }
        }

        vector<int> res(n, 0);

        while(!st.empty()){
            vector<int> t = st.top();
            st.pop();
            res[t[3]] = t[1]; 
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(res[i] > 0){
                ans.push_back(res[i]);
            }
        }

        return ans;
    }
};