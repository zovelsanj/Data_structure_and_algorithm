/*11. Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
Eg:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.*/
#include<iostream>
#include<vector>
using namespace std;

class Container {
public:
    Container() 
    {
        //This constructer is not much of use here but it significantly reduces the runtime for very large number of inputs.
        ios_base::sync_with_stdio(false);   //disable i/o sync between C++ and C equivalents to remove overhead
        cin.tie(NULL);  //untie cin and cout
    }
    int maxArea(vector<int>& height) 
    {
        int ptr1 = 0;
        int ptr2 = height.size()-1;
        int max_area = 0;
        int area = 0;
        while (ptr1<ptr2)
        {
            if (height[ptr1]<height[ptr2])
            {
                area = height[ptr1]*(ptr2-ptr1);
                ptr1++;
            }
            else 
            {
                area = height[ptr2]*(ptr2-ptr1);
                ptr2--;
            }
            max_area = (max_area<area)?area:max_area;
        }
        return max_area;
    }
};

int main()
{
    vector<int> height {1,8,6,2,5,4,8,3,7};
    Container c;
    cout<<"Max Area of Container: "<<c.maxArea(height)<<endl;
}
