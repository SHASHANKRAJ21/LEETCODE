class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()){
            return " ";
        } 
        int start=0;
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            int l=i;
            int r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>maxlen){
                    start=l;
                    maxlen=r-l+1;
                }
                l--;
                r++;

            }
            l=i;
            r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>maxlen){
                    start=l;
                    maxlen=r-l+1;
                }
                l--;
                r++;
            }
        }
        return s.substr(start,maxlen);

    }
};