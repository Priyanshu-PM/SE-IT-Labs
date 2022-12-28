#include<bits/stdc++.h>
using namespace std;
#define v 5

int findParent(int p[], int x) {

    if(p[x] == x) {
        return x;
    }
    return findParent(p, p[x]);
}

void makeUnion(int p[], int x, int y) {

    int a = findParent(p, x);
    int b = findParent(p, y);

    if(a == b) {
        return;
    }
    p[b] = a;
}

void findKruskals(int g[v][v]) {


    int parent[v];
    for(int i = 0; i < v; i++) {
        parent[i] = i;
    }
    int no_of_edges = 0;
    while(no_of_edges != v-1) {
        int min = INT_MAX;
        int x = 0;
        int y = 0;
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {

                if(findParent(parent, i) != findParent(parent, j) && g[i][j] != 0 && min > g[i][j]) {
                    min = g[i][j];
                    x = i;
                    y = j;
                }

            }
        }
        makeUnion(parent, x, y);
        no_of_edges++;
        cout << "The edge is between "<<x <<" - "<<y <<" and cost of the edge is : "<<min<<endl;;
    }

}

int main() {

    int graph[v][v] = {
        {0, 0, 3, 0, 0},
        {0, 0, 10, 4, 0},
        {3, 10, 0, 2, 6},
        {0, 4, 2, 0, 1},
        {0, 0, 6, 1, 0},
    };

    findKruskals(graph);
    return 0;

}