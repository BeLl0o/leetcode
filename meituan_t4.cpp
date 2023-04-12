#include <stdio.h>
#include <vector>

using namespace std;
int f(int index, int cheat, vector<int>& val){
    int n = val.size() - 1;
    if(index < 0){
        return 0;
    }
    if(index == 0){
        return val[0];
    }
    if(cheat < 0){
        return 0;
    }else if(cheat == 0){
        return val[index] + f(index - 2, cheat, val);
    }else if(cheat > 0){
        return max(val[index] + f(index - 2, cheat, val), val[index] + f(index - 1, cheat - 1, val));
    }
    return 0;
}
int main() {
    int n, cheat;
    scanf("%d %d", &n, &cheat);
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    int res = f(n - 1, cheat, val);
    printf("%d\n", res);
    return 0;
}