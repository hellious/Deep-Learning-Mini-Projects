
"""
question : Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

"""


class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #sol : create two sets one with numbers and other with numbers + k and find which is common between two sets 
        nums1 = set(nums)
        nums2 = set([num+k for num in nums])
        if k>0:
            return len(nums1 & nums2)
        elif k==0:
            return len(set([x for x in nums if nums.count(x)>1]))
        else:
            return 0
        