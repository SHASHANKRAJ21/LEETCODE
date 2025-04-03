class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>st;
        for(string &email : emails){
            string cleanemail;
            for(char c:email){
                if(c=='+' || c=='@'){
                    break;
                }
                if(c=='.'){
                    continue;
                }
                cleanemail=cleanemail+c;
            }
            cleanemail+=email.substr(email.find('@'));
            st.insert(cleanemail);
        }
        return st.size();
        
    }
};