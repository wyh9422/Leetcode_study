int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;  // 空数组的情况

    int minPrice = prices[0];       // 初始化最小价格为第一天的价格
    int maxProfit = 0;              // 初始化最大利润为0

    // 遍历价格数组
    for (int i = 1; i < pricesSize; i++) {
        // 如果当前价格比之前记录的最小价格低，更新最小价格
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            // 否则，计算在当前价格卖出的利润，并更新最大利润
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
    }

    return maxProfit;  // 返回计算得到的最大利润
}

// 辅助函数：返回两个整数中较大的一个
int max(int a, int b) {
    return (a > b) ? a : b;
}
