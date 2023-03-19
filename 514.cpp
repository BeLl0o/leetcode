#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<char, vector<int> > charToIndex;
vector<vector<int> > memo;
int findRotatedSteps(string ring, string key){
    int m = ring.size();
    int n = key.size();
    //memo存放的元素也是指针在ring[i]时输入key[j]所需要的元素
    memo = vector<vector<int> >(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        charToIndex[ring[i]].push_back(i);
    }
}
//dp是圆盘指针在ring[i]时输入key[j]所需要的最少操作数
int dp(string ring, int i, string key, int j){
    if(j == key.size()){
        return 0;
    }
    if(memo[i][j] != 0){
        return memo[i][j];
    }
    int m = ring.size();
    int res = INT_MAX;
    //ring中可能有重复字符，这些重复字符的索引并不相同，所以需要用for循环遍历同一字符的不同索引
    for(int k : charToIndex[key[j]]){
        //abs是绝对值函数
        int delta = abs(k - i);
        delta = min(delta, m - delta);
        int sub = dp(ring, k, key, j + 1);
        //1代表按动一次按钮
        res = min(res, 1 + delta);
    }
    memo[i][j] = res;
    return res;
}
int main()
{
    vector<vector<int> > memo;
    memo[0].push_back(0);
    cout << memo[0][0] << endl;
    return 0;
}