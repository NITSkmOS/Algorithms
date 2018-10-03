'''
    Dijkstra's shortest path Algorithm
        Args :  G - Dictionary of edges
                s - Starting Node
        Vars :  dist - Dictionary storing shortest distance from s to
         every other node
                known - Set of knows nodes
                path - Preceding node in path
'''


def dijkstras(G, s):
    dist, known, path = {s: 0}, set(), {s: 0}
    while True:
        if len(known) == len(G) - 1:
            break
        mini = 100000
        for i in dist:
            if i not in known and dist[i] < mini:
                mini = dist[i]
                u = i
        known.add(u)
        for v in G[u]:
            if v[0] not in known:
                if dist[u] + v[1] < dist.get(v[0], 100000):
                    dist[v[0]] = dist[u] + v[1]
                    path[v[0]] = u
    return dist


def main():
    G = {1: [[3, 4]],
         2: [[5, 2]],
         3: [[4, 2], [5, 4], [2, 6]],
         4: [],
         5: [[2, 2]]}
    s = 1
    dist = dijkstras(G, s)
    for i in dist:
        if i != s:
            print(dist[i])


if __name__ == '__main__':
    main()
