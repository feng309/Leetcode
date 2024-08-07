# 指定编译器
CXX = g++

# 指定编译器选项
CXXFLAGS = -Wall -std=c++17

# 指定目标文件
TARGET = myLRUCache

# 指定源文件
SRCS = LRUCache.cpp main.cpp

# 指定生成的对象文件
OBJS = $(SRCS:.cpp=.o)

# 默认目标
all: $(TARGET)

# 链接对象文件生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 编译源文件生成对象文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理生成文件
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
