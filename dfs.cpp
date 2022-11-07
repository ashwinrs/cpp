#include <iostream>
using namespace std;


struct Node {
  char value;
  Node* left;
  Node* right;
};

void traverseDFS(Node* node) {
  if (node == NULL) {
    return;
  }
  cout << node->value << " ";
  traverseDFS(node->left);
  traverseDFS(node->right);
}

int main() {
  Node C = {'C', NULL, NULL};
  Node D = {'D', NULL, NULL};
  Node E = {'E', NULL, NULL};
  Node B = {'B', &D, &E};
  Node A = {'A', &B, &C};
  traverseDFS(&A);
}

