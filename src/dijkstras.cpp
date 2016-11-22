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

// converts (i,j) coordinates to a single value in linear array 
int f(int i, int j, int M) {
    return i * M + j;
}

// converts single value in linear array to pair of coordinates
pair<int,int> index(int Linear, int M) {
    return {(Linear / M), (Linear % M) };
}

void print_array(vector< vector<int> > arr, int M, int N){
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    	}
}


// MAIN EXECUTION -------------------------------------------------
int main(int argc, char *argv[]) {

    map<char, int> m;
    char c;
    int TILES_N, a, M, N, r1, c1, r2, c2;

    // PROCESS TILE WEIGHTS ---------------------------------------
    cin >> TILES_N;
    for (int i=0; i<TILES_N; i++){
        cin >> c >> a;
        m[c] = a;
    }
    
    // STORE FOREST ARRAY -----------------------------------------
    cin >> M >> N;
    
    vector< vector<int> > forest(N, vector<int> (M));
    vector< map<int, int> > g(M*N);
    
        // LOAD VERTICES ------------------------------------------
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                cin >> c;
                forest[i][j] = m[c];
            }
        }
    
        //print_array(forest, M, N);
    
    // BUILD MAP WITH COSTS ---------------------------------------
    int curr;
    for(int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            curr = f(i,j,M);
            // store cost of left node
            	if(i!=0)   g[curr][f(i-1, j  , M)] = forest[i][j];
            // store cost of bottom node
            	if(j!=0)   g[curr][f(i  , j-1, M)] = forest[i][j];
            // store cost of right node
            	if(i!=N-1) g[curr][f(i+1, j  , M)] = forest[i][j];
            // store cost of top node
            	if(j!=M-1) g[curr][f(i  , j+1, M)] = forest[i][j];
        }
    }
    
    // INPUT START AND END POINTS ---------------------------------
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    
    // DIKJSTRAS ALGORITHM ----------------------------------------
    priority_queue<int, std::vector<Edge>, EdgeCost> frontier;
    //typedef pair<int, int> Pair;
    //map<Pair, int> marked;
    map<int, int> marked;
    int total_cost = 0;
    
    frontier.push({0, f(r1,c1,M), f(r1,c1,M)});
    
    while (!frontier.empty()){
        Edge v = frontier.top();
        frontier.pop();
    
        if (marked.find(v.name) != marked.end())
            continue;
	
	    //cout << "at {" << v.cost << ", " << v.name << ", from " << v.prev << "}" << endl;

        marked[v.name] = v.prev;

        	if(v.name == f(r2, c2, M)) {
        	    //cout << " have not reached " << r2 << ", " << c2 << endl;
            break;
        	}

        total_cost = v.cost;
        
        for (auto u : g[v.name]){
            frontier.push({u.second + v.cost, u.first, v.name});
            //cout << "pushing {" << u.second + v.cost << ", " << u.first << ", " << v.name << "}" << endl;
        }
    }
                       
    // STORE CORRECT PATH ----------------------------------------
    int q = f(r2, c2, M);
    stack<int> path;
    while(q != 0) {
        	//cout << q << endl;
        	path.push(q);
        	q = marked[q];
    }
    path.push(f(r1, c1, M));
    
    cout << total_cost << endl;
    while(!path.empty()) {
        	q = path.top();
        	path.pop();
        	//cout << q << "   ";
        	cout << index(q, M).first << ' ' << index(q, M).second << endl;
    }

    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
