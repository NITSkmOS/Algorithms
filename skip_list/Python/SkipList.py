'''
    Skip list is a probabilistic data structure that allows efficient search,
    insertion and removal operations.
    It allows fast search within an ordered sequence of elements,
    O(log(n)) complexity.

    Wikipedia Page: https://en.wikipedia.org/wiki/Skip_list
'''
from random import randint, seed
import time
class SkipNode:
    '''
        A single node in a SkipList data structure,
        which is similar to a normal linked list node.
    '''
    def __init__(self,height=0,elem=None):
        self.elem=elem
        self.next=[None]*height

class SkipList:
    def __init__(self):
        # This will set the head node of the list.
        self.head=SkipNode()
        self.len=0
        self.maxHeight=0
    def __len__(self):
        return self.len
    '''
        The Search operation takes O(log(n)) time complexity
        as compared to O(n) in classical linked list.
    '''
    def find(self,elem,update=None):
        if(update==None):
            update = self.updateList(elem)
        if(len(update)>0):
            candidate = update[0].next[0]
            if(candidate!=None and candidate.elem==elem):
                return candidate
        return None
    '''
        This function returns a randomized hieght for insertion algorithm.
    '''
    def randomHeight(self):
        height=1
        while randint(1,2)!=1:
            height+=1
        return height
    '''
        This function returns the skip list that is below the element
        which is closest and smaller than the element that is required to find.
    '''
    def updateList(self,elem):
        update=[None]*self.maxHeight
        x=self.head
        for i in reversed(range(self.maxHeight)):
            while x.next[i]!=None and x.next[i].elem<elem:
                x=x.next[i]
            update[i]=x
        return update        
    '''
        This function inserts an element in the correct possition.
        The insertion operation takes O(n) time complexity
    '''
    def insert(self,elem):
        node=SkipNode(self.randomHeight(),elem)
        self.maxHeight=max(self.maxHeight,len(node.next))
        while(len(self.head.next)<len(node.next)):
            self.head.next.append(None)
        update=self.updateList(elem)            
        if(self.find(elem, update)==None):
            for i in range(len(node.next)):
                node.next[i]=update[i].next[i]
                update[i].next[i]=node
            self.len+=1
    '''
        This function will remove the specified element from the list. 
        The deletion operation in Skip List takes O(log(n)) time.
    '''
    def remove(self,elem):
        update=self.updateList(elem)
        x=self.find(elem,update)
        if(x!=None):
            for i in reversed(range(len(x.next))):
                update[i].next[i]=x.next[i]
                if(self.head.next[i]==None):
                    self.maxHeight-=1
            self.len-=1            
    '''
        This function will print the entier Data Structure,
        level by level (top to bottom)
    '''       
    def printList(self):
        for i in range(len(self.head.next)-1, -1, -1):
            x=self.head
            while(x.next[i]!=None):
                print(x.next[i].elem,)
                x=x.next[i]
            print('')
if __name__ == "__main__":
    skipList = SkipList()
    print("Insertion Started")
    t0=time.time()
    for i in range(1000000):
        skipList.insert(i)
    print("Time taken to insert 1M elements: "+str(time.time()-t0)+" s.")
    print("Total Size = "+str(len(skipList)))
    t0 = time.time()
    print(skipList.find(596536)!=None)
    print("Time taken to search in a list of size 1M: "+str(time.time()-t0)+" s.")
