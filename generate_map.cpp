// generate_map.cpp

#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <time.h>

using namespace std;

// Utility functions -----------------------------------------------------------

void usage(int status) {
	cout << "usage: generate_map" << endl
		<< "    -n N    Generates a NxN map of random tiles" << endl;
	exit(status);
}

void parse_command_line_options(int argc, char *argv[], int &N) {
	int c;
	
	N = 5;
	while ((c = getopt(argc, argv, "hn:")) != -1) {
		switch (c) {
			case 'n':
				N = stoi(optarg);
				break;
			case 'h':
				usage(0);
				break;
			default:
				usage(1);
				break;
		}
	}
}

char tiles[6] = {'f','g','G','h','m','r'};

char random_tiles(){
	return tiles[rand()%6];
}

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
	int  N = 1;
	parse_command_line_options(argc, argv, N);

    cout << "6\nf3\ng1\nG2\nh4\nm7\nr5\n" << N << ' ' << N << endl;

    srand(time(NULL));
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			cout << random_tiles();
		}
		cout << endl;
	}

    cout << rand()%N << ' ' << rand()%N << endl;
    cout << rand()%N << ' ' << rand()%N << endl;
	
	return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
