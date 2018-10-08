import numpy as np
import matplotlib.pyplot as plt
from scipy.misc import imread
import itertools

def ClusterGraph(cluster_dict):

    colors = itertools.cycle(["cyan", "b", "g","brown","orange","hotpink","yellow","r",
    "magenta","gold","olive","darkorchid","seagreen","crimson","midnightblue"])
    img = imread("data/USA_Counties.png")
    for k in cluster_dict.keys():
        c = next(colors)
        plt.scatter(k[0],k[1], s = 100, color = c, edgecolors = "black", zorder =2)
        for node in cluster_dict[k]:
            f = [node[0],k[0]]
            g = [node[1],k[1]]
            plt.scatter(f,g,marker='o', color = c, zorder =1, s = 15)
    plt.imshow(img,zorder=0)
    plt.show()

def errorFunction(h,k,xlabel,ylabel,title):
    plt.grid()
    plt.plot([x for x in range(6,21)], h,  label = "Hierarchical")
    plt.plot([x for x in range(6,21)], k, label = "Kmeans")
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.title(title)
    plt.legend()
    plt.show()
