char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    // 分配内存
    char *prefix = malloc(strlen(strs[0]) + 1);
    if (!prefix) return ""; // 检查内存分配是否成功

    int i = 0;
    while (strs[0][i] != '\0') {
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i] || strs[j][i] == '\0') {
                prefix[i] = '\0';
                return prefix;
            }
        }
        prefix[i] = strs[0][i];
        i++;
    }
    prefix[i] = '\0'; // 确保以空字符结束
    return prefix;
}