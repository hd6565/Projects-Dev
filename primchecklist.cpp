#include<iostream>  
#include<vector>  
#include<string.h>  
#include<utility>  
#include<limits.h>  
using namespace std;  

const int maxn = 1001; // s? �?nh t?i �a  
struct canh {  
    int x, y, w; // �?nh �?u, �?nh cu?i, tr?ng s?  
};  

int n, m; // s? �?nh v� s? c?nh  
vector<pair<int, int>> adj[maxn]; // l�u danh s�ch k?  
bool danhDau[maxn]; // ��nh d?u �?nh thu?c V hay V(mst)  

void nhap() {  
    cin >> n >> m; // s? �?nh v� s? c?nh  
    for (int i = 0; i < m; i++) { // duy?t qua m c?nh  
        int x, y, w;   
        cin >> x >> y >> w; // �?nh �?u, �?nh cu?i, tr?ng s?   
        adj[x].push_back({y, w}); // do th? v� h�?ng  
        adj[y].push_back({x, w});  
    }  
    memset(danhDau, false, sizeof(danhDau)); // kh?i t?o t?t c? �?nh l� false  
}  

void prim(int u) {  
    vector<canh> MST; // c�y khung mst r?ng  
    int d = 0; // t?ng tr?ng s? c?a mst  
    danhDau[u] = true; // ��a �?nh u v�o V(mst)  

    while (MST.size() < n - 1) {  
        int min_w = INT_MAX; // l�u k? l?c tr?ng s? nh? nh?t  
        int X = -1, Y = -1; // l�u 2 �?nh c?a c?nh e  

        for (int i = 1; i <= n; i++) {  
            if (danhDau[i]) {  
                for (pair<int, int> a : adj[i]) {  
                    int j = a.first, trongso = a.second;  

                    if (!danhDau[j] && trongso < min_w) {  
                        min_w = trongso;  
                        X = j;  
                        Y = i;  
                    }  
                }  
            }  
        }  

        if (X != -1 && Y != -1) {  
            MST.push_back({X, Y, min_w}); // th�m c?nh v�o MST  
            d += min_w;  
            danhDau[X] = true; // ��nh d?u X v�o V(mst)  
        } else {  
            break; // Ng�n kh�ng cho ti?p t?c n?u kh�ng c?n c?nh n�o h?p l?  
        }  
    }  

    cout << d << endl; // in t?ng tr?ng s?  
    for (canh e : MST) {  
        cout << e.x << " " << e.y << " " << e.w << endl; // in c�c c?nh trong MST  
    }  
}  

int main() {  
    nhap();  
    prim(1); 
	 system("pause");   
	 return 0; 
}  
