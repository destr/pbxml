cmake_minimum_required(VERSION 3.11)
project(pb2xml)

find_package(Protobuf REQUIRED)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES cpp/xml_format.cc main.cpp)

set(HEADERS cpp/xml_format.h)

set(ProtoFiles
    test/proto/addressbook.proto
)
set(PROTOBUF_IMPORT_DIRS ${PROTOBUF_INCLUDE_DIRS})
set(PROTOBUF_GENERATE_CPP_APPEND_PATH FALSE)

PROTOBUF_GENERATE_CPP(ProtoSources ProtoHeaders ${ProtoFiles})

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${ProtoSources} ${ProtoHeaders})
target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARY})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
