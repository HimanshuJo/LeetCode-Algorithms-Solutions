/*
https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/?envType=daily-question&envId=2025-07-14
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

    int toDec(string &str){
        int lngth=str.size(), res=0, bgnPw=lngth-1;
        for(int i=0; i<lngth; ++i){
            res+=(str[i]-'0')*(1<<bgnPw);
            bgnPw--;
        }
        return res;
    }

    int getDecimalValue(ListNode* head) {
        string bnstr="";
        while(head!=nullptr){
            bnstr+=to_string(head->val);
            head=head->next;
        }
        return toDec(bnstr);
    }
};