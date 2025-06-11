//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

//The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> mergedArray(vector<int> nums1, vector<int> nums2) {
        vector<int> arr(nums1);

        for (auto it = nums2.begin(); it != nums2.end(); it++) {
            arr.push_back(*it); // arr becomes nums1 + nums2
        }

        vector<int> sortedMergedArr = {};
        int left = 0, right = nums1.size();

        while (left < nums1.size() && right < arr.size()) {
            if (arr[left] <= arr[right]) {
                sortedMergedArr.push_back(arr[left]);
                left++;
            } else {
                sortedMergedArr.push_back(arr[right]);
                right++;
            }
        }

        while (left < nums1.size()) {
            sortedMergedArr.push_back(arr[left]);
            left++;
        } 
        while (right < arr.size()) {
            sortedMergedArr.push_back(arr[right]);
            right++;
        }

        return sortedMergedArr;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sortedMergedArr = mergedArray(nums1, nums2);
        
        double median;
        if (sortedMergedArr.size()%2 == 0) {
            int half = sortedMergedArr.size()/2;
            median = (sortedMergedArr[half] + sortedMergedArr[half+1])/2;
        } else {
            int half = sortedMergedArr.size()/2;
            median = sortedMergedArr[half];
        }

        return median;
    }
};