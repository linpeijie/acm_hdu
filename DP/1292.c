/* 算法设计思想：原题型为求n个元素的集合{1，2，3... N}，可以划分为若干个非空子集，也是求将n个数放入不同空盒子的算法，
               既是动态规划，也是组合数学里面的Bell数
动态规划思路： 若用f[n][m]表示n个元数的集合中分为m个子集的分法数量，则：
1.对于只含有1个数的集合f[1][m]，m={1} 可知只有一种分法；
2.对于含有2个数的集合f[2][m],m={1,2} 可知有 f[2][2]={1},{2}，f[2][1]={1，2} 两种分法；
3.对于含有3个数的集合f[3][m]，m=[1,2,3] 可知f[3][1]=1,f[3][2]=3,f[3][3]=1; 
  对f[3][2]来讲，可以在f[2][1]中加入新子集{{1，2}，{3}}，也可以在f[2][2]中的每个子集里加入元素3变成 {{1，3},2，{1,{2，3}}，同时也只有这两种方法
4.假设对于k<n，有f[n][k] = f[n-1][k-1] + k*f[n-1][k];
5.由数学归纳法可知，当k = n 时上式也成立。
6.所以由状态转移方程就可以算出答案

*/
#include<stdio.h>

int main(){
    int C,n,i,j;
    long long f[25][25],sum;

    for(i = 1; i < 25; i++){
        f[i][1] = 1;
        for(j = 2; j < 25; j++)
            if(i == j)
                f[i][j] = 1;
    }

    for(i = 3; i < 25; i++)
        for(j = 2; j < i; j++)
            f[i][j] = f[i-1][j-1] + j*f[i-1][j];
    
    scanf("%d",&C);

    while(C--){
        sum = 0;
        scanf("%d",&n);

        for(i = 1; i <= n; i++)
            sum += f[n][i];

        printf("%lld\n",sum);
    }
    return 0;
}
