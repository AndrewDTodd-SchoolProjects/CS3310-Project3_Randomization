#include <limits>
#include <iostream>
#include <string>
#include <algorithm>

#include "Project3_ConstDeff.h"

#include "ArrayGen.h"
#include "ArrayFromFile.h"

#include "QuickSort.h"

int main(int argc, char* argv[])
{
	int* array = nullptr;
	uint32_t arraySize = 0;
	uint32_t itterations = ITTR;
	
	
	if (argc < 2)
	{
		array = new int[ARRAY_SIZE];
		arraySize = ARRAY_SIZE;

		GenerateRandomArray(array, ARRAY_SIZE, 1, std::numeric_limits<int>::max());
	}
	else
	{
		try
		{
			array = ArrayFromFile(argv[1], &arraySize);
			if(argc == 3)
				itterations = std::stoi(argv[2]);
		}
		catch (std::invalid_argument argEx)
		{
			std::cerr << argEx.what() << std::endl;

			return 1;
		}
	}
	

	//Testing block to read a specified file with number list while in debug
	/*
	try
	{
		array = ArrayFromFile("../../LotsOfNum.txt", &arraySize);
	}
	catch (std::invalid_argument argEx)
	{
		std::cerr << argEx.what() << std::endl;

		return 1;
	}
	*/

	//can be used for testing
	//int array[] = { 54044, 14108, 79294, 29649, 25260, 60660, 2995, 53777, 49689, 9083 };

	int* copyArray = new int[arraySize];

#ifdef PRINT_DEBUG_INFO
	std::cout << "Array pre sort:" << std::endl;
	std::cout << "[ ";
	for (uint32_t i = 0; i < arraySize; i++)
	{
		std::cout << array[i] << ", ";
	}
	std::cout << " ]" << std::endl;
#endif // PRINT_DEBUG_INFO

	//Call quicksort with LeftPivot
	std::chrono::milliseconds total = std::chrono::milliseconds();
	std::chrono::milliseconds fastest = std::chrono::milliseconds();
	std::chrono::milliseconds slowest = std::chrono::milliseconds();
	uint64_t compCountTotal = 0;
	for (int leftIttr = 0; leftIttr < itterations; leftIttr++)
	{
		std::copy(array, array + arraySize, copyArray);

		auto startTime = std::chrono::high_resolution_clock::now();
		uint64_t inversionCount = 0;
		QuickSort::QuickSort(copyArray, arraySize, QuickSort::LeftPivot, compCountTotal);
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

		total += duration;

		if (duration < fastest || leftIttr == 0)
			fastest = duration;
		else if (duration > slowest)
			slowest = duration;
	}

	std::cout << "Quicksort called with LeftPivot for " << itterations << " itterations: " << std::endl <<
		"Average execution time: " << total.count() / itterations << " milliseconds" << std::endl <<
		"Fastest execution time: " << fastest.count() << " milliseconds" << std::endl <<
		"Slowest execution time: " << slowest.count() << " milliseconds" << std::endl <<
		"Counted " << compCountTotal / itterations << " comparisons per itteration" << std::endl << std::endl;

	compCountTotal = 0;
	//Call quicksort with RightPivot
	for (int leftIttr = 0; leftIttr < itterations; leftIttr++)
	{
		std::copy(array, array + arraySize, copyArray);

		auto startTime = std::chrono::high_resolution_clock::now();
		uint64_t inversionCount = 0;
		QuickSort::QuickSort(copyArray, arraySize, QuickSort::RightPivot, compCountTotal);
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

		total += duration;

		if (duration < fastest || leftIttr == 0)
			fastest = duration;
		else if (duration > slowest)
			slowest = duration;
	}

	std::cout << "Quicksort called with RightPivot for " << itterations << " itterations: " << std::endl <<
		"Average execution time: " << total.count() / itterations << " milliseconds" << std::endl <<
		"Fastest execution time: " << fastest.count() << " milliseconds" << std::endl <<
		"Slowest execution time: " << slowest.count() << " milliseconds" << std::endl <<
		"Counted " << compCountTotal / itterations << " comparisons per itteration" << std::endl << std::endl;

	compCountTotal = 0;
	//Call quicksort with RandomPivot
	for (int leftIttr = 0; leftIttr < itterations; leftIttr++)
	{
		std::copy(array, array + arraySize, copyArray);

		auto startTime = std::chrono::high_resolution_clock::now();
		uint64_t inversionCount = 0;
		QuickSort::QuickSort(copyArray, arraySize, QuickSort::RandomPivot, compCountTotal);
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

		total += duration;

		if (duration < fastest || leftIttr == 0)
			fastest = duration;
		else if (duration > slowest)
			slowest = duration;
	}

	std::cout << "Quicksort called with RandomPivot for " << itterations << " itterations: " << std::endl <<
		"Average execution time: " << total.count() / itterations << " milliseconds" << std::endl <<
		"Fastest execution time: " << fastest.count() << " milliseconds" << std::endl <<
		"Slowest execution time: " << slowest.count() << " milliseconds" << std::endl <<
		"Counted " << compCountTotal / itterations << " comparisons per itteration" << std::endl << std::endl;

	std::copy(array, array + arraySize, copyArray);
	compCountTotal = 0;
	//Call quicksort with MedianThreePivot
	for (int leftIttr = 0; leftIttr < itterations; leftIttr++)
	{
		std::copy(copyArray, copyArray + arraySize, array);

		auto startTime = std::chrono::high_resolution_clock::now();
		uint64_t inversionCount = 0;
		QuickSort::QuickSort(array, arraySize, QuickSort::MedianThreePivot, compCountTotal);
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

		total += duration;

		if (duration < fastest || leftIttr == 0)
			fastest = duration;
		else if (duration > slowest)
			slowest = duration;
	}

	std::cout << "Quicksort called with MedianThreePivot for " << itterations << " itterations: " << std::endl <<
		"Average execution time: " << total.count() / itterations << " milliseconds" << std::endl <<
		"Fastest execution time: " << fastest.count() << " milliseconds" << std::endl <<
		"Slowest execution time: " << slowest.count() << " milliseconds" << std::endl <<
		"Counted " << compCountTotal / itterations << " comparisons per itteration" << std::endl << std::endl;

#ifdef PRINT_DEBUG_INFO
	std::cout << "Array post sort:" << std::endl;
	std::cout << "[ ";
	for (uint32_t i = 0; i < arraySize; i++)
	{
		std::cout << array[i] << ", ";
	}
	std::cout << " ]" << std::endl;
#endif // PRINT_DEBUG_INFO

	delete[] array, copyArray;

	return 0;
}
