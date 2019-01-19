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
        // 1.使用set方法 判断是否每个节点只出现过一次
        // 2.快指针慢指针 快指针一次走两步 慢指针一次走一步 如果能够相遇
        // 那么说明是一个闭合环
        // 时间 8ms 奇怪的是4ms的答案和我一样 不知道哪里多了两倍的时间
        if(head==NULL||head->next==NULL){
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast &&fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};