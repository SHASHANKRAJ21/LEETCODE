class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,int>countS,countt;
        for(char c: s){
            countS[c]++;
        }
        for(char c: t){
            countt[c]++;
        }
        for(char c:s){
            if(countS[c]!=countt[c]){
                return false;
            }
        }
        return true;
    }

};