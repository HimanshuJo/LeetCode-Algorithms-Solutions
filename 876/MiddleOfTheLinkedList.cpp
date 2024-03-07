/*
https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07
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
    ListNode* middleNode(ListNode* head) {
        vector<int>all;
        ListNode *tmp=head, *anthtmp=head;
        while(head!=nullptr){
            all.push_back(head->val);
            head=head->next;
        }
        int sz=all.size(), count=sz/2;
        while(count--){
            anthtmp=anthtmp->next;
        }
        return anthtmp;
    }
};