#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void quickSort(int low, int high, vector<int> &nums)
    {
        if (low >= high)
            return;
        // choose key
        int key = nums[low];
        // choose workers
        int left = low, right = high;
        while (left < right)
        {
            while (left < right && nums[right] > key)
                right--;
            while (left < right && nums[left] <= key)
                left++;

            if (left < right)
                swap(nums[left], nums[right]);
        }
        // put key at its final pos: right
        swap(nums[low], nums[right]);
        quickSort(low, right, nums);
        quickSort(right + 1, high, nums);
    }
};

void printArr(vector<int> &nums)
{
    for (int x : nums)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> nums = {2, 5, 4, 3};
    printArr(nums);
    Solution s;
    s.quickSort(0, nums.size(), nums);
    printArr(nums);
    return 0;
}
