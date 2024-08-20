
#include <cstddef>
#include <cstdlib>
#include <iostream>
using namespace std;
class Node {
private:
  int dt;

public:
  int getDt() { return dt; }
  Node *getLeft() { return left; }
  Node *getRight() { return right; }
  Node *left;
  Node *right;

  void changeDt(int data) { dt = data; }
  void changeLeft(Node *nextNode) { left = nextNode; }
  Node(int dta) { this->dt = dta; }
  void changeRight(Node *nextNode) { right = nextNode; }
  void insert(int data) {
    if (dt == data) {
      cout << "ERROR NODE ALREADY EXISTS";
      return;

    } else if (data < dt) {

      if (left == NULL) {

        left = new Node(data);
      } else {
        left->insert(data);
      }
    } else if (data > dt) {

      if (right == NULL) {

        right = new Node(data);
      } else {
        right->insert(data);
      }
    }
  }
  void inOrder() {
    cout << dt << "\n";
    if (left != NULL) {

      left->inOrder();
    }
    if (right != NULL) {

      right->inOrder();
    }
  }
  static Node *Remove(int data, Node *root) {

    if (root == nullptr) {

      return nullptr;
    } else if (root->dt > data) {

      root->left = Remove(data, root->left);
    } else if (root->dt < data) {

      root->right = Remove(data, root->right);
    } else {
      if (root->left == nullptr) {

        Node *temp = root->right;
        delete root;
        return temp;
      }

      else if (root->right == nullptr) {

        Node *temp = root->left;
        delete root;
        return temp;
      } else {
        Node *temp = root->right;
        while (temp->left != nullptr) {

          temp = temp->left;
        }
        root->dt = temp->dt;
        root->right = Remove(temp->dt, root->right);
      }
    }
    return root;
  }
  static int balanceFactor(Node *root) {
    int bf = 0;
    if (root->left == nullptr && root->right == nullptr) {
      return 0;

    } else if (root->left == nullptr && root->right != nullptr) {

      bf += 1 + balanceFactor(root->right);
    } else if (root->left != nullptr && root->right == nullptr) {

      bf += (-1 - balanceFactor(root->left));
    } else {
      bf = balanceFactor(root->right) - balanceFactor(root->left);
    }
    return bf;
  }
};

int main() {
  Node *home = new Node(3);

  int arr[] = {2, 4, 1, 5};
  for (int i = 0; i < 4; i++) {
    home->insert(arr[i]);
  }
  std::cout << Node::balanceFactor(home);
}
