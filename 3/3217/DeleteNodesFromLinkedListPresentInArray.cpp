/*
https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2025-11-01
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
        map<int, int>mp;
        for(auto &vals: nums) mp[vals]=vals;
        vector<int>allValids;
        while(head!=nullptr){
            int curVal=head->val;
            auto itr=mp.find(curVal);
            if(itr==mp.end()){
                allValids.push_back(curVal);
            }
            head=head->next;
        }
        ListNode *res=new ListNode(allValids[0]);
        ListNode *tailForRes=res;
        int sz=allValids.size();
        for(int i=1; i<=sz-1; ++i){
            ListNode *nwNode=new ListNode(allValids[i]);
            tailForRes->next=nwNode;
            tailForRes=nwNode;
        }
        return res;
    }
};