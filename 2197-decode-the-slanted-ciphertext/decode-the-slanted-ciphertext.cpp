class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
//         int cols=encodedText.length()/rows;
//         vector<vector<char>>result(rows,vector<char>(cols,'.'));
//         int n=encodedText.length();
//         int k=0;
//         bool flag=false;
//         int temp=0;
     
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(encodedText[k]!=' '){
//                     result[i][j]=encodedText[k];
//                     flag=true;
//                     temp++;
//                 }
//                 cout<<result[i][j]<<" ";   
//                 k++;
//             }
//             cout<<endl;
//         }
//            if(flag==false){
//             return encodedText;
//            }
//            string ans="";
//            int i=0;
//             for(int j=0;j<cols;j++){
//                 int count=0;
//                 int i1=i;
//                 int j1=j;
//                 while(count<rows){
//                     if(i1>=rows || j1>=cols){
//                         break;
//                     }
//                     if(result[i1][j1]!='.'){
//                         ans.push_back(result[i1][j1]);
//                     }
//                     if(result[i1][j1]=='.'){
//                         ans=ans+" ";
//                     }
//                     count++;
//                     i1++;
//                     j1++;

//                 }
//             }
           
//  while (!ans.empty() && ans.back() == ' ') {
//             ans.pop_back();
//         }

              
//            return ans;


int n = encodedText.length();
        if (n == 0 || rows == 0) return "";

        int cols = n / rows;
        string ans = "";

        for (int j = 0; j < cols; ++j) {
            int i = 0, j1 = j;
            while (i < rows && j1 < cols) {
                char ch = encodedText[i * cols + j1];
                ans.push_back(ch);
                ++i;
                ++j1;
            }
        }

        // Trim trailing spaces
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;

    }
};