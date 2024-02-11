#include <bits/stdc++.h>
using namespace std;

int isSafe(vector<vector<int>>& mx, int r, int c,
           vector<vector<bool>>& vsted) {
    return (r >= 0) && (r < mx.size()) && (c >= 0) &&
           (c < mx[0].size()) && (mx[r][c] && !vsted[r][c]);
}

void DFS(vector<vector<int>>& mx, int i, int j,
         vector<vector<bool>>& vsted, int& count) {
    static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    vsted[i][j] = true;
    for (int k = 0; k < 8; ++k) {
        if (isSafe(mx, i + rowNbr[k], j + colNbr[k], vsted)) {
            count++;
            DFS(mx, i + rowNbr[k], j + colNbr[k], vsted, count);
        }
    }
}

int lr(vector<vector<int>>& mx) {
    int k, r;
    k = mx.size();
    r = mx[0].size();
    vector<vector<bool>> vsted(k, vector<bool>(r, false));

    int rs = INT_MIN;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < r; j++) {
            if (mx[i][j] && !vsted[i][j]) {
                int count = 1;
                DFS(mx, i, j, vsted, count);
                rs = max(rs, count);
            }
        }
    }

    return rs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout.setf(ios::fixed);
    vector<vector<int>> mt = {{0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}, {0, 0, 1, 1}};
    cout << lr(mt);
    return 0;
}
