class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string res="";
        int cols=encodedText.length()/rows;

       for(int col=0;col<cols;col++){
        for(int j=col;j<encodedText.length();j=j+cols+1){
            res.push_back(encodedText[j]);
        }
       }
      int n1=res.length();
     int k=n1-1;
      while(k>=0 && res[k]==' '){
        res.pop_back();
        k--;
      }
      return res;
    }
};