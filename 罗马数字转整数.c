//原始代码
int romanToInt(char* s) {
    int RomaNumber(char c);
    enum Roma {I, V, X, L, C, D, M}; // 枚举类型，但在实际代码中未使用
    int i = 1, n = 1;
    int Stack[15]; // 使用数组模拟栈
    Stack[0] = RomaNumber(s[0]); // 将第一个罗马数字字符转换为整数并存入栈
    int sum = 0;

    while (s[i] != '\0') { // 遍历整个字符串
        if (Stack[n - 1] >= RomaNumber(s[i])) {
            // 如果栈顶元素大于或等于当前字符表示的值，则将该值入栈
            Stack[n++] = RomaNumber(s[i++]);
        } else {
            // 如果栈顶元素小于当前字符表示的值，则从栈顶元素中减去该值
            Stack[n - 1] = RomaNumber(s[i++]) - Stack[n - 1];
        }
    }

    for (int j = 0; j < n; j++)
        sum += Stack[j]; // 计算栈中所有元素的总和
    return sum;
}

int RomaNumber(char c) { // 函数：将罗马数字字符转换为对应的整数值
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}


//改进代码
int romanToInt(char* s) {
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++) { // 遍历字符串中的每个字符
        int val = RomaNumber(s[i]); // 获取当前罗马数字字符的整数值
        // 检查下一个字符是否存在且代表的数值是否大于当前字符的数值
        if (s[i + 1] && val < RomaNumber(s[i + 1])) {
            sum -= val; // 如果是特殊情况（如 IV、IX），则减去当前值
        } else {
            sum += val; // 否则，加上当前值
        }
    }
    return sum; // 返回最终的总和
}

int RomaNumber(char c) { // 函数：将罗马数字字符转换为对应的整数值
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}
/*采用的算法
这个算法基于贪心算法的原则。它从头开始遍历罗马数字，每次取一个字符，并根据其右侧字符的值决定是加还是减这个字符的值。这种方法确保了每一步都是局部最优解，最终得到全局最优解。*/