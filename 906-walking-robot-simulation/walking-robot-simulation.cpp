class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
       map<pair<int,int>,bool> mymap;
       for(auto it:obstacles){
        mymap[{it[0],it[1]}]=true;
       } 
       int ans=0;
       int x=0;
       int y=0;
       vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
       int n=4;
       int k=0;
       for(int it:commands){
           if(it!=-1 && it!=-2){
           int i=dirs[k][0];
           int j=dirs[k][1];
           int t=it;
           while(t>0){
            if(mymap[{x+i,y+j}]!=true){
                x=x+i;
                y=y+j;
                ans=max(ans,x*x+y*y);
            }
            else{
                break;
            }
            t--;
           }
           }
           if(it==-1){
                 k=(k+1)%n;
           }
           if(it==-2){
            k=(k-1+4)%4;
           }
           cout<<"x is "<<x<<endl<<"y is "<<y<<endl;
           cout<<"k is "<<k<<endl;
       }
       return ans;
    }
};