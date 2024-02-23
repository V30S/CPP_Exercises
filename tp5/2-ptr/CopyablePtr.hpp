#pragma once

#include "Object.hpp"

class CopyablePtr
{
private:
    Object* _object_ptr;

public:
    bool operator==(const std::nullptr_t& ptr) const;

    CopyablePtr();

    CopyablePtr(int number);

    const Object& operator*() const;

    void operator=(std::nullptr_t new_object);

    CopyablePtr(const CopyablePtr& other);

    CopyablePtr(CopyablePtr&& other);
};
