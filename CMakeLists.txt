# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)
add_definitions(-std=c++11)

project ("umc_tool")

set(OPENCV_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/deps/opencv/build/include)
set(OPENCV_LIB_DIR ${CMAKE_SOURCE_DIR}/deps/opencv/build/x64/vc15/lib)
set(BIN_DIR ${CMAKE_BINARY_DIR}/bin)


#设置执行文件输出目录
SET(EXECUTABLE_OUTPUT_PATH ${BIN_DIR})
#设置库输出路径
SET(LIBRARY_OUTPUT_PATH ${BIN_DIR})

include_directories(
	${CMAKE_SOURCE_DIR}/umc_company
	${OPENCV_INCLUDE_DIR}  
)

link_directories(
	${BIN_DIR}
	${OPENCV_LIB_DIR}
)

# 包含子项目。
add_subdirectory ("umc_tool")
add_subdirectory ("umc_company")

