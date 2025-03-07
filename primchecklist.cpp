#include<iostream>  
#include<vector>  
#include<string.h>  
#include<utility>  
#include<limits.h>  
using namespace std;  

const int maxn = 1001; // s? ð?nh t?i ða  
struct canh {  
    int x, y, w; // ð?nh ð?u, ð?nh cu?i, tr?ng s?  
};  

int n, m; // s? ð?nh và s? c?nh  
vector<pair<int, int>> adj[maxn]; // lýu danh sách k?  
bool danhDau[maxn]; // ðánh d?u ð?nh thu?c V hay V(mst)  

void nhap() {  
    cin >> n >> m; // s? ð?nh và s? c?nh  
    for (int i = 0; i < m; i++) { // duy?t qua m c?nh  
        int x, y, w;   
        cin >> x >> y >> w; // ð?nh ð?u, ð?nh cu?i, tr?ng s?   
        adj[x].push_back({y, w}); // do th? vô hý?ng  
        adj[y].push_back({x, w});  
    }  
    memset(danhDau, false, sizeof(danhDau)); // kh?i t?o t?t c? ð?nh là false  
}  

void prim(int u) {  
    vector<canh> MST; // cây khung mst r?ng  
    int d = 0; // t?ng tr?ng s? c?a mst  
    danhDau[u] = true; // ðýa ð?nh u vào V(mst)  

    while (MST.size() < n - 1) {  
        int min_w = INT_MAX; // lýu k? l?c tr?ng s? nh? nh?t  
        int X = -1, Y = -1; // lýu 2 ð?nh c?a c?nh e  

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
            MST.push_back({X, Y, min_w}); // thêm c?nh vào MST  
            d += min_w;  
            danhDau[X] = true; // ðánh d?u X vào V(mst)  
        } else {  
            break; // Ngãn không cho ti?p t?c n?u không c?n c?nh nào h?p l?  
        }  
    }  

    cout << d << endl; // in t?ng tr?ng s?  
    for (canh e : MST) {  
        cout << e.x << " " << e.y << " " << e.w << endl; // in các c?nh trong MST  
    }  
}  

int main() {  
    nhap();  
    prim(1); 
	 system("pause");   
	 return 0; 
}  
