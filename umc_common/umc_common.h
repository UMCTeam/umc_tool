#ifndef UMC_COMMON_H
#	define UMC_COMMON_API _declspec(dllexport)
#else
#   define UMC_ADB_API __declspec(dllimport)
#endif

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "umc_opencv.h"
#include "umc_logger.h"

UMC_COMMON_API void executeCMD(const char* cmd, char* result);