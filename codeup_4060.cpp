//
//  codeup_4060.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 1. 22..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//


#include<iostream>
#include<stack>
using namespace std;

int m, n;
int mat[200][200], mat2[200][200];

void off (int r, int c)
{
    if (r < 0 || r >= m || c < 0 || c >= n) return ;
    
    if (mat[r][c] == 0) return; // already off
    
    mat[r][c] = 0; // off
    
    off (r+1, c);
    off (r-1, c);
    off (r, c+1);
    off (r, c-1);
}

int turn_off ()
{
    int num = 0;
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++) {
            if (mat[r][c]) {
                off (r, c);
                num ++;
            }
        }
    return num;
}

void on (int r, int c, int mm[200][200])
{
    if (r < 0 || r >= m || c < 0 || c >= n) return ;
    
    if (mm[r][c] != 0) return; // already off
    
    mm[r][c] = 1; // off
    
    on (r+1, c, mm);
    on (r-1, c, mm);
    on (r, c+1, mm);
    on (r, c-1, mm);
}

int turn_on (int mm[200][200])
{
    int num = 0;
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++) {
            if (mm[r][c] == 0) {
                on (r, c, mm);
                num ++;
            }
        }
    return num;
}

int main()
{
    cin >> m >> n;

    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++) {
            cin >> mat[r][c];
            mat2[r][c] = mat[r][c]; // a copy
        }
    
    int noff = turn_off ();
    
    int non = turn_on (mat2);
    
    cout << non << ' ' << noff << endl;
    return 0;
}
