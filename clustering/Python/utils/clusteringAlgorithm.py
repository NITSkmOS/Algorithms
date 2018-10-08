from collections import defaultdict
from .closestPairAlgorithm import *
import math
import numpy as np
import matplotlib.pyplot as plt
from scipy.misc import imread
import itertools

def maxPopulation(k, dataSet):
    Cp, C = [], []
    for i in dataSet.keys():
        Cp.append((i,dataSet[i][0]))

    Cp = sorted(Cp,key = lambda people: people[1],reverse = True)
    Cp = Cp[:k]
    for el in Cp:
        C.append(el[0])

    return C

def clusterDistortion(cluster, dataSet):
    error = 0

    for center, list in cluster.items():
        for point in list:
            population = dataSet[point][0]
            distance_from_center = calcDistance(point,center)

            error = error + (population * (math.pow(distance_from_center,2)))

    return error

def calcCenter(P):
       sum_x, sum_y = 0.0, 0.0
       for (x,y) in P:
           sum_x = sum_x + x
           sum_y = sum_y + y

       n = len(P)
       return (sum_x/n , sum_y/n)



def hierarchicalClustering(P, k, flag):
    # dizionario che ha come chiave il centro del cluster e come valore l'insieme delle coordinate nel cluster
    if not flag:
        clusters_dict = defaultdict(list)

        for i in P:
            clusters_dict[i] = [i]

    else:
        clusters_dict = P

    L = clusters_dict.keys() # Lista dei centri
    centers_list_ord_x = sorted(L, key = lambda coord: coord[0]) # lista dei centri ordinata secondo l'asse x
    centers_list_ord_y = sorted(L, key = lambda coord: coord[1]) # lista dei centri ordinata secondo l'asse y


    while len(clusters_dict) > k:
        (d,i,j) = fastClosestPair(centers_list_ord_x, centers_list_ord_y)
        C = clusters_dict[i] + (clusters_dict[j]) # todo: decidere se appendere il più corto al più lungo

        clusters_dict[calcCenter(C)] = C
        del clusters_dict[i]
        del clusters_dict[j]
        L = clusters_dict.keys() # Lista dei centri

        centers_list_ord_x = sorted(L, key = lambda coord: coord[0]) # lista dei centri ordinata secondo l'asse x
        centers_list_ord_y = sorted(L, key = lambda coord: coord[1]) # lista dei centri ordinata secondo l'asse y
    return clusters_dict

# C[i]
def KMeansClustering(P,C,k,q): #
    clusters_dict = defaultdict(list)

    for i in range(q):
        for z in range(k):
            clusters_dict[z] = []

        for pair in P:
            l = closestPoint(pair,C)
            clusters_dict[l].append(pair)

        for f in range(k):
            if(clusters_dict[f]):
                C[f] = calcCenter(clusters_dict[f])

    for i in range(k): # prima iteravo su clusters_dict.keys(), ma succedeva un errore run-time. In questo modo la pace sembra ristabilita
        clusters_dict[C[i]] = clusters_dict[i]
        del clusters_dict[i]

    return clusters_dict

def closestPoint(p,C):
    d = math.inf
    l = -1
    n = len(C)
    for i in range(n): # confronto p con tutti i centri in C
        distance = calcDistance(p,C[i])
        if distance < d:
            d = distance
            l = i # aggiorno la nuova distanza

    return l
