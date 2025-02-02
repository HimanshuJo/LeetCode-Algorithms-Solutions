/*
https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*>st;
        while(head!=nullptr){
            if(st.find(head)!=st.end()) return true;
            st.insert(head);
            head=head->next;
        }
        return false;
    }
};