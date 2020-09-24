/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__GRANULE_KCA
#define _nrn_initial _nrn_initial__GRANULE_KCA
#define nrn_cur _nrn_cur__GRANULE_KCA
#define _nrn_current _nrn_current__GRANULE_KCA
#define nrn_jacob _nrn_jacob__GRANULE_KCA
#define nrn_state _nrn_state__GRANULE_KCA
#define _net_receive _net_receive__GRANULE_KCA 
#define _f_rate _f_rate__GRANULE_KCA 
#define rate rate__GRANULE_KCA 
#define states states__GRANULE_KCA 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define Aalpha_c _p[0]
#define Balpha_c _p[1]
#define Kalpha_c _p[2]
#define Abeta_c _p[3]
#define Bbeta_c _p[4]
#define Kbeta_c _p[5]
#define Q10_diff _p[6]
#define Q10_channel _p[7]
#define gbar _p[8]
#define ic _p[9]
#define c_inf _p[10]
#define tau_c _p[11]
#define g _p[12]
#define alpha_c _p[13]
#define beta_c _p[14]
#define gbar_Q10 _p[15]
#define c _p[16]
#define cai _p[17]
#define ek _p[18]
#define Dc _p[19]
#define ik _p[20]
#define v _p[21]
#define _g _p[22]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
#define _ion_cai	*_ppvar[3]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_alp_c(void);
 static void _hoc_bet_c(void);
 static void _hoc_rate(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_GRANULE_KCA", _hoc_setdata,
 "alp_c_GRANULE_KCA", _hoc_alp_c,
 "bet_c_GRANULE_KCA", _hoc_bet_c,
 "rate_GRANULE_KCA", _hoc_rate,
 0, 0
};
#define alp_c alp_c_GRANULE_KCA
#define bet_c bet_c_GRANULE_KCA
 extern double alp_c( _threadargsprotocomma_ double );
 extern double bet_c( _threadargsprotocomma_ double );
 
static void _check_rate(double*, Datum*, Datum*, _NrnThread*); 
static void _check_table_thread(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, int _type) {
   _check_rate(_p, _ppvar, _thread, _nt);
 }
 /* declare global and static user variables */
#define usetable usetable_GRANULE_KCA
 double usetable = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "usetable_GRANULE_KCA", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Aalpha_c_GRANULE_KCA", "/ms",
 "Balpha_c_GRANULE_KCA", "mM",
 "Kalpha_c_GRANULE_KCA", "mV",
 "Abeta_c_GRANULE_KCA", "/ms",
 "Bbeta_c_GRANULE_KCA", "mM",
 "Kbeta_c_GRANULE_KCA", "mV",
 "gbar_GRANULE_KCA", "mho/cm2",
 "ic_GRANULE_KCA", "mA/cm2",
 "tau_c_GRANULE_KCA", "ms",
 "g_GRANULE_KCA", "mho/cm2",
 "alpha_c_GRANULE_KCA", "/ms",
 "beta_c_GRANULE_KCA", "/ms",
 "gbar_Q10_GRANULE_KCA", "mho/cm2",
 0,0
};
 static double c0 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "usetable_GRANULE_KCA", &usetable_GRANULE_KCA,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[4]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"GRANULE_KCA",
 "Aalpha_c_GRANULE_KCA",
 "Balpha_c_GRANULE_KCA",
 "Kalpha_c_GRANULE_KCA",
 "Abeta_c_GRANULE_KCA",
 "Bbeta_c_GRANULE_KCA",
 "Kbeta_c_GRANULE_KCA",
 "Q10_diff_GRANULE_KCA",
 "Q10_channel_GRANULE_KCA",
 "gbar_GRANULE_KCA",
 0,
 "ic_GRANULE_KCA",
 "c_inf_GRANULE_KCA",
 "tau_c_GRANULE_KCA",
 "g_GRANULE_KCA",
 "alpha_c_GRANULE_KCA",
 "beta_c_GRANULE_KCA",
 "gbar_Q10_GRANULE_KCA",
 0,
 "c_GRANULE_KCA",
 0,
 0};
 static Symbol* _k_sym;
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 23, _prop);
 	/*initialize range parameters*/
 	Aalpha_c = 2.5;
 	Balpha_c = 0.0015;
 	Kalpha_c = -11.765;
 	Abeta_c = 1.5;
 	Bbeta_c = 0.00015;
 	Kbeta_c = -11.765;
 	Q10_diff = 1.5;
 	Q10_channel = 3;
 	gbar = 0.0045;
 	_prop->param = _p;
 	_prop->param_size = 23;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[3]._pval = &prop_ion->param[1]; /* cai */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _GRANULE_KCA_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", -10000.);
 	ion_reg("ca", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
     _nrn_thread_table_reg(_mechtype, _check_table_thread);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 23, 5);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GRANULE_KCA /home/stefano/Documenti/paperRevision/GL_Model/x86_64/GRANULE_KCA.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double *_t_c_inf;
 static double *_t_tau_c;
static int _reset;
static char *modelname = "Cerebellum Granule Cell Model";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int _f_rate(_threadargsprotocomma_ double);
static int rate(_threadargsprotocomma_ double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static void _n_rate(_threadargsprotocomma_ double _lv);
 static int _slist1[1], _dlist1[1];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rate ( _threadargscomma_ v ) ;
   Dc = ( c_inf - c ) / tau_c ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rate ( _threadargscomma_ v ) ;
 Dc = Dc  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_c )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rate ( _threadargscomma_ v ) ;
    c = c + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_c)))*(- ( ( ( c_inf ) ) / tau_c ) / ( ( ( ( - 1.0 ) ) ) / tau_c ) - c) ;
   }
  return 0;
}
 
double alp_c ( _threadargsprotocomma_ double _lv ) {
   double _lalp_c;
 double _lQ10 ;
 _lQ10 = pow( Q10_channel , ( ( celsius - 30.0 ) / 10.0 ) ) ;
   _lalp_c = _lQ10 * Aalpha_c / ( 1.0 + ( Balpha_c * exp ( _lv / Kalpha_c ) / cai ) ) ;
   
return _lalp_c;
 }
 
static void _hoc_alp_c(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alp_c ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double bet_c ( _threadargsprotocomma_ double _lv ) {
   double _lbet_c;
 double _lQ10 ;
 _lQ10 = pow( Q10_channel , ( ( celsius - 30.0 ) / 10.0 ) ) ;
   _lbet_c = _lQ10 * Abeta_c / ( 1.0 + cai / ( Bbeta_c * exp ( _lv / Kbeta_c ) ) ) ;
   
return _lbet_c;
 }
 
static void _hoc_bet_c(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  bet_c ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 static double _mfac_rate, _tmin_rate;
  static void _check_rate(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  static double _sav_Aalpha_c;
  static double _sav_Balpha_c;
  static double _sav_Kalpha_c;
  static double _sav_Abeta_c;
  static double _sav_Bbeta_c;
  static double _sav_Kbeta_c;
  static double _sav_celsius;
  if (!usetable) {return;}
  if (_sav_Aalpha_c != Aalpha_c) { _maktable = 1;}
  if (_sav_Balpha_c != Balpha_c) { _maktable = 1;}
  if (_sav_Kalpha_c != Kalpha_c) { _maktable = 1;}
  if (_sav_Abeta_c != Abeta_c) { _maktable = 1;}
  if (_sav_Bbeta_c != Bbeta_c) { _maktable = 1;}
  if (_sav_Kbeta_c != Kbeta_c) { _maktable = 1;}
  if (_sav_celsius != celsius) { _maktable = 1;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_rate =  - 100.0 ;
   _tmax =  30.0 ;
   _dx = (_tmax - _tmin_rate)/13000.; _mfac_rate = 1./_dx;
   for (_i=0, _x=_tmin_rate; _i < 13001; _x += _dx, _i++) {
    _f_rate(_p, _ppvar, _thread, _nt, _x);
    _t_c_inf[_i] = c_inf;
    _t_tau_c[_i] = tau_c;
   }
   _sav_Aalpha_c = Aalpha_c;
   _sav_Balpha_c = Balpha_c;
   _sav_Kalpha_c = Kalpha_c;
   _sav_Abeta_c = Abeta_c;
   _sav_Bbeta_c = Bbeta_c;
   _sav_Kbeta_c = Kbeta_c;
   _sav_celsius = celsius;
  }
 }

 static int rate(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _lv) { 
#if 0
_check_rate(_p, _ppvar, _thread, _nt);
#endif
 _n_rate(_p, _ppvar, _thread, _nt, _lv);
 return 0;
 }

 static void _n_rate(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _lv){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_rate(_p, _ppvar, _thread, _nt, _lv); return; 
}
 _xi = _mfac_rate * (_lv - _tmin_rate);
 if (isnan(_xi)) {
  c_inf = _xi;
  tau_c = _xi;
  return;
 }
 if (_xi <= 0.) {
 c_inf = _t_c_inf[0];
 tau_c = _t_tau_c[0];
 return; }
 if (_xi >= 13000.) {
 c_inf = _t_c_inf[13000];
 tau_c = _t_tau_c[13000];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 c_inf = _t_c_inf[_i] + _theta*(_t_c_inf[_i+1] - _t_c_inf[_i]);
 tau_c = _t_tau_c[_i] + _theta*(_t_tau_c[_i+1] - _t_tau_c[_i]);
 }

 
static int  _f_rate ( _threadargsprotocomma_ double _lv ) {
   double _la_c , _lb_c ;
 _la_c = alp_c ( _threadargscomma_ _lv ) ;
   _lb_c = bet_c ( _threadargscomma_ _lv ) ;
   tau_c = 1.0 / ( _la_c + _lb_c ) ;
   c_inf = _la_c / ( _la_c + _lb_c ) ;
    return 0; }
 
static void _hoc_rate(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 
#if 1
 _check_rate(_p, _ppvar, _thread, _nt);
#endif
 _r = 1.;
 rate ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 1;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
  cai = _ion_cai;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 1; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
  cai = _ion_cai;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 3, 1);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  c = c0;
 {
   gbar_Q10 = gbar * ( pow( Q10_diff , ( ( celsius - 30.0 ) / 10.0 ) ) ) ;
   rate ( _threadargscomma_ v ) ;
   c = c_inf ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];

#if 0
 _check_rate(_p, _ppvar, _thread, _nt);
#endif
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ek = _ion_ek;
  cai = _ion_cai;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   g = gbar_Q10 * c ;
   ik = g * ( v - ek ) ;
   ic = ik ;
   alpha_c = alp_c ( _threadargscomma_ v ) ;
   beta_c = bet_c ( _threadargscomma_ v ) ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ek = _ion_ek;
  cai = _ion_cai;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ek = _ion_ek;
  cai = _ion_cai;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(c) - _p;  _dlist1[0] = &(Dc) - _p;
   _t_c_inf = makevector(13001*sizeof(double));
   _t_tau_c = makevector(13001*sizeof(double));
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/home/stefano/Documenti/paperRevision/GL_Model/templates/granule/GRANULE_KCA.mod";
static const char* nmodl_file_text = 
  "TITLE Cerebellum Granule Cell Model\n"
  "\n"
  "COMMENT\n"
  "        KCa channel\n"
  "   \n"
  "	Author: E.D'Angelo, T.Nieus, A. Fontana\n"
  "	Last revised: 8.5.2000\n"
  "ENDCOMMENT\n"
  " \n"
  "NEURON { \n"
  "	SUFFIX GRANULE_KCA\n"
  "	USEION k READ ek WRITE ik\n"
  "	USEION ca READ cai\n"
  "	RANGE Q10_diff,Q10_channel,gbar_Q10\n"
  "	RANGE gbar, ic, g, alpha_c, beta_c\n"
  "	RANGE Aalpha_c, Balpha_c, Kalpha_c\n"
  "	RANGE Abeta_c, Bbeta_c, Kbeta_c \n"
  "	RANGE c_inf, tau_c \n"
  "} \n"
  " \n"
  "UNITS { \n"
  "	(mA) = (milliamp) \n"
  "	(mV) = (millivolt) \n"
  "	(molar) = (1/liter)\n"
  "	(mM) = (millimolar)\n"
  "} \n"
  " \n"
  "PARAMETER { \n"
  "	Aalpha_c = 2.5 (/ms)\n"
  "	Balpha_c = 1.5e-3 (mM)\n"
  "\n"
  "	Kalpha_c =  -11.765 (mV)\n"
  "\n"
  "	Abeta_c = 1.5 (/ms)\n"
  "	Bbeta_c = 0.15e-3 (mM)\n"
  "\n"
  "	Kbeta_c = -11.765 (mV)\n"
  "\n"
  "	v (mV) \n"
  "	cai (mM)\n"
  "	Q10_diff	= 1.5\n"
  "	Q10_channel	= 3\n"
  "	gbar= 0.0045 (mho/cm2) \n"
  "	ek = -84.69 (mV) \n"
  "	celsius (degC)\n"
  "} \n"
  "\n"
  "STATE { \n"
  "	c \n"
  "} \n"
  "\n"
  "ASSIGNED { \n"
  "	ic (mA/cm2) \n"
  "	ik (mA/cm2)\n"
  "\n"
  "	c_inf \n"
  "	tau_c (ms) \n"
  "	g (mho/cm2) \n"
  "	alpha_c (/ms) \n"
  "	beta_c (/ms) \n"
  "	gbar_Q10 (mho/cm2)\n"
  "} \n"
  " \n"
  "INITIAL { \n"
  "	gbar_Q10 = gbar*(Q10_diff^((celsius-30)/10))\n"
  "	rate(v) \n"
  "	c = c_inf \n"
  "} \n"
  " \n"
  "BREAKPOINT { \n"
  "	SOLVE states METHOD cnexp \n"
  "	g = gbar_Q10*c \n"
  "	ik = g*(v - ek) \n"
  "	ic = ik\n"
  "	alpha_c = alp_c(v) \n"
  "	beta_c = bet_c(v) \n"
  "} \n"
  " \n"
  "DERIVATIVE states { \n"
  "	rate(v) \n"
  "	c' =(c_inf - c)/tau_c \n"
  "} \n"
  " \n"
  "FUNCTION alp_c(v(mV))(/ms) { LOCAL Q10\n"
  "	Q10 = Q10_channel^((celsius-30(degC))/10(degC))\n"
  "	alp_c = Q10*Aalpha_c/(1+(Balpha_c*exp(v/Kalpha_c)/cai)) \n"
  "} \n"
  " \n"
  "FUNCTION bet_c(v(mV))(/ms) { LOCAL Q10\n"
  "	Q10 = Q10_channel^((celsius-30(degC))/10(degC))\n"
  "	bet_c = Q10*Abeta_c/(1+cai/(Bbeta_c*exp(v/Kbeta_c))) \n"
  "} \n"
  " \n"
  "PROCEDURE rate(v (mV)) {LOCAL a_c, b_c \n"
  "	TABLE c_inf, tau_c \n"
  "	DEPEND Aalpha_c, Balpha_c, Kalpha_c, \n"
  "	       Abeta_c, Bbeta_c, Kbeta_c, celsius FROM -100 TO 30 WITH 13000 \n"
  "	a_c = alp_c(v)  \n"
  "	b_c = bet_c(v) \n"
  "	tau_c = 1/(a_c + b_c) \n"
  "	c_inf = a_c/(a_c + b_c) \n"
  "} \n"
  "\n"
  ;
#endif
