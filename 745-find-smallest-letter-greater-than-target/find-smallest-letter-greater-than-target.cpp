class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char ch:letters){
            if(target<ch){
                return ch;
            }
        }
        return letters[0];
    }
};