#include <stdio.h>
#include <stdlib.h>
//#include "bai2.h"

// Định nghĩa cấu trúc của một nút
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tạo nút mới
Node* createNode2(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Cấp phát bộ nhớ cho nút mới
    newNode->data = data;                         // Gán giá trị vào data
    newNode->next = NULL;                         // Gán con trỏ next của nút mới = NULL
    return newNode;                               // Trả về con trỏ đến nút mới tạo
}

// Hàm thêm nút vào đầu danh sách
void addNodeToHead2(Node** head, int data) {
    Node* newNode = createNode2(data);  // Tạo nút mới
    newNode->next = *head;             // Con trỏ next của nút mới trỏ đến nút đầu (head)
    *head = newNode;                   // Đổi con trỏ head để trỏ đến nút mới
}

// Hàm thêm nút vào cuối danh sách
void addNodeToTail2(Node** head, int data) {
    Node* newNode = createNode2(data);
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

// Hàm in danh sách
void printList2(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Hàm tìm giá trị lớn nhất và nhỏ nhất trong danh sách
void findMinMax2(Node* head, int* min, int* max) {
    if (head == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    
    // Khởi tạo min và max với giá trị của nút đầu tiên
    *min = head->data;
    *max = head->data;
    
    Node* temp = head->next;
    
    while (temp != NULL) {
        if (temp->data < *min) {
            *min = temp->data;  // Cập nhật min
        }
        if (temp->data > *max) {
            *max = temp->data;  // Cập nhật max
        }
        temp = temp->next;
    }
}

// Hàm main để kiểm tra
void bai2() {
    Node* head = NULL;
    int value;

    printf("Nhap 10 gia tri cho danh sach lien ket:\n");
    
    // Nhập thủ công 10 giá trị từ bàn phím
    for (int i = 0; i < 10; i++) {
        printf("Nhap gia tri cho nut %d: ", i+1);
        scanf("%d", &value);
        addNodeToTail2(&head, value);  // Thêm nút vào cuối danh sách
    }

    // In danh sách ban đầu
    printf("\nDanh sach ban dau: \n");
    printList2(head);

    // Tìm giá trị lớn nhất và nhỏ nhất trong danh sách
    int min, max;
    findMinMax2(head, &min, &max);

    printf("\nGia tri nho nhat trong danh sach: %d\n", min);
    printf("Gia tri lon nhat trong danh sach: %d\n", max);

}
