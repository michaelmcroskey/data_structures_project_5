// dijsktras.cpp
// Michael McRoskey

#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// FUNCTIONS ------------------------------------------------------
char to_char(int array_index){ return (char)(array_index+65);}
int to_int(char character){ return (int)(character-65); }

struct Edge{
    int cost;
    char name;
    char prev;
};

struct EdgeCost{
    bool operator()(const Edge& lhs, const Edge& rhs) const{
        return lhs.cost > rhs.cost;
    }
};


TILES_N
TILE_NAME_0 TILE_COST_0
...
TILE_NAME_N-1   TILE_COST_N-1

MAP_ROWS MAP_COLUMNS
TILE_0_0    ...
...

RUNNER_START_ROW RUNNER_START_COL
RUNNER_END_ROW   RUNNER_END_COL


// MAIN EXECUTION -------------------------------------------------
int main(int argc, char *argv[]) {
    
    bool first_pass = true;
    int TILES_N;
    
    // EACH GRAPH -------------------------------------------------
    while (cin >> TILES_N){
        
        map<char, int> g[26];
        
        // LOAD VERTICES ------------------------------------------
        for (int i=0; i<TILES_N; i++){
            for (int j=0; j<TILES_N; j++){
                int cost;
                cin >> cost;
                if (cost>0){
                    g[i][to_char(j)] = cost;
                    g[j][to_char(i)] = cost;
                }
            }
        }
        
        priority_queue<int, std::vector<Edge>, EdgeCost> frontier;
        map<char, char> marked;
        
        // STARTING NODE -----------------------------------------
        frontier.push({0, 'A', 'A'});
        
        // PRIM ALGORITHM -----------------------------------------
        while (!frontier.empty()){
            Edge v = frontier.top();
            frontier.pop();
        
            if (marked.find(v.name) != marked.end())
                continue;
           
            marked[v.name] = v.prev;
            
            for (auto u : g[to_int(v.name)])
                frontier.push({u.second + v.cost, u.first, v.name});
        }
           
        marked.erase(marked.find('A'));
        
        // SORT RESULTS -------------------------------------------
        vector<pair<char, char>> results;
        for (auto key : marked){
            char A = key.first, B = key.second;
            if (A<B){
                results.push_back({A,B});
            } else {
                results.push_back({B,A});
            }
        }
            
        sort(results.begin(), results.end());
        
        // OUTPUT RESULT ------------------------------------------
        if (first_pass){
            first_pass = false;
        } else {
            cout << endl;
        }
        
        for (auto i : results)
            cout << i.first << i.second << endl;
    }
    
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
