//
//  main.cpp
//  Search_Insert_Position
//
//  Created by Quanju Gu on 9/27/16.
//  Copyright © 2016 Jerry Gu. All rights reserved.
//


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size(),mid;
        while(low < high)
        {
            mid = (low + high) /2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                high = mid;
            else
                low = mid + 1;
        }
    return low;
    }
};

int main()
{
    // insert code here...
    cout << "Hello, World!\n";
    
    //int A[] = {2,7,4};
    int A[] = {4,5,7,9,10};
    vector<int> numsA(A,A+5);
    //int B[] = {1,5,6};
    //vector<int> numsB(B,B+3);
    
    //vector<int> ans;
    Solution result;
    cout << "the result is " << result.searchInsert(numsA, 6) << endl;
    /*
    vector<int>::iterator it;
    it =numsA.begin();
    while ( it !=numsA.end())
    {
        cout << (*it) << endl;
        it ++;
    }
    */
    return 0;
}

