anti_Kruskal(){
	init T = G;
	Sort edges in descending order of weight;
	visit all edges of the G{
		int e = get_one_edge(G);
		int v , w = two_vertices_of_edge(e);
		Graph temp_G = G - e;
		int max_weight = DFS(temp_G, v, w);
		if((max_weight != -1)&&(max_weight < weight(e)))
			T = T - e;
	}
}

