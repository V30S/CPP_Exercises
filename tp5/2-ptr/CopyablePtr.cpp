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

void CopyablePtr::operator=(std::nullptr_t new_object)
{
    delete _object_ptr;
    _object_ptr = new_object;
}

CopyablePtr::CopyablePtr(const CopyablePtr& other)
{
    if (other._object_ptr == nullptr)
    {
        _object_ptr = nullptr;
    }
    else
    {
        _object_ptr = new Object(*other._object_ptr);
    }
}

CopyablePtr::CopyablePtr(CopyablePtr&& other)
    : _object_ptr { std::move(other._object_ptr) }
{
    other._object_ptr = nullptr;
}

CopyablePtr& CopyablePtr::operator=(const CopyablePtr& other)
{
    if (this != &other)
    {
        delete _object_ptr;
        _object_ptr = other._object_ptr != nullptr ? new Object(*other._object_ptr) : nullptr;
    }
    return *this;
}

CopyablePtr& CopyablePtr::operator=(CopyablePtr&& other)
{
    if (this != &other)
    {
        delete _object_ptr;
        _object_ptr       = std::move(other._object_ptr);
        other._object_ptr = nullptr;
    }
    return *this;
}

CopyablePtr::~CopyablePtr()
{
    delete _object_ptr;
}