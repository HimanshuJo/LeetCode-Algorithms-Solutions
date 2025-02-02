/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int countOfAllNodes=0, idx=0, pointer=0;
        ListNode *tmp=head;
        while(tmp!=nullptr){
            countOfAllNodes++;
            tmp=tmp->next;
        }
        idx=countOfAllNodes-n;
        if(pointer==idx){
            if(countOfAllNodes==1) return nullptr;
            else{
                return head->next;
            }
        }
        ListNode *fnres=head;
        while(fnres!=nullptr){
            if(pointer+1==idx){
                ListNode *curnextnext=fnres->next->next;
                fnres->next=curnextnext;
            }
            fnres=fnres->next;
            pointer++;
        }
        return head;
    }
};