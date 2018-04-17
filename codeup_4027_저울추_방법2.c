//
//  codeup_4027_저울추_방법2.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 4. 17..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>

#define nw 7
#define true 1
#define false 0

int w[] = {1, 3, 9, 27, 81, 243, 729};
int place[nw+1];
int putleft[nw];
enum POSITION {NONE, LEFT, RIGHT};
char POSITION_STR[3][10] = { "NONE", "LEFT", "RIGHT" };
int n_input;

int found = false;

int main()
{
    scanf("%d", &n_input);
    
    {
    int i = 0;
    int n = n_input;
    while (n != 0) {
        int r = n % 3;
        int q = n / 3;
        place[i++] = r;
        n = q;
    }
    }
    
    for (int i = 0; i < nw; i++)
        if (place[i] == 2) {
            putleft[i] = true;
            place[i] = 0;
            place[i+1] += 1; // carry
            for (int k = i+1; k < nw; k++) {
                int carry = place[k] == 3;
                if (carry) {
                    place[k] = 0;
                    place[k+1] += 1;
                }
                else
                    break;
            }
        }
    
    printf ("%d ", n_input);
    for (int i = 0; i < nw; i++) // left
        if (putleft[i])
            printf ("%d ", w[i]);
    printf ("0 ");
    for (int i = 0; i < nw; i++) // right
        if (place[i])
            printf ("%d ", w[i]);
    
    return 0 ;
}
