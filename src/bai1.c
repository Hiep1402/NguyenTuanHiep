#include <stdio.h>
#include <stdlib.h>
#include "bai1.h"

// Định nghĩa cấu trúc của một nút
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tạo nút mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Cấp phát bộ nhớ cho nút mới
    newNode->data = data;                         // Gán giá trị vào data
    newNode->next = NULL;                         // Gán con trỏ next của nút mới = NULL
    return newNode;                               // Trả về con trỏ đến nút mới tạo
}

// Hàm thêm nút vào đầu danh sách
void addNodeToHead(Node** head, int data) {
    Node* newNode = createNode(data);  // Tạo nút mới
    newNode->next = *head;             // Con trỏ next của nút mới trỏ đến nút đầu (head)
    *head = newNode;                   // Đổi con trỏ head để trỏ đến nút mới
}

// Hàm thêm nút vào cuối danh sách
void addNodeToTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Hàm chèn nút trước một nút có giá trị xác định
void insertNodeBefore(Node** head, int target, int data) {
    Node* newNode = createNode(data);

    // Trường hợp danh sách rỗng
    if (*head == NULL) {
        printf("Danh sach rong. Khong the chen truoc nut co gia tri %d\n", target);
        free(newNode);
        return;
    }

    // Trường hợp chèn trước nút đầu tiên
    if ((*head)->data == target) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }

    // Nếu tìm thấy nút có giá trị target
    if (temp->next != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Khong tim thay nut co gia tri %d\n", target);
        free(newNode);
    }
}

// Hàm xóa nút có giá trị xác định
void deleteNode(Node** head, int target) {
    if (*head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    Node* temp = *head;

    // Trường hợp nút đầu tiên có giá trị cần xóa
    if (temp->data == target) {
        *head = temp->next;
        free(temp);
        return;
    }

    Node* prev = NULL;
    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }

    // Nếu tìm thấy nút có giá trị target
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Khong tim thay nut co gia tri %d\n", target);
    }
}

// Hàm in danh sách
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Hàm main để kiểm tra
void bai1() {
    Node* head = NULL;

    addNodeToHead(&head, 1);  // Thêm 1 vào đầu danh sách
    addNodeToTail(&head, 2);  // Thêm 2 vào cuối danh sách
    addNodeToTail(&head, 3);  // Thêm 3 vào cuối danh sách
    insertNodeBefore(&head, 2, 4);  // Chèn 4 trước nút có giá trị 2
    printf("Danh sach ban dau: \n");
    printList(head);  // In danh sách liên kết

    deleteNode(&head, 2);  // Xóa nút có giá trị 2
    printf("\nDanh sach sau khi xoa nut 2: \n");
    printList(head);  // In danh sách sau khi xóa nút 2

    //return 0;
}
