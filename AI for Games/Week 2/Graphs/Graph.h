#pragma once
#include "GraphEdge.h"
#include "GraphNode.h"

namespace aie {
	class Renderer2D;
}

class Graph
{
public:
	Graph();
	// adds node to the graph
	void AddNode(GraphNode* node);
	// connects the two nodes in the graph
	void ConnectNode(GraphNode* a, GraphNode* b, float cost);
	// Get the nodes
	std::vector<GraphNode*> GetNodes();
	// depth first search
	std::vector<GraphNode*> DFS(GraphNode* startNode, GraphNode* endNode);
	// breadth first search
	std::vector<GraphNode*> BFS(GraphNode* startNode, GraphNode* endNode);
	// djisktra shortest path search
	std::vector<GraphNode*> DjikstraSearch(GraphNode* startNode, GraphNode* endNode);
	// draw the nodes onto the screen
	void draw(aie::Renderer2D * renderer);

	~Graph();
private:
	std::vector<GraphNode*> m_nodes;
};

