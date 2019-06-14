#pragma once 
#ifndef _INSUFFICIENT_FUNDS_EXCEPTION_
#define _INSUFFICIENT_FUNDS_EXCEPTION_
#include <iostream>

class Insufficient_Funds_Exception: public std::exception
{
public:
	Insufficient_Funds_Exception() = default;
	~Insufficient_Funds_Exception() = default;	
	virtual const char *what() const noexcept
	{
		return "Insufficient Funds Exception";
	}
};


#endif // _INSUFFICIENT_FUNDS_EXCEPTION_