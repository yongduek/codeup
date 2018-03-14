//
//  2634_거스름돈_II.cpp
//  codeup
//
//  Created by Yongduek Seo on 3/12/18.
//  Copyright © 2018 com.yndk. All rights reserved.
//

#include <iostream>
using namespace std;

const int inf = 1000000; // much larger than the input max
int N;
int coin[11];

int mincoins[10010];

// ** complete search algorithm **
//
// this DP's time complexity is O(nV), n = # coins, V = values
//
// change(0) = 0 ; we need 0 coins to produce 0 cents
// change (<0) = inf ; in practice we can return a large positive value
// change (infeasible) = inf ; this case eventually ends up with change (<0)!
// cnage (value) = 1 + min (change(value-coinValue[i])) for i in [0 .. n-1]

int nchange (int value)
{
    if (value == 0) return 0;
    else if (value < 0) return inf;
    else {
        if (mincoins[value]) return mincoins[value];
        
        int minchange = inf;
        for (int i = 0; i < N; i++)
            minchange = std::min (minchange, nchange (value - coin[i]));
        mincoins[value] = minchange + 1;
    }
    return mincoins[value];
}

int getmin (int val)
{
    if (val < 0 ) return inf;
    else return mincoins[val];
}
int nchange2 (int amount)
{
    mincoins[0] = 0;
    for (int v = 1; v <= amount; v++) {
        int minch = inf;
        for (int i = 0; i < N; i++)
            minch = std::min ( minch, getmin( v - coin[i] ) );
        mincoins[v] = 1 + minch;
    }
    return mincoins[amount];
}
int main()
{
    int amount; // input amout of money
    cin >> amount >> N;
    for (int i = 0; i < N; i++)
        cin >> coin[i];
    
//    cout << nchange (amount);
    cout << nchange2 (amount);

    return 0;
}
