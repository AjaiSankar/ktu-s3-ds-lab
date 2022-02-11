#include <stdio.h>
#include <stdbool.h>

#define V 11
#define stackSize  100
int stack[stackSize];
int top = -1;

void stackPush(int);
int stackPop();
bool stackEmpty();

void depthFirstTraversal(int graph[][V], int u)
{
    int visited[V] = {0}; // to keep track of visited nodes
    stackPush(u);         // push starting node into the stack
    int curr_node;
    while (!stackEmpty())
    {
        curr_node = stackPop();      // get a node from top of the stack
        if (visited[curr_node] == 0) // if it is not visited
        {
            printf("%d -> ", curr_node); // print its value
            visited[curr_node] = 1;      // and mark as visited
        }
        for (int i = 0; i < V; i++)                          // for every node in the graph
            if (graph[curr_node][i] == 1 && visited[i] == 0) // if it is adjacent and not visited
                stackPush(i);                                // push it into the stack
    }
}

void addEdge(int graph[][V], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void stackPush(int data)
{
    if (top == stackSize - 1)
        return;

    stack[++top] = data;
}

int stackPop()
{
    if (stackEmpty())
        return -1;
    return stack[top--];
}

bool stackEmpty()
{
    return top == -1;
}

int main()
{
    int graph[V][V] = {0}; // initiliazing Adjacency Matrix

    addEdge(graph, 1, 2); // adding edges between graph nodes
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 7);
    addEdge(graph, 2, 8);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 10);
    addEdge(graph, 3, 9);
    addEdge(graph, 5, 6);
    addEdge(graph, 5, 7);
    addEdge(graph, 5, 8);
    addEdge(graph, 7, 8);


    printf("\nDepth first traversal from node 1\n");
    depthFirstTraversal(graph, 1);

    printf("\n");
    return 0;
}