#include <stdio.h>
#include <stdlib.h>
#include "bai3.h"

// Định nghĩa cấu trúc của một nút trong danh sách liên kết
typedef struct Node {
    int data;           // Dữ liệu chứa trong nút
    struct Node* next;  // Con trỏ trỏ đến nút tiếp theo trong danh sách
} Node;

// Hàm tạo một nút mới
Node* createNode3(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Cấp phát bộ nhớ cho nút mới
    newNode->data = data;                         // Gán giá trị vào dữ liệu của nút
    newNode->next = NULL;                         // Con trỏ next của nút mới trỏ tới NULL (nút cuối)
    return newNode;                               // Trả về con trỏ tới nút mới
}

// Hàm thêm một nút vào cuối danh sách
void addNodeToTail3(Node** head, int data) {
    Node* newNode = createNode3(data);  // Tạo nút mới với giá trị data
    if (*head == NULL) {
        *head = newNode;  // Nếu danh sách rỗng, đặt nút mới làm đầu danh sách
        return;
    }
    Node* temp = *head;
    // Duyệt qua danh sách đến nút cuối
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;  // Gắn nút mới vào cuối danh sách
}

// Hàm kiểm tra xem danh sách liên kết có vòng lặp không
int hasCycle(Node* head) {
    if (head == NULL) {
        return 0;  // Nếu danh sách rỗng, không có vòng lặp
    }

    Node* slow = head;  // Con trỏ chậm sẽ di chuyển 1 bước mỗi lần
    Node* fast = head;  // Con trỏ nhanh sẽ di chuyển 2 bước mỗi lần

    // Duyệt danh sách với con trỏ nhanh và con trỏ chậm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Di chuyển con trỏ chậm một bước
        fast = fast->next->next;    // Di chuyển con trỏ nhanh hai bước

        // Nếu con trỏ nhanh và chậm gặp nhau, chứng tỏ có vòng lặp
        if (slow == fast) {
            return 1;  // Có vòng lặp
        }
    }

    return 0;  // Không có vòng lặp
}

// Hàm in danh sách liên kết
void printList3(Node* head) {
    Node* temp = head;
    Node* slow = head;
    Node* fast = head;

    // Duyệt danh sách và kiểm tra vòng lặp
    while (temp != NULL) {
        printf("%d -> ", temp->data);  // In ra dữ liệu của nút hiện tại
        temp = temp->next;  // Di chuyển đến nút tiếp theo

        // Kiểm tra vòng lặp bằng thuật toán Floyd's Tortoise and Hare
        if (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Di chuyển con trỏ chậm
            fast = fast->next->next;    // Di chuyển con trỏ nhanh
            if (slow == fast) {         // Nếu con trỏ chậm và nhanh gặp nhau
                printf("... (cycle detected)\n");  // phát hiện vòng lặp
                return;  // Dừng hàm, vì đã phát hiện vòng lặp
            }
        }
    }
    printf("NULL\n");  // In "NULL" khi kết thúc danh sách mà không có vòng lặp
}

// Hàm main để kiểm tra
void bai3() {
    Node* head = NULL;

    // Thêm các phần tử vào danh sách liên kết
    addNodeToTail3(&head, 1);  // Thêm 1 vào cuối danh sách
    addNodeToTail3(&head, 2);  // Thêm 2 vào cuối danh sách
    addNodeToTail3(&head, 3);  // Thêm 3 vào cuối danh sách
    addNodeToTail3(&head, 4);  // Thêm 4 vào cuối danh sách

    // In danh sách ban đầu
    printf("Danh sach ban dau: ");
    printList3(head);

    // Tạo vòng lặp bằng cách nối nút cuối với nút đầu tiên
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head->next;  // Tạo vòng lặp tại nút thứ 2 (giá trị 2)

    // In lại danh sách sau khi tạo vòng lặp (không in được toàn bộ do có vòng lặp)
    printf("\nDanh sach sau khi tao vong lap: ");
    printList3(head);

    // Kiểm tra vòng lặp
    if (hasCycle(head)) {
        printf("Danh sach co vong lap.\n");
    } else {
        printf("Danh sach khong co vong lap.\n");
    }
}
