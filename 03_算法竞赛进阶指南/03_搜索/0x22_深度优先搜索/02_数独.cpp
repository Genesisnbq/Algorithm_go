/*
 * Project: 0x22_深度优先搜索
 * File Created:Wednesday, January 27th 2021, 8:01:50 pm
 * Author: Bug-Free
 * Problem: AcWing 166. 数独
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 9;

// 0- 511
// ones 快速求出一个状态有多少个1
// map快速求出 log_2 ^x  的值   log_2 ^ 8 = 3   map[8] = 3;
int ones[1 << N], map[1 << N];
int row[N], col[N], cell[3][3];
char str[100];

inline int lowbit(int x) {
    return x & -x;
}

void init() {
    for (int i = 0; i < N; i++) {
        row[i] = col[i] = (1 << N) - 1;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cell[i][j] = (1 << N) - 1;
        }
    }
}

// 求可选方案的交集
inline int get(int x, int y) {
    return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt) {
    if (!cnt) {
        return true;
    }

    // 找出可选方案最少的空格
    int minv = 10;
    int x, y;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (str[i * 9 + j] == '.') {
                int t = ones[get(i, j)];
                if (t < minv) {
                    minv = t;
                    x = i, y = j;
                }
            }
        }
    }

    for (int i = get(x, y); i; i -= lowbit(i)) {
        int t = map[lowbit(i)];

        //修改状态
        row[x] -= 1 << t;
        col[y] -= 1 << t;
        cell[x / 3][y / 3] -= 1 << t;
        str[x * 9 + y] = '1' + t;

        if (dfs(cnt - 1)) {
            return true;
        }

        //恢复现场
        row[x] += 1 << t;
        col[y] += 1 << t;
        cell[x / 3][y / 3] += 1 << t;
        str[x * 9 + y] = '.';
    }

    return false;
}

int main() {
    for (int i = 0; i < N; i++) {
        map[1 << i] = i;
    }
    for (int i = 0; i < 1 << N; i++) {
        int s = 0;
        for (int j = i; j; j -= lowbit(j)) {
            s++;
        }
        ones[i] = s;  // i的二进制表示中有s个1
    }

    while (cin >> str, str[0] != 'e') {
        init();

        int cnt = 0;
        for (int i = 0, k = 0; i < N; i++) {
            for (int j = 0; j < N; j++, k++) {
                if (str[k] != '.') {
                    int t = str[k] - '1';
                    row[i] -= 1 << t;
                    col[j] -= 1 << t;
                    cell[i / 3][j / 3] -= 1 << t;
                } else {
                    cnt++;
                }
            }
        }
        dfs(cnt);
        cout << str << endl;
    }
    return 0;
}
