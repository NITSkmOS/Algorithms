public class LinkedList<T> {
    public static void main(String[] args) {
        LinkedList<String> list = new LinkedList<String>("head");
        list.add("second");
        list.add("third");
        list.add("last");
        System.out.println(list.length()); // should be 4
        System.out.println(list.remove("third")); // should print "third"
        System.out.println(list.length()); // should be 3
    }

    private Node<T> head;

    public LinkedList(T head) {
        this.head = new Node<T>(head);
    }

    public LinkedList() {
    }

    /**
     * Adds a value to the end of the list
     *
     * @param val value to be added
     * @return true if add succeeds; false otherwise
     */
    public boolean add(T val) {
        Node<T> tmp = this.head;
        if (tmp == null) {
            this.head = new Node<T>(val);
            return true;
        }

        while (tmp.next() != null) {
            tmp = tmp.next();
        }

        tmp.setNext(new Node<T>(val));
        return true;
    }

    /**
     * Returns the value that was removed if the requested value
     * was found. Otherwise returns null if the value doesn't exist
     * in the list
     * @param val
     * @return T
     */
    public T remove(T val) {
        if (this.head != null) {
            if (this.head.getValue() == val) {
                Node<T> trash = this.head;
                this.head = this.head.next();
                trash.setNext(null);
                return trash.getValue();
            }
        } else {
            return null;
        }

        Node<T> prev = this.head;
        Node<T> tmp = prev.next();
        while (tmp != null) {
            if (tmp.getValue() == val) {
                prev.setNext(tmp.next());
                tmp.setNext(null);
                return tmp.getValue();
            }
            tmp = tmp.next();
            prev = prev.next();
        }

        return null;
    }

    public int length() {
        int len = 0;
        Node<T> tmp = this.head;
        while (tmp != null) {
            len++;
            tmp = tmp.next();
        }

        return len;
    }

    private class Node<T> {
        private Node<T> nextNode;
        private T value;

        public Node(T val) {
            this.value = val;
        }

        public Node<T> next() {
            return this.nextNode;
        }

        public void setNext(Node<T> next) {
            this.nextNode = next;
        }

        public T getValue() {
            return this.value;
        }
    }
}

