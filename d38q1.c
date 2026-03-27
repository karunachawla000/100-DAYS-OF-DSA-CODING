#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return (front == -1);
}

// Size
int size() {
    if (empty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

// Push front
void push_front(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }
    if (empty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = x;
}

// Push back
void push_back(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }
    if (empty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

// Pop front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Pop back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Get front
void get_front() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

// Get rear
void get_back() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

// Clear deque
void clear() {
    front = rear = -1;
}

// Display
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    display();

    pop_front();
    pop_back();
    display();

    get_front();
    get_back();

    printf("Size: %d\n", size());

    clear();
    display();

    return 0;
}
