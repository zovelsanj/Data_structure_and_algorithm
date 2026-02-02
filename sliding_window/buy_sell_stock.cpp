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
