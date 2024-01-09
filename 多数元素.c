int majorityElement(int* nums, int numsSize) {
    int n = 1;       // 初始化遍历索引
    int m = nums[0]; // 初始化候选多数元素为数组的第一个元素
    int num = 0;     // 初始化候选元素的计数器

    // 遍历数组
    while (n < numsSize) {
        // 情况1: 当前元素与候选多数元素不同且计数器为0
        // 将当前元素设置为新的候选多数元素
        if (nums[n] != m && num == 0) {
            m = nums[n];
        }
        // 情况2: 当前元素与候选多数元素不同且计数器大于0
        // 减少候选元素的计数
        else if (nums[n] != m && num > 0) {
            num--;
        }
        // 情况3: 当前元素与候选多数元素相同
        // 增加候选元素的计数
        else {
            num++;
        }
        // 移动索引到下一个元素
        n++;
    }
    // 返回多数元素
    return m;
}

//改进
int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0], count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }

    return candidate;
}
