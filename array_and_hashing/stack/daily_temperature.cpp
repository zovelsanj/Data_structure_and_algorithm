/*Daily Temperatures (Medium)
You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.
Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a future day. If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead.
Example 1:
Input: temperatures = [30,38,30,36,35,40,28]
Output: [1,4,1,2,1,0,0]

Constraints:
1 <= temperatures.length <= 1000.
1 <= temperatures[i] <= 100
You should aim for a solution as good or better than O(n) time and O(n) space, where n is the size of the input array.
*/
#include <vector>
#include <stack>
#include <iostream>

class dailyTemperature {
public:
    std::vector<int> warmerDays(std::vector<int> &temperatures){
        std::stack<std::pair<int, int> > tempStack;
        std::vector<int> result(temperatures.size(), 0);

        for (int i=0; i<temperatures.size(); ++i){
            while (!tempStack.empty() && tempStack.top().first < temperatures[i]){
                auto [temp, idx] = tempStack.top();
                tempStack.pop();
                result[idx] = i - idx;
            }
            tempStack.push({temperatures[i], i});
        }
        return result;
        }
};

int main(){
    dailyTemperature dt;
    std::vector<int> temperatures = {30,40,50,60};
    std::vector<int> result = dt.warmerDays(temperatures);
    for (int days : result){
        std::cout << days << " ";
    }
    std::cout << std::endl;
}
