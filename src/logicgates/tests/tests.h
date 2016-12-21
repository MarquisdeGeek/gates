#ifndef _GATES_TESTS_H
#define _GATES_TESTS_H	1

#include "truth_table.h"
#include "ternary.h"
#include "binary.h"

namespace Gate {
	void	TestAllBinary(std::ostream &s);
	void	TestAllTernary(std::ostream &s);
}

#endif // _GATES_TESTS_H
