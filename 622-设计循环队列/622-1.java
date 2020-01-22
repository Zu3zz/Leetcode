class MyCircularQueue {
  int[] array;
  int front = 0;
  int tail = -1;
  int size = 0;

  /** Initialize your data structure here. Set the size of the queue to be k. */
  public MyCircularQueue(int k) {
      array = new int[k];
  }
  
  /** Insert an element into the circular queue. Return true if the operation is successful. */
  public boolean enQueue(int value) {
      if(isFull()){
          return false;
      }
      tail = (tail + 1) % array.length;
      array[tail] = value;
      size ++;
      return true;
  }
  
  /** Delete an element from the circular queue. Return true if the operation is successful. */
  public boolean deQueue() {
      if(isEmpty()){
          return false;
      }
      front = (front + 1) % array.length;
      size --;
      return true;
  }
  
  /** Get the front item from the queue. */
  public int Front() {
      return isEmpty() ? -1 : array[front];
  }
  
  /** Get the last item from the queue. */
  public int Rear() {
      return isEmpty() ? -1 : array[tail];
  }
  
  /** Checks whether the circular queue is empty or not. */
  public boolean isEmpty() {
      return size == 0;
  }
  
  /** Checks whether the circular queue is full or not. */
  public boolean isFull() {
      return size == array.length;
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
