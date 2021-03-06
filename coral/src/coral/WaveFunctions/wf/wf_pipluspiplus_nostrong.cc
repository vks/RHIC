#ifndef __CWAVEFUNCTION_WF_PIPLUSPIPLUS_NOSTRONG_CC__
#define __CWAVEFUNCTION_WF_PIPLUSPIPLUS_NOSTRONG_CC__
#include "wavefunction.h"

CWaveFunction_pipluspiplus_nostrong::CWaveFunction_pipluspiplus_nostrong(string  parsfilename){
  int iq,ichannel,*I;
  double q;

  ParsInit(parsfilename);

  m1=MPI;
  m2=MPI;
	IDENTICAL=1;
  q1q2=1;
  if(COULOMB==false) q1q2=0;
  nchannels=0;
  InitArrays();
  InitWaves();  
  printf("pipluspiplus_nostrong wf initialized\n");
}

double CWaveFunction_pipluspiplus_nostrong::CalcPsiSquared(int iq,double r,double ctheta){
	double psisquared;
	double delta_s,delta_p,delta_d;
	const double ROOT2=sqrt(2.0);
	complex<double> psi;

	if(iq>=nqmax){
		psisquared=1.0;
	}
	else{
		psi=(planewave[iq]->planewave(r,ctheta)+planewave[iq]->planewave(r,-ctheta))/ROOT2;
		psisquared=real(psi*conj(psi));
		//psisquared*=RelativisticCorrection(r,iq);
	}
	return psisquared;
}

#endif
