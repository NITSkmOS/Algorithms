using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace OwnArray
{
    class DynamicList<T> : IEnumerable<T>
    {
        private class Node
        {
            private T element;
            private Node next;

            public T Element
            {
                get { return element; }
                set { element = value; }
            }

            public Node Next
            {
                get { return next; }
                set { next = value; }
            }

            public Node(T element, Node prevNode)
            {
                this.element = element;
                prevNode.next = this;
            }

            public Node(T element)
            {
                this.element = element;
                this.Next = null;
            }
        }

        private Node head;
        private Node tail;
        private int count;

        public DynamicList()
        {
            this.head = null;
            this.tail = null;
            this.count = 0;
        }

        public void Add(T item)
        {
            if (this.head == null)
            {
                Node n = new Node(item);
                this.head = n;
                this.tail = n;
                count++;
            }
            else
            {
                Node n = new Node(item, tail);
                this.tail = n;
                count++;
            }
        }
        public T RemoveAtIndex(int index)
        {
            if (index < 0 || index >= this.count)
            {
                throw new ArgumentOutOfRangeException();
            }

            Node a = head;
            Node prevNode = a;
            int position = 0;

            if (index == position)
            {
                head = a.Next;
                count--;
                return a.Element;
            }

            while (a != null)
            {
                if (position == index)
                {
                    prevNode.Next = a.Next;
                    count--;
                    return a.Element;
                }
                position++;
                prevNode = a;
                a = a.Next;
            }

            return default(T);

        }


        public int Remove(T item)
        {
            Node a = head;
            Node prevNode = a;
            int position = 0;

            while (a != null)
            {
                if (a.Element.Equals(item))
                {
                    prevNode.Next = a.Next;
                    count--;
                    return position;
                }
                position++;
                prevNode = a;
                a = a.Next;
            }

            return -1;

        }
        public int IndexOf(T item)
        {
            Node a = head;
            int position = 0;
            while (a != null)
            {
                if (a.Element.Equals(item))
                {
                    return position;
                }
                position++;
                a = a.Next;
            }

            return -1;
        }

        public bool Contains(T item)
        {
            if (IndexOf(item) == -1)
            {
                return false;
            }

            return true;
        }

        public IEnumerator<T> GetEnumerator()
        {
            Node a = head;
            Node prevNode = a;
            int position = 0;

            while (a != null)
            {
                yield return a.Element;
                position++;
                prevNode = a;
                a = a.Next;
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return this.GetEnumerator();
        }

        public T this[int index]
        {
            get
            {
                if (index < 0 || index >= this.count)
                {
                    throw new ArgumentOutOfRangeException();
                }
                Node a = head;
                int position = 0;
                while (a != null)
                {
                    if (position == index)
                    {
                        return a.Element;
                    }
                    position++;
                    a = a.Next;
                }

                return default(T);

            }
            set
            {
                if (index < 0 || index >= this.count)
                {
                    throw new ArgumentOutOfRangeException();
                }
                Node a = head;
                int position = 0;
                while (a != null)
                {
                    if (position == index)
                    {
                        a.Element = value;
                    }
                    position++;
                    a = a.Next;
                }
            }
        }

        public int Count
        {
            get
            {
                return count;
            }
        }
    }

}

