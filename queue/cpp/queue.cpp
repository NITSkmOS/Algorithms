#include <iostream>
#include<conio.h>
#include<stdlib.h>

#define MAX_SIZE 100

using namespace std;

int main() {
    int item, choice, i;
    int arr_queue[MAX_SIZE];
    int rear = 0;
    int front = 0;
    int exit = 1;

    cout << "\nSimple Queue Example - Array";
    do {
        cout << "\n\n Queue Main Menu";

        cout << "\n1.Insert \n2.Remove \n3.Display \nOthers to exit";
        cout << "\nEnter Your Choice : ";
        cin>>choice;
        switch (choice) {
            case 1:
                if (rear == MAX_SIZE)
                    cout << "\n## Queue Reached Max!!";
                else {
                    cout << "\nEnter The Value to be Insert : ";
                    cin>>item;
                    cout << "\n## Position : " << rear + 1 << " , Insert Value  : " << item;
                    arr_queue[rear++] = item;
                }
                break;
            case 2:
                if (front == rear)
                    cout << "\n## Queue is Empty!";
                else {
                    cout << "\n## Position : " << front << " , Remove Value  :" << arr_queue[front];
                    front++;
                }
                break;
            case 3:
                cout << "\n## Queue Size : " << (rear - front);
                for (i = front; i < rear; i++)
                    cout << "\n## Position : " << i << " , Value  : " << arr_queue[i];
                break;
            default:
                exit = 0;
                break;
        }
    } while (exit);

    return 0;
}