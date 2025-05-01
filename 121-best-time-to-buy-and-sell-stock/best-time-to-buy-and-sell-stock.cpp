class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricetobuy=prices[0];
        int profit=0;
        for(int i=0;i<prices.size();i++){
            if(pricetobuy>prices[i]){
                pricetobuy=prices[i];
            }
            profit=max(profit,prices[i]-pricetobuy);
        }
        return profit;

        
    }
};