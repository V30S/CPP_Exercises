#pragma once

#include <array>
#include <utility>
#include <vector>

template <typename T, int Size>
class HybridArray
{
public:
    static constexpr int static_size() { return Size; }

    auto& push_back(T value)
    {
        if (_index < Size)
        {
            return _ctn_array[_index++] = std::move(value);
        }
        else if (_index == Size && _ctn_vector.empty())
        {
            _ctn_vector.insert(_ctn_vector.begin(), _ctn_array.begin(), _ctn_array.end());
            return _ctn_vector.emplace_back(std::move(value));
        }
        return _ctn_vector.emplace_back(std::move(value));
    }

    int size() const { return _ctn_vector.empty() ? _index : _ctn_vector.size(); }

    T& operator[](int index) { return _ctn_vector.empty() ? _ctn_array[index] : _ctn_vector[index]; }

    const T& operator[](int index) const
    {
        return _ctn_vector.empty() ? _ctn_array[index] : _ctn_vector[index];
    }

    template <typename... Args>
    HybridArray(Args&&... args)
    {
        (push_back(std::forward<Args>(args)), ...);
    }

private:
    std::array<T, Size> _ctn_array;
    int                 _index = 0;
    std::vector<T>      _ctn_vector;
};

template <typename T>
class HybridArray<T, 0> : public std::vector<T>
{
    using std::vector<T>::vector;
};