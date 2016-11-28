Project 05: Path Finding
========================

This [project] implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[project]:              https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/project05.html
[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]


2.

Averages:
| N             | Elapsed Time  | Memory Usage   |
|---------------|---------------|----------------|
| 10            | 0.001523      |   0.820312     |
| 20            | 0.002399      |   0.898438     |
| 50            | 0.008668      |   1.375020     |
| 100           | 0.028216      |   3.167969     |
| 200           | 0.134578      |  10.324219     |
| 500           | 1.285132      |  61.460938     |
| 1000          | 2.455428      | 226.656250     |
|---------------|---------------|----------------|

3.

    The map was represented by a vector of vector<int> called forest.
The tiles are translated into their integer value to make a grid of
"leaving cost" weights. Another vector contains a map<int, int> for 
every tile. Each map contains the cost of leaving each of the surrounding
tiles.
    The algorithm searches through a priority queue that starts with
the runner tile and pushes the surrounding tiles from the associated
map after a tile is popped. Another map keeps track of already visited
tiles and their previous tile. Every time a tile is pushed, the total
path cost is updated for that tile. Tiles are searched in order of smallest
path cost until the target is found. Since all tiles could be processed and
for each tile there is a constant max of 4 tiles to check if marked, the
complexity is O(# of tiles).
    The implementation scaled decently considering the number of tiles grows
exponentially in proportion to N. When the number of tiles was multiplied by
100, such as from N=100->N=1000 or N=20->N=200, the time and memory grew by
a factor of less than 100.

Contributions:

Troy Prince: implemented dijkstras.cpp, debugging

Michael McRoskey: began dijkstras.cpp, implemented generate_map.cpp

David Mellitt: Debugging, benchmarks, README
