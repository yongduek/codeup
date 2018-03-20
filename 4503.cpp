//
//  Created by Yongduek Seo on 2018. 3. 2..
//  yndk@sogang.ac.kr
//

/*
 codeup 4503
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > adjlist(102);
bool visit[102];

void dfs (int s)
{
    visit[s] = true;
    for (int i = 0; i < adjlist[s].size(); i++)
        {
        int dest = adjlist[s][i];
        if (visit[dest] == false)
            {
            dfs (dest);
            }
        }
}

int get_dfs (int s)
{
    dfs (s);

    int count = 0;
    
    for (int i = 0; i < adjlist.size(); i++)
        if (visit[i])
            count ++;
    
    return count;
}


void dfs2 (int s, int& nc)
{
    ++nc;
    visit[s] = true;
    for (int i=0; i < adjlist[s].size(); i++)
        if (visit[adjlist[s][i]] == false)
            dfs2 (adjlist[s][i], nc);
}

int get_dfs2 (int s)
{
    int nc = 0;
    dfs2 (s, nc);
    return nc;
}

int main(int argc, const char * argv[]) {

    int n;
    cin >> n;
    ++n; // 1-based index
    int nedges;
    cin >> nedges;
    for (int i = 0; i < nedges; i++)
        {
        int s, e;
        cin >> s >> e;
        adjlist[s].push_back (e);
        adjlist[e].push_back (s);
        }

    int nconnected = get_dfs2 (1);
    // int nconnected = get_dfs (1);  // this also works!
    
    cout << nconnected - 1; // source node is not included.
    return 0;
}
