

template <typename TPIN, typename TGATE>
void ShowTruthTable21(std::ostream &s) {
	TPIN v;	
	size_t bitsize = v.getStateCount();
	TPIN *pStateList = v.getStateList();

	s << "       b" << std::endl;
	s << "     ";

	for(size_t i=0;i<bitsize;++i) {
		s << pStateList[i].asStringShort() << " ";
	}
	s << std::endl;

	for(size_t i=0;i<bitsize;++i) {
		if (i == 1) {
			s << "a ";
		} else {
			s << "  ";
		}
		s << pStateList[i].asStringShort() << "  ";
		
		for(size_t j=0;j<bitsize;++j) {
			TGATE v(pStateList[i], pStateList[j]);

			s << v.getResult().asStringShort() << " ";
		}
		s << std::endl;
	}	
}


template <typename TPIN, typename TGATE>
void ShowTruthTable22(std::ostream &s) {
	TPIN v;	
	size_t bitsize = v.getStateCount();
	TPIN *pStateList = v.getStateList();

	s << "          b" << std::endl;
	s << "       ";

	for(size_t i=0;i<bitsize;++i) {
		s << pStateList[i].asStringShort() << "     ";
	}
	s << std::endl;

	for(size_t i=0;i<bitsize;++i) {
		if (i == 1) {
			s << "a ";
		} else {
			s << "  ";
		}
		s << pStateList[i].asStringShort();
		
		for(size_t j=0;j<bitsize;++j) {
			TGATE v(pStateList[i], pStateList[j]);

			s << " : " << v.getResult().asStringShort() << "/" << v.getResult2().asStringShort();
		}
		s << std::endl;
	}	
}

template <size_t rows, typename TPIN, typename TGATE>
void ShowTruthTable32(std::ostream &s) {
	TPIN v;	
	size_t bitsize = v.getStateCount();
	TPIN *pStateList = v.getStateList();
	char *heading[] = {"c", "b", "a"};

	s << "   ";
	for(size_t i=0;i<bitsize;++i) {
		s << heading[i] << "  ";
	}
	s << std::endl;

	for(size_t i=0;i<rows;++i) {
		// Imagine this is in the order: C - B - A
		size_t temp_i = i;
		size_t a = temp_i % bitsize;
		temp_i = (temp_i - a) / bitsize;

		size_t b = temp_i % bitsize;
		temp_i = (temp_i - b) / bitsize;

		size_t c = temp_i % bitsize;
		
		// The computation
		TGATE v(pStateList[a], pStateList[b], pStateList[c]);

		s << "   " << pStateList[c].asStringShort() << "  " << pStateList[a].asStringShort() << "  " << pStateList[b].asStringShort();
		s << " :  " << v.getResult().asStringShort() << "/" << v.getResult2().asStringShort();
		s << std::endl;
	}
	
}

