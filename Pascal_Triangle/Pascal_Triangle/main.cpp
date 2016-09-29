//
//  main.cpp
//  Pascal_Triangle
//
//  Created by Quanju Gu on 9/27/16.
//  Copyright © 2016 Jerry Gu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        if(numRows == 0)
            return result;
        result.push_back(vector<int>(1,1));//push the first line
        
        for (int i=1; i< numRows; i++)
        {
            vector<int> v;
            for (int j=0;j<=i;j++)
            {
                if(j==0 ||j==i)
                    v.push_back(1);
                else
                {
                    v.push_back(result[i-1][j-1]+result[i-1][j]);
                }
            }
        result.push_back(v);
        }
        /*
        for (int i = 2; i <= numRows; i++)
        {
            vector<int> current(i,1);//?
            const vector<int> &prev = result[i-2];
            
            for(int j =1; j< i-1; j++)
            {
                current[j] = prev[j-1] + prev[j];
            }
            result.push_back(current);
        }
         */
        return result;
    }
};

int main(int argc, const char * argv[])
{
    // insert code here...
    cout << "Hello, World!\n";
    vector<vector <int>> ans;
    Solution result;
    ans = result.generate(5);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
        cout << "The result is : " << i <<"and " << j<< " BELWOW "<< ans[i][j] <<endl;
        }
    }
    return 0;
}
