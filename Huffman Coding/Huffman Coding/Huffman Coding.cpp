#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char ch;
    int num;
    Node* L;
    Node* R;
    Node(char c, int n) {
        ch = c;
        num = n;
        L = R = nullptr;
    }
};

struct cmp {
    bool operator()(Node* A, Node* B) {
        return A->num > B->num;
    }
};

void pre(Node* root, string temp, vector<string>& out) {
    if (!root) return;

    if (!root->L && !root->R) {
        out.push_back(temp);
        return;
    }

    pre(root->L, temp + "0", out);
    pre(root->R, temp + "1", out);
}

int main() {
    string S = "abcdef";
    int arr[] = { 5, 9, 12, 13, 16, 45 };
    int N = S.size();

    priority_queue<Node*, vector<Node*>, cmp> Q;

    for (int I = 0; I < N; I++) {
        Q.push(new Node(S[I], arr[I]));
    }

    while (Q.size() > 1) {
        Node* X = Q.top(); Q.pop();
        Node* Y = Q.top(); Q.pop();

        Node* Z = new Node('$', X->num + Y->num);
        Z->L = X;
        Z->R = Y;

        Q.push(Z);
    }

    vector<string> V;
    pre(Q.top(), "", V);

    for (auto& c : V) cout << c << "   ";
    cout << endl;

    return 0;
}
