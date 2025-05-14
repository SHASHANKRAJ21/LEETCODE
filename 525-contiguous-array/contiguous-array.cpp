class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>prefixindex;
        int maxlen=0;
        int sum=0;
        prefixindex[0]=-1;//Yeh base case hai: matlab agar kabhi sum dobara 0 ho gaya, to index -1 ke baad jitna bhi distance hoga, wo ek valid subarray hoga
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum=sum-1;
            }
            else{
                sum=sum+1;
            }

            if(prefixindex.find(sum)!=prefixindex.end()){
                int len=i-prefixindex[sum];
                maxlen=max(maxlen,len);
            }
            else{
                prefixindex[sum]=i;
            } 
        }
        return maxlen;

        
    }
};




//....isme mena prefixsum ka use kiya ah 
