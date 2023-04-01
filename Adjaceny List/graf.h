#ifndef GRAF_H
#define GRAF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char city_name[50];
    int city_plate;
    struct Node *next;
} Node;

typedef struct Graph {
    int num_vertices;
    Node **adj_list;
} Graph;

Graph *create_graph(int num_vertices);
void add_edge(Graph *graph, int src, int dest, char *city_name);
void print_adj_list(Graph *graph);
int find_in_degree(Graph *graph, int city_plate);
int find_out_degree(Graph *graph, int city_plate);
int count_edges(Graph *graph);
void reachable_cities(Graph *graph, int city_plate);
void cities_reaching(Graph *graph, int city_plate);
void read_graph_file(const char *file_name, Graph *graph);

#endif