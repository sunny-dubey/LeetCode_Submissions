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
    
    int getLength(ListNode* &head)
    {
        int l = 0;
        ListNode*temp = head;
        while(temp!=NULL)
        {
            l++;
            temp = temp->next;
        }
        return l;
        
    }
    
    ListNode* middleNode(ListNode* head) {
        int l = getLength(head);
        int ans = l/2;
        int count = 0;
        ListNode *temp = head;
        while(count<ans)
        {
            temp = temp->next;
            count++;
        }
        return temp;
    }
};