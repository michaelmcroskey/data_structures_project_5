// generate_map.cpp

#include <iostream>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <set>
#include <algorithm>

// Utility functions -----------------------------------------------------------

void usage(int status) {
	std::cout << "usage: generate_map" << std::endl
		<< "    -n N    Generates a NxN map of random tiles" << std::endl;
	exit(status);
}

void parse_command_line_options(int argc, char *argv[], int &N) {
	int c;
	
	N = 5;
	while ((c = getopt(argc, argv, "hn:")) != -1) {
		switch (c) {
			case 'n':
				N = std::stoi(optarg);
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

std::set<char> tiles = {'f','g','G','h','m','r'};

char random_tiles(){
	std::set<char>::iterator randIt = tiles.begin();
	std::advance(randIt, std::rand() % tiles.size());
	return *randIt;
}

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
	int  N = 1;
	parse_command_line_options(argc, argv, N);

	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			std::cout << random_tiles();
		}
		std::cout << std::endl;
	}
	
	return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
