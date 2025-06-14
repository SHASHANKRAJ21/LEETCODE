class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>set;
        int right=0;
        int left=0;
        int maxlength=0;
        while(right<s.length()){
            if(set.find(s[right])==set.end()){
                set.insert(s[right]);
                maxlength=max(maxlength,right-left+1);
                right++;
            }
            else{
                set.erase(s[left]);
                left++;
            }
        }
        return maxlength;
    }
};