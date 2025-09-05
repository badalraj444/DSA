// wheel of swaps: store next, replace with prev, prev = next(using temp)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // rotating n times means k = 0
        k = k%n;
        //if k = 0, no rotation
        if(k == 0) return;
        int start = 0;
        int done = 0, i = start;
        int prev = nums[start];

        while(done != n){
            //if i == start again. it means it cycled back
            if(i==start && done != 0 && done != n){
                start++;
                prev = nums[start];
                i++;
            }
            i = (i+k)%n;
            int temp = nums[i];
            nums[i] = prev;
            prev = temp;
            //one done at a time
            done++;
        }      
    }
};
//idea: rotation can be seen as left-right switching
// store smaller side, switch other half, store back 
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         // rotating n times means k = 0
//         k = k%n;
//         //if k = 0, no rotation
//         if(k == 0) return;
        
//         queue<int>q;
//         // store last k elements in queue
//         for(int i = n-k; i<n; i++){
//            q.push(nums[i]);
//         }
//         //shift 1st  n-k elements right -->
//         for(int i = n-k-1; i>=0; i--){
//             nums[i+k] = nums[i];
//         }
//         //restore last section to beginning
//         int i =0;
//         while(!q.empty()){
//             nums[i++] = q.front();
//             q.pop();
//         }
//     }
// };
// //idea: rotation can be seen as left-right switching
// // store smaller side, switch other half, store back 