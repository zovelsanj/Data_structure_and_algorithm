/* 347. TOP K FREQUENT ELEMENTS
Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.
Eg: Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

class topKFrequent {
public:
    static bool sortByVal(const pair<int , int> &a, const pair<int , int> &b) 
    { 
        return (a.second > b.second); 
    } 
    vector<int> getTopKFrequent(vector<int>& nums, int k) 
    {
        unordered_map <int , int > freq_nums;
        vector<int> top_freq_nums;
        for (int i = 0; i < nums.size(); i++)
        {
           freq_nums[nums.at(i)]++;
        }

        vector<pair<int, int>> sorted_map;
        unordered_map <int, int> :: iterator it;
        for (it=freq_nums.begin(); it!=freq_nums.end(); it++) 
        {
            sorted_map.push_back(make_pair(it->first, it->second));
        }

        sort(sorted_map.begin(), sorted_map.end(), sortByVal);
        for (int i = 0; i < k; i++)
        {
            top_freq_nums.push_back(sorted_map[i].first);
            
        }
        // for (int i = 0; i < sorted_map.size(); i++)
        //     cout << "Key: " << sorted_map[i].first << ", Value: " << sorted_map[i].second << endl;
        return top_freq_nums;
    }
};

int main()
{
    vector<int> nums {1, 1, 1, 2, 2, 3, 3, 5};
    vector<int> nfrequent_nums;
    topKFrequent t;
    nfrequent_nums = t.getTopKFrequent(nums, 2);
}