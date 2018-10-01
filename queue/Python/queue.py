import queue

L = queue.Queue(maxsize=20)

L.put(5)
L.put(9)
L.put(1)
L.put(7)

print(L.get())
print(L.get())
print(L.get())
print(L.get())
