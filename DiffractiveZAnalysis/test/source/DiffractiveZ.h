#ifndef DiffractiveZ_h
#define DiffractiveZ_h

#include <TFile.h>
#include <TTree.h>

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "PhysicsTools/Utilities/interface/LumiReWeighting.h"

class DiffractiveEvent;
class DiffractiveZEvent;
class EventInfoEvent;

class DiffractiveZ {

  TFile* effcut;
  TFile* efftrigger;
  TFile* inf;
  TFile* pudata;
  TFile* pumc;
  TTree* tr;
  TBranch *diff;
  TBranch *diffZ;
  TBranch *info;
  TH1* h_castor_channel;
  DiffractiveEvent *eventdiff;
  DiffractiveZEvent *eventdiffZ;
  EventInfoEvent *eventinfo;

  std::string fileinput;
  std::string processinput;
  int index;
  int pileup;
  int totalweight;
  double aSumE;
  int l, k;

  double absdeltaetapf;
  double deltaetapf;
  double deltaphielectrons;
  double deltaphimuons;
  double deltaetaelectrons;
  double deltaetamuons;
  double deltapTelectrons;
  double deltapTmuons;
  double sumCastorEnergy;
  double isoTk1;
  double isoTk2;
  double isoEcal1;
  double isoEcal2;
  double isoHcal1;
  double isoHcal2;
  int innerHits1;
  double Dcot1;
  double Dist1;
  double DeltaEtaTkClu1;
  double DeltaPhiTkClu1;
  double sigmaIeIe1;
  double HE1;
  int innerHits2;
  double Dcot2;
  double Dist2;
  double DeltaEtaTkClu2;
  double DeltaPhiTkClu2;
  double sigmaIeIe2;
  double HE2;
  double sumCastorAndHFMinusEnergy;
  int SectorCastorHit;
  double castorthreshold;
  double channelsthreshold;
  double etamin_;
  bool castoractivity;
  bool castorgap;

  std::string filein;
  std::string processname;
  std::string savehistofile;
  std::string switchtrigger;
  std::string type;
  std::string typesel;
  std::string switchlumiweight;
  std::string castorcorrfile;
  double mcweight;
  int nVertex;
  int optTrigger;
  double lepton1pt;
  double lepton2pt;
  int SectorZeroCastorCounter;
  double CastorEnergySector[16];

  std::vector<std::vector<TH1F*> > m_hVector_DiElectronMass;
  std::vector<std::vector<TH1F*> > m_hVector_DiElectronEta;
  std::vector<std::vector<TH1F*> > m_hVector_DiElectronPt;
  std::vector<std::vector<TH1F*> > m_hVector_DiElectronPhi;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronPt;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronEta;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronPhi;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronCharge;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronPt;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronEta;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronPhi;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronCharge;
  std::vector<std::vector<TH1F*> > m_hVector_ElectronsN;

  std::vector<std::vector<TH1F*> > m_hVector_DiMuonMass;
  std::vector<std::vector<TH1F*> > m_hVector_DiMuonEta;
  std::vector<std::vector<TH1F*> > m_hVector_DiMuonPt;
  std::vector<std::vector<TH1F*> > m_hVector_DiMuonPhi;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingMuonPt;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingMuonEta;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingMuonPhi;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingMuonCharge;
  std::vector<std::vector<TH1F*> > m_hVector_SecondMuonPt;
  std::vector<std::vector<TH1F*> > m_hVector_SecondMuonEta;
  std::vector<std::vector<TH1F*> > m_hVector_SecondMuonPhi;
  std::vector<std::vector<TH1F*> > m_hVector_SecondMuonCharge;
  std::vector<std::vector<TH1F*> > m_hVector_MuonsN;

  std::vector<std::vector<TH1F*> > m_hVector_sumEHFplus;
  std::vector<std::vector<TH1F*> > m_hVector_sumEHFminus;
  std::vector<std::vector<TH1F*> > m_hVector_sumEHEplus;
  std::vector<std::vector<TH1F*> > m_hVector_sumEHEminus;

  std::vector<std::vector<TH1F*> > m_hVector_lumi;
  std::vector<std::vector<TH1F*> > m_hVector_asumE;
  std::vector<std::vector<TH2F*> > m_hVector_multhf;
  std::vector<std::vector<TH2F*> > m_hVector_etcalos_p;
  std::vector<std::vector<TH2F*> > m_hVector_etcalos_n;
  std::vector<std::vector<TH1F*> > m_hVector_tracks;
  std::vector<std::vector<TH1F*> > m_hVector_pfetamax;
  std::vector<std::vector<TH1F*> > m_hVector_pfetamin;
  std::vector<std::vector<TH1F*> > m_hVector_pfetamincastor;
  std::vector<std::vector<TH1F*> > m_hVector_vertex;

  std::vector<std::vector<TH1F*> > m_hVector_deltaphielectrons;
  std::vector<std::vector<TH1F*> > m_hVector_deltaphimuons;
  std::vector<std::vector<TH1F*> > m_hVector_deltapTelectrons;
  std::vector<std::vector<TH1F*> > m_hVector_deltapTmuons;
  std::vector<std::vector<TH1F*> > m_hVector_deltaetaelectrons;
  std::vector<std::vector<TH1F*> > m_hVector_deltaetamuons;

  std::vector<std::vector<TH2F*> > m_hVector_vertexvslumi;

  std::vector<std::vector<TH1F*> > m_hVector_patNElectron;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron1Pt;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron1Eta;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron1Phi;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron1Charge;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron1Et;
  std::vector<std::vector<TH1F*> > m_hVector_patNMuon;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1Pt;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1Eta;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1Phi;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1Charge;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1Et;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron2Pt;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron2Eta;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron2Phi;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron2Charge;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron2Et;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2Pt;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2Eta;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2Phi;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2Charge;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2Et;
  std::vector<std::vector<TH1F*> > m_hVector_patDiElectronMass;
  std::vector<std::vector<TH1F*> > m_hVector_patDiMuonMass;
  std::vector<std::vector<TH1F*> > m_hVector_patDiElectronEta;
  std::vector<std::vector<TH1F*> > m_hVector_patDiMuonEta;
  std::vector<std::vector<TH1F*> > m_hVector_patDiElectronPt;
  std::vector<std::vector<TH1F*> > m_hVector_patDiMuonPt;
  std::vector<std::vector<TH1F*> > m_hVector_patDiElectronPhi;
  std::vector<std::vector<TH1F*> > m_hVector_patDiMuonPhi;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron1TkDr03;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron1TkDr04;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron1EcalDr03;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron1EcalDr04;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron1HcalDr03;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron1HcalDr04;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron2TkDr03;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron2TkDr04;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron2EcalDr03;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron2EcalDr04;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron2HcalDr03;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron2HcalDr04;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron1relIsoDr03;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron1relIsoDr04;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron2relIsoDr03;
  std::vector<std::vector<TH1F*> > m_hVector_patElectron2relIsoDr04;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1SumPtR03;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1SumPtR05;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1EmEtR03;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1EmEtR05;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1HadEtR03;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1HadEtR05;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2SumPtR03;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2SumPtR05;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2EmEtR03;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2EmEtR05;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2HadEtR03;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2HadEtR05;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1relIsoDr03;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1relIsoDr05;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2relIsoDr03;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2relIsoDr05;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon1relIso;
  std::vector<std::vector<TH1F*> > m_hVector_patMuon2relIso;

  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronTkDr03;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronTkDr04;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronEcalDr03;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronEcalDr04;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronHcalDr03;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronHcalDr04;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronTkDr03;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronTkDr04;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronEcalDr03;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronEcalDr04;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronHcalDr03;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronHcalDr04;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronrelIsoDr03;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronrelIsoDr04;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronrelIsoDr03;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronrelIsoDr04;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingMuonSumPtR03;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingMuonSumPtR05;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingMuonEmEtR03;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingMuonEmEtR05;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingMuonHadEtR03;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingMuonHadEtR05;
  std::vector<std::vector<TH1F*> > m_hVector_SecondMuonSumPtR03;
  std::vector<std::vector<TH1F*> > m_hVector_SecondMuonSumPtR05;
  std::vector<std::vector<TH1F*> > m_hVector_SecondMuonEmEtR03;
  std::vector<std::vector<TH1F*> > m_hVector_SecondMuonEmEtR05;
  std::vector<std::vector<TH1F*> > m_hVector_SecondMuonHadEtR03;
  std::vector<std::vector<TH1F*> > m_hVector_SecondMuonHadEtR05;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingMuonrelIsoDr03;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingMuonrelIsoDr05;
  std::vector<std::vector<TH1F*> > m_hVector_SecondMuonrelIsoDr03;
  std::vector<std::vector<TH1F*> > m_hVector_SecondMuonrelIsoDr05;

  std::vector<std::vector<TH2F*> > m_hVector_correlationElectron1Pt;
  std::vector<std::vector<TH2F*> > m_hVector_correlationElectron1Eta;
  std::vector<std::vector<TH2F*> > m_hVector_correlationElectron1Phi;
  std::vector<std::vector<TH2F*> > m_hVector_correlationElectron1Iso;
  std::vector<std::vector<TH2F*> > m_hVector_correlationMuon1Pt;
  std::vector<std::vector<TH2F*> > m_hVector_correlationMuon1Eta;
  std::vector<std::vector<TH2F*> > m_hVector_correlationMuon1Phi;
  std::vector<std::vector<TH2F*> > m_hVector_correlationMuon1Iso;

  std::vector<std::vector<TH2F*> > m_hVector_correlationElectron2Pt;
  std::vector<std::vector<TH2F*> > m_hVector_correlationElectron2Eta;
  std::vector<std::vector<TH2F*> > m_hVector_correlationElectron2Phi;
  std::vector<std::vector<TH2F*> > m_hVector_correlationElectron2Iso;
  std::vector<std::vector<TH2F*> > m_hVector_correlationMuon2Pt;
  std::vector<std::vector<TH2F*> > m_hVector_correlationMuon2Eta;
  std::vector<std::vector<TH2F*> > m_hVector_correlationMuon2Phi;
  std::vector<std::vector<TH2F*> > m_hVector_correlationMuon2Iso;

  std::vector<std::vector<TH2F*> > m_hVector_ECaloVsEta;
  std::vector<std::vector<TProfile*> > m_hVector_ECaloVsEtaTProf;
  std::vector<std::vector<TH1F*> > m_hVector_sumECastorMinus;
  std::vector<std::vector<TH2F*> > m_hVector_ECastorSector;
  std::vector<std::vector<TProfile*> > m_hVector_ECastorSectorTProf;

  std::vector<std::vector<TH1F*> > m_hVector_tracksOutMuonsCone03;
  std::vector<std::vector<TH1F*> > m_hVector_tracksOutElectronsCone03;
  std::vector<std::vector<TH1F*> > m_hVector_tracksOutpatMuonsCone03;
  std::vector<std::vector<TH1F*> > m_hVector_tracksOutpatElectronsCone03;

  std::vector<std::vector<TH1F*> > m_hVector_tracksOutMuonsCone04;
  std::vector<std::vector<TH1F*> > m_hVector_tracksOutElectronsCone04;
  std::vector<std::vector<TH1F*> > m_hVector_tracksOutpatMuonsCone04;
  std::vector<std::vector<TH1F*> > m_hVector_tracksOutpatElectronsCone04;

  std::vector<std::vector<TH1F*> > m_hVector_tracksOutMuonsCone05;
  std::vector<std::vector<TH1F*> > m_hVector_tracksOutElectronsCone05;
  std::vector<std::vector<TH1F*> > m_hVector_tracksOutpatMuonsCone05;
  std::vector<std::vector<TH1F*> > m_hVector_tracksOutpatElectronsCone05;

  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronInnerHits;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronDCot;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronDist;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronDeltaEtaTkClu;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronDeltaPhiTkClu;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronSigmaIeIe;
  std::vector<std::vector<TH1F*> > m_hVector_LeadingElectronHE;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronInnerHits;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronDCot;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronDist;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronDeltaEtaTkClu;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronDeltaPhiTkClu;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronSigmaIeIe;
  std::vector<std::vector<TH1F*> > m_hVector_SecondElectronHE;
  std::vector<std::vector<TH1F*> > m_hVector_SumEHFplus_S;
  std::vector<std::vector<TH1F*> > m_hVector_SumEHFminus_S;
  std::vector<std::vector<TH1F*> > m_hVector_SumEHFplus_L;
  std::vector<std::vector<TH1F*> > m_hVector_SumEHFminus_L;

  std::vector<std::vector<TH1F*> > m_hVector_maxetagap;
  std::vector<std::vector<TH1F*> > m_hVector_LimPlusgap;
  std::vector<std::vector<TH1F*> > m_hVector_LimMinusgap;
  std::vector<std::vector<TH1F*> > m_hVector_SumPTLimPlusgap;
  std::vector<std::vector<TH1F*> > m_hVector_SumPTLimMinusgap;

  std::vector<std::vector<TH1F*> > m_hVector_ElectronsPt;
  std::vector<std::vector<TH1F*> > m_hVector_ElectronsEta;
  std::vector<std::vector<TH1F*> > m_hVector_ElectronsPhi;
  std::vector<std::vector<TH1F*> > m_hVector_MuonsPt;
  std::vector<std::vector<TH1F*> > m_hVector_MuonsEta;
  std::vector<std::vector<TH1F*> > m_hVector_MuonsPhi;
  std::vector<std::vector<TH1F*> > m_hVector_patElectronsPt;
  std::vector<std::vector<TH1F*> > m_hVector_patElectronsEta;
  std::vector<std::vector<TH1F*> > m_hVector_patElectronsPhi;
  std::vector<std::vector<TH1F*> > m_hVector_patMuonsPt;
  std::vector<std::vector<TH1F*> > m_hVector_patMuonsEta;
  std::vector<std::vector<TH1F*> > m_hVector_patMuonsPhi;

  std::vector<std::vector<TH1F*> > m_hVector_SumEHFMax;
  std::vector<std::vector<TH1F*> > m_hVector_SumEHFMin;
  std::vector<std::vector<TH1F*> > m_hVector_EnergyVsEtaBin1D;
  std::vector<std::vector<TH1F*> >  m_hVector_absdeltaEtaPF;
  std::vector<std::vector<TH1F*> >  m_hVector_deltaEtaPF;
  std::vector<std::vector<TH1F*> > m_hVector_ECastorSectorBin1D;

  std::vector<std::vector<TH1F*> > m_hVector_RunNumber;
  std::vector<std::vector<TH1F*> > m_hVector_RunNumberZeroCastor;
  std::vector<std::vector<TH1F*> > m_hVector_RunNumberHighCastor;
  std::vector<std::vector<TProfile*> > m_hVector_EnergyHFMinusVsCastorTProf;
  std::vector<std::vector<TProfile*> > m_hVector_EnergyHFPlusVsCastorTProf;
  std::vector<std::vector<TH1F*> > m_hVector_sumECastorAndHFMinus;
  std::vector<std::vector<TH1F*> > m_hVector_CastorMultiplicity;
  std::vector<std::vector<TH2F*> > m_hVector_CastorMultiplicityVsLumi;
  std::vector<std::vector<TH2F*> > m_hVector_SectorVsTotalCastorEnergy;
  std::vector<std::vector<TProfile*> > m_hVector_SectorVsTotalCastorEnergyTProf;

  std::vector<std::vector<TH1F*> > m_hVector_XiPlusPF;
  std::vector<std::vector<TH1F*> > m_hVector_XiMinusPF;
  std::vector<std::vector<TH1F*> > m_hVector_XiPF;

  std::vector <std::string> Folders;

  public :
  DiffractiveZ() {}
  ~DiffractiveZ() {
    inf->Close();
  }

  void Run(std::string, std::string, std::string, std::string, int, double, double, int, std::string, std::string, double, std::string, double, double, std::string);
  void LoadFile(std::string,std::string);
  void CreateHistos(std::string);
  void FillHistos(int, int, double);
  void SaveHistos(std::string);

};
#endif
