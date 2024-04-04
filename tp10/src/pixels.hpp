#pragma once

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