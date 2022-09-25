class MyCircularQueue {
private:
    vector<int> q; 
    int front = 0, rear = 0; // initialize index 0 as diffirentiator index
    int qSize = 0;  
public:
    MyCircularQueue(int k) 
    {
        q.resize(k+1);  // +1 for differentiator index
        qSize = k+1;  
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % qSize;
        q[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % qSize;
        return true;
    }
    
    int Front() {
        
        return isEmpty() ? -1 : q[(front + 1) % qSize]; 
        
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[rear];  
    }
    
    bool isEmpty() {
        return front == rear; 
    }
    
    bool isFull() {
        return (rear + 1) % qSize == front;
    }
};