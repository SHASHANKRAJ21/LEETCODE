class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricetobuy=prices[0];
        int n=prices.size();
        int profit=0;
        for(int i=0;i<n;i++){
            if(pricetobuy>prices[i]){
                pricetobuy=prices[i];
            }
            profit=max(profit,prices[i]-pricetobuy);
        }
        return profit;
    
        
    }
};