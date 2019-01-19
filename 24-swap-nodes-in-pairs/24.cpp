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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next == NULL){
            return head;
        }
        // 定义一个新的头指针pstart
        // 定义一个pre指针 用来指向一组两个元素中位置靠前的一位
        // 此时新的头指针指向的next节点就是题目给出的head节点
        ListNode* pstart = new ListNode(0);
        ListNode* pre = pstart;
        pstart->next = head;
        // 当一组内的两个指针都存在时, while循环才会继续
        while(pre->next&&pre->next->next){
            // 定义两个临时链表, 用来存储此时下一组两个链表的位置
            ListNode* a = pre->next;
            ListNode* b = a->next;
            ListNode* temp = b->next;
            // 改变互相的指向位置
            pre->next = b;
            b->next = a;
            a->next = temp;
            pre = a;
        }
        return pstart->next;
    }
};