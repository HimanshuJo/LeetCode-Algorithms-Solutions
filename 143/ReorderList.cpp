/*
https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23
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
    void reorderList(ListNode* head) {
        if(head->next==nullptr) return;
        ListNode *res=head;
        ListNode *anthhead=head;
        vector<int>all;
        while(anthhead!=nullptr){
            all.push_back(anthhead->val);
            anthhead=anthhead->next;
        }
        int sz=all.size(), left=1, right=sz-2, count=0;
        ListNode *tmpres=res;
        tmpres->next=new ListNode(all[sz-1]);
        tmpres=tmpres->next;
        while(left<=right){
            if(count%2==0){
                tmpres->next=new ListNode(all[left++]);
            } else{
                tmpres->next=new ListNode(all[right--]);
            }
            tmpres=tmpres->next;
            count++;
        }
    }
};