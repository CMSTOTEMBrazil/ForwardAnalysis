#ifndef DiffractiveZEvent_h
#define DiffractiveZEvent_h

#include "DataFormats/Candidate/interface/Particle.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/Common/interface/DetSetVector.h"

namespace diffractiveZAnalysis {
  class DiffractiveZAnalysis;
}

class DiffractiveZEvent {
  public:
    typedef diffractiveZAnalysis::DiffractiveZAnalysis analysis_type;
    static const char* name;

    typedef reco::Particle::LorentzVector LorentzVector;

    DiffractiveZEvent();
    ~DiffractiveZEvent();

    void SetHLTPath(int idx, int fHLTBit)         { hltTrigResults_[idx] = fHLTBit;}
    void SetDiElectronMass(double fDiElectronMass) { DiElectronMass_ = fDiElectronMass;}
    void SetDiElectronPt(double fDiElectronPt) { DiElectronPt_ = fDiElectronPt;}
    void SetDiElectronEta(double fDiElectronEta) { DiElectronEta_ = fDiElectronEta;}
    void SetDiElectronPhi(double fDiElectronPhi) { DiElectronPhi_ = fDiElectronPhi;}
    void SetDiMuonMass(double fDiMuonMass) { DiMuonMass_ = fDiMuonMass;}
    void SetDiMuonPt(double fDiMuonPt) { DiMuonPt_ = fDiMuonPt;}
    void SetDiMuonEta(double fDiMuonEta) { DiMuonEta_ = fDiMuonEta;}
    void SetDiMuonPhi(double fDiMuonPhi) { DiMuonPhi_ = fDiMuonPhi;}

    void SetLeadingElectronPt(double fLeadingElectronPt)    { LeadingElectronPt_     = fLeadingElectronPt;}
    void SetLeadingElectronEta(double fLeadingElectronEta)  { LeadingElectronEta_     = fLeadingElectronEta;}
    void SetLeadingElectronPhi(double fLeadingElectronPhi)  { LeadingElectronPhi_    = fLeadingElectronPhi;}
    void SetLeadingElectronP4(LorentzVector fLeadingElectronP4)    { LeadingElectronP4_     = fLeadingElectronP4;}
    void SetLeadingElectronCharge(int fLeadingElectronCharge)  { LeadingElectronCharge_     = fLeadingElectronCharge;}
    void SetSecondElectronPt(double fSecondElectronPt)    { SecondElectronPt_     = fSecondElectronPt;}
    void SetSecondElectronEta(double fSecondElectronEta)  { SecondElectronEta_     = fSecondElectronEta;}
    void SetSecondElectronPhi(double fSecondElectronPhi)  { SecondElectronPhi_    = fSecondElectronPhi;}
    void SetSecondElectronP4(LorentzVector fSecondElectronP4)    { SecondElectronP4_     = fSecondElectronP4;}
    void SetSecondElectronCharge(int fSecondElectronCharge)  { SecondElectronCharge_     = fSecondElectronCharge;}
    void SetElectronsN(int fElectronsN)  { ElectronsN_    = fElectronsN;}

    void SetLeadingElectronTkDr03(double fLeadingElectronTkDr03)    {LeadingElectronTkDr03_ = fLeadingElectronTkDr03;}
    void SetLeadingElectronEcalDr03(double fLeadingElectronEcalDr03)    {LeadingElectronEcalDr03_ = fLeadingElectronEcalDr03;}
    void SetLeadingElectronHcalDr03(double fLeadingElectronHcalDr03)    {LeadingElectronHcalDr03_ = fLeadingElectronHcalDr03;}
    void SetSecondElectronTkDr03(double fSecondElectronTkDr03)    {SecondElectronTkDr03_ = fSecondElectronTkDr03;}
    void SetSecondElectronEcalDr03(double fSecondElectronEcalDr03)    {SecondElectronEcalDr03_ = fSecondElectronEcalDr03;}
    void SetSecondElectronHcalDr03(double fSecondElectronHcalDr03)    {SecondElectronHcalDr03_ = fSecondElectronHcalDr03;}

    void SetLeadingElectronTkDr04(double fLeadingElectronTkDr04)    {LeadingElectronTkDr04_ = fLeadingElectronTkDr04;}
    void SetLeadingElectronEcalDr04(double fLeadingElectronEcalDr04)    {LeadingElectronEcalDr04_ = fLeadingElectronEcalDr04;}
    void SetLeadingElectronHcalDr04(double fLeadingElectronHcalDr04)    {LeadingElectronHcalDr04_ = fLeadingElectronHcalDr04;}
    void SetSecondElectronTkDr04(double fSecondElectronTkDr04)    {SecondElectronTkDr04_ = fSecondElectronTkDr04;}
    void SetSecondElectronEcalDr04(double fSecondElectronEcalDr04)    {SecondElectronEcalDr04_ = fSecondElectronEcalDr04;}
    void SetSecondElectronHcalDr04(double fSecondElectronHcalDr04)    {SecondElectronHcalDr04_ = fSecondElectronHcalDr04;}

    void SetLeadingElectronrelIsoDr03(double fLeadingElectronrelIsoDr03)    {LeadingElectronrelIsoDr03_ = fLeadingElectronrelIsoDr03;}
    void SetLeadingElectronrelIsoDr04(double fLeadingElectronrelIsoDr04)    {LeadingElectronrelIsoDr04_ = fLeadingElectronrelIsoDr04;}
    void SetSecondElectronrelIsoDr03(double fSecondElectronrelIsoDr03)    {SecondElectronrelIsoDr03_ = fSecondElectronrelIsoDr03;}
    void SetSecondElectronrelIsoDr04(double fSecondElectronrelIsoDr04)    {SecondElectronrelIsoDr04_ = fSecondElectronrelIsoDr04;}

    void SetLeadingMuonPt(double fLeadingMuonPt)    { LeadingMuonPt_     = fLeadingMuonPt;}
    void SetLeadingMuonEta(double fLeadingMuonEta)  { LeadingMuonEta_     = fLeadingMuonEta;}
    void SetLeadingMuonPhi(double fLeadingMuonPhi)  { LeadingMuonPhi_    = fLeadingMuonPhi;}
    void SetLeadingMuonP4(LorentzVector fLeadingMuonP4)    { LeadingMuonP4_     = fLeadingMuonP4;}
    void SetLeadingMuonCharge(int fLeadingMuonCharge)  { LeadingMuonCharge_     = fLeadingMuonCharge;}
    void SetSecondMuonPt(double fSecondMuonPt)    { SecondMuonPt_     = fSecondMuonPt;}
    void SetSecondMuonEta(double fSecondMuonEta)  { SecondMuonEta_     = fSecondMuonEta;}
    void SetSecondMuonPhi(double fSecondMuonPhi)  { SecondMuonPhi_    = fSecondMuonPhi;}
    void SetSecondMuonP4(LorentzVector fSecondMuonP4)    { SecondMuonP4_     = fSecondMuonP4;}
    void SetSecondMuonCharge(int fSecondMuonCharge)  { SecondMuonCharge_     = fSecondMuonCharge;}
    void SetMuonsN(int fMuonsN)  { MuonsN_    = fMuonsN;}

    void SetLeadingMuonSumPtR03(double fLeadingMuonSumPtR03)    {LeadingMuonSumPtR03_ = fLeadingMuonSumPtR03;}
    void SetLeadingMuonEmEtR03(double fLeadingMuonEmEtR03)    {LeadingMuonEmEtR03_ = fLeadingMuonEmEtR03;}
    void SetLeadingMuonHadEtR03(double fLeadingMuonHadEtR03)    {LeadingMuonHadEtR03_ = fLeadingMuonHadEtR03;}
    void SetLeadingMuonSumPtR05(double fLeadingMuonSumPtR05)    {LeadingMuonSumPtR05_ = fLeadingMuonSumPtR05;}
    void SetLeadingMuonEmEtR05(double fLeadingMuonEmEtR05)    {LeadingMuonEmEtR05_ = fLeadingMuonEmEtR05;}
    void SetLeadingMuonHadEtR05(double fLeadingMuonHadEtR05)    {LeadingMuonHadEtR05_ = fLeadingMuonHadEtR05;}

    void SetSecondMuonSumPtR03(double fSecondMuonSumPtR03)    {SecondMuonSumPtR03_ = fSecondMuonSumPtR03;}
    void SetSecondMuonEmEtR03(double fSecondMuonEmEtR03)    {SecondMuonEmEtR03_ = fSecondMuonEmEtR03;}
    void SetSecondMuonHadEtR03(double fSecondMuonHadEtR03)    {SecondMuonHadEtR03_ = fSecondMuonHadEtR03;}
    void SetSecondMuonSumPtR05(double fSecondMuonSumPtR05)    {SecondMuonSumPtR05_ = fSecondMuonSumPtR05;}
    void SetSecondMuonEmEtR05(double fSecondMuonEmEtR05)    {SecondMuonEmEtR05_ = fSecondMuonEmEtR05;}
    void SetSecondMuonHadEtR05(double fSecondMuonHadEtR05)    {SecondMuonHadEtR05_ = fSecondMuonHadEtR05;}

    void SetLeadingMuonrelIsoDr03(double fLeadingMuonrelIsoDr03)    {LeadingMuonrelIsoDr03_ = fLeadingMuonrelIsoDr03;}
    void SetSecondMuonrelIsoDr03(double fSecondMuonrelIsoDr03)    {SecondMuonrelIsoDr03_ = fSecondMuonrelIsoDr03;}
    void SetLeadingMuonrelIsoDr05(double fLeadingMuonrelIsoDr05)    {LeadingMuonrelIsoDr05_ = fLeadingMuonrelIsoDr05;}
    void SetSecondMuonrelIsoDr05(double fSecondMuonrelIsoDr05)    {SecondMuonrelIsoDr05_ = fSecondMuonrelIsoDr05;}

    void SetLeadingMuonTrackerHits(double fLeadingMuonTrackerHits)    {LeadingMuonTrackerHits_ = fLeadingMuonTrackerHits;}
    void SetLeadingMuonPixelHits(double fLeadingMuonPixelHits)    {LeadingMuonPixelHits_ = fLeadingMuonPixelHits;}
    void SetLeadingMuonNormalizedChi2(double fLeadingMuonNormalizedChi2)    {LeadingMuonNormalizedChi2_ = fLeadingMuonNormalizedChi2;}
    void SetLeadingMuonMatchedStations(double fLeadingMuonMatchedStations)    {LeadingMuonMatchedStations_ = fLeadingMuonMatchedStations;}
    void SetLeadingMuonDxy(double fLeadingMuonDxy)    {LeadingMuonDxy_ = fLeadingMuonDxy;}
    void SetLeadingMuonDz(double fLeadingMuonDz) {LeadingMuonDz_ = fLeadingMuonDz;}
    void SetLeadingMuonIsGlobal(bool fLeadingMuonIsGlobal)    {LeadingMuonIsGlobal_ = fLeadingMuonIsGlobal;}
    void SetLeadingMuonIsTracker(bool fLeadingMuonIsTracker)    {LeadingMuonIsTracker_ = fLeadingMuonIsTracker;}
    void SetLeadingMuonIsGood(bool fLeadingMuonIsGood) {LeadingMuonIsGood_ = fLeadingMuonIsGood;}
    void SetSecondMuonTrackerHits(double fSecondMuonTrackerHits)    {SecondMuonTrackerHits_ = fSecondMuonTrackerHits;}
    void SetSecondMuonPixelHits(double fSecondMuonPixelHits)    {SecondMuonPixelHits_ = fSecondMuonPixelHits;}
    void SetSecondMuonNormalizedChi2(double fSecondMuonNormalizedChi2)    {SecondMuonNormalizedChi2_ = fSecondMuonNormalizedChi2;}
    void SetSecondMuonMatchedStations(double fSecondMuonMatchedStations)    {SecondMuonMatchedStations_ = fSecondMuonMatchedStations;}
    void SetSecondMuonDxy(double fSecondMuonDxy)    {SecondMuonDxy_ = fSecondMuonDxy;}
    void SetSecondMuonDz(double fSecondMuonDz) {SecondMuonDz_ = fSecondMuonDz;}
    void SetSecondMuonIsGlobal(bool fSecondMuonIsGlobal)    {SecondMuonIsGlobal_ = fSecondMuonIsGlobal;}
    void SetSecondMuonIsTracker(bool fSecondMuonIsTracker)    {SecondMuonIsTracker_ = fSecondMuonIsTracker;}
    void SetSecondMuonIsGood(bool fSecondMuonIsGood) {SecondMuonIsGood_ = fSecondMuonIsGood;}

    void SetVertexMultiplicity(const std::vector<double>& fVertexMultiplicity) { VertexMultiplicity_ = fVertexMultiplicity; }
    void SetVertexChiNorm(const std::vector<double>& fVertexChiNorm) { VertexChiNorm_ = fVertexChiNorm; }
    void SetVertexNDOF(const std::vector<double>& fVertexNDOF) { VertexNDOF_ = fVertexNDOF; }
    void SetVz(const std::vector<double>& fVz) { Vz_ = fVz; }
    void SetVx(const std::vector<double>& fVx) { Vx_ = fVx; }
    void SetVy(const std::vector<double>& fVy) { Vy_ = fVy; }
    void SetTracksPt(const std::vector<std::vector<double> >& fTracksPt) { TracksPt_ = fTracksPt; }
    void SetTrackEtaMin(double ftracketamin)    { tracketamin_     = ftracketamin;}
    void SetTrackEtaMax(double ftracketamax)    { tracketamax_     = ftracketamax;}
    void SetZDCdigifC(const std::vector<std::vector<double> >& fZDCdigifC) { ZDCdigifC_ = fZDCdigifC; }

    void SetXiGenMinus(double fxigenminus)    { xigenminus_     = fxigenminus;}
    void SetXiGenPlus(double fxigenplus)    { xigenplus_     = fxigenplus;}

    void SetMxGenMinus(double fmxgenminus)    { mxgenminus_     = fmxgenminus;}
    void SetMxGenPlus(double fmxgenplus)    { mxgenplus_     = fmxgenplus;}
    void SetMx2GenMinus(double fmx2genminus)    { mx2genminus_     = fmx2genminus;}
    void SetMx2GenPlus(double fmx2genplus)    { mx2genplus_     = fmx2genplus;}
    void SetMxGenLeft(double fmxgenleft)    { mxgenleft_     = fmxgenleft;}
    void SetMxGenRight(double fmxgenright)    { mxgenright_     = fmxgenright;}
    void SetMx2GenLeft(double fmx2genleft)    { mx2genleft_     = fmx2genleft;}
    void SetMx2GenRight(double fmx2genright)    { mx2genright_     = fmx2genright;}
    void SetLrgGen(double flrggen)    { lrggen_     = flrggen;}
    void SetEtaMaxGen(double fetamaxgen)    { etamaxgen_     = fetamaxgen;}
    void SetEtaMinGen(double fetamingen)    { etamingen_     = fetamingen;}
    void SetEpluspzGen(double fepluspzgen)    { epluspzgen_     = fepluspzgen;}
    void SetEminuspzGen(double feminuspzgen)    { eminuspzgen_     = feminuspzgen;}
    void SetEtExpoPlusGen(double fetexpoplusgen)    { etexpoplusgen_     = fetexpoplusgen;}
    void SetEtExpoMinusGen(double fetexpominusgen)    { etexpominusgen_     = fetexpominusgen;}
    void SetSumECastorMinusGen(double fsumECastorMinusGen)    { sumECastorMinusGen_     = fsumECastorMinusGen;}
    void SetParticlesPDGidGen(const std::vector<double>& fparticlespdgidgen) { particlespdgidgen_ = fparticlespdgidgen; }
    void SetParticlesEnergyGen(const std::vector<double>& fparticlesenergygen) { particlesenergygen_ = fparticlesenergygen; }
    void SetParticlesEtaGen(const std::vector<double>& fparticlesetagen) { particlesetagen_ = fparticlesetagen; }
    void SetParticlesP4Gen(const std::vector< math::XYZTLorentzVector > fparticlesp4gen)    { particlesp4gen_     = fparticlesp4gen;}
    void SetNParticlesGen(int fnparticlesgen)    {nparticlesgen_ = fnparticlesgen;}
    void SetSumptGenLeft(double fsumptgenleft)    { sumptgenleft_     = fsumptgenleft;}
    void SetSumptGenRight(double fsumptgenright)    { sumptgenright_     = fsumptgenright;}

    void SetEpluspzGenLim(double fepluspzGenLim)    { epluspzGenLim_     = fepluspzGenLim;}
    void SetEminuspzGenLim(double feminuspzGenLim)    { eminuspzGenLim_     = feminuspzGenLim;}
    void SetEtExpoPlusGenLim(double fetexpoplusGenLim)    { etexpoplusGenLim_     = fetexpoplusGenLim;}
    void SetEtExpoMinusGenLim(double fetexpominusGenLim)    { etexpominusGenLim_     = fetexpominusGenLim;}     
    void SetMxGen(double fmxGen)    { mxGen_     = fmxGen;}
    void SetMx2Gen(double fmx2Gen)    { mx2Gen_     = fmx2Gen;}

    void SetMxGenMinusCMS(double fmxgenminusCMS)    { mxgenminusCMS_     = fmxgenminusCMS;}
    void SetMxGenPlusCMS(double fmxgenplusCMS)    { mxgenplusCMS_     = fmxgenplusCMS;}
    void SetMx2GenMinusCMS(double fmx2genminusCMS)    { mx2genminusCMS_     = fmx2genminusCMS;}
    void SetMx2GenPlusCMS(double fmx2genplusCMS)    { mx2genplusCMS_     = fmx2genplusCMS;}
    void SetMxGenLeftCMS(double fmxgenleftCMS)    { mxgenleftCMS_     = fmxgenleftCMS;}
    void SetMxGenRightCMS(double fmxgenrightCMS)    { mxgenrightCMS_     = fmxgenrightCMS;}
    void SetMx2GenLeftCMS(double fmx2genleftCMS)    { mx2genleftCMS_     = fmx2genleftCMS;}
    void SetMx2GenRightCMS(double fmx2genrightCMS)    { mx2genrightCMS_     = fmx2genrightCMS;}
    void SetLrgGenCMS(double flrggenCMS)    { lrggenCMS_     = flrggenCMS;}
    void SetEtaMaxGenCMS(double fetamaxgenCMS)    { etamaxgenCMS_     = fetamaxgenCMS;}
    void SetEtaMinGenCMS(double fetamingenCMS)    { etamingenCMS_     = fetamingenCMS;}
    void SetEpluspzGenCMS(double fepluspzgenCMS)    { epluspzgenCMS_     = fepluspzgenCMS;}
    void SetEminuspzGenCMS(double feminuspzgenCMS)    { eminuspzgenCMS_     = feminuspzgenCMS;}
    void SetEtExpoPlusGenCMS(double fetexpoplusgenCMS)    { etexpoplusgenCMS_     = fetexpoplusgenCMS;}
    void SetEtExpoMinusGenCMS(double fetexpominusgenCMS)    { etexpominusgenCMS_     = fetexpominusgenCMS;}
    void SetSumptGenLeftCMS(double fsumptgenleftCMS)    { sumptgenleftCMS_     = fsumptgenleftCMS;}
    void SetSumptGenRightCMS(double fsumptgenrightCMS)    { sumptgenrightCMS_     = fsumptgenrightCMS;}

    void SetDiElectronMassPF(double fDiElectronMassPF) { DiElectronMassPF_ = fDiElectronMassPF;}
    void SetDiMuonMassPF(double fDiMuonMassPF) { DiMuonMassPF_ = fDiMuonMassPF;}

    void SetSumEHFPlus(double fSumEHFPlus)    { SumEHFPlus_ = fSumEHFPlus;}
    void SetSumEHF_SPlus(double fSumEHF_SPlus)    { SumEHF_SPlus_ = fSumEHF_SPlus;}
    void SetSumEHF_LPlus(double fSumEHF_LPlus)    { SumEHF_LPlus_ = fSumEHF_LPlus;}
    void SetSumEtHFPlus(double fSumEtHFPlus)    { SumEtHFPlus_ = fSumEtHFPlus;}

    void SetSumEHFMinus(double fSumEHFMinus)    { SumEHFMinus_ = fSumEHFMinus;}
    void SetSumEHF_SMinus(double fSumEHF_SMinus)    { SumEHF_SMinus_ = fSumEHF_SMinus;}
    void SetSumEHF_LMinus(double fSumEHF_LMinus)    { SumEHF_LMinus_ = fSumEHF_LMinus;}
    void SetSumEtHFMinus(double fSumEtHFMinus)    { SumEtHFMinus_ = fSumEtHFMinus;}

    void SetSumEHEPlus(double fSumEHEPlus)    { SumEHEPlus_ = fSumEHEPlus;}
    void SetSumEtHEPlus(double fSumEtHEPlus)    { SumEtHEPlus_ = fSumEtHEPlus;}
    void SetSumEHEMinus(double fSumEHEMinus)    { SumEHEMinus_ = fSumEHEMinus;}
    void SetSumEtHEMinus(double fSumEtHEMinus)    { SumEtHEMinus_ = fSumEtHEMinus;}

    void SetSumEHBPlus(double fSumEHBPlus)    { SumEHBPlus_ = fSumEHBPlus;}
    void SetSumEtHBPlus(double fSumEtHBPlus)    { SumEtHBPlus_ = fSumEtHBPlus;}
    void SetSumEHBMinus(double fSumEHBMinus)    { SumEHBMinus_ = fSumEHBMinus;}
    void SetSumEtHBMinus(double fSumEtHBMinus)    { SumEtHBMinus_ = fSumEtHBMinus;}

    void SetSumEEEPlus(double fSumEEEPlus)    { SumEEEPlus_ = fSumEEEPlus;}
    void SetSumEtEEPlus(double fSumEtEEPlus)    { SumEtEEPlus_ = fSumEtEEPlus;}
    void SetSumEEEMinus(double fSumEEEMinus)    { SumEEEMinus_ = fSumEEEMinus;}
    void SetSumEtEEMinus(double fSumEtEEMinus)    { SumEtEEMinus_ = fSumEtEEMinus;}

    void SetSumEEBPlus(double fSumEEBPlus)    { SumEEBPlus_ = fSumEEBPlus;}
    void SetSumEtEBPlus(double fSumEtEBPlus)    { SumEtEBPlus_ = fSumEtEBPlus;}
    void SetSumEEBMinus(double fSumEEBMinus)    { SumEEBMinus_ = fSumEEBMinus;}
    void SetSumEtEBMinus(double fSumEtEBMinus)    { SumEtEBMinus_ = fSumEtEBMinus;}

    void SetEpluspzCalo(double fEPZCaloPlus)    { EPZCaloPlus_ = fEPZCaloPlus;}
    void SetEminuspzCalo(double fEPZCaloMinus)    { EPZCaloMinus_ = fEPZCaloMinus;}
    void SetEtExpoPlusCalo(double fEtEtaCaloPlus)    { EtEtaCaloPlus_ = fEtEtaCaloPlus;}
    void SetEtExpoMinusCalo(double fEtEtaCaloMinus)    { EtEtaCaloMinus_ = fEtEtaCaloMinus;}

    void SetEtaCaloMax(double fEtaCaloMax)    { EtaCaloMax_ = fEtaCaloMax;}
    void SetEtaCaloMin(double fEtaCaloMin)    { EtaCaloMin_ = fEtaCaloMin;}
    void SetLrgCalo(double flrgCalo)    { lrgCalo_     = flrgCalo;}

    void SetMultiplicityHFPlus(int fMultiplicityHFPlus)    { MultiplicityHFPlus_ = fMultiplicityHFPlus;}
    void SetMultiplicityHEPlus(int fMultiplicityHEPlus)    { MultiplicityHEPlus_ = fMultiplicityHEPlus;}
    void SetMultiplicityEEPlus(int fMultiplicityEEPlus)    { MultiplicityEEPlus_ = fMultiplicityEEPlus;}
    void SetMultiplicityHFMinus(int fMultiplicityHFMinus)    { MultiplicityHFMinus_ = fMultiplicityHFMinus;}
    void SetMultiplicityHEMinus(int fMultiplicityHEMinus)    { MultiplicityHEMinus_ = fMultiplicityHEMinus;}
    void SetMultiplicityEEMinus(int fMultiplicityEEMinus)    { MultiplicityEEMinus_ = fMultiplicityEEMinus;}

    void SetVertex(int fVertex)    { Vertex_ = fVertex;}
    void SetMxPFMinus(double fmxpfminus)    { mxpfminus_     = fmxpfminus;}
    void SetMxPFPlus(double fmxpfplus)    { mxpfplus_     = fmxpfplus;}  
    void SetMx2PFMinus(double fmx2pfminus)    { mx2pfminus_     = fmx2pfminus;}
    void SetMx2PFPlus(double fmx2pfplus)    { mx2pfplus_     = fmx2pfplus;}
    void SetEtaMaxPF(double fetamaxpf)    { etamaxpf_     = fetamaxpf;}
    void SetEtaMinPF(double fetaminpf)    { etaminpf_     = fetaminpf;}
    void SetEpluspzPF(double fepluspzpf)    { epluspzpf_     = fepluspzpf;}
    void SetEminuspzPF(double feminuspzpf)    { eminuspzpf_     = feminuspzpf;}
    void SetEtExpoPlusPF(double fetexpopluspf)    { etexpopluspf_     = fetexpopluspf;}
    void SetEtExpoMinusPF(double fetexpominuspf)    { etexpominuspf_     = fetexpominuspf;}
    void SetLrgPF(double flrgPF)    { lrgPF_     = flrgPF;}
    void SetMxPFLeft(double fmxpfleft)    { mxpfleft_     = fmxpfleft;}
    void SetMxPFRight(double fmxpfright)    { mxpfright_     = fmxpfright;}
    void SetMx2PFLeft(double fmx2pfleft)    { mx2pfleft_     = fmx2pfleft;}
    void SetMx2PFRight(double fmx2pfright)    { mx2pfright_     = fmx2pfright;}
    void SetSumptPFLeft(double fsumptpfleft)    { sumptpfleft_     = fsumptpfleft;}
    void SetSumptPFRight(double fsumptpfright)    { sumptpfright_     = fsumptpfright;}
    void SetSumEHFPlusPF(double fSumEHFPluspf)    { SumEHFPluspf_ = fSumEHFPluspf;}
    void SetSumEHFMinusPF(double fSumEHFMinuspf)    { SumEHFMinuspf_ = fSumEHFMinuspf;}
    void SetMxPF(double fmxpf)    { mxpf_     = fmxpf;}
    void SetMx2PF(double fmx2pf)    { mx2pf_     = fmx2pf;}

    void SetMxPFNoZMinus(double fmxpfnozminus)    { mxpfnozminus_     = fmxpfnozminus;} 
    void SetMxPFNoZPlus(double fmxpfnozplus)    { mxpfnozplus_     = fmxpfnozplus;}  
    void SetMx2PFNoZMinus(double fmx2pfnozminus)    { mx2pfnozminus_     = fmx2pfnozminus;}
    void SetMx2PFNoZPlus(double fmx2pfnozplus)    { mx2pfnozplus_     = fmx2pfnozplus;}
    void SetEtaMaxPFNoZ(double fetamaxpfnoz)    { etamaxpfnoz_     = fetamaxpfnoz;}
    void SetEtaMinPFNoZ(double fetaminpfnoz)    { etaminpfnoz_     = fetaminpfnoz;}
    void SetEpluspzPFNoZ(double fepluspzpfnoz)    { epluspzpfnoz_     = fepluspzpfnoz;}
    void SetEminuspzPFNoZ(double feminuspzpfnoz)    { eminuspzpfnoz_     = feminuspzpfnoz;}
    void SetEtExpoPlusPFNoZ(double fetexpopluspfnoz)    { etexpopluspfnoz_     = fetexpopluspfnoz;}
    void SetEtExpoMinusPFNoZ(double fetexpominuspfnoz)    { etexpominuspfnoz_     = fetexpominuspfnoz;}
    void SetLrgPFNoZ(double flrgPFnoz)    { lrgPFnoz_     = flrgPFnoz;}
    void SetMxPFNoZLeft(double fmxpfnozleft)    { mxpfnozleft_     = fmxpfnozleft;}
    void SetMxPFNoZRight(double fmxpfnozright)    { mxpfnozright_     = fmxpfnozright;}
    void SetMx2PFNoZLeft(double fmx2pfnozleft)    { mx2pfnozleft_     = fmx2pfnozleft;}
    void SetMx2PFNoZRight(double fmx2pfnozright)    { mx2pfnozright_     = fmx2pfnozright;}
    void SetSumptPFNoZLeft(double fsumptpfnozleft)    { sumptpfnozleft_     = fsumptpfnozleft;}
    void SetSumptPFNoZRight(double fsumptpfnozright)    { sumptpfnozright_     = fsumptpfnozright;}
    void SetMxPFNoZ(double fmxpfnoz)    { mxpfnoz_     = fmxpfnoz;}
    void SetMx2PFNoZ(double fmx2pfnoz)    { mx2pfnoz_     = fmx2pfnoz;}

    void SetPatNMuon(int fpatNMuon)    {patNMuon_ = fpatNMuon;}
    void SetPatMuon1Pt(double fpatMuon1Pt)    {patMuon1Pt_ = fpatMuon1Pt;}
    void SetPatMuon1Charge(int fpatMuon1Charge)    {patMuon1Charge_ = fpatMuon1Charge;}
    void SetPatMuon1Phi(double fpatMuon1Phi)    {patMuon1Phi_ = fpatMuon1Phi;}
    void SetPatMuon1Eta(double fpatMuon1Eta)    {patMuon1Eta_ = fpatMuon1Eta;}
    void SetPatMuon1Et(double fpatMuon1Et)    {patMuon1Et_ = fpatMuon1Et;}
    void SetPatMuon1P4(LorentzVector fpatMuon1P4)    {patMuon1P4_ = fpatMuon1P4;}

    void SetPatMuon2Pt(double fpatMuon2Pt)    {patMuon2Pt_ = fpatMuon2Pt;}
    void SetPatMuon2Charge(int fpatMuon2Charge)    {patMuon2Charge_ = fpatMuon2Charge;}
    void SetPatMuon2Phi(double fpatMuon2Phi)    {patMuon2Phi_ = fpatMuon2Phi;}
    void SetPatMuon2Eta(double fpatMuon2Eta)    {patMuon2Eta_ = fpatMuon2Eta;}
    void SetPatMuon2Et(double fpatMuon2Et)    {patMuon2Et_ = fpatMuon2Et;}
    void SetPatMuon2P4(LorentzVector fpatMuon2P4)    {patMuon2P4_ = fpatMuon2P4;}

    void SetPatMuon1SumPtR03(double fpatMuon1SumPtR03)    {patMuon1SumPtR03_ = fpatMuon1SumPtR03;}
    void SetPatMuon1EmEtR03(double fpatMuon1EmEtR03)    {patMuon1EmEtR03_ = fpatMuon1EmEtR03;}
    void SetPatMuon1HadEtR03(double fpatMuon1HadEtR03)    {patMuon1HadEtR03_ = fpatMuon1HadEtR03;}    
    void SetPatMuon1SumPtR05(double fpatMuon1SumPtR05)    {patMuon1SumPtR05_ = fpatMuon1SumPtR05;}
    void SetPatMuon1EmEtR05(double fpatMuon1EmEtR05)    {patMuon1EmEtR05_ = fpatMuon1EmEtR05;}
    void SetPatMuon1HadEtR05(double fpatMuon1HadEtR05)    {patMuon1HadEtR05_ = fpatMuon1HadEtR05;}    

    void SetPatMuon2SumPtR03(double fpatMuon2SumPtR03)    {patMuon2SumPtR03_ = fpatMuon2SumPtR03;}
    void SetPatMuon2EmEtR03(double fpatMuon2EmEtR03)    {patMuon2EmEtR03_ = fpatMuon2EmEtR03;}
    void SetPatMuon2HadEtR03(double fpatMuon2HadEtR03)    {patMuon2HadEtR03_ = fpatMuon2HadEtR03;}    
    void SetPatMuon2SumPtR05(double fpatMuon2SumPtR05)    {patMuon2SumPtR05_ = fpatMuon2SumPtR05;}
    void SetPatMuon2EmEtR05(double fpatMuon2EmEtR05)    {patMuon2EmEtR05_ = fpatMuon2EmEtR05;}
    void SetPatMuon2HadEtR05(double fpatMuon2HadEtR05)    {patMuon2HadEtR05_ = fpatMuon2HadEtR05;}  

    void SetPatMuon1relIsoDr03(double fpatMuon1relIsoDr03)    {patMuon1relIsoDr03_ = fpatMuon1relIsoDr03;}
    void SetPatMuon2relIsoDr03(double fpatMuon2relIsoDr03)    {patMuon2relIsoDr03_ = fpatMuon2relIsoDr03;}
    void SetPatMuon1relIsoDr05(double fpatMuon1relIsoDr05)    {patMuon1relIsoDr05_ = fpatMuon1relIsoDr05;}
    void SetPatMuon2relIsoDr05(double fpatMuon2relIsoDr05)    {patMuon2relIsoDr05_ = fpatMuon2relIsoDr05;}
    void SetPatMuon1relIso(double fpatMuon1relIso)    {patMuon1relIso_ = fpatMuon1relIso;}
    void SetPatMuon2relIso(double fpatMuon2relIso)    {patMuon2relIso_ = fpatMuon2relIso;}

    void SetPatMuon1TrackerHits(double fpatMuon1TrackerHits)    {patMuon1TrackerHits_ = fpatMuon1TrackerHits;}
    void SetPatMuon1PixelHits(double fpatMuon1PixelHits)    {patMuon1PixelHits_ = fpatMuon1PixelHits;}
    void SetPatMuon1NormalizedChi2(double fpatMuon1NormalizedChi2)    {patMuon1NormalizedChi2_ = fpatMuon1NormalizedChi2;}
    void SetPatMuon1MatchedStations(double fpatMuon1MatchedStations)    {patMuon1MatchedStations_ = fpatMuon1MatchedStations;}
    void SetPatMuon1Dxy(double fpatMuon1Dxy)    {patMuon1Dxy_ = fpatMuon1Dxy;}
    void SetPatMuon1Dz(double fpatMuon1Dz) {patMuon1Dz_ = fpatMuon1Dz;}
    void SetPatMuon1IsGlobal(bool fpatMuon1IsGlobal)    {patMuon1IsGlobal_ = fpatMuon1IsGlobal;}
    void SetPatMuon1IsTracker(bool fpatMuon1IsTracker)    {patMuon1IsTracker_ = fpatMuon1IsTracker;}
    void SetPatMuon1IsGood(bool fpatMuon1IsGood) {patMuon1IsGood_ = fpatMuon1IsGood;}
    void SetPatMuon2TrackerHits(double fpatMuon2TrackerHits)    {patMuon2TrackerHits_ = fpatMuon2TrackerHits;}
    void SetPatMuon2PixelHits(double fpatMuon2PixelHits)    {patMuon2PixelHits_ = fpatMuon2PixelHits;}
    void SetPatMuon2NormalizedChi2(double fpatMuon2NormalizedChi2)    {patMuon2NormalizedChi2_ = fpatMuon2NormalizedChi2;}
    void SetPatMuon2MatchedStations(double fpatMuon2MatchedStations)    {patMuon2MatchedStations_ = fpatMuon2MatchedStations;}
    void SetPatMuon2Dxy(double fpatMuon2Dxy)    {patMuon2Dxy_ = fpatMuon2Dxy;}
    void SetPatMuon2Dz(double fpatMuon2Dz) {patMuon2Dz_ = fpatMuon2Dz;}
    void SetPatMuon2IsGlobal(bool fpatMuon2IsGlobal)    {patMuon2IsGlobal_ = fpatMuon2IsGlobal;}
    void SetPatMuon2IsTracker(bool fpatMuon2IsTracker)    {patMuon2IsTracker_ = fpatMuon2IsTracker;}
    void SetPatMuon2IsGood(bool fpatMuon2IsGood) {patMuon2IsGood_ = fpatMuon2IsGood;}

    void SetPatDiMuonMass(double fpatDiMuonMass) { patDiMuonMass_ = fpatDiMuonMass;}
    void SetPatDiMuonPt(double fpatDiMuonPt) { patDiMuonPt_ = fpatDiMuonPt;}
    void SetPatDiMuonEta(double fpatDiMuonEta) { patDiMuonEta_ = fpatDiMuonEta;}
    void SetPatDiMuonPhi(double fpatDiMuonPhi) { patDiMuonPhi_ = fpatDiMuonPhi;}

    void SetPatNElectron(int fpatNElectron)    {patNElectron_ = fpatNElectron;}
    void SetPatElectron1Pt(double fpatElectron1Pt)    {patElectron1Pt_ = fpatElectron1Pt;}
    void SetPatElectron1Charge(int fpatElectron1Charge)    {patElectron1Charge_ = fpatElectron1Charge;}
    void SetPatElectron1Phi(double fpatElectron1Phi)    {patElectron1Phi_ = fpatElectron1Phi;}
    void SetPatElectron1Eta(double fpatElectron1Eta)    {patElectron1Eta_ = fpatElectron1Eta;}
    void SetPatElectron1Et(double fpatElectron1Et)    {patElectron1Et_ = fpatElectron1Et;}
    void SetPatElectron1P4(LorentzVector fpatElectron1P4)    {patElectron1P4_ = fpatElectron1P4;}

    void SetPatElectron2Pt(double fpatElectron2Pt)    {patElectron2Pt_ = fpatElectron2Pt;}
    void SetPatElectron2Charge(int fpatElectron2Charge)    {patElectron2Charge_ = fpatElectron2Charge;}
    void SetPatElectron2Phi(double fpatElectron2Phi)    {patElectron2Phi_ = fpatElectron2Phi;}
    void SetPatElectron2Eta(double fpatElectron2Eta)    {patElectron2Eta_ = fpatElectron2Eta;}
    void SetPatElectron2Et(double fpatElectron2Et)    {patElectron2Et_ = fpatElectron2Et;}
    void SetPatElectron2P4(LorentzVector fpatElectron2P4)    {patElectron2P4_ = fpatElectron2P4;}

    void SetPatElectron1TkDr03(double fpatElectron1TkDr03)    {patElectron1TkDr03_ = fpatElectron1TkDr03;}
    void SetPatElectron1EcalDr03(double fpatElectron1EcalDr03)    {patElectron1EcalDr03_ = fpatElectron1EcalDr03;}
    void SetPatElectron1HcalDr03(double fpatElectron1HcalDr03)    {patElectron1HcalDr03_ = fpatElectron1HcalDr03;}
    void SetPatElectron2TkDr03(double fpatElectron2TkDr03)    {patElectron2TkDr03_ = fpatElectron2TkDr03;}
    void SetPatElectron2EcalDr03(double fpatElectron2EcalDr03)    {patElectron2EcalDr03_ = fpatElectron2EcalDr03;}
    void SetPatElectron2HcalDr03(double fpatElectron2HcalDr03)    {patElectron2HcalDr03_ = fpatElectron2HcalDr03;}

    void SetPatElectron1TkDr04(double fpatElectron1TkDr04)    {patElectron1TkDr04_ = fpatElectron1TkDr04;}
    void SetPatElectron1EcalDr04(double fpatElectron1EcalDr04)    {patElectron1EcalDr04_ = fpatElectron1EcalDr04;}
    void SetPatElectron1HcalDr04(double fpatElectron1HcalDr04)    {patElectron1HcalDr04_ = fpatElectron1HcalDr04;}
    void SetPatElectron2TkDr04(double fpatElectron2TkDr04)    {patElectron2TkDr04_ = fpatElectron2TkDr04;}
    void SetPatElectron2EcalDr04(double fpatElectron2EcalDr04)    {patElectron2EcalDr04_ = fpatElectron2EcalDr04;}
    void SetPatElectron2HcalDr04(double fpatElectron2HcalDr04)    {patElectron2HcalDr04_ = fpatElectron2HcalDr04;}

    void SetPatElectron1relIsoDr03(double fpatElectron1relIsoDr03)    {patElectron1relIsoDr03_ = fpatElectron1relIsoDr03;}
    void SetPatElectron1relIsoDr04(double fpatElectron1relIsoDr04)    {patElectron1relIsoDr04_ = fpatElectron1relIsoDr04;}
    void SetPatElectron2relIsoDr03(double fpatElectron2relIsoDr03)    {patElectron2relIsoDr03_ = fpatElectron2relIsoDr03;}
    void SetPatElectron2relIsoDr04(double fpatElectron2relIsoDr04)    {patElectron2relIsoDr04_ = fpatElectron2relIsoDr04;}

    void SetPatDiElectronMass(double fpatDiElectronMass) { patDiElectronMass_ = fpatDiElectronMass;}
    void SetPatDiElectronPt(double fpatDiElectronPt) { patDiElectronPt_ = fpatDiElectronPt;}
    void SetPatDiElectronEta(double fpatDiElectronEta) { patDiElectronEta_ = fpatDiElectronEta;}
    void SetPatDiElectronPhi(double fpatDiElectronPhi) { patDiElectronPhi_ = fpatDiElectronPhi;}

    void SetCastorTowerEnergy(const std::vector<double>& fCastorTowerEnergy) { CastorTowerEnergy_ = fCastorTowerEnergy; }
    void SetCastorModule1Energy(const std::vector<double>& fCastorModule1Energy) { CastorModule1Energy_ = fCastorModule1Energy; }
    void SetCastorModule2Energy(const std::vector<double>& fCastorModule2Energy) { CastorModule2Energy_ = fCastorModule2Energy; }
    void SetCastorModule3Energy(const std::vector<double>& fCastorModule3Energy) { CastorModule3Energy_ = fCastorModule3Energy; }
    void SetCastorModule4Energy(const std::vector<double>& fCastorModule4Energy) { CastorModule4Energy_ = fCastorModule4Energy; }
    void SetCastorModule5Energy(const std::vector<double>& fCastorModule5Energy) { CastorModule5Energy_ = fCastorModule5Energy; }
    void SetCastorBadChannels(const std::vector<int>& fCastorBadChannels) { CastorBadChannels_ = fCastorBadChannels; }
    void SetCastorNumberBadChannels(int fCastorNumberBadChannels) { CastorNumberBadChannels_ = fCastorNumberBadChannels;}

    void SetEachTowerEta(const std::vector<double>& fEachTowerEta) { EachTowerEta_ = fEachTowerEta; }
    void SetEachTowerEnergy(const std::vector<double>& fEachTowerEnergy) { EachTowerEnergy_ = fEachTowerEnergy; }
    void SetEachTowerCounter(int fEachTowerCounter)    {EachTowerCounter_ = fEachTowerCounter;}

    void SetTracksNonConeLeadingMuonR03(int fTracksNonConeLeadingMuonR03)    {TracksNonConeLeadingMuonR03_ = fTracksNonConeLeadingMuonR03;}
    void SetTracksNonConeLeadingElectronR03(int fTracksNonConeLeadingElectronR03)    {TracksNonConeLeadingElectronR03_ = fTracksNonConeLeadingElectronR03;}
    void SetTracksNonConePatMuon1R03(int fTracksNonConePatMuon1R03)    {TracksNonConePatMuon1R03_ = fTracksNonConePatMuon1R03;}
    void SetTracksNonConePatElectron1R03(int fTracksNonConePatElectron1R03)    {TracksNonConePatElectron1R03_ = fTracksNonConePatElectron1R03;}

    void SetTracksNonConeLeadingMuonR04(int fTracksNonConeLeadingMuonR04)    {TracksNonConeLeadingMuonR04_ = fTracksNonConeLeadingMuonR04;}
    void SetTracksNonConeLeadingElectronR04(int fTracksNonConeLeadingElectronR04)    {TracksNonConeLeadingElectronR04_ = fTracksNonConeLeadingElectronR04;}
    void SetTracksNonConePatMuon1R04(int fTracksNonConePatMuon1R04)    {TracksNonConePatMuon1R04_ = fTracksNonConePatMuon1R04;}
    void SetTracksNonConePatElectron1R04(int fTracksNonConePatElectron1R04)    {TracksNonConePatElectron1R04_ = fTracksNonConePatElectron1R04;}

    void SetTracksNonConeLeadingMuonR05(int fTracksNonConeLeadingMuonR05)    {TracksNonConeLeadingMuonR05_ = fTracksNonConeLeadingMuonR05;}
    void SetTracksNonConeLeadingElectronR05(int fTracksNonConeLeadingElectronR05)    {TracksNonConeLeadingElectronR05_ = fTracksNonConeLeadingElectronR05;}
    void SetTracksNonConePatMuon1R05(int fTracksNonConePatMuon1R05)    {TracksNonConePatMuon1R05_ = fTracksNonConePatMuon1R05;}
    void SetTracksNonConePatElectron1R05(int fTracksNonConePatElectron1R05)    {TracksNonConePatElectron1R05_ = fTracksNonConePatElectron1R05;}

    void SetTracksNonConeSecondMuonR03(int fTracksNonConeSecondMuonR03)    {TracksNonConeSecondMuonR03_ = fTracksNonConeSecondMuonR03;}
    void SetTracksNonConeSecondElectronR03(int fTracksNonConeSecondElectronR03)    {TracksNonConeSecondElectronR03_ = fTracksNonConeSecondElectronR03;}
    void SetTracksNonConePatMuon2R03(int fTracksNonConePatMuon2R03)    {TracksNonConePatMuon2R03_ = fTracksNonConePatMuon2R03;}
    void SetTracksNonConePatElectron2R03(int fTracksNonConePatElectron2R03)    {TracksNonConePatElectron2R03_ = fTracksNonConePatElectron2R03;}

    void SetTracksNonConeSecondMuonR04(int fTracksNonConeSecondMuonR04)    {TracksNonConeSecondMuonR04_ = fTracksNonConeSecondMuonR04;}
    void SetTracksNonConeSecondElectronR04(int fTracksNonConeSecondElectronR04)    {TracksNonConeSecondElectronR04_ = fTracksNonConeSecondElectronR04;}
    void SetTracksNonConePatMuon2R04(int fTracksNonConePatMuon2R04)    {TracksNonConePatMuon2R04_ = fTracksNonConePatMuon2R04;}
    void SetTracksNonConePatElectron2R04(int fTracksNonConePatElectron2R04)    {TracksNonConePatElectron2R04_ = fTracksNonConePatElectron2R04;}

    void SetTracksNonConeSecondMuonR05(int fTracksNonConeSecondMuonR05)    {TracksNonConeSecondMuonR05_ = fTracksNonConeSecondMuonR05;}
    void SetTracksNonConeSecondElectronR05(int fTracksNonConeSecondElectronR05)    {TracksNonConeSecondElectronR05_ = fTracksNonConeSecondElectronR05;}
    void SetTracksNonConePatMuon2R05(int fTracksNonConePatMuon2R05)    {TracksNonConePatMuon2R05_ = fTracksNonConePatMuon2R05;}
    void SetTracksNonConePatElectron2R05(int fTracksNonConePatElectron2R05)    {TracksNonConePatElectron2R05_ = fTracksNonConePatElectron2R05;}

    void SetLeadingElectronDeltaPhiTkClu(double fLeadingElectronDeltaPhiTkClu)    {LeadingElectronDeltaPhiTkClu_ = fLeadingElectronDeltaPhiTkClu;}
    void SetLeadingElectronDeltaEtaTkClu(double fLeadingElectronDeltaEtaTkClu)    {LeadingElectronDeltaEtaTkClu_ = fLeadingElectronDeltaEtaTkClu;}
    void SetLeadingElectronSigmaIeIe(double fLeadingElectronSigmaIeIe)    {LeadingElectronSigmaIeIe_ = fLeadingElectronSigmaIeIe;}
    void SetLeadingElectronDCot(double fLeadingElectronDCot)    {LeadingElectronDCot_ = fLeadingElectronDCot;}
    void SetLeadingElectronDist(double fLeadingElectronDist)    {LeadingElectronDist_ = fLeadingElectronDist;}
    void SetLeadingElectronInnerHits(double fLeadingElectronInnerHits)    {LeadingElectronInnerHits_ = fLeadingElectronInnerHits;}
    void SetLeadingElectronHE(double fLeadingElectronHE)    {LeadingElectronHE_ = fLeadingElectronHE;}
    void SetLeadingElectronIsWP95(bool fLeadingElectronIsWP95) {LeadingElectronIsWP95_ = fLeadingElectronIsWP95;}
    void SetLeadingElectronIsWP80(bool fLeadingElectronIsWP80) {LeadingElectronIsWP80_ = fLeadingElectronIsWP80;}

    void SetSecondElectronDeltaPhiTkClu(double fSecondElectronDeltaPhiTkClu)    {SecondElectronDeltaPhiTkClu_ = fSecondElectronDeltaPhiTkClu;}
    void SetSecondElectronDeltaEtaTkClu(double fSecondElectronDeltaEtaTkClu)    {SecondElectronDeltaEtaTkClu_ = fSecondElectronDeltaEtaTkClu;}
    void SetSecondElectronSigmaIeIe(double fSecondElectronSigmaIeIe)    {SecondElectronSigmaIeIe_ = fSecondElectronSigmaIeIe;}
    void SetSecondElectronDCot(double fSecondElectronDCot)    {SecondElectronDCot_ = fSecondElectronDCot;}
    void SetSecondElectronDist(double fSecondElectronDist)    {SecondElectronDist_ = fSecondElectronDist;}
    void SetSecondElectronInnerHits(double fSecondElectronInnerHits)    {SecondElectronInnerHits_ = fSecondElectronInnerHits;}
    void SetSecondElectronHE(double fSecondElectronHE)    {SecondElectronHE_ = fSecondElectronHE;}
    void SetSecondElectronIsWP95(bool fSecondElectronIsWP95) {SecondElectronIsWP95_ = fSecondElectronIsWP95;}
    void SetSecondElectronIsWP80(bool fSecondElectronIsWP80) {SecondElectronIsWP80_ = fSecondElectronIsWP80;}

    void SetPatElectron1DeltaPhiTkClu(double fpatElectron1DeltaPhiTkClu)    {patElectron1DeltaPhiTkClu_ = fpatElectron1DeltaPhiTkClu;}
    void SetPatElectron1DeltaEtaTkClu(double fpatElectron1DeltaEtaTkClu)    {patElectron1DeltaEtaTkClu_ = fpatElectron1DeltaEtaTkClu;}
    void SetPatElectron1SigmaIeIe(double fpatElectron1SigmaIeIe)    {patElectron1SigmaIeIe_ = fpatElectron1SigmaIeIe;}
    void SetPatElectron1DCot(double fpatElectron1DCot)    {patElectron1DCot_ = fpatElectron1DCot;}
    void SetPatElectron1Dist(double fpatElectron1Dist)    {patElectron1Dist_ = fpatElectron1Dist;}
    void SetPatElectron1InnerHits(double fpatElectron1InnerHits)    {patElectron1InnerHits_ = fpatElectron1InnerHits;}
    void SetPatElectron1HE(double fpatElectron1HE)    {patElectron1HE_ = fpatElectron1HE;}
    void SetPatElectron1IsWP95(bool fpatElectron1IsWP95) {patElectron1IsWP95_ = fpatElectron1IsWP95;}
    void SetPatElectron1IsWP80(bool fpatElectron1IsWP80) {patElectron1IsWP80_ = fpatElectron1IsWP80;}

    void SetPatElectron2DeltaPhiTkClu(double fpatElectron2DeltaPhiTkClu)    {patElectron2DeltaPhiTkClu_ = fpatElectron2DeltaPhiTkClu;}
    void SetPatElectron2DeltaEtaTkClu(double fpatElectron2DeltaEtaTkClu)    {patElectron2DeltaEtaTkClu_ = fpatElectron2DeltaEtaTkClu;}
    void SetPatElectron2SigmaIeIe(double fpatElectron2SigmaIeIe)    {patElectron2SigmaIeIe_ = fpatElectron2SigmaIeIe;}
    void SetPatElectron2DCot(double fpatElectron2DCot)    {patElectron2DCot_ = fpatElectron2DCot;}
    void SetPatElectron2Dist(double fpatElectron2Dist)    {patElectron2Dist_ = fpatElectron2Dist;}
    void SetPatElectron2InnerHits(double fpatElectron2InnerHits)    {patElectron2InnerHits_ = fpatElectron2InnerHits;}
    void SetPatElectron2HE(double fpatElectron2HE)    {patElectron2HE_ = fpatElectron2HE;}
    void SetPatElectron2IsWP95(bool fpatElectron2IsWP95) {patElectron2IsWP95_ = fpatElectron2IsWP95;}
    void SetPatElectron2IsWP80(bool fpatElectron2IsWP80) {patElectron2IsWP80_ = fpatElectron2IsWP80;}

    void SetDVtxMuon(double fdvtxmuon) { dvtxmuon_ = fdvtxmuon;}
    void SetDVtxMuonZ(double fdvtxmuonZ) { dvtxmuonZ_ = fdvtxmuonZ;}
    void SetDVtxElectron(double fdvtxelectron) { dvtxelectron_ = fdvtxelectron;}
    void SetDVtxElectronZ(double fdvtxelectronZ) { dvtxelectronZ_ = fdvtxelectronZ;}
    void SetDMuonElectron(double fdmuonelectron) { dmuonelectron_ = fdmuonelectron;}
    void SetDMuonElectronZ(double fdmuonelectronZ) { dmuonelectronZ_ = fdmuonelectronZ;}
    void SetDMuons(double fdmuons) { dmuons_ = fdmuons;}
    void SetDMuonsZ(double fdmuonsZ) { dmuonsZ_ = fdmuonsZ;}
    void SetDElectrons(double fdelectrons) { delectrons_ = fdelectrons;}
    void SetDElectronsZ(double fdelectronsZ) { delectronsZ_ = fdelectronsZ;}

    void SetGenLeadingElectronPt(double fGenLeadingElectronPt)    { GenLeadingElectronPt_     = fGenLeadingElectronPt;}
    void SetGenLeadingElectronEta(double fGenLeadingElectronEta)  { GenLeadingElectronEta_     = fGenLeadingElectronEta;}
    void SetGenLeadingElectronPhi(double fGenLeadingElectronPhi)  { GenLeadingElectronPhi_    = fGenLeadingElectronPhi;}
    void SetGenLeadingElectronP4(LorentzVector fGenLeadingElectronP4)    { GenLeadingElectronP4_     = fGenLeadingElectronP4;}
    void SetGenSecondElectronPt(double fGenSecondElectronPt)    { GenSecondElectronPt_     = fGenSecondElectronPt;}
    void SetGenSecondElectronEta(double fGenSecondElectronEta)  { GenSecondElectronEta_     = fGenSecondElectronEta;}
    void SetGenSecondElectronPhi(double fGenSecondElectronPhi)  { GenSecondElectronPhi_    = fGenSecondElectronPhi;}
    void SetGenSecondElectronP4(LorentzVector fGenSecondElectronP4)    { GenSecondElectronP4_     = fGenSecondElectronP4;}

    void SetGenLeadingMuonPt(double fGenLeadingMuonPt)    { GenLeadingMuonPt_     = fGenLeadingMuonPt;}
    void SetGenLeadingMuonEta(double fGenLeadingMuonEta)  { GenLeadingMuonEta_     = fGenLeadingMuonEta;}
    void SetGenLeadingMuonPhi(double fGenLeadingMuonPhi)  { GenLeadingMuonPhi_    = fGenLeadingMuonPhi;}
    void SetGenLeadingMuonP4(LorentzVector fGenLeadingMuonP4)    { GenLeadingMuonP4_     = fGenLeadingMuonP4;}
    void SetGenSecondMuonPt(double fGenSecondMuonPt)    { GenSecondMuonPt_     = fGenSecondMuonPt;}
    void SetGenSecondMuonEta(double fGenSecondMuonEta)  { GenSecondMuonEta_     = fGenSecondMuonEta;}
    void SetGenSecondMuonPhi(double fGenSecondMuonPhi)  { GenSecondMuonPhi_    = fGenSecondMuonPhi;}
    void SetGenSecondMuonP4(LorentzVector fGenSecondMuonP4)    { GenSecondMuonP4_     = fGenSecondMuonP4;}

    int GetHLTPath(int idx) const { return hltTrigResults_[idx]; }
    double GetDiElectronMass() const {return DiElectronMass_;}
    double GetDiElectronPt() const {return DiElectronPt_;}
    double GetDiElectronEta() const {return DiElectronEta_;}
    double GetDiElectronPhi() const {return DiElectronPhi_;}
    double GetDiMuonMass() const {return DiMuonMass_;}
    double GetDiMuonPt() const {return DiMuonPt_;}
    double GetDiMuonEta() const {return DiMuonEta_;}
    double GetDiMuonPhi() const {return DiMuonPhi_;}

    double GetLeadingElectronPt() const {return LeadingElectronPt_;}
    double GetLeadingElectronEta() const {return LeadingElectronEta_;}
    double GetLeadingElectronPhi() const {return LeadingElectronPhi_;}
    const LorentzVector& GetLeadingElectronP4() const {return LeadingElectronP4_;}
    int GetLeadingElectronCharge() const {return LeadingElectronCharge_;}
    double GetSecondElectronPt() const {return SecondElectronPt_;}
    double GetSecondElectronEta() const {return SecondElectronEta_;}
    double GetSecondElectronPhi() const {return SecondElectronPhi_;}
    const LorentzVector& GetSecondElectronP4() const {return SecondElectronP4_;}
    int GetSecondElectronCharge() const {return SecondElectronCharge_;}
    int GetElectronsN() const {return ElectronsN_;}
    double GetLeadingElectronTkDr03() const {return LeadingElectronTkDr03_;}
    double GetLeadingElectronEcalDr03() const {return LeadingElectronEcalDr03_;}
    double GetLeadingElectronHcalDr03() const {return LeadingElectronHcalDr03_;}
    double GetSecondElectronTkDr03() const {return SecondElectronTkDr03_;}
    double GetSecondElectronEcalDr03() const {return SecondElectronEcalDr03_;}
    double GetSecondElectronHcalDr03() const {return SecondElectronHcalDr03_;}

    double GetLeadingElectronTkDr04() const {return LeadingElectronTkDr04_;}
    double GetLeadingElectronEcalDr04() const {return LeadingElectronEcalDr04_;}
    double GetLeadingElectronHcalDr04() const {return LeadingElectronHcalDr04_;}
    double GetSecondElectronTkDr04() const {return SecondElectronTkDr04_;}
    double GetSecondElectronEcalDr04() const {return SecondElectronEcalDr04_;}
    double GetSecondElectronHcalDr04() const {return SecondElectronHcalDr04_;}

    double GetLeadingElectronrelIsoDr03() const {return LeadingElectronrelIsoDr03_;}
    double GetLeadingElectronrelIsoDr04() const {return LeadingElectronrelIsoDr04_;}
    double GetSecondElectronrelIsoDr03() const {return SecondElectronrelIsoDr03_;}
    double GetSecondElectronrelIsoDr04() const {return SecondElectronrelIsoDr04_;}

    double GetLeadingMuonPt() const {return LeadingMuonPt_;}
    double GetLeadingMuonEta() const {return LeadingMuonEta_;}
    double GetLeadingMuonPhi() const {return LeadingMuonPhi_;}
    const LorentzVector& GetLeadingMuonP4() const {return LeadingMuonP4_;}
    int GetLeadingMuonCharge() const {return LeadingMuonCharge_;}
    double GetSecondMuonPt() const {return SecondMuonPt_;}
    double GetSecondMuonEta() const {return SecondMuonEta_;}
    double GetSecondMuonPhi() const {return SecondMuonPhi_;}
    const LorentzVector& GetSecondMuonP4() const {return SecondMuonP4_;}
    int GetSecondMuonCharge() const {return SecondMuonCharge_;}
    int GetMuonsN() const {return MuonsN_;}

    double GetLeadingMuonSumPtR03() const {return LeadingMuonSumPtR03_;}
    double GetLeadingMuonEmEtR03() const {return LeadingMuonEmEtR03_;}
    double GetLeadingMuonHadEtR03() const {return LeadingMuonHadEtR03_;}
    double GetLeadingMuonSumPtR05() const {return LeadingMuonSumPtR05_;}
    double GetLeadingMuonEmEtR05() const {return LeadingMuonEmEtR05_;}
    double GetLeadingMuonHadEtR05() const {return LeadingMuonHadEtR05_;}

    double GetSecondMuonSumPtR03() const {return SecondMuonSumPtR03_;}
    double GetSecondMuonEmEtR03() const {return SecondMuonEmEtR03_;}
    double GetSecondMuonHadEtR03() const {return SecondMuonHadEtR03_;}
    double GetSecondMuonSumPtR05() const {return SecondMuonSumPtR05_;}
    double GetSecondMuonEmEtR05() const {return SecondMuonEmEtR05_;}
    double GetSecondMuonHadEtR05() const {return SecondMuonHadEtR05_;}

    double GetLeadingMuonrelIsoDr03() const {return LeadingMuonrelIsoDr03_;}
    double GetSecondMuonrelIsoDr03() const {return SecondMuonrelIsoDr03_;}
    double GetLeadingMuonrelIsoDr05() const {return LeadingMuonrelIsoDr05_;}
    double GetSecondMuonrelIsoDr05() const {return SecondMuonrelIsoDr05_;}
    double GetLeadingMuonTrackerHits() const {return LeadingMuonTrackerHits_;}
    double GetLeadingMuonPixelHits() const {return LeadingMuonPixelHits_;}
    double GetLeadingMuonNormalizedChi2() const {return LeadingMuonNormalizedChi2_;}
    double GetLeadingMuonMatchedStations() const {return LeadingMuonMatchedStations_;}
    double GetLeadingMuonDxy() const {return LeadingMuonDxy_;}
    double GetLeadingMuonDz() const {return LeadingMuonDz_;}
    bool GetLeadingMuonIsGlobal() const {return LeadingMuonIsGlobal_;}
    bool GetLeadingMuonIsTracker() const {return LeadingMuonIsTracker_;}
    bool GetLeadingMuonIsGood() const {return LeadingMuonIsGood_;}
    double GetSecondMuonTrackerHits() const {return SecondMuonTrackerHits_;}
    double GetSecondMuonPixelHits() const {return SecondMuonPixelHits_;}
    double GetSecondMuonNormalizedChi2() const {return SecondMuonNormalizedChi2_;}
    double GetSecondMuonMatchedStations() const {return SecondMuonMatchedStations_;}
    double GetSecondMuonDxy() const {return SecondMuonDxy_;}
    double GetSecondMuonDz() const {return SecondMuonDz_;}
    bool GetSecondMuonIsGlobal() const {return SecondMuonIsGlobal_;}
    bool GetSecondMuonIsTracker() const {return SecondMuonIsTracker_;}
    bool GetSecondMuonIsGood() const {return SecondMuonIsGood_;}

    double GetVertexMultiplicity(int i) const { return VertexMultiplicity_[i]; }
    double GetVertexChiNorm(int i) const { return VertexChiNorm_[i]; }
    double GetVertexNDOF(int i) const { return VertexNDOF_[i]; }
    double GetVz(int i) const { return Vz_[i]; }
    double GetVx(int i) const { return Vx_[i]; }
    double GetVy(int i) const { return Vy_[i]; }
    double GetTracksPt(int i,int j) const { return TracksPt_[i][j]; }
    double GetTrackEtaMin() const {return tracketamin_;}
    double GetTrackEtaMax() const {return tracketamax_;}
    double GetZDCdigifC(int i,int j) const { return ZDCdigifC_[i][j]; }

    double GetXiGenMinus() const {return xigenminus_;}
    double GetXiGenPlus() const {return xigenplus_;}

    double GetMxGenMinus() const { return mxgenminus_;}
    double GetMxGenPlus() const { return mxgenplus_;}
    double GetMx2GenMinus() const { return mx2genminus_;}
    double GetMx2GenPlus() const { return mx2genplus_;}
    double GetMxGenLeft() const { return mxgenleft_;}
    double GetMxGenRight() const { return mxgenright_;}
    double GetMx2GenLeft() const { return mx2genleft_;}
    double GetMx2GenRight() const { return mx2genright_;}
    double GetLrgGen() const { return lrggen_;}
    double GetEtaMaxGen() const { return etamaxgen_;}
    double GetEtaMinGen() const { return etamingen_;}
    double GetEpluspzGen() const { return epluspzgen_;}
    double GetEminuspzGen() const { return eminuspzgen_;}
    double GetEtExpoPlusGen() const { return etexpoplusgen_;}
    double GetEtExpoMinusGen() const { return etexpominusgen_;}
    double GetSumECastorMinusGen() const { return sumECastorMinusGen_;}
    double GetParticlesPDGidGen(int i) const { return particlespdgidgen_[i]; }
    double GetParticlesEnergyGen(int i) const { return particlesenergygen_[i]; }
    double GetParticlesEtaGen(int i) const { return particlesetagen_[i]; }
    const LorentzVector& GetParticlesP4Gen(int i) const {return particlesp4gen_[i];}
    int GetNParticlesGen() const {return nparticlesgen_;}

    double GetSumptGenLeft() const { return sumptgenleft_;}
    double GetSumptGenRight() const { return sumptgenright_;}

    double GetEpluspzGenLim() const { return epluspzGenLim_;}
    double GetEminuspzGenLim() const { return eminuspzGenLim_;}
    double GetEtExpoPlusGenLim() const { return etexpoplusGenLim_;}
    double GetEtExpoMinusGenLim() const { return etexpominusGenLim_;}   
    double GetMxGen() const { return mxGen_;}
    double GetMx2Gen() const { return mx2Gen_;}

    double GetMxGenMinusCMS() const { return mxgenminusCMS_;}
    double GetMxGenPlusCMS() const { return mxgenplusCMS_;}
    double GetMx2GenMinusCMS() const { return mx2genminusCMS_;}
    double GetMx2GenPlusCMS() const { return mx2genplusCMS_;}
    double GetMxGenLeftCMS() const { return mxgenleftCMS_;}
    double GetMxGenRightCMS() const { return mxgenrightCMS_;}
    double GetMx2GenLeftCMS() const { return mx2genleftCMS_;}
    double GetMx2GenRightCMS() const { return mx2genrightCMS_;}
    double GetLrgGenCMS() const { return lrggenCMS_;}
    double GetEtaMaxGenCMS() const { return etamaxgenCMS_;}
    double GetEtaMinGenCMS() const { return etamingenCMS_;}
    double GetEpluspzGenCMS() const { return epluspzgenCMS_;}
    double GetEminuspzGenCMS() const { return eminuspzgenCMS_;}
    double GetEtExpoPlusGenCMS() const { return etexpoplusgenCMS_;}
    double GetEtExpoMinusGenCMS() const { return etexpominusgenCMS_;}
    double GetSumptGenLeftCMS() const { return sumptgenleftCMS_;}
    double GetSumptGenRightCMS() const { return sumptgenrightCMS_;}

    double GetDiElectronMassPF() const {return DiElectronMassPF_;}
    double GetDiMuonMassPF() const {return DiMuonMassPF_;}

    double GetSumEHFPlus() const {return SumEHFPlus_;}
    double GetSumEHF_SPlus() const {return SumEHF_SPlus_;}
    double GetSumEHF_LPlus() const {return SumEHF_LPlus_;}
    double GetSumEtHFPlus() const {return SumEtHFPlus_;}

    double GetSumEHFMinus() const {return SumEHFMinus_;}
    double GetSumEHF_SMinus() const {return SumEHF_SMinus_;}
    double GetSumEHF_LMinus() const {return SumEHF_LMinus_;}
    double GetSumEtHFMinus() const {return SumEtHFMinus_;}

    double GetSumEHEPlus() const {return SumEHEPlus_;}
    double GetSumEtHEPlus() const {return SumEtHEPlus_;}
    double GetSumEHEMinus() const {return SumEHEMinus_;}
    double GetSumEtHEMinus() const {return SumEtHEMinus_;}

    double GetSumEHBPlus() const {return SumEHBPlus_;}
    double GetSumEtHBPlus() const {return SumEtHBPlus_;}
    double GetSumEHBMinus() const {return SumEHBMinus_;}
    double GetSumEtHBMinus() const {return SumEtHBMinus_;}

    double GetSumEEEPlus() const {return SumEEEPlus_;}
    double GetSumEtEEPlus() const {return SumEtEEPlus_;}
    double GetSumEEEMinus() const {return SumEEEMinus_;}
    double GetSumEtEEMinus() const {return SumEtEEMinus_;}

    double GetSumEEBPlus() const {return SumEEBPlus_;}
    double GetSumEtEBPlus() const {return SumEtEBPlus_;}
    double GetSumEEBMinus() const {return SumEEBMinus_;}
    double GetSumEtEBMinus() const {return SumEtEBMinus_;}

    double GetEpluspzCalo() const {return EPZCaloPlus_;}
    double GetEminuspzCalo() const {return EPZCaloMinus_;}
    double GetEtExpoPlusCalo() const {return EtEtaCaloPlus_;}
    double GetEtExpoPlusMinus() const {return EtEtaCaloMinus_;}

    double GetEtaCaloMax() const {return EtaCaloMax_;}
    double GetEtaCaloMin() const {return EtaCaloMin_;}
    double GetLrgCalo() const { return lrgCalo_;}

    int GetMultiplicityHFPlus() const {return MultiplicityHFPlus_;}
    int GetMultiplicityHEPlus() const {return MultiplicityHEPlus_;}
    int GetMultiplicityEEPlus() const {return MultiplicityEEPlus_;}
    int GetMultiplicityHFMinus() const {return MultiplicityHFMinus_;}
    int GetMultiplicityHEMinus() const {return MultiplicityHEMinus_;}
    int GetMultiplicityEEMinus() const {return MultiplicityEEMinus_;}

    int GetVertex() const {return Vertex_;}   
    double GetMxPFMinus() const { return mxpfminus_;}
    double GetMxPFPlus() const { return mxpfplus_;}
    double GetMx2PFMinus() const { return mx2pfminus_;}
    double GetMx2PFPlus() const { return mx2pfplus_;}
    double GetEtaMaxPF() const { return etamaxpf_;}
    double GetEtaMinPF() const { return etaminpf_;}
    double GetEpluspzPF() const { return epluspzpf_;}
    double GetEminuspzPF() const { return eminuspzpf_;}
    double GetEtExpoPlusPF() const { return etexpopluspf_;}
    double GetEtExpoMinusPF() const { return etexpominuspf_;}
    double GetLrgPF() const { return lrgPF_;}
    double GetMxPFLeft() const { return mxpfleft_;}
    double GetMxPFRight() const { return mxpfright_;}
    double GetMx2PFLeft() const { return mx2pfleft_;}
    double GetMx2PFRight() const { return mx2pfright_;}
    double GetSumptPFLeft() const { return sumptpfleft_;}
    double GetSumptPFRight() const { return sumptpfright_;}
    double GetSumEHFPlusPF() const {return SumEHFPluspf_;}
    double GetSumEHFMinusPF() const {return SumEHFMinuspf_;}
    double GetMxPF() const { return mxpf_;}
    double GetMx2PF() const { return mx2pf_;}

    double GetMxPFNoZMinus() const { return mxpfnozminus_;}
    double GetMxPFNoZPlus() const { return mxpfnozplus_;}
    double GetMx2PFNoZMinus() const { return mx2pfnozminus_;}
    double GetMx2PFNoZPlus() const { return mx2pfnozplus_;}
    double GetEtaMaxPFNoZ() const { return etamaxpfnoz_;}
    double GetEtaMinPFNoZ() const { return etaminpfnoz_;}
    double GetEpluspzPFNoZ() const { return epluspzpfnoz_;}
    double GetEminuspzPFNoZ() const { return eminuspzpfnoz_;}
    double GetEtExpoPlusPFNoZ() const { return etexpopluspfnoz_;}
    double GetEtExpoMinusPFNoZ() const { return etexpominuspfnoz_;}
    double GetLrgPFNoZ() const { return lrgPFnoz_;}
    double GetMxPFNoZLeft() const { return mxpfnozleft_;}
    double GetMxPFNoZRight() const { return mxpfnozright_;}
    double GetMx2PFNoZLeft() const { return mx2pfnozleft_;}
    double GetMx2PFNoZRight() const { return mx2pfnozright_;}
    double GetSumptPFNoZLeft() const { return sumptpfnozleft_;}
    double GetSumptPFNoZRight() const { return sumptpfnozright_;}
    double GetMxPFNoZ() const { return mxpfnoz_;}
    double GetMx2PFNoZ() const { return mx2pfnoz_;}

    int GetPatNMuon() const {return patNMuon_;}
    double GetPatMuon1Pt() const {return patMuon1Pt_;}
    int GetPatMuon1Charge() const {return patMuon1Charge_;}
    double GetPatMuon1Phi() const {return patMuon1Phi_;}
    double GetPatMuon1Eta() const {return patMuon1Eta_;}
    double GetPatMuon1Et() const {return patMuon1Et_;}
    const LorentzVector& GetPatMuon1P4() const {return patMuon1P4_;}

    double GetPatMuon2Pt() const {return patMuon2Pt_;}
    int GetPatMuon2Charge() const {return patMuon2Charge_;}
    double GetPatMuon2Phi() const {return patMuon2Phi_;}
    double GetPatMuon2Eta() const {return patMuon2Eta_;}
    double GetPatMuon2Et() const {return patMuon2Et_;}
    const LorentzVector& GetPatMuon2P4() const {return patMuon2P4_;}

    double GetPatMuon1SumPtR03() const {return patMuon1SumPtR03_;}
    double GetPatMuon1EmEtR03() const {return patMuon1EmEtR03_;}
    double GetPatMuon1HadEtR03() const {return patMuon1HadEtR03_;}    
    double GetPatMuon1SumPtR05() const {return patMuon1SumPtR05_;}
    double GetPatMuon1EmEtR05() const {return patMuon1EmEtR05_;}
    double GetPatMuon1HadEtR05() const {return patMuon1HadEtR05_;}    

    double GetPatMuon2SumPtR03() const {return patMuon2SumPtR03_;}
    double GetPatMuon2EmEtR03() const {return patMuon2EmEtR03_;}
    double GetPatMuon2HadEtR03() const {return patMuon2HadEtR03_;}    
    double GetPatMuon2SumPtR05() const {return patMuon2SumPtR05_;}
    double GetPatMuon2EmEtR05() const {return patMuon2EmEtR05_;}
    double GetPatMuon2HadEtR05() const {return patMuon2HadEtR05_;}  

    double GetPatMuon1relIsoDr03() const {return patMuon1relIsoDr03_;}
    double GetPatMuon2relIsoDr03() const {return patMuon2relIsoDr03_;}
    double GetPatMuon1relIsoDr05() const {return patMuon1relIsoDr05_;}
    double GetPatMuon2relIsoDr05() const {return patMuon2relIsoDr05_;}

    double GetPatMuon1relIso() const {return patMuon1relIso_;}
    double GetPatMuon2relIso() const {return patMuon2relIso_;}
    double GetPatMuon1TrackerHits() const {return patMuon1TrackerHits_;}
    double GetPatMuon1PixelHits() const {return patMuon1PixelHits_;}
    double GetPatMuon1NormalizedChi2() const {return patMuon1NormalizedChi2_;}
    double GetPatMuon1MatchedStations() const {return patMuon1MatchedStations_;}
    double GetPatMuon1Dxy() const {return patMuon1Dxy_;}
    double GetPatMuon1Dz() const {return patMuon1Dz_;}
    bool GetPatMuon1IsGlobal() const {return patMuon1IsGlobal_;}
    bool GetPatMuon1IsTracker() const {return patMuon1IsTracker_;}
    bool GetPatMuon1IsGood() const {return patMuon1IsGood_;}
    double GetPatMuon2TrackerHits() const {return patMuon2TrackerHits_;}
    double GetPatMuon2PixelHits() const {return patMuon2PixelHits_;}
    double GetPatMuon2NormalizedChi2() const {return patMuon2NormalizedChi2_;}
    double GetPatMuon2MatchedStations() const {return patMuon2MatchedStations_;}
    double GetPatMuon2Dxy() const {return patMuon2Dxy_;}
    double GetPatMuon2Dz() const {return patMuon2Dz_;}
    bool GetPatMuon2IsGlobal() const {return patMuon2IsGlobal_;}
    bool GetPatMuon2IsTracker() const {return patMuon2IsTracker_;}
    bool GetPatMuon2IsGood() const {return patMuon2IsGood_;}

    double GetPatDiMuonMass() const {return patDiMuonMass_;}
    double GetPatDiMuonPt() const {return patDiMuonPt_;}
    double GetPatDiMuonEta() const {return patDiMuonEta_;}
    double GetPatDiMuonPhi() const {return patDiMuonPhi_;}

    int GetPatNElectron() const {return patNElectron_;}
    double GetPatElectron1Pt() const {return patElectron1Pt_;}
    int GetPatElectron1Charge() const {return patElectron1Charge_;}
    double GetPatElectron1Phi() const {return patElectron1Phi_;}
    double GetPatElectron1Eta() const {return patElectron1Eta_;}
    double GetPatElectron1Et() const {return patElectron1Et_;}
    const LorentzVector& GetPatElectron1P4() const {return patElectron1P4_;}

    double GetPatElectron2Pt() const {return patElectron2Pt_;}
    int GetPatElectron2Charge() const {return patElectron2Charge_;}
    double GetPatElectron2Phi() const {return patElectron2Phi_;}
    double GetPatElectron2Eta() const {return patElectron2Eta_;}
    double GetPatElectron2Et() const {return patElectron2Et_;}
    const LorentzVector& GetPatElectron2P4() const {return patElectron2P4_;}

    double GetPatElectron1TkDr03() const {return patElectron1TkDr03_;}    
    double GetPatElectron1EcalDr03() const {return patElectron1EcalDr03_;}
    double GetPatElectron1HcalDr03() const {return patElectron1HcalDr03_;}
    double GetPatElectron2TkDr03() const {return patElectron2TkDr03_;}
    double GetPatElectron2EcalDr03() const {return patElectron2EcalDr03_;}
    double GetPatElectron2HcalDr03() const {return patElectron2HcalDr03_;}

    double GetPatElectron1TkDr04() const {return patElectron1TkDr04_;}
    double GetPatElectron1EcalDr04() const {return patElectron1EcalDr04_;}
    double GetPatElectron1HcalDr04() const {return patElectron1HcalDr04_;}
    double GetPatElectron2TkDr04() const {return patElectron2TkDr04_;}
    double GetPatElectron2EcalDr04() const {return patElectron2EcalDr04_;}
    double GetPatElectron2HcalDr04() const {return patElectron2HcalDr04_;}

    double GetPatElectron1relIsoDr03() const {return patElectron1relIsoDr03_;}
    double GetPatElectron1relIsoDr04() const {return patElectron1relIsoDr04_;}
    double GetPatElectron2relIsoDr03() const {return patElectron2relIsoDr03_;}
    double GetPatElectron2relIsoDr04() const {return patElectron2relIsoDr04_;}

    double GetPatDiElectronMass() const {return patDiElectronMass_;}
    double GetPatDiElectronPt() const {return patDiElectronPt_;}
    double GetPatDiElectronEta() const {return patDiElectronEta_;}
    double GetPatDiElectronPhi() const {return patDiElectronPhi_;}

    double GetEachTowerEta(int i) const { return EachTowerEta_[i]; }
    double GetEachTowerEnergy(int i) const { return EachTowerEnergy_[i]; }
    int GetEachTowerCounter() const {return EachTowerCounter_;}

    double GetCastorTowerEnergy(int i) const { return CastorTowerEnergy_[i]; }
    double GetCastorModule1Energy(int i) const { return CastorModule1Energy_[i]; }
    double GetCastorModule2Energy(int i) const { return CastorModule2Energy_[i]; }
    double GetCastorModule3Energy(int i) const { return CastorModule3Energy_[i]; }
    double GetCastorModule4Energy(int i) const { return CastorModule4Energy_[i]; }
    double GetCastorModule5Energy(int i) const { return CastorModule5Energy_[i]; }
    int GetCastorBadChannels(int i) const { return CastorBadChannels_[i]; }
    int GetCastorNumberBadChannels() const { return CastorNumberBadChannels_;}

    int GetTracksNonConeLeadingMuonR03() const {return TracksNonConeLeadingMuonR03_;}
    int GetTracksNonConeLeadingElectronR03() const {return TracksNonConeLeadingElectronR03_;}
    int GetTracksNonConePatMuon1R03() const {return TracksNonConePatMuon1R03_;}
    int GetTracksNonConePatElectron1R03() const {return TracksNonConePatElectron1R03_;}

    int GetTracksNonConeLeadingMuonR04() const {return TracksNonConeLeadingMuonR04_;}
    int GetTracksNonConeLeadingElectronR04() const {return TracksNonConeLeadingElectronR04_;}
    int GetTracksNonConePatMuon1R04() const {return TracksNonConePatMuon1R04_;}
    int GetTracksNonConePatElectron1R04() const {return TracksNonConePatElectron1R04_;}

    int GetTracksNonConeLeadingMuonR05() const {return TracksNonConeLeadingMuonR05_;}
    int GetTracksNonConeLeadingElectronR05() const {return TracksNonConeLeadingElectronR05_;}
    int GetTracksNonConePatMuon1R05() const {return TracksNonConePatMuon1R05_;}
    int GetTracksNonConePatElectron1R05() const {return TracksNonConePatElectron1R05_;}

    int GetTracksNonConeSecondMuonR03() const {return TracksNonConeSecondMuonR03_;}
    int GetTracksNonConeSecondElectronR03() const {return TracksNonConeSecondElectronR03_;}
    int GetTracksNonConePatMuon2R03() const {return TracksNonConePatMuon2R03_;}
    int GetTracksNonConePatElectron2R03() const {return TracksNonConePatElectron2R03_;}

    int GetTracksNonConeSecondMuonR04() const {return TracksNonConeSecondMuonR04_;}
    int GetTracksNonConeSecondElectronR04() const {return TracksNonConeSecondElectronR04_;}
    int GetTracksNonConePatMuon2R04() const {return TracksNonConePatMuon2R04_;}
    int GetTracksNonConePatElectron2R04() const {return TracksNonConePatElectron2R04_;}

    int GetTracksNonConeSecondMuonR05() const {return TracksNonConeSecondMuonR05_;}
    int GetTracksNonConeSecondElectronR05() const {return TracksNonConeSecondElectronR05_;}
    int GetTracksNonConePatMuon2R05() const {return TracksNonConePatMuon2R05_;}
    int GetTracksNonConePatElectron2R05() const {return TracksNonConePatElectron2R05_;}

    double GetLeadingElectronDeltaPhiTkClu() const {return LeadingElectronDeltaPhiTkClu_;}
    double GetLeadingElectronDeltaEtaTkClu() const {return LeadingElectronDeltaEtaTkClu_;}
    double GetLeadingElectronSigmaIeIe() const {return LeadingElectronSigmaIeIe_;}
    double GetLeadingElectronDCot() const {return LeadingElectronDCot_;}
    double GetLeadingElectronDist() const {return LeadingElectronDist_;}
    double GetLeadingElectronInnerHits() const {return LeadingElectronInnerHits_;}
    double GetLeadingElectronHE() const {return LeadingElectronHE_;}
    bool GetLeadingElectronIsWP95() const {return LeadingElectronIsWP95_;}
    bool GetLeadingElectronIsWP80() const {return LeadingElectronIsWP80_;}

    double GetSecondElectronDeltaPhiTkClu() const {return SecondElectronDeltaPhiTkClu_;}
    double GetSecondElectronDeltaEtaTkClu() const {return SecondElectronDeltaEtaTkClu_;}
    double GetSecondElectronSigmaIeIe() const {return SecondElectronSigmaIeIe_;}
    double GetSecondElectronDCot() const {return SecondElectronDCot_;}
    double GetSecondElectronDist() const {return SecondElectronDist_;}
    double GetSecondElectronInnerHits() const {return SecondElectronInnerHits_;}
    double GetSecondElectronHE() const {return SecondElectronHE_;}
    bool GetSecondElectronIsWP95() const {return SecondElectronIsWP95_;}
    bool GetSecondElectronIsWP80() const {return SecondElectronIsWP80_;}

    double GetPatElectron1DeltaPhiTkClu() const {return patElectron1DeltaPhiTkClu_;}
    double GetPatElectron1DeltaEtaTkClu() const {return patElectron1DeltaEtaTkClu_;}
    double GetPatElectron1SigmaIeIe() const {return patElectron1SigmaIeIe_;}
    double GetPatElectron1DCot() const {return patElectron1DCot_;}
    double GetPatElectron1Dist() const {return patElectron1Dist_;}
    double GetPatElectron1InnerHits() const {return patElectron1InnerHits_;}
    double GetPatElectron1HE() const {return patElectron1HE_;}
    bool GetPatElectron1IsWP95() const {return patElectron1IsWP95_;}
    bool GetPatElectron1IsWP80() const {return patElectron1IsWP80_;}

    double GetPatElectron2DeltaPhiTkClu() const {return patElectron2DeltaPhiTkClu_;}
    double GetPatElectron2DeltaEtaTkClu() const {return patElectron2DeltaEtaTkClu_;}
    double GetPatElectron2SigmaIeIe() const {return patElectron2SigmaIeIe_;}
    double GetPatElectron2DCot() const {return patElectron2DCot_;}
    double GetPatElectron2Dist() const {return patElectron2Dist_;}
    double GetPatElectron2InnerHits() const {return patElectron2InnerHits_;}
    double GetPatElectron2HE() const {return patElectron2HE_;}
    bool GetPatElectron2IsWP95() const {return patElectron2IsWP95_;}
    bool GetPatElectron2IsWP80() const {return patElectron2IsWP80_;}

    double GetDVtxMuon() const {return dvtxmuon_;}
    double GetDVtxMuonZ() const {return dvtxmuonZ_;}
    double GetDVtxElectron() const {return dvtxelectron_;}
    double GetDVtxElectronZ() const {return dvtxelectronZ_;}
    double GetDMuonElectron() const {return dmuonelectron_;}
    double GetDMuonElectronZ() const {return dmuonelectronZ_;}
    double GetDMuons() const {return dmuons_;}
    double GetDMuonsZ() const {return dmuonsZ_;}
    double GetDElectrons() const {return delectrons_;}
    double GetDElectronsZ() const {return delectronsZ_;}

    double GetGenLeadingElectronPt() const {return GenLeadingElectronPt_;}
    double GetGenLeadingElectronEta() const {return GenLeadingElectronEta_;}
    double GetGenLeadingElectronPhi() const {return GenLeadingElectronPhi_;}
    const LorentzVector& GetGenLeadingElectronP4() const {return GenLeadingElectronP4_;}
    double GetGenSecondElectronPt() const {return GenSecondElectronPt_;}
    double GetGenSecondElectronEta() const {return GenSecondElectronEta_;}
    double GetGenSecondElectronPhi() const {return GenSecondElectronPhi_;}
    const LorentzVector& GetGenSecondElectronP4() const {return GenSecondElectronP4_;}

    double GetGenLeadingMuonPt() const {return GenLeadingMuonPt_;}
    double GetGenLeadingMuonEta() const {return GenLeadingMuonEta_;}
    double GetGenLeadingMuonPhi() const {return GenLeadingMuonPhi_;}
    const LorentzVector& GetGenLeadingMuonP4() const {return GenLeadingMuonP4_;}
    double GetGenSecondMuonPt() const {return GenSecondMuonPt_;}
    double GetGenSecondMuonEta() const {return GenSecondMuonEta_;}
    double GetGenSecondMuonPhi() const {return GenSecondMuonPhi_;}
    const LorentzVector& GetGenSecondMuonP4() const {return GenSecondMuonP4_;}

  private:
    friend class diffractiveZAnalysis::DiffractiveZAnalysis;

    void reset();

    int hltTrigResults_[20];
    double DiElectronMass_;
    double DiElectronPt_;
    double DiElectronEta_;
    double DiElectronPhi_;

    double DiMuonMass_;
    double DiMuonPt_;
    double DiMuonEta_;
    double DiMuonPhi_;

    double LeadingElectronPt_;
    double LeadingElectronEta_;
    double LeadingElectronPhi_;
    LorentzVector LeadingElectronP4_;
    int LeadingElectronCharge_;
    double SecondElectronPt_;
    double SecondElectronEta_;
    double SecondElectronPhi_;
    LorentzVector SecondElectronP4_;
    int SecondElectronCharge_;
    int ElectronsN_;

    double LeadingElectronTkDr03_;
    double LeadingElectronEcalDr03_;
    double LeadingElectronHcalDr03_;
    double SecondElectronTkDr03_;
    double SecondElectronEcalDr03_;
    double SecondElectronHcalDr03_;

    double LeadingElectronTkDr04_;
    double LeadingElectronEcalDr04_;
    double LeadingElectronHcalDr04_;
    double SecondElectronTkDr04_;
    double SecondElectronEcalDr04_;
    double SecondElectronHcalDr04_;

    double LeadingElectronrelIsoDr03_;
    double LeadingElectronrelIsoDr04_;
    double SecondElectronrelIsoDr03_;
    double SecondElectronrelIsoDr04_;

    double LeadingMuonPt_;
    double LeadingMuonEta_;
    double LeadingMuonPhi_;
    LorentzVector LeadingMuonP4_;
    int LeadingMuonCharge_;
    double SecondMuonPt_;
    double SecondMuonEta_;
    double SecondMuonPhi_;
    LorentzVector SecondMuonP4_;
    int SecondMuonCharge_;
    int MuonsN_;

    double LeadingMuonSumPtR03_;
    double LeadingMuonEmEtR03_;
    double LeadingMuonHadEtR03_;
    double LeadingMuonSumPtR05_;
    double LeadingMuonEmEtR05_;
    double LeadingMuonHadEtR05_;

    double SecondMuonSumPtR03_;
    double SecondMuonEmEtR03_;
    double SecondMuonHadEtR03_;
    double SecondMuonSumPtR05_;
    double SecondMuonEmEtR05_;
    double SecondMuonHadEtR05_;

    double LeadingMuonrelIsoDr03_;
    double SecondMuonrelIsoDr03_;
    double LeadingMuonrelIsoDr05_;
    double SecondMuonrelIsoDr05_;
    double LeadingMuonTrackerHits_;
    double LeadingMuonPixelHits_;
    double LeadingMuonNormalizedChi2_;
    double LeadingMuonMatchedStations_;
    double LeadingMuonDxy_;
    double LeadingMuonDz_;
    bool LeadingMuonIsGlobal_;
    bool LeadingMuonIsTracker_;
    bool LeadingMuonIsGood_;
    double SecondMuonTrackerHits_;
    double SecondMuonPixelHits_;
    double SecondMuonNormalizedChi2_;
    double SecondMuonMatchedStations_;
    double SecondMuonDxy_;
    double SecondMuonDz_;
    bool SecondMuonIsGlobal_;
    bool SecondMuonIsTracker_;
    bool SecondMuonIsGood_;

    std::vector<double> VertexMultiplicity_;
    std::vector<double> VertexChiNorm_;
    std::vector<double> VertexNDOF_;
    std::vector<double> Vz_;
    std::vector<double> Vx_;
    std::vector<double> Vy_;
    std::vector<std::vector<double> > TracksPt_;
    std::vector<std::vector<double> > ZDCdigifC_;
    std::vector<double> EachTowerEta_;
    std::vector<double> EachTowerEnergy_;
    std::vector<double> CastorTowerEnergy_;
    std::vector<double> CastorModule1Energy_;
    std::vector<double> CastorModule2Energy_;
    std::vector<double> CastorModule3Energy_;
    std::vector<double> CastorModule4Energy_;
    std::vector<double> CastorModule5Energy_;
    std::vector<int> CastorBadChannels_;

    int CastorNumberBadChannels_;
    int EachTowerCounter_;

    double xigenminus_;
    double xigenplus_;
    double tracketamin_;
    double tracketamax_;

    double mxgenminus_;
    double mxgenplus_;
    double mx2genminus_;
    double mx2genplus_;
    double mxgenleft_;
    double mxgenright_;
    double mx2genleft_;
    double mx2genright_;
    double lrggen_;
    double etamaxgen_;
    double etamingen_;
    double epluspzgen_;
    double eminuspzgen_;
    double etexpoplusgen_;
    double etexpominusgen_;
    double sumECastorMinusGen_;
    std::vector<double> particlesetagen_;
    std::vector<double> particlespdgidgen_;
    std::vector<double> particlesenergygen_;
    std::vector< math::XYZTLorentzVector > particlesp4gen_;
    int nparticlesgen_;
    double sumptgenleft_;
    double sumptgenright_;

    double mxGen_;
    double mx2Gen_;
    double epluspzGenLim_;
    double eminuspzGenLim_;
    double etexpoplusGenLim_;
    double etexpominusGenLim_;

    double mxgenminusCMS_;
    double mxgenplusCMS_;
    double mx2genminusCMS_;
    double mx2genplusCMS_;
    double mxgenleftCMS_;
    double mxgenrightCMS_;
    double mx2genleftCMS_;
    double mx2genrightCMS_;
    double lrggenCMS_;
    double etamaxgenCMS_;
    double etamingenCMS_;
    double epluspzgenCMS_;
    double eminuspzgenCMS_;
    double etexpoplusgenCMS_;
    double etexpominusgenCMS_;
    double sumptgenleftCMS_;
    double sumptgenrightCMS_;

    double DiElectronMassPF_;
    double DiMuonMassPF_;

    double SumEHFPlus_;
    double SumEHF_SPlus_;
    double SumEHF_LPlus_;
    double SumEtHFPlus_;
    double SumEHFMinus_;
    double SumEHF_SMinus_;
    double SumEHF_LMinus_;
    double SumEtHFMinus_;
    double SumEHEPlus_;
    double SumEtHEPlus_;
    double SumEHEMinus_;
    double SumEtHEMinus_;
    double SumEHBPlus_;
    double SumEtHBPlus_;
    double SumEHBMinus_;
    double SumEtHBMinus_;
    double SumEEEPlus_;
    double SumEtEEPlus_;
    double SumEEEMinus_;
    double SumEtEEMinus_;
    double SumEEBPlus_;
    double SumEtEBPlus_;
    double SumEEBMinus_;
    double SumEtEBMinus_;
    double EPZCaloPlus_;
    double EPZCaloMinus_;
    double EtEtaCaloPlus_;
    double EtEtaCaloMinus_;
    double EtaCaloMax_;
    double EtaCaloMin_;
    double lrgCalo_;
    int MultiplicityHFPlus_;
    int MultiplicityHEPlus_;
    int MultiplicityEEPlus_;
    int MultiplicityHFMinus_;
    int MultiplicityHEMinus_;
    int MultiplicityEEMinus_;

    int Vertex_;
    double mxpfminus_;
    double mxpfplus_;
    double mx2pfminus_;
    double mx2pfplus_;
    double etamaxpf_;
    double etaminpf_;
    double epluspzpf_; 
    double eminuspzpf_;
    double etexpopluspf_;
    double etexpominuspf_;
    double lrgPF_;
    double mxpfleft_;
    double mxpfright_;
    double mx2pfleft_;
    double mx2pfright_;
    double sumptpfleft_;
    double sumptpfright_;
    double SumEHFPluspf_;
    double SumEHFMinuspf_;
    double mxpf_;
    double mx2pf_;

    double mxpfnozminus_;
    double mxpfnozplus_;
    double mx2pfnozminus_;
    double mx2pfnozplus_;
    double etamaxpfnoz_;
    double etaminpfnoz_;
    double epluspzpfnoz_;
    double eminuspzpfnoz_;
    double etexpopluspfnoz_;
    double etexpominuspfnoz_;
    double lrgPFnoz_;
    double mxpfnozleft_;
    double mxpfnozright_;
    double mx2pfnozleft_;
    double mx2pfnozright_;
    double sumptpfnozleft_;
    double sumptpfnozright_;
    double mxpfnoz_;
    double mx2pfnoz_;

    int patNMuon_;

    double patMuon1Pt_;
    int patMuon1Charge_;
    double patMuon1Phi_;
    double patMuon1Eta_;
    double patMuon1Et_;
    LorentzVector patMuon1P4_;

    double patMuon2Pt_;
    int patMuon2Charge_;
    double patMuon2Phi_ ;
    double patMuon2Eta_;
    double patMuon2Et_;
    LorentzVector patMuon2P4_;

    double patMuon1SumPtR03_;
    double patMuon1EmEtR03_;
    double patMuon1HadEtR03_;   
    double patMuon1SumPtR05_;
    double patMuon1EmEtR05_;
    double patMuon1HadEtR05_;   

    double patMuon2SumPtR03_;
    double patMuon2EmEtR03_;
    double patMuon2HadEtR03_;    
    double patMuon2SumPtR05_;
    double patMuon2EmEtR05_;
    double patMuon2HadEtR05_;  

    double patMuon1relIsoDr03_;
    double patMuon2relIsoDr03_;
    double patMuon1relIsoDr05_;
    double patMuon2relIsoDr05_;
    double patMuon1relIso_;
    double patMuon2relIso_;
    double patMuon1TrackerHits_;
    double patMuon1PixelHits_;
    double patMuon1NormalizedChi2_;
    double patMuon1MatchedStations_;
    double patMuon1Dxy_;
    double patMuon1Dz_;
    bool patMuon1IsGlobal_;
    bool patMuon1IsTracker_;
    bool patMuon1IsGood_;
    double patMuon2TrackerHits_;
    double patMuon2PixelHits_;
    double patMuon2NormalizedChi2_;
    double patMuon2MatchedStations_;
    double patMuon2Dxy_;
    double patMuon2Dz_;
    bool patMuon2IsGlobal_;
    bool patMuon2IsTracker_;
    bool patMuon2IsGood_;

    double patDiMuonMass_;
    double patDiMuonPt_;
    double patDiMuonEta_;
    double patDiMuonPhi_;

    double patDiElectronMass_;
    double patDiElectronPt_;
    double patDiElectronEta_;
    double patDiElectronPhi_;

    int patNElectron_; 

    double patElectron1Pt_;
    int patElectron1Charge_;
    double patElectron1Phi_;
    double patElectron1Eta_;
    double patElectron1Et_;
    LorentzVector patElectron1P4_;

    double patElectron2Pt_;
    int patElectron2Charge_;
    double patElectron2Phi_;
    double patElectron2Eta_;
    double patElectron2Et_;
    LorentzVector patElectron2P4_;

    double patElectron1TkDr03_;    
    double patElectron1EcalDr03_;
    double patElectron1HcalDr03_;
    double patElectron2TkDr03_;
    double patElectron2EcalDr03_;
    double patElectron2HcalDr03_;

    double patElectron1TkDr04_;
    double patElectron1EcalDr04_;
    double patElectron1HcalDr04_;
    double patElectron2TkDr04_;
    double patElectron2EcalDr04_;
    double patElectron2HcalDr04_;

    double patElectron1relIsoDr03_;
    double patElectron1relIsoDr04_;
    double patElectron2relIsoDr03_;
    double patElectron2relIsoDr04_;

    int TracksNonConeLeadingMuonR03_;
    int TracksNonConeLeadingElectronR03_;
    int TracksNonConePatMuon1R03_;
    int TracksNonConePatElectron1R03_;

    int TracksNonConeLeadingMuonR04_;
    int TracksNonConeLeadingElectronR04_;
    int TracksNonConePatMuon1R04_;
    int TracksNonConePatElectron1R04_;

    int TracksNonConeLeadingMuonR05_;
    int TracksNonConeLeadingElectronR05_;
    int TracksNonConePatMuon1R05_;
    int TracksNonConePatElectron1R05_;

    int TracksNonConeSecondMuonR03_;
    int TracksNonConeSecondElectronR03_;
    int TracksNonConePatMuon2R03_;
    int TracksNonConePatElectron2R03_;

    int TracksNonConeSecondMuonR04_;
    int TracksNonConeSecondElectronR04_;
    int TracksNonConePatMuon2R04_;
    int TracksNonConePatElectron2R04_;

    int TracksNonConeSecondMuonR05_;
    int TracksNonConeSecondElectronR05_;
    int TracksNonConePatMuon2R05_;
    int TracksNonConePatElectron2R05_;

    double LeadingElectronDeltaPhiTkClu_;
    double LeadingElectronDeltaEtaTkClu_;
    double LeadingElectronSigmaIeIe_;
    double LeadingElectronDCot_;
    double LeadingElectronDist_;
    double LeadingElectronInnerHits_;
    double LeadingElectronHE_;
    bool LeadingElectronIsWP95_;
    bool LeadingElectronIsWP80_;
    double SecondElectronDeltaPhiTkClu_;
    double SecondElectronDeltaEtaTkClu_;
    double SecondElectronSigmaIeIe_;
    double SecondElectronDCot_ ;
    double SecondElectronDist_;
    double SecondElectronInnerHits_;
    double SecondElectronHE_;
    bool SecondElectronIsWP95_;
    bool SecondElectronIsWP80_;
    double patElectron1DeltaPhiTkClu_;
    double patElectron1DeltaEtaTkClu_;
    double patElectron1SigmaIeIe_;
    double patElectron1DCot_;
    double patElectron1Dist_;
    double patElectron1InnerHits_;
    double patElectron1HE_;
    bool patElectron1IsWP95_;
    bool patElectron1IsWP80_;
    double patElectron2DeltaPhiTkClu_;
    double patElectron2DeltaEtaTkClu_;
    double patElectron2SigmaIeIe_;
    double patElectron2DCot_;
    double patElectron2Dist_;
    double patElectron2InnerHits_;
    double patElectron2HE_;
    bool patElectron2IsWP95_;
    bool patElectron2IsWP80_;

    double dvtxmuon_;
    double dvtxmuonZ_;
    double dvtxelectron_;
    double dvtxelectronZ_;
    double dmuonelectron_;
    double dmuonelectronZ_;
    double dmuons_;
    double dmuonsZ_;
    double delectrons_;
    double delectronsZ_;

    double GenLeadingElectronPt_;
    double GenLeadingElectronEta_;
    double GenLeadingElectronPhi_;
    LorentzVector GenLeadingElectronP4_;
    double GenSecondElectronPt_;
    double GenSecondElectronEta_;
    double GenSecondElectronPhi_;
    LorentzVector GenSecondElectronP4_;

    double GenLeadingMuonPt_;
    double GenLeadingMuonEta_;
    double GenLeadingMuonPhi_;
    LorentzVector GenLeadingMuonP4_;
    double GenSecondMuonPt_;
    double GenSecondMuonEta_;
    double GenSecondMuonPhi_;
    LorentzVector GenSecondMuonP4_;

};

#endif    
