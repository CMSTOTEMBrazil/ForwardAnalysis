//-------------------------------------------------------------------------------------------------------->>
// UNIVERSIDADE DO ESTADO DO RIO DE JANEIRO - CMS/Brasil
//-------------------------------------------------------------------------------------------------------->>
//
// Twiki: https://twiki.cern.ch/twiki/bin/view/CMS/FwdPhysicsExclusiveDijetsAnalysis#Macro_Analysis
//

//#if !defined(__CINT__) || defined(__MAKECINT__)

#include <TROOT.h>
#include <TChain.h>
#include <TString.h>
#include <TH1.h>
#include <TH2.h>
#include <TTree.h>
#include <TMath.h>

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>

#include "statusbar.h"
#include "ExclusiveDijet.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/EventInfoEvent.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/ExclusiveDijetsEvent.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/DiffractiveEvent.h"
#include "PhysicsTools/Utilities/interface/LumiReWeighting.h"

#define isfinite(x) !std::isinf(x)

using namespace diffractiveAnalysis;
using namespace exclusiveDijetsAnalysis;
using namespace eventInfo;
using namespace reweight;

void ExclusiveDijet::LoadFile(std::string fileinput, std::string processinput){

  inf = NULL;
  tr = NULL;
  inf = TFile::Open(fileinput.c_str(),"read");
  std::string fdirectory = processinput + "/ProcessedTree";
  tr = (TTree*)inf->Get(fdirectory.c_str());
  eventdiff = new DiffractiveEvent();
  eventexcl = new ExclusiveDijetsEvent();
  eventinfo = new EventInfoEvent();
  diff = tr->GetBranch("DiffractiveAnalysis");
  excl = tr->GetBranch("ExclusiveDijetsAnalysis");
  info = tr->GetBranch("EventInfo");
  diff->SetAddress(&eventdiff);
  excl->SetAddress(&eventexcl);
  info->SetAddress(&eventinfo);

}

void ExclusiveDijet::CreateHistos(std::string type, std::string switchCastorHisto){

  double xi_bin[18]={0.0003,0.002,0.0045,0.01,0.02,0.04,0.06,0.08,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1};

  std::string step0 = "without_cuts"; // Without cuts
  std::string step1 = "with_trigger"; // Trigger
  std::string step2 = "step1"; // Trigger + Presel
  std::string step3 = "step2"; // Trigger + Presel + Vertex
  std::string step4 = "step3"; // Trigger + Presel + Vertex + Dijet
  std::string step5 = "step4_4"; // Trigger + Presel + Vertex + Dijet + Etamax/Etamin 4
  std::string step6 = "step4_3"; // Trigger + Presel + Vertex + Dijet + Etamax/Etamin 3
  std::string step7 = "step4_2"; // Trigger + Presel + Vertex + Dijet + Etamax/Etamin 2
  std::string step8 = "step4_1"; // Trigger + Presel + Vertex + Dijet + Etamax/Etamin 1
  std::string step9 = "step4_4_CASTOR"; // Trigger + Presel + Vertex + Dijet + CASTORGAP + Etamax/Etamin 4
  std::string step10 = "step4_3_CASTOR"; // Trigger + Presel + Vertex + Dijet + CASTORGAP + Etamax/Etamin 3
  std::string step11 = "step4_2_CASTOR"; // Trigger + Presel + Vertex + Dijet + CASTORGAP + Etamax/Etamin 2
  std::string step12 = "step4_1_CASTOR"; // Trigger + Presel + Vertex + Dijet + CASTORGAP + Etamax/Etamin 1

  Folders.push_back(step0);
  Folders.push_back(step1);
  Folders.push_back(step2);
  Folders.push_back(step3);
  Folders.push_back(step4);
  Folders.push_back(step5);
  Folders.push_back(step6);
  Folders.push_back(step7);
  Folders.push_back(step8);
  if (switchCastorHisto == "castor_correction" || switchCastorHisto == "castor_no_correction") {
    Folders.push_back(step9);
    Folders.push_back(step10);
    Folders.push_back(step11);
    Folders.push_back(step12);
  }

  int nloop=-999;

  if (type=="multiple_pileup") nloop=21;
  else if (type=="no_multiple_pileup") nloop=1;

  char tag[300];

  for (std::vector<std::string>::size_type j=0; j<Folders.size(); j++){

    m_hVector_lumi.push_back( std::vector<TH1D*>() );
    m_hVector_rjj.push_back( std::vector<TH1D*>() );
    m_hVector_detagen.push_back( std::vector<TH1D*>() );
    m_hVector_mxGen.push_back( std::vector<TH1D*>() );
    m_hVector_multhf.push_back( std::vector<TH2F*>() );
    m_hVector_etcalos.push_back( std::vector<TH2F*>() );
    m_hVector_tracks.push_back( std::vector<TH1D*>() );
    m_hVector_pfetamax.push_back( std::vector<TH1D*>() );
    m_hVector_pfetamin.push_back( std::vector<TH1D*>() );
    m_hVector_asumE.push_back( std::vector<TH1D*>() );
    m_hVector_deltaetajets.push_back( std::vector<TH1D*>() );
    m_hVector_deltaphijets.push_back( std::vector<TH1D*>() );
    m_hVector_deltaptjets.push_back( std::vector<TH1D*>() );
    m_hVector_dijetmass.push_back( std::vector<TH1D*>() );
    m_hVector_ptjet1.push_back( std::vector<TH1D*>() );
    m_hVector_ptjet2.push_back( std::vector<TH1D*>() );
    m_hVector_etajet1.push_back( std::vector<TH1D*>() );
    m_hVector_etajet2.push_back( std::vector<TH1D*>() );
    m_hVector_phijet1.push_back( std::vector<TH1D*>() );
    m_hVector_phijet2.push_back( std::vector<TH1D*>() );
    m_hVector_sumEHFplus.push_back( std::vector<TH1D*>() );
    m_hVector_sumEHFminus.push_back( std::vector<TH1D*>() );
    m_hVector_sumEHEplus.push_back( std::vector<TH1D*>() );
    m_hVector_sumEHEminus.push_back( std::vector<TH1D*>() );
    m_hVector_sumEHFpfplus.push_back( std::vector<TH1D*>() );
    m_hVector_sumEHFpfminus.push_back( std::vector<TH1D*>() );
    m_hVector_sumECastor.push_back( std::vector<TH1D*>() );
    m_hVector_deltaEtaPF.push_back( std::vector<TH1D*>() );
    m_hVector_absdeltaEtaPF.push_back( std::vector<TH1D*>() );
    m_hVector_vertex.push_back( std::vector<TH1D*>() );
    m_hVector_sumEHFplusVsetaMax.push_back( std::vector<TH2D*>() );
    m_hVector_sumEHFminusVsetaMin.push_back( std::vector<TH2D*>() );
    m_hVector_sumEHFpfplusVsetaMax.push_back( std::vector<TH2D*>() );
    m_hVector_sumEHFpfminusVsetaMin.push_back( std::vector<TH2D*>() );
    m_hVector_sumEHFplusVsiEta.push_back( std::vector<TH1D*>() );
    m_hVector_sumEHFminusVsiEta.push_back( std::vector<TH1D*>() );
    m_hVector_uncJet1.push_back( std::vector<TH1D*>() );
    m_hVector_uncJet2.push_back( std::vector<TH1D*>() );
    m_hVector_sumECastorHFMinus.push_back( std::vector<TH1D*>() );
    m_hVector_TracksNonCone.push_back( std::vector<TH1D*>() );
    m_hVector_TracksTransverse.push_back( std::vector<TH1D*>() );
    m_hVector_TracksOutsideJets.push_back( std::vector<TH1D*>() );
    m_hVector_XiPlusPF.push_back( std::vector<TH1D*>() );
    m_hVector_XiMinusPF.push_back( std::vector<TH1D*>() );
    m_hVector_XiPF.push_back( std::vector<TH1D*>() );
    m_hVector_ptjets.push_back( std::vector<TH1D*>() );
    m_hVector_etajets.push_back( std::vector<TH1D*>() );
    m_hVector_phijets.push_back( std::vector<TH1D*>() );

    for (int k=0;k<nloop;k++){

      if (type=="multiple_pileup"){
	sprintf(tag,"multiple_pileup_%i",k);
      }
      else {
	sprintf(tag,"no_multiple_pileup");
      }

      char name1[300];
      sprintf(name1,"RJJ_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_rjj = new TH1D(name1,"R_{jj} Distribution; R_{jj}; N events",20,0,1.2);
      m_hVector_rjj[j].push_back(histo_rjj);

      char name2[300];
      sprintf(name2,"DeltaEtaGen_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_detagen = new TH1D(name2,"#Delta#eta_{Gen} Distribution; #Delta#eta_{Gen}; N events",20,0.0,5.2);
      m_hVector_detagen[j].push_back(histo_detagen);

      char name3[300];
      sprintf(name3,"MxGenRange_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_MxGenRange = new TH1D(name3,"Mass_{X} Gen Distribution; M_{x} Gen [GeV]; N events",50,0,5000);
      m_hVector_mxGen[j].push_back(histo_MxGenRange);

      char name4[300];
      sprintf(name4,"mHF_%s_%s",tag,Folders.at(j).c_str());
      TH2F *histo_MultHF = new TH2F(name4,"HF^{+} and HF^{-} Multiplicity; n HF^{+}; n HF^{-}; N events", 10, 0., 10., 10, 0., 10. );
      m_hVector_multhf[j].push_back(histo_MultHF);

      char name5[300];
      sprintf(name5,"ETCalos_%s_%s",tag,Folders.at(j).c_str());
      TH2F *histo_ET_Calos = new TH2F(name5,"HF^{+} and Castor; #sum Energy HF^{+}; #sum Energy Castor [GeV]; N events", 400, 0., 2000., 500, 0., 5000. );
      m_hVector_etcalos[j].push_back(histo_ET_Calos);

      char name6[300];
      sprintf(name6,"Tracks_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_Tracks = new TH1D(name6,"Tracks Multiplicity; n Tracks; N events",50,0,150);
      m_hVector_tracks[j].push_back(histo_Tracks);

      char name7[300];
      sprintf(name7,"pfetamax_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_PFEtamax = new TH1D(name7,"Particle Flow #eta_{max} Distribution; #eta; N events",20,0,5.5);
      m_hVector_pfetamax[j].push_back(histo_PFEtamax);

      char name8[300];
      sprintf(name8,"pfetamin_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_PFEtamin = new TH1D(name8,"Particle Flow #eta_{min} Distribution; #eta; N events",20,-5.5,0);
      m_hVector_pfetamin[j].push_back(histo_PFEtamin);

      char name9[300];
      sprintf(name9,"aEnergy_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_aSumE = new TH1D(name9,"Forward Backward Asymmetry Distribution ; (#sum HF^{+} - #sum HF^{-})x(#sum HF^{+} + #sum HF^{-})^{-1}; N events",50,-1,1);
      m_hVector_asumE[j].push_back(histo_aSumE);

      char name10[300];
      sprintf(name10,"deltaEtaJets_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_deltaetajets = new TH1D(name10,"#Delta#eta_{jj} Distribution; #Delta#eta_{jj}; N events",20,0.0,5.2);
      m_hVector_deltaetajets[j].push_back(histo_deltaetajets);

      char name11[300];
      sprintf(name11,"deltaPhiJets_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_deltaphijets = new TH1D(name11,"#Delta#phi_{jj} Distribution; #Delta#phi_{jj}; N events",20,0.0,3.2);
      m_hVector_deltaphijets[j].push_back(histo_deltaphijets);

      char name12[300];
      sprintf(name12,"deltaPtJets_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_deltaptjets = new TH1D(name12,"#Delta P_{T} Distribution; #Delta P_{T} [GeV.c^{-1}]; N events",40,0,400);
      m_hVector_deltaptjets[j].push_back(histo_deltaptjets);

      char name13[300];
      sprintf(name13,"DijetMass_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_dijetmass = new TH1D(name13,"Dijet Invariant Mass Distribution; M_{jj} [GeV]; N events",80,0,800);
      m_hVector_dijetmass[j].push_back(histo_dijetmass);

      char name14[300];
      sprintf(name14,"pTJet1_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_ptjet1 = new TH1D(name14,"Leading Jet - P_{T} Distribution; P_{T} [GeV.c^{-1}]; N events",100,0,2000);
      m_hVector_ptjet1[j].push_back(histo_ptjet1);

      char name15[300];
      sprintf(name15,"pTJet2_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_ptjet2 = new TH1D(name15,"Second Jet - P_{T} Distribution; P_{T} [GeV.c^{-1}]; N events",100,0,2000);
      m_hVector_ptjet2[j].push_back(histo_ptjet2);

      char name16[300];
      sprintf(name16,"etaJet1_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_etajet1 = new TH1D(name16,"Leading Jet - #eta Distribution; #eta; N events",50,-5.2,5.2);
      m_hVector_etajet1[j].push_back(histo_etajet1);

      char name17[300];
      sprintf(name17,"etaJet2_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_etajet2 = new TH1D(name17,"Second Jet - #eta Distribution; #eta; N events",50,-5.2,5.2);
      m_hVector_etajet2[j].push_back(histo_etajet2);

      char name18[300];
      sprintf(name18,"phiJet1_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_phijet1 = new TH1D(name18,"Leading Jet - #phi Distribution; #phi [rad]; N events",50,-3.3,3.3);
      m_hVector_phijet1[j].push_back(histo_phijet1);

      char name19[300];
      sprintf(name19,"phiJet2_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_phijet2 = new TH1D(name19,"Second Jet - #phi Distribution; #phi [rad]; N events",50,-3.3,3.3);
      m_hVector_phijet2[j].push_back(histo_phijet2);

      char name20[300];
      sprintf(name20,"sumEHFplus_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_sumEHFplus = new TH1D(name20,"HF^{+} - Sum of Energy; #sum E_{HF^{+}} [GeV]; N events",100,0,2000);
      m_hVector_sumEHFplus[j].push_back(histo_sumEHFplus);

      char name21[300];
      sprintf(name21,"sumEHFminus_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_sumEHFminus = new TH1D(name21,"HF^{-} - Sum of Energy; #sum E_{HF^{-}} [GeV]; N events",100,0,2000);
      m_hVector_sumEHFminus[j].push_back(histo_sumEHFminus);

      char name22[300];
      sprintf(name22,"sumEHEplus_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_sumEHEplus = new TH1D(name22,"HE^{+} - Sum of Energy; #sum E_{HE^{+}} [GeV]; N events",100,0,2000);
      m_hVector_sumEHEplus[j].push_back(histo_sumEHEplus);

      char name23[300];
      sprintf(name23,"sumEHEminus_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_sumEHEminus = new TH1D(name23,"HE^{-} - Sum of Energy; #sum E_{HE^{-}} [GeV]; N events",100,0,2000);
      m_hVector_sumEHEminus[j].push_back(histo_sumEHEminus);

      char name24[300];
      sprintf(name24,"sumEHFpfplus_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_sumEHFpfplus = new TH1D(name24,"HF^{+} - Sum of PF Energy; #sum E_{HF^{+}_{PF}} [GeV]; N events",100,0,2000);
      m_hVector_sumEHFpfplus[j].push_back(histo_sumEHFpfplus);

      char name25[300];
      sprintf(name25,"sumEHFpfminus_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_sumEHFpfminus = new TH1D(name25,"HF^{-} - Sum of PF Energy; #sum E_{HF^{-}_{PF}} [GeV]; N events",100,0,2000);
      m_hVector_sumEHFpfminus[j].push_back(histo_sumEHFpfminus);

      char name26[300];
      sprintf(name26,"deltaEtamaxminPF_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_deltaEtaPF = new TH1D(name26,"#Delta#eta_{PF} Distribution; #eta_{max}-#eta_{min}; N events",20,0,10);
      m_hVector_deltaEtaPF[j].push_back(histo_deltaEtaPF);

      char name27[300];
      sprintf(name27,"absdeltaEtamaxminPF_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_absdeltaEtaPF = new TH1D(name27,"|#Delta#eta_{PF}| Distribution; |#eta_{max}-#eta_{min}|; N events",20,0,10);
      m_hVector_absdeltaEtaPF[j].push_back(histo_absdeltaEtaPF);

      char name28[300];
      sprintf(name28,"vertex_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_vertex = new TH1D(name28,"Number of Vertex; # Vertex; N events",25,0,25);
      m_hVector_vertex[j].push_back(histo_vertex);

      char name29[300];
      sprintf(name29,"lumi_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_lumi = new TH1D(name29,"Luminosity per Bunch; L_{Bunch} [#mub^{-1}s^{-1}]; N events",25,0,2);
      m_hVector_lumi[j].push_back(histo_lumi);

      char name30[300];
      sprintf(name30,"sumEHFpfplusVspfetamax_%s_%s",tag,Folders.at(j).c_str());
      TH2D *histo_sumEHFpfplusVsPFEtamax = new TH2D(name30,"#sum E_{HF^{+}} Vs #eta_{max} Distribution; #eta_{Max};#sum E_{HF^{+}} [GeV]; N events",20,0,5.5,100, 0., 2000.);
      m_hVector_sumEHFpfplusVsetaMax[j].push_back(histo_sumEHFpfplusVsPFEtamax);

      char name31[300];
      sprintf(name31,"sumEHFpfminusVspfetamin_%s_%s",tag,Folders.at(j).c_str());
      TH2D *histo_sumEHFpfminusVsPFEtamin = new TH2D(name31,"#sum E_{HF^{-}} Vs #eta_{min} Distribution; #eta_{Min};#sum E_{HF^{-}} [GeV]; N events",20,-5.5,0,100, 0., 2000);
      m_hVector_sumEHFpfminusVsetaMin[j].push_back(histo_sumEHFpfminusVsPFEtamin);

      char name32[300];
      sprintf(name32,"sumEHFplusVspfetamax_%s_%s",tag,Folders.at(j).c_str());
      TH2D *histo_sumEHFplusVsPFEtamax = new TH2D(name32,"#sum E_{HF^{+}} Vs #eta_{max} Distribution; #eta_{Max};#sum E_{HF^{+}} [GeV]; N events",20,0,5.5,100, 0., 2000.);
      m_hVector_sumEHFplusVsetaMax[j].push_back(histo_sumEHFplusVsPFEtamax);

      char name33[300];
      sprintf(name33,"sumEHFminusVspfetamin_%s_%s",tag,Folders.at(j).c_str());
      TH2D *histo_sumEHFminusVsPFEtamin = new TH2D(name33,"#sum E_{HF^{-}} Vs #eta_{min} Distribution; #eta_{Min};#sum E_{HF^{-}} [GeV]; N events",20,-5.5,0,100, 0., 2000);
      m_hVector_sumEHFminusVsetaMin[j].push_back(histo_sumEHFminusVsPFEtamin);

      char name34[300];
      sprintf(name34,"sumECastor_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_sumECastor = new TH1D(name34,"Castor - Total Energy; #sum E_{Castor} [GeV]; N events",100,0,2000);
      m_hVector_sumECastor[j].push_back(histo_sumECastor);

      char name_ieta[300];
      for(int ieta = 29; ieta <= 41; ++ieta){
	sprintf(name_ieta,"sumEHFplus_iEta_%d_%s_%s",ieta,tag,Folders.at(j).c_str());
	TH1D *histo_sumEHFplus_ieta = new TH1D(name_ieta,"HF^{+} - Sum of Energy; #sum E_{HF^{+}} [GeV]; N events",500,0,500);
	m_hVector_sumEHFplusVsiEta[j].push_back(histo_sumEHFplus_ieta);

	sprintf(name_ieta,"sumEHFminus_iEta_%d_%s_%s",ieta,tag,Folders.at(j).c_str());
	TH1D *histo_sumEHFminus_ieta = new TH1D(name_ieta,"HF^{-} - Sum of Energy; #sum E_{HF^{-}} [GeV]; N events",500,0,500);
	m_hVector_sumEHFminusVsiEta[j].push_back(histo_sumEHFminus_ieta);
      }

      char name35[300];
      sprintf(name35,"UncJet1_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_uncJet1 = new TH1D(name35,"Uncertainty Leading Jet; Uncertainty Jet pT; N events",20,0,1);
      m_hVector_uncJet1[j].push_back(histo_uncJet1);

      char name36[300];
      sprintf(name36,"UncJet2_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_uncJet2 = new TH1D(name36,"Uncertainty Second Jet; Uncertainty Jet pT; N events",20,0,1);
      m_hVector_uncJet2[j].push_back(histo_uncJet2);

      char name37[300];
      sprintf(name37,"sumECastorHFMinus_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_sumECastorHFMinus = new TH1D(name37,"HF Minus and Castor - Total Energy; #sum E_{Castor} + #sum E_{HF^{-}} [GeV]; N events",4000,0,2000);
      m_hVector_sumECastorHFMinus[j].push_back(histo_sumECastorHFMinus);

      char name38[300];
      sprintf(name38,"TracksNonCone_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_TracksNonCone = new TH1D(name38,"Tracks Non Cone; N events",300,0,300);
      m_hVector_TracksNonCone[j].push_back(histo_TracksNonCone);

      char name39[300];
      sprintf(name39,"TracksTransverse_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_TracksTransverse = new TH1D(name39,"Tracks Transverse; N events",300,0,300);
      m_hVector_TracksTransverse[j].push_back(histo_TracksTransverse);

      char name40[300];
      sprintf(name40,"TracksOutsideJets_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_TracksOutsideJets = new TH1D(name40,"Tracks Outside Jet Cone; N events",300,0,300);
      m_hVector_TracksOutsideJets[j].push_back(histo_TracksOutsideJets);

      char name41[300];
      sprintf(name41,"xiPlusPF_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_XiPlusPF = new TH1D(name41,"#xi_{plus} Particle Flow; #xi_{plus}; N Event",17,xi_bin);
      m_hVector_XiPlusPF[j].push_back(histo_XiPlusPF);

      char name42[300];
      sprintf(name42,"xiMinusPF_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_XiMinusPF = new TH1D(name42,"#xi_{minus} Particle Flow; #xi_{minus}; N Event",17,xi_bin);
      m_hVector_XiMinusPF[j].push_back(histo_XiMinusPF);

      char name43[300];
      sprintf(name43,"xiPF_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_XiPF = new TH1D(name43,"#xi Particle Flow; #xi; N Event",17,xi_bin);
      m_hVector_XiPF[j].push_back(histo_XiPF);

      char name44[300];
      sprintf(name44,"pTJets_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_ptjets = new TH1D(name44,"Jets P_{T} Distribution; P_{T} [GeV.c^{-1}]; N events",100,0,2000);
      m_hVector_ptjets[j].push_back(histo_ptjets);

      char name45[300];
      sprintf(name45,"etaJets_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_etajets = new TH1D(name45,"Jets #eta Distribution; #eta; N events",50,-5.2,5.2);
      m_hVector_etajets[j].push_back(histo_etajets);

      char name46[300];
      sprintf(name46,"phiJets_%s_%s",tag,Folders.at(j).c_str());
      TH1D *histo_phijets = new TH1D(name46,"Jets #phi Distribution; #phi [rad]; N events",50,-3.3,3.3);
      m_hVector_phijets[j].push_back(histo_phijets);

    }
  }
}

void ExclusiveDijet::FillHistos(int index, int pileup, double totalweight){

  m_hVector_rjj[index].at(pileup)->Fill(eventexcl->GetRjjFromJets(),totalweight);
  m_hVector_detagen[index].at(pileup)->Fill(eventexcl->GetDeltaEtaGen(),totalweight);
  m_hVector_mxGen[index].at(pileup)->Fill(eventexcl->GetMxGenRange(),totalweight);
  m_hVector_multhf[index].at(pileup)->Fill(eventdiff->GetMultiplicityHFPlus(),eventdiff->GetMultiplicityHFMinus(),totalweight);
  m_hVector_etcalos[index].at(pileup)->Fill(eventdiff->GetSumEnergyHFPlus(),eventdiff->GetSumETotCastor(),totalweight);
  m_hVector_tracks[index].at(pileup)->Fill(eventdiff->GetMultiplicityTracks(),totalweight);
  m_hVector_pfetamax[index].at(pileup)->Fill(eventdiff->GetEtaMaxFromPFCands(),totalweight);
  m_hVector_pfetamin[index].at(pileup)->Fill(etamin_,totalweight);
  m_hVector_asumE[index].at(pileup)->Fill(aSumE,totalweight);
  m_hVector_deltaetajets[index].at(pileup)->Fill(eventexcl->GetJetsDeltaEta(),totalweight);
  m_hVector_deltaphijets[index].at(pileup)->Fill(deltaphi,totalweight);
  m_hVector_deltaptjets[index].at(pileup)->Fill(eventexcl->GetJetsDeltaPt(),totalweight);
  m_hVector_dijetmass[index].at(pileup)->Fill(eventexcl->GetMassDijets(),totalweight);
  m_hVector_ptjet1[index].at(pileup)->Fill(ptJet1,totalweight);
  m_hVector_ptjet2[index].at(pileup)->Fill(ptJet2,totalweight);
  m_hVector_etajet1[index].at(pileup)->Fill(eventexcl->GetLeadingJetEta(),totalweight);
  m_hVector_etajet2[index].at(pileup)->Fill(eventexcl->GetSecondJetEta(),totalweight);
  m_hVector_phijet1[index].at(pileup)->Fill(eventexcl->GetLeadingJetPhi(),totalweight);
  m_hVector_phijet2[index].at(pileup)->Fill(eventexcl->GetSecondJetPhi(),totalweight);
  m_hVector_sumEHFplus[index].at(pileup)->Fill(eventdiff->GetSumEnergyHFPlus(),totalweight);
  m_hVector_sumEHFminus[index].at(pileup)->Fill(eventdiff->GetSumEnergyHFMinus(),totalweight);
  m_hVector_sumEHEplus[index].at(pileup)->Fill(eventdiff->GetSumEnergyHEPlus(),totalweight);
  m_hVector_sumEHEminus[index].at(pileup)->Fill(eventdiff->GetSumEnergyHEMinus(),totalweight);
  m_hVector_sumEHFpfplus[index].at(pileup)->Fill(eventexcl->GetSumEHFPFlowPlus(),totalweight);
  m_hVector_sumEHFpfminus[index].at(pileup)->Fill(eventexcl->GetSumEHFPFlowMinus(),totalweight);
  m_hVector_deltaEtaPF[index].at(pileup)->Fill(deltaetapf,totalweight);
  m_hVector_absdeltaEtaPF[index].at(pileup)->Fill(absdeltaetapf,totalweight);
  m_hVector_vertex[index].at(pileup)->Fill(eventexcl->GetNVertex(),totalweight);
  m_hVector_lumi[index].at(pileup)->Fill(eventinfo->GetInstLumiBunch());
  m_hVector_sumEHFpfplusVsetaMax[index].at(pileup)->Fill(eventdiff->GetEtaMaxFromPFCands(),eventexcl->GetSumEHFPFlowPlus(),totalweight);
  m_hVector_sumEHFpfminusVsetaMin[index].at(pileup)->Fill(etamin_,eventexcl->GetSumEHFPFlowMinus(),totalweight);
  m_hVector_sumEHFplusVsetaMax[index].at(pileup)->Fill(eventdiff->GetEtaMaxFromPFCands(),eventdiff->GetSumEnergyHFPlus(),totalweight);
  m_hVector_sumEHFminusVsetaMin[index].at(pileup)->Fill(etamin_,eventdiff->GetSumEnergyHFMinus(),totalweight);
  m_hVector_sumECastor[index].at(pileup)->Fill(sumCastorEnergy,totalweight);
  m_hVector_sumECastorHFMinus[index].at(pileup)->Fill(sumCastorAndHFMinusEnergy,totalweight);
  m_hVector_uncJet1[index].at(pileup)->Fill(eventexcl->GetUnc1());
  m_hVector_uncJet2[index].at(pileup)->Fill(eventexcl->GetUnc2());
  m_hVector_TracksNonCone[index].at(pileup)->Fill(eventexcl->GetTracksNonCone());
  m_hVector_TracksTransverse[index].at(pileup)->Fill(eventexcl->GetTracksTransverse());
  m_hVector_TracksOutsideJets[index].at(pileup)->Fill(eventexcl->GetTracksOutsideJets());
  m_hVector_XiPlusPF[index].at(pileup)->Fill(eventdiff->GetXiPlusFromPFCands(),totalweight);
  m_hVector_XiMinusPF[index].at(pileup)->Fill(eventdiff->GetXiMinusFromPFCands(),totalweight);
  m_hVector_XiPF[index].at(pileup)->Fill(eventdiff->GetXiPlusFromPFCands(),totalweight);
  m_hVector_XiPF[index].at(pileup)->Fill(eventdiff->GetXiMinusFromPFCands(),totalweight);
  m_hVector_ptjets[index].at(pileup)->Fill(ptJet1,totalweight);
  m_hVector_ptjets[index].at(pileup)->Fill(ptJet2,totalweight);
  m_hVector_etajets[index].at(pileup)->Fill(eventexcl->GetLeadingJetEta(),totalweight);
  m_hVector_etajets[index].at(pileup)->Fill(eventexcl->GetSecondJetEta(),totalweight);
  m_hVector_phijets[index].at(pileup)->Fill(eventexcl->GetLeadingJetPhi(),totalweight);
  m_hVector_phijets[index].at(pileup)->Fill(eventexcl->GetSecondJetPhi(),totalweight);
}

void ExclusiveDijet::SaveHistos(std::string type){

  int ipileup;

  if (type=="multiple_pileup") ipileup=21;
  else ipileup=1;

  for (int i = 0; i < ipileup; i++){
    for (std::vector<std::string>::size_type j=0; j<Folders.size(); j++){
      m_hVector_rjj[j].at(i)->Write();
      m_hVector_detagen[j].at(i)->Write();
      m_hVector_mxGen[j].at(i)->Write();
      m_hVector_multhf[j].at(i)->Write();
      m_hVector_etcalos[j].at(i)->Write();
      m_hVector_tracks[j].at(i)->Write();
      m_hVector_pfetamax[j].at(i)->Write();
      m_hVector_pfetamin[j].at(i)->Write();
      m_hVector_asumE[j].at(i)->Write();
      m_hVector_deltaetajets[j].at(i)->Write();
      m_hVector_deltaphijets[j].at(i)->Write();
      m_hVector_deltaptjets[j].at(i)->Write();
      m_hVector_dijetmass[j].at(i)->Write();
      m_hVector_ptjet1[j].at(i)->Write();
      m_hVector_ptjet2[j].at(i)->Write();
      m_hVector_etajet1[j].at(i)->Write();
      m_hVector_etajet2[j].at(i)->Write();
      m_hVector_phijet1[j].at(i)->Write();
      m_hVector_phijet2[j].at(i)->Write();
      m_hVector_sumEHFplus[j].at(i)->Write();
      m_hVector_sumEHFminus[j].at(i)->Write();
      m_hVector_sumEHEplus[j].at(i)->Write();
      m_hVector_sumEHEminus[j].at(i)->Write();
      m_hVector_sumEHFpfplus[j].at(i)->Write();
      m_hVector_sumEHFpfminus[j].at(i)->Write();
      m_hVector_deltaEtaPF[j].at(i)->Write();
      m_hVector_absdeltaEtaPF[j].at(i)->Write();
      m_hVector_vertex[j].at(i)->Write();
      m_hVector_lumi[j].at(i)->Write();
      m_hVector_sumEHFpfplusVsetaMax[j].at(i)->Write();
      m_hVector_sumEHFpfminusVsetaMin[j].at(i)->Write();
      m_hVector_sumEHFplusVsetaMax[j].at(i)->Write();
      m_hVector_sumEHFminusVsetaMin[j].at(i)->Write();
      m_hVector_sumECastor[j].at(i)->Write();
      m_hVector_sumECastorHFMinus[j].at(i)->Write();
      m_hVector_uncJet1[j].at(i)->Write();
      m_hVector_uncJet2[j].at(i)->Write();
      m_hVector_TracksNonCone[j].at(i)->Write();
      m_hVector_TracksTransverse[j].at(i)->Write();
      m_hVector_TracksOutsideJets[j].at(i)->Write();
      m_hVector_XiMinusPF[j].at(i)->Write();
      m_hVector_XiPlusPF[j].at(i)->Write();
      m_hVector_XiPF[j].at(i)->Write();
      m_hVector_ptjets[j].at(i)->Write();
      m_hVector_etajets[j].at(i)->Write();
      m_hVector_phijets[j].at(i)->Write();

    }
  }

}

double* ExclusiveDijet::cutCorrection(){

  bool debug = false;

  if (eventinfo->GetInstLumiBunch() < -999){
    std::cout << "\n--------------------------------------------------------------" << std::endl;
    std::cout << " Only apply cut correction in data, not in MC." << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    exit(EXIT_FAILURE);
  }

  double cutCorrection[10];
  double* cutfactor;

  cutfactor = cutCorrection;

  TH1F* h_eff_excl = (TH1F*)effcut->Get("RatioPreSel");
  TH1F* h_eff_vertex = (TH1F*)effcut->Get("RatioVertex");
  TH1F* h_eff_step_4_4 = (TH1F*)effcut->Get("RatioStep4_4");
  TH1F* h_eff_step_4_3 = (TH1F*)effcut->Get("RatioStep4_3");
  TH1F* h_eff_step_4_2 = (TH1F*)effcut->Get("RatioStep4_2");
  TH1F* h_eff_step_4_1 = (TH1F*)effcut->Get("RatioStep4_1");
  TH1F* h_eff_step_4_4_castor = (TH1F*)effcut->Get("RatioStep4_4_castorgap");
  TH1F* h_eff_step_4_3_castor = (TH1F*)effcut->Get("RatioStep4_3_castorgap");
  TH1F* h_eff_step_4_2_castor = (TH1F*)effcut->Get("RatioStep4_2_castorgap");
  TH1F* h_eff_step_4_1_castor = (TH1F*)effcut->Get("RatioStep4_1_castorgap");

  cutCorrection[0] = 1./h_eff_excl->GetBinContent(h_eff_excl->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  cutCorrection[1] = 1./h_eff_vertex->GetBinContent(h_eff_vertex->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  cutCorrection[2] = 1./h_eff_step_4_4->GetBinContent(h_eff_step_4_4->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  cutCorrection[3] = 1./h_eff_step_4_3->GetBinContent(h_eff_step_4_3->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  cutCorrection[4] = 1./h_eff_step_4_2->GetBinContent(h_eff_step_4_2->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  cutCorrection[5] = 1./h_eff_step_4_1->GetBinContent(h_eff_step_4_1->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  cutCorrection[6] = 1./h_eff_step_4_4_castor->GetBinContent(h_eff_step_4_4_castor->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  cutCorrection[7] = 1./h_eff_step_4_3_castor->GetBinContent(h_eff_step_4_3_castor->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  cutCorrection[8] = 1./h_eff_step_4_2_castor->GetBinContent(h_eff_step_4_2_castor->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  cutCorrection[9] = 1./h_eff_step_4_1_castor->GetBinContent(h_eff_step_4_1_castor->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));


  for (int i=0; i<10; i++){
    if (!isfinite(cutCorrection[i])) {
      cutCorrection[i] = 1.;
      ++counterinfcut;
      if (debug) {
	std::cout << "\n <DIVISION PER ZERO>" << std::endl;
	exit(EXIT_FAILURE);
      }
    }
  }

  return cutfactor;

}

double* ExclusiveDijet::triggerCorrection(){

  bool debug = false;

  if (eventinfo->GetInstLumiBunch() < -999){
    std::cout << "\n--------------------------------------------------------------" << std::endl;
    std::cout << " Only apply trigger correction in data, not in MC." << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    exit(EXIT_FAILURE);
  }

  double triggerCorrection[8];
  double* triggerfactor;

  triggerfactor = triggerCorrection;

  TH1F* h_eff_trigger_eta1 = (TH1F*)efftrigger->Get("Events_with_RefTriggerCutsOffLineAndTrigger_eta1");
  TH1F* h_eff_trigger_eta2 = (TH1F*)efftrigger->Get("Events_with_RefTriggerCutsOffLineAndTrigger_eta2");
  TH1F* h_eff_trigger_eta3 = (TH1F*)efftrigger->Get("Events_with_RefTriggerCutsOffLineAndTrigger_eta3");
  TH1F* h_eff_trigger_eta4 = (TH1F*)efftrigger->Get("Events_with_RefTriggerCutsOffLineAndTrigger_eta4");
  TH1F* h_eff_trigger_eta1_castorgap = (TH1F*)efftrigger->Get("Events_with_RefTriggerCutsOffLineAndTrigger_eta1_castorgap");
  TH1F* h_eff_trigger_eta2_castorgap = (TH1F*)efftrigger->Get("Events_with_RefTriggerCutsOffLineAndTrigger_eta2_castorgap");
  TH1F* h_eff_trigger_eta3_castorgap = (TH1F*)efftrigger->Get("Events_with_RefTriggerCutsOffLineAndTrigger_eta3_castorgap");
  TH1F* h_eff_trigger_eta4_castorgap = (TH1F*)efftrigger->Get("Events_with_RefTriggerCutsOffLineAndTrigger_eta4_castorgap");

  triggerCorrection[0] = 1./h_eff_trigger_eta4->GetBinContent(h_eff_trigger_eta4->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  triggerCorrection[1] = 1./h_eff_trigger_eta3->GetBinContent(h_eff_trigger_eta3->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  triggerCorrection[2] = 1./h_eff_trigger_eta2->GetBinContent(h_eff_trigger_eta2->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  triggerCorrection[3] = 1./h_eff_trigger_eta1->GetBinContent(h_eff_trigger_eta1->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  triggerCorrection[4] = 1./h_eff_trigger_eta4_castorgap->GetBinContent(h_eff_trigger_eta4_castorgap->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  triggerCorrection[5] = 1./h_eff_trigger_eta3_castorgap->GetBinContent(h_eff_trigger_eta3_castorgap->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  triggerCorrection[6] = 1./h_eff_trigger_eta2_castorgap->GetBinContent(h_eff_trigger_eta2_castorgap->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));
  triggerCorrection[7] = 1./h_eff_trigger_eta1_castorgap->GetBinContent(h_eff_trigger_eta1_castorgap->GetXaxis()->FindBin(eventinfo->GetInstLumiBunch()));

  for (int i=0; i<8; i++){
    if (!isfinite(triggerCorrection[i])) {
      triggerCorrection[i] = 1.;
      ++counterinftrigger;
      if (debug) {
	std::cout << "\n <DIVISION PER ZERO>" << std::endl;
	exit(EXIT_FAILURE);
      }
    }
  }

  return triggerfactor;

}

void ExclusiveDijet::Run(std::string filein_, std::string savehistofile_, std::string processname_, std::string switchtrigger_, std::string type_, std::string jetunc_, std::string switchpucorr_, std::string pudatafile_, std::string pumcfile_, std::string switchcutcorr_, std::string switchtriggercorr_, std::string cutcorrfile_, std::string triggercorrfile_, std::string switchlumiweight_, double lumiweight_, std::string switchmceventweight_, int optnVertex_, int optTrigger_, double jet1pT_, double jet2pT_, std::string switchcastor_, std::string castorcorrfile_, double castorthreshold_, std::string switchpresel_){

  bool debug = false;
  bool debugcastor = false;

  counterinfcut = 0.;
  counterinftrigger = 0.;

  TH1::SetDefaultSumw2(true);
  TH2::SetDefaultSumw2(true);

  filein = filein_;
  savehistofile = savehistofile_;
  processname = processname_;
  type = type_;
  switchtrigger = switchtrigger_;
  jetunc = jetunc_;
  switchpucorr = switchpucorr_;
  pudatafile = pudatafile_;
  pumcfile = pumcfile_;
  switchcutcorr = switchcutcorr_;
  switchtriggercorr = switchtriggercorr_;
  cutcorrfile = cutcorrfile_;
  triggercorrfile = triggercorrfile_;
  switchlumiweight = switchlumiweight_;
  lumiweight = lumiweight_;
  switchmceventweight = switchmceventweight_;
  optnVertex = optnVertex_;
  optTrigger = optTrigger_;
  jet1pT = jet1pT_;
  jet2pT = jet2pT_;
  switchcastor = switchcastor_;
  castorthreshold = castorthreshold_;
  castorcorrfile = castorcorrfile_;
  switchpresel = switchpresel_;

  // Adding TTree Golden Events
  TString TTreeoutput;
  TTreeoutput = "TTreeGoldenCEP_" + savehistofile;
  fOut = new TFile(TTreeoutput, "RECREATE");
  fOut->cd();
  trout = new TTree("Events", "Events");
  trout->Branch("RunNumber",&bRunNumber,"bRunNumber/I");
  trout->Branch("LumiSection",&bLumiSection,"bLumiSection/I");
  trout->Branch("EventNumber",&bEventNumber,"bEventNumber/I");
  trout->Branch("LeadingJetPt",&bptJet1,"bptJet1/D");
  trout->Branch("SecondJetPt",&bptJet2,"bptJet2/D");
  trout->Branch("LeadingJetPtUnci",&bUnc1,"bUnc1/D");
  trout->Branch("SecondJetPtUnc",&bUnc2,"bUnc2/D");
  trout->Branch("LeadingJetEta",&bLeadingJetEta,"bLeadingJetEta/D");
  trout->Branch("SecondJetEta",&bSecondJetEta,"bSecondJetEta/D");
  trout->Branch("LeadingJetPhi",&bLeadingJetPhi,"bLeadingJetPhi/D");
  trout->Branch("SecondJetPhi",&bSecondJetPhi,"bSecondJetPhi/D");
  trout->Branch("JetsDeltaEta",&bJetsDeltaEta,"bJetsDeltaEta/D");
  trout->Branch("JetsDeltaPhi",&bJetsDeltaphi,"bJetsDeltaphi/D");
  trout->Branch("JetsDeltaPt",&bJetsDeltaPt,"bJetsDeltaPt/D");
  trout->Branch("MassDijets",&bMassDijets,"bMassDijets/D");
  trout->Branch("SumEHFMinus",&bSumEnergyHFPlus,"bSumEnergyHFPlus/D");
  trout->Branch("SumEHFPlus",&bSumEnergyHFMinus,"bSumEnergyHFMinus/D");
  trout->Branch("SumEHEPlus",&bSumEnergyHEPlus,"bSumEnergyHEPlus/D");
  trout->Branch("SumEHEMinus",&bSumEnergyHEMinus,"bSumEnergyHEMinus/D");
  trout->Branch("SumEHFPFlowPlus",&bSumEHFPFlowPlus,"bSumEHFPFlowPlus/D");
  trout->Branch("SumEHFPFlowMinus",&bSumEHFPFlowMinus,"bSumEHFPFlowMinus/D");
  trout->Branch("SumECASTOR",&bsumCastorEnergy,"bsumCastorEnergy/D");
  trout->Branch("SumECastorAndHFMinus",&bsumCastorAndHFMinusEnergy,"bsumCastorAndHFMinusEnergy/D");
  trout->Branch("nHFPlus",&bMultiplicityHFPlus,"bMultiplicityHFPlus/I");
  trout->Branch("nHFMinus",&bMultiplicityHFMinus,"bMultiplicityHFMinus/I");
  trout->Branch("nTracks",&bMultiplicityTracks,"bMultiplicityTracks/I");
  trout->Branch("nTracksNonCone",&bTracksNonCone,"bTracksNonCone/I");
  trout->Branch("nTracksTransverse",&bTracksTransverse,"bTracksTransverse/I");
  trout->Branch("nTracksOutsideJets",&bTracksOutsideJets,"bTracksOutsideJets/I");
  trout->Branch("Rjj",&bRjjFromJets,"bRjjFromJets/D");
  trout->Branch("EtaMax",&bEtaMaxFromPFCands,"bEtaMaxFromPFCands/D");
  trout->Branch("EtaMin",&betamin,"betamin/D");
  trout->Branch("aSumE",&baSumE,"baSumE/D");
  trout->Branch("DeltaEtaPF",&bdeltaetapf,"bdeltaetapf/D");
  trout->Branch("XiPlus",&bXiPlusFromPFCands,"bXiPlusFromPFCands/D");
  trout->Branch("XiMinus",&bXiMinusFromPFCands,"bXiMinusFromPFCands/D");

  TString TTreeoutputAll;
  TTreeoutputAll = "TTreeAllJets_" + savehistofile;
  fOutAll = new TFile(TTreeoutputAll, "RECREATE");
  fOutAll->cd();
  troutAll = trout->CloneTree(0);

  TFile check1(filein.c_str());
  TFile check2(castorcorrfile.c_str());

  if (check1.IsZombie()){

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << " There is no the file " << filein << " or the" << std::endl;
    std::cout << " path is not correct." << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    return;

  }

  if (check1.GetDirectory(processname.c_str())){
    LoadFile(filein,processname);
  }

  else {
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << " There is no directory/path " << processname << std::endl;
    std::cout << " in the file." << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    return;
  }

  TFile *outf = new TFile(savehistofile.c_str(),"RECREATE");
  TString outtxt = savehistofile;
  outtxt.ReplaceAll("root","txt");
  std::ofstream outstring(outtxt);

  outstring << "" << std::endl;
  outstring << "<< Gold Events >>" << std::endl;
  outstring << "" << std::endl;
  outstring << "Please, insert this events in another text file to be used by PickEvent Tool. " << std::endl;
  outstring << "Twiki: https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookPickEvents " << std::endl;
  outstring << ">>---------------------------------------------------------------------- " << std::endl;
  outstring << "Selected Events: Trigger + PreSel + Vertex + Dijets (pT and Tracker acceptance) + etamax/etamin 2 " << std::endl;

  int NEVENTS = tr->GetEntries();
  int pileup = -999;
  int triggercounter[20]={0};
  char channel_castor[300];

  TH1::SetDefaultSumw2(true);
  TH2::SetDefaultSumw2(true);

  unsigned NEntries = tr->GetEntries();
  std::cout << "" << std::endl;
  std::cout<< "Reading Tree: "<< NEntries << " events"<<std::endl;
  std::cout << "" << std::endl;

  std::string status, jetstatus;

  edm::LumiReWeighting LumiWeights_(pumcfile.c_str(),pudatafile.c_str(),"pileUpBx0_complete_without_cuts","pileup");

  std::cout << "" << std::endl;
  std::cout<< "Status Bar" << std::endl;
  std::cout << "" << std::endl;

  if (switchtriggercorr == "trigger_correction") efftrigger = TFile::Open(triggercorrfile_.c_str());
  if (switchcutcorr == "cut_correction") effcut = TFile::Open(cutcorrfile_.c_str());

  if (switchcastor == "castor_correction" || switchcastor == "castor_no_correction") {

    h_castor_channel = (TH2F*)check2.Get("channelcorrector");

    // Get CASTOR Corrections
    for(int i=1; i<6;i++){
      for(int j=1; j<17; j++){
	energycorr[i-1][j-1]=0;
	if (switchcastor == "castor_correction"){
	  energycorr[i-1][j-1]=h_castor_channel->GetBinContent(i,j);
	}else{
	  energycorr[i-1][j-1]=1.;
	}
	if (debugcastor) std::cout << "Module " << i << " | Sector: " << j << ", Correction: " << energycorr[i-1][j-1] << std::endl;
      }
    }

  }

  for(int i=0;i<NEVENTS;i++){

    deltaphi = -999.;
    aSumE = -999.;
    absdeltaetapf = -999.;
    deltaetapf = -999.;
    ptJet1 = -999.;
    ptJet2 = -999.;
    double sumHFs = eventdiff->GetSumEnergyHFPlus() + eventdiff->GetSumEnergyHFMinus();

    if (!debug) {
      loadBar(i,NEVENTS,100,100);
    }

    tr->GetEntry(i);

    if ( type=="multiple_pileup" && (eventexcl->GetNPileUpBx0()==-1 && eventexcl->GetNPileUpBxm1()==-1 && eventexcl->GetNPileUpBxp1()==-1 )){
      std::cout << " " << std::endl;
      std::cout << "--------------------------------------------------------------" << std::endl;
      std::cout << " There is no pile-up TTree information in your PATTuplefile." << std::endl;
      std::cout << " Please, use another PATTuple with PU information to run mul- " << std::endl;
      std::cout << " tiple PU option." << std::endl;
      std::cout << "--------------------------------------------------------------" << std::endl;
      return;
    }

    if (type=="multiple_pileup"){
      pileup = eventexcl->GetNPileUpBx0();
    }
    else{
      pileup = 0;
    }

    for (int nt=0;nt<20;nt++){
      if(eventexcl->GetHLTPath(nt)>0){
	triggercounter[nt]++;
      }
    }

    deltaphi = fabs(eventexcl->GetLeadingJetPhi()-eventexcl->GetSecondJetPhi());
    if(sumHFs>0.){
      aSumE = (eventdiff->GetSumEnergyHFPlus() - eventdiff->GetSumEnergyHFMinus())/(eventdiff->GetSumEnergyHFPlus() + eventdiff->GetSumEnergyHFMinus());
    }else{
      aSumE = 999.;
    }
    absdeltaetapf = fabs(eventdiff->GetEtaMaxFromPFCands()-eventdiff->GetEtaMinFromPFCands());
    deltaetapf = (eventdiff->GetEtaMaxFromPFCands()-eventdiff->GetEtaMinFromPFCands());

    if (jetunc == "plus"){
      ptJet1 = eventexcl->GetLeadingJetPt() + eventexcl->GetUnc1()*eventexcl->GetLeadingJetPt();
      ptJet2 = eventexcl->GetSecondJetPt() + eventexcl->GetUnc2()*eventexcl->GetSecondJetPt();
      jetstatus = "Jets Unc. Plus";
    }

    else if (jetunc == "minus"){
      ptJet1 = eventexcl->GetLeadingJetPt() - eventexcl->GetUnc1()*eventexcl->GetLeadingJetPt();
      ptJet2 = eventexcl->GetSecondJetPt() - eventexcl->GetUnc2()*eventexcl->GetSecondJetPt();
      jetstatus = "Jets Unc. Minus";
    }

    else if (jetunc == "none"){
      ptJet1 = eventexcl->GetLeadingJetPt();
      ptJet2 = eventexcl->GetSecondJetPt();
      jetstatus = "Normal";
    }

    else {
      ptJet1 = eventexcl->GetLeadingJetPt();
      ptJet2 = eventexcl->GetSecondJetPt();
      jetstatus = "\nUnrecognized jet energy scale correction. Jets without uncertainty.";
      exit(EXIT_FAILURE);
    }

    double totalcommon = 1.;
    double mclumiweight = 1.;
    double mcweightpu = 1.;
    double mcweight = 1.;

    double triggereff4 = 1.;
    double triggereff3 = 1.;
    double triggereff2 = 1.;
    double triggereff1 = 1.;
    double triggereff4_castorgap = 1.;
    double triggereff3_castorgap = 1.;
    double triggereff2_castorgap = 1.;
    double triggereff1_castorgap = 1.;

    double cuteff_excl = 1.; // presel
    double cuteff_vertex = 1.; // presel + vertex
    double cuteff_step4_4 = 1. ; // presel + vertex + etamax 4
    double cuteff_step4_3 = 1.; // presel + vertex + etamax 3
    double cuteff_step4_2 = 1.; // presel + vertex + etamax 2
    double cuteff_step4_1 = 1.; // presel + vertex + etamax 1
    double cuteff_step4_4_castor = 1. ; // presel + vertex + etamax 4 + CASTOR
    double cuteff_step4_3_castor = 1.; // presel + vertex + etamax 3 + CASTOR
    double cuteff_step4_2_castor = 1.; // presel + vertex + etamax 2 + CASTOR
    double cuteff_step4_1_castor = 1.; // presel + vertex + etamax 1 +CASTOR

    if (switchlumiweight == "mc_lumi_weight"){
      mclumiweight = lumiweight;
    }

    if (switchmceventweight == "mc_event_weight"){
      if (eventinfo->GetGeneratorWeight() < 0){
	std::cout << " " << std::endl;
	std::cout << "\n--------------------------------------------------------------" << std::endl;
	std::cout << " The event mc weight is negative. Set up correct MC." << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	exit(EXIT_FAILURE);
      }
      mcweight = eventinfo->GetGeneratorWeight();
    }

    if (switchpucorr=="pileup_correction") mcweightpu = LumiWeights_.weight(eventexcl->GetNPileUpBx0());

    if (switchtriggercorr == "trigger_correction"){
      double* vfactortrigger = triggerCorrection();
      triggereff4 = vfactortrigger[0];
      triggereff3 = vfactortrigger[1];
      triggereff2 = vfactortrigger[2];
      triggereff1 = vfactortrigger[3];
      triggereff4_castorgap = vfactortrigger[4];
      triggereff3_castorgap = vfactortrigger[3];
      triggereff2_castorgap = vfactortrigger[2];
      triggereff1_castorgap = vfactortrigger[1];
    }

    if (switchcutcorr == "cut_correction"){
      double* vfactorcut = cutCorrection();
      cuteff_excl = vfactorcut[0];
      cuteff_vertex = vfactorcut[1];
      cuteff_step4_4 = vfactorcut[2];
      cuteff_step4_3 = vfactorcut[3];
      cuteff_step4_2 = vfactorcut[4];
      cuteff_step4_1 = vfactorcut[5];
      cuteff_step4_4_castor = vfactorcut[6];
      cuteff_step4_3_castor = vfactorcut[7];
      cuteff_step4_2_castor = vfactorcut[8];
      cuteff_step4_1_castor = vfactorcut[9];
    }

    totalcommon = mcweightpu*mcweight*mclumiweight;

    if (debug){
      if( i % 1000 == 0 ){
	std::cout << "\nEvent " << i << std::endl;
	std::cout << "Nr. events Bx 0: " << eventexcl->GetNPileUpBx0() << std::endl;
	std::cout << "Lumi per Bunch: " << eventinfo->GetInstLumiBunch() << std::endl;
	std::cout << "Leading Jet: " << eventexcl->GetLeadingJetPt() << " | Unc: " << eventexcl->GetUnc1() << " | Unc*pT: " << eventexcl->GetLeadingJetPt()*eventexcl->GetUnc1() << " | Eta: " << eventexcl->GetLeadingJetEta() << std::endl;
	std::cout << "Second Jet: " << eventexcl->GetSecondJetPt() << " | Unc: " << eventexcl->GetUnc2() << " | Unc*pT: " << eventexcl->GetSecondJetPt()*eventexcl->GetUnc2() << " | Eta: " << eventexcl->GetSecondJetEta() << std::endl;
	std::cout << "Leading Jet P4: " << eventexcl->GetLeadingJetP4().Pt() << " | Unc: " << eventexcl->GetUnc1() << " | Unc*pT: " << eventexcl->GetLeadingJetP4().Pt()*eventexcl->GetUnc1() << " | Eta: " << eventexcl->GetLeadingJetP4().Eta() << std::endl;
	std::cout << "Second Jet P4: " << eventexcl->GetSecondJetP4().Pt() << " | Unc: " << eventexcl->GetUnc2() << " | Unc*pT: " << eventexcl->GetSecondJetP4().Pt()*eventexcl->GetUnc2() << " | Eta: " << eventexcl->GetSecondJetP4().Eta() << std::endl;
	std::cout << "ReWeight Pile-up (a): " << mcweightpu << std::endl;
	std::cout << "Event by Event MC flat weight (b): " << mcweight << std::endl;
	std::cout << "Luminosity weight (c): " << mclumiweight <<std::endl;
	std::cout << "Total Common weight (a*b*c): " << totalcommon <<std::endl;
	std::cout << "Trigger Eff. Corr Eta 4: " <<triggereff4 <<std::endl;
	std::cout << "Trigger Eff. Corr Eta 3: " <<triggereff3 <<std::endl;
	std::cout << "Trigger Eff. Corr Eta 2: " <<triggereff2 <<std::endl;
	std::cout << "Trigger Eff. Corr Eta 1: " <<triggereff1 <<std::endl;
	std::cout << "Eff cuts Pre Sel.: " << cuteff_excl <<std::endl;
	std::cout << "Eff cuts vertex: " << cuteff_vertex <<std::endl;
	std::cout << "Eff cuts eta 4: " << cuteff_step4_4 <<std::endl;
	std::cout << "Eff cuts eta 3: " << cuteff_step4_3 <<std::endl;
	std::cout << "Eff cuts eta 2: " << cuteff_step4_2 <<std::endl;
	std::cout << "Eff cuts eta 1: " << cuteff_step4_1 <<std::endl;
	std::cout << "Eff cuts eta 4 and CASTOR: " << cuteff_step4_4_castor <<std::endl;
	std::cout << "Eff cuts eta 3 and CASTOR: " << cuteff_step4_3_castor <<std::endl;
	std::cout << "Eff cuts eta 2 and CASTOR: " << cuteff_step4_2_castor <<std::endl;
	std::cout << "Eff cuts eta 1 and CASTOR: " << cuteff_step4_1_castor <<std::endl;

      }
    }

    sumCastorEnergy = 0.;
    sumCastorAndHFMinusEnergy = 0.;
    SectorCastorHit = 0;
    SectorZeroCastorCounter = 0;

    bool castorgap = false;
    bool castoractivity = false;
    double CastorEnergySector[16]; 

    if (switchcastor == "castor_correction" || switchcastor == "castor_no_correction") {

      sprintf(channel_castor,">> Castor Channel Threshold: %0.2f GeV",castorthreshold);
      for (int i=0; i < 16; i++){
	CastorEnergySector[i]=0.;
	if (i==4 || i==5){
	  if (eventdiff->GetCastorModule2Energy(i)*energycorr[1][i] > castorthreshold) CastorEnergySector[i]+=eventdiff->GetCastorModule2Energy(i)*energycorr[1][i];
	  if (eventdiff->GetCastorModule3Energy(i)*energycorr[2][i] > castorthreshold) CastorEnergySector[i]+=eventdiff->GetCastorModule3Energy(i)*energycorr[2][i];
	  if (eventdiff->GetCastorModule4Energy(i)*energycorr[3][i] > castorthreshold) CastorEnergySector[i]+=eventdiff->GetCastorModule4Energy(i)*energycorr[3][i];
	  if (eventdiff->GetCastorModule5Energy(i)*energycorr[4][i] > castorthreshold) CastorEnergySector[i]+=eventdiff->GetCastorModule5Energy(i)*energycorr[4][i];
	}else{
	  if (eventdiff->GetCastorModule1Energy(i)*energycorr[0][i] > castorthreshold) CastorEnergySector[i]+=eventdiff->GetCastorModule1Energy(i)*energycorr[0][i];
	  if (eventdiff->GetCastorModule2Energy(i)*energycorr[1][i] > castorthreshold) CastorEnergySector[i]+=eventdiff->GetCastorModule2Energy(i)*energycorr[1][i];
	  if (eventdiff->GetCastorModule3Energy(i)*energycorr[2][i] > castorthreshold) CastorEnergySector[i]+=eventdiff->GetCastorModule3Energy(i)*energycorr[2][i];
	  if (eventdiff->GetCastorModule4Energy(i)*energycorr[3][i] > castorthreshold) CastorEnergySector[i]+=eventdiff->GetCastorModule4Energy(i)*energycorr[3][i];
	  if (eventdiff->GetCastorModule5Energy(i)*energycorr[4][i] > castorthreshold) CastorEnergySector[i]+=eventdiff->GetCastorModule5Energy(i)*energycorr[4][i];
	}
      }

      for (int l=0; l<16;l++){
	sumCastorEnergy+=CastorEnergySector[l];
      }

      if (sumCastorEnergy > 0.){
	castoractivity = true;
      }else{
	castorgap = true;
      }

      if (castoractivity) {
	etamin_ = -6.;
      }else{
	etamin_ = eventdiff->GetEtaMinFromPFCands();
      }

    }else{
      sumCastorEnergy = -999.;
      etamin_ = eventdiff->GetEtaMinFromPFCands();
      castoractivity = true;
      castorgap = true;
    }

    sumCastorAndHFMinusEnergy = sumCastorEnergy+eventdiff->GetSumEnergyHFMinus();

    bool trigger = false;
    bool presel = false;
    bool vertex = false;
    bool dijetpt = false;
    bool dijeteta = false;
    bool d_eta4 = false;
    bool d_eta3 = false;
    bool d_eta2 = false;
    bool d_eta1 = false;

    // Defining Branchs
    bRunNumber = eventdiff->GetRunNumber();
    bLumiSection = eventdiff->GetLumiSection();
    bEventNumber = eventdiff->GetEventNumber();
    bptJet1 = ptJet1;
    bptJet2 = ptJet2;
    bUnc1 = eventexcl->GetUnc1();
    bUnc2 = eventexcl->GetUnc2();
    bLeadingJetEta = eventexcl->GetLeadingJetEta();
    bSecondJetEta = eventexcl->GetSecondJetEta();
    bLeadingJetPhi = eventexcl->GetLeadingJetPhi();
    bSecondJetPhi = eventexcl->GetSecondJetPhi();
    bJetsDeltaEta = eventexcl->GetJetsDeltaEta();
    bJetsDeltaphi = deltaphi;
    bJetsDeltaPt = eventexcl->GetJetsDeltaPt();
    bMassDijets = eventexcl->GetMassDijets();
    bSumEnergyHFPlus = eventdiff->GetSumEnergyHFPlus();
    bSumEnergyHFMinus = eventdiff->GetSumEnergyHFMinus();
    bSumEnergyHEPlus = eventdiff->GetSumEnergyHEPlus();
    bSumEnergyHEMinus = eventdiff->GetSumEnergyHEMinus();
    bSumEHFPFlowPlus = eventexcl->GetSumEHFPFlowPlus();
    bSumEHFPFlowMinus = eventexcl->GetSumEHFPFlowMinus();
    bsumCastorEnergy = sumCastorEnergy;
    bsumCastorAndHFMinusEnergy = sumCastorAndHFMinusEnergy;
    bMultiplicityHFPlus = eventdiff->GetMultiplicityHFPlus();
    bMultiplicityHFMinus = eventdiff->GetMultiplicityHFMinus();
    bMultiplicityTracks = eventdiff->GetMultiplicityTracks();
    bTracksNonCone = eventexcl->GetTracksNonCone();
    bTracksTransverse = eventexcl->GetTracksTransverse();
    bTracksOutsideJets = eventexcl->GetTracksOutsideJets();
    bRjjFromJets = eventexcl->GetRjjFromJets();
    bEtaMaxFromPFCands = eventdiff->GetEtaMaxFromPFCands();
    betamin = etamin_;
    baSumE = aSumE;
    bdeltaetapf = deltaetapf;
    bXiPlusFromPFCands = eventdiff->GetXiPlusFromPFCands();
    bXiMinusFromPFCands = eventdiff->GetXiMinusFromPFCands();

    if (eventexcl->GetHLTPath(optTrigger)>0) trigger = true;

    if (switchpresel == "preselection") {
      if ((eventdiff->GetSumEnergyHFPlus() < 30 && eventdiff->GetSumEnergyHFMinus() < 30)) presel = true;
    }
    if (switchpresel == "no_preselection") presel = true;
    if (eventexcl->GetNVertex() > 0 && eventexcl->GetNVertex()<= optnVertex) vertex = true;
    if (ptJet1 > jet1pT && ptJet2 > jet2pT) dijetpt = true;
    if (eventexcl->GetLeadingJetEta() < 2.9 && eventexcl->GetSecondJetEta() < 2.9 && eventexcl->GetLeadingJetEta() > -2.9 && eventexcl->GetSecondJetEta() > -2.9) dijeteta = true;
    if ((eventdiff->GetEtaMinFromPFCands() > -4. && eventdiff->GetEtaMaxFromPFCands() < 4.)) d_eta4 = true;
    if ((eventdiff->GetEtaMinFromPFCands() > -3. && eventdiff->GetEtaMaxFromPFCands() < 3.)) d_eta3 = true;
    if ((eventdiff->GetEtaMinFromPFCands() > -2. && eventdiff->GetEtaMaxFromPFCands() < 2.)) d_eta2 = true;
    if ((eventdiff->GetEtaMinFromPFCands() > -1. && eventdiff->GetEtaMaxFromPFCands() < 1.)) d_eta1 = true;

    if(pileup < 21){ // Never comment this line. It is the program defense.

      if(switchtrigger == "trigger"){
	FillHistos(0,pileup,totalcommon);
	if(trigger) FillHistos(1,pileup,totalcommon);
	if(trigger && presel) FillHistos(2,pileup,totalcommon*cuteff_excl);
	if(trigger && presel && vertex) FillHistos(3,pileup,totalcommon*cuteff_vertex);
	if(trigger && presel && vertex && dijetpt && dijeteta) FillHistos(4,pileup,totalcommon*cuteff_vertex);
	if(trigger && presel && vertex && dijetpt && dijeteta && d_eta4){
	  FillHistos(5,pileup,totalcommon*cuteff_step4_4*triggereff4);
	  fOutAll->cd();
	  troutAll->Fill();
	}
	if(trigger && presel && vertex && dijetpt && dijeteta && d_eta3) FillHistos(6,pileup,totalcommon*cuteff_step4_3*triggereff3);
	if(trigger && presel && vertex && dijetpt && dijeteta && d_eta2){
	  FillHistos(7,pileup,totalcommon*cuteff_step4_2*triggereff2);
	  outstring << eventdiff->GetRunNumber() << ":" << eventdiff->GetLumiSection() << ":" << eventdiff->GetEventNumber() << std::endl;
	  fOut->cd();
	  trout->Fill();
	}
	if(trigger && presel && vertex && dijetpt && dijeteta && d_eta1) FillHistos(8,pileup,totalcommon*cuteff_step4_1*triggereff1);

	if (switchcastor == "castor_correction" || switchcastor == "castor_no_correction") {
	  if(trigger && presel && vertex && dijetpt && dijeteta && castorgap && d_eta4){
	    FillHistos(9,pileup,totalcommon*cuteff_step4_4_castor*triggereff4_castorgap);
	    fOutAll->cd();
	    troutAll->Fill();
	  }
	  if(trigger && presel && vertex && dijetpt && dijeteta && castorgap && d_eta3) FillHistos(10,pileup,totalcommon*cuteff_step4_3_castor*triggereff3_castorgap);
	  if(trigger && presel && vertex && dijetpt && dijeteta && castorgap && d_eta2){
	    FillHistos(11,pileup,totalcommon*cuteff_step4_2_castor*triggereff2_castorgap);
	    outstring << "CASTOR GAP " << eventdiff->GetRunNumber() << ":" << eventdiff->GetLumiSection() << ":" << eventdiff->GetEventNumber() << std::endl;
	    fOut->cd();
	    trout->Fill();
	  }
	  if(trigger && presel && vertex && dijetpt && dijeteta && castorgap && d_eta1) FillHistos(12,pileup,totalcommon*cuteff_step4_1_castor*triggereff1_castorgap);
	}
      }

      else if (switchtrigger =="no_trigger"){
	FillHistos(0,pileup,totalcommon);
	if(presel) FillHistos(2,pileup,totalcommon*cuteff_excl);
	if(presel && vertex) FillHistos(3,pileup,totalcommon*cuteff_vertex);
	if(presel && vertex && dijetpt && dijeteta) FillHistos(4,pileup,totalcommon*cuteff_vertex);
	if(presel && vertex && dijetpt && dijeteta && d_eta4){
	  FillHistos(5,pileup,totalcommon*cuteff_step4_4*triggereff4);
	  fOutAll->cd();
	  troutAll->Fill();
	}
	if(presel && vertex && dijetpt && dijeteta && d_eta3) FillHistos(6,pileup,totalcommon*cuteff_step4_3*triggereff3);
	if(presel && vertex && dijetpt && dijeteta && d_eta2){
	  FillHistos(7,pileup,totalcommon*cuteff_step4_2*triggereff2);
	  fOut->cd();
	  trout->Fill();
	}
	if(presel && vertex && dijetpt && dijeteta && d_eta1) FillHistos(8,pileup,totalcommon*cuteff_step4_1*triggereff1);
	if (switchcastor == "castor_correction" || switchcastor == "castor_no_correction") {
	  if(presel && vertex && dijetpt && dijeteta && castorgap && d_eta4){
	    FillHistos(9,pileup,totalcommon*cuteff_step4_4_castor*triggereff4_castorgap);
	    fOutAll->cd();
	    troutAll->Fill();
	  }
	  if(presel && vertex && dijetpt && dijeteta && castorgap && d_eta3) FillHistos(10,pileup,totalcommon*cuteff_step4_3_castor*triggereff3_castorgap);
	  if(presel && vertex && dijetpt && dijeteta && castorgap && d_eta2){
	    FillHistos(11,pileup,totalcommon*cuteff_step4_2_castor*triggereff2_castorgap);
	    fOut->cd();
	    trout->Fill();
	  }
	  if(presel && vertex && dijetpt && dijeteta && castorgap && d_eta1) FillHistos(12,pileup,totalcommon*cuteff_step4_1_castor*triggereff1_castorgap);
	}
      }
      else {
	exit(EXIT_FAILURE);
      }
    }
  }

  outstring << "" << std::endl;
  outstring << "<< INPUTS >>" << std::endl;
  outstring << " " << std::endl;
  outstring << ">> Input file: " << filein << std::endl;
  outstring << ">> Output file: " << savehistofile << std::endl;
  outstring << ">> TTree Name: " << processname << std::endl;
  outstring << ">> Input PU Data file: " << pudatafile <<std::endl;
  outstring << ">> Input PU MC file: " << pumcfile <<std::endl;
  outstring << ">> Input Trigger Corr. file: " << triggercorrfile <<std::endl;
  outstring << ">> Input Cuts Corr. file: " << cutcorrfile <<std::endl;
  outstring << " " << std::endl;
  outstring << "<< OPTIONS >>" << std::endl;
  outstring << " " << std::endl;
  outstring << ">> Jet Uncertainty: " << jetstatus << std::endl;
  outstring << ">> Trigger: " << switchtrigger << " | Option: " << optTrigger << std::endl;
  outstring << ">> # Vertex: " << optnVertex << std::endl;
  outstring << ">> PU Reweight: " << switchpucorr << std::endl;
  outstring << ">> Corr. Trigger: " << switchtriggercorr << std::endl;
  outstring << ">> Corr. Cuts: " << switchcutcorr << std::endl;
  outstring << ">> Lumi. Weight: " << switchlumiweight << " | Weight: " << lumiweight << std::endl;
  outstring << ">> MC Event-Event Weight: " << switchmceventweight << std::endl;
  outstring << ">> Jet1(pT) > " << jet1pT <<std::endl;
  outstring << ">> Jet2(pT) > " << jet2pT <<std::endl;
  outstring << ">> Castor: " << switchcastor << std::endl;
  outstring << ">> Castor Threshold: " << channel_castor << " GeV" << std::endl;
  outstring << ">> Castor Correction file: " << castorcorrfile << std::endl;
  outstring << ">> Preselection: " << switchpresel <<std::endl;
  outstring << " " << std::endl;
  outstring << "<< TRIGGER >> " << std::endl;
  outstring << " " << std::endl;
  outstring << "Total Trigger Fired: " << std::endl;
  outstring << "Trigger 0: " << triggercounter[0] << std::endl;
  outstring << "Trigger 1: " << triggercounter[1] << std::endl;
  outstring << "Trigger 2: " << triggercounter[2] << std::endl;
  outstring << "Trigger 3: " << triggercounter[3] << std::endl;
  outstring << "Trigger 4: " << triggercounter[4] << std::endl;
  outstring << "Trigger 5: " << triggercounter[5] << std::endl;
  outstring << "Trigger 6: " << triggercounter[6] << std::endl;
  outstring << "Trigger 7: " << triggercounter[7] << std::endl;
  outstring << "Trigger 8: " << triggercounter[8] << std::endl;
  outstring << "Trigger 9: " << triggercounter[9] << std::endl;
  outstring << "Trigger 10: " << triggercounter[10] << std::endl;
  outstring << "Trigger 11: " << triggercounter[11] << std::endl;
  outstring << "Trigger 12: " << triggercounter[12] << std::endl;
  outstring << "Trigger 13: " << triggercounter[13] << std::endl;
  outstring << "Trigger 14: " << triggercounter[14] << std::endl;
  outstring << "Trigger 15: " << triggercounter[15] << std::endl;
  outstring << "Trigger 16: " << triggercounter[16] << std::endl;
  outstring << "Trigger 17: " << triggercounter[17] << std::endl;
  outstring << "Trigger 18: " << triggercounter[18] << std::endl;
  outstring << "Trigger 19: " << triggercounter[19] << std::endl;
  outstring << "" << std::endl;
  outstring << "<< TRIGGER >> " << std::endl;
  outstring << " " << std::endl;
  outstring << "# of correction trigger efficiencies factors with NAN: " << counterinftrigger << std::endl;
  outstring << "# of correction cut efficiencies factors with NAN: " << counterinfcut << std::endl;
  outstring << "These weights were treated as 1. TH1* root defense." << std::endl;
  outstring << " " << std::endl;

  outf->cd();
  SaveHistos(type);
  outf->Close();

  fOut->cd();
  trout->Write();
  fOut->Close();

  fOutAll->cd();
  troutAll->Write();
  fOutAll->Close();

}

#if !defined(__CINT__) || defined(__MAKECINT__)
#include "FWCore/FWLite/interface/AutoLibraryLoader.h"
int main(int argc, char **argv)
{
  AutoLibraryLoader::enable();

  const char *s1="*";
  std::string filein_;
  std::string savehistofile_;
  std::string processname_;
  std::string switchtrigger_;
  std::string type_;
  std::string jetunc_;
  std::string switchpucorr_;
  std::string pudatafile_;
  std::string pumcfile_;
  std::string cutcorrfile_;
  std::string triggercorrfile_;
  std::string switchcutcorr_;
  std::string switchtriggercorr_;
  std::string switchlumiweight_;
  std::string switchcastor_;
  std::string castorcorrfile_;
  std::string switchpresel_;
  double lumiweight_;
  std::string switchmceventweight_;
  int optnVertex_;
  int optTrigger_;
  double jet1pT_;
  double jet2pT_;
  double castorthreshold_;

  if (argc > 1 && strcmp(s1,argv[1]) != 0) filein_ = argv[1];
  if (argc > 2 && strcmp(s1,argv[2]) != 0) savehistofile_ = argv[2];
  if (argc > 3 && strcmp(s1,argv[3]) != 0) processname_ = argv[3];
  if (argc > 4 && strcmp(s1,argv[4]) != 0) switchtrigger_ = argv[4];
  if (argc > 5 && strcmp(s1,argv[5]) != 0) type_ = argv[5];
  if (argc > 6 && strcmp(s1,argv[6]) != 0) jetunc_ = argv[6];
  if (argc > 7 && strcmp(s1,argv[7]) != 0) switchpucorr_ = argv[7];
  if (argc > 8 && strcmp(s1,argv[8]) != 0) pudatafile_ = argv[8];
  if (argc > 9 && strcmp(s1,argv[9]) != 0) pumcfile_ = argv[9];
  if (argc > 10 && strcmp(s1,argv[10]) != 0) cutcorrfile_ = argv[10];
  if (argc > 11 && strcmp(s1,argv[11]) != 0) triggercorrfile_ = argv[11];
  if (argc > 12 && strcmp(s1,argv[12]) != 0) switchcutcorr_ = argv[12];
  if (argc > 13 && strcmp(s1,argv[13]) != 0) switchtriggercorr_ = argv[13];
  if (argc > 14 && strcmp(s1,argv[14]) != 0) switchlumiweight_ = argv[14];
  if (argc > 15 && strcmp(s1,argv[15]) != 0) lumiweight_ = atof(argv[15]);
  if (argc > 16 && strcmp(s1,argv[16]) != 0) switchmceventweight_ = argv[16];
  if (argc > 17 && strcmp(s1,argv[17]) != 0) optnVertex_ = atoi(argv[17]);
  if (argc > 18 && strcmp(s1,argv[18]) != 0) optTrigger_ = atoi(argv[18]);
  if (argc > 19 && strcmp(s1,argv[19]) != 0) jet1pT_ = atof(argv[19]);
  if (argc > 20 && strcmp(s1,argv[20]) != 0) jet2pT_ = atof(argv[20]);
  if (argc > 21 && strcmp(s1,argv[21]) != 0) switchcastor_ = argv[21];
  if (argc > 22 && strcmp(s1,argv[22]) != 0) castorcorrfile_ = argv[22];
  if (argc > 23 && strcmp(s1,argv[23]) != 0) castorthreshold_ = atof(argv[23]);
  if (argc > 24 && strcmp(s1,argv[24]) != 0) switchpresel_ = argv[24];

  if(switchcutcorr_ == "cut_correction" || switchcutcorr_ == "no_cut_correction") {}
  else{
    std::cout << " " << std::endl;
    std::cout << "\nPlease Insert Cut Correction Option: " << std::endl;
    std::cout << "1) cut_correction: apply efficiency cut correction." << std::endl;
    std::cout << "2) no_cut_correction: do not apply efficiency cut correction." << std::endl;
    exit(EXIT_FAILURE);
  }

  if(switchtrigger_ == "trigger" || switchtrigger_ == "no_trigger") {}
  else{
    std::cout << " " << std::endl;
    std::cout << "\nPlease Insert type of selection: " << std::endl;
    std::cout << "1) trigger: with trigger. If PATTuple has trigger." << std::endl;
    std::cout << "2) no_trigger: without trigger. If PATTuple has not trigger." << std::endl;
    exit(EXIT_FAILURE);
  }

  if(switchcastor_ == "castor_correction" || switchcastor_ =="castor_no_correction" || switchcastor_ == "no_castor") {}
  else{
    std::cout << " " << std::endl;
    std::cout << "\nPlease Insert Castor Option: " << std::endl;
    std::cout << "1) castor_correction: for MC. Running with CASTOR but applying channels correction on MC." << std::endl;
    std::cout << "2) castor_no_correction: for data. Running with CASTOR." << std::endl;
    std::cout << "3) no_castor: without castor requirements." << std::endl;
    exit(EXIT_FAILURE);
  }

  if(switchpucorr_ == "pileup_correction" || switchpucorr_ == "no_pileup_correction") {}
  else{
    std::cout << " " << std::endl;
    std::cout << "\nPlease Insert Pile Up Reweight Option: " << std::endl;
    std::cout << "1) pileup_correction: apply pileup reweight. It works only for MC with PU." << std::endl;
    std::cout << "2) no_pileup_correction: do not apply pileup reweight. It works only for MC with PU." << std::endl;
    exit(EXIT_FAILURE);
  }

  if(switchtriggercorr_ == "trigger_correction" || switchtriggercorr_ == "no_trigger_correction") {}
  else{
    std::cout << " " << std::endl;
    std::cout << "\nPlease Insert Trigger Correction Option: " << std::endl;
    std::cout << "1) trigger_correction: apply trigger correction in the data." << std::endl;
    std::cout << "2) no_trigger_correction: do not apply trigger correction in the data." << std::endl;
    exit(EXIT_FAILURE);
  }

  if(switchmceventweight_ == "mc_event_weight" || switchmceventweight_ == "no_mc_event_weight") {}
  else{
    std::cout << " " << std::endl;
    std::cout << "\nPlease Insert MC Flat Weight Option" << std::endl;
    std::cout << "1) mc_event_weight: apply event by event weight in the flat MC. It works only for MC with flat pT distribution." << std::endl;
    std::cout << "2) no_mc_event_weight: do not apply event by event reweight in the MC." << std::endl;
    exit(EXIT_FAILURE);
  }

  if(switchlumiweight_ == "mc_lumi_weight" || switchlumiweight_ == "no_mc_lumi_weight") {}
  else{
    std::cout << " " << std::endl;
    std::cout << "\nPlease Insert MC Cross Section Weight: " << std::endl;
    std::cout << "1) mc_lumi_weight: apply normalization factor in the MC." << std::endl;
    std::cout << "2) no_mc_lumi_weight: do not apply normalization factor in the MC." << std::endl;
    exit(EXIT_FAILURE);
  }

  if(jetunc_ == "none" || jetunc_ == "minus" || jetunc_ == "plus") {}
  else{
    std::cout << " " << std::endl;
    std::cout << "\nPlease Insert Jet Uncertainty for systematic studies: " << std::endl;
    std::cout << "1) plus: pT + sigma." << std::endl;
    std::cout << "2) minus: pT - sigma." << std::endl;
    std::cout << "3) none: pT." << std::endl;
    exit(EXIT_FAILURE);
  }

  if(switchpresel_ == "preselection" || switchpresel_ == "no_preselection") {}
  else{
    std::cout << " " << std::endl;
    std::cout << "\nPlease Insert Pre Selection Option: " << std::endl;
    std::cout << "1) preselection: apply preselection cut." << std::endl;
    std::cout << "2) no_preselection: do not apply preselection cut." << std::endl;
    exit(EXIT_FAILURE);
  }

  if (type_=="multiple_pileup" || type_=="no_multiple_pileup") {

    if (optnVertex_ <= 0 || optTrigger_ < 0 || lumiweight_ <= 0 || jet1pT_ < 0 || jet2pT_ < 0 ){
      std::cout << "----------------------------------------------" << std::endl;
      std::cout << " Pay attention on the input numbers parameters" << std::endl;
      std::cout << "----------------------------------------------" << std::endl;
      std::cout << ">> Requirements: " << std::endl;
      std::cout << "I) optnVertex_ > 0 " << std::endl;
      std::cout << "II) optTrigger >= 0" << std::endl;
      std::cout << "III) lumiweight_ > 0" << std::endl;
      std::cout << "IV) jet1pT_ and jet2pT_ >= 0" << std::endl;
      std::cout << "----------------------------------------------" << std::endl;
      return 0;
    }

    ExclusiveDijet* exclusive = new ExclusiveDijet();
    exclusive->CreateHistos(type_,switchcastor_);

    TFile pudata(pudatafile_.c_str());
    TFile pumc(pumcfile_.c_str());
    if (pudata.IsZombie() || pumc.IsZombie()){
      std::cout << "----------------------------------------------" << std::endl;
      std::cout << " There is no Pile-Up data/mc file or the" << std::endl;
      std::cout << " path is not correct." << std::endl;
      std::cout << "----------------------------------------------" << std::endl;
      return 0;
    }
    else if (!pudata.GetListOfKeys()->Contains("pileup") || !pumc.GetListOfKeys()->Contains("pileUpBx0_complete_without_cuts") ){
      std::cout << "----------------------------------------------" << std::endl;
      std::cout << " There is no Pile-Up data/mc histograms: " << std::endl;
      std::cout << " data: pileup" << std::endl;
      std::cout << " mc: pileUpBx0_complete_without_cuts" << std::endl;
      std::cout << "----------------------------------------------" << std::endl;
      return 0;
    }

    if(switchcutcorr_ == "cut_correction"){
      TFile effcut(cutcorrfile_.c_str());
      if (effcut.IsZombie()){
	std::cout << "---------------------------------------" << std::endl;
	std::cout << " There is no Efficiency cut file or the" << std::endl;
	std::cout << " path is not correct." << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	return 0;
      }
      else if (!effcut.GetListOfKeys()->Contains("RatioPreSel") || !effcut.GetListOfKeys()->Contains("RatioVertex") || !effcut.GetListOfKeys()->Contains("RatioStep4_4") || !effcut.GetListOfKeys()->Contains("RatioStep4_3") || !effcut.GetListOfKeys()->Contains("RatioStep4_2")| !effcut.GetListOfKeys()->Contains("RatioStep4_1")){
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << " There is no Eff. Cuts histograms " << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	return 0;
      }
    }
    if(switchtriggercorr_ == "trigger_correction"){
      TFile efftrigger(triggercorrfile_.c_str());
      if (efftrigger.IsZombie()){
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << " There is no trigger efficiency file or the" << std::endl;
	std::cout << " path is not correct." << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	return 0;
      }
      else if (!efftrigger.GetListOfKeys()->Contains("Events_with_RefTriggerCutsOffLineAndTrigger_eta4") || !efftrigger.GetListOfKeys()->Contains("Events_with_RefTriggerCutsOffLineAndTrigger_eta3") || !efftrigger.GetListOfKeys()->Contains("Events_with_RefTriggerCutsOffLineAndTrigger_eta2") || !efftrigger.GetListOfKeys()->Contains("Events_with_RefTriggerCutsOffLineAndTrigger_eta1")){
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << " There is no Eff. Trigger histograms " << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	return 0;
      }
    }
    if(switchcastor_ == "castor_correction"){
      TFile castorfile(castorcorrfile_.c_str());
      if (castorfile.IsZombie()){
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << " There is no the file " << castorcorrfile_ << " or the" << std::endl;
	std::cout << " path is not correct." << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	return 0;
      }
      else if (!castorfile.GetListOfKeys()->Contains("channelcorrector")){
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << " There is no CASTOR channel corrector histogram " << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	return 0;
      }
    }

    exclusive->Run(filein_, savehistofile_, processname_, switchtrigger_, type_, jetunc_, switchpucorr_, pudatafile_, pumcfile_, switchcutcorr_, switchtriggercorr_, cutcorrfile_, triggercorrfile_, switchlumiweight_, lumiweight_, switchmceventweight_, optnVertex_, optTrigger_, jet1pT_, jet2pT_, switchcastor_, castorcorrfile_, castorthreshold_, switchpresel_);
    return 0;

  }

  else{
    std::cout << "Please Insert type of histograms: " << std::endl;
    std::cout << "1) multiple_pileup: create histograms for each pile-up event. It works only for MC with pile-up." << std::endl;
    std::cout << "2) no_multiple_pileup: create histograms without each pile-up event. It works for data and MC with/without pile-up." << std::endl;
    return 0;
  }
}
#endif
