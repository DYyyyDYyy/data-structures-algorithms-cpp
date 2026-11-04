# Makefile для Лабораторної роботи №5 - Піраміди

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Файли бібліотеки
LIB_SOURCES = Heap.cpp
LIB_OBJECTS = $(LIB_SOURCES:.cpp=.o)

# Цілі проекти
TARGET1 = Lab_05_01
TARGET2 = Lab_05_02

# Всі цілі
all: $(TARGET1) $(TARGET2)

# Компіляція Lab_05_01
$(TARGET1): Lab_05_01.o $(LIB_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET1) Lab_05_01.o $(LIB_OBJECTS)
	@echo "✓ $(TARGET1) скомпільовано успішно!"

# Компіляція Lab_05_02
$(TARGET2): Lab_05_02.o $(LIB_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET2) Lab_05_02.o $(LIB_OBJECTS)
	@echo "✓ $(TARGET2) скомпільовано успішно!"

# Компіляція об'єктних файлів
%.o: %.cpp Heap.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Запуск першої частини
run1: $(TARGET1)
	@echo "Запуск $(TARGET1)..."
	@./$(TARGET1)

# Запуск другої частини
run2: $(TARGET2)
	@echo "Запуск $(TARGET2)..."
	@./$(TARGET2)

# Очищення
clean:
	rm -f *.o $(TARGET1) $(TARGET2)
	@echo "✓ Очищено всі скомпільовані файли"

# Перекомпіляція
rebuild: clean all

.PHONY: all clean rebuild run1 run2
