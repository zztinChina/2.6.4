#include <stdio.h>  

int main() {
    int n = 1; // 假设用户想要进行计算，您可以从1开始，然后通过输入0来退出  
    do {
        int year, month, day;
        int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int i, ret = 0;

        printf("输入1开始计算，输入0退出程序：");
        scanf_s("%d", &n);
        if (n == 0) break; // 如果用户输入0，则退出循环  

        printf("请输入年份、月份和日期（用空格隔开）：");
        scanf_s("%d %d %d", &year, &month, &day);

        if (month > 12 || month <= 0) {
            printf("您需要再看看日历，以确保您输入的月份正确。\n");
            continue; // 如果月份无效，跳过此次循环的剩余部分  
        }

        // 检查是否为闰年，并调整二月的天数  
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            arr[1] = 29;
        }

        if (day < 1 || day > arr[month - 1]) {
            printf("您需要再看看日历，以确保您输入的日期正确。\n");
            continue; // 如果日期无效，跳过此次循环的剩余部分  
        }

        // 计算这是该年的第几天  
        for (i = 0; i < month - 1; i++) {
            ret += arr[i];
        }
        ret += day;

        // 输出结果  
        printf("您输入的是这一年的第%d天\n", ret);

    } while (n != 0); // 当用户输入0时退出循环  

    return 0;
}