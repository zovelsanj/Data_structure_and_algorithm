/* Car Fleet (Medium)

There are n cars traveling to the same destination on a one-lane highway. You are given two arrays of integers position and speed, both of length n.
position[i] is the position of the ith car (in miles), speed[i] is the speed of the ith car (in miles per hour). The destination is at position target miles.

A car can not pass another car ahead of it. It can only catch up to another car and then drive at the same speed as the car ahead of it.
A car fleet is a non-empty set of cars driving at the same position and same speed. A single car is also considered a car fleet.
If a car catches up to a car fleet the moment the fleet reaches the destination, then the car is considered to be part of the fleet.
Return the number of different car fleets that will arrive at the destination.

Example:
Input: target = 10, position = [4,1,0,7], speed = [2,2,1,1]
Output: 3
Explanation: The cars starting at 4 and 7 become a fleet at position 10. The cars starting at 1 and 0 never catch up to the car ahead of them. Thus, there are 3 car fleets that will arrive at the destination.

You should aim for a solution with O(nlogn) time and O(n) space, where n is the size of the input array.
*/

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

class carFleet {
public:
    std::vector<std::pair<int, int> > reverseSort(std::vector<int> &X, std::vector<int> &Y){
        std::vector<std::pair<int, int> > pairs;
        for (int i = 0; i < X.size(); i++) {
            pairs.push_back({X[i], Y[i]});
        }
        std::sort(pairs.begin(), pairs.end(),
        [](auto& a, auto& b) { return a.first > b.first; });
        return pairs;
    }
    int carFleetNum(int target, std::vector<int> &position, std::vector<int> &speed){
        std::vector<float> carStack;
        std::vector<std::pair<int, int> > pairs = reverseSort(position, speed);
        for (auto &[pos, s]: pairs){
            float time = float(target-pos)/s;
            carStack.push_back(time);
            if (carStack.size() > 1 && carStack.back() <= carStack[carStack.size()-2]){
                carStack.pop_back();
            }
        }
        return carStack.size();
    }
};

int main(){
    int target = 10;
    std::vector<int> position = {6,8};
    std::vector<int> speed = {3, 2};
    carFleet cf;
    int result = cf.carFleetNum(target, position, speed);
    std::cout << result << std::endl;
    return 0;
}
