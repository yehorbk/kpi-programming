#pragma once

class ISerializable
{
	virtual char* serialize() = 0;
	virtual char* deserialize() = 0;
};
