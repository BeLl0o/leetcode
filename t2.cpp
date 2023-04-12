#include <stdio.h>
#include <vector>


int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> val(n), f(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    f[0] = val[0];
    f[1] = std::max(val[0], val[1]);
    f[2] = std::max(val[0], std::max(val[1], val[2]));
    for (int i = 3; i < n; i++) {
        f[i] = std::max(val[i] + f[i - 3], f[i - 1]);
    }
    printf("%d\n", f[n - 1]);
    return 0;
}