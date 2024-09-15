class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        string doubles=s+s;
        if(doubles.find(goal)<doubles.size()){
            return true;
        }
        else{
            return false;
        }
    }
};