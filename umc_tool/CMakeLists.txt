# CMakeList.txt: umc_tool 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

include_directories(
	${CMAKE_SOURCE_DIR}/umc_company
	${OPENCV_INCLUDE_DIR}  
)

link_directories(
	${LIB_DIR}
	${OPENCV_LIB_DIR}
)

# 将源代码添加到此项目的可执行文件。
add_executable (umc_tool "umc_tool.cpp" "umc_tool.h")

target_link_libraries(umc_tool umc_company)

