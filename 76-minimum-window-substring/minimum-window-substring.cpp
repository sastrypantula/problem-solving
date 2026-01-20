class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()){
            return "";
        }
        unordered_map<char,int> mymap;
        int reqcount=t.size();
        for(char& ch:t){
            mymap[ch]++;
        }
        int i=0;
        int j=0;
        int start_index=0;
        int min_window_size=INT_MAX;
        while(j<s.length()){

            if(mymap[s[j]]>0){
               
                reqcount--;
            }
             mymap[s[j]]--;
            while(reqcount==0){ // means manaki window size vachindi 
              int present_window_size=j-i+1;
              if(present_window_size<min_window_size){
                  start_index=i;
                  min_window_size=present_window_size;
              }
              mymap[s[i]]++;
             if(mymap[s[i]]>0){
                reqcount++;
             }
             i++;
            }
            
            j++;
        }
        if(min_window_size==INT_MAX){
            return "";
        }
        return s.substr(start_index,min_window_size);
    }
};