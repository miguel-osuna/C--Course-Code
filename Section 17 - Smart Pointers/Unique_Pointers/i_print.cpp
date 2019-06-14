#include "i_print.h"

std::ostream &operator<<(std::ostream &os, const I_Print &obj)
{
	obj.print(os);
	return os;
}