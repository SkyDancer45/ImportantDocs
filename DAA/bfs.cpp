#include <cstdlib>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct Node {
  string name;
  vector<struct Node> neighbors;
};
struct Graph {
  vector<struct Node> nodes;
  queue<struct Node> visitQueue;
  unordered_map<struct Node, bool> visited;
};
void addNode(string name, struct Graph *graph, vector<Node> neighbors) {
  struct Node *newNode = (struct Node *)malloc(sizeof(Node));
  newNode->neighbors = neighbors;
  newNode->name = name;
}

int main() { return 0; }
