# include <iostream>
#include <vector>

using namespace std;

void mergeArray(vector<int>& nums,int left,int mid,int right);
void mergeSort(vector<int>& nums,int left, int right);

int main(){
    vector<int> nums = {4,2,8,1,9,4,6};
    cout << "before sorting...\n";
    for(int num:nums){
        cout <<num <<" ";
    }
    cout<< "\nafter sorting...\n";
    mergeSort(nums,0,nums.size()-1);
    for(int num:nums){
        cout << num <<" ";
    }
    return 0;
}
void mergeSort(vector<int>& nums,int left, int right){
    //base case
    if(left == right){ 
        return;
    }//general case
    else{
        int mid = left+(right-left)/2;
       mergeSort(nums,left,mid);
       mergeSort(nums,mid+1,right);
       mergeArray(nums,left,mid,right);
    }
}

void mergeArray(vector<int>& nums,int left,int mid,int right){
    vector<int> temp;
    int i = left, j = mid+1; 
    //append when both non-empty
    while(i<=mid && j<=right){
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i++]);
        }else{
            temp.push_back(nums[j++]);
        }
    }
    //append when only one non-empty
    while(i<=mid){
        temp.push_back(nums[i++]);
    }
    while(j<=right){
        temp.push_back(nums[j++]);
    }
    //copy back to original array
    for(int i = 0; i < temp.size(); i++){
        nums[left+i] = temp[i];
    }
}