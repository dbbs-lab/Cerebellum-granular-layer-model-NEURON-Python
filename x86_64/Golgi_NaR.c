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
 
#define nrn_init _nrn_init__Golgi_NaR
#define _nrn_initial _nrn_initial__Golgi_NaR
#define nrn_cur _nrn_cur__Golgi_NaR
#define _nrn_current _nrn_current__Golgi_NaR
#define nrn_jacob _nrn_jacob__Golgi_NaR
#define nrn_state _nrn_state__Golgi_NaR
#define _net_receive _net_receive__Golgi_NaR 
#define _f_rate _f_rate__Golgi_NaR 
#define rate rate__Golgi_NaR 
#define states states__Golgi_NaR 
 
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
#define V0alpha_s _p[1]
#define Kalpha_s _p[2]
#define Shiftalpha_s _p[3]
#define Abeta_s _p[4]
#define V0beta_s _p[5]
#define Kbeta_s _p[6]
#define Shiftbeta_s _p[7]
#define Aalpha_f _p[8]
#define V0alpha_f _p[9]
#define Kalpha_f _p[10]
#define Abeta_f _p[11]
#define V0beta_f _p[12]
#define Kbeta_f _p[13]
#define gbar _p[14]
#define Q10_diff _p[15]
#define Q10_channel _p[16]
#define ina _p[17]
#define g _p[18]
#define s_inf _p[19]
#define tau_s _p[20]
#define f_inf _p[21]
#define tau_f _p[22]
#define tcorr _p[23]
#define gbar_Q10 _p[24]
#define ic _p[25]
#define s _p[26]
#define f _p[27]
#define ena _p[28]
#define Ds _p[29]
#define Df _p[30]
#define alpha_s _p[31]
#define beta_s _p[32]
#define alpha_f _p[33]
#define beta_f _p[34]
#define v _p[35]
#define _g _p[36]
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
 
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
 static void _hoc_alp_f(void);
 static void _hoc_alp_s(void);
 static void _hoc_bet_f(void);
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
 "setdata_Golgi_NaR", _hoc_setdata,
 "alp_f_Golgi_NaR", _hoc_alp_f,
 "alp_s_Golgi_NaR", _hoc_alp_s,
 "bet_f_Golgi_NaR", _hoc_bet_f,
 "bet_s_Golgi_NaR", _hoc_bet_s,
 "rate_Golgi_NaR", _hoc_rate,
 0, 0
};
#define alp_f alp_f_Golgi_NaR
#define alp_s alp_s_Golgi_NaR
#define bet_f bet_f_Golgi_NaR
#define bet_s bet_s_Golgi_NaR
 extern double alp_f( _threadargsprotocomma_ double );
 extern double alp_s( _threadargsprotocomma_ double );
 extern double bet_f( _threadargsprotocomma_ double );
 extern double bet_s( _threadargsprotocomma_ double );
 
static void _check_rate(double*, Datum*, Datum*, _NrnThread*); 
static void _check_table_thread(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, int _type) {
   _check_rate(_p, _ppvar, _thread, _nt);
 }
 /* declare global and static user variables */
#define usetable usetable_Golgi_NaR
 double usetable = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "usetable_Golgi_NaR", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Aalpha_s_Golgi_NaR", "/ms",
 "V0alpha_s_Golgi_NaR", "mV",
 "Kalpha_s_Golgi_NaR", "mV",
 "Shiftalpha_s_Golgi_NaR", "/ms",
 "Abeta_s_Golgi_NaR", "/ms",
 "V0beta_s_Golgi_NaR", "mV",
 "Kbeta_s_Golgi_NaR", "mV",
 "Shiftbeta_s_Golgi_NaR", "/ms",
 "Aalpha_f_Golgi_NaR", "/ms",
 "V0alpha_f_Golgi_NaR", "mV",
 "Kalpha_f_Golgi_NaR", "mV",
 "Abeta_f_Golgi_NaR", "/ms",
 "V0beta_f_Golgi_NaR", "mV",
 "Kbeta_f_Golgi_NaR", "mV",
 "gbar_Golgi_NaR", "mho/cm2",
 "ina_Golgi_NaR", "mA/cm2",
 "g_Golgi_NaR", "mho/cm2",
 "tau_s_Golgi_NaR", "ms",
 "tau_f_Golgi_NaR", "ms",
 "tcorr_Golgi_NaR", "1",
 "gbar_Q10_Golgi_NaR", "mho/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double f0 = 0;
 static double s0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "usetable_Golgi_NaR", &usetable_Golgi_NaR,
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
"Golgi_NaR",
 "Aalpha_s_Golgi_NaR",
 "V0alpha_s_Golgi_NaR",
 "Kalpha_s_Golgi_NaR",
 "Shiftalpha_s_Golgi_NaR",
 "Abeta_s_Golgi_NaR",
 "V0beta_s_Golgi_NaR",
 "Kbeta_s_Golgi_NaR",
 "Shiftbeta_s_Golgi_NaR",
 "Aalpha_f_Golgi_NaR",
 "V0alpha_f_Golgi_NaR",
 "Kalpha_f_Golgi_NaR",
 "Abeta_f_Golgi_NaR",
 "V0beta_f_Golgi_NaR",
 "Kbeta_f_Golgi_NaR",
 "gbar_Golgi_NaR",
 "Q10_diff_Golgi_NaR",
 "Q10_channel_Golgi_NaR",
 0,
 "ina_Golgi_NaR",
 "g_Golgi_NaR",
 "s_inf_Golgi_NaR",
 "tau_s_Golgi_NaR",
 "f_inf_Golgi_NaR",
 "tau_f_Golgi_NaR",
 "tcorr_Golgi_NaR",
 "gbar_Q10_Golgi_NaR",
 "ic_Golgi_NaR",
 0,
 "s_Golgi_NaR",
 "f_Golgi_NaR",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 37, _prop);
 	/*initialize range parameters*/
 	Aalpha_s = -0.00493;
 	V0alpha_s = -4.48754;
 	Kalpha_s = -6.81881;
 	Shiftalpha_s = 8e-05;
 	Abeta_s = 0.01558;
 	V0beta_s = 43.9749;
 	Kbeta_s = 0.10818;
 	Shiftbeta_s = 0.04752;
 	Aalpha_f = 0.31836;
 	V0alpha_f = -80;
 	Kalpha_f = -62.5262;
 	Abeta_f = 0.01014;
 	V0beta_f = -83.3332;
 	Kbeta_f = 16.0538;
 	gbar = 0.0017;
 	Q10_diff = 1.5;
 	Q10_channel = 3;
 	_prop->param = _p;
 	_prop->param_size = 37;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
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

 void _Golgi_NaR_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
     _nrn_thread_table_reg(_mechtype, _check_table_thread);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 37, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Golgi_NaR /home/stefano/Documenti/paperRevision/GL_Model/x86_64/Golgi_NaR.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double *_t_s_inf;
 static double *_t_tau_s;
 static double *_t_f_inf;
 static double *_t_tau_f;
static int _reset;
static char *modelname = "Cerebellum Golgi Cell Model";

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
   Df = ( f_inf - f ) / tau_f ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rate ( _threadargscomma_ v ) ;
 Ds = Ds  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_s )) ;
 Df = Df  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_f )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rate ( _threadargscomma_ v ) ;
    s = s + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_s)))*(- ( ( ( s_inf ) ) / tau_s ) / ( ( ( ( - 1.0 ) ) ) / tau_s ) - s) ;
    f = f + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_f)))*(- ( ( ( f_inf ) ) / tau_f ) / ( ( ( ( - 1.0 ) ) ) / tau_f ) - f) ;
   }
  return 0;
}
 static double _mfac_rate, _tmin_rate;
  static void _check_rate(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  static double _sav_celsius;
  if (!usetable) {return;}
  if (_sav_celsius != celsius) { _maktable = 1;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_rate =  - 100.0 ;
   _tmax =  30.0 ;
   _dx = (_tmax - _tmin_rate)/13000.; _mfac_rate = 1./_dx;
   for (_i=0, _x=_tmin_rate; _i < 13001; _x += _dx, _i++) {
    _f_rate(_p, _ppvar, _thread, _nt, _x);
    _t_s_inf[_i] = s_inf;
    _t_tau_s[_i] = tau_s;
    _t_f_inf[_i] = f_inf;
    _t_tau_f[_i] = tau_f;
   }
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
  f_inf = _xi;
  tau_f = _xi;
  return;
 }
 if (_xi <= 0.) {
 s_inf = _t_s_inf[0];
 tau_s = _t_tau_s[0];
 f_inf = _t_f_inf[0];
 tau_f = _t_tau_f[0];
 return; }
 if (_xi >= 13000.) {
 s_inf = _t_s_inf[13000];
 tau_s = _t_tau_s[13000];
 f_inf = _t_f_inf[13000];
 tau_f = _t_tau_f[13000];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 s_inf = _t_s_inf[_i] + _theta*(_t_s_inf[_i+1] - _t_s_inf[_i]);
 tau_s = _t_tau_s[_i] + _theta*(_t_tau_s[_i+1] - _t_tau_s[_i]);
 f_inf = _t_f_inf[_i] + _theta*(_t_f_inf[_i+1] - _t_f_inf[_i]);
 tau_f = _t_tau_f[_i] + _theta*(_t_tau_f[_i+1] - _t_tau_f[_i]);
 }

 
static int  _f_rate ( _threadargsprotocomma_ double _lv ) {
   double _la_s , _lb_s , _la_f , _lb_f ;
 _la_s = alp_s ( _threadargscomma_ _lv ) ;
   _lb_s = bet_s ( _threadargscomma_ _lv ) ;
   s_inf = _la_s / ( _la_s + _lb_s ) ;
   tau_s = 1.0 / ( _la_s + _lb_s ) ;
   _la_f = alp_f ( _threadargscomma_ _lv ) ;
   _lb_f = bet_f ( _threadargscomma_ _lv ) ;
   f_inf = _la_f / ( _la_f + _lb_f ) ;
   tau_f = 1.0 / ( _la_f + _lb_f ) ;
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
 
double alp_s ( _threadargsprotocomma_ double _lv ) {
   double _lalp_s;
 tcorr = pow( Q10_channel , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   _lalp_s = tcorr * ( Shiftalpha_s + Aalpha_s * ( ( _lv + V0alpha_s ) / 1.0 ) / ( exp ( ( _lv + V0alpha_s ) / Kalpha_s ) - 1.0 ) ) ;
   
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
 double _lx1 ;
 tcorr = pow( Q10_channel , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   _lx1 = ( _lv + V0beta_s ) / Kbeta_s ;
   if ( _lx1 > 200.0 ) {
     _lx1 = 200.0 ;
     }
   _lbet_s = tcorr * ( Shiftbeta_s + Abeta_s * ( ( _lv + V0beta_s ) / 1.0 ) / ( exp ( _lx1 ) - 1.0 ) ) ;
   
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
 
double alp_f ( _threadargsprotocomma_ double _lv ) {
   double _lalp_f;
 tcorr = pow( Q10_channel , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   _lalp_f = tcorr * Aalpha_f * exp ( ( _lv - V0alpha_f ) / Kalpha_f ) ;
   
return _lalp_f;
 }
 
static void _hoc_alp_f(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alp_f ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double bet_f ( _threadargsprotocomma_ double _lv ) {
   double _lbet_f;
 tcorr = pow( Q10_channel , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   _lbet_f = tcorr * Abeta_f * exp ( ( _lv - V0beta_f ) / Kbeta_f ) ;
   
return _lbet_f;
 }
 
static void _hoc_bet_f(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  bet_f ( _p, _ppvar, _thread, _nt, *getarg(1) );
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
  ena = _ion_ena;
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
  ena = _ion_ena;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  f = f0;
  s = s0;
 {
   gbar_Q10 = gbar * ( pow( Q10_diff , ( ( celsius - 23.0 ) / 10.0 ) ) ) ;
   rate ( _threadargscomma_ v ) ;
   s = s_inf ;
   f = f_inf ;
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
  ena = _ion_ena;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   g = gbar_Q10 * s * f ;
   ina = g * ( v - ena ) ;
   ic = ina ;
   alpha_s = alp_s ( _threadargscomma_ v ) ;
   beta_s = bet_s ( _threadargscomma_ v ) ;
   alpha_f = alp_f ( _threadargscomma_ v ) ;
   beta_f = bet_f ( _threadargscomma_ v ) ;
   }
 _current += ina;

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
  ena = _ion_ena;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
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
  ena = _ion_ena;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(s) - _p;  _dlist1[0] = &(Ds) - _p;
 _slist1[1] = &(f) - _p;  _dlist1[1] = &(Df) - _p;
   _t_s_inf = makevector(13001*sizeof(double));
   _t_tau_s = makevector(13001*sizeof(double));
   _t_f_inf = makevector(13001*sizeof(double));
   _t_tau_f = makevector(13001*sizeof(double));
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/home/stefano/Documenti/paperRevision/GL_Model/templates/golgi/Golgi_NaR.mod";
static const char* nmodl_file_text = 
  "TITLE Cerebellum Golgi Cell Model\n"
  "\n"
  "COMMENT\n"
  "        Na resurgent channel\n"
  "	  \n"
  "	Author: T.Nieus\n"
  "	Last revised: 30.6.2003 \n"
  "	Critical value gNa\n"
  "	Inserted a control in bet_s to avoid huge values of x1\n"
  "			\n"
  "ENDCOMMENT\n"
  " \n"
  "NEURON { \n"
  "	SUFFIX Golgi_NaR\n"
  "	USEION na READ ena WRITE ina \n"
  "	RANGE Q10_diff,Q10_channel,gbar_Q10\n"
  "	RANGE gbar, ina, g\n"
  "	RANGE Aalpha_s,Abeta_s,V0alpha_s,V0beta_s,Kalpha_s,Kbeta_s \n"
  "        RANGE Shiftalpha_s,Shiftbeta_s,tau_s,s_inf\n"
  "	RANGE Aalpha_f,Abeta_f,V0alpha_f,V0beta_f,Kalpha_f, Kbeta_f\n"
  "	RANGE f, tau_f,f_inf,s , tau_s,s_inf, tcorr, ic\n"
  "} \n"
  " \n"
  "UNITS {    \n"
  "	(mA) = (milliamp) \n"
  "	(mV) = (millivolt) \n"
  "} \n"
  " \n"
  "PARAMETER { \n"
  "	\n"
  "	: s-ALFA\n"
  "	Aalpha_s = -0.00493 (/ms)\n"
  "	V0alpha_s = -4.48754 (mV)\n"
  "	Kalpha_s = -6.81881 (mV)\n"
  "	Shiftalpha_s = 0.00008 (/ms)\n"
  "\n"
  "	: s-BETA\n"
  "	Abeta_s = 0.01558 (/ms)\n"
  "	V0beta_s = 43.97494 (mV)\n"
  "	Kbeta_s =  0.10818 (mV)\n"
  "	Shiftbeta_s = 0.04752 (/ms)\n"
  "\n"
  "	: f-ALFA\n"
  "	Aalpha_f = 0.31836 (/ms)\n"
  "	V0alpha_f = -80 (mV)\n"
  "	Kalpha_f = -62.52621 (mV)\n"
  "\n"
  "	: f-BETA\n"
  "	Abeta_f = 0.01014 (/ms)\n"
  "	V0beta_f = -83.3332 (mV)\n"
  "	Kbeta_f = 16.05379 (mV)\n"
  "\n"
  "	v (mV) \n"
  "	gbar= 0.0017 (mho/cm2)\n"
  "	ena  (mV) \n"
  "	celsius (degC) \n"
  "	Q10_diff	= 1.5\n"
  "	Q10_channel	= 3\n"
  "} \n"
  "\n"
  "STATE { \n"
  "	s \n"
  "	f\n"
  "} \n"
  "\n"
  "ASSIGNED { \n"
  "	ina (mA/cm2) \n"
  "	g (mho/cm2) \n"
  "\n"
  "	alpha_s (/ms)\n"
  "	beta_s (/ms)\n"
  "	s_inf\n"
  "	tau_s (ms)\n"
  "	\n"
  "	alpha_f (/ms)\n"
  "	beta_f (/ms)\n"
  "	f_inf\n"
  "	tau_f (ms)\n"
  "	tcorr (1)\n"
  "	gbar_Q10 (mho/cm2)\n"
  "	ic\n"
  "    } \n"
  " \n"
  "INITIAL { \n"
  "	gbar_Q10 = gbar*(Q10_diff^((celsius-23)/10))\n"
  "	rate(v) \n"
  "	s = s_inf\n"
  "	f = f_inf\n"
  "} \n"
  " \n"
  "BREAKPOINT { \n"
  "	SOLVE states METHOD cnexp \n"
  "	g = gbar_Q10*s*f\n"
  "	ina = g*(v - ena)\n"
  "	ic = ina\n"
  "\n"
  "	alpha_s = alp_s(v)\n"
  "	beta_s = bet_s(v) \n"
  "\n"
  "	alpha_f = alp_f(v)\n"
  "	beta_f = bet_f(v) \n"
  "} \n"
  " \n"
  "DERIVATIVE states { \n"
  "	rate(v) \n"
  "	s' = ( s_inf - s ) / tau_s \n"
  "	f' = ( f_inf - f ) / tau_f \n"
  "} \n"
  " \n"
  "PROCEDURE rate(v (mV)) { LOCAL a_s,b_s,a_f,b_f\n"
  "	TABLE s_inf,tau_s,f_inf,tau_f DEPEND celsius FROM -100 TO 30 WITH 13000	\n"
  "\n"
  "	a_s = alp_s(v)  \n"
  "	b_s = bet_s(v) \n"
  "	s_inf = a_s / ( a_s + b_s ) \n"
  "	tau_s = 1 / ( a_s + b_s ) \n"
  "\n"
  "	a_f = alp_f(v)  \n"
  "	b_f = bet_f(v) \n"
  "	f_inf = a_f / ( a_f + b_f ) \n"
  "	tau_f = 1 / ( a_f + b_f ) \n"
  "} \n"
  "\n"
  "\n"
  "\n"
  "FUNCTION alp_s(v (mV)) (/ms){\n"
  "	tcorr = Q10_channel^( ( celsius - 20 (degC) ) / 10 (degC) )\n"
  "	alp_s = tcorr*(Shiftalpha_s+Aalpha_s*((v+V0alpha_s)/ 1 (mV) )/(exp((v+V0alpha_s)/Kalpha_s)-1))\n"
  "}\n"
  "\n"
  "FUNCTION bet_s(v (mV)) (/ms){ LOCAL x1\n"
  "	tcorr = Q10_channel^((celsius-20(degC))/10(degC))	\n"
  "\n"
  "	x1=(v+V0beta_s)/Kbeta_s\n"
  "	if (x1>200) {x1=200}\n"
  "	bet_s =tcorr*(Shiftbeta_s+Abeta_s*((v+V0beta_s)/1 (mV) )/(exp(x1)-1))\n"
  "\n"
  "}\n"
  "\n"
  "FUNCTION alp_f(v (mV)) (/ms){\n"
  "	tcorr = Q10_channel^( ( celsius - 20 (degC) ) / 10 (degC) )\n"
  "	alp_f =	tcorr * Aalpha_f * exp( ( v - V0alpha_f ) / Kalpha_f)\n"
  "}\n"
  "\n"
  "FUNCTION bet_f(v (mV)) (/ms){\n"
  "	tcorr = Q10_channel^( ( celsius - 20 (degC) ) / 10 (degC) )\n"
  "	bet_f =	tcorr * Abeta_f * exp( ( v - V0beta_f ) / Kbeta_f )	\n"
  "}\n"
  "\n"
  ;
#endif
