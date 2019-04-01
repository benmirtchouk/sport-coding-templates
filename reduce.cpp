#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define x first
#define y second
#define pil pair<int,long long>

int main()
{
    int N;
    cin >> N;

    vector<pair<int, long long> > A(N);
    for (int i=0;i<N;i++){
        A[i].x=i;
        cin >> A[i].y;
    }

    sort(A.begin(),A.end(),[](const pil& a, const pil& b){ return a.y < b.y; });
    for (int i=0;i<N;i++){
        A[i].y=i;
    }
    sort(A.begin(),A.end(),[](const pil& a, const pil& b){ return a.x < b.x; });

    return 0;
}
