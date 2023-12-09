#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &arr, int n, vector<string> &ans, int x, int y, string output) {
    if (x < 0 || y < 0 || x >= n || y >= n || arr[x][y] == 0) {
        return;
    }

    if (x == n - 1 && y == n - 1) {
        ans.push_back(output);
        return;
    }

    arr[x][y] = 0;  // Mark the current cell as visited

    solve(arr, n, ans, x + 1, y, output + "D");
    solve(arr, n, ans, x, y + 1, output + "R");
    solve(arr, n, ans, x - 1, y, output + "U");
    solve(arr, n, ans, x, y - 1, output + "L");

    arr[x][y] = 1;  // Backtrack: Mark the current cell as unvisited
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<string> ans;
    int x = 0, y = 0;
    string output = "";
    solve(arr, n, ans, x, y, output);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<string> result = searchMaze(arr, n);

    for (const string &path : result) {
        cout << path << " ";
    }

    return 0;
}
