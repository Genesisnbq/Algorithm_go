/*
 * Project: 11_哈希表
 * File Created:Sunday, January 17th 2021, 2:11:23 pm
 * Author: Bug-Free
 * Problem:AcWing 840. 模拟散列表 拉链法
 */
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 3;  // 取大于1e5的第一个质数，取质数冲突的概率最小 可以百度

//* 开一个槽 h
int h[N], e[N], ne[N], idx;  //邻接表

void insert(int x) {
    // c++中如果是负数 那他取模也是负的 所以 加N 再 %N 就一定是一个正数
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x) {
    //用上面同样的 Hash函数 讲x映射到 从 0-1e5 之间的数
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x) {
            return true;
        }
    }
    return false;
}

int n;

int main() {
    cin >> n;

    memset(h, -1, sizeof h);  //将槽先清空 空指针一般用 -1 来表示

    while (n--) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "I") {
            insert(x);
        } else {
            if (find(x)) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
    return 0;
}
