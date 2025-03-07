#include <iostream>
#include <stack>
using namespace std;

const int maxV = 100; // Gi?i h?n s? ð?nh t?i ða

struct DOTHI {
    int nV;            // S? ð?nh c?a ð? th?
    int mtke[maxV][maxV]; // Ma tr?n k? c?a ð? th?
};

// Hàm DFS
void DFS(DOTHI g, int s) { // s là ð?nh xu?t phát
    int danhdau[maxV];     // M?ng ðánh d?u các ð?nh ð? ðý?c duy?t
    stack<int> st;         // Ngãn x?p (stack)

    // Kh?i t?o: t?t c? các ð?nh ð?u chýa ðý?c xét
    for (int i = 1; i <= g.nV; i++) {
        danhdau[i] = 0;
    }

    // Ðýa ð?nh xu?t phát vào ngãn x?p
    st.push(s);

    // Th?c hi?n duy?t DFS
    while (!st.empty()) {
        int v = st.top(); // L?y ð?nh ? ð?nh ngãn x?p
        st.pop();         // Lo?i b? ð?nh kh?i ngãn x?p

        if (danhdau[v] == 0) { // N?u ð?nh chýa ðý?c xét
            cout << v << " ";  // In ð?nh ra màn h?nh
            danhdau[v] = 1;   // Ðánh d?u ð?nh ð? ðý?c xét

            // Ðýa các ð?nh k? c?a v vào ngãn x?p (ngý?c th? t?)
            for (int i = g.nV; i >= 1; i--) {
                if (!danhdau[i] && g.mtke[v][i] != 0) {
                    st.push(i);
                }
            }
        }
    }
}

// Hàm chính
int main() {
    DOTHI g;

    // Nh?p s? ð?nh và ma tr?n k? c?a ð? th?
    cout << "Nhap so dinh cua do thi: ";
    cin >> g.nV;
    cout << "Nhap ma tran ke cua do thi:\n";
    for (int i = 1; i <= g.nV; i++) {
        for (int j = 1; j <= g.nV; j++) {
            cin >> g.mtke[i][j];
        }
    }

    // Nh?p ð?nh xu?t phát
    int s;
    cout << "Nhap dinh xuat phat: ";
    cin >> s;

    // G?i hàm DFS
    cout << "Ket qua duyet DFS: ";
    DFS(g, s);

    return 0;
}
