class MyCircularQueue {
private:
    vector<int> q; 
    int front = 0, rear = 0;
    int k = 0;  
public:
    MyCircularQueue(int l) 
    {
        k = l;
        q.resize(k+1);  
        k = k+1;  
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % k;
        q[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % k;
        return true;
    }
    
    int Front() {
        
        return isEmpty() ? -1 : q[(front + 1) % k]; 
        
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[rear];  
    }
    
    bool isEmpty() {
        return front == rear; 
    }
    
    bool isFull() {
        return (rear + 1) % k == front;
    }
};