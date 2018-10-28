'''
 ____       _           _   _             ____             _   
/ ___|  ___| | ___  ___| |_(_) ___  _ __ / ___|  ___  _ __| |_ 
\___ \ / _ | |/ _ \/ __| __| |/ _ \| '_ \\___ \ / _ \| '__| __|
 ___) |  __| |  __| (__| |_| | (_) | | |  ___) | (_) | |  | |_ 
|____/ \___|_|\___|\___|\__|_|\___/|_| |_|____/ \___/|_|   \__|

'''
# author: john2ksonn
# date: 10.28.2018

import random

def sort(a):
    max_idx = len(a) - 1
    for idx in range(0, max_idx):
        min_idx = idx        
        for i in range(idx+1, max_idx+1):
            if a[i] < a[min_idx]:
                min_idx = i
        a[idx], a[min_idx] = a[min_idx], a[idx]        
    return a
    

if __name__ == "__main__":
    rand_list = random.sample(range(1000), 40)
    sorted_list = sort(rand_list)
    print(sorted_list)
