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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return head;
        }
        // 初始化两个指针 pre用来指向链表的末尾
        // cur用来记录当前指针位置 
        // 将cur->next记录为pre 依次后延
        ListNode* pre = NULL;
        ListNode* cur = head;
        // 用save记录cur->next的位置 否则在赋予pre指针的时候会发生指向错误
        ListNode* save = NULL;
        while(cur!=NULL){
            save = cur->next;
            cur->next = pre;
            pre = cur;
            cur = save;
        }
        return pre;
    }
};