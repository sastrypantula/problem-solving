class Solution {
public:
    string sortVowels(string s) {
        int n=s.length();
        deque<char> vowels;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'  ){
                vowels.push_back(s[i]);
            }
        }
        if(vowels.empty()){
            return s;
        }
        sort(vowels.begin(), vowels.end(), [](char a, char b) {
    return a < b;
});

        for(int i=0;i<n;i++){
 if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'  ){
                char t=vowels.front();
                vowels.pop_front();
                s[i]=t;
            }
        }
        return s;
    }
};