// T2 分糖
// 老师让小美从一堆b个编号分别为1, 2, ..., n的糖果中选择任意多个糖果作为奖励，
// 但为了防止小美一次吃太多糖果有害身体健康，老师设定了一个限制：如果选择了编号为i的糖果，
// 那么就不能选择编号为i-2, i-1, i+1, i+2的糖果了。在小美看来，每个糖果都有一个对应的美味值，
// 小美想让她选出的糖果的美味值之和最大。
// 输入描述
// 第一行一个整数n，表示糖果数量。
// 第二行n个数a1, a2, ..., an，其中ai 表示编号为i的糖果的美味值。
// 1<n<=50000, 1<aj<=10000
// 输出描述
// 美味值最大值
// 输入
// 7
// 3 1 2 7 10 2 4
// 输出
// 14 （选择编号 1 4 7 的糖果）

#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;
//max = 第i个值 + max(第i + 2个到最后一个数字这个范围内的最大美味值)
//怎么分析时间复杂度？
//寻找美味值应该是一个递归函数
//findMax：在索引start和索引end范围内最大的美味值
int max(int a, int b, int c){
    if(a >= b){
        if(a >= c){
            return a;
        }else{
            return c;
        }
    }else{
        if(b >= c){
            return b;
        }else{
            return c;
        }
    }
}
vector<int> memo;
int findMax(int start, vector<int>& val){
    if(memo[start] != -1){
        return memo[start];
    }
    //先讨论base case
    int n = val.size() - 1;
    if(start > n){
        return 0;
    }
    if(n - start == 0){
        memo[start] = val[start];
    }else if(n - start == 1){
        memo[start] = (val[start] > val[n]) ? val[start] : val[n];
    }else if(n - start == 2){
        memo[start] = max(val[start], val[start + 1], val[start + 2]);
    }else{
        int x1 = val[start] + findMax(start + 3, val);
        int x2 = val[start + 1] + findMax(start + 4, val); 
        int x3 = val[start + 2] + findMax(start + 5, val); 
        memo[start] = max(x1, x2, x3);
    }
    return memo[start];

}

int main(){
    //input 
    int num = 10000;
    //scanf("%d", &num);
    memo.resize(num + 1, -1);
    vector<int> val;
    for(int i = 0; i < num; i++){
        int tmp = rand() % 20000;

        //scanf("%d", &tmp);
        
        val.push_back(tmp);
    }
    int res = findMax(0, val);
    printf("%d", res);

}