class MyCircularDeque {
public:
    vector<int> queue;
    int front;
    int rear;
    int cap;
    int currSize;
    MyCircularDeque(int k) {
        cap = k;
        queue.resize(cap, 0);
        front = 0;
        rear = cap-1;
        currSize = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        front = (front - 1 + cap) % cap;
        queue[front] = value;
        currSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }

        rear = (rear + 1) % cap;
        queue[rear] = value;
        currSize++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }

        front = (front + 1) % cap;
        currSize--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        rear = (rear - 1 + cap) % cap;
        currSize--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }

        return queue[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }

        return queue[rear];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */