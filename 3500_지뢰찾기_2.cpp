//
//  3500_지뢰찾기_2.cpp
//  codeup
//
//  Created by Yongduek Seo on 3/30/18.
//  Copyright © 2018 com.yndk. All rights reserved.
//

// !!!!   NOT Solved.  Try 지뢰찾기 1 before further going.
// I guess I don't know the rule of this game.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

const int s = 9;
int map[s][s];
int out[s][s];
bool visible[s][s]; // invisible in the beginning

void add1 (int r, int c)
{
    if (r < 0 || c < 0 || r >= s || c >= s) return;
    if (out[r][c] == '_') return;
    out[r][c] += 1;
}
void mark (int r, int c)
{
    for (int rr = -1; rr <= 1; rr++)
        for (int cc = -1; cc <= 1; cc++) {
            add1 (r+rr, c+cc);
        }
    out[r][c] = '_' ;
}

void pr ()
{
    for (int r = 0; r < s; r++) {
        for (int c = 0; c < s; c++)
            if (visible[r][c])
                {
                if (out[r][c] == '_')
                    cout << "_ ";
                else
                    cout << out[r][c] << " " ;
                }
            else {
                cout << "_ ";
            }
        cout << endl;
    }
}

void set_visible (int r, int c)
{
    if (r < 0 || c < 0 || r >= s || c >= s) return;
    
    visible[r][c] = true;
}

void bfs (int r, int c)
{
    queue<pair<int,int> > q;
    set_visible(r, c);
    q.push (make_pair(r, c));
    while (!q.empty()) {
        //cout << q.size() << endl;
        pair<int,int> n = q.front(); q.pop();

        r = n.first;
        c = n.second;
        for (int rr = r-1; rr <= r+1; rr++)
            for (int cc = c-1; cc <= c+1; cc++) {
                rr , cc;
                if (rr >= 0 && rr < s && cc >= 0 && cc < s
                    && visible[rr][cc]==false && out[rr][cc] == 0) {
                    set_visible(rr, cc);
                    q.push (make_pair(rr, cc));
                }
            }
    }
}
int main()
{
    for (int r = 0; r < s; r++)
        for (int c = 0; c < s; c++) {
            cin >> map[r][c];
        }
    
    int r0, c0;
    cin >> r0 >> c0;
    
    r0--, c0--; // 1-based :-> 2-based
    
    if (map[r0][c0] == 1) { cout << -1; }
    else {
        for (int r = 0; r < s; r++)
            for (int c = 0; c < s; c++)
                if (map[r][c] == 1)
                    mark (r,c);
    }
    
    bfs (r0,c0); // visibility 1
    
    //pr ();
//    cout << "---" << endl;

    vector<pair<int,int>> vis;
    
    for (int r = 0; r < s; r++)
        for (int c = 0; c < s; c++)
            if (visible[r][c] && out[r][c] == 0)
                {
                for (int a = r - 1; a <= r+1; a++)
                    for (int b = c - 1; b <= c+1; b++)
                        if (a >= 0 && b >=0 && a < s && b < s
                            //&& out[a][b] != '_'
                            )
                            {
                            vis.push_back(make_pair(a, b));
                        }
                }
    
    for (auto i = 0; i < vis.size(); i++)
        visible[vis[i].first][vis[i].second] = true;
    
    
    pr();
    
    return 0;
}

/*
 입력:
 0 1 0 0 0 0 0 0 1
 0 1 0 0 0 0 0 0 0
 0 1 0 1 0 0 0 0 0
 0 1 0 0 0 0 0 0 0
 0 1 0 0 0 1 0 0 0
 0 1 0 0 0 1 0 0 1
 0 1 1 0 1 1 0 0 0
 0 1 0 0 1 0 0 1 0
 0 1 0 0 0 0 0 0 0
 9 1
 
 정답:
 _ _ _ _ _ _ _ _ _
 _ _ _ _ _ _ _ _ _
 _ _ _ _ _ _ _ _ _
 _ _ _ _ _ _ _ _ _
 _ _ _ _ _ _ _ _ _
 _ _ _ _ _ _ _ _ _
 _ _ _ _ _ _ _ _ _
 _ _ _ _ _ _ _ _ _
 2 _ _ _ _ _ _ _ _

 */
