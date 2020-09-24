TITLE Gaba mod file only for fitting purpose 

COMMENT
Thierry Nieus, unpublished results, please keep reserved.
Variables with suffix "_s" are meant for single IPSC fit, with suffix "_2" for CGP experimental condition
	Does not work with variable dt!
ENDCOMMENT



NEURON {
	POINT_PROCESS GRANULE_Gaba_det_vi
	 
	NONSPECIFIC_CURRENT i
	RANGE Q10_diff,Q10_channel
	RANGE g, ic ,Cdur ,Tmax, Erev
	RANGE Open,Open_a6	:, ,OpenScaled, 
	:RANGE ScaleAlfa1,ScaleAlfa6,ScaleFactor_s

	RANGE kon,koff,d3,r3,d1d2,r1r2,a1,b1,a2,b2,r1,r2,d1,d2
	RANGE kon_a6,koff_a6,d3_a6,r3_a6,d1d2_a6,r1r2_a6,a1_a6,b1_a6,a2_a6,b2_a6,r1_a6,r2_a6,d1_a6,d2_a6

	RANGE gmaxA1,gmaxA6,onSET	
	RANGE gA1,gA6

	RANGE xout,yout,zout,uout	
	
	RANGE tau_1,tau_rec,tau_facil,U,T,U_2 
	RANGE diff_flag,diff_flag2,M,Rd,Diff,lamd
	RANGE nd,diffus ,Trelease, gmax_factor, syntype 
}

UNITS {
	(nA) 	= (nanoamp)
	(mV) 	= (millivolt)
	(umho)  = (micromho)
	(mM) 	= (milli/liter)
	(pS) 	= (picosiemens)
	PI   	= (pi)(1)
    }
    
    
    
    PARAMETER {
	syntype
	gmax_factor = 1
	: Parametri Postsinaptici
	gmaxA1	= 918.807	(pS)	
	gmaxA6	= 132.842	(pS)	
	Q10_diff	= 1.5
	Q10_channel	= 2.4
	Cdur	= 0.3		(ms)	
	Cdur_2 	= 0.3 		(ms)

	: A1 kinetic rates EC50=(around) 20 uM, U=0.35
	kon	= 17.7		(/ms/mM)	: 20
	koff	= 2		(/ms) 		 
	d3	= 21.703	(/ms) 	: 15	 
	r3	= 0.97325	(/ms) 	: 0.15, use 3.75 for slices in the PR model
	d1d2	= 0		(/ms/mM) : 15	
	r1r2	= 0		(/ms)	: 0.007
	a1	= 0.4144	(/ms)	: 0.06
	b1	= 0.03		(/ms)
	a2	= 1.0002	(/ms)	: 0.4
	b2	= 10		(/ms)	
	r1	= 7e-4		(/ms)
	r2	= 0.14208	(/ms)	: 6e-3
	d1	= 3.3e-4	(/ms)
	d2	= 3.4898	(/ms)	: 1.2
	
	: A6 kinetic rates according bifit_gaba_ver5.conf have EC50 curve max value 0.727 with pulse 400ms, EC50=1.5uM
	kon_a6	= 54.8		(/ms/mM)	:20
	koff_a6	= 0.31061	(/ms) 		:2
	d3_a6	= 15		(/ms) 		 
	r3_a6	= 7.4132	(/ms) 		:3.75
	d1d2_a6	= 24.2		(/ms/mM)	:15
	r1r2_a6	= 0.091668	(/ms)		:0.007
	a1_a6	= 0.06		(/ms)
	b1_a6	= 0.03		(/ms)
	a2_a6	= 0.4		(/ms)
	b2_a6	= 10		(/ms)	
	r1_a6	= 0.040001	(/ms)		:7e-4
	r2_a6	= 0.4316	(/ms)		:6e-3
	d1_a6	= 0.86042	(/ms)		:3.3e-4
	d2_a6	= 2.7012	(/ms)		:1.2
	
	Erev	= -65		(mV)

	: Parametri Presinaptici
	tau_1 	= 0.1 		(ms) 	< 1e-9, 1e9 >
	tau_rec = 36.169 	(ms) 	< 1e-9, 1e9 > 	:43.4
	tau_facil = 58.517	(ms) 	< 0, 1e9 >	: 6.22 
	U 	= 0.35			< 0, 1 >
	 
	
	Tmax	= 1  		(mM)	
	onSET	= 1
	 
		
	: Diffusion parameters
	: Diffusion: M=21.500, R=1.033, D=0.223, lamd=0.02 as in excitatory synapses	

	M	= 7.506	: numero di (kilo) molecole in una vescicola	(52.76)	
	Rd	= 0.978 (um)	:4.79	:4.96	: 4.96 (first fit!)
	Diff	= 0.223 (um2/ms)

	lamd	= 20 		(nm)
	diff_flag	= 1			: flag diffusion on/off
	 
	nd		= 1			: kernel exponent of diffusion

	 
	celsius (degC)
}


ASSIGNED {
	v		(mV)		: postsynaptic voltage
	i 		(nA)		: current = g*(v - Erev)
	ic 		(nA)		: current = g*(v - Erev)
	g 		(pS)		: conductance
	gA1		(nA)
	gA6		(nA)
	
	Open
	Open_a6
 
	diffus	
 
	T		(mM)	
	 
	Trelease	(mM)
	 	
	Mres		(mM)	
	tpre		(ms)

	xout
	yout
	zout
	uout
	
	tspike[100]	(ms)	: will be initialized by the pointprocess
	PRE[100]
	:PRE_2[500]
	numpulses
	tzero
	gbar_Q10 (mho/cm2)
	Q10 (1)
}

STATE {	
	: CTRL - A1
	C
	CA1
	CA2
	DA1
	DA2
	DA2f
	OA1
	OA2	

	: CTRL - A6
	C_a6
	CA1_a6
	CA2_a6
	DA1_a6
	DA2_a6
	DA2f_a6
	OA1_a6
	OA2_a6
 
}

INITIAL {
	: CTRL - A1
	C=1
	CA1=0
	CA2=0
	DA1=0
	DA2=0
	DA2f=0
	OA1=0  	
	OA2=0
	CA1=0
	CA2=0

	: CTRL - A6
	C_a6=1
	CA1_a6=0
	CA2_a6=0
	DA1_a6=0
	DA2_a6=0
	DA2f_a6=0
	OA1_a6=0  	
	OA2_a6=0
	CA1_a6=0
	CA2_a6=0

 
	Open=0
	  
	T=0 		(mM)
	
	gbar_Q10 = Q10_diff^((celsius-30)/10)
	Q10 = Q10_channel^((celsius-30)/10)
 
	numpulses=0
	Mres=1e3* (1e3 * 1e15 / 6.022e23 * M)     : (M) to (mM) so 1e3, 1um^3=1dm^3*1e-15 so 1e15
	FROM i=1 TO 100 { PRE[i-1]=0 tspike[i-1]=0 } :PRE_2[500]=0}
	tspike[0]=1e12	(ms)
	if(tau_1>=tau_rec){ 
		printf("Warning: tau_1 (%g) should never be higher neither equal to tau_rec (%g)!\n",tau_1,tau_rec)
		tau_rec=tau_1+1e-5
		:printf("tau_rec has been set to %g\n",tau_rec) 
	} 
	onSET	= 1
	 
}
	FUNCTION imax(a,b) {
	    if (a>b) { imax=a }
	    else { imax=b }
	}
	
FUNCTION diffusione(){	 
	LOCAL DifWave,i,cntc,fi,aaa
	DifWave=0
	cntc=imax(numpulses-100,0)
	FROM i=cntc  TO numpulses{
	    fi=fmod(i,100)
	    tzero=tspike[fi]
		if(t>tzero){
		    aaa = (-Rd*Rd/(4*Diff*(t-tzero)))
		    if(fabs(aaa)<699){
			DifWave=DifWave+PRE[fi]*Mres*exp(aaa)/((4*PI*Diff*(1e-3)*lamd)*(t-tzero)) : ^nd nd =1
		    }else{
			if(aaa>0){
			    DifWave=DifWave+PRE[fi]*Mres*exp(699)/((4*PI*Diff*(1e-3)*lamd)*(t-tzero)) : ^nd nd =1
			}else{
			    DifWave=DifWave+PRE[fi]*Mres*exp(-699)/((4*PI*Diff*(1e-3)*lamd)*(t-tzero)) : ^nd nd =1
			}
		    }
		}
	}	
	diffusione=DifWave
}



BREAKPOINT {
	SOLVE kstates METHOD sparse
	
	Open=OA1+OA2
	Open_a6=OA1_a6+OA2_a6
	
	gA1 = gmaxA1 * gbar_Q10 * Open
	gA6 = gmaxA6 * gbar_Q10 * Open_a6
	
	g = (gA1 + gA6) * gmax_factor
	
	i = (1e-6) * g * ( v - Erev )
	ic = i
}

KINETIC kstates {

	: ************
	: *** CTRL ***	
	: ************
	

	diffus=diffusione() 	
	Trelease = T + diffus
	
	:	***	ALFA 1 *** 
	
	: second row
	~	C  	<-> 	CA1	(2*kon*Trelease*Q10,koff*Q10)
	~	CA1 	<-> 	CA2	(kon*Trelease*Q10,2*koff*Q10)
	~	CA2	<->	DA2f	(d3*Q10,r3*Q10)
	: third row
	~ 	DA1  	<-> 	DA2	(d1d2*Trelease*Q10,r1r2*Q10)
	: first <=> second row
	~ 	OA1  	<-> 	CA1	(a1*Q10,b1*Q10)
	~ 	OA2  	<-> 	CA2	(a2*Q10,b2*Q10)
	: third <=> second row
	~	DA1	<->	CA1	(r1*Q10,d1*Q10)
	~	DA2	<->	CA2	(r2*Q10,d2*Q10)	
	CONSERVE C+CA1+CA2+DA1+DA2+DA2f+OA1+OA2=1
	
	:	***	ALFA 6 *** 
	
	: second row
	~	C_a6  	<-> 	CA1_a6	(2*kon_a6*diffus*Q10,koff_a6*Q10)
	~	CA1_a6 	<-> 	CA2_a6	(kon_a6*diffus*Q10,2*koff_a6*Q10)
	~	CA2_a6	<->	DA2f_a6	(d3_a6*Q10,r3_a6*Q10)
	: third row
	~ 	DA1_a6  <-> 	DA2_a6	(d1d2_a6*diffus*Q10,r1r2_a6*Q10)
	: first <=> second row
	~ 	OA1_a6  <-> 	CA1_a6	(a1_a6*Q10,b1_a6*Q10)
	~ 	OA2_a6  <-> 	CA2_a6	(a2_a6*Q10,b2_a6*Q10)
	: third <=> second row
	~	DA1_a6	<->	CA1_a6	(r1_a6*Q10,d1_a6*Q10)
	~	DA2_a6	<->	CA2_a6	(r2_a6*Q10,d2_a6*Q10)	
	CONSERVE C_a6+CA1_a6+CA2_a6+DA1_a6+DA2_a6+DA2f_a6+OA1_a6+OA2_a6=1	
	
}


NET_RECEIVE(weight,on, nspike,tzero (ms),x,y,z,u, tsyn (ms)) {LOCAL fi
	INITIAL {
		x = 0
		y = 0
		z = 0
		u = 0 
		 		
		xout=x
		yout=y
		zout=z
		uout=u
		tsyn = t
		nspike = 1
	}

	if(onSET){
		on=0 
		onSET=0
		 
	}
	
	if (flag == 0) { 
		: Qui faccio rientrare la modulazione presinaptica
		nspike = nspike + 1
		:printf("T = %g (mM)\n",Trelease)
		if (!on) {
			tzero = t	
			tpre=t	: activates diffusion
			on = 1		
					
			z = z*exp(-(t - tsyn)/tau_rec)		
			z = z + ( y*(exp(-(t - tsyn)/tau_1) - exp(-(t - tsyn)/tau_rec)) / ((tau_1/tau_rec)-1) )
			y = y*exp(-(t - tsyn)/tau_1)			
			x = 1-y-z			
			if (tau_facil > 0) { 
				u = u*exp(-(t - tsyn)/tau_facil)
				u = u + U * ( 1 - u )							
			} else { u = U }
			y = y + x * u
			T=Tmax*y

			 
				
			fi=fmod(numpulses,100)
			PRE[fi]=y	: PRE[numpulses]=y
			 
			tspike[fi] = t
			numpulses=numpulses+1

			 

			tsyn = t			
		}
		net_send(Cdur, nspike)
		 
	}

	if (flag == nspike) { 
		T = 0
		 
		on = 0
	}

	 


}
