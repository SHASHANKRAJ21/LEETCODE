class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int maxlen=0;
        int n=nums.size();
        int zero=0;
        while(right<n){
            if(nums[right]==0){
                zero++;
            }
            if(zero>k){
                if(nums[left]==0){
                    zero--;
                }
                left++;
            }
            if(zero<=k){
                int len=right-left+1;
                maxlen=max(maxlen,len);
            }
            right++;
        }
        return maxlen;
        
    }
};