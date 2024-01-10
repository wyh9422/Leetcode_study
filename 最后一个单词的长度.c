int lengthOfLastWord(char* s) {
    int length = 0; // 用于计算最后一个单词的长度

    // 从字符串末尾开始遍历
    for (int i = strlen(s) - 1; i >= 0; i--) {
        // 如果遇到非空格字符，则开始计数
        if (s[i] != ' ') {
            length++;
        // 如果已经在计数（即找到了单词的末尾）且遇到空格，则结束循环
        } else if (length > 0) {
            break;
        }
    }

    return length;
}

在这个改进版本中，我用一个单独的循环来处理整个字符串。这个循环首先跳过尾部的空格，然后计算最后一个单词的长度，直到遇到另一个空格或字符串开始。
