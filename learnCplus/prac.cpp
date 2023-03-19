#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
};
using II = vector<pair <int, int> >;
II nums_, temp_;
vector<int> kount;
void merge(II& num_, int lo, int mid, int hi){
    for(int i = lo; i <= hi; i++){
        temp_[i] = nums_[i];
    }
    int i = lo, j = mid + 1;
    int right_bin = 0;
    for(int k = lo; k <= hi; k++){
        if(i == mid + 1){
            nums_[k] = temp_[j++];
            right_bin++;
        }else if(j == hi + 1){
            nums_[k] = temp_[i];
            kount[temp_[i].first] += right_bin;
            i++;
        }else if(temp_[i].second > temp_[j].second ){
            nums_[k] = temp_[j++];
            right_bin++;
            
        }else{
            nums_[k] = temp_[i];
            kount[temp_[i].first] += right_bin;
            i++;
        }
    }
}
void sort1(II& num_, int lo, int hi){
    if(lo == hi){
        return;
    }
    int mid = (lo + hi) / 2;
    sort1(nums_, lo, mid);
    sort1(nums_, mid + 1, hi);
    merge(nums_, lo, mid, hi);
}

void sort(II& nums_){
    kount.resize(nums_.size());
    temp_.resize(nums_.size());
    sort1(nums_, 0, nums_.size() - 1);
}
    
    

vector<int> countSmaller(vector<int>& nums) {
    nums_.resize(nums.size());
    for(int i = 0; i < nums.size(); i++){
        nums_[i] = (make_pair(i, nums[i]));
    }
    
    sort(nums_);
    return kount;
}
vector<vector <int> > buildGraph(int numCourses, vector<vector <int> > prerequisites){
    vector<vector <int> > graph;
    graph.resize(numCourses);
    for(vector <int> edge : prerequisites){
        int from = edge[1], to = edge[0];
        graph[from].push_back(to);
    }
    return graph;
}
vector <bool> visited;
void traverse(vector<vector <int> > graph, int s){
    if(visited[s]) return;
    visited[s] = true;
    for(int t : graph[s]){
        traverse(graph, t);
    }
}
bool canFinish(int numCourses, vector<vector <int> > prerequisites){

}
int main() {
    vector <int> nums;
    nums.push_back(-1);
    nums.push_back(-1);
    
    vector<int> res = countSmaller(nums);
    
    return 0;
        
    
}
//M N 为迷宫的长和宽
#define M = 100
#define N = 50
vector< vector<char> > maze;
maze.resize(M);
for(int i = 0; i < M; i++){
    maze[i].resize(N);
}

# define Wall = '+'
# define glass = '.'
# define oneRock = '#'
# define twoRock = '$'

int findExit(vector< vector<char> >& maze, vector<int>& exit) {
    int m = maze.size();
    int n = maze[0].size();
    queue < pair<int,int> > que;
    que.push(make_pair(exit[0], exit[1]));
    maze[exit[0]][exit[1]] = '+';
    int res = 10000;
    int level = 1;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy ={0, -1, 0, 1};
    //BFS求解
    while(que.size() > 0)
    {
        int size = que.size();
        while(size > 0)
        {
            pair<int,int> temp = que.front();
            que.pop();

            for(int i = 0;i < dx.size(); i++)
            {
                int x = temp.first + dx[i];
                int y = temp.second + dy[i];
                if(x < 0||y < 0||x >= m||y >= n||maze[x][y] == '+') {
                    continue;
                }    
                maze[x][y] = '+';
                if(x == 0||y == 0||x == m - 1||y == n - 1) 
                {
                    return level;
                }
                que.push(make_pair(x,y));
            }
            size--;
        }
        level++;
    }
    //有结果就返回res，没有结果返回-1
    return res == 10000? -1 :res;
}

//定义插入操作：把索引i-j的（j - i + 1）个元素插入索引为k的位置
//建立vector记录每次操作的i, j 和插入的位置
//对上述操作求逆获取第k个元素的位置
int findIndex(vector<int> num){

}
vector<vector<int>> gift = {{35, 40}, {30, 30}, {20, 20}};


for i in range(1, N+1):
    for j in range(gift[0][i], M+1):
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-gift[1][i]]+Value[i])

max_value = dp[N][M]


for(int i; i < N + 1; i++){
    for(int j = 1){

    }
}