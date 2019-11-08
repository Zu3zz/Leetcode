/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
  public ListNode reverseList(ListNode head) {
      ListNode newHead = null;
      while(head!=null){
          ListNode tmp = head.next;
          head.next = newHead;
          newHead = head;
          head = tmp;
      }
      return newHead;
  }
}