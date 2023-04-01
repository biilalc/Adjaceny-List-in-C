#include "graf.h"

void read_graph_file(const char *file_name, Graph *graph) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        printf("Hata: Dosya açılamadı!\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int src, dest;
        char city_name[50];
        char *token = strtok(line, "->\n");

        sscanf(token, "%[^/]/%d", city_name, &src);
        token = strtok(NULL, "->\n");
        while (token) {
            sscanf(token, "%[^/]/%d", city_name, &dest);
            add_edge(graph, src, dest, city_name);
            token = strtok(NULL, "->\n");
        }
    }
    fclose(file);
}

Graph *create_graph(int num_vertices) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    if(!graph)
    {
        printf("Hata: Hafızada Yer Tahsil Edilemedi!\n");
        return NULL;
    }
    graph->num_vertices = num_vertices;

    graph->adj_list = (Node **) malloc(num_vertices * sizeof(Node *));
    if(!graph->adj_list)
    {
        printf("Hata: Hafızada Yer Tahsil Edilemedi!\n");
        return NULL;
    }
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = '\0';
    }
    return graph;
}

void add_edge(Graph *graph, int src, int dest, char *city_name) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->city_name, city_name);
    new_node->city_plate = dest;
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;
}

void print_adj_list(Graph *graph) {
    for (int i = 1; i < graph->num_vertices; i++) {
        Node *temp = graph->adj_list[i];
        printf("%d Plakalı Şehirden Gidilebilecek Yerler : ", i);
        while (temp) {
            printf("%s/%d -> ", temp->city_name, temp->city_plate);
            temp = temp->next;
        }
        printf("null\n");
    }
}

int find_in_degree(Graph *graph, int city_plate) {
    int count = 0;
    for (int i = 0; i < graph->num_vertices; i++) {
        Node *temp = graph->adj_list[i];
        while (temp) {
            if (temp->city_plate == city_plate) {
                count++;
            }
            temp = temp->next;
        }
    }
    return count;
}

int find_out_degree(Graph *graph, int city_plate) {
    int count = 0;
    Node *temp = graph->adj_list[city_plate];
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int count_edges(Graph *graph) {
    int count = 0;
    for (int i = 0; i < graph->num_vertices; i++) {
        Node *temp = graph->adj_list[i];
        while (temp) {
            count++;
            temp = temp->next;
        }
    }
    return count;
}
void reachable_cities(Graph *graph, int city_plate) {
    Node *temp = graph->adj_list[city_plate];
    printf("%d Plakalı Şehirden Şu Şehir(ler)e Gidilebilir :\n", city_plate);
    while (temp) {
        printf("%s/%d\n", temp->city_name, temp->city_plate);
        temp = temp->next;
    }
    printf("\n");
}

void cities_reaching(Graph *graph, int city_plate) {
    printf("%d Plakalı Şehre Şu Şehir(ler)den Gelinmiştir :\n", city_plate);
    for (int i = 0; i < graph->num_vertices; i++) {
        Node *temp = graph->adj_list[i];
        while (temp) {
            int flag = 0;
            if (temp->city_plate == city_plate) {
                printf("%s/%d\n", temp->city_name, city_plate);
            }
            temp = temp->next;
        }
    }
}
