#include "CopyablePtr.hpp"

bool CopyablePtr::operator==(const std::nullptr_t& ptr) const
{
    return _object_ptr == ptr;
}