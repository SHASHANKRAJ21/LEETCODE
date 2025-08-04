class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string result="";
        char ch;
        int count;
        string say=countAndSay(n-1);
        for(int i=0;i<say.length();i++){
            ch=say[i];
            count=1;
            while(i<say.length()-1 && say[i]==say[i+1]){
                count++;
                i++;
            }
            result += to_string(count)+string(1,ch);

        }
        return result;
    }
};