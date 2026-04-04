// class Solution {
// public:
//     string decodeCiphertext(string encodedText, int rows) {
//         string res="";
//         int cols=encodedText.length()/rows;

//        for(int col=0;col<cols;col++){
//         for(int j=col;j<encodedText.length();j=j+cols+1){
//             res.push_back(encodedText[j]);
//         }
//        }
//       int n1=res.length();
//      int k=n1-1;
//       while(k>=0 && res[k]==' '){
//         res.pop_back();
//         k--;
//       }
//       return res;
//     }
// };
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string res="";
        int cols=encodedText.length()/rows;
        vector<vector<char>> temp(rows,vector<char>(cols,'.'));
        int k=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++,k++){
                if(encodedText[k]==' '){
                    continue;
                }
                temp[i][j]=encodedText[k];
            }
        }

        int count2=0;
        while(count2<cols){
            int i=0;
            int j=count2;
       int count1=0;
       while(count1<rows && i<rows && j<cols){
        if(temp[i][j]=='.'){
            res.push_back(' ');
        }
        else{
         res.push_back(temp[i][j]);
        }
        i++;
        j++;
        count1++;
       }
       count2++;
        }
      int n=res.length();
      k=n-1;
      while(k>=0 && res[k]==' '){
        res.pop_back();
        k--;
      }
      return res;
    }
};