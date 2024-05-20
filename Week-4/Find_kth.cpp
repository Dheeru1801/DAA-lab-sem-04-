#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Heapify function to maintain the heap property
void heapify(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] < arr[smallest])
        smallest = leftChild;
    if (rightChild < n && arr[rightChild] < arr[smallest])
        smallest = rightChild;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Function to build a min-heap
void buildMinHeap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

// Function to find the Kth smallest element using min-heap
int findKthSmallest(vector<int> &arr, int K)
{
    int n = arr.size();
    if (K > n || K < 1)
    {
        return INT_MAX; // K is out of bounds
    }

    buildMinHeap(arr, n);

    for (int i = 0; i < K - 1; i++)
    {
        swap(arr[0], arr[n - 1]);
        n--;
        heapify(arr, n, 0);
    }

    return arr[0];
}

// Function to build a max-heap
void heapifyMax(vector<int> &arr, int n, int i)
{
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

// Function to find the Kth largest element using max-heap
int findKthLargest(vector<int> &arr, int K)
{
    int n = arr.size();
    if (K > n || K < 1)
    {
        return INT_MAX; // K is out of bounds
    }

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMax(arr, n, i);
    }

    for (int i = 0; i < K - 1; i++)
    {
        swap(arr[0], arr[n - 1]);
        n--;
        heapifyMax(arr, n, 0);
    }

    return arr[0];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int K;
        cin >> K;

        int resultSmallest = findKthSmallest(arr, K);
        int resultLargest = findKthLargest(arr, K);

        if (resultSmallest == INT_MAX)
        {
            cout << "not present ";
        }
        else
        {
            cout << resultSmallest << " ";
        }

        if (resultLargest == INT_MAX)
        {
            cout << "not present" << endl;
        }
        else
        {
            cout << resultLargest << endl;
        }
    }

    return 0;
}
