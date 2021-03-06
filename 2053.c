/*暴力模拟操作的话会严重超时，故需要观察发现规律。
由题意可知，灯泡数量为1...i...n,且每次只操作编号为i的倍数的灯泡，操作过的灯泡不再改变，
所以编号i之后的灯泡一定会被操作多次，关键是求出一共被操作了多少次。
举例编号10的灯泡，当i为 1，2，5，10时会被操作，观察发现（1，10）（2，5）是10的约数，
   编号25的灯泡，当i为1，5，25时会被操作，观察发现（1，25）（5）的约数，且25是平方数
由此可以得出结论，当n的约数为偶数时，操作结果为0；当n的约束为奇数且n为平方数时，操作结果为1；
故可以由此得出答案
*/
#include<stdio.h>
#include<math.h>

int main(){
    int n;
    int i,j;

    while(scanf("%d",&n)!=EOF) {
        if(sqrt(n*1.0) == (int)sqrt(n*1.0))
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}
