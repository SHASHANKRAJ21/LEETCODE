class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        int prefixlength=prefix.size();
        for(int i=1;i<strs.size();i++){
            int j=0;
            while(j<prefixlength && j<strs[i].size() && prefix[j]==strs[i][j]){
                j++;
            }
            prefixlength=j; 
            if(prefixlength==0){
                return "";
            }
        }
        string result="";
        for(int m=0;m<prefixlength;m++){
            result+=prefix[m];
        }
        return result;

    }
};