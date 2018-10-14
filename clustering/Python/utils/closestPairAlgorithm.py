import math
import time as T


# calcola la distanza tra p1 e p2
def calcDistance(p1,p2):
    x1 = p1[0]
    y1 = p1[1]
    x2 = p2[0]
    y2 = p2[1]
    return math.pow(math.pow(x2-x1,2) + math.pow(y2-y1,2),0.5)

def split(S, Pl, Pr):
    n = len(S)
    Sl, Sr = [], []
    for i in range(n):
        if S[i] in Pl:
            Sl.append(S[i])
        else:
            Sr.append(S[i])

    return Sl,Sr

def closestPairStrip(S,mid,d):
    n = len(S)
    Sp = []
    k = 0
    for i in range(n):
        if abs(S[i][0] - mid) < d: # S[i][0] è l'i-esima coordinata x
            Sp.append(S[i])
            k = k + 1

    (d,i,j) = (math.inf,-1,-1)
    for u in range(k-1): # qui e sotto potrebbero esserci problemi con gli indici... forse è k-1, u+4 e n
        for v in range(u+1, min(u+4,k)):
            (d,i,j) = min((d,i,j), (calcDistance(Sp[u], Sp[v]),Sp[u],Sp[v]))

    return (d,i,j)


# ritorna gli indici (cioè i centri) dei due cluster più vicini
# i due cluster più vicini sono quelli con la distanza minore tra i due centri
# in input vuole la lista dei centri
def slowClosestPair(P):
    (d,i,j) = (math.inf,-1,-1)
    n = len(P)

    for w in range(n): # confronto ogni centro con tutti gli altri centri. (n*(n+1) / 2) iterazioni e non n*(n-1)
        c1 = P[w]
        for z in range(w+1,n): # controllo se w + 1 < n ? non dovrebbe servire
            c2 = P[z]
            (d,i,j) = min((d,i,j), (calcDistance(c1,c2),c1,c2))

    return (d,i,j)

# P ed S devono essere pre-ordinati, ovvero essere ordinati prima dell'invocazione della funzione
# P è ordinato secondo la coordinata x, S è ordinato secondo la coordinata y
def fastClosestPair(P,S):
    n = len(P)
    if n <= 3:
        return slowClosestPair(P)

    m = math.floor(n / 2) # calcolo il punto di divisione tra Pl e Pr
    # costruisco Pl e Pr
    Pl, Pr = P[:m], P[m:]
    Sl, Sr = split(S,Pl,Pr)
    (d,i,j) = min(fastClosestPair(Pl,Sl),fastClosestPair(Pr,Sr))
    mid = (Pl[len(Pl) - 1][0] + Pr[0][0]) / 2
    return min((d,i,j), closestPairStrip(S,mid,d))
