/*  Largest Rectangle In Histogram (Hard)
You are given an array of integers heights where heights[i] represents the height of a bar. The width of each bar is 1.
Return the area of the largest rectangle that can be formed among the bars.
Note: This chart is known as a histogram.

Example:
Input: heights = [7,1,7,2,2,4]
Output: 8

You should aim for a solution with O(n) time and O(n) space, where n is the size of the input array.
*/

#include <iostream>
#include <vector>
#include <stack>

class largestRectHistogram {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<std::pair<int, int>> hist_stack; // pair: (index, height)
        int max_area = 0;

        for (int i = 0; i <= heights.size(); i++){
            int start_id = i;
            while (!hist_stack.empty() && hist_stack.top().second > heights[i]){
                int idx = hist_stack.top().first;
                int h = hist_stack.top().second;
                hist_stack.pop();
                max_area = std::max(max_area, h * (i - idx));
                start_id = idx;
            }
            hist_stack.push({start_id, heights[i]});
        }
        while (!hist_stack.empty()){
            int idx = hist_stack.top().first;
            int h = hist_stack.top().second;
            hist_stack.pop();
            max_area = std::max(max_area, h * ((int)heights.size() - idx));
        }
        return max_area;
    }
};

int main() {
    largestRectHistogram lrh;
    std::vector<int> heights = {2,1,5,6,2,3};
    int result = lrh.largestRectangleArea(heights);
    std::cout << "Largest Rectangle Area: " << result << std::endl; // Output: 10
    return 0;
}
