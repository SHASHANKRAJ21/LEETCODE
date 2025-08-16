class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int open=0;
        for(char c:s){
            if(c=='('){
                if(open>0){
                    result+='(';

                }
                open++;
                
            }else{
                open--;
                if(open>0){
                    result+=')';
                }
            }
        }
        return result;
    }
};