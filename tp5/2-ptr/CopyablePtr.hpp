#pragma once

#include "Object.hpp"

class CopyablePtr
{
private:
    Object* _object_ptr = nullptr;

public:
    bool operator==(const std::nullptr_t& ptr) const;
};
