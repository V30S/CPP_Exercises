#pragma once

#include <array>
#include <functional>

template <typename P, size_t W, size_t H>
class Image
{
public:
    Image() = default;

    Image(const P& pixel)
    {
        for (size_t i = 0; i < H; ++i)
        {
            for (size_t j = 0; j < W; ++j)
            {
                pixels[i][j] = pixel;
            }
        }
    }

    Image(const std::function<P(size_t i, size_t j)>& f)
    {
        for (size_t i = 0; i < H; ++i)
        {
            for (size_t j = 0; j < W; ++j)
            {
                pixels[i][j] = f(i, j);
            }
        }
    }

    const P& operator()(size_t i, size_t j) const { return pixels[j][i]; }

    P& operator()(size_t i, size_t j) { return pixels[j][i]; }

    const Image& operator+=(const Image& other)
    {
        Image result;
        for (size_t i = 0; i < W; ++i)
        {
            for (size_t j = 0; j < H; ++j)
            {
                result(i, j) = (*this)(i, j) + other(i, j);
            }
        }
        return result;
    }

private:
    std::array<std::array<P, W>, H> pixels;
};