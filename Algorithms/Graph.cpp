#include <iostream>
#include <vector>
#include <map>
#include <utility>
using std::cout;
using std::vector;
using std::map;
using std::pair;
using V = char;

enum Status {
    UNKNOWN,
    BOUNDARY,
    TREE
};

struct Edge {
    V start;
    V end;
    int weight;
    Edge(V _start = V(), V _end = V(), int _weight = 0) {
        start = _start;
        end = _end;
        weight = _weight;
    }
};

class Graph {
    vector<V> vertices;
    map<V, vector<Edge>> adjLists;

public:
    void addVertex(V v) {
        vertices.push_back(v);
        adjLists[v] = vector<Edge>();
    }

    void addEdge(V v1, V v2, int weight) {
        Edge edge1 = Edge(v1, v2, weight);
        Edge edge2 = Edge(v2, v1, weight);

        adjLists[v1].push_back(edge1);
        adjLists[v1].push_back(edge2);
    }

    Graph mst() {
        vector<V> treeVertices;
        V s = vertices[0];
        treeVertices.push_back(s);

        map<V, vector<Edge>> treeEdges;
        for (int i = 0; i < vertices.size(); i++) {
            treeEdges[vertices[i]] = vector<Edge>();
        }
        
        map<V, Status> statuses;
        for (int i = 0; i < vertices.size(); i++) {
            statuses[vertices[i]] = UNKNOWN;
        }
        statuses[s] = TREE;

        for (int i = 0; i < adjLists[s].size(); i++) {
            V neighbour = adjLists[s][i].end;
            statuses[neighbour] = BOUNDARY;
        }
        
        map<V, Edge> candidateEdges;

        while(treeVertices.size() <= vertices.size()) {
            V x = treeVertices[treeVertices.size() - 1];

            for (int i = 0; i < adjLists[x].size(); i++) {
                Edge edge = adjLists[x][i];
                V y = edge.end;
                if (statuses[y] == BOUNDARY) {
                    if (!candidateEdges.count(y) || edge.weight < candidateEdges[y].weight) {
                        candidateEdges[y] = edge;
                    }
                } 
                else if (statuses[y] == UNKNOWN) {
                    statuses[y] = BOUNDARY;
                    candidateEdges[y] = edge;
                }
            }
            Edge minCandidateEdge = Edge(V(), V(), 999999);
            for(pair<V, Edge> p : candidateEdges) {
                if (p.second.weight < minCandidateEdge.weight) {
                    minCandidateEdge = p.second;
                }
            }
            V newTreeVertex = minCandidateEdge.end;
            statuses[newTreeVertex] = TREE;
            treeVertices.push_back(newTreeVertex);
            treeEdges[minCandidateEdge.start].push_back(minCandidateEdge);
            treeEdges[minCandidateEdge.end].push_back(Edge(minCandidateEdge.end, minCandidateEdge.start, minCandidateEdge.weight));
            candidateEdges.erase(newTreeVertex);
        }

        Graph tree;
        tree.vertices = treeVertices;
        tree.adjLists = treeEdges;

        return tree;
    }

    void print() const {
        for (pair<V, vector<Edge>> p : adjLists) {
            cout << p.first << ": ";
            for (int i = 0; i < p.second.size(); i++) {
                cout << '(' << p.second[i].end << ',' << p.second[i].weight << ") ";
            }
            cout << '\n';
        }
    }
};

Graph createGraph() {
    Graph g;
    g.addVertex('a');
    g.addVertex('b');
    g.addVertex('c');
    g.addVertex('d');

    g.addVertex('u');
    g.addVertex('v');
    g.addVertex('w');
    g.addVertex('z');

    g.addVertex('p');
    g.addVertex('q');
    g.addVertex('r');

    g.addEdge('a', 'b', 1);
    g.addEdge('a', 'd', 2);
    g.addEdge('a', 'u', 4);
    g.addEdge('b', 'c', 1);
    
    g.addEdge('b', 'd', 3);
    g.addEdge('b', 'u', 5);
    g.addEdge('b', 'v', 2);
    g.addEdge('c', 'd', 1);

    g.addEdge('c', 'w', 6);
    g.addEdge('c', 'z', 5);
    g.addEdge('d', 'w', 5);
    g.addEdge('u', 'v', 1);

    g.addEdge('u', 'p', 5);
    g.addEdge('v', 'w', 4);
    g.addEdge('v', 'q', 5);
    g.addEdge('v', 'p', 2);

    g.addEdge('w', 'q', 2);
    g.addEdge('w', 'r', 5);
    g.addEdge('z', 'r', 2);

    return g;
}

int main() {
    Graph g = createGraph();
    Graph tree = g.mst();
    tree.print();

    return 0;
}