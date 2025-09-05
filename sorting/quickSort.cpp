#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void quickSort(int low, int high, vector<int> &nums)
    {
        if (low >= high)
            return; // base case

        int key = nums[low];
        int i = low, j = high;

        while (i < j)
        {
            // ! with use of i<j in inner while loops, i dont need sentinel(infinite value in end) in array to guard
            while (i < j && nums[j] > key)
                j--; // move j left stop when less than equal to ( loose) j - lose
            while (i < j && nums[i] <= key)
                i++; // move i right stop when greater than key (strict)
            if (i < j)
                swap(nums[i], nums[j]); // critical if(i<j) dont miss
        }

        // Place pivot at its correct position
        swap(nums[low], nums[j]);

        // Recurse for left and right parts
        quickSort(low, j, nums);
        quickSort(j + 1, high, nums);
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
