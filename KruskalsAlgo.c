#include <stdio.h>
#include <limits.h>
#define I INT_MAX

int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

void union_sets(int u, int v) {
    if (set[u] < set[v]) {
        set[u] += set[v];
        set[v] = u;
    } else {
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u) {
    int x = u, v = 0;
    while (set[x] > 0) {
        x = set[x];
    }
    while (u != x) {
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

int edges[3][9] = {
    {1, 1, 2, 2, 3, 4, 4, 5, 5},
    {2, 6, 3, 7, 4, 5, 7, 6, 7},
    {25, 5, 12, 10, 8, 16, 14, 20, 18}
};

int included[9] = {0};
int t[2][6];

int main() {
    
    int i, j, k, u, v, min = I, n = 7, e = 9;
    int totalCost = 0; // Move totalCost declaration here
    
    i = 0;
    while (i < n - 1) {
        min = I;
        for (j = 0; j < e; j++) {
            if (included[j] == 0 && edges[2][j] < min) {
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }
        if (find(u) != find(v)) {
            t[0][i] = u;
            t[1][i] = v;
            union_sets(find(u), find(v));
            totalCost += min; // Add the weight of the current edge to totalCost
            i++;
        }
        included[k] = 1;
    }
    printf("The edges of the minimum spanning tree are:\n");
    for(i = 0; i < n - 1; i++) {
        printf("(%d , %d)\n", t[0][i], t[1][i]);
    }
    
    printf("Minimum Cost of Spanning Tree: %d", totalCost);

    return 0;
}