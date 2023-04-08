// 有n个巧克力，边长分别为a1, a2, ..., an，第n个巧克力的重量为ai^2，有m个询问，每个询问
// 查询qi大小的背包最多能装多少块巧克力
// 输入描述
// 第一行 n, m，表示巧克力数量和询问数量 1<n, m<=50000
// 第二行 a1, a2, ..., an，表示每个巧克力的边长，注意巧克力不能被拆分
// 第三回m个整数 q1, ...qn, qi询问表示如果小美选择一个qi大小的包，最多能装多少巧克力
// 1<=ai<=1e4, 1<=qi<=1e18
// 输入
// 5 5
// 1 2 2 4 5
// 1 3 7 9 15
// 输出
// 1 1 2 3 3

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int chocNum, bagNum;
    scanf("%d %d", &chocNum, &bagNum);
    vector<int> chocLen;
    vector<int> bagSize;
    vector<int> res;
    for(int i = 0; i < chocNum; i++){
        int tmp;
        scanf("%d", &tmp);
        chocLen.push_back(tmp * tmp);
    }
    sort(chocLen.begin(), chocLen.end());
    vector<int> preSum;
    preSum.resize(chocNum);
    preSum[0] = chocLen[0];
    for(int i = 1; i < chocNum; i++){
        preSum[i] = preSum[i - 1] + chocLen[i];
    }
    
    
    for(int i = 0; i < bagNum; i++){
        int tmp;
        scanf("%d", &tmp);
        bagSize.push_back(tmp);
    }
    for(int i = 0; i < bagNum; i++){
        int tmp = 0;
        // for(int j = 0; j < chocNum; j++){
        //     if(bagSize[i] - chocLen[j] * chocLen[j] < 0){
        //         break;
        //     }
        //     bagSize[i] -= chocLen[j] *chocLen[j];
        //     tmp++;
        // }
        //二分查找preSum中与bagSize[i]匹配的索引
        int flg = 1;
        if(preSum[0] > bagSize[i]){
            tmp = 0;
            flg = 0;
        }
        if(preSum[chocNum - 1] <= bagSize[i]){
            tmp = chocNum;
            flg = 0;
        }
        int left = 0, right = chocNum - 1;
        if(flg){
        while(left < right){
            if(preSum[0] > bagSize[i]){
                tmp = 0;
                break;
            }
            if(preSum[chocNum - 1] <= bagSize[i]){
                tmp = chocNum;
                break;
            }
            int mid = (left + right) / 2;
            if(preSum[mid] < bagSize[i]){
                left = mid;
                if(preSum[mid + 1] > bagSize[i]){
                    tmp = mid + 1;
                    break;
                }
            }else if(preSum[mid] > bagSize[i]){
                right = mid;
                if(mid != 0 && preSum[mid - 1] < bagSize[i]){
                    tmp = mid;
                    break;
                }
            }else{
                tmp = mid + 1;
                break;
            }
        }
        }
        
        res.push_back(tmp);
    }
    for(int i = 0; i < bagNum; i++){
        printf("%d ", res[i]);
    }
    return 0;
}