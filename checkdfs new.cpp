#include <iostream>
#include <stack>
using namespace std;

const int maxV = 100; // Gi?i h?n s? �?nh t?i �a

struct DOTHI {
    int nV;            // S? �?nh c?a �? th?
    int mtke[maxV][maxV]; // Ma tr?n k? c?a �? th?
};

// H�m DFS
void DFS(DOTHI g, int s) { // s l� �?nh xu?t ph�t
    int danhdau[maxV];     // M?ng ��nh d?u c�c �?nh �? ��?c duy?t
    stack<int> st;         // Ng�n x?p (stack)

    // Kh?i t?o: t?t c? c�c �?nh �?u ch�a ��?c x�t
    for (int i = 1; i <= g.nV; i++) {
        danhdau[i] = 0;
    }

    // ��a �?nh xu?t ph�t v�o ng�n x?p
    st.push(s);

    // Th?c hi?n duy?t DFS
    while (!st.empty()) {
        int v = st.top(); // L?y �?nh ? �?nh ng�n x?p
        st.pop();         // Lo?i b? �?nh kh?i ng�n x?p

        if (danhdau[v] == 0) { // N?u �?nh ch�a ��?c x�t
            cout << v << " ";  // In �?nh ra m�n h?nh
            danhdau[v] = 1;   // ��nh d?u �?nh �? ��?c x�t

            // ��a c�c �?nh k? c?a v v�o ng�n x?p (ng�?c th? t?)
            for (int i = g.nV; i >= 1; i--) {
                if (!danhdau[i] && g.mtke[v][i] != 0) {
                    st.push(i);
                }
            }
        }
    }
}

// H�m ch�nh
int main() {
    DOTHI g;

    // Nh?p s? �?nh v� ma tr?n k? c?a �? th?
    cout << "Nhap so dinh cua do thi: ";
    cin >> g.nV;
    cout << "Nhap ma tran ke cua do thi:\n";
    for (int i = 1; i <= g.nV; i++) {
        for (int j = 1; j <= g.nV; j++) {
            cin >> g.mtke[i][j];
        }
    }

    // Nh?p �?nh xu?t ph�t
    int s;
    cout << "Nhap dinh xuat phat: ";
    cin >> s;

    // G?i h�m DFS
    cout << "Ket qua duyet DFS: ";
    DFS(g, s);

    return 0;
}
