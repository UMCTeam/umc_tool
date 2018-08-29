# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("umc_company_dll")

set(UMC_COMPANY_SRC umc_company.cpp)

include_directories(
	${CMAKE_SOURCE_DIR}/umc_company
)

add_library(umc_company_static STATIC ${UMC_COMPANY_SRC})
add_library(umc_company SHARED ${UMC_COMPANY_SRC})

# 指定静态库的输出名称
set_target_properties(umc_company_static PROPERTIES OUTPUT_NAME "umc_company")