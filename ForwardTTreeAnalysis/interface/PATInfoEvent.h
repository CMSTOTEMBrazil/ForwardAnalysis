#ifndef PATInfoEvent_h
#define PATInfoEvent_h




namespace patInfo {
  class PATInfo;
}

class PATInfoEvent {
  public:

  typedef patInfo::PATInfo type;
  

  PATInfoEvent();
  ~PATInfoEvent();
 //------------ Set FWD methods ------------------------------
  void SetPTTriggerCandidate(double fPTTriggerCand)                     { PTTriggerCand_ =  fPTTriggerCand;}
  void SetPTTriggerRef(double fPTTriggerRef)                            { PTTriggerRef_  =  fPTTriggerRef;}

  void SetNBit(bool fnbit)                                               { nbit_  =  fnbit;}
  void SetTechL1Bit(bool fL1bit)                                         { TechL1bit_  =  fL1bit;}

  void SetL1TriggerConditionKeys(bool fL1TriggerConditionKeys)           { L1TriggerConditionKeys_  = fL1TriggerConditionKeys; }
  void SetGTL1Results(bool fGTL1Results )                                 { GTL1Results_ = fGTL1Results; }

  void SetL1TriggerDecision(bool fL1TriggerDecision )                     { L1TriggerDecision_ = fL1TriggerDecision;}
  void SetL1TriggerDecisionBeforeMask(bool fL1TriggerDecisionBeforeMask ) { L1TriggerDecisionBeforeMask_ = fL1TriggerDecisionBeforeMask; }
  void SetL1TriggerDecisionAfterMask(bool fL1TriggerDecisionAfterMask )   { L1TriggerDecisionAfterMask_ = fL1TriggerDecisionAfterMask; }


  //
  //------------ Get FWD methods ------------------------------
  double GetPTTriggerCandidate()  const { return PTTriggerCand_ ;}
  double GetPTTriggerRef()        const { return PTTriggerRef_ ;}

  bool GetNBit()                   const{ return nbit_;}
  bool GetTechL1Bit()                  const{ return TechL1bit_;}

  bool GetL1TriggerConditionKeys()   const { return L1TriggerConditionKeys_; }
  bool GetGTL1Results()              const { return GTL1Results_; }

  bool GetL1TriggerDecision()             const { return L1TriggerDecision_ ;}
  bool GetL1TriggerDecisionBeforeMask()   const { return L1TriggerDecisionBeforeMask_; }
  bool GetL1TriggerDecisionAfterMask()    const { return L1TriggerDecisionBeforeMask_; }


  private:
     friend class patInfo::PATInfo;

     double  PTTriggerCand_;
     double PTTriggerRef_;

     bool  nbit_;
     bool TechL1bit_;

     bool L1TriggerConditionKeys_;
     bool GTL1Results_;

     bool L1TriggerDecisionBeforeMask_;
     bool L1TriggerDecisionAfterMask_;
     bool L1TriggerDecision_;



     
//////////////////////////////////
};//end code

#endif