#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _GRANULE_CALC_reg(void);
extern void _GRANULE_CA_reg(void);
extern void _GRANULE_KA_reg(void);
extern void _GRANULE_KCA_reg(void);
extern void _GRANULE_KIR_reg(void);
extern void _GRANULE_KM_reg(void);
extern void _GRANULE_KV_reg(void);
extern void _GRANULE_LKG1_reg(void);
extern void _GRANULE_LKG2_reg(void);
extern void _GRANULE_NA_reg(void);
extern void _GRANULE_NAR_reg(void);
extern void _GRANULE_PNA_reg(void);
extern void _MF_pregen_modul_reg(void);
extern void _Golgi_BK_reg(void);
extern void _Golgi_Ca_HVA_reg(void);
extern void _Golgi_CALC_ca2_reg(void);
extern void _Golgi_CALC_reg(void);
extern void _Golgi_Ca_LVA_reg(void);
extern void _Golgi_hcn1_reg(void);
extern void _Golgi_hcn2_reg(void);
extern void _Golgi_KA_reg(void);
extern void _Golgi_KM_reg(void);
extern void _Golgi_KV_reg(void);
extern void _Golgi_lkg_reg(void);
extern void _Golgi_Na_reg(void);
extern void _Golgi_NaP_reg(void);
extern void _Golgi_NaR_reg(void);
extern void _Golgi_Pregen2_reg(void);
extern void _Golgi_Pregen_reg(void);
extern void _Golgi_SK2_reg(void);
extern void _Release_site_reg(void);
extern void _vecevent_reg(void);
extern void _gapj_reg(void);
extern void _Golgi_PF_AMPA_reg(void);
extern void _Golgi_PF_NMDA_reg(void);
extern void _GRANULE_Ampa_det_Prel_reg(void);
extern void _GRANULE_Ampa_det_vi_reg(void);
extern void _GRANULE_Ampa_stoch_vi_reg(void);
extern void _GRANULE_Gaba_det_vi_reg(void);
extern void _GRANULE_Nmda_det_vi_reg(void);
extern void _GRANULE_Nmda_leak_reg(void);
extern void _GRANULE_Nmda_stoch_vi_reg(void);
extern void _MLI_KM_reg(void);
extern void _MLI_KV_reg(void);
extern void _MLI_lkg_reg(void);
extern void _MLI_Na_reg(void);
extern void _MLI_NAP_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," templates/granule//GRANULE_CALC.mod");
    fprintf(stderr," templates/granule//GRANULE_CA.mod");
    fprintf(stderr," templates/granule//GRANULE_KA.mod");
    fprintf(stderr," templates/granule//GRANULE_KCA.mod");
    fprintf(stderr," templates/granule//GRANULE_KIR.mod");
    fprintf(stderr," templates/granule//GRANULE_KM.mod");
    fprintf(stderr," templates/granule//GRANULE_KV.mod");
    fprintf(stderr," templates/granule//GRANULE_LKG1.mod");
    fprintf(stderr," templates/granule//GRANULE_LKG2.mod");
    fprintf(stderr," templates/granule//GRANULE_NA.mod");
    fprintf(stderr," templates/granule//GRANULE_NAR.mod");
    fprintf(stderr," templates/granule//GRANULE_PNA.mod");
    fprintf(stderr," templates/granule//MF_pregen_modul.mod");
    fprintf(stderr," templates/golgi//Golgi_BK.mod");
    fprintf(stderr," templates/golgi//Golgi_Ca_HVA.mod");
    fprintf(stderr," templates/golgi//Golgi_CALC_ca2.mod");
    fprintf(stderr," templates/golgi//Golgi_CALC.mod");
    fprintf(stderr," templates/golgi//Golgi_Ca_LVA.mod");
    fprintf(stderr," templates/golgi//Golgi_hcn1.mod");
    fprintf(stderr," templates/golgi//Golgi_hcn2.mod");
    fprintf(stderr," templates/golgi//Golgi_KA.mod");
    fprintf(stderr," templates/golgi//Golgi_KM.mod");
    fprintf(stderr," templates/golgi//Golgi_KV.mod");
    fprintf(stderr," templates/golgi//Golgi_lkg.mod");
    fprintf(stderr," templates/golgi//Golgi_Na.mod");
    fprintf(stderr," templates/golgi//Golgi_NaP.mod");
    fprintf(stderr," templates/golgi//Golgi_NaR.mod");
    fprintf(stderr," templates/golgi//Golgi_Pregen2.mod");
    fprintf(stderr," templates/golgi//Golgi_Pregen.mod");
    fprintf(stderr," templates/golgi//Golgi_SK2.mod");
    fprintf(stderr," templates/mossy//Release_site.mod");
    fprintf(stderr," templates/mossy//vecevent.mod");
    fprintf(stderr," templates/gapj//gapj.mod");
    fprintf(stderr," templates/synapse//Golgi_PF_AMPA.mod");
    fprintf(stderr," templates/synapse//Golgi_PF_NMDA.mod");
    fprintf(stderr," templates/synapse//GRANULE_Ampa_det_Prel.mod");
    fprintf(stderr," templates/synapse//GRANULE_Ampa_det_vi.mod");
    fprintf(stderr," templates/synapse//GRANULE_Ampa_stoch_vi.mod");
    fprintf(stderr," templates/synapse//GRANULE_Gaba_det_vi.mod");
    fprintf(stderr," templates/synapse//GRANULE_Nmda_det_vi.mod");
    fprintf(stderr," templates/synapse//GRANULE_Nmda_leak.mod");
    fprintf(stderr," templates/synapse//GRANULE_Nmda_stoch_vi.mod");
    fprintf(stderr," templates/mli/MLI_KM.mod");
    fprintf(stderr," templates/mli/MLI_KV.mod");
    fprintf(stderr," templates/mli/MLI_lkg.mod");
    fprintf(stderr," templates/mli/MLI_Na.mod");
    fprintf(stderr," templates/mli/MLI_NAP.mod");
    fprintf(stderr, "\n");
  }
  _GRANULE_CALC_reg();
  _GRANULE_CA_reg();
  _GRANULE_KA_reg();
  _GRANULE_KCA_reg();
  _GRANULE_KIR_reg();
  _GRANULE_KM_reg();
  _GRANULE_KV_reg();
  _GRANULE_LKG1_reg();
  _GRANULE_LKG2_reg();
  _GRANULE_NA_reg();
  _GRANULE_NAR_reg();
  _GRANULE_PNA_reg();
  _MF_pregen_modul_reg();
  _Golgi_BK_reg();
  _Golgi_Ca_HVA_reg();
  _Golgi_CALC_ca2_reg();
  _Golgi_CALC_reg();
  _Golgi_Ca_LVA_reg();
  _Golgi_hcn1_reg();
  _Golgi_hcn2_reg();
  _Golgi_KA_reg();
  _Golgi_KM_reg();
  _Golgi_KV_reg();
  _Golgi_lkg_reg();
  _Golgi_Na_reg();
  _Golgi_NaP_reg();
  _Golgi_NaR_reg();
  _Golgi_Pregen2_reg();
  _Golgi_Pregen_reg();
  _Golgi_SK2_reg();
  _Release_site_reg();
  _vecevent_reg();
  _gapj_reg();
  _Golgi_PF_AMPA_reg();
  _Golgi_PF_NMDA_reg();
  _GRANULE_Ampa_det_Prel_reg();
  _GRANULE_Ampa_det_vi_reg();
  _GRANULE_Ampa_stoch_vi_reg();
  _GRANULE_Gaba_det_vi_reg();
  _GRANULE_Nmda_det_vi_reg();
  _GRANULE_Nmda_leak_reg();
  _GRANULE_Nmda_stoch_vi_reg();
  _MLI_KM_reg();
  _MLI_KV_reg();
  _MLI_lkg_reg();
  _MLI_Na_reg();
  _MLI_NAP_reg();
}
