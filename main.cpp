#include <iostream>
#include "inc/bai4.h"
#include "inc/bai5.h"

// Chọn bài
#define BAI_1
//#define BAI_2
//#define BAI_3
//#define BAI_4
//#define BAI_5

#ifdef BAI_1
extern "C" void bai1();  // Khai báo hàm bài 1 (C)
#endif

#ifdef BAI_2
extern "C" void bai2();  // Khai báo hàm bài 2 (C)
#endif

#ifdef BAI_3
extern "C" void bai3();  // Khai báo hàm bài 3 (C)
#endif

#ifdef BAI_4
void bai4();  // Khai báo hàm bài 4 (C++)
#endif

#ifdef BAI_5
void bai5();  // Khai báo hàm bài 5 (C++)
#endif

int main() {
    std::cout << "\nChuong trinh bat dau...\n";
    
    #ifdef BAI_1
        bai1();  // Gọi bài 1
    #endif

    #ifdef BAI_2
        bai2();  // Gọi bài 2
    #endif

    #ifdef BAI_3
        bai3();  // Gọi bài 3
    #endif

    #ifdef BAI_4
        bai4();  // Gọi bài 4
    #endif

     #ifdef BAI_5
        bai5();  // Gọi bài 5
    #endif

    return 0;
}

