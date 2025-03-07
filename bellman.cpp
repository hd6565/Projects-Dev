#include <iostream>  
#include <vector>  
#include <algorithm>  
#include <climits>  

using namespace std;  

typedef long long ll;  

const int MaxN = 1 + 1e2;  
const ll INF = 1e18;  

int n, m, s, mark[MaxN];  
ll dist[MaxN];  

class Edge {  
    public:  
        int u, v, weight;  
        Edge(int _u, int _v, int _weight): u(_u), v(_v), weight(_weight){}  
};  

vector<Edge> edges;  

void Bellman_ford() {  
    fill(dist + 1, dist + n + 1, INF);  
    dist[s] = 0;  

    for(int i = 1; i <= n; i++){  
        for(Edge e : edges){  
            if(dist[e.u] + e.weight < dist[e.v]){  
                if(i == n) mark[e.v] = 1;  
                dist[e.v] = dist[e.u] + e.weight;  
            }  
        }  
    }  
}  

int main(){  
    cin >> n >> m >> s;  
    for(int i = 1; i <= m; i++){  
        int u, v, weight;  
        cin >> u >> v >> weight;  
        edges.push_back(Edge(u, v, weight));  
    }  
    Bellman_ford();  
    for(int i = 1; i <= n; i++)  
    if(!mark[i]){   
        if(dist[i] == INF) cout << "-1" << endl;  
        else cout << dist[i] << endl;  
    } else cout << "-2" << endl;  

    return 0;  
}  
