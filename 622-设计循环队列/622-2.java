// 你妈死了
class MyCircularQueue {
  private int[] list;
  private int front;
  private int tail;
  private int size;

  /** Initialize your data structure here. Set the size of the queue to be k. */
  public MyCircularQueue(int k) {
      list = new int[k];
      front = -1;
      tail = -1;
      size = k;
  }
  
  /** Insert an element into the circular queue. Return true if the operation is successful. */
  public boolean enQueue(int value) {
      if(isFull()){
          return false;
      }
      if(isEmpty()){
          front = 0;
      }
      tail = (tail + 1) % size;
      list[tail] = value;
      return true;
  }
  
  /** Delete an element from the circular queue. Return true if the operation is successful. */
  public boolean deQueue() {
      if(isEmpty()){
          return false;
      }
      if(front == tail){
          front = -1;
          tail = -1;
          return true;
      }
      front = (front + 1) % list.length;
      return true;
  }
  
  /** Get the front item from the queue. */
  public int Front() {
      // System.out.println(front);
      return isEmpty() ? -1 : list[front];
  }
  
  /** Get the last item from the queue. */
  public int Rear() {
      System.out.println(tail);
      return isEmpty() ? -1 : list[tail];
  }
  
  /** Checks whether the circular queue is empty or not. */
  public boolean isEmpty() {
      return front == -1;
  }
  
  /** Checks whether the circular queue is full or not. */
  public boolean isFull() {
      return ((tail+1) % size) == front;
  }
}

/**
* Your MyCircularQueue object will be instantiated and called as such:
* MyCircularQueue obj = new MyCircularQueue(k);
* boolean param_1 = obj.enQueue(value);
* boolean param_2 = obj.deQueue();
* int param_3 = obj.Front();
* int param_4 = obj.Rear();
* boolean param_5 = obj.isEmpty();
* boolean param_6 = obj.isFull();
*/