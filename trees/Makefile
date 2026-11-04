# Makefile для проектів Lab_04_01 та Lab_04_02

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = 

# Цілі
all: Lab_04_01 Lab_04_02

# Проект 1: Побудова та обхід простого бінарного дерева
Lab_04_01: Lab_04_01.cpp Tree.cpp Tree.h
	$(CXX) $(CXXFLAGS) -o Lab_04_01 Lab_04_01.cpp Tree.cpp $(LDFLAGS)
	@echo "Lab_04_01 успішно скомпільовано!"

# Проект 2: Бінарне дерево пошуку
Lab_04_02: Lab_04_02.cpp Tree.cpp Tree.h
	$(CXX) $(CXXFLAGS) -o Lab_04_02 Lab_04_02.cpp Tree.cpp $(LDFLAGS)
	@echo "Lab_04_02 успішно скомпільовано!"

# Запуск проекту 1
run1: Lab_04_01
	./Lab_04_01

# Запуск проекту 2
run2: Lab_04_02
	./Lab_04_02

# Очистка
clean:
	rm -f Lab_04_01 Lab_04_02 *.o

# Переомпіляція
rebuild: clean all

.PHONY: all run1 run2 clean rebuild
