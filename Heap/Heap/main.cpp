#include <iostream>
#define MAXHEAP 1
#define MINHEAP 0
using namespace std;

struct Vector {
    int* array;
    int size;
    int MaxCapacity;
};

Vector initialize() {
    Vector n;
    n.size = 0;
    n.MaxCapacity = 2;
    n.array = new int[n.MaxCapacity];
    return n;
}


void push_back(Vector& n, int DataToBeAdded) {
    if (n.size >= n.MaxCapacity) {
        int* tmp = n.array;
        n.MaxCapacity *= 2;
        n.array = new int[n.MaxCapacity];
        for (int i = 0; i < n.size; i++) {
            n.array[i] = tmp[i];
        }
        delete tmp;
    }
    n.array[n.size++] = DataToBeAdded;
    return;
}

void pop_last(Vector& n) {
    if (n.size >0) {
        if (--(n.size) < n.MaxCapacity /2) {
            int* tmp = n.array;
            n.MaxCapacity /= 2;
            n.array = new int[n.MaxCapacity];
            for (int i = 0; i < n.size; i++) {
                n.array[i] = tmp[i];
            }
            delete tmp;
        }
    }
    return;
}

void Heapify(Vector& tab, int parent, bool HeapMode) {
    int maxIndex = parent;
    int n = tab.size;
    int left = parent * 2 + 1;
    int right = parent * 2 + 2;
    if (HeapMode) {
        if (left<n && tab.array[left]>tab.array[maxIndex])  maxIndex = left;
        if (right<n && tab.array[right]>tab.array[maxIndex])  maxIndex = right;
        if (maxIndex != parent) {
            int temp = tab.array[parent];
            tab.array[parent] = tab.array[maxIndex];
            tab.array[maxIndex] = temp;

            Heapify(tab, maxIndex, HeapMode);
        }
    }
    else if (!HeapMode) {
        if (left < n && tab.array[left] < tab.array[maxIndex])  maxIndex = left;
        if (right < n && tab.array[right] < tab.array[maxIndex])  maxIndex = right;
        if (maxIndex != parent) {
            int temp = tab.array[parent];
            tab.array[parent] = tab.array[maxIndex];
            tab.array[maxIndex] = temp;
            Heapify(tab, maxIndex, HeapMode);
        }
    }
}

void buildHeap(Vector& tab, bool HeapMode)
{
    int IndexOfLastParent = ((tab.size) / 2) - 1;
    for (int i = IndexOfLastParent; i >= 0; i--) {
       Heapify(tab, i, HeapMode);
    }
}

void deleteRoot(Vector& tab, bool HeapMode)
{
    int lastElement = tab.array[tab.size -1];

    tab.array[0] = lastElement;

    pop_last(tab);

    Heapify(tab, 0, HeapMode);
}

int main() {
    Vector vector=initialize();
    char command;
    bool HeapMode = MAXHEAP;
    int state = 1;
    while (state) {
        cin >> command;
        switch (command) {
        case '+': {
            int DataToBeAdded;
            cin >> DataToBeAdded;
            push_back(vector, DataToBeAdded);
            buildHeap(vector, HeapMode);
            break;
        }
        case '-': {
            if (vector.size > 0) {
                cout << vector.array[0] << endl;
                deleteRoot(vector, HeapMode);
                buildHeap(vector, HeapMode);
                break;
            }
            else if (vector.size == 0) { cout << endl; break; }
           
            break;
        }
        case 'p': {
            if (vector.size > 0) {
                for (int i = 0; i < vector.size; i++)cout << vector.array[i] << " ";
                cout << endl;        
                break;
            }
            else if (vector.size == 0) cout << endl;
            break;
        }

        case 'r': {
            int number_of_elements, DataToBeAdded;
            cin >> number_of_elements;
            int* temp = vector.array;
            delete temp;
            vector = initialize();
            for (int i = 0; i < number_of_elements; i++) {
                cin >> DataToBeAdded;
                push_back(vector, DataToBeAdded);
            }
            buildHeap(vector, HeapMode);
            break;
        }
        case 's': {
            if (HeapMode) HeapMode = MINHEAP;
            else if (!HeapMode) HeapMode = MAXHEAP;
            buildHeap(vector, HeapMode);
            break;
        }
        case 'q': {
            state = 0;
            break;
        }
        }
    }
        return 0;
    }
