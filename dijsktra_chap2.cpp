#include <iostream>  
#include <set>  
#include <vector>  
#include <queue>  
#include <climits>   

using namespace std;  
   
using ll = long long;  
   
const int maxn = 100001;  
int n, m, s, t;  
vector<pair<int, int>> adj[maxn];  
   
void nhap(){  
	cout<<"nhap so dinh-"<<"so canh-"<<"dinh bat dau";
	cout<<endl;
	
    cin >> n >> m >> s;  
    for(int i = 0; i < m; i++){  
        int x, y, w; cin >> x >> y >> w;  
        adj[x].push_back({y, w});  
        //adj[y].push_back({x, w});   
    }  
}  
   
const int INF = 1e9;  
int pre[maxn];  
   
void dijkstra(int s){  
    // mang luu khoang cach duong di  
    vector<ll> d(n + 1, INF);  
    d[s] = 0;  

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> Q;  
    // (khoang cach, dinh)  
    Q.push({0, s});  
    
    while(!Q.empty()){  
        //chon ra dinh co khoang cach nho nhat tu s  
        pair<int, int> top = Q.top(); Q.pop();  
        int u = top.second;  
        int kc = top.first;  
        
        // neu kc hien tai lon hon kc da biet thi bo qua  
        if(kc > d[u]) continue;  
    
        for(auto it : adj[u]){  
            int v = it.first;  
            int w = it.second;  
            if(d[v] > d[u] + w){  
                d[v] = d[u] + w;  
                Q.push({d[v], v});  
            }  
        }  
    }  

    for(int i = 1; i <= n; i++){  
        cout << d[i] << ' ';  
    }  
}  

int main(){  
    nhap();  
    dijkstra(s);  
    return 0;  
}  
