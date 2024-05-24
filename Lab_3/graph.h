#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <iostream>

const int INF = 1e9;
using namespace std;
template<typename Vertex, typename Distance>
class Graph {
    struct Edge {
        Vertex from;
        Vertex to;
        Distance distance;
    };
private:
    unordered_map<Vertex, vector<Edge>> adj_list;

public:
    bool has_vertex(const Vertex& v) const {
        return adj_list.find(v) != adj_list.end();
    }

    void add_vertex(const Vertex& v) {
        adj_list[v];
    }

    bool remove_vertex(const Vertex& v) {
        if (adj_list.erase(v)) {
            for (auto& [key, edges] : adj_list) {
                for (auto& edge : edges) {
                    if (edge.to == v)
                        remove_edge(edge.from, v);
                }
            }
            return true;
        }
        return false;
    }

    vector<Vertex> vertices() const {
        vector<Vertex> v_list;
        for (const auto& tmp : adj_list) {
            v_list.push_back(tmp.first);
        }
        return v_list;
    }

    void add_edge(const Vertex& from, const Vertex& to, const Distance& d) {
        add_vertex(from);
        add_vertex(to);
        adj_list[from].push_back({ from, to, d });
    }

    bool remove_edge(const Vertex& from, const Vertex& to) {
        if (!has_vertex(from) || !has_vertex(to)) return false;
        auto& edges = adj_list[from];
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            if (it->to == to) {
                it = edges.erase(it); 
            }
        }
        return false;
    }

    bool remove_edge(const Edge& e) {
        if (!has_vertex(e.from) || !has_vertex(e.to)) return false;
        auto& edges = adj_list[e.from];
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            if (it->to == e.to && e.distance == it->distance) {
                it = edges.erase(it);
            }
        }
        return false;
    }

    bool has_edge(const Vertex& from, const Vertex& to) const {
        if (!has_vertex(from)) return false;
        vector<Edge> edges = adj_list.at(from);
        for (auto& edge : edges) {
            if (edge.to == to)
                return true;
        }
        return false;
    }

    bool has_edge(const Edge& e) const {
        if (!has_vertex(e.from)) return false;
        vector<Edge> edges = adj_list.at(e.from);
        for (auto& edge : edges) {
            if (edge.to == e.to && e.distance == edge->distance)
                return true;
        }
        return false;
    }

    vector<Edge> edges(const Vertex& vertex) const {
        if (!has_vertex(vertex)) return {};
        return adj_list.at(vertex);
    }

    vector<Edge> shortest_path(const Vertex& from, const Vertex& to) const {
        if (!has_vertex(from) || !has_vertex(to)) return {};

        unordered_map<Vertex, Distance> distances;
        unordered_map<Vertex, Vertex> previous;
        priority_queue<pair<Distance, Vertex>,
            vector<pair<Distance, Vertex>>,
            greater<>> Q;

        for (const auto& tmp : adj_list) {
            distances[tmp.first] = INF;
        }
        distances[from] = 0;
        Q.emplace(0, from);

        while (!Q.empty()) {
            pair<Distance, Vertex> p = Q.top();
            Q.pop();
            Vertex u = p.second;
            if (u == to) break;
            for ( const Edge& edge : adj_list.at(u)) {
                if (edge.distance < 0)
                    throw out_of_range("The distance needs to be positive")
                Distance new_distace = distances[u] + edge.distance;
                if (new_distace < distances[edge.to]) {
                    distances[edge.to] = new_distace;
                    previous[edge.to] = u;
                    if(new_distace<0)
                        throw out_of_range("The distance needs to be positive")
                    Q.emplace(new_distace, edge.to);
                }
            }
        }

        vector<Edge> path;
        for (Vertex at = to; at != from; at = previous[at]) {
            Vertex prev = previous[at];
            path.push_back({ prev, at});
        }
        reverse(path.begin(), path.end());
        return path;
    }

    vector<Vertex> walk(const Vertex& start_vertex) const {
        vector<Vertex> visited;
        if (!has_vertex(start_vertex)) return visited;

        queue<Vertex> q;
        q.push(start_vertex);
        while (!q.empty()) {
            Vertex current = q.front();
            q.pop();
            visited.push_back(current);
            for (const auto& edge : adj_list.at(current)) {
                if (find(visited.begin(), visited.end(),edge.to) == visited.end()) {
                    q.push(edge.to);
                }
            }
        }
        return visited;
    }

    //Дополнительные задания
    void walk(const Vertex& start_vertex, function<void(const Vertex&)> action) const {
        if (!has_vertex(start_vertex)) return;

        queue<Vertex> q;
        set<Vertex> visited_set;

        q.push(start_vertex);
        visited_set.insert(start_vertex);

        while (!q.empty()) {
            Vertex current = q.front();
            q.pop();
            action(current);

            for (const auto& edge : adj_list.at(current)) { 
                if (visited_set.find(edge.to) == visited_set.end()) {
                    q.push(edge.to);
                    visited_set.insert(edge.to);
                }
            }
        }
    }


};

