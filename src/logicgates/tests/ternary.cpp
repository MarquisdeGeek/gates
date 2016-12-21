#include <sstream>
#include "../gates/gates.h"
#include "tests.h"


using namespace Gate::Tests;

bool
Ternary::Gate::And2(std::ostream &s) {
	PinTernary r[3][3] = { 
		{ PinTernary::FalseState,	PinTernary::FalseState,			PinTernary::FalseState},
		{ PinTernary::FalseState,	PinTernary::UndeterminedState,	PinTernary::UndeterminedState},
		{ PinTernary::FalseState,	PinTernary::UndeterminedState,	PinTernary::TrueState},
	};

	s << "Ternary AND test:" << std::endl;

	return TestTruthTable21<3, 3, PinTernary, TernaryGateAnd2>(s, r);
}

bool
Ternary::Gate::Nand2(std::ostream &s) {
	PinTernary r[3][3] = { 
		{ PinTernary::TrueState,		PinTernary::TrueState,			PinTernary::TrueState},
		{ PinTernary::TrueState,		PinTernary::UndeterminedState,	PinTernary::UndeterminedState},
		{ PinTernary::TrueState,		PinTernary::UndeterminedState,	PinTernary::FalseState},
	};

	s << "Ternary NAND test:" << std::endl;

	return TestTruthTable21<3, 3, PinTernary, TernaryGateNand2>(s, r);
}

bool
Ternary::Gate::Nor2(std::ostream &s) {
	PinTernary r[3][3] = { 
		{ PinTernary::TrueState,			PinTernary::UndeterminedState,	PinTernary::FalseState},
		{ PinTernary::UndeterminedState,	PinTernary::UndeterminedState,	PinTernary::FalseState},
		{ PinTernary::FalseState,			PinTernary::FalseState,			PinTernary::FalseState},
	};

	s << "Ternary NOR test:" << std::endl;

	return TestTruthTable21<3, 3, PinTernary, TernaryGateNor2>(s, r);
}

bool
Ternary::Gate::Xor2(std::ostream &s) {
	PinTernary r[3][3] = { 
		{ PinTernary::FalseState,			PinTernary::UndeterminedState,	PinTernary::TrueState},
		{ PinTernary::UndeterminedState,	PinTernary::UndeterminedState,	PinTernary::UndeterminedState},
		{ PinTernary::TrueState,			PinTernary::UndeterminedState,	PinTernary::FalseState},
	};

	s << "Ternary XOR test:" << std::endl;

	return TestTruthTable21<3, 3, PinTernary, TernaryGateXor2>(s, r);
}

bool
Ternary::Gate::Xnor2(std::ostream &s) {
	PinTernary r[3][3] = { 
		{ PinTernary::TrueState,			PinTernary::UndeterminedState,	PinTernary::FalseState},
		{ PinTernary::UndeterminedState,	PinTernary::UndeterminedState,	PinTernary::UndeterminedState},
		{ PinTernary::FalseState,			PinTernary::UndeterminedState,	PinTernary::TrueState},
	};

	s << "Ternary XNOR test:" << std::endl;

	return TestTruthTable21<3, 3, PinTernary, TernaryGateXnor2>(s, r);
}

bool
Ternary::Gate::Or2(std::ostream &s) {
	PinTernary r[3][3] = { 
		{ PinTernary::FalseState,			PinTernary::UndeterminedState,	PinTernary::TrueState},
		{ PinTernary::UndeterminedState,	PinTernary::UndeterminedState,	PinTernary::TrueState},
		{ PinTernary::TrueState,			PinTernary::TrueState,			PinTernary::TrueState},
	};

	s << "Ternary OR test:" << std::endl;

	return TestTruthTable21<3, 3, PinTernary, TernaryGateOr2>(s, r);
}

bool
Ternary::Gate::Not(std::ostream &s) {
	PinTernary r[3] = { 
		 PinTernary::TrueState,			
		 PinTernary::UndeterminedState,	
		 PinTernary::FalseState,			
	};

	s << "Ternary NOT test:" << std::endl;

	return TestTruthTable11<3, PinTernary, TernaryGateNot>(s, r);
}

//
// Combinatorial methods
//
bool
Ternary::Combinatorial::HalfAdder(std::ostream &s) {
	PinTernary r[3][3][2] = { 
		{ {PinTernary::F,PinTernary::F},	{PinTernary::U,PinTernary::F},	{PinTernary::T,PinTernary::F}},
		{ {PinTernary::U,PinTernary::F},	{PinTernary::U,PinTernary::U},	{PinTernary::U,PinTernary::U}},
		{ {PinTernary::T,PinTernary::F},	{PinTernary::U,PinTernary::U},	{PinTernary::F,PinTernary::T}},
	};

	s << "Ternary HalfAdder test:" << std::endl;

	return TestTruthTable22<3, 3, PinTernary, TernaryCombinatorialHalfAdder>(s, r);
}

bool
Ternary::Combinatorial::FullAdder(std::ostream &s) {
	PinTernary r[27][2] = { 
		{PinTernary::F, PinTernary::F},
		{PinTernary::U, PinTernary::F},
		{PinTernary::T, PinTernary::F},
		{PinTernary::U, PinTernary::F},
		{PinTernary::U, PinTernary::U},
		{PinTernary::U, PinTernary::U},
		{PinTernary::T, PinTernary::F},
		{PinTernary::U, PinTernary::U},
		{PinTernary::F, PinTernary::T},

		{PinTernary::U, PinTernary::F},
		{PinTernary::U, PinTernary::U},
		{PinTernary::U, PinTernary::U},
		{PinTernary::U, PinTernary::U},
		{PinTernary::U, PinTernary::U},
		{PinTernary::U, PinTernary::U},
		{PinTernary::U, PinTernary::U},
		{PinTernary::U, PinTernary::U},
		{PinTernary::U, PinTernary::T},

		{PinTernary::T, PinTernary::F},
		{PinTernary::U, PinTernary::U},
		{PinTernary::F, PinTernary::T},
		{PinTernary::U, PinTernary::U},
		{PinTernary::U, PinTernary::U},
		{PinTernary::U, PinTernary::U},
		{PinTernary::F, PinTernary::T},
		{PinTernary::U, PinTernary::U},
		{PinTernary::T, PinTernary::T},
	};

	s << "Ternary FullAdder test:" << std::endl;

	return TestTruthTable32<27, PinTernary, TernaryCombinatorialFullAdder>(s, r);
}

