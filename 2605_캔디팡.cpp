//
//  2605_캔디팡.cpp
//  codeup
//
//  Created by Yongduek Seo on 3/30/18.
//  Copyright © 2018 com.yndk. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int gg[8][8];
const int rows=7, cols=7;

const int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs (int r, int c, int color)
{
    if (r < 0 || c < 0 || r >= 7 || c >= 7
        || gg[r][c] != color) return 0;

    gg[r][c] = 0; // put mark!
    int nc = 1;
    for (int k = 0; k < 4; k++)
        nc += dfs (r+d[k][0], c+d[k][1], color);
    return nc;
}

int get_connected(int r, int c, int color)
{
    int nc = dfs (r, c, color);
    
    return nc;
}
int main()
{
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            cin >> gg[r][c];

    int nfunc = 0;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (gg[r][c]) {
                int nc = get_connected(r,c, gg[r][c]);
                if (nc >= 3) nfunc ++;
                if (0) {
                    printf ("---- nc=%d nf=%d ----\n", nc, nfunc);
                    for (int r = 0; r < rows; r++) {
                        printf ("   ");
                        for (int c = 0; c < cols; c++)
                            printf("%d ", gg[r][c]);
                        printf("\n");
                    }
                }
            }
    
    cout << nfunc;
    return 0;
}
