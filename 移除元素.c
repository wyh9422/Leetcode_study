int removeElement(int* nums, int numsSize, int val) {
    int m=0; // 初始化写索引，用于记录下一个不等于val的元素应该放置的位置
    int n=0; // 初始化读索引，用于遍历数组中的每个元素

    // 遍历数组中的每个元素
    while(n < numsSize){
        // 如果当前元素不等于val
        if(nums[n] != val){
            // 将当前元素复制到写索引指向的位置
            nums[m] = nums[n];
            // 移动写索引到下一个位置
            m++;
        }
        // 无论当前元素是否等于val，都移动读索引到下一个位置
        n++;
    }

    // 计算并返回新的数组长度，即所有不等于val的元素的数量
    return m;
}

