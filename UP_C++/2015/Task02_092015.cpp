#include <iostream>
#include <vector>
using std::cout;
using std::vector;

const int NUMBER_OF_VERTICES = 3;

class Graph {
    vector<int> adjLists[NUMBER_OF_VERTICES + 1];

    bool existsPath(int from, int to, bool* visited) const {
        if (from == to) {
            return true;
        }
        for (int i = 0; i < adjLists[from].size(); i++) {
            int neighbour = adjLists[from][i];
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                if (existsPath(neighbour, to, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    vector<int> getListOf(int v) const {
        return adjLists[v];
    }

    void addEdge(int from , int to) {
        adjLists[from].push_back(to);
    }

    bool existsPath(int from, int to) const {
        if (from <= 0 || from > NUMBER_OF_VERTICES || to <= 0 || to > NUMBER_OF_VERTICES) {
            return false;
        }
        bool visited[NUMBER_OF_VERTICES + 1] = { false };
        visited[from] = true;
        return existsPath(from , to, visited);
    }
};

bool isConnected(const Graph& g) {
    for (int i = 1; i <= NUMBER_OF_VERTICES - 1; i++) {
        for (int j = i + 1; j <= NUMBER_OF_VERTICES; j++) {
            if(!g.existsPath(i, j) && !g.existsPath(j, i)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "isConnected: " << isConnected(g) << '\n';

    return 0;
}