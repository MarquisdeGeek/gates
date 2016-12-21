#ifndef _GATES_TESTS_TRUTH_TABLES_H
#define _GATES_TESTS_TRUTH_TABLES_H	1

// The numbers affixed to each method indicate the number of inputs, and outputs,
// respectively.


template <size_t rows, typename TPIN, typename TGATE>
bool TestTruthTable11(std::ostream &s, const TPIN (&table)[rows]) {
	TPIN v;	
	TPIN *pStateList = v.getStateList();

	int passed = 0;
	for(int i=0;i<rows;++i) {
		TGATE v(pStateList[i]);
		s << "   " << pStateList[i].asStringShort() << "  " << " = " << v.getResult().asStringShort();
		if (v.getResult() == table[i]) {
			++passed;
			s << " PASS ";
		} else {
			s << " FAIL (expecting " << table[i].asStringShort() << ")";
		}
		s << std::endl;
	}

	s << "   " << passed << " out of " << rows << std::endl;
	s << (passed == rows ? "SUCCESS" : "FAILURE") << std::endl << std::endl;
	
	return passed == rows;
}


template <size_t rows, size_t cols, typename TPIN, typename TGATE>
bool TestTruthTable21(std::ostream &s, const TPIN (&table)[rows][cols]) {
	TPIN v;	
	TPIN *pStateList = v.getStateList();

	int passed = 0;
	for(int i=0;i<rows;++i) {
		for(int j=0;j<cols;++j) {
			TGATE v(pStateList[i], pStateList[j]);
			s << "   " << pStateList[i].asStringShort() << "  " << pStateList[j].asStringShort() << " = " << v.getResult().asStringShort();
			if (v.getResult() == table[i][j]) {
				++passed;
				s << " PASS ";
			} else {
				s << " FAIL (expecting " << table[i][j].asStringShort() << ")";
			}
			s << std::endl;
		}
	}

	s << passed << " out of " << (rows * cols) << std::endl;
	s << (passed == rows*cols ? "SUCCESS" : "FAILURE") << std::endl << std::endl;
	
	return passed == rows*cols;
}


template <size_t rows, size_t cols, typename TPIN, typename TGATE>
bool TestTruthTable22(std::ostream &s, const TPIN (&table)[rows][cols][2]) {
	TPIN v;	
	TPIN *pStateList = v.getStateList();

	int passed = 0;
	for(int i=0;i<rows;++i) {
		for(int j=0;j<cols;++j) {
			TGATE v(pStateList[i], pStateList[j]);
			s << "   " << pStateList[i].asStringShort() << "  " << pStateList[j].asStringShort();
			s << " = " << v.getResult().asStringShort() << "/" << v.getResult2().asStringShort();
			if (v.getResult() == table[i][j][0] && v.getResult2() == table[i][j][1]) {
				++passed;
				s << " PASS ";
			} else {
				s << " FAIL (expecting " << table[i][j][0].asStringShort() << "/" << table[i][j][1].asStringShort() << ")";
			}
			s << std::endl;
		}
	}

	s << passed << " out of " << (rows * cols) << std::endl;
	s << (passed == rows*cols ? "SUCCESS" : "FAILURE") << std::endl << std::endl;
	
	return passed == rows*cols;
}


template <size_t rows, typename TPIN, typename TGATE>
bool TestTruthTable31(std::ostream &s, const TPIN (&table)[rows]) {
	TPIN v;	
	size_t bitsize = v.getStateCount();
	TPIN *pStateList = v.getStateList();

	size_t passed = 0;

	for(size_t i=0;i<rows;++i) {
		// Imagine this is in the order: C - B - A
		size_t temp_i = i;
		size_t a = temp_i % bitsize;
		temp_i = (temp_i - a) / bitsize;

		size_t b = temp_i % bitsize;
		temp_i = (temp_i - b) / bitsize;

		size_t c = temp_i % bitsize;
		
		TGATE v(pStateList[a], pStateList[b], pStateList[c]);
		s << "   " << pStateList[c].asStringShort() << "  " << pStateList[b].asStringShort() << "  " << pStateList[a].asStringShort();
		s << " = " << v.getResult().asStringShort();
		if (v.getResult() == table[i]) {
			++passed;
			s << " PASS ";
		} else {
			s << " FAIL (expecting " << table[i].asStringShort() << ")";
		}
		s << std::endl;
	}

	s << passed << " out of " << rows << std::endl;
	s << (passed == rows ? "SUCCESS" : "FAILURE") << std::endl << std::endl;
	
	return passed == rows;
}


template <size_t rows, typename TPIN, typename TGATE>
bool TestTruthTable32(std::ostream &s, const TPIN (&table)[rows][2]) {
	// This temp variable helps us determine the valid states for the pin.
	// It's not pretty, and needs to be fixed sometime.
	TPIN v;	
	size_t bitsize = v.getStateCount();
	TPIN *pStateList = v.getStateList();

	size_t passed = 0;

	for(size_t i=0;i<rows;++i) {
		// Imagine this is in the order: C - B - A
		size_t temp_i = i;
		size_t a = temp_i % bitsize;
		temp_i = (temp_i - a) / bitsize;

		size_t b = temp_i % bitsize;
		temp_i = (temp_i - b) / bitsize;

		size_t c = temp_i % bitsize;
		
		TGATE v(pStateList[a], pStateList[b], pStateList[c]);
		s << "   " << pStateList[c].asStringShort() << "  " << pStateList[b].asStringShort() << "  " << pStateList[a].asStringShort();
		s << " = " << v.getResult().asStringShort() << "/" << v.getResult2().asStringShort();
		if (v.getResult() == table[i][0] && v.getResult2() == table[i][1]) {
			++passed;
			s << " PASS ";
		} else {
			s << " FAIL (expecting " << table[i][0].asStringShort() << "/" << table[i][1].asStringShort() << ")";
		}
		s << std::endl;

	}

	s << passed << " out of " << rows << std::endl;
	s << (passed == rows ? "SUCCESS" : "FAILURE") << std::endl << std::endl;
	
	return passed == rows;
}


#endif	// _GATES_TESTS_TRUTH_TABLES_H
