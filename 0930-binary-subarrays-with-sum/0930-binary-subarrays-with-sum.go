func numSubarraysWithSum(nums []int, goal int) int {
    n := len(nums)
    i, j := 0, 0
    ans := 0
    windowSum := 0
    countZeroes := 0
    
    for j < n {
        windowSum += nums[j]
        
        for i < j && (nums[i] == 0 || windowSum > goal) {
            if nums[i] == 0 {
                countZeroes++
            } else {
                countZeroes = 0
            }
            
            windowSum -= nums[i]
            i++
        }
        
        if windowSum == goal {
            ans += 1 + countZeroes
        }
        
        j++
    }
    
    return ans
}
