class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mpp;
        if(nums.empty()){
            return {};
        }
        vector<int>ans;
        for(int num:nums){
            mpp[num]++;
        }
        for(auto it:mpp){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};