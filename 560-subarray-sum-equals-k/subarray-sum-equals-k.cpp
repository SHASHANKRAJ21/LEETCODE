class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> mpp; // prefix sum -> frequency
        int count = 0;
        long long sum = 0;

        mpp[0] = 1; // empty prefix

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            long long rem = sum - k;
            if(mpp.find(rem) != mpp.end()){
                count += mpp[rem];
            }

            // increment frequency of this prefix sum
            mpp[sum] += 1;
        }
        return count;
    }
};
