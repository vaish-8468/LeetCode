import (
    "math"
       )
func firstMissingPositive(nums []int) int {
    var n int = len(nums)
    var contains1 bool = false

    for i := 0; i < n; i++ {
            // Check whether 1 is in the original array
            if (nums[i] == 1) {
                contains1 = true
            }
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1 
            }      
        }

    if !contains1{
        return 1 
    }

        // Mark whether integers 1 to n are in nums
        // Use index as a hash key and negative sign as a presence detector.
    for i := 0; i < n; i++ {
            
        var val int = int(math.Abs(float64(nums[i])));
        var idx int = val-1;
            
        if(nums[idx] < 0) {continue}
            nums[idx] *= -1;
            
        }

        // First positive in nums is smallest missing positive integer
    for i := 0; i < n; i++ {
        if (nums[i] > 0){
                return i+1;
        }
    }
    return n + 1;
}