#include "CopyablePtr.hpp"

bool CopyablePtr::operator==(const std::nullptr_t& ptr) const
{
    return _object_ptr == ptr;
}

CopyablePtr::CopyablePtr()
    : _object_ptr { nullptr }
{}

CopyablePtr::CopyablePtr(int number)
    : _object_ptr { new Object(number) }
{}

const Object& CopyablePtr::operator*() const
{
    return *_object_ptr;
}