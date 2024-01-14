//我的代码
bool canJump(int* nums, int numsSize) {
    // 如果数组只有一个元素，直接返回true，因为已经在最后一个位置
    if(numsSize == 1) return true;

    // foot表示从当前位置到达最后位置所需的最小步数，初始为1，代表至少需要一步
    int foot = 1; 

    // 从数组倒数第二个元素开始向前遍历
    for(int i = numsSize - 2; i >= 0; i--) {
        // 如果当前元素的值小于所需的最小步数foot
        if(nums[i] < foot) {
            // 说明无法直接跳到已经覆盖的位置，需要增加一步来跳得更远
            foot++;
        } else {
            // 如果当前元素的值大于或等于所需的最小步数foot
            // 说明可以从这个位置跳到至少foot步远的地方，重置foot为1
            // 因为从这个新位置开始，最少需要一步到达下一个可达的位置
            foot = 1;
        }
    }

    // 最后检查数组的第一个元素是否能够跳至少foot步
    // 如果可以，返回true，表示可以到达最后一个位置
    // 否则返回false
    if(nums[0] >= foot) return true;
    else return false;
}

//贪心算法的版本
bool canJump(int* nums, int numsSize) {
    int maxReach = 0; // 初始化最远可达位置为0
    for (int i = 0; i < numsSize; i++) {
        if (i > maxReach) return false; // 当前位置超出最远可达位置
        maxReach = max(maxReach, i + nums[i]); // 更新最远可达位置
        if (maxReach >= numsSize - 1) return true; // 最远可达位置已经超过或达到

