//
//  main.cpp
//  Merge_Sorted_Array
//
//  Created by Quanju Gu on 9/26/16.
//  Copyright © 2016 Jerry Gu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i,j=0;
        vector<int> temp;
        while((i<m) && (j<n))
        {
            if(nums1[i]<nums2[j])
            {
                temp.push_back(nums1[i]);
                i++;
            }
            else
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        if (i == m)
        {
            while(j<n)
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        if (j == n)
        {
            while(i<m)
            {
                temp.push_back(nums1[i]);
                i++;
            }
        }
        
        nums1 = temp;
    }
};

int main()
{
    // insert code here...
    cout << "Hello, World!\n";
    
    //int A[] = {2,7,4};
    int A[] = {2,3,4};
    vector<int> numsA(A,A+3);
    int B[] = {1,5,6};
    vector<int> numsB(B,B+3);
 
    //vector<int> ans;
    Solution result;
    result.merge(numsA,3, numsB,3);
    
    
    vector<int>::iterator it;
    it =numsA.begin();
    while ( it !=numsA.end())
    {
        cout << (*it) << endl;
        it ++;
    }
    
    return 0;
}
