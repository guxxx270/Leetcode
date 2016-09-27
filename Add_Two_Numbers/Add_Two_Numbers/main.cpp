//
//  main.cpp
//  Add_Two_Numbers
//
//  Created by Quanju Gu on 9/23/16.
//  Copyright © 2016 Jerry Gu. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    
    } // This line means to initialize the value
    //put x to val and nullptr to next address
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *pa = l1;
        ListNode *pb = l2;
        int carry = 0;
        ListNode *first;
        ListNode newHead(0);
        first = &newHead;
        
        while (pa !=nullptr || pb !=nullptr || carry != 0)
        {
            int num1 = pa == nullptr ? 0 : pa->val;
            int num2 = pb == nullptr ? 0 : pb->val;
            int sum = num1 + num2 + carry;
            carry = sum /10;
            sum = sum % 10;
            
            first->next = new ListNode(sum);
            first = first->next;
            
            pa = pa == nullptr?nullptr:pa->next;
            pb = pb == nullptr?nullptr:pb->next;
        }
        //return newHead;
        return newHead.next; //here we get the first address of the value
    }
};

int main()
{
    // insert code here...
    cout << "Hello, World!\n";
    //how to put number in link list//using dynamically allocated
    ListNode *head,*second,*third;
    head = new ListNode(0);
    second = new ListNode(0);
    third = new ListNode(0);
    
    head->val = 3;
    head->next = second;
    
    second->val = 0;
    second->next = third;
    
    third->val = 4;
    third->next = nullptr;
    
    //THE SECOND METHOD TO USE LINK LIST.
    ListNode *first;
    ListNode chest1(5),chest2(0),chest3(6);
    first = &chest1;
    chest1.next = &chest2;
    chest2.next = &chest3;
    chest3.next = nullptr;
    
    Solution result;
    
    ListNode *p;
    p = result.addTwoNumbers(head, first);
    while (p != nullptr)
    {
        cout << "The listnode value is : " << p->val << endl;
        p = p-> next;
    }
    
    delete head;
    delete second;
    delete third;
    return 0;
}
