/*
https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2024-09-06
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bool flag=false;
        ListNode *res=new ListNode(head->val);
        map<int, int>mp;
        for(auto &vals: nums){
            mp[vals]++;
        }
        ListNode *tail=res;
        while(head!=nullptr){
            int curval=head->val;
            auto itr=mp.find(curval);
            if(itr==mp.end()){
                if(!flag){
                    res=new ListNode(curval);
                    tail=res;
                    flag=true;
                } else{
                    ListNode *newNode=new ListNode(curval);
                    tail->next=newNode;
                    tail=tail->next;
                }
            }
            head=head->next;
        }
        return res;
    }
};