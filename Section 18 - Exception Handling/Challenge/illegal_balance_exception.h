#pragma once
#ifndef _ILLEGAL_BALANCE_EXCEPTION_
#define _ILLEGAL_BALANCE_EXCEPTION_
#include <iostream>

class Illegal_Balance_Exception
{
public:
	Illegal_Balance_Exception() = default;
	~Illegal_Balance_Exception() = default;
	virtual const char *what() const noexcept
	{
		return "Illegal Balance Exception";
	}
};

#endif // _ILLEGAL_BALANCE_EXCEPTION_