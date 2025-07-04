class Solution {
public:
    int first(vector<int>&nums,int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int first=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }


        }
        return first;
    }
    int last(vector<int>&nums,int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int last=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }


        }
        return last;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>answer;
        int x=first(nums,target);
        if(x==-1){
            return {-1,-1};
        }
        int y=last(nums,target);
        answer.push_back(x);
        answer.push_back(y);
        return answer;
        
    }
};