#include <iostream>
#include <string>

#include "gates/gates.h"
#include "helpers/helpers.h"
#include "tests/tests.h"

int main() {

	Gate::TestAllTernary(std::cout);
	Gate::TestAllBinary(std::cout);

	ShowTruthTable32<27, Gate::PinTernary, Gate::TernaryCombinatorialFullAdder>(std::cout);

	return 0;
}
