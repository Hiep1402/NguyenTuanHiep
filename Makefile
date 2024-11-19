CC = gcc
CXX = g++
CFLAGS = -Wall -g
CXXFLAGS = -Wall -g
INCDIR = -I./inc

SRC = src/bai1.c src/bai2.c src/bai3.c src/bai4.cpp src/bai5.cpp
OBJ = src/bai1.o src/bai2.o src/bai3.o src/bai4.o src/bai5.o main.o
TARGET = run

# Biên dịch các file .c thành .o
src/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

# Biên dịch các file .cpp thành .o
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCDIR) -c $< -o $@

# Liên kết các file .o thành file thực thi
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Clean up: Xóa các file đối tượng và file thực thi
clean:
	rm -f $(OBJ) $(TARGET)

# Tạo thư mục obj nếu chưa có
obj:
	mkdir -p obj

# Phục hồi các thư mục con (nếu cần)
.PHONY: clean obj