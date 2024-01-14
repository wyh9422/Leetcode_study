int jump(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;

    int jumps = 0; // 记录跳跃次数
    int currentReach = 0; // 当前能到达的最远位置
    int nextReach = 0; // 下一跳能到达的最远位置

    for (int i = 0; i < numsSize - 1; ++i) {
        nextReach = max(nextReach, i + nums[i]);

        // 当到达当前能到达的最远位置时，跳跃并更新
        if (i == currentReach) {
            jumps++;
            currentReach = nextReach;

            // 如果当前已经能到达数组末尾，提前结束
            if (currentReach >= numsSize - 1) break;
        }
    }
    return jumps;
}
//基于贪心算法，复杂度为O(n)
这种方法的关键在于，每次在到达当前最远位置之前，就已经知道了下一步能跳到的最远位置。这样，一旦到达当前最远位置，就可以直接进行下一次跳跃，并且跳跃次数增加。通过这种方式，代码的效率得到了提高。同时，这种方法保持了贪心算法的特点，即每次都尽可能向前跳得更远。