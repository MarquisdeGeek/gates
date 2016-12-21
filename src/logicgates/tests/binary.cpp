#include <sstream>
#include "../gates/gates.h"
#include "tests.h"

// All tests are performed in the order:
//       b
//     F   T
//a  F 1   2
//   T 3   4

using namespace Gate::Tests;

bool
Binary::Gate::And2(std::ostream &s) {
	PinBinary r[2][2] = { 
		{ PinBinary::FalseState,		PinBinary::FalseState},
		{ PinBinary::FalseState,		PinBinary::TrueState},
	};

	s << "Binary AND test:" << std::endl;

	return TestTruthTable21<2, 2, PinBinary, BinaryGateAnd2>(s, r);
}


bool
Binary::Gate::Nand2(std::ostream &s) {
	PinBinary r[2][2] = { 
		{ PinBinary::TrueState,		PinBinary::TrueState},
		{ PinBinary::TrueState,		PinBinary::FalseState},
	};

	s << "Binary NAND test:" << std::endl;

	return TestTruthTable21<2, 2, PinBinary, BinaryGateNand2>(s, r);
}

bool
Binary::Gate::Or2(std::ostream &s) {
	PinBinary r[2][2] = { 
		{ PinBinary::FalseState,		PinBinary::TrueState},
		{ PinBinary::TrueState,			PinBinary::TrueState},
	};

	s << "Binary OR test:" << std::endl;

	return TestTruthTable21<2, 2, PinBinary, BinaryGateOr2>(s, r);
}

bool
Binary::Gate::Nor2(std::ostream &s) {
	PinBinary r[2][2] = { 
		{ PinBinary::TrueState,		PinBinary::FalseState},
		{ PinBinary::FalseState,	PinBinary::FalseState},
	};

	s << "Binary NOR test:" << std::endl;

	return TestTruthTable21<2, 2, PinBinary, BinaryGateNor2>(s, r);
}

bool
Binary::Gate::Xor2(std::ostream &s) {
	PinBinary r[2][2] = { 
		{ PinBinary::FalseState,	PinBinary::TrueState},
		{ PinBinary::TrueState,		PinBinary::FalseState},
	};

	s << "Binary XOR test:" << std::endl;

	return TestTruthTable21<2, 2, PinBinary, BinaryGateXor2>(s, r);
}

bool
Binary::Gate::Xnor2(std::ostream &s) {
	PinBinary r[2][2] = { 
		{ PinBinary::TrueState,		PinBinary::FalseState},
		{ PinBinary::FalseState,	PinBinary::TrueState},
	};

	s << "Binary XNOR test:" << std::endl;

	return TestTruthTable21<2, 2, PinBinary, BinaryGateXnor2>(s, r);
}

bool
Binary::Gate::Xor3(std::ostream &s) {
	PinBinary r[8] = { 
		PinBinary::FalseState,		
		PinBinary::TrueState,
		PinBinary::TrueState,		
		PinBinary::FalseState,
		PinBinary::TrueState,		
		PinBinary::FalseState,
		PinBinary::FalseState,		
		PinBinary::TrueState,
	};

	s << "Binary XOR3 test:" << std::endl;

	return TestTruthTable31<8, PinBinary, BinaryGateXor3>(s, r);
}

bool
Binary::Gate::Not(std::ostream &s) {
	PinBinary r[2] = { 
		 PinBinary::TrueState,			
		 PinBinary::FalseState,			
	};

	s << "Binary NOT test:" << std::endl;

	return TestTruthTable11<2, PinBinary, BinaryGateNot>(s, r);
}

//
// Combinatorial methods
//
bool
Binary::Combinatorial::HalfAdder(std::ostream &s) {
	PinBinary r[2][2][2] = { 
		{ {PinBinary::FalseState,PinBinary::FalseState},	{PinBinary::TrueState,PinBinary::FalseState}},
		{ {PinBinary::TrueState,PinBinary::FalseState},		{PinBinary::FalseState,PinBinary::TrueState}},
	};

	s << "Binary HALFADDER test:" << std::endl;

	return TestTruthTable22<2, 2, PinBinary, BinaryCombinatorialHalfAdder>(s, r);
}

bool
Binary::Combinatorial::FullAdder(std::ostream &s) {
	PinBinary r[8][2] = { 
		{PinBinary::FalseState, PinBinary::FalseState},
		{PinBinary::TrueState,  PinBinary::FalseState},
		{PinBinary::TrueState,  PinBinary::FalseState},
		{PinBinary::FalseState, PinBinary::TrueState},
		{PinBinary::TrueState,  PinBinary::FalseState},
		{PinBinary::FalseState, PinBinary::TrueState},
		{PinBinary::FalseState, PinBinary::TrueState},
		{PinBinary::TrueState,  PinBinary::TrueState},
	};

	s << "Binary FULLADDER test:" << std::endl;

	return TestTruthTable32<8, PinBinary, BinaryCombinatorialFullAdder>(s, r);
}

