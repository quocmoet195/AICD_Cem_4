#include <iostream>
#include <vector>
#include <string>
#include "graph.h"

using namespace std;
void add_data(Graph<string, double>& graph) {
    graph.add_edge("A", "B", 1.5);
    graph.add_edge("A", "E", 5);
    graph.add_edge("B", "C", 1.2);
    graph.add_edge("B", "D", 2);
    graph.add_edge("C", "E", 2);
    graph.add_edge("D", "E", 1.1);
}

string find_furthest_vertex(const Graph<string, double>& graph) {
    string furthest_vertex;
    double max_distance = 0.0;

    for (const auto& vertex : graph.vertices()) {
        double total_distance = 0.0;
        size_t edge_count = 0;
        for (const auto& edge : graph.edges(vertex)) {
            total_distance += edge.distance;
            ++edge_count;
        }
        if (edge_count > 0) {
            double distance = total_distance / edge_count;
            if (distance > max_distance) {
                max_distance = distance;
                furthest_vertex = vertex;
            }
        }
    }
    return furthest_vertex;
}

int main() {
    Graph<string, double> graph;
    add_data(graph);

    cout << "Vertices in the graph: ";
    for (const auto& v : graph.vertices()) {
        cout << v << " ";
    }
    cout << "\n";

    cout << "Edges in the graph: \n";
    for (const auto& v : graph.vertices()) {
        for (const auto& e : graph.edges(v)) {
            cout << e.from << " -> " << e.to << " : " << e.distance << "\n";
        }
    }
    string start = "A";
    string end = "E";
    cout << "Shortest path from " << start << " to " << end << ": ";

    for (const auto& edge : graph.shortest_path(start, end)) {
        cout << edge.from << " -> " ;
    }
    cout << end <<"\n";


    vector<string> result_set = graph.walk("A");
    cout << "Breadth-first walk starting from A: ";
    for (const auto& v : result_set) {
        cout << v << " ";
    }
    cout << "\n";

    string furthest_vertex = find_furthest_vertex(graph);
    cout << "Node furthest from its direct neighbors: " << furthest_vertex << "\n";

    //Дополнительные задания
    vector<string> result;
    auto action = [&result](const string& vertex) {
        cout << vertex << "  ";
        result.push_back(vertex);
    };

    cout << "Breadth-first walk c function: ";
    graph.walk("B", action);
    cout << "\n";

    cout << "Get the vertices during the traversal: ";
    for (const auto& v : result) {
        cout << v << " ";
    }
    cout << "\n";


    return 0;
}
