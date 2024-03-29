/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


*/

 int maxProfit(vector<int>& prices) {
        vector<int> profit(prices.size());
        profit[0]=0;
        profit[1]=prices[1]-prices[0];
        for(int i=2;i<prices.size();i++)
        {
            profit[i]=max(prices[i]-prices[i-1],prices[i]-prices[i-1]+profit[i-1]);
        }
        int n=profit.size(),max_profit=0;
        for(int i=0;i<n;i++)
        {
          max_profit=max(max_profit,profit[i]);  
        }
        return max_profit;
    }
};
/*
int maxProfit(vector<int>& prices) {
int profit=0;
int buy=INT_MAX;

for(int price : prices)
{
	if(price < buy) buy=price;
	if(profit < price - buy) profit = price - buy;
}

return profit;
}*/
