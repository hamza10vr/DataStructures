#include<list>
#include<iostream>

 // Definition for singly-linked list.
 struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 



 class Solution {
 public:
     ListNode* oddEvenList(ListNode* head) {
         if (!head || !(head->next)) {
             return head;
         }

         ListNode* odd = head;
         ListNode* evenHead = head->next;
         ListNode* even = head->next;

         bool oddTurn = true;
         while (even) {
             if (oddTurn) {
                 odd->next = even->next;
                 odd = odd->next ? odd->next : odd;
                 oddTurn = false;
             }
             else {
                 even->next = odd->next;
                 even = even->next;
                 oddTurn = true;
             }
         }

         odd->next = evenHead;

         return head;

     }
 };