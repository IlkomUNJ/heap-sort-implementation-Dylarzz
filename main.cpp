#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int lChild(int i) { return (2 * i + 1); }
    int rChild(int i) { return (2 * i + 2); }

    void heapifyDown(int i) {
        int largest = i;
        int left = lChild(i);
        int right = rChild(i);

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;
        
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    MaxHeap() {}

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int getMax() {
        return heap.empty() ? -1 : heap[0];
    }

    int size() {
        return heap.size();
    }

    void displayHeap() {
        cout << "Heap elements: ";
        for (int num : heap)
            cout << num << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap heap;

    heap.insert(16);
    heap.insert(4);
    heap.insert(10);
    heap.insert(14);
    heap.insert(7);
    heap.insert(9);
    heap.insert(3);
    heap.insert(2);
    heap.insert(8);
    heap.insert(1);

    heap.displayHeap();

    cout << "Current max value: " << heap.getMax() << endl;

    return 0;
}
