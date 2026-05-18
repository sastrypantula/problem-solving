class Solution {
public:
// DFS will not give me the shortest path only BFS will give 
// int n; 
// unordered_map<int,vector<int>> mymap;
// int func(int i,vector<int>& arr,vector<bool>& visited){
//     if(i>n || i<0){
//         return INT_MAX;
//     }
// if(i==n-1){
//     return 0;
// }
// if(visited[i]==true){
//     return INT_MAX;
// }
//   visited[i]=true;
// int steps1=INT_MAX;
// int steps2=INT_MAX;
// int steps3=INT_MAX;
// if(i+1<n && visited[i+1]==false){
  
//     steps1=1+func(i+1,arr,visited);
// }
// if(i-1>=0 && visited[i-1]==false){

//     steps2=1+func(i-1,arr,visited);
// }
// if(mymap.count(arr[i])){
//     for(auto j:mymap[arr[i]]){
//         if(i!=j && visited[j]==false){
        
//             int temp=1+func(j,arr,visited);
//             steps3=min(steps3,temp);
//         }
//     }
        
// }
// return min({steps1,steps2,steps3});

// }
    int minJumps(vector<int>& arr) {
        // n=arr.size();
        // vector<bool> visited(n,false);
        // for(int i=0;i<n;i++){
        //     mymap[arr[i]].push_back(i);
        // }
        // return func(0,arr,visited);
        int n=arr.size();
        unordered_map<int,vector<int>> mymap;
        for(int i=0;i<n;i++){
            mymap[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        int steps=0;
        vector<bool> visited(n,false);
        visited[0]=true;
        while(!q.empty()){
            int N=q.size();
            while(N--){
            int curr=q.front();
            q.pop();
            if(curr==n-1){
                return steps;
            }
            if(0<=curr-1 && visited[curr-1]==false){
                q.push(curr-1);
                visited[curr-1]=true;
            }
            if(curr+1<n && visited[curr+1]==false){
                q.push(curr+1);
                visited[curr+1]=true;
            }
            if(mymap.count(arr[curr])){
                for(auto j:mymap[arr[curr]]){
                    q.push(j);
                    visited[j]=true;
                }
                mymap.erase(arr[curr]);
            }
            }
            steps++;
        }
        return -1;
    }
};