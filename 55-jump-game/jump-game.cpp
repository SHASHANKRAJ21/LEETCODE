class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int recheable=0;
        for(int i=0;i<n;i++){
            if(i>recheable){
                return false;
            }
            recheable=max(recheable,i+nums[i]);
        }
        return true;
    }
};