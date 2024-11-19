/*
Factory Design Pattern là gì? 
Viết một chương trình C++ ứng dụng Factory design pattern.
*/

/*
Factory Design Pattern là một mẫu thiết kế trong lập trình, dùng để tạo đối tượng 
mà không cần phải chỉ rõ lớp cụ thể của đối tượng đó trong mã nguồn chính.

Thay vì sử dụng new để tạo đối tượng, thì mình yêu cầu một lớp Factory (nhà máy) thực hiện việc này. 
Factory sẽ tự quyết định và trả về đối tượng phù hợp dựa trên thông tin mà người dùng cung cấp 
*/

#include <iostream>
#include <memory>
#include <string>
#include "bai5.h"

// Lớp cơ sở (Base class) đại diện cho động vật
class Animal {
public:
    virtual void makeSound() const = 0; // Hàm ảo (pure virtual function), buộc lớp con phải định nghĩa.
    virtual ~Animal() = default;       // Destructor ảo để đảm bảo hủy đối tượng lớp con đúng cách.
};

// Lớp dẫn xuất (Derived class): Mèo (Cat)
class Cat : public Animal {
public:
    void makeSound() const override {   // Ghi đè (override) phương thức makeSound để in âm thanh của mèo.
        std::cout << "Meo! Meo!\n";   // Hiển thị tiếng mèo kêu.
    }
};

// Lớp dẫn xuất (Derived class): Chó (Dog)
class Dog : public Animal {
public:
    void makeSound() const override {   // Ghi đè (override) phương thức makeSound để in âm thanh của chó.
        std::cout << "Woof! Woof!\n";   // Hiển thị tiếng chó sủa.
    }
};

// Lớp nhà máy (Factory class) chịu trách nhiệm tạo đối tượng động vật
class AnimalFactory {
public:
    // Phương thức tĩnh tạo đối tượng động vật dựa trên loại đầu vào (type)
    static std::unique_ptr<Animal> createAnimal(const std::string& type) {
        if (type == "cat") {                    // Nếu yêu cầu "cat"
            return std::make_unique<Cat>();     // Trả về đối tượng Mèo (Cat)
        } else if (type == "dog") {             // Nếu yêu cầu "dog"
            return std::make_unique<Dog>();     // Trả về đối tượng Chó (Dog)
        } else {
            return nullptr;                     // Nếu không hợp lệ, trả về con trỏ rỗng (nullptr)
        }
    }
};

// Hàm chính (Main function)
void bai5() {
    std::string choice; // Chuỗi để lưu loại động vật được người dùng nhập

    std::cout << "Enter animal type (cat/dog): "; // Yêu cầu người dùng nhập loại động vật
    std::cin >> choice;                          // Đọc giá trị đầu vào từ người dùng

    auto animal = AnimalFactory::createAnimal(choice); // Gọi phương thức factory để tạo đối tượng động vật

    if (animal) {                  // Nếu đối tượng hợp lệ (không phải nullptr)
        animal->makeSound();       // Gọi phương thức makeSound để hiển thị âm thanh của động vật
    } else {                       // Nếu đối tượng không hợp lệ
        std::cout << "Invalid animal type.\n"; // Thông báo loại động vật không hợp lệ
    }
}
