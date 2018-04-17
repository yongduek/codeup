//
//  codeup_4027_저울추.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 4. 17..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <deque>
using namespace std;

const int nw = 7;
int w[] = {1, 3, 9, 27, 81, 243, 729};
int place[nw];
enum POSITION {NONE, LEFT, RIGHT};
char POSITION_STR[3][10] = { "NONE", "LEFT", "RIGHT" };
int n_input;

bool found = false;

void pr()
{
    printf ("%d ", n_input);
    for (int i = 0; i < nw; i++)
        if (place[i] == LEFT)
            printf ("%d ", w[i]);
    printf ("0 ");
    for (int i = 0; i < nw; i++)
        if (place[i] == RIGHT)
            printf ("%d ", w[i]);
}


void solve (int index, int left, int right)
{
    if (left == right) {
        // finished
        found = true;
        //for (int i = 0; i < nw; i++)
        //    printf ("%d: w=%d %s\n", i, w[i], POSITION_STR[place[i]]);
        
        //pr();
        return;
    }
    if (index >= nw) return; // no solution
    
    int weight = w[index];
    //if (found) return;
    place[index] = LEFT; solve (index+1, left + weight, right);

    if (found) return;
    place[index] = RIGHT;solve (index+1, left, right + weight);
    
    if (found) return;
    place[index] = NONE; solve (index+1, left, right);
}

int main()
{
    int n;
    cin >> n_input;
    
    solve (0, n_input, 0);
    pr();
}
