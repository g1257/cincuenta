#ifndef CINC_MODELPARAMS_H
#define CINC_MODELPARAMS_H
#include "Vector.h"
#include "Matrix.h"

namespace Dmft {

template<typename RealType>
struct ModelParams {

	typedef typename PsimagLite::Vector<RealType>::Type VectorRealType;

	ModelParams(const VectorRealType& bathParams)
	{
		SizeType bath = bathParams.size()/2;
		assert((bathParams.size() & 1) == 0);
		sites = bath + 1;
		potentialV.resize(sites);
		hoppings.resize(sites, sites);
		for (SizeType i = 0; i < bath; ++i) {
			potentialV[i + 1] = bathParams[i];
			hoppings(i + 1, 0) = hoppings(0, i + 1) = bathParams[i + bath];
		}
	}

	SizeType sites;
	VectorRealType potentialV;
	PsimagLite::Matrix<RealType> hoppings;
};

}
#endif // CINC_MODELPARAMS_H
