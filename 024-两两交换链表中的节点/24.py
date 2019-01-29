# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        // 总体思路与cpp的相同 新建一个头指针phead
        // 两个一组分别改变其指向 循环终止条件就是剩余个数不足两个
        phead = ListNode(None)
        pre,pre.next = phead,head
        while pre.next and pre.next.next:
            a = pre.next
            b = a.next
            pre.next,b.next,a.next = b,a,b.next
            pre = a
        return phead.next