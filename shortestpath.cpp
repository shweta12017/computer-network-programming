#include <iostream>
#include <climits>
using namespace std;

#define V 6

void dijkstra(int graph[V][V], int src) //Store costs bet vertices and src means source vertex
{
    int dist[V];     // store shortest distance to vertex
    bool visited[V];   // check that vertex is checked or not

    for (int i = 0; i < V; i++)    // initialize the distance
    {                                 
        dist[i] = INT_MAX;   // at starting distance of all vertices is infinite 
        visited[i] = false;     //suppose vertices are unvisited
    }

    dist[src] = 0;   // source distance is 0

    for (int count = 0; count < V - 1; count++)   //choose shortest distance vertex
    {
        int minDist = INT_MAX;  //store  shortest distance
        int u = -1;   //no any vertex choose

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nShortest distances from " << char('A' + src) << ":\n";

    for (int i = 0; i < V; i++)
    {
        cout << char('A' + i) << " = ";

        if (dist[i] == INT_MAX)
            cout << "Unreachable";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main()
{
    int graph[V][V] = {0};
    char u, v;
    int cost, edges;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges and costs (example: A B 4):\n";

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> cost;

        if (u >= 'a' && u <= 'f') u -= 32;
        if (v >= 'a' && v <= 'f') v -= 32;

        if (u < 'A' || u > 'F' ||
            v < 'A' || v > 'F' ||
            cost <= 0)
        {
            cout << "Invalid input!\n";
            return 1;
        }

        int a = u - 'A';
        int b = v - 'A';

        graph[a][b] = cost;
        graph[b][a] = cost;
    }

    char source;
    cout << "Enter source vertex (A-F): ";
    cin >> source;

    if (source >= 'a' && source <= 'f')
        source -= 32;

    if (source < 'A' || source > 'F')
    {
        cout << "Invalid source vertex!\n";
        return 1;
    }

    dijkstra(graph, source - 'A');

    return 0;
}

/*Enter number of edges: 9
Enter edges and costs (example: A B 4):
A B 4
A C 5
B C 11
B D 9
B E 7
C E 3
D E 13
D F 2
E F 6
Enter source vertex (A-F): A

Shortest distances from A:
A = 0
B = 4
C = 5
D = 13
E = 8
F = 14*/