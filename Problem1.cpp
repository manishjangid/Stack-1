/* Problem Statement:

VERIFIED ON LEETCODE PLATFORM 
503. Next Greater Element II
Medium

Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:

Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.

Note: The length of given array won't exceed 10000. 

 * Solution 1: using Inorder traversal
   Time Complexity : O(n)
 * Space complexity :O(n)
 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int length = nums.size(); /* length of array*/
        int iter_length = 2 * length; // make it double of nums length as we will iterate once more for circular case 
        int idx, circ_idx;
        /* Store result array elements */
        vector<int> result(length, -1);
        
        if (0 == length) {
            return result;
        }
        /* Stack will store indexes of elements so that we can match it. Keep storing elements in stack. For processing if element in array is greater than the top elment in stack ,pop the index from stack and update the next higher element for it at result idx */
        stack<int> st;
        
        for (idx = 0; idx < iter_length; idx++) {
            circ_idx = idx % length; // for circular array 
            while (!st.empty() && nums[circ_idx] > nums[st.top()]) {
                result[st.top()] = nums[circ_idx];
                st.pop();
            }
            /* Can only push elements in stack only once */
            if (idx < length)
                st.push(idx);
        }
        return result;
    }
};/* Execute on leetcode platform */


