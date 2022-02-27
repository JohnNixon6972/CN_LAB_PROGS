#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long int>

void BellmanFord(int network_lanes[100][3], int routers, int connections, int src_router, int final_table[20][20])
{
    int dist[routers];
    for (int i = 0; i < routers; i++)
    {
        dist[routers] = INT_MAX;
    }

    dist[src_router] = 0;

    for (int i = 0; i < routers - 1; i++)
    {
        for (int j = 0; j < connections; j++)
        {
            int intermediate_router, destination_router, dest_hopcost;
            intermediate_router = network_lanes[j][0];
            destination_router = network_lanes[j][1];
            dest_hopcost = network_lanes[j][2];

            if (dist[intermediate_router] != INT_MAX && dist[intermediate_router] + dest_hopcost < dist[destination_router])
            {
                dist[destination_router] = dist[intermediate_router] + dest_hopcost;
            }

            intermediate_router = network_lanes[j][1];
            destination_router = network_lanes[j][0];
            dest_hopcost = network_lanes[j][2];

            if (dist[intermediate_router] != INT_MAX && dist[intermediate_router] + dest_hopcost < dist[destination_router])
            {
                dist[destination_router] = dist[intermediate_router] + dest_hopcost;
            }
        }
    }

    cout << "Router Distance from Source-router " << src_router << endl;
    cout << "Source\tDest\tHop_Cost" << endl;

    for (int i = 0; i < routers; i++)
    {
        cout << src_router << "\t\t" << i << "\t\t" << dist[i] << endl;
        final_table[src_router][i] = min(final_table[src_router][i], dist[i]);
        final_table[i][src_router] = min(final_table[i][src_router], dist[i]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);

    int routers, connections;

    cout << "Enter number of routers :: ";
    cin >> routers;

    cout << "\nEnter number of connections :: ";
    cin >> connections;

    int network_lanes[100][3];
    int final_table[20][20];

    for (int i = 0; i < connections; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            network_lanes[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < routers; i++)
    {
        for (int j = 0; j < routers; j++)
        {
            final_table[i][j] = INT_MAX;
        }
    }

    cout << "Enter " << connections << " details in (source_router,destination_router,hop_cost) format :: " << endl;

    int src, dest, hop_cost;

    for (int i = 0; i < connections; i++)
    {
        cin >> src >> dest >> hop_cost;

        network_lanes[i][0] = src;
        network_lanes[i][1] = dest;
        network_lanes[i][2] = hop_cost;
    }

    for (int src_router = 0; src_router < routers; src_router++)
    {

        cout << "Router Table for Router " << src_router << " :: " << endl;
        BellmanFord(network_lanes, routers, connections, src_router, final_table);
    }

    cout << "Complete Router table for the network_lanes :: " << endl;
    for (int i = 0; i < routers; i++)
    {
        for (int j = 0; j < routers; j++)
        {
            cout << final_table[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}