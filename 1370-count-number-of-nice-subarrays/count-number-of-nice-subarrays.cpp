class Solution {
public:
    int sumofsubarrays(vector<int>&nums,int k){
        int l=0;
        int r=0;
        int cnt=0;
        int sum=0;
        while(r<nums.size()){
            sum=sum+(nums[r]%2);
            while(sum>k){
                sum=sum-(nums[l]%2);
                l=l+1;
            }
            cnt=cnt+r-l+1;
            r=r+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(k<0){
            return 0;
        }
        return sumofsubarrays(nums,k)-sumofsubarrays(nums,k-1);
    }
};