#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Node {
public:
    int n;
    Node *left, *right;

    Node(int n) {
        this->n=n;
        left = nullptr;
        right = nullptr;
    }
};

struct CompareNodes {
    bool operator()(Node* a, Node* b) {
        return a->n > b->n;
    }
};

void preOrder(Node* root, vector<string>& ans, string curr)
{
        if (root == nullptr)
        return;

        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(curr);
            return;
        }

        preOrder(root->left, ans, curr + '0');
        preOrder(root->right, ans, curr + '1');
 }
 vector<string> encode(string s, int f[], int N)
 {
        priority_queue<Node*, vector<Node*>, CompareNodes> pq;
        for (int i = 0; i < N; i++)
        {
            Node* newNode=new Node(f[i]);
            pq.push(newNode);
        }

        while (pq.size() >= 2)
        {
            Node* l = pq.top();
            pq.pop();
            Node* r = pq.top();
            pq.pop();
            Node* newNode = new Node(l->n + r->n);
            newNode->left = l;
            newNode->right = r;
            pq.push(newNode);
        }

        Node* root = pq.top();
        vector<string> ans;
        preOrder(root, ans, "");
        return ans;
}
int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    int n = s.length();
    int f[n];
    cout << "Enter the frequency: ";
    for (int i = 0; i < n; i++)
        cin >> f[i];

    vector<string> ans = encode(s, f, n);

    cout << "Huffman coding:" << endl;
    for (int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
