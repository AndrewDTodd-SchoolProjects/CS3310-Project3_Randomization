#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include<cstdint>
#include<utility>

#include "RandomRange.h"

namespace QuickSort
{
    template <typename T>
    T LeftPivot(T* arr, const uint32_t& left, const uint32_t& right)
    {
        return left;
    }

    template <typename T>
    T RightPivot(T* arr, const uint32_t& left, const uint32_t& right)
    {
        return right;
    }

    template <typename T>
    T RandomPivot(T* arr, const uint32_t& left, const uint32_t& right)
    {
        return RandomRange<uint32_t>(left, right);
    }

    template <typename T>
    T MedianThreePivot(T* arr, const uint32_t& left, const uint32_t& right)
    {
        uint32_t first = RandomRange<uint32_t>(left, right);
        uint32_t second = RandomRange<uint32_t>(left, right);
        uint32_t third = RandomRange<uint32_t>(left, right);

        if ((arr[first] >= arr[second] && arr[first] <= arr[third]) || (arr[first] <= arr[second] && arr[first] >= arr[third]))
        {
            return first;
        }
        else if ((arr[second] >= arr[first] && arr[second] <= arr[third]) || (arr[second] <= arr[first] && arr[second] >= arr[third]))
        {
            return second;
        }
        else
            return third;
    }
    
    template<typename T> 
    using ChoosePivot = T(*)(T* arr, const uint32_t& left, const uint32_t& right);

    template <typename T>
    uint32_t Partition(T* arr, const uint32_t& left, const uint32_t& right)
    {
        T pivot = arr[right];
        int i = left - 1;

        for (int j = left; j < right; j++)
        {
            if (arr[j] < pivot)
            {
                i++;

                T old = std::move(arr[i]);
                arr[i] = std::move(arr[j]);
                arr[j] = std::move(old);
            }
        }

        T old = std::move(arr[i + 1]);
        arr[i + 1] = std::move(arr[right]);
        arr[right] = std::move(old);

        return i + 1;
    }

    template <typename T>
    void QuickSort(T* arr, const uint32_t& left, const uint32_t& right, uint64_t& compCount)
    {
        if (left < right)
        {
            compCount += right - left;

            uint32_t boundry = Partition(arr, left, right);

            if (boundry > left)
                QuickSort<T>(arr, left, boundry - 1, compCount);
            if (boundry < right)
                QuickSort<T>(arr, boundry + 1, right, compCount);
        }
    }

    template <typename T>
    void QuickSort(T* arr, const uint32_t& arraySize, ChoosePivot<T> pivotMethod, uint64_t& compCount)
    {
        T pivot = pivotMethod(arr, 0, arraySize - 1);

        T old = std::move(arr[arraySize - 1]);
        arr[arraySize - 1] = std::move(arr[pivot]);
        arr[pivot] = std::move(old);

        QuickSort<T>(arr, 0, arraySize - 1, compCount);
    }
}

#endif // !QUICK_SORT_H

