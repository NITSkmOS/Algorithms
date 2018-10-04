from collections import defaultdict

class Graph:

    def __init__(self):
        self.graph = defaultdict(list)
        self.unvisited = []
        self.min_dist,self.parent = {},{}
    
    def add_vertex(self,_from,_to,wt):
        '''
        param _from : source vertex
        param _to : destination vertex
        param wt : weight of the edge between source and destination
        '''
        self.graph[_from].append({_to:wt})
        self.graph[_to].append({_from:wt})
        self.unvisited.append(_from)
        self.unvisited.append(_to)
     
    def dijkstra(self,start,end):   
        '''
        param start : start vertex from which the dijkstra's algorithm starts
        param end : final destination vertex
        '''
        self.unvisited = list(set(self.unvisited))
        visited = [start]

        # initialize the shortest path values for each vertex
        for n in self.graph.keys():
            if n!=start:
                self.min_dist[n] = float('inf')
                self.parent[n] = None
            else:
                self.min_dist[start] = 0
                self.parent[start] = None

        while self.unvisited:
            node = min(self.unvisited,key=self.min_dist.get)
            if node in self.unvisited:
                self.unvisited.remove(node)
                visited.append(node)
                
                for n in self.graph[node]:
                    if self.min_dist[node] + n.values()[0] < self.min_dist[n.keys()[0]]:
                        self.min_dist[n.keys()[0]] = self.min_dist[node] + n.values()[0]
                        self.parent[n.keys()[0]] = node

        #Find the shortest path
        path = ''
        ptr = end
        path += end + ' '
        while ptr != start:
            ptr = self.parent[ptr]
            path += ptr
            path += ' '
        print path

def main():
    G = Graph()
    G.add_vertex('a','b',6)
    G.add_vertex('a','d',1)
    G.add_vertex('b','d',2)
    G.add_vertex('d','e',1)
    G.add_vertex('b','e',2)
    G.add_vertex('b','c',5)
    G.add_vertex('e','c',5)
    #G.show()
    G.dijkstra('a','c')

if __name__ == '__main__':
    main()
