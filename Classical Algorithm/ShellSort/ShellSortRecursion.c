#include<stdio.h>

// Log 方法
void printSort(int data[], int n, int currentIndex) {
    
    printf("\n");
    printf("排序后%d:", currentIndex);
    for (int i = 0; i < n; ++ i) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

// 引自 StraightInsertionSort.c 直接插入排序方式三：
/**
 针对特定子序列进行直接插入排序，比较每一趟排序的数字并排排序
 
 @param data 待排序的序列
 @param tmp 寻找插入位置的当前元素
 @param n 序列长度
 @param delta 本趟排序增量
 */
int StraightInsertionSortInnerRecursionCompare(int data[], int tmp, int n, int delta) {
    if (n < 0) return n + delta;
//    printf("%d--%d--%d\n", n, data[n], tmp);
    if (tmp < data[n]) {
        data[n + delta] = data[n];
    }else {
        return n + delta;
    }
    return StraightInsertionSortInnerRecursionCompare(data, tmp, n - delta, delta);
}
// 得出索引值
int StraightInsertionSortInnerRecursionIndex(int data[], int n, int delta) {
    return StraightInsertionSortInnerRecursionCompare(data, data[n], n - delta, delta);
}
// 2.递归增量分割的所有子序列，针对排序递归！
void StraightInsertionSortInnerRecursion(int data[], int n, int currentIndex, int delta)  {
    if (currentIndex >= n) return;
    int tmp =  data[currentIndex];
    data[StraightInsertionSortInnerRecursionIndex(data, currentIndex, delta)] = tmp;
    StraightInsertionSortInnerRecursion(data, n, currentIndex + delta, delta);
}

/**
 递归增量序列，希尔排序，注意delta 为素数，
 
 @param data 待排序的序列
 @param n 序列长度
 @param currentIndex 子序列排序起点
 @param delta 本趟排序增量
 */
void shellSort(int data[], int n, int currentIndex, int delta) {
    if (delta % 2 == 0) {
        printf("Delta error!");
        return;
    }
//    printf("shellSort if:%d delta:%d\n",currentIndex + delta, delta);
    if (delta < 1) return;
    
    if (currentIndex + delta > n) {
        printSort(data, n, currentIndex);
        shellSort(data, n, 0, delta - 2);
    }else {
        StraightInsertionSortInnerRecursion(data, n, currentIndex + delta, delta);
//        printf("shellSort:%d",currentIndex + delta + 1);
        
        printSort(data, n, currentIndex);
        
        if (delta > 1) {
            shellSort(data, n, currentIndex + 1, delta);
        }
    }
}

int main() {
    int data[] = {13, 12, 2, 22, 16, 11, 10, 1, 21, 15};
    int n = 10;
    shellSort(data, n, 0, 5);
    return 0;
}
