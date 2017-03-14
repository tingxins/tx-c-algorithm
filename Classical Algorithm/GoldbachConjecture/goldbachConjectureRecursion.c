#include <stdio.h>

void splitSum(int original, int flag);
void splitSumInner(int original, int current, int flag);

// 判断偶数
int isEven(int original) {
    return (original % 2 == 0);
}
// 针对 for 循环，大部分都可采用递归形式代替！！
// 根据哥德巴赫猜想，current 参数一定为奇数
// 素数递归判断
int isPrimeInner(int original, int current) {
    if (current<=0 || original<=0 || original == 1) return 0;
    
    if (original % 2 == 0) {
        if (original == 2) return 1;
        return 0;
    }
    
    if (current > (original / 2) + 1) return 1;
    
    if (original % current == 0 && current != 1) return 0;
    
    return isPrimeInner(original, current + 2);
}

// 是否为素数
int isPrime(int original) {
    return isPrimeInner(original, 1);
}

// current: 代表分裂初始值
// flag: 代表是否深入遍历，此处用于控制重复遍历的情况，如：original=10 时，second=8 时，两次会都会重复遍历 6/4/2，因此加入flag进行限制，只进行一次深入遍历！！
void splitSumInner(int original, int current, int flag) {
    // 哥德巴赫为大于2的偶数
    if (original <= 2) return;
    // 如果 current 大于 original 的一半，即代表遍历完毕
    if (current >= (original / 2) + 1) return;
    
    // 第一次分裂 original 数值
    int first = current;
    int second = original - current;

    // 递归遍历并分裂 original 数值
    splitSumInner(original, ++ current, flag);
//    splitSumInner(original, current ++); // 换死循环哈 current 只会后加
    
    // 判断能否深入遍历
    if (flag && first > 2 && isEven(first)) {
        // 深入遍历 分裂第一个子偶数
        splitSum(first, 0);
    }
    
    if (flag && second > 2 && isEven(second)) {
        // 深入遍历 分裂第二个子偶数
        splitSum(second, 0);
    }
    
    if (isEven(original) && isPrime(first) && isPrime(second)) {
        printf("\n%d=%d+%d\n",original, first, second);
    }
    
}

// original: 待分裂的原始数值（ps：会自动分裂 小于 original 下的所有数值）
// flag: 1 代表分裂小于 original 下的所有数值；0 代表分裂当前 original 数值
void splitSum(int original, int flag) {
    splitSumInner(original, 1, flag);
}

void goldbachConjecture(int n) {
    splitSum(n, 1);
}

int main() {
    do {
        printf("please enter a number:");
        int number = 0;
        scanf("%d", &number);
        goldbachConjecture(number);
    } while (1);
    return 0;
}
