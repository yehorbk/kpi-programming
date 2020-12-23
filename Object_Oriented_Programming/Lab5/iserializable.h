#pragma once

template <typename T>
class ISerializable
{
public:
    virtual const char* serialize() = 0;
};
