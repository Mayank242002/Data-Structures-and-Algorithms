#include <stdio.h>
#include <stdlib.h>
 
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};
 
struct AdjList
{
    struct AdjListNode *head;
};
 
struct Graph
{
    int V;
    struct AdjList* array;
};
 
struct Graph* createGraph(int V)
{
    struct Graph* graph =
        (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array =
      (struct AdjList*) malloc(V * sizeof(struct AdjList));
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 

void addEdge(struct Graph* graph, int src, int dest,int weight)
{
  struct AdjListNode* check = NULL;
  struct AdjListNode* newNode =(struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight=weight;
    newNode->next = NULL;
   
  if(graph->array[src].head == NULL)
  {
    graph->array[src].head = newNode;
  }
  else
  { 
    check = graph->array[src].head;
    while(check->next != NULL)
    {
      check = check->next;
    }
    check->next = newNode;
  }

  newNode =(struct AdjListNode*) malloc(sizeof(struct AdjListNode));
  newNode->dest = src;
  newNode->weight=weight;
  newNode->next = NULL;
  if(graph->array[dest].head == NULL)
  {
    graph->array[dest].head = newNode;
  }
  else
  {
    check = graph->array[dest].head;
    while(check->next != NULL)
    {
      check = check->next;
    }
    check->next = newNode;
  }
}
 
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d|%d", pCrawl->dest,pCrawl->weight);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
 

int main()
{
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1,5);
    addEdge(graph, 0, 4,4);
    addEdge(graph, 1, 2,3);
    addEdge(graph, 1, 3,2);
    addEdge(graph, 1, 4,1);
    addEdge(graph, 2, 3,2);
    addEdge(graph, 3, 4,1);
    printGraph(graph);
}