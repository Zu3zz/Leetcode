/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
  public ListNode middleNode(ListNode head) {
      ListNode dummy = head;
      while(dummy != null && dummy.next != null){
          dummy = dummy.next.next;
          head = head.next;
      }
      return head;
  }
}