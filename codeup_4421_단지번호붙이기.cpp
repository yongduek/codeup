//
//  codeup_4421_단지번호붙이기.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 1. 22..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct xy {
    int r, c;
    xy (int _r, int _c) : r(_r), c(_c) {}
};

int m, n;
int mat[200][200];

bool outside(int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n) return true;
    return false;
}

bool notAblock(int r, int c) {
    return mat[r][c] == 0;
}

bool marked(int r, int c, int number) {
    return mat[r][c] == number;
}

int bfs (queue<xy>& q, int number)
{
    int count = 0;
    while (!q.empty()) {
        xy p = q.front(); q.pop();

        if (outside(p.r, p.c) || notAblock(p.r, p.c) || marked(p.r, p.c, number))
            continue;
        q.push (xy(p.r+1, p.c));
        q.push (xy(p.r-1, p.c));
        q.push (xy(p.r, p.c+1));
        q.push (xy(p.r, p.c-1));
        
        mat[p.r][p.c] = number;
        count ++;
    }
    return count;
}

int main()
{
    string line;
    cin >> line;
    m = n = stoi(line);
    
    for (int r = 0; r < m; r++) {
        cin >> line;
        for (int c = 0; c < n; c++) {
            mat[r][c] = line[c] - '0';
        }
    }

//    for (int r = 0; r < m; r++) {
//        for (int c = 0; c < n; c++) {
//            cout << mat[r][c] << ' ' ;
//        }
//        cout << endl;
//    }

    // BFS
    vector<int> blocks;
    int number = 2; // start with this number
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++) {
            if (mat[r][c] == 1) {
                queue<xy> q;
                q.push(xy(r,c));
                int nhouses = bfs (q, number++);
                blocks.push_back(nhouses);
            }
        }

//    cout << "--- result:" << endl;
//    for (int r = 0; r < m; r++) {
//        for (int c = 0; c < n; c++) {
//            cout << mat[r][c] << ' ' ;
//        }
//        cout << endl;
//    }

    std::sort (blocks.begin(), blocks.end());
    cout << blocks.size() << endl;
    for (auto i=0; i < blocks.size(); i++)
        cout << blocks[i] << endl;
    
    return 0;
}
