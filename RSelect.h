#ifndef R_SELECT_H
#define R_SELECT_H

#include<cstdint>
#include<utility>

#include "RandomRange.h"

namespace RSelect
{
    template<typename T>
    using ChoosePivot = T(*)(T* arr, const uint32_t& left, const uint32_t& right);

    template <typename T>
    uint32_t Partition(T* arr, const uint32_t& left, const uint32_t& right, ChoosePivot<T> pivotMethod)
    {
        T pivotIndex = pivotMethod(arr, left, right);

        T old = std::move(arr[right]);
        arr[right] = std::move(arr[pivotIndex]);
        arr[pivotIndex] = std::move(old);

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

        old = std::move(arr[i + 1]);
        arr[i + 1] = std::move(arr[right]);
        arr[right] = std::move(old);

        return i + 1;
    }

    template <typename T>
    T RSelect(T* arr, const uint32_t& left, const uint32_t& right, const uint32_t& target, ChoosePivot<T> pivotMethod, uint64_t& compCount)
    {
        if (left <= right)
        {

            compCount += right - left;

            T pivotIndex = Partition(arr, left, right, pivotMethod);
            T pivotRank = pivotIndex - left + 1;

            if (target == pivotRank)
            {
                return arr[pivotIndex];
            }
            else if (target < pivotRank)
            {
                return RSelect(arr, left, pivotIndex - 1, target, pivotMethod, compCount);
            }
            else
                return RSelect(arr, pivotIndex + 1, right, target - pivotRank, pivotMethod, compCount);
        }
        else
        {
            throw std::invalid_argument("Invalid indices");
        }
    }

    /*template <typename T>
    void RSelect(T* arr, const uint32_t& arraySize, T(*ChoosePivot)(T* arr, const uint32_t& left, const uint32_t& right), uint64_t& compCount)
    {
        T pivot = ChoosePivot(arr, 0, arraySize - 1);

        T old = std::move(arr[arraySize - 1]);
        arr[arraySize - 1] = std::move(arr[pivot]);
        arr[pivot] = std::move(old);

        RSelect<T>(arr, 0, arraySize - 1, compCount);
    }*/
}

#endif // !R_SELECT_H

