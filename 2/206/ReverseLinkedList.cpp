/*
https://leetcode.com/problems/reverse-linked-list/description/?envType=daily-question&envId=2024-03-21
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=nullptr;
        while(head!=nullptr){
            ListNode *curnext=head->next;
            head->next=prev;
            prev=head;
            head=curnext;
        }
        return prev;
    }
};