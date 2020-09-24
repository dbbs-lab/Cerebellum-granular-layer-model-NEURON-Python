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
 
#define nrn_init _nrn_init__GRANULE_CA
#define _nrn_initial _nrn_initial__GRANULE_CA
#define nrn_cur _nrn_cur__GRANULE_CA
#define _nrn_current _nrn_current__GRANULE_CA
#define nrn_jacob _nrn_jacob__GRANULE_CA
#define nrn_state _nrn_state__GRANULE_CA
#define _net_receive _net_receive__GRANULE_CA 
#define _f_rate _f_rate__GRANULE_CA 
#define rate rate__GRANULE_CA 
#define states states__GRANULE_CA 
 
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
#define Aalpha_s _p[0]
#define Kalpha_s _p[1]
#define V0alpha_s _p[2]
#define Abeta_s _p[3]
#define Kbeta_s _p[4]
#define V0beta_s _p[5]
#define Aalpha_u _p[6]
#define Kalpha_u _p[7]
#define V0alpha_u _p[8]
#define Abeta_u _p[9]
#define Kbeta_u _p[10]
#define V0beta_u _p[11]
#define Q10_diff _p[12]
#define Q10_channel _p[13]
#define gbar _p[14]
#define ica _p[15]
#define ic _p[16]
#define s_inf _p[17]
#define u_inf _p[18]
#define tau_s _p[19]
#define tau_u _p[20]
#define g _p[21]
#define alpha_s _p[22]
#define beta_s _p[23]
#define alpha_u _p[24]
#define beta_u _p[25]
#define gbar_Q10 _p[26]
#define s _p[27]
#define u _p[28]
#define eca _p[29]
#define Ds _p[30]
#define Du _p[31]
#define v _p[32]
#define _g _p[33]
#define _ion_eca	*_ppvar[0]._pval
#define _ion_ica	*_ppvar[1]._pval
#define _ion_dicadv	*_ppvar[2]._pval
 
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
 static void _hoc_alp_u(void);
 static void _hoc_alp_s(void);
 static void _hoc_bet_u(void);
 static void _hoc_bet_s(void);
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
 "setdata_GRANULE_CA", _hoc_setdata,
 "alp_u_GRANULE_CA", _hoc_alp_u,
 "alp_s_GRANULE_CA", _hoc_alp_s,
 "bet_u_GRANULE_CA", _hoc_bet_u,
 "bet_s_GRANULE_CA", _hoc_bet_s,
 "rate_GRANULE_CA", _hoc_rate,
 0, 0
};
#define alp_u alp_u_GRANULE_CA
#define alp_s alp_s_GRANULE_CA
#define bet_u bet_u_GRANULE_CA
#define bet_s bet_s_GRANULE_CA
 extern double alp_u( _threadargsprotocomma_ double );
 extern double alp_s( _threadargsprotocomma_ double );
 extern double bet_u( _threadargsprotocomma_ double );
 extern double bet_s( _threadargsprotocomma_ double );
 
static void _check_rate(double*, Datum*, Datum*, _NrnThread*); 
static void _check_table_thread(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, int _type) {
   _check_rate(_p, _ppvar, _thread, _nt);
 }
 /* declare global and static user variables */
#define usetable usetable_GRANULE_CA
 double usetable = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "usetable_GRANULE_CA", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Aalpha_s_GRANULE_CA", "/ms",
 "Kalpha_s_GRANULE_CA", "mV",
 "V0alpha_s_GRANULE_CA", "mV",
 "Abeta_s_GRANULE_CA", "/ms",
 "Kbeta_s_GRANULE_CA", "mV",
 "V0beta_s_GRANULE_CA", "mV",
 "Aalpha_u_GRANULE_CA", "/ms",
 "Kalpha_u_GRANULE_CA", "mV",
 "V0alpha_u_GRANULE_CA", "mV",
 "Abeta_u_GRANULE_CA", "/ms",
 "Kbeta_u_GRANULE_CA", "mV",
 "V0beta_u_GRANULE_CA", "mV",
 "gbar_GRANULE_CA", "mho/cm2",
 "ica_GRANULE_CA", "mA/cm2",
 "ic_GRANULE_CA", "mA/cm2",
 "tau_s_GRANULE_CA", "ms",
 "tau_u_GRANULE_CA", "ms",
 "g_GRANULE_CA", "mho/cm2",
 "alpha_s_GRANULE_CA", "/ms",
 "beta_s_GRANULE_CA", "/ms",
 "alpha_u_GRANULE_CA", "/ms",
 "beta_u_GRANULE_CA", "/ms",
 "gbar_Q10_GRANULE_CA", "mho/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double s0 = 0;
 static double u0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "usetable_GRANULE_CA", &usetable_GRANULE_CA,
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
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"GRANULE_CA",
 "Aalpha_s_GRANULE_CA",
 "Kalpha_s_GRANULE_CA",
 "V0alpha_s_GRANULE_CA",
 "Abeta_s_GRANULE_CA",
 "Kbeta_s_GRANULE_CA",
 "V0beta_s_GRANULE_CA",
 "Aalpha_u_GRANULE_CA",
 "Kalpha_u_GRANULE_CA",
 "V0alpha_u_GRANULE_CA",
 "Abeta_u_GRANULE_CA",
 "Kbeta_u_GRANULE_CA",
 "V0beta_u_GRANULE_CA",
 "Q10_diff_GRANULE_CA",
 "Q10_channel_GRANULE_CA",
 "gbar_GRANULE_CA",
 0,
 "ica_GRANULE_CA",
 "ic_GRANULE_CA",
 "s_inf_GRANULE_CA",
 "u_inf_GRANULE_CA",
 "tau_s_GRANULE_CA",
 "tau_u_GRANULE_CA",
 "g_GRANULE_CA",
 "alpha_s_GRANULE_CA",
 "beta_s_GRANULE_CA",
 "alpha_u_GRANULE_CA",
 "beta_u_GRANULE_CA",
 "gbar_Q10_GRANULE_CA",
 0,
 "s_GRANULE_CA",
 "u_GRANULE_CA",
 0,
 0};
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 34, _prop);
 	/*initialize range parameters*/
 	Aalpha_s = 0.04944;
 	Kalpha_s = 15.873;
 	V0alpha_s = -29.06;
 	Abeta_s = 0.08298;
 	Kbeta_s = -25.641;
 	V0beta_s = -18.66;
 	Aalpha_u = 0.0013;
 	Kalpha_u = -18.183;
 	V0alpha_u = -48;
 	Abeta_u = 0.0013;
 	Kbeta_u = 83.33;
 	V0beta_u = -48;
 	Q10_diff = 1.5;
 	Q10_channel = 3;
 	gbar = 0.00046;
 	_prop->param = _p;
 	_prop->param_size = 34;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* eca */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 
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

 void _GRANULE_CA_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
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
  hoc_register_prop_size(_mechtype, 34, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GRANULE_CA /home/stefano/Documenti/paperRevision/GL_Model/x86_64/GRANULE_CA.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double *_t_s_inf;
 static double *_t_tau_s;
 static double *_t_u_inf;
 static double *_t_tau_u;
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
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rate ( _threadargscomma_ v ) ;
   Ds = ( s_inf - s ) / tau_s ;
   Du = ( u_inf - u ) / tau_u ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rate ( _threadargscomma_ v ) ;
 Ds = Ds  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_s )) ;
 Du = Du  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_u )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rate ( _threadargscomma_ v ) ;
    s = s + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_s)))*(- ( ( ( s_inf ) ) / tau_s ) / ( ( ( ( - 1.0 ) ) ) / tau_s ) - s) ;
    u = u + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_u)))*(- ( ( ( u_inf ) ) / tau_u ) / ( ( ( ( - 1.0 ) ) ) / tau_u ) - u) ;
   }
  return 0;
}
 
double alp_s ( _threadargsprotocomma_ double _lv ) {
   double _lalp_s;
 double _lQ10 ;
 _lQ10 = pow( Q10_channel , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   _lalp_s = _lQ10 * Aalpha_s * exp ( ( _lv - V0alpha_s ) / Kalpha_s ) ;
   
return _lalp_s;
 }
 
static void _hoc_alp_s(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alp_s ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double bet_s ( _threadargsprotocomma_ double _lv ) {
   double _lbet_s;
 double _lQ10 ;
 _lQ10 = pow( Q10_channel , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   _lbet_s = _lQ10 * Abeta_s * exp ( ( _lv - V0beta_s ) / Kbeta_s ) ;
   
return _lbet_s;
 }
 
static void _hoc_bet_s(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  bet_s ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double alp_u ( _threadargsprotocomma_ double _lv ) {
   double _lalp_u;
 double _lQ10 ;
 _lQ10 = pow( Q10_channel , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   _lalp_u = _lQ10 * Aalpha_u * exp ( ( _lv - V0alpha_u ) / Kalpha_u ) ;
   
return _lalp_u;
 }
 
static void _hoc_alp_u(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alp_u ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double bet_u ( _threadargsprotocomma_ double _lv ) {
   double _lbet_u;
 double _lQ10 ;
 _lQ10 = pow( Q10_channel , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   _lbet_u = _lQ10 * Abeta_u * exp ( ( _lv - V0beta_u ) / Kbeta_u ) ;
   
return _lbet_u;
 }
 
static void _hoc_bet_u(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  bet_u ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 static double _mfac_rate, _tmin_rate;
  static void _check_rate(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  static double _sav_Aalpha_s;
  static double _sav_Kalpha_s;
  static double _sav_V0alpha_s;
  static double _sav_Abeta_s;
  static double _sav_Kbeta_s;
  static double _sav_V0beta_s;
  static double _sav_Aalpha_u;
  static double _sav_Kalpha_u;
  static double _sav_V0alpha_u;
  static double _sav_Abeta_u;
  static double _sav_Kbeta_u;
  static double _sav_V0beta_u;
  static double _sav_celsius;
  if (!usetable) {return;}
  if (_sav_Aalpha_s != Aalpha_s) { _maktable = 1;}
  if (_sav_Kalpha_s != Kalpha_s) { _maktable = 1;}
  if (_sav_V0alpha_s != V0alpha_s) { _maktable = 1;}
  if (_sav_Abeta_s != Abeta_s) { _maktable = 1;}
  if (_sav_Kbeta_s != Kbeta_s) { _maktable = 1;}
  if (_sav_V0beta_s != V0beta_s) { _maktable = 1;}
  if (_sav_Aalpha_u != Aalpha_u) { _maktable = 1;}
  if (_sav_Kalpha_u != Kalpha_u) { _maktable = 1;}
  if (_sav_V0alpha_u != V0alpha_u) { _maktable = 1;}
  if (_sav_Abeta_u != Abeta_u) { _maktable = 1;}
  if (_sav_Kbeta_u != Kbeta_u) { _maktable = 1;}
  if (_sav_V0beta_u != V0beta_u) { _maktable = 1;}
  if (_sav_celsius != celsius) { _maktable = 1;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_rate =  - 100.0 ;
   _tmax =  30.0 ;
   _dx = (_tmax - _tmin_rate)/13000.; _mfac_rate = 1./_dx;
   for (_i=0, _x=_tmin_rate; _i < 13001; _x += _dx, _i++) {
    _f_rate(_p, _ppvar, _thread, _nt, _x);
    _t_s_inf[_i] = s_inf;
    _t_tau_s[_i] = tau_s;
    _t_u_inf[_i] = u_inf;
    _t_tau_u[_i] = tau_u;
   }
   _sav_Aalpha_s = Aalpha_s;
   _sav_Kalpha_s = Kalpha_s;
   _sav_V0alpha_s = V0alpha_s;
   _sav_Abeta_s = Abeta_s;
   _sav_Kbeta_s = Kbeta_s;
   _sav_V0beta_s = V0beta_s;
   _sav_Aalpha_u = Aalpha_u;
   _sav_Kalpha_u = Kalpha_u;
   _sav_V0alpha_u = V0alpha_u;
   _sav_Abeta_u = Abeta_u;
   _sav_Kbeta_u = Kbeta_u;
   _sav_V0beta_u = V0beta_u;
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
  s_inf = _xi;
  tau_s = _xi;
  u_inf = _xi;
  tau_u = _xi;
  return;
 }
 if (_xi <= 0.) {
 s_inf = _t_s_inf[0];
 tau_s = _t_tau_s[0];
 u_inf = _t_u_inf[0];
 tau_u = _t_tau_u[0];
 return; }
 if (_xi >= 13000.) {
 s_inf = _t_s_inf[13000];
 tau_s = _t_tau_s[13000];
 u_inf = _t_u_inf[13000];
 tau_u = _t_tau_u[13000];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 s_inf = _t_s_inf[_i] + _theta*(_t_s_inf[_i+1] - _t_s_inf[_i]);
 tau_s = _t_tau_s[_i] + _theta*(_t_tau_s[_i+1] - _t_tau_s[_i]);
 u_inf = _t_u_inf[_i] + _theta*(_t_u_inf[_i+1] - _t_u_inf[_i]);
 tau_u = _t_tau_u[_i] + _theta*(_t_tau_u[_i+1] - _t_tau_u[_i]);
 }

 
static int  _f_rate ( _threadargsprotocomma_ double _lv ) {
   double _la_s , _lb_s , _la_u , _lb_u ;
 _la_s = alp_s ( _threadargscomma_ _lv ) ;
   _lb_s = bet_s ( _threadargscomma_ _lv ) ;
   _la_u = alp_u ( _threadargscomma_ _lv ) ;
   _lb_u = bet_u ( _threadargscomma_ _lv ) ;
   s_inf = _la_s / ( _la_s + _lb_s ) ;
   tau_s = 1.0 / ( _la_s + _lb_s ) ;
   u_inf = _la_u / ( _la_u + _lb_u ) ;
   tau_u = 1.0 / ( _la_u + _lb_u ) ;
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
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  eca = _ion_eca;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
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
  eca = _ion_eca;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  s = s0;
  u = u0;
 {
   gbar_Q10 = gbar * ( pow( Q10_diff , ( ( celsius - 30.0 ) / 10.0 ) ) ) ;
   rate ( _threadargscomma_ v ) ;
   s = s_inf ;
   u = u_inf ;
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
  eca = _ion_eca;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   g = gbar_Q10 * s * s * u ;
   ica = g * ( v - eca ) ;
   ic = ica ;
   alpha_s = alp_s ( _threadargscomma_ v ) ;
   beta_s = bet_s ( _threadargscomma_ v ) ;
   alpha_u = alp_u ( _threadargscomma_ v ) ;
   beta_u = bet_u ( _threadargscomma_ v ) ;
   }
 _current += ica;

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
  eca = _ion_eca;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dica;
  _dica = ica;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ica += ica ;
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
  eca = _ion_eca;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(s) - _p;  _dlist1[0] = &(Ds) - _p;
 _slist1[1] = &(u) - _p;  _dlist1[1] = &(Du) - _p;
   _t_s_inf = makevector(13001*sizeof(double));
   _t_tau_s = makevector(13001*sizeof(double));
   _t_u_inf = makevector(13001*sizeof(double));
   _t_tau_u = makevector(13001*sizeof(double));
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/home/stefano/Documenti/paperRevision/GL_Model/templates/granule/GRANULE_CA.mod";
static const char* nmodl_file_text = 
  "TITLE Cerebellum Granule Cell Model\n"
  "\n"
  "COMMENT\n"
  "        CaHVA channel\n"
  "   \n"
  "	Author: E.D'Angelo, T.Nieus, A. Fontana\n"
  "	Last revised: 8.5.2000\n"
  "ENDCOMMENT\n"
  " \n"
  "NEURON { \n"
  "	SUFFIX GRANULE_CA \n"
  "	USEION ca READ eca WRITE ica \n"
  "	RANGE Q10_diff,Q10_channel,gbar_Q10\n"
  "	RANGE gbar, ica, ic , g, alpha_s, beta_s, alpha_u, beta_u \n"
  "	RANGE Aalpha_s, Kalpha_s, V0alpha_s\n"
  "	RANGE Abeta_s, Kbeta_s, V0beta_s\n"
  "	RANGE Aalpha_u, Kalpha_u, V0alpha_u\n"
  "	RANGE Abeta_u, Kbeta_u, V0beta_u\n"
  "	RANGE s_inf, tau_s, u_inf, tau_u \n"
  "} \n"
  " \n"
  "UNITS { \n"
  "	(mA) = (milliamp) \n"
  "	(mV) = (millivolt) \n"
  "} \n"
  " \n"
  "PARAMETER { \n"
  "	\n"
  "	Aalpha_s = 0.04944 (/ms)\n"
  "	Kalpha_s =  15.873 (mV)\n"
  "	V0alpha_s = -29.06 (mV)\n"
  "	\n"
  "	Abeta_s = 0.08298 (/ms)\n"
  "	Kbeta_s =  -25.641 (mV)\n"
  "	V0beta_s = -18.66 (mV)\n"
  "	\n"
  "	\n"
  "\n"
  "	Aalpha_u = 0.0013 (/ms)\n"
  "	Kalpha_u =  -18.183 (mV)\n"
  "	V0alpha_u = -48 (mV)\n"
  "		\n"
  "	Abeta_u = 0.0013 (/ms)\n"
  "	Kbeta_u =   83.33 (mV)\n"
  "	V0beta_u = -48 (mV)\n"
  "\n"
  "	v (mV) \n"
  "	Q10_diff	= 1.5\n"
  "	Q10_channel	= 3\n"
  "	gbar= 0.00046 (mho/cm2) \n"
  "	eca (mV) \n"
  "	celsius (degC)\n"
  "} \n"
  "\n"
  "STATE { \n"
  "	s \n"
  "	u \n"
  "} \n"
  "\n"
  "ASSIGNED { \n"
  "	ica (mA/cm2) \n"
  "	ic (mA/cm2) \n"
  "	s_inf \n"
  "	u_inf \n"
  "	tau_s (ms) \n"
  "	tau_u (ms) \n"
  "	g (mho/cm2) \n"
  "	alpha_s (/ms)\n"
  "	beta_s (/ms)\n"
  "	alpha_u (/ms)\n"
  "	beta_u (/ms)\n"
  "	gbar_Q10 (mho/cm2)\n"
  "} \n"
  " \n"
  "INITIAL { \n"
  "	gbar_Q10 = gbar*(Q10_diff^((celsius-30)/10))\n"
  "	rate(v) \n"
  "	s = s_inf \n"
  "	u = u_inf \n"
  "} \n"
  " \n"
  "BREAKPOINT { \n"
  "	SOLVE states METHOD cnexp \n"
  "	g = gbar_Q10*s*s*u \n"
  "	ica = g*(v - eca) \n"
  "	ic = ica\n"
  "	alpha_s = alp_s(v)\n"
  "	beta_s = bet_s(v)\n"
  "	alpha_u = alp_u(v)\n"
  "	beta_u = bet_u(v)\n"
  "}\n"
  " \n"
  "DERIVATIVE states { \n"
  "	rate(v) \n"
  "	s' =(s_inf - s)/tau_s \n"
  "	u' =(u_inf - u)/tau_u \n"
  "} \n"
  " \n"
  "FUNCTION alp_s(v(mV))(/ms) { LOCAL Q10\n"
  "	Q10 = Q10_channel^((celsius-20(degC))/10(degC))\n"
  "	alp_s = Q10*Aalpha_s*exp((v-V0alpha_s)/Kalpha_s) \n"
  "} \n"
  " \n"
  "FUNCTION bet_s(v(mV))(/ms) { LOCAL Q10\n"
  "	Q10 = Q10_channel^((celsius-20(degC))/10(degC))\n"
  "	bet_s = Q10*Abeta_s*exp((v-V0beta_s)/Kbeta_s) \n"
  "} \n"
  " \n"
  "FUNCTION alp_u(v(mV))(/ms) { LOCAL Q10\n"
  "	Q10 = Q10_channel^((celsius-20(degC))/10(degC))\n"
  "	alp_u = Q10*Aalpha_u*exp((v-V0alpha_u)/Kalpha_u) \n"
  "} \n"
  " \n"
  "FUNCTION bet_u(v(mV))(/ms) { LOCAL Q10\n"
  "	Q10 = Q10_channel^((celsius-20(degC))/10(degC))\n"
  "	bet_u = Q10*Abeta_u*exp((v-V0beta_u)/Kbeta_u) \n"
  "} \n"
  " \n"
  "PROCEDURE rate(v (mV)) {LOCAL a_s, b_s, a_u, b_u \n"
  "	TABLE s_inf, tau_s, u_inf, tau_u \n"
  "	DEPEND Aalpha_s, Kalpha_s, V0alpha_s, \n"
  "	       Abeta_s, Kbeta_s, V0beta_s,\n"
  "               Aalpha_u, Kalpha_u, V0alpha_u,\n"
  "               Abeta_u, Kbeta_u, V0beta_u, celsius FROM -100 TO 30 WITH 13000 \n"
  "	a_s = alp_s(v)  \n"
  "	b_s = bet_s(v) \n"
  "	a_u = alp_u(v)  \n"
  "	b_u = bet_u(v) \n"
  "	s_inf = a_s/(a_s + b_s) \n"
  "	tau_s = 1/(a_s + b_s) \n"
  "	u_inf = a_u/(a_u + b_u) \n"
  "	tau_u = 1/(a_u + b_u) \n"
  "}\n"
  "\n"
  ;
#endif
