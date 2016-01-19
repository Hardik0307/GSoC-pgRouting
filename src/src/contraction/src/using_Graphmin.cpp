#include "../../common/src/structs.h"
#include "graphMinimizer.hpp"
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
using namespace std;
using namespace boost;
typedef adjacency_list<vecS, vecS, undirectedS, Vertex,Edge> G;
int main(int argc, char const *argv[])
{
	/* code */
	typedef Graph_Minimizer<G> Graph;
	Graph g(UNDIRECTED,0);
	Edge *edges=NULL;
	int edge_count=6;
	edges=(Edge*)malloc(edge_count*sizeof(Edge));
	edges[0].id=1;
	edges[0].source=1;
	edges[0].target=2;
	edges[0].cost=1;
	edges[0].revcost=-1;

	edges[1].id=2;
	edges[1].source=2;
	edges[1].target=3;
	edges[1].cost=2;
	edges[1].revcost=-3;

	edges[2].id=3;
	edges[2].source=2;
	edges[2].target=4;
	edges[2].cost=1;
	edges[2].revcost=-1;

	edges[3].id=4;
	edges[3].source=3;
	edges[3].target=4;
	edges[3].cost=3;
	edges[3].revcost=-1;

	edges[4].id=5;
	edges[4].source=4;
	edges[4].target=5;
	edges[4].cost=1;
	edges[4].revcost=-2;

	edges[5].id=6;
	edges[5].source=5;
	edges[5].target=6;
	edges[5].cost=4;
	edges[5].revcost=-1;
	g.initialize_graph_minimizer(edges,edge_count);
	g.print_graph();
	cout << "initial vertices " << g.reduced_graph->numb_vertices << endl;
	g.contract_to_level(0);
	cout << "final contracted vertices " << g.reduced_graph->numb_vertices << endl;
	g.print_removed_vertices();
	char *name;
	g.getGraphName(&name,0);
	cout << "Name: " << name << endl;
	g.getEdgeString(&edges,edge_count,&name);
	cout << "Edge String: " << name << endl;
	//g.remove_vertex(0);
	
	return 0;
}