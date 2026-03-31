// tried this passed 737/739 so copied the solution
// class Solution {
// public:
//     string generateString(string str1, string str2) {
//         int n=str1.length();
//         int m=str2.length();
//         string s(n+m-1,'a');
//          vector<bool> temp(n+m-1,false);
//          for(int i=0;i<n;i++){
//             if(str1[i]=='T'){
//                 for(int j=i,k=0;j<n+m-1 && k<m;j++,k++){
//                     if(temp[j]==false || s[j]==str2[k]){
//                         s[j]=str2[k];
//                         temp[j]=true;
//                     }
//                     else{
//                         return "";
//                     }
//                 }
//             }
//          }
//            // after the trues 
//            cout<<"After Trues "<<s<<endl;


//            for(int i=0;i<n;i++){
//             if(str1[i]=='F'){
//                 bool equal = true;
//         for(int j = 0; j < m; j++){
//             if(s[i + j] != str2[j]){
//                 equal = false;
//                 break;
//             }
//         }

//         if(equal){
//             bool changed = false;

//             for(int j =i,k=0; j<i+m && k<m; j++,k++){ // right to left for lexicographically smallest
//                 if(temp[j]==false){
//                   if(str2[k]=='a'){
//                     s[j]='b';
//                   }
//                   else{
//                     s[j]='a';
//                   }
//                   changed=true;
//                   break;
//                 }
//             }

//             if(!changed) return "";
//             }
//          }
//            }
//          return s;
//     }
// };

class Solution {
public:
    bool isSame(string &word, string & str2, int i, int m) {
        for(int j = 0; j < m; j++) {
            if(word[i] != str2[j]) {
                return false;
            }

            i++;
        }

        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        int N = n + m - 1;
        string word(N, '$');

        vector<bool> canChange(N, false);

        //Process the 'T'
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                int i_ = i;
                for(int j = 0; j < m; j++) {
                   //word[i] = str2[j]
                   //word[i+1] = str2[j+1] and so on....
                   if(word[i_] != '$' && word[i_] != str2[j]) {
                        return "";
                   }
                   word[i_] = str2[j];
                   i_++;
                }
            }
        }

        //FIll the remaining spaces with 'a'
        for(int i = 0; i < N; i++) {
            if(word[i] == '$') {
                word[i] = 'a';
                canChange[i] = true;
            }
        }

        //Process the 'F'
        //T.C : O(n * m)
        //S,C : O(N)
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F') {

                if(isSame(word, str2, i, m)) { //If same, then we need to make it unequal
                    
                    bool changed = false;
                    for(int k = i + m - 1; k >= i; k--) {
                        if(canChange[k] == true) {
                            word[k] = 'b';
                            changed = true;
                            break;
                        }
                    }

                    if(changed == false) { //i was not able to change any character to break equality
                        return "";
                    }

                }

            }
        }

        return word;
    }
};