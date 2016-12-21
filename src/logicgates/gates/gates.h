#ifndef _GATES_GATE_H
#define _GATES_GATE_H	1

// The USE_NAND_ONLY switches the main code to derive all logic gates
// from component NAND chips, instead of C++ oriented logic.

// It might be a little slower, but it will demonstrate how the 
// combinatorial circuits work.

// It's also useful for experimenting with ternary, and other, logics.

#define USE_NAND_ONLY	1

namespace Gate {
	
	template <typename pintype, size_t width> class PinRadix {
	public:
		static pintype	TrueState;
		static pintype	FalseState;
		static pintype	UndeterminedState;
		static pintype	T;
		static pintype	F;
		static pintype	U;

		PinRadix() {
			m_Value = false;
			m_BitWidth = width;
		}

		PinRadix(pintype initialValue) {
			m_Value = initialValue;
			m_BitWidth = width;
		}

		bool isTrue() const {
			return m_Value == TrueState ? true : false;
		}

		bool isFalse() const {
			return m_Value == FalseState ? true : false;
		}

		bool isUndetermined() const {
			return m_Value == UndeterminedState ? true : false;
		}

		bool operator==(const PinRadix &rhs) const {
			return m_Value == rhs.m_Value;
		}

		PinRadix<pintype, width> operator!() const {
			if (isTrue()) {
				return FalseState;
			} else if (isFalse()) {
				return TrueState;
			}

			return UndeterminedState;
		}


		// implicit conversion, to eliminate the asString method
		operator const char *() const { 
			return asString(); 
		}

		const char * asString() const {
			return isTrue() ? "true" : isFalse() ? "false" : "undetermined";
		}

		const char * asStringShort() const {
			return isTrue() ? "T" : isFalse() ? "F" : "U";
		}

		size_t	getStateCount() const {
			return m_BitWidth;
		}

		PinRadix<pintype, width> * getStateList() const {
			static PinRadix<pintype, width> pBinaryStateList[] = { FalseState,  TrueState};
			static PinRadix<pintype, width> pTernaryStateList[] = { FalseState, UndeterminedState,  TrueState};

			if (m_BitWidth == 2) {
				return pBinaryStateList;
			}
			return pTernaryStateList;
		}

	private:
		pintype m_Value;
		size_t	m_BitWidth;
	};
	
	// Implementation of static members
	template <typename T, size_t width>
	T PinRadix<T, width>::TrueState = true;
	template <typename T, size_t width>
	T PinRadix<T, width>::T = TrueState;

	template <typename T, size_t width>
	T PinRadix<T, width>::FalseState = false;
	template <typename T, size_t width>
	T PinRadix<T, width>::F = FalseState;

	template <typename T, size_t width>
	T PinRadix<T, width>::UndeterminedState = false;
	template <typename T, size_t width>
	T PinRadix<T, width>::U = UndeterminedState;

	// Definition for binary
	typedef PinRadix<bool, 2> PinBinary;

	// Definition and specializations for ternary
	char PinRadix<char, 3>::UndeterminedState = -1;
	char PinRadix<char, 3>::U = PinRadix<char, 3>::UndeterminedState;
	typedef PinRadix<char, 3> PinTernary;

	//
	// Basic Logic Gates
	//
	template <typename pintype> class LogicBase {
	public:
		pintype getResult() {
			return m_Result;
		}
		
		// implicit conversion, to eliminate the getResult method, should you desire
		operator pintype() const { 
			return m_Result; 
		}

		pintype operator!() const {
			return !m_Result;
		}

		operator const char *() const { 
			return m_Result.asString(); 
		}

	protected:
		pintype m_Result;
	};


	template <typename pintype> class Nand2 : public LogicBase<pintype> {
	public:
		Nand2(const pintype &a, const pintype &b) {
#if USE_NAND_ONLY
			// Macro included for ease of navigation only.
			// Do not put code here, for fear of getting stuck in finite loops
#endif
			if (a == b && a.isTrue()) {
				m_Result = pintype::FalseState;
			} else if (a.isFalse() || b.isFalse()) {
				m_Result = pintype::TrueState;
			} else {
				m_Result = pintype::UndeterminedState;
			}
		}
	};

	template <typename pintype> class And2 : public LogicBase<pintype> {
	public:
		And2(const pintype &a, const pintype &b) {
#if USE_NAND_ONLY
			Nand2<pintype> nand(a, b);

			m_Result = Nand2<pintype>(nand, nand);
#else
			if (a == b && a.isTrue()) {
				m_Result = pintype::TrueState;
			} else if (a.isFalse() || b.isFalse()) {
				m_Result = pintype::FalseState;
			} else {
				m_Result = pintype::UndeterminedState;
			}
#endif
		}
	};

	template <typename pintype> class Or2 : public LogicBase<pintype> {
	public:
		Or2(const pintype &a, const pintype &b) {
#if USE_NAND_ONLY
			Nand2<pintype> nand1(a, a);
			Nand2<pintype> nand2(b, b);

			m_Result = Nand2<pintype>(nand1, nand2);
#else
			if (a.isTrue() || b.isTrue()) {
				m_Result = pintype::TrueState;
			} else if (a.isFalse() && b.isFalse()) {
				m_Result = pintype::FalseState;
			} else {
				m_Result = pintype::UndeterminedState;
			}
#endif
		}
	};

	template <typename pintype> class Not : public LogicBase<pintype> {
	public:
		Not(const pintype &i) {
#if USE_NAND_ONLY
			m_Result = Nand2<pintype>(i, i);
#else
			m_Result = !i;
#endif
		}
	};

	template <typename pintype> class Nor2 : public LogicBase<pintype> {
	public:
		Nor2(const pintype &a, const pintype &b) {
#if USE_NAND_ONLY
			// This is an OR
			Nand2<pintype> nand1(a, a);
			Nand2<pintype> nand2(b, b);
			Nand2<pintype> nand3(nand1, nand2);

			// This is NOT
			m_Result = Nand2<pintype>(nand3, nand3);
#else
			Or2<pintype> or(a, b);

			m_Result = !or;
#endif
		}
	};

	template <typename pintype> class Xor2 : public LogicBase<pintype> {
	public:
		Xor2(const pintype &a, const pintype &b) {
			Nand2<pintype> nand1(a, b);
			Nand2<pintype> nand2(a, nand1);
			Nand2<pintype> nand3(nand1, b);

			m_Result = Nand2<pintype>(nand2, nand3);
		}
	};

	template <typename pintype> class Xnor2 : public LogicBase<pintype> {
	public:
		Xnor2(const pintype &a, const pintype &b) {
			Xor2<pintype> xor2(a, b);

			m_Result = !xor2;			
		}
	};

	//
	// Small circuits
	//
	template <typename pintype> class Decode12 : public LogicBase<pintype> {
	public:
		Decode12(const pintype &a) {
			m_Result = !a;
			m_D1 = a;
		}

		pintype getD0() {
			return m_Result;
		}

		pintype getD1() {
			return m_D1;
		}

	protected:
		pintype m_D1;
	};

	template <typename pintype> class Xor3 : public LogicBase<pintype> {
	public:
		Xor3(const pintype &a, const pintype &b, const pintype &c) {
			Xor2<pintype> xor1(a, b);

			m_Result = Xor2<pintype>(xor1, c);
		}
	};


	template <typename pintype> class Comparison : public LogicBase<pintype> {
	public:
		Comparison(const pintype &a) {
			if (a == b) {
				m_Result = pintype::TrueState;
			} else {
				m_Result = pintype::FalseState;
			}
		}
	};

	template <typename pintype> class HalfAdder : public LogicBase<pintype> {
	public:
		HalfAdder(const pintype &a, const pintype &b) {
			m_Result = Xor2<pintype>(a, b);
			m_Carry  = And2<pintype>(a, b);
		}

		pintype getSum() {
			return m_Result;
		}

		pintype getCarry() {
			return m_Carry;
		}

		// getResult2 is essentially to make the test suites uniform
		pintype getResult2() {
			return m_Carry;
		}

	protected:
		pintype m_Carry;
	};


	template <typename pintype> class FullAdder : public LogicBase<pintype> {
	public:
		FullAdder(const pintype &a, const pintype &b, const pintype &carry) {
			HalfAdder<pintype> ha1(a, b);
			HalfAdder<pintype> ha2(ha1.getSum(), carry);
			m_Result = ha2;			

			Or2<pintype> or(ha1.getCarry(), ha2.getCarry());
			m_Carry = or;			
		}

		pintype getSum() {
			return m_Result;
		}

		pintype getCarry() {
			return m_Carry;
		}

		// getResult2 is essentially to make the test suites uniform
		pintype getResult2() {
			return m_Carry;
		}

	protected:
		pintype m_Carry;
	};


	//
	// Helper types
	//
	typedef And2<PinBinary>		BinaryGateAnd2;
	typedef And2<PinTernary>	TernaryGateAnd2;

	typedef Or2<PinBinary>		BinaryGateOr2;
	typedef Or2<PinTernary>		TernaryGateOr2;

	typedef Nor2<PinBinary>		BinaryGateNor2;
	typedef Nor2<PinTernary>	TernaryGateNor2;

	typedef Not<PinBinary>		BinaryGateNot;
	typedef Not<PinTernary>		TernaryGateNot;

	typedef Nand2<PinBinary>	BinaryGateNand2;
	typedef Nand2<PinTernary>	TernaryGateNand2;

	typedef Xor2<PinBinary>		BinaryGateXor2;
	typedef Xor2<PinTernary>	TernaryGateXor2;

	typedef Xnor2<PinBinary>	BinaryGateXnor2;
	typedef Xnor2<PinTernary>	TernaryGateXnor2;

	typedef Decode12<PinBinary> BinaryGateDecode;
	typedef Decode12<PinTernary> TernaryGateDecode;

	typedef Xor3<PinBinary>		BinaryGateXor3;
	typedef Xor3<PinTernary>	TernaryGateXor3;

	// Combinatorials
	typedef HalfAdder<PinBinary>	BinaryCombinatorialHalfAdder;
	typedef HalfAdder<PinTernary>	TernaryCombinatorialHalfAdder;

	typedef FullAdder<PinBinary>	BinaryCombinatorialFullAdder;
	typedef FullAdder<PinTernary>	TernaryCombinatorialFullAdder;


	//
	// Gate factory
	//
	template <typename pintype> class Factory {
	public:
		And2<pintype> makeAnd2(const pintype &a, const pintype &b) {
			return And2<pintype>(a, b);
		}

		Nand2<pintype> makeNand2(const pintype &a, const pintype &b) {
			return Nand2<pintype>(a, b);
		}

		Or2<pintype> makeOr2(const pintype &a, const pintype &b) {
			return Or2<pintype>(a, b);
		}

		Nor2<pintype> makeNor2(const pintype &a, const pintype &b) {
			return Nor2<pintype>(a, b);
		}

		Not<pintype> makeNot(const pintype &a) {
			return Not<<pintype>(a);
		}

		Xor2<pintype> makeXor2(const pintype &a, const pintype &b) {
			return Xor2<pintype>(a, b);
		}

		Xnor2<pintype> makeXnor2(const pintype &a, const pintype &b) {
			return Xnor2<pintype>(a, b);
		}

		Decode12<pintype> makeDecode12(const pintype &i) {
			return Decode12<pintype>(i);
		}
	};

	typedef Factory<PinBinary> BinaryGateFactory;
	typedef Factory<PinTernary> TernaryGateFactory;
}

#endif	// _GATES_GATE_H
