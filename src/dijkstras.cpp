// dijsktras.cpp
// Michael McRoskey

#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// FUNCTIONS ------------------------------------------------------
int to_char(int array_index){ return array_index;}
int to_int(int character){ return character; }

struct Edge{
    int cost;
    int name;
    int prev;
};

struct EdgeCost{
    bool operator()(const Edge& lhs, const Edge& rhs) const{
        return lhs.cost > rhs.cost;
    }
};

int f(int i, int j, int M) {
    return i * M + j;
}

pair<int,int> printIndex(int Linear, int M) {
    return {(Linear / M), (Linear % M) - 1};
}


//    TILES_N
//    TILE_NAME_0 TILE_COST_0
//    ...
//    TILE_NAME_N-1   TILE_COST_N-1
//
//    M N
//    TILE_0_0    ...
//    ...
//
//    RUNNER_START_ROW RUNNER_START_COL
//    RUNNER_END_ROW   RUNNER_END_COL


// MAIN EXECUTION -------------------------------------------------
int main(int argc, char *argv[]) {
    
    int TILES_N;
    
    // PROCESS ---------------------------------------------------
    
    cin >> TILES_N;
    map<char, int> m;
    char c;
    int a;
    
    for (int i=0; i<TILES_N; i++){
        cin >> c >> a;
        m[c] = a;
    }
    
    int M, N;
    cin >> M >> N;
        
    vector< map<int, int> > g(M*N);
    vector< vector<int> > forest(N, vector<int> (M));
    
    // LOAD VERTICES ------------------------------------------
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            cin >> c;
            forest[i][j] = m[c];
        }
    }
    
//    for (int i=0; i<M; i++){
//        for (int j=0; j<N; j++){
//            cout << forest[i][j];
//        }
//        cout << endl;
//    }
    
    
    int curr;
    for(int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            	curr = f(i,j,M);
            cout << curr << " ";
            	if(i!=0) g[curr][f(i-1, j  , M)] = forest[i-1][j];
            	if(j!=0) g[curr][f(i  , j-1, M)] = forest[i][j-1];
            	if(i!=N) g[curr][f(i+1, j  , M)] = forest[i+1][j];
            	if(j!=M) g[curr][f(i  , j+1, M)] = forest[i][j+1];
        }
        cout << endl;
     }

    int RUNNER_START_ROW, RUNNER_START_COL;
    int RUNNER_END_ROW, RUNNER_END_COL;
    
    cin >> RUNNER_START_ROW >> RUNNER_START_COL;
    cin >> RUNNER_END_ROW >> RUNNER_END_COL;
    
    int total_weight = 0;
    
    priority_queue<int, std::vector<Edge>, EdgeCost> frontier;
    map<int, int> marked;
    
    // STARTING NODE -----------------------------------------
    frontier.push({0, 1, 1});
    
    // PRIM ALGORITHM -----------------------------------------
//    while (!frontier.empty()){
//        Edge v = frontier.top();
//        frontier.pop();
//    
//        if (marked.find(v.name) != marked.end())
//            continue;
//       
//        marked[v.name] = v.prev;
//        total_weight += v.cost;
//        
//        for (auto u : g[to_int(v.name)])
//            frontier.push({u.second + v.cost, u.first, v.name});
//    }
//       
//    marked.erase(marked.find('A'));
//    
//    // SORT RESULTS -------------------------------------------
//    vector<pair<char, char>> results;
//    for (auto key : marked){
//        char A = key.first, B = key.second;
//        if (A<B){
//            results.push_back({A,B});
//        } else {
//            results.push_back({B,A});
//        }
//    }
//        
//    sort(results.begin(), results.end());
//    
//    // OUTPUT RESULT ------------------------------------------
//    cout << total_weight << endl;
//    
//    for (auto i : results)
//        cout << to_int(i.first) << " " << to_int(i.second) << endl;
    
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
