#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // Check if the mid element is the target
            if (nums[mid] == target) return mid;

            // Decide where to search  left or right sorted array

            // the left half must be sorted
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1; // Search in the left half
                } else {
                    l = mid + 1; // Search in the right half
                }
            }
            // Otherwise, the right half must be sorted
            else {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1; // Search in the right half
                } else {
                    r = mid - 1; // Search in the left half
                }
            }
        }

        return -1; // Target not found
    }
};
