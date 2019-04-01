#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> G[N];
    vector<int> D(N);

    //G[from].push_back(to);

    int first;
    cin >> first;

    queue<int> q;
    q.push(first);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        if (D[v]==0){
            D[v]=1;
            for (int j=0;j<G[v].size();j++)
                q.push(G[v][j]);
        }
    }

    for (int i=0;i<N;i++)
        cout << D[i] << " ";

    return 0;
}
