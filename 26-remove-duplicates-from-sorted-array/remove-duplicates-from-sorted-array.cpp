class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        // clear nums and put unique elements back
        nums.clear();
        for(int s : st) {
            nums.push_back(s);
        }
        sort(nums.begin(),nums.end());

        return nums.size(); // return unique count
    }
};
