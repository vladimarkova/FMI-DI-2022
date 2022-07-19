#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> graph;

// graph[0] ---> vertex 0 neghbs
// graph[0][3] ---> int (negbh)

void DFS() {
    visited
    for (int i = 0; i < graph.size(); i++) {
        if (!visited) {
            dfs-rec(graph[i], visited)
        }
    }
}

dfs(rec, int v, visited&, graph) {
    v stava visited
    std::cout << stoinost na v to si e st-st
    for (decata na v) {
        if (dete ne e visited) {
            dfs-rec sus dete
        }
    }
}

void DFS-all-starts() {
    visited
    for (int i = 0; i < graph.size(); i++) {
        // clear visited ??? no
        dfs-all(graph[i], visited)
}

dfs-all(rec, int v, visited&, graph) {
    if (v ne e visited) {
        v stava visited
    }
    for (deca na v) {
        if (dete ne e visited) {
            dfs-all(dete na v)
        }
    }
}