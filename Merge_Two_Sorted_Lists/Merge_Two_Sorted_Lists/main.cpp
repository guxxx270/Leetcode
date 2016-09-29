//
//  main.cpp
//  Merge_Two_Sorted_Lists
//
//  Created by Quanju Gu on 9/26/16.
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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *pa = l1;
        ListNode *pb = l2;
        ListNode *first;
        ListNode newHead(0);
        first = &newHead;
        
        while((pa != nullptr) || (pb != nullptr))
        {
            int num1 = pa == nullptr?INT_MAX : pa->val;
            int num2 = pb == nullptr?INT_MAX : pb->val;
            
            if((num1) < (num2))
            {
                first->next = pa;
                pa = pa->next;
                first = first->next;
            }
            else
            {
                first->next = pb;
                pb = pb->next;
                first = first->next;
            }
            

        }
        
        return newHead.next;
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
    
    second->val = 4;
    second->next = third;
    
    third->val = 5;
    third->next = nullptr;
    
    //THE SECOND METHOD TO USE LINK LIST.
    ListNode *first;
    ListNode chest1(1),chest2(2),chest3(3);
    first = &chest1;
    chest1.next = &chest2;
    chest2.next = &chest3;
    chest3.next = nullptr;
    
    Solution result;
    
    ListNode *p;
    
    p = result.mergeTwoLists(head, first);
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
