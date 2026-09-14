
//QUESTION 1
#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (heap[parent] >= heap[i])
                break;

            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest == i)
                break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int remove() {
        if (heap.empty())
            return -1;

        int x = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);

        return x;
    }

    void display() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};


class MinHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (heap[parent] <= heap[i])
                break;

            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;

            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i)
                break;

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int remove() {
        if (heap.empty())
            return -1;

        int x = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);

        return x;
    }

    void display() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
  
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
  
    MaxHeap maxHeap;

    maxHeap.insert(30);
    maxHeap.insert(10);
    maxHeap.insert(50);
    maxHeap.insert(20);
    maxHeap.insert(40);

    cout << "Max Heap: ";
    maxHeap.display();

    cout << "Removed from Max Heap: " << maxHeap.remove() << endl;

    MinHeap minHeap;

    minHeap.insert(30);
    minHeap.insert(10);
    minHeap.insert(50);
    minHeap.insert(20);
    minHeap.insert(40);

    cout << "Min Heap: ";
    minHeap.display();

    cout << "Removed from Min Heap: " << minHeap.remove() << endl;

    MaxHeap priorityQueue;

    priorityQueue.insert(5);
    priorityQueue.insert(20);
    priorityQueue.insert(10);
    priorityQueue.insert(50);
    priorityQueue.insert(30);

    cout << "Priority Queue: ";
    priorityQueue.display();

    cout << "Highest Priority: "<< priorityQueue.remove() << endl;

    int arr[] = {40, 10, 30, 50, 20};
    int n = 5;

    heapSort(arr, n);

    cout << "Heap Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}


//QUESTION 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<long long> a(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<long long> ans;

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        if (left == right) {
            ans.push_back(a[left]);
            break;
        }

        ans.push_back(a[left]);
        ans.push_back(a[right]);

        left++;
        right--;
    }

    long long sum = 0;

    for (int i = 0; i < n - 1; i++)
        sum += abs(ans[i] - ans[i + 1]);

    cout << "Rearranged Array: ";

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    cout << "\nTotal Sum = " << sum;

    return 0;
}


//QUESTION 3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target: ";
    cin >> target;

    int left = 0;
    int minLength = n + 1;
    long long sum = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        while (sum > target) {
            minLength = min(minLength, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }

    if (minLength == n + 1)
        cout << "Output: -1";
    else
        cout << "Output: " << minLength;

    return 0;
}