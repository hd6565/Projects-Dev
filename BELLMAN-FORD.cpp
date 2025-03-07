#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Ð?t giá tr? vô h?n

// C?u trúc ð? lýu tr? thông tin v? m?t c?nh
struct Edge {
    int u;      // Ð?nh ð?u
    int v;      // Ð?nh cu?i
    int weight; // Tr?ng s? c?a c?nh
};

// L?p Graph ð? ð?i di?n cho ð? th?
class Graph {
public:
    int V; // S? lý?ng ð?nh
    vector<Edge> edges; // Danh sách các c?nh

    // Constructor ð? kh?i t?o ð? th? v?i s? ð?nh
    Graph(int V) {
        this->V = V;
    }

    // Phýõng th?c ð? thêm m?t c?nh vào ð? th?
    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight}); // Thêm c?nh vào danh sách
    }

    // Phýõng th?c th?c hi?n thu?t toán Bellman-Ford
    void bellmanFord(int src) {
        vector<int> distance(V, INF); // Kh?i t?o kho?ng cách t? ð?nh ngu?n
        distance[src] = 0; // Kho?ng cách t? ð?nh ngu?n ð?n chính nó là 0

        // C?p nh?t kho?ng cách cho t?t c? các c?nh
        for (int i = 0; i < V - 1; i++) { // L?p V-1 l?n
            for (const auto& edge : edges) { // Duy?t qua t?t c? các c?nh
                if (distance[edge.u] != INF && 
                    distance[edge.u] + edge.weight < distance[edge.v]) {
                    distance[edge.v] = distance[edge.u] + edge.weight; // C?p nh?t kho?ng cách
                }
            }
        }

        // Ki?m tra chu tr?nh âm
        for (const auto& edge : edges) {
            if (distance[edge.u] != INF && 
                distance[edge.u] + edge.weight < distance[edge.v]) {
                cout << "Do thi chua chu trinh am" << endl; // Thông báo có chu tr?nh âm
                return; // K?t thúc hàm
            }
        }

        // In ra kho?ng cách t? ð?nh ngu?n ð?n các ð?nh khác
        cout << "Khoang cach tu dinh " << src << " den cac dinh khac:" << endl;
        for (int i = 0; i < V; i++) {
            if (distance[i] == INF) {
                cout << "Dinh" << i << ": vo cung" << endl; // N?u không th? ð?n ð?nh
            } else {
                cout << "Dinh " << i << ": " << distance[i] << endl; // In ra kho?ng cách
            }
        }
    }
};

int main() {
    int V, E; // Khai báo s? lý?ng ð?nh và c?nh
    cout << "Nhap so dinh va so canh: ";
    cin >> V >> E; // Nh?p s? lý?ng ð?nh và c?nh

    Graph g(V); // T?o m?t ð?i tý?ng ð? th? v?i V ð?nh

    cout << "Nhap cac canh(u,v, trong so):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight; // Khai báo các bi?n cho ð?nh ð?u, ð?nh cu?i và tr?ng s?
        cin >> u >> v >> weight; // Nh?p các giá tr?
g.addEdge(u, v, weight); // Thêm c?nh vào ð? th?
    }

    int src; // Khai báo bi?n cho ð?nh ngu?n
    cout << "Nhap dinh nguon: ";
    cin >> src; // Nh?p ð?nh ngu?n

    g.bellmanFord(src); // G?i phýõng th?c bellmanFord ð? t?m ðý?ng ði ng?n nh?t t? ð?nh ngu?n

    return 0; // K?t thúc hàm main
}
