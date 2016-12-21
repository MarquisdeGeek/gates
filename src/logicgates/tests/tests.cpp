#include <sstream>
#include "../gates/gates.h"
#include "tests.h"

using namespace Gate::Tests;

void
Gate::TestAllBinary(std::ostream &s) {
	bool allclear = true;

	allclear &= Binary::Gate::And2(s);
	allclear &= Binary::Gate::Nand2(s);
	allclear &= Binary::Gate::Or2(s);
	allclear &= Binary::Gate::Nor2(s);	
	allclear &= Binary::Gate::Xor2(s);
	allclear &= Binary::Gate::Xnor2(s);
	allclear &= Binary::Gate::Xor3(s);
	allclear &= Binary::Gate::Not(s);	
	//
	allclear &= Binary::Combinatorial::HalfAdder(s);
	allclear &= Binary::Combinatorial::FullAdder(s);
	//
	if (allclear) {
		s << "*** Binary tests all work" << std::endl;
	} else {
		s << "*** There were one or more problems in binary tests. Please check ***" << std::endl;
	}
}

void
Gate::TestAllTernary(std::ostream &s) {
	bool allclear = true;

	allclear &= Ternary::Gate::And2(s);
	allclear &= Ternary::Gate::Nand2(s);
	allclear &= Ternary::Gate::Or2(s);
	allclear &= Ternary::Gate::Nor2(s);	
	allclear &= Ternary::Gate::Xor2(s);
	allclear &= Ternary::Gate::Xnor2(s);
	allclear &= Ternary::Gate::Not(s);
	//
	allclear &= Ternary::Combinatorial::HalfAdder(s);
	allclear &= Ternary::Combinatorial::FullAdder(s);
	//
	if (allclear) {
		s << "*** Binary tests all work" << std::endl;
	} else {
		s << "*** There were one or more problems in binary tests. Please check ***" << std::endl;
	}
}
