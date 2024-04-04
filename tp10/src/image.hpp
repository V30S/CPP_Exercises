#pragma once

#include <array>

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

    const P& operator()(size_t i, size_t j) const { return pixels[j][i]; }

    P& operator()(size_t i, size_t j) { return pixels[j][i]; }

private:
    std::array<std::array<P, W>, H> pixels;
};