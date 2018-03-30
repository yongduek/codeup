//
//  3121_topological_sort_kahn.cpp
//  codeup
//
//  Created by Yongduek Seo on 3/30/18.
//  Copyright © 2018 com.yndk. All rights reserved.
//

// Kahn algorithm: similar to BFS
// https://en.wikipedia.org/wiki/Topological_sorting

/****************************************************
L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edge
while S is non-empty do
    remove a node n from S
    add n to tail of L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S
if graph has edges then
    return error (graph has at least one cycle)
else 
    return L (a topologically sorted order)
******************************************************/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;


deque< deque<int> > adjListIn(200+10), adjListOut(200+10);

int nv;

deque<int> tsout;

bool ts()
{
    auto inList = adjListIn;
    auto outList = adjListOut;
    priority_queue<int, vector<int>, greater<int> > pq; // default: max heap, this way we have min priority queue
    
    for (int v = 1; v <= nv; v++)
        if (inList[v].size() == 0) // a starting vertex
            pq.push(v);
    
    while (!pq.empty())
        {
        int v = pq.top(); pq.pop(); // get & remove v
        tsout.push_back(v); // add to the TS list
        
        deque<int>& out = outList[v];
        for (int o = 0; o < out.size(); o++)
            {
            int m = out[o]; // v -> m
                // remove edge e from the graph
            //auto & l = inList[m];
            for (auto it = inList[m].begin(); it != inList[m].end(); ++it)// int kk = 0; kk < l.size(); kk++)
                if (*it == v) { inList[m].erase(it); break; }
                // if m has no other incoming edges then
                //     insert m into S
            if (inList[m].size() == 0)
                pq.push (m);
            }
        }
    // now check if inList is not empty. Then G has a cycle.
    for (int v = 1; v <= nv; v++)
        if (inList[v].size() > 0) return false;
    
    return true;
}

int main ()
{
    int ne;
    cin >> nv >> ne;
    while (ne-- > 0) { // for each edge,
        int s, e;
        cin >> s >> e;
        adjListIn[e].push_back(s); // directed graph, adjList, incoming
        adjListOut[s].push_back(e); // outgoing adjList
    }

    bool r = ts ();
    if (r) {
        for (auto n : tsout)
            cout << n << endl;
    }
    else
        cout << -1;
}
