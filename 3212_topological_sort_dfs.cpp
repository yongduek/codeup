//
//  3212_topological_sort.cpp
//  codeup
//
//  Created by Yongduek Seo on 3/30/18.
//  Copyright © 2018 com.yndk. All rights reserved.
//

/***
 입력:
 11 14
 1 5
 1 9
 2 3
 3 6
 3 7
 4 8
 5 2
 5 4
 5 9
 6 8
 7 9
 8 9
 9 10
 11 1

 정답:
 11
 1
 5
 2
 3
 4
 6
 7
 8
 9
 10

 
 *** 우선순위가 같을 때 정점의 번호가 낮은 것을 우선으로 한다.
 그래서 위 결과가 나와야 하는데, dfs 로 돌리면 저렇게 나오지 않는다.
 
 !! BFS 를 사용하는 Kahn 알고리듬을 사용하면 위 정답이 나온다.
 
 
 
 ***/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int nv;
vector< vector<int> > adjList;

deque<int> tsresult;
vector<bool> visited(201, false);

void dfs (int startnode) {
    visited[startnode] = true;
    vector<int>& edges = adjList[startnode];
    if (10) {
        printf (" s: %d >> ", startnode);
        for (int i = 0; i < edges.size(); i++)
            printf (" %d (%s) ", edges[i], visited[edges[i]] ? "T" : "F");
        printf ("\n");
    }
    for (int i = 0; i < edges.size(); i++) {
        if (visited[edges[i]] == false) {
            printf (" from (%d) goto (%d)\n", startnode, edges[i]);
            dfs (edges[i]);
        }
    }
    tsresult.push_front (startnode);
}

bool ts ()
{
    vector<int> snode; // vertices of no incoming edges
    vector<bool> noIncoming(adjList.size(), true);
    for (int i = 1; i <= nv; i++) {
        vector<int>& edges = adjList[i];
        for (int k = 0; k < edges.size(); k++) {
            noIncoming[edges[k]] = false;
        }
    }
    for (int k = 1; k <= nv; k++)
        if (noIncoming[k])
            snode.push_back (k);

    if (snode.size() < 1) return false;

    for (int i = 0; i < adjList.size(); i++) // sort edge list, the smaller id has priority
        sort (adjList[i].begin(), adjList[i].end());

    if (10) {
        for (int i = 0; i < adjList.size(); i++) {
            printf ("%d >> ", i);
            for (int k = 0; k < adjList[i].size(); k++)
                printf (" %d", adjList[i][k]);
            printf ("\n");
        }
    }

    for (auto i = 0; i < snode.size(); i++) {
        if (10) printf (">> starting at node %d\n", snode[i]);
        dfs (snode[i]);
    }
    
    return true;
}

int main()
{
    int ne;
    cin >> nv >> ne;
    adjList.resize(nv + 1); // allocate NV, 1-based indexing
    while (ne-- > 0) { // for each edge,
        int s, e;
        cin >> s >> e;
        adjList[s].push_back(e); // directed graph
    }
    
    bool r = ts ();
    if (r) { // print ts result
        for (int i = 0; i < tsresult.size(); i++)
            cout << tsresult[i] << endl ;
    }
    else
        cout << -1 ;

    return 0;
}


/*
 https://cs.stackexchange.com/questions/9133/finding-a-source-of-a-directed-acyclic-graph-in-linear-time
 
 As Yuval mentions, the datastructure is important here. I'll try to give a solution for some of the types of adjacency lists:
 
 Incoming edge list: For each node, there is a list of vertices from which there is an incoming edge to this node. You can simply scan all vertices and check if the size of their adjacency list is 0
 or not. A size 0
 list means no incoming edges, so the node is either a source or disconnected. Assuming a connected graph, this scan of each vertex will give you a list of all sources (or you can stop after finding one) in O(|V|)
 time - linear in the number of vertices.
 Outgoing edge list: For each node, there is a list of vertices to which there is a directed edge from this node. Keep a bit-string with each bit representing a vertex, initialized to 0. Starting from the first node, start scanning its list for vertices to which there is an outgoing edge from this. Every such node (neighbour) cannot be a source, so keep setting their corresponding bit in the bit-string. At the end, all vertices whose corresponding bits are still unset, are the source vertices. You can do this in time linear in the size of the graph - O(|V|+|E|)
 .
 Both lists together: For each vertex, there is a mixed list of vertices which have an edge to or from this vertex, with some other attribute indicating which of the two is actually the case. The approach is similar to 2 above, with the addition that any incoming edge immediately rules out the current vertex (and you can mark its bit set). Unlike in point 2 where you need to go through all vertices, here, you might find some source sooner. If you don't stop, you will have all sources. For both cases, time is again linear in the size of the graph - O(|V|+|E|)
 .
 Both lists separately: Just pick the incoming edge list and follow 1.
 As a side note, if choosing the datastructure is in your hands, you might want to analyze what all operations you intend to perform, and how frequently, and choose an appropriate datastructure.
 
 Edit: For case 1, if you have a dag where the number of sources is very small as compared to |V|
 (eg, in a tree with one source), and where the average distance from any vertex to a source is small as compared to |V|
 and you only want any one source, you can use a faster on average algorithm (although worst case asymptotic complexity will be the same). Select any vertex at random, and go to any of its parent (from the incoming edge list), and on to its parent and so on, till you reach a node which has no parent - a source. This small gain of efficiency is for very limited types of graphs with a slightly more complex algorithm.
 
 */
