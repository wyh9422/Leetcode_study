int removeDuplicates(int* nums, int numsSize) {
    int writeIndex = 0; // 初始化写指针，用于记录非重复元素的位置
    int readIndex = 0;  // 初始化读指针，用于遍历数组

    while (readIndex < numsSize) {
        // 如果当前读指针指向的元素与写指针指向的元素相同，则移动读指针
        if (nums[writeIndex] == nums[readIndex]) {
            readIndex++;
        } else {
            // 发现新的非重复元素，移动写指针并更新其值
            nums[++writeIndex] = nums[readIndex];
        }
    }
    // 返回唯一元素的数量，写指针位置加1（因为索引从0开始）
    return writeIndex + 1;
}
