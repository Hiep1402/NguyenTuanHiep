/*
- Singleton Pattern dùng để tạo một lớp chỉ có duy nhất một thể hiện (instance) 
trong toàn bộ ứng dụng và cung cấp một phương thức để truy cập đối tượng đó.
- Constructor của lớp là private để không cho việc tạo đối tượng từ ngoài.
- Chỉ có 1 đối tượng nên tiết kiệm bộ nhớ, tuy nhiên khó cho việc mở rộng hoặc thay đổi đối tượng
*/

#include <iostream>
#include "bai4.h"
using namespace std;

// Lớp Singleton Animal
class Animal {
private:
    // Con trỏ static duy nhất
    static Animal* instance;

    // Constructor private để ngăn chặn tạo các đối tượng mới ngoài getInstance
    Animal() {
        cout << "Singleton Animal instance created!" << endl;
    }

public:
    // Phương thức để truy cập thể hiện Animal
    static Animal* getInstance() {
        if (instance == nullptr) {
            instance = new Animal();
        }
        return instance;
    }

    // Phương thức mẫu để in thông điệp
    void speak() {
        cout << "Hello from the Singleton Animal!" << endl;
    }

    // Destructor để hủy thể hiện Singleton
    ~Animal() {
        cout << "Singleton Animal instance destroyed!" << endl;
    }
};

// Khởi tạo con trỏ instance là nullptr
Animal* Animal::instance = nullptr;

void bai4() {
    // Truy cập thể hiện duy nhất của Animal
    Animal* animal1 = Animal::getInstance();
    animal1->speak();  // Gọi phương thức speak của Animal

    // Thử truy cập lại (cả hai sẽ trỏ đến cùng một thể hiện)
    Animal* animal2 = Animal::getInstance();
    animal2->speak();  // Gọi phương thức speak của Animal

    // Kiểm tra xem cả hai con trỏ có trỏ đến cùng một đối tượng không
    if (animal1 == animal2) {
        cout << "animal1 and animal2 are the same instance!" << endl;
    }

    // Hủy thể hiện của Singleton (gọi Destructor)
    delete animal1;  // Hủy instance

}