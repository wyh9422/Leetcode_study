//
//  main.c
//  test
//
//  Created by 万宇航 on 2024/1/8.
//

#include <stdio.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int num = m + n - 1; // 合并后nums1数组中的元素的序号，初始化为最后一个位置
    while (n > 0)
    {
        if (m > 0 && nums1[m - 1] >= nums2[n - 1])
        {
            // 如果nums1中的元素大于等于nums2中的元素，将nums1中的元素复制到合并后的位置
            nums1[num--] = nums1[m - 1];
            m--;
        }
        else
        {
            // 如果nums2中的元素大于nums1中的元素或者nums1中的元素已经用完，将nums2中的元素复制到合并后的位置
            nums1[num--] = nums2[n - 1];
            n--;
        }
    }
}

// 问题说明：
// 原始代码中的问题是，它从nums1和nums2的前面开始合并元素，可能导致元素的覆盖和错误的结果。
// 正确的方法是从nums1和nums2的末尾开始合并，以确保不会覆盖已经合并过的元素。


int main(void)
{
    int nums1[6];
    int nums2[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &nums1[i]);
    }
    printf("输入完第一个数组\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &nums2[i]);
    }
    printf("输入完第二个数组\n");
    merge(nums1, 6, 3, nums2, 3, 3);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", nums1[i]);
    }
    return 0;
}
