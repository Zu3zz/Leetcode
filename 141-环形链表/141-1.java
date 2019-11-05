/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
  public boolean hasCycle(ListNode head) {
      Set<ListNode> set = new HashSet<>();
      while(head!=null){
        if(set.contains(head)){
          return true;
        }else {
          set.add(head);
        }
        head = head.next;
      }
      return false;
  }
}