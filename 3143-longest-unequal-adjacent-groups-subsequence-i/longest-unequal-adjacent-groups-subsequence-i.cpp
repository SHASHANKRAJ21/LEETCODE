class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        int n = words.size();
        int flag = -1;
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            if (groups[i] != flag) {
                flag = groups[i];
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};