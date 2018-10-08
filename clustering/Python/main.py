from utils.readFromFile import *
from utils.closestPairAlgorithm import *
from utils.clusteringAlgorithm import *
from createGraph import *

def maxPopulation(k, dataSet):
    Cp, C = [], []
    for i in dataSet.keys():
        Cp.append((i,dataSet[i][0]))

    Cp = sorted(Cp,key = lambda people: people[1],reverse = True)
    Cp = Cp[:k]
    for el in Cp:
        C.append(el[0])

    return C

#creazione data-set
minDataSet = readFromFile("data/unifiedCancerData_111.csv")
mediumDataSet = readFromFile("data/unifiedCancerData_290.csv")
maxDataSet = readFromFile("data/unifiedCancerData_896.csv")
completeDataSet = readFromFile("data/unifiedCancerData_3108.csv")



#Domanda1
k = 15 #number of cluster
q = 5 # number of iteration in k-means clustering
P = completeDataSet.keys()

hierarchical_clusters_dict = hierarchicalClustering(P,k,False)

ClusterGraph(hierarchical_clusters_dict)

#Domanda2
#Costruisco la lista dei centri = sono le 15 coordinate con la popolazione maggiore
C = maxPopulation(k,completeDataSet)

# Clustering K-means
kmeans_clusters_dict = KMeansClustering(P,C,k,q)

ClusterGraph(kmeans_clusters_dict)

#Domanda4
k = 9
q = 5
P = list(minDataSet.keys())

hierarchical_clusters_dict = hierarchicalClustering(P,k,False)
ClusterGraph(hierarchical_clusters_dict)

#Domanda5
C = maxPopulation(k, minDataSet)

kmeans_clusters_dict = KMeansClustering(P,C,k,q)

ClusterGraph(kmeans_clusters_dict)

#Domanda6
error_hierarchical = clusterDistortion(hierarchical_clusters_dict, minDataSet)
error_kmeans = clusterDistortion(kmeans_clusters_dict, minDataSet)

print(error_hierarchical, "hier")
print(error_kmeans, "kmeans")

#Domanda9
q = 5
pMin = list(minDataSet.keys())
pMed = list(mediumDataSet.keys())
pMax = list(maxDataSet.keys())

hMin = []
hMed = []
hMax = []
kMin = []
kMed = []
kMax = []

#se il flag è true hierarchicalClustering usa il dizionario in input (dict[center] : {lista di punti del cluster}) come clustering
#invece di inizializzare un clustering vuoto
#utilizzato per migliorare l'efficienza nella domanda 9
flag = False

minHierData = pMin
medHierData = pMed
maxHierData = pMax

for k in reversed(range(6,21)):
    #hierarchicalClustering per dataset da 111 contee
    hierarchical_clusters_dict1 = hierarchicalClustering(minHierData,k,flag)
    error_hierarchical1 = clusterDistortion(hierarchical_clusters_dict1, minDataSet)
    hMin.insert(0,error_hierarchical1)
    minHierData = hierarchical_clusters_dict1

    #hierarchicalClustering per dataset da 290 contee
    hierarchical_clusters_dict2 = hierarchicalClustering(medHierData,k,flag)
    error_hierarchical2 = clusterDistortion(hierarchical_clusters_dict2, mediumDataSet)
    hMed.insert(0,error_hierarchical2)
    medHierData = hierarchical_clusters_dict2

    #hierarchicalClustering per dataset da 896 contee
    hierarchical_clusters_dict3 = hierarchicalClustering(maxHierData,k,flag)
    error_hierarchical3 = clusterDistortion(hierarchical_clusters_dict3, maxDataSet)
    hMax.insert(0,error_hierarchical3)
    maxHierData = hierarchical_clusters_dict3

    #nella prossima iterazione passeremo a hierarchicalClustering i cluster calcolati nell'iterazione precedente
    flag = True

    CMin = maxPopulation(k, minDataSet)
    #kmeans per dataset da 111 contee
    kmeans_clusters_dict1 = KMeansClustering(pMin,CMin,k,q)
    error_kmeans1 = clusterDistortion(kmeans_clusters_dict1, minDataSet)
    kMin.insert(0,error_kmeans1)

    CMed = maxPopulation(k, mediumDataSet)
    #kmeans per dataset da 290 contee
    kmeans_clusters_dict2 = KMeansClustering(pMed,CMed,k,q)
    error_kmeans2 = clusterDistortion(kmeans_clusters_dict2, mediumDataSet)
    kMed.insert(0,error_kmeans2)

    CMax = maxPopulation(k, maxDataSet)
    #kmeans per dataset da 896 contee
    kmeans_clusters_dict3 = KMeansClustering(pMax,CMax,k,q)
    error_kmeans3 = clusterDistortion(kmeans_clusters_dict3, maxDataSet)
    kMax.insert(0,error_kmeans3)




errorFunction(hMin,kMin, "Numero di cluster", "Distorsione", "Distorsione nel Data Set con 111 contee")
errorFunction(hMed,kMed, "Numero di cluster", "Distorsione", "Distorsione nel Data Set con 290 contee")
errorFunction(hMax,kMax, "Numero di cluster", "Distorsione", "Distorsione nel Data Set con 896 contee")
