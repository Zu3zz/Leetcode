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
    ListNode *detectCycle(ListNode *head) {
        // 这题目有个小坑 就是返回值
        // 不要去管题目的预期输出结果
        // 直接返回你定义的链表节点即可 leetcode会自动帮你做输出的转换

    	// 时间复杂度是8ms 为了阅读方便吧两个过程进行了拆解
    	// leetcode上4ms的答案直接将第二部分放入了第一部分中
        if(head==NULL || head->next == NULL){
            return NULL;
            // cout<<"no cycle"<<endl;
        }
        // 第一部分 先判断是否有环
        // 前一段和141题一样 用快指针慢指针判断是否有环
        ListNode* fast = head;
        ListNode* slow = head;
        bool hasLoop = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                hasLoop = true;
                break;
            }
        }
        // 第二部分 判断环的开始位置
        // 当快指针 慢指针相遇时，此时从头结点出发一个新指针 与慢指针速度相同
        // 当新指针与慢指针相遇时，恰巧会在环开始的节点相遇，直接返回定义的新指针即可
        // 证明过程如下: 设环开始前链表长度为a 环的长度为b
        // 快慢指针相遇时 假设慢指针已经在环上走了k个长度 且快指针速度为慢指针两倍
        // 则有方程如下 2(a+k) = a+b+k, 可解得k = b - a 
        // 也就是说此时如果慢指针需要重新走回到环开始的位置 还需要走a个长度 与从头结点开始的begin指针相同
        if(hasLoop){
            ListNode* begin = head;
            int count = 0;
            while(begin != slow){
                begin = begin->next;
                slow = slow->next;
                count+=1;
            }
            return begin;
            // cout<<"tail connects to node index "<<count<<endl;
        } else {
            return NULL;
            // cout<<"no cycle"<<endl;
        }
    }
    
};