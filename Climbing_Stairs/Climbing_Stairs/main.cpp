//
//  main.cpp
//  Climbing_Stairs
//
//  Created by Quanju Gu on 9/28/16.
//  Copyright © 2016 Jerry Gu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int *dp;
        dp = new int[n+1];
        if (n == 0 || n ==1)
            return 1;
        dp[0] =1; dp[1] = 1;
        for (int i=2; i < n+1;i++)
        {
            dp[i] = dp[i-1] + dp [i-2];
            //cout << "EACH DP VALUE IS : " << dp[i] << endl;
        }
        int result = dp[n];
        delete [] dp;
        return result;
    }
};

int main(int argc, const char * argv[])
{
    // insert code here...
    cout << "Hello, World!\n";
    Solution result;
    cout << "The result is :" << result.climbStairs(6) << endl;
    
    return 0;
}
