//
//  main.cpp
//  Median_of_Two_Sorted_Arrays_v2
//
//  Created by Quanju Gu on 9/22/16.
//  Copyright © 2016 Jerry Gu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;





class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> nums3;
        vector<int> nums4;
        nums3.assign(nums1.begin(), nums1.end());
        nums4.assign(nums2.begin(), nums2.end());
        
        int total = (int)(nums1.size() + nums2.size());
        //cout << "The total value is : " << total << endl;
        //int odd = (total % 2);
        if (total & 0x1)
            return find_kth(nums1, nums2, total / 2 + 1);
        else
        {
            //cout << "The first value is : " << find_kth(nums1, nums2, total /2) << endl;
            //cout << "The second value is : " << find_kth(nums1, nums2, total /2 + 1) << endl;
            
            return (find_kth(nums1, nums2, total /2) + find_kth(nums3, nums4, total /2 + 1)) / 2;
        }
    }
    
private:
    
    static double find_kth(vector<int>& nums1, vector<int>& nums2,int k)
    {
        //always assume nums1.size is equal or smaller than nums2.size
        if (nums1.size() > nums2.size())
            return find_kth(nums2, nums1, k);
        if (nums1.size() == 0)
            return nums2[k - 1];
        if(k == 1)
            return min(nums1[0],nums2[0]);
        
        //divde k into two parts
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int pa = min(k / 2, m);
        int pb = k - pa;
        if (nums1[pa - 1] <= nums2[pb -1])
        {
            vector<int> num1_new(nums1.begin() + pa,nums1.end());
            //nums1.erase(nums1.begin(),nums1.begin()+pa);
            return find_kth(num1_new, nums2 , k - pa);
            
        }
        else if(nums1[pa - 1] > nums2[pb -1])
        {
            vector<int> num2_new(nums2.begin() + pb,nums2.end());
            //nums2.erase(nums2.begin(),nums2.begin()+pb);
            return find_kth(nums1, num2_new , k - pb);
        }
        else
        {
            return nums1[pa -1];
        }
        
    }
    
};


int main()
{
    // insert code here...
    cout << "Hello, World!\n";
    int A[] = {1,3,6,7};
    vector<int> num1(A, A+4);
    int B[] = {2,4,5,8};
    vector<int> num2(B,B+4);
    
    //int myarray[5] = {1,3,5,7,9};
    //vector<int> myvector(myarray , myarray+5);
    //cout << "The myvector value is : " << myvector[1] << endl;
    
    
    //int n = A.size();
    double result = 0;
    Solution test;
    result = test.findMedianSortedArrays(num1,num2);
    //result = test.removeDuplicates(A,n);
    //Solution(A[],n);
    //result = Solution.removeDuplicates(A[],n);
    cout << "result:" << result << endl;
    return 0;
}
