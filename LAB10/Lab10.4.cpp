#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class DynamicArray {
protected:
    T* arr;
    int capacity;
    int length;

    virtual void resize(int newCapacity) = 0;

public:
    DynamicArray(int initialCapacity = 10) : capacity(initialCapacity), length(0) {
        arr = new T[capacity];
    }

    virtual ~DynamicArray() {
        delete[] arr;
    }

    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual int size() const = 0;
};

template <typename T>
class DynamicQueue : public DynamicArray<T> {
private:
    int front;
    int rear;

    void resize(int newCapacity) override {
        T* newArr = new T[newCapacity];
        int j = 0;

        for (int i = front; i != rear; i = (i + 1) % this->capacity) {
            newArr[j++] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = newArr;
        this->capacity = newCapacity;
        front = 0;
        rear = j;
    }

public:
    DynamicQueue(int initialCapacity = 10) : DynamicArray<T>(initialCapacity), front(0), rear(0) {}

    bool isEmpty() const override {
        return front == rear;
    }

    bool isFull() const override {
        return (rear + 1) % this->capacity == front;
    }

    int size() const override {
        return (rear - front + this->capacity) % this->capacity;
    }

    T Front() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return this->arr[front];
    }

    T Rear() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return this->arr[(rear - 1 + this->capacity) % this->capacity];
    }

    void enqueue(T value) {
        if (isFull()) {
            resize(this->capacity * 2);
        }

        this->arr[rear] = value;
        rear = (rear + 1) % this->capacity;
        this->length++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }

        T value = this->arr[front];
        front = (front + 1) % this->capacity;
        this->length--;

        if (this->length > 0 && this->length == this->capacity / 4) {
            resize(this->capacity / 2);
        }

        return value;
    }
};

int main() {
	cout << " The code is written by MESUM ABBAS CT-238" << endl;
    DynamicQueue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;
    cout << "Size: " << q.size() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;
    cout << "Size: " << q.size() << endl;

    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;
    cout << "Size: " << q.size() << endl;

    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    return 0;
}
