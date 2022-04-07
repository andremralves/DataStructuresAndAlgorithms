public class Stack {
    private static int items[] = new int[256]; 
    private static int count = 0;

    public static void main(String[] args) {
        push(5); 
        push(3); 
        push(2); 
        push(1); 

        for (int i = 0; i < 5; i++) {
            System.out.println(pop()); 
        }
    }

    // Push a new item to the stack and returns it.
    public static int push(int item) {
        if(isFull()) {
            System.out.println("Stack is Full!");
            return -1;
        }
        items[count] = item;
        count++; 
        return item;
    }

    // Pop an item from the stack and returns it.
    public static int pop() {
        if(isEmpty()) {
            System.out.println("Empty Stack!");
            return -1;
        }
        int item = items[count - 1];
        count--;
        return item;
    }

    // Returns a copy of the top element without removing it.
    public static int peek() {
        return items[count - 1];
    }

    // Check if the stack is Empty.
    public static boolean isEmpty() {
        return count == 0; 
    }

    // Check if the stack is Full.
    public static boolean isFull() {
        return count == 256; 
    }


}
