#include < iostream >
using namespace std;

struct node {
    int data;
    node * next;
};

class linked_list {
    node * head, * tail;
 public:
    linked_list() //constructor
    {
        head = NULL;
        tail = NULL;
    }
    void create_node(int);
    void insert_start(int);
    void insert_end(int);
    void insert_pos(int, int);
    void insert_after_pos(int, int);
    void display();
    void count_node();
    void unsort_search(int);
    void sort();
    void del_after_node(int);
    void concatenate(linked_list);
};

void linked_list::create_node(int value) {
    node * temp = new node;
    temp - > data = value;
    temp - > next = NULL;
    head = temp;
    tail = temp;
}

void linked_list::insert_start(int value) {
    node * temp = new node;
    temp - > data = value;
    temp - > next = head;
    head = temp;
}

void linked_list::insert_end(int value) {
    node * temp = new node;
    temp - > data = value;
    temp - > next = NULL;
    tail - > next = temp;
    tail = temp;
}

void linked_list::insert_pos(int pos, int value) {
    node * temp = new node;
    node * insert = new node;
    node * save;
    temp = head;
    int count = 0;
    if (temp == NULL) {
        insert_start(value);
    }
    while (temp != NULL) {
        count++;
        if ((count + 1) == pos) {
            save = temp - > next;
            insert - > data = value;
            insert - > next = save;
            temp - > next = insert;
        }
        temp = temp - > next;
    }
}

void linked_list::display() {
    node * temp = new node;
    temp = head;
    if (temp == NULL) {
        cout << "The list is empty!" << endl;
    }
    while (temp != NULL) {
        cout << temp - > data << endl;
        temp = temp - > next;
    }
}

void linked_list::count_node() {
    node * temp = new node;
    temp = head;
    int count = 0;
    if (temp == NULL) {
        cout << "The list is empty!" << endl;
    }
    while (temp != NULL) {
        count++;
        temp = temp - > next;
    }
    cout << "The list consists of " << count << " nodes." << endl;
}

void linked_list::unsort_search(int item) {
    node * temp = new node;
    temp = head;
    int count = 0;
    if (temp == NULL) {
        cout << "The list is empty!" << endl;
    }
    while (temp != NULL) {
        if (item == temp - > data) {
            cout << "Item found at location: " << (count + 1) << endl;
            break;
        }
        count++;
        temp = temp - > next;
        if (temp == NULL) {
            cout << "Item not found in the list!" << endl;
        }
    }
}

void linked_list::insert_after_pos(int pos, int value) {
    node * save;
    node * temp = new node;
    node * insert = new node;
    temp = head;
    int count = 0;
    if (temp == NULL) {
        insert_start(value);
    }
    while (temp != NULL) {
        count++;
        if ((count + 1) == pos) {
            save = temp - > next;
            insert - > data = value;
            insert - > next = save;
            temp - > next = insert;
        }
        temp = temp - > next;
    }
}

void linked_list::del_after_node(int value) {
    node * temp = new node;
    node * save;
    temp = head;
    if (temp == NULL) {
        cout << "The list is empty!" << endl;
    }
    while (temp != NULL) {
        save = temp;
        save = save - > next;
        if (value == temp - > data) {
            save = save - > next;
            temp - > next = save;
        }
        temp = temp - > next;
    }
}

void linked_list::sort() {
    node * temp = new node;
    node * small, * save;
    temp = head;
    if (temp == NULL) {
        cout << "The list is empty!" << endl;
    }
    while (temp != NULL) {
        small = temp;
        small = small - > next;
        while (small != NULL) {
            if (small - > data < temp - > data) {
                save = small - > next;
                small - > next = temp;
                temp - > next = save;
                head = small;
            }
        }
        temp = temp - > next;
    }
}

void linked_list::concatenate(linked_list A) {
    int flag = 1;
    node * temp1 = new node;
    node * temp2 = new node;
    temp1 = head;
    temp2 = A.head;
    if (temp1 == NULL) {
        cout << "Fisrt list is empty!";
        head = temp2;
        flag = 0;
    } else if (temp2 == NULL) {
        cout << "Second list is empty!";
        head = temp1;
        flag = 0;
    }
    while (flag == 1) {
        temp1 = temp1 - > next;
        if (temp1 - > next == NULL) {
            temp1 - > next = temp2;
            head = temp1;
            flag = 0;
        }
    }
}
