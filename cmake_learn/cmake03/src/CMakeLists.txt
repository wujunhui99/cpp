ADD_EXECUTABLE(hello main.cpp)
INCLUDE_DIRECTORIES(/usr/include/hello)
TARGET_LINK_LIBRARIES(hello libhello.so)
