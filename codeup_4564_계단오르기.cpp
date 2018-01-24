//
//  codeup_4564.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 1. 21..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int nsteps;
int score [303];
int maxPointAt[303];
int point = 0;

void next (int curr, int didOne, int accPoint, vector<int>& track)
{
//    cout << "curr: " << curr << ' ' << didOne << ' ' << accPoint ;
    
    if (curr >= nsteps) {
        track.pop_back();
//        cerr << " step exceeded!" << endl;
        return;
    }
    
    accPoint += score[curr];
    
//    cout << " ==> accPoint ==> " << accPoint << endl;
    
    if (curr == nsteps-1) {
        if (point < accPoint) {
            point = accPoint;

            cout << "> point = " << point << endl;
            int acc = 0;
            for (int i=0; i<track.size(); i++) {
                acc += score[track[i]];
                cout << track[i] << " : " << score[track[i]] << "  == " << acc << endl;
            }
            cout << " ----- " << endl;
        }
        track.pop_back();
        return; // finish.
    }
    
    if (didOne == 1) {
        track.push_back (curr+1);
        next (curr+1, didOne+1, accPoint, track);

        track.push_back (curr+2);
        next (curr+2, 1, accPoint, track);
    }
    else { // didOne == 2
        track.push_back (curr+2);
        next (curr+2, 1, accPoint, track);
    }
    
    track.pop_back();
}

void solve ()
{
    vector<int> track;
    track.push_back ( 0 );
    next (0, 1, 0, track); // one step

    track.push_back (1);
    next (1, 1, 0, track); // two steps
    
    cout << point << endl;
}

int main()
{
    cin >> nsteps;
    for (int i=0; i < nsteps; i++)
        cin >> score[i];
    
//    cout << "--" << endl;
//    for (int i=0; i < nsteps; i++)
//        cout << score[i] << endl;
//    cout << "--" << endl;
    
    solve ();
    
    return 0;
}
