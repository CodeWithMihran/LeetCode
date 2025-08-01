// Questions : 
//                                                        MEDIUM
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.
 

// Follow up: Could you come up with a one-pass algorithm using only constant extra space?

// Solution:
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int x=0, y=0, z=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                x++;
            }
            else if(nums[i] == 1){
                y++;
            }
            else if(nums[i] == 2){
                z++;
            }
        }
        int index = 0;
        for(int i=0; i<x; i++){
            nums[index++] = 0;
        }
        for(int i=0; i<y; i++){
            nums[index++] = 1; 
        }
        for(int i=0; i<z; i++){
            nums[index++] = 2;
        }
    }
};
