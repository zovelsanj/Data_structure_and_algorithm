/*Best Time to Buy and Sell Stock (Easy)

You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.
You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.
Return the maximum profit you can achieve. You may choose to not make any transactions, in which case the profit would be 0.

Example:
Input: prices = [10,1,5,6,7,1]
Output: 6

You should aim for a solution with O(n) time and O(1) space, where n is the size of the input array.
*/

#include <iostream>
#include <vector>

class buySellStock {
public:
    int maxProfit(std::vector<int>& prices) {
        int lptr = 0;
        int rptr = 1;
        int max_profit = 0;
        while (rptr < prices.size()){
            if (prices[lptr] > prices[rptr]){
                lptr = rptr;
                rptr++;
            }
            else {
                max_profit = std::max(max_profit, prices[rptr]-prices[lptr]);
                rptr++;
            }
        }
        return max_profit;
    }
};

int main() {
    buySellStock bss;
    std::vector<int> prices = {5,1,5,6,7,1};
    int result = bss.maxProfit(prices);
    std::cout << "Max Profit: " << result << std::endl; // Output: 6
    return 0;
}
