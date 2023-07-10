#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
typedef int NodeID;                                                    

class graph {                                                          
        public:                                                        
                void init_graph() {                                    
                        read_header();                                 
                        read_graph(); 
                }                                                      
                void read_header() {                                   
                        string line;
                        std::getline(cin,line);
                        std::stringstream ss(line);
                        ss >> n;                                 
                        ss >> m;                                 
                        adj_list.resize(n);                                    
                }                                                      
                void read_graph() {                                    
                        for(int i = 0; i < m; i++) {                   
                                NodeID source, target;                 
                                string line;
                                std::getline(cin,line);
                                std::stringstream ss(line);
                                ss >> source;                    
                                ss >> target;                      
                                // Note that the index of the node is always node-1
                                adj_list[source-1].push_back(target-1);
                        }                                              
                }     
                NodeID n, m;
                std::vector<std::vector<NodeID>> adj_list;
};

void DFS(NodeID v, graph& G, std::vector<bool>& marked) {
        // simple Depth-First-Search based on lecture (pp. 360)
        // std::cout << "DFS from " << v + 1 << " to.." <<std::endl;
        for(NodeID w : G.adj_list[v]) {
                // std::cout << w + 1 << std::flush;
                if (! marked[w]) {
                        // std::cout << " -> " << std::flush;
                        marked[w] = true;
                        DFS(w, G, marked);

                }
                // std::cout << " backtrack " << v + 1 << std::endl;
        }
}

bool is_strongly_connected(graph & G) {
    // check corner case: no vertex
    if (G.n == 0) {return true;}

    // for all nodes, check if the vertex is connected
    for(NodeID s = 0; s < G.n; ++s) {
        // std::cout << "s = " << s + 1 << std::endl;

        // initialize vector with marks (parent vector of DFS not needed because no backtracking necessary) 
        std::vector<bool> marked(G.n, false);
        marked[s] = true;

        // DFS starting from s
        DFS(s, G, marked);

        // check if all nodes were reached
        // int i = 1;
        for(bool mark : marked) {
                if (! mark) {
                        // std::cout << "Missing path: " << s+1 << " -> " << i << std::endl;
                        return false;
                }
                // ++i;
        }
        // std::cout << "No missing path detected!\n" << std::endl; 
    }

    // all nodes have been reached from all starting nodes
    return true;
}

int main()
{
    graph G;
    G.init_graph();
    if (is_strongly_connected(G)) 
        std::cout << "G is strongly connected." << std::endl;
    else  
        std::cout << "G is not strongly connected." << std::endl;
    return 0;
}
