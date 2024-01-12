// 函数用于右旋转数组
void rotate(int* nums, int numsSize, int k) {
    // 检查边界条件，若数组大小为0、旋转次数为0、数组大小为1、旋转次数等于数组大小，则不进行操作
    if (numsSize == 0 || k == 0 || numsSize == 1 || numsSize == k) return; // 改进：增加了对 numsSize == 0 的检查

    // 计算实际的旋转次数（考虑超过数组长度的情况）
    k = k % numsSize;

    // 反转数组的前半部分，直到 "numsSize - k - 1" 的位置
    reverse(nums, 0, numsSize - k - 1);
    // 反转数组的后半部分，从 "numsSize - k" 到数组末尾
    reverse(nums, numsSize - k, numsSize - 1);
    // 反转整个数组
    reverse(nums, 0, numsSize - 1);
}

// 辅助函数，用于反转数组中从 front 到 rear 的部分
void reverse(int* nums, int front, int rear) {
    // 使用双指针方法进行反转
    for (int i = 0; i <= (rear - front) / 2; i++) {
        // 交换 front + i 和 rear - i 的元素
        int temp = nums[front + i];
        nums[front + i] = nums[rear - i];
        nums[rear - i] = temp;
    }
}
