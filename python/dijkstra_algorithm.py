from collections import deque
         
#     ---6--- A ---2---
#     |       |       | 
#   Begin     3      End
#     |       |       |
#     ---2--- B ---5---

def getLessCostNode(costs, processed):
    min = float("inf") 
    node = None
    for c in costs:
        if c not in processed:
            if costs[c] < min:
                min = costs[c]
                node = c 
    return node



def main():
    inf = float("inf")
    # Graph is stored in a python dic
    # Dics are Hash Table
    graph = {}
    graph["begin"] = {}
    graph["begin"]["a"] = 6
    graph["begin"]["b"] = 2

    graph["a"] = {}
    graph["a"]["end"] = 1 

    graph["b"] = {}
    graph["b"]["a"] =3
    graph["b"]["end"] = 5 

    graph["end"] = {}

    # Costs
    costs = {}
    costs["a"] = 6
    costs["b"] = 2
    costs["end"] = inf

    # Parents
    parents = {}
    parents["a"] = "begin" 
    parents["b"] = "begin"
    parents["end"] = None

    processed = []

    node = getLessCostNode(costs, processed)

    while node is not None:
        cost = costs[node]
        neighbors = graph[node]
        for n in neighbors.keys():
            new_cost = cost + neighbors[n]
            if costs[n] > new_cost:
                costs[n] = new_cost
                parents[n] = node
        processed.append(node)
        node = getLessCostNode(costs, processed)

    print(parents)

if __name__ == "__main__":
    main()
