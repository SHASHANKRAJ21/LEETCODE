class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int count=0;
        int i=0;
        int index=0;
        while(i<n){
            char curr_ind=chars[i];
            count=0;
            while(i<n && curr_ind==chars[i]){
                count++;
                i++;
            }
            chars[index]=curr_ind;
            index++;
            if(count>1){
                string curr=to_string(count);
                for(char &ch:curr){
                    chars[index]=ch;
                    index++;
                }
            }
            
        }
        return index;
    }
};