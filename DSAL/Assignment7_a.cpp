#include <bits/stdc++.h>
using namespace std;
#define v 5

void findPrims(int g[v][v]) {

    int visited[v];

    for(int i = 0; i < v; i++) {
        visited[i] = 0;
    }
    visited[0] = 1;
    int no_of_edges = 0;
    while(no_of_edges != v-1) {
        int min = INT_MAX;
        int x = 0;
        int y = 0;
        for(int i = 0; i < v; i++) {
            if(visited[i]) {
                for(int j = 0; j < v; j++) {
                    if(visited[j] == 0 && g[i][j] > 0) {
                        if(min > g[i][j]) {
                            min = g[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        no_of_edges++;
        visited[y] = 1;
        cout << "The edge is between "<<x << " - "<<y << " and cost is "<<min << endl;
    }
}

int main() {

    int graph[v][v] = {
      { INT_MAX, 12, INT_MAX, 25, INT_MAX },
      { 12, INT_MAX, 11, 8, 12 },
      { INT_MAX, 11, INT_MAX, INT_MAX, 17 },
      { 25, 8, INT_MAX, INT_MAX, 15 },
      { INT_MAX, 12, 17, 15, INT_MAX },
   };

   findPrims(graph);
   return 0;

}