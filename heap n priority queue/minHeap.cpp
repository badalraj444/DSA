#include <iostream>
#include <vector>
using namespace std;
void printArr(vector<int> &nums)
{
    for (int a : nums)
    {
        cout << a << " ";
    }
    cout << endl;
}

void heapify(vector<int> &nums, int i)
{
    int temp = nums[i];
    while (i > 0 && nums[(i - 1) / 2] < temp)
    {
        nums[i] = nums[i / 2];
        i = (i - 1) / 2;
    }
    nums[i] = temp;
}
void initialiseHeap(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        heapify(nums, i);
    }
}
void insert(vector<int> &heap, int x)
{
    heap.push_back(x);
    heapify(heap, heap.size() - 1);
}

int extractMax(vector<int> &nums)
{
    if (nums.empty())
        return -1;
    int x = nums[0];                 // store root
    nums[0] = nums[nums.size() - 1]; // root -> last
    nums.pop_back();
    int i = 0, j = i * 2 + 1;
    while (j < nums.size())
    {
        if (nums[j + 1] > nums[j])
            j++; // if right is bigger
        if (nums[j] > nums[i])
        {
            swap(nums[i], nums[j]);
            i = j;
            j = i * 2 + 1;
        }
        else
            break;
    }
    return x;
}

int main()
{

    vector<int> nums = {6, 2, 5, 23, 40, 8, 4, 3};
    cout << "before heapifying" << endl;
    printArr(nums);
    initialiseHeap(nums);
    cout << "after heapifying" << endl;
    printArr(nums);
    int x = 51;
    insert(nums, 51);
    cout << "after inserting " << x << endl;
    printArr(nums);
    extractMax(nums);
    cout << "after deleting one item" << endl;
    printArr(nums);
    return 0;
}