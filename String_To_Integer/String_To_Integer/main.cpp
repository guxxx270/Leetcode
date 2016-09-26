//
//  main.cpp
//  String_To_Integer
//
//  Created by Quanju Gu on 9/24/16.
//  Copyright © 2016 Jerry Gu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int i = 0;
        int t = 0;
        int temp = 0;
        while (str[i] == ' ')
        {
            i++;
            t++;
        }
        
        while(str[i] == '-' || str[i] == '+')
        {
            if(str[i] == '+' && str[i+1] == '-')
            {
                return 0;
            }
            
            if(str[i] == '-' && str[i+1] == '+')
            {
                return 0;
            }
            
            if(str[i] == '+' && str[i+1] == '+')
            {
                return 0;
            }
            
            if(str[i] == '-' && str[i+1] == '-')
            {
                return 0;
            }
            i++;
            t++;
        }

        while(str[i] == 0)
        {
            i++;
        }
        
        for(; i < str.size();)
        {
 
            if (str[i] < '0' || str[i] > '9')
                break;
            if ((temp == 214748364 && (str[i] - '0') > 7) || temp > 214748364)
            {
                if (str[t-1] == '-')
                    temp = -2147483648;
                else
                temp = 2147483647;
                break;
            }
            
            temp = temp * 10 + (str[i] - '0');
            i++;
        }
        
        for(int j=0;j < t;j++)
        {
            if(str[j] == '-' && temp != -2147483648)
            temp = -temp;
        }
        
        if(temp > 2147483647)
        {
            temp = 2147483647;
        }
        
        return temp;
    }
};

/*
 int str2int(const char *str)
 {
 int temp = 0;
 const char *ptr = str;  //ptr保存str字符串开头
 
 if (*str == '-' || *str == '+')  //如果第一个字符是正负号，
 {                      //则移到下一个字符
 str++;
 }
 while(*str != 0)
 {
 if ((*str < '0') || (*str > '9'))  //如果当前字符不是数字
 {                       //则退出循环
 break;
 }
 temp = temp * 10 + (*str - '0'); //如果当前字符是数字则计算数值
 str++;      //移到下一个字符
 }
 if (*ptr == '-')     //如果字符串是以“-”开头，则转换成其相反数
 {
 temp = -temp;
 }
 
 return temp;
 }
*/
int main()
{
    int n = 0;
    //char p[10] = "";
    string t = "      -11919730356x";
    cout << "Test data: " << t[1] << endl;
    //cin.getline(p, 20);   //从终端获取一个字符串
    //n = str2int(p);      //把字符串转换成整型数
    Solution result;
    n = result.myAtoi(t);
    cout << "The result is : "<< n << endl;
    
    return 0;
}
