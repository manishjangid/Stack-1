/* Problem Statement:

VERIFIED ON LEETCODE PLATFORM 
739. Daily Temperatures
Medium

Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100]. 

 * Solution 1: 
   Time Complexity : O(n)
 * Space complexity :O(n)
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int length = T.size(); /* length of array*/
        int idx;
        /* Store result array elements */
        vector<int> result(length, 0);
        
        /* Stack will store indexes of elements so that we can match it. Keep storing elements in stack. For processing if element in temp array is greater than the value at top element in stack ,pop the index from stack and update the warmer temperature for it at result idx */
        stack<int> st;
        
        for (idx = 0; idx < length; idx++) {

            while (!st.empty() && T[idx] > T[st.top()]) {
                result[st.top()] = idx - st.top();
                st.pop();
            }
            st.push(idx);
        }
        return result;
    }
};/* Execute on leetcode platform */


