#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // �?t gi� tr? v� h?n

// C?u tr�c �? l�u tr? th�ng tin v? m?t c?nh
struct Edge {
    int u;      // �?nh �?u
    int v;      // �?nh cu?i
    int weight; // Tr?ng s? c?a c?nh
};

// L?p Graph �? �?i di?n cho �? th?
class Graph {
public:
    int V; // S? l�?ng �?nh
    vector<Edge> edges; // Danh s�ch c�c c?nh

    // Constructor �? kh?i t?o �? th? v?i s? �?nh
    Graph(int V) {
        this->V = V;
    }

    // Ph��ng th?c �? th�m m?t c?nh v�o �? th?
    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight}); // Th�m c?nh v�o danh s�ch
    }

    // Ph��ng th?c th?c hi?n thu?t to�n Bellman-Ford
    void bellmanFord(int src) {
        vector<int> distance(V, INF); // Kh?i t?o kho?ng c�ch t? �?nh ngu?n
        distance[src] = 0; // Kho?ng c�ch t? �?nh ngu?n �?n ch�nh n� l� 0

        // C?p nh?t kho?ng c�ch cho t?t c? c�c c?nh
        for (int i = 0; i < V - 1; i++) { // L?p V-1 l?n
            for (const auto& edge : edges) { // Duy?t qua t?t c? c�c c?nh
                if (distance[edge.u] != INF && 
                    distance[edge.u] + edge.weight < distance[edge.v]) {
                    distance[edge.v] = distance[edge.u] + edge.weight; // C?p nh?t kho?ng c�ch
                }
            }
        }

        // Ki?m tra chu tr?nh �m
        for (const auto& edge : edges) {
            if (distance[edge.u] != INF && 
                distance[edge.u] + edge.weight < distance[edge.v]) {
                cout << "Do thi chua chu trinh am" << endl; // Th�ng b�o c� chu tr?nh �m
                return; // K?t th�c h�m
            }
        }

        // In ra kho?ng c�ch t? �?nh ngu?n �?n c�c �?nh kh�c
        cout << "Khoang cach tu dinh " << src << " den cac dinh khac:" << endl;
        for (int i = 0; i < V; i++) {
            if (distance[i] == INF) {
                cout << "Dinh" << i << ": vo cung" << endl; // N?u kh�ng th? �?n �?nh
            } else {
                cout << "Dinh " << i << ": " << distance[i] << endl; // In ra kho?ng c�ch
            }
        }
    }
};

int main() {
    int V, E; // Khai b�o s? l�?ng �?nh v� c?nh
    cout << "Nhap so dinh va so canh: ";
    cin >> V >> E; // Nh?p s? l�?ng �?nh v� c?nh

    Graph g(V); // T?o m?t �?i t�?ng �? th? v?i V �?nh

    cout << "Nhap cac canh(u,v, trong so):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight; // Khai b�o c�c bi?n cho �?nh �?u, �?nh cu?i v� tr?ng s?
        cin >> u >> v >> weight; // Nh?p c�c gi� tr?
g.addEdge(u, v, weight); // Th�m c?nh v�o �? th?
    }

    int src; // Khai b�o bi?n cho �?nh ngu?n
    cout << "Nhap dinh nguon: ";
    cin >> src; // Nh?p �?nh ngu?n

    g.bellmanFord(src); // G?i ph��ng th?c bellmanFord �? t?m ��?ng �i ng?n nh?t t? �?nh ngu?n

    return 0; // K?t th�c h�m main
}
