#pragma once

#include "../lib/image_lib.hpp"

struct RGBA
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
}

struct RGB
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
}

struct Luma
{
    uint8_t g;
}

template <typename To, typename From>
To convert(const From& stuff);

template <>
RGBA convert<RGBA, RGBA>(const RGBA& x)
{
    return { x.r, x.g, x.b, x.a };
}

template <>
RGB convert<RGB, RGB>(const RGB& x)
{
    return { x.r, x.g, x.b };
}

template <>
Luma convert<Luma, Luma>(const Luma& x)
{
    return { x.g };
}

template <>
RGB convert<RGB, RGBA>(const RGBA& x)
{
    return { x.r, x.g, x.b };
}

template <>
RGBA convert<RGBA, RGB>(const RGB& x)
{
    return { x.r, x.g, x.b, 255 };
}

template <>
Luma convert<Luma, RGB>(const RGB& x)
{
    return { image_lib::rgb_to_grayscale(x.r, x.g, x.b) };
}

template <>
RGB convert<RGB, Luma>(const Luma& x)
{
    const auto rgb = image_lib::grayscale_to_rgb(x.g);
    return { rgb[0], rgb[1], rgb[2] };
}

template <>
Luma convert<Luma, RGBA>(const RGBA& x)
{
    return convert<Luma>(convert<RGB>(x));
}

template <>
RGBA convert<RGBA, Luma>(const Luma& x)
{
    return convert<RGBA>(convert<RGB>(x));
}

RGBA operator+(const RGBA& lhs, const RGBA& rhs)
{
    const auto mixed = image_lib::mix_color(lhs.r, lhs.g, lhs.b, lhs.a, rhs.r, rhs.g, rhs.b, rhs.a);
    return { mixed[0], mixed[1], mixed[2], mixed[3] };
}

RGB operator+(const RGB& lhs, const RGBA& rhs)
{
    const auto lhs_rgba = convert<RGBA>(lhs);
    return convert<RGB>(lhs_rgba + rhs);
}

RGB operator+(const Luma& lhs, const RGBA& rhs)
{
    const auto lhs_rgba = convert<RGBA>(lhs);
    return convert<RGB>(lhs_rgba + rhs);
}

RGBA operator+(const RGBA& lhs, const RGB& rhs)
{
    const auto rhs_rgba = convert<RGBA>(rhs);
    return lhs + rhs_rgba;
}

RGB operator+(const RGB& lhs, const RGB& rhs)
{
    const auto lhs_rgba = convert<RGBA>(lhs);
    const auto rhs_rgba = convert<RGBA>(rhs);
    return convert<RGB>(lhs_rgba + rhs_rgba);
}

RGB operator+(const Luma& lhs, const RGB& rhs)
{
    const auto lhs_rgba = convert<RGBA>(lhs);
    return convert<RGB>(lhs_rgba + rhs);
}