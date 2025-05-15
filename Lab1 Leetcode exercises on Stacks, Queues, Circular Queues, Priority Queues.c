1. Stack Programs
1.1 Reverse a String using Stack
Problem: Write a program to reverse a string using a stack.

Solution: You can use an array as a stack. Push each character of the string onto the stack and then pop each character to form the reversed string.
#include <stdio.h>
#include <string.h>
#define MAX 100

void reverse(char str[]) {
    int top = -1;
    char stack[MAX];
    int len = strlen(str);
    
    // Push characters onto stack
    for (int i = 0; i < len; i++) {
        stack[++top] = str[i];
    }
    
    // Pop characters from stack to reverse the string
    for (int i = 0; i < len; i++) {
        str[i] = stack[top--];
    }
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);
    
    reverse(str);
    
    printf("Reversed string: %s\n", str);
    
    return 0;
}

2. Queue Programs
2.1 Implementing a Simple Queue
Problem: Write a program to implement a simple queue using an array.

Solution: Use an array to simulate the queue and implement the enqueue and dequeue operations.
  #include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) front = rear = -1;
        else front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    
    display();
    
    dequeue();
    dequeue();
    
    display();
    
    return 0;
}


2.2 Circular Queue Implementation
Problem: Implement a circular queue using an array.

Solution: Use modular arithmetic to simulate the circular nature of the queue.
  #include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = value;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    
    display();
    
    dequeue();
    dequeue();
    
    display();
    
    return 0;
}

3. Priority Queue Program
3.1 Simple Priority Queue using an Array
Problem: Implement a simple priority queue where the highest priority element is dequeued first.

Solution: Use an array and sort the elements by priority before performing the dequeue operation.
  #include <stdio.h>
#define MAX 5

int queue[MAX];
int priority[MAX];
int size = 0;

void enqueue(int value, int prio) {
    if (size == MAX) {
        printf("Queue is full!\n");
        return;
    }
    queue[size] = value;
    priority[size] = prio;
    size++;
}

void dequeue() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return;
    }
    
    int maxPriorityIndex = 0;
    for (int i = 1; i < size; i++) {
        if (priority[i] > priority[maxPriorityIndex]) {
            maxPriorityIndex = i;
        }
    }
    
    printf("Dequeued: %d\n", queue[maxPriorityIndex]);
    
    for (int i = maxPriorityIndex; i < size - 1; i++) {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }
    
    size--;
}

void display() {
    if (size == 0) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10, 1);
    enqueue(20, 2);
    enqueue(30, 1);
    enqueue(40, 3);
    
    display();
    
    dequeue();
    dequeue();
    
    display();
    
    return 0;
}
