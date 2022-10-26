class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        mpp = {0:-1}
        sum = 0
        for i in range(0, len(nums)):
            sum+= nums[i]
            sum%=k
            
            if sum not in mpp:
                mpp[sum]=i
            elif i -mpp[sum]>1:
                return True
            
        return False