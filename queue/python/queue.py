q=[]

def insert(num):
    q.append(num)
    print(f"{num} Was Inserted")

def remove():
    if len(q) == 0:
        print("UnderFlow")
    else:
        print(f"{q.pop(0)} was removed")

def display():
    if len(q) == 0:
        print("Queue Empty")
    else:
        print(q)

def main():
    insert(5)
    insert(9)
    insert(18)
    insert(63)
    insert(68)
    remove()
    display()

if __name__ == "__main__":
    main()
