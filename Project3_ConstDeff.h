#ifndef PROJECT2_DEFFS_H
#define PROJECT2_DEFFS_H

//#define PRINT_DEBUG_INFO

#include <chrono>
#include <vector>

#define TIME_METHOD(method) \
	auto startTime = std::chrono::high_resolution_clock::now(); \
	uint64_t inversionCount = 0; \
	method; \
	auto endTime = std::chrono::high_resolution_clock::now(); \
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

constexpr auto ARRAY_SIZE = 100000;
constexpr auto ITTR = 100;
constexpr auto TARGET_RANK = 4;

#endif // !PROJECT2_DEFFS_H
