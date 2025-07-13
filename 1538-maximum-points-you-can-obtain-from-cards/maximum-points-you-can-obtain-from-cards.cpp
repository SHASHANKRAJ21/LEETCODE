class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int leftsum=0;
        int rightsum=0;
        int maxsum=0;
        int n=nums.size();
        for(int i=0;i<k;i++){
            leftsum=leftsum+nums[i];
        }
        maxsum=leftsum;
        int rindex=n-1;
        for(int i=k-1;i>=0;i--){
            leftsum=leftsum-nums[i];
            rightsum=rightsum+nums[rindex];
            rindex=rindex-1;
            maxsum=max(maxsum,leftsum+rightsum);
        }
        return maxsum;
    }
};