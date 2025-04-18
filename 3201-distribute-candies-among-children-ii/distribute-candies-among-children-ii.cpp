class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        int firstmin=max(0,n-2*limit);
        int firstmax=min(n,limit);
        for (int i=firstmin;i<=firstmax;i++){
            int secondmin=max(0,n-i-limit);
            int secondmax=min(limit,n-i);
            ans= ans + secondmax-secondmin+1;

        }
        return ans;
        
    }
};