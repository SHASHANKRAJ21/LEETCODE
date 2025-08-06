class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1; // Base case: prefix sum = 0 occurs once
        int count = 0, sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum - k;
            if (mpp.find(rem) != mpp.end()) {
                count += mpp[rem];
            }
            mpp[sum]++;
        }

        return count;
    }
};
