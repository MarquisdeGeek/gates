#ifndef _GATES_TESTS_BINARY_H
#define _GATES_TESTS_BINARY_H	1

namespace Gate {
	namespace Tests {
		namespace Binary {

			namespace Gate {							
				bool	And2(std::ostream &s);
				bool	Nand2(std::ostream &s);
				bool	Or2(std::ostream &s);
				bool	Nor2(std::ostream &s);				
				bool	Xor2(std::ostream &s);
				bool	Xnor2(std::ostream &s);
				bool	Xor3(std::ostream &s);				
				bool	Not(std::ostream &s);
			}	// Gate

			namespace Combinatorial {
				bool	HalfAdder(std::ostream &s);	
				bool	FullAdder(std::ostream &s);	
			}	// Combinatorial

		}	// Binary
	} // Tests
} // Gate

#endif	// _GATES_TESTS_BINARY_H