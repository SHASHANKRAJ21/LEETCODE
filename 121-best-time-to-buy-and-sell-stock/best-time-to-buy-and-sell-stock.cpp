class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int pricetobuy=prices[0];
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]<pricetobuy){
                pricetobuy=prices[i];
            }
            profit=max(profit,prices[i]-pricetobuy);
        }
        return profit;

    }
};