// dijsktras.cpp
// Michael McRoskey

#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>

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

// returns index of , based on linear index
pair<int,int> index(int Linear, int M) {
    return {(Linear / M), (Linear % M) };
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
    
    /* for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            cout << forest[i][j] << " ";
        }
        cout << endl;
	}*/
    
    
    int curr;
    for(int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            	curr = f(i,j,M);
            	if(i!=0)   g[curr][f(i-1, j  , M)] = forest[i-1][j];
            	if(j!=0)   g[curr][f(i  , j-1, M)] = forest[i][j-1];
            	if(i!=N-1) g[curr][f(i+1, j  , M)] = forest[i+1][j];
            	if(j!=M-1) g[curr][f(i  , j+1, M)] = forest[i][j+1];
        }
     }

    int r1, c1;
    int r2, c2;
    
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    
    int total_weight = 0;
    
    priority_queue<int, std::vector<Edge>, EdgeCost> frontier;
    map<int, int> marked;
    
    // STARTING NODE -----------------------------------------
    frontier.push({0, f(r1,c1,M), f(r1,c1,M)});
    
    // DIKJSTRAS ALGORITHM -----------------------------------
    while (!frontier.empty()){
        Edge v = frontier.top();
        frontier.pop();
        
        //auto t = index(v.name, M);
        //if (t.first == r2 && t.second == c2)
        //    break;
    
        if (marked.find(v.name) != marked.end())
            continue;
	
	//cout << "at {" << v.cost << ", " << v.name << ", from " << v.prev << "}" << endl;


        marked[v.name] = v.prev;

	//auto t = index(v.name, M);
        //if (t.first == r2-1 && t.second == c2-1) {
	if(v.name == f(r2, c2, M)) {
	    //cout << " have not reached " << r2 << ", " << c2 << endl;
            break;
	}

        total_weight = v.cost;
        
        for (auto u : g[to_int(v.name)]){
            frontier.push({u.second + v.cost, u.first, v.name});
            //cout << "pushing {" << u.second + v.cost << ", " << u.first << ", " << v.name << "}" << endl;
        }
    }
                       
    // OUTPUT RESULT ------------------------------------------
    //cout << total_weight << endl;
    
    //for (auto i : marked)
    //    cout << i.first << " " << i.second << endl;
    
    
    int q = f(r2, c2, M);
    stack<int> path;
    while(q != 0) {
	//cout << q << endl;
	path.push(q);
	q = marked[q];
    }
    path.push(f(r1, c1, M));
    cout << total_weight << endl;
    while(!path.empty()) {
	q = path.top();
	path.pop();
	//cout << q << "   ";
	cout << index(q, M).first << ' ' << index(q, M).second << endl;
    }


    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
