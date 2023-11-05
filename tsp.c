#include <stdio.h>

#define MAX 999 // Assuming this is a large value representing infinity
#define V 4
int tsp_g[V][V] = {    { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };

int visited[V]; // To keep track of visited cities
int n = V; // Number of cities
int cost = 0;

    void travellingsalesman(int c) {
        int k, adj_vertex = MAX;
        int min = MAX;
    
        visited[c] = 1;
    
        //  printf("%d ", c + 1);


        printf("\n min 1: %d, ",min);   
        for (k = 0; k < n; k++) {
            if (tsp_g[c][k] != 0 && visited[k] == 0) {
                if (tsp_g[c][k] < min) {
                    min = tsp_g[c][k];
                    adj_vertex = k;
        printf("\n min 2: %d, ",min);   

                }
            }
        }
        
        if (min != MAX) {
            cost = cost + min;
        }
        
        if (adj_vertex == MAX) {
            adj_vertex = 0;
            printf("%d", adj_vertex + 1);
            cost = cost + tsp_g[c][adj_vertex];
            return;
        }
        
        travellingsalesman(adj_vertex);
    }

    int main() {
        int i, j;
        for (i = 0; i < n; i++) {
            visited[i] = 0;
        }
        // printf("Shortest Path: ");
        travellingsalesman(0);
        printf("\nMinimum Cost: %d\n", cost);
        return 0;
    }
