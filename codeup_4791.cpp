//
//  codeup_4791.cpp
//  codeup
//
//  Created by Yongduek Seo on 3/12/18.
//  Copyright © 2018 com.yndk. All rights reserved.
//

#include <algorithm>
#include <iostream>
using namespace std;

int M, N, L;
int shoot[100010];
struct Loc {
    int x, y;
};
Loc loc[100010];
bool visible[100010];

int dist (int i, int j) {
    int d = abs(shoot[i] - loc[j].x) + loc[j].y;
    return d;
}

int complete_search()
{
    for (auto i = 0; i < M; i++) { // for all shooting position
        for (auto j = 0; j < N; j++) { // for each animal
            if (visible[j]) continue; // already done
            if (dist(i,j) <= L)
                visible[j] = true;
        }
    }
    
    int count = 0;
    for (auto j = 0; j < N; j++)
        count += visible[j];
    
    return count;
}

int complete_search_2 ()
{
    for (auto j = 0; j < N; j++) { // for each animal
        bool tag = visible[j]
        || loc[j].y > L // y > Limit
        ;
        if (tag) continue;
        for (auto i = 0; i < M; i++) { // for each shooting position
            bool tag2 = abs(loc[j].x - shoot[i]) > L ;
            if (!visible[j] && !tag2 && dist(i,j) <= L)
                visible[j] = true;
        }
    }
    
    int count = 0;
    for (auto j = 0; j < N; j++)
        count += visible[j];
    
    return count;
}


/*
 std::lower_bound (begin, end, val)
    Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val. 크거나 같은 것들 중에서 첫번째 것.
 
 std::upper_bound (begin, end, val)
    Returns an iterator pointing to the first element in the range [first,last) which compares greater than val. 큰 것들 중에서 첫번째 것

 */
bool feasible (int shoot_x, int i)
{
    return ( abs(shoot_x - loc[i].x) + loc[i].y  <= L );
}
int solve ()
{
    int count = 0;
    for (int i = 0; i < N; i++) {
        int *lb = std::lower_bound(shoot, shoot + M, loc[i].x); // 사냥감과 같거나 큰 슈팅위치
        
//        printf ("game (%d, %d) is tested by (%d, %d)\n", loc[i].x, loc[i].y, *lb, *(lb-1));
        
        if (lb == shoot+M) // not found,
            count += feasible (*(lb-1), i);
        else if (lb == shoot) // the first
            count += feasible (*lb, i);
        else {
            if (feasible (*lb, i) || feasible (*(lb-1), i))
                count ++;
        }
    }
    return count;
}

int main() {
    cin >> M >> N >> L;
    
    for (auto i = 0; i < M; i++)
        cin >> shoot[i];
    
    sort (shoot, shoot+M);
    //    for (auto i = 0; i < M; i++)
    //            printf("%d  ", shoot[i]);
    //    printf("\n");
    
    for (auto i = 0; i < N; i++) {
        cin >> loc[i].x >> loc[i].y;
    }
    
    //    for (auto i = 0; i < N; i++) {
    //            printf ("(%d, %d)\n", loc[i].first, loc[i].second);
    //    }
    
    int ncapture;
    // TLE
    //    ncapture = complete_search ();
    //    ncapture = complete_search_2 ();
    
    ncapture = solve ();
    
    cout << ncapture ;
    
    return 0;
}

