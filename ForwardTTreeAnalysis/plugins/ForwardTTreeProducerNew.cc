#include "FWCore/Framework/interface/MakerMacros.h"

#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/PATTriggerInfo.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/EventInfo.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/DiffractiveAnalysis.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/DiffractiveZAnalysis.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/DiffractiveWAnalysis.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/ZeroBiasAnalysis.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/TriggerAnalysis.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/ExclusiveDijetsAnalysis.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/DijetsTriggerAnalysis.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/HeavyFlavorAnalysis.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/PFCandInfo.h"

#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/PATTriggerInfoEvent.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/EventInfoEvent.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/DiffractiveEvent.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/DiffractiveZEvent.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/DiffractiveWEvent.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/ZeroBiasEvent.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/TriggerEvent.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/ExclusiveDijetsEvent.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/DijetsTriggerEvent.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/HeavyFlavorEvent.h"
#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/PFCandInfoEvent.h"

#include "ForwardAnalysis/ForwardTTreeAnalysis/interface/ForwardTTreeProducer.h"

typedef forwardTTreeAnalysis::ForwardTTreeProducer<diffractiveZAnalysis::DiffractiveZAnalysis> DiffractiveZAnalysisTTree;
DEFINE_FWK_MODULE(DiffractiveZAnalysisTTree);


typedef forwardTTreeAnalysis::ForwardTTreeProducer<pfCandInfo::PFCandInfo> PFCandInfoTTree;
DEFINE_FWK_MODULE(PFCandInfoTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<patTriggerInfo::PATTriggerInfo> PATTriggerInfoTTree;
DEFINE_FWK_MODULE(PATTriggerInfoTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<eventInfo::EventInfo> EventInfoTTree;
DEFINE_FWK_MODULE(EventInfoTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<diffractiveAnalysis::DiffractiveAnalysis> DiffractiveAnalysisTTree;
DEFINE_FWK_MODULE(DiffractiveAnalysisTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<exclusiveDijetsAnalysis::ExclusiveDijetsAnalysis> ExclusiveDijetsAnalysisTTree;
DEFINE_FWK_MODULE(ExclusiveDijetsAnalysisTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<dijetsTriggerAnalysis::DijetsTriggerAnalysis> DijetsTriggerAnalysisTTree;
DEFINE_FWK_MODULE(DijetsTriggerAnalysisTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<eventInfo::EventInfo,
                                                   exclusiveDijetsAnalysis::ExclusiveDijetsAnalysis> EventInfoExclusiveDijetsAnalysisTTree;
DEFINE_FWK_MODULE(EventInfoExclusiveDijetsAnalysisTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<dijetsTriggerAnalysis::DijetsTriggerAnalysis,
                                                   patTriggerInfo::PATTriggerInfo> DijetsTriggerAnalysisPATTriggerInfoTTree;
DEFINE_FWK_MODULE(DijetsTriggerAnalysisPATTriggerInfoTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<diffractiveAnalysis::DiffractiveAnalysis,
                                                   patTriggerInfo::PATTriggerInfo> DiffractiveAnalysisPATTriggerInfoTTree;
DEFINE_FWK_MODULE(DiffractiveAnalysisPATTriggerInfoTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<diffractiveAnalysis::DiffractiveAnalysis,
                                                   heavyFlavorAnalysis::HeavyFlavorAnalysis> DiffractiveHeavyFlavorAnalysisTTree;
DEFINE_FWK_MODULE(DiffractiveHeavyFlavorAnalysisTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<eventInfo::EventInfo,
                                                   diffractiveAnalysis::DiffractiveAnalysis,
                                                   exclusiveDijetsAnalysis::ExclusiveDijetsAnalysis> EventInfoDiffractiveExclusiveDijetsAnalysisTTree;
DEFINE_FWK_MODULE(EventInfoDiffractiveExclusiveDijetsAnalysisTTree);


typedef forwardTTreeAnalysis::ForwardTTreeProducer<eventInfo::EventInfo,
                                                   pfCandInfo::PFCandInfo,
                                                   diffractiveAnalysis::DiffractiveAnalysis,
                                                   exclusiveDijetsAnalysis::ExclusiveDijetsAnalysis> EventInfoPFCandInfoDiffractiveExclusiveDijetsAnalysisTTree;
DEFINE_FWK_MODULE(EventInfoPFCandInfoDiffractiveExclusiveDijetsAnalysisTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<eventInfo::EventInfo,
                                                   diffractiveAnalysis::DiffractiveAnalysis,
                                                   diffractiveZAnalysis::DiffractiveZAnalysis> EventInfoDiffractiveDiffractiveZAnalysisTTree;
DEFINE_FWK_MODULE(EventInfoDiffractiveDiffractiveZAnalysisTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<eventInfo::EventInfo,
                                                   pfCandInfo::PFCandInfo,
                                                   diffractiveAnalysis::DiffractiveAnalysis,
                                                   diffractiveZAnalysis::DiffractiveZAnalysis> EventInfoPFCandInfoDiffractiveDiffractiveZAnalysisTTree;
DEFINE_FWK_MODULE(EventInfoPFCandInfoDiffractiveDiffractiveZAnalysisTTree);


typedef forwardTTreeAnalysis::ForwardTTreeProducer<eventInfo::EventInfo,
                                                   diffractiveAnalysis::DiffractiveAnalysis,
                                                   diffractiveWAnalysis::DiffractiveWAnalysis> EventInfoDiffractiveDiffractiveWAnalysisTTree;
DEFINE_FWK_MODULE(EventInfoDiffractiveDiffractiveWAnalysisTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<eventInfo::EventInfo,
                                                   pfCandInfo::PFCandInfo,
                                                   diffractiveAnalysis::DiffractiveAnalysis,
                                                   diffractiveWAnalysis::DiffractiveWAnalysis> EventInfoPFCandInfoDiffractiveDiffractiveWAnalysisTTree;
DEFINE_FWK_MODULE(EventInfoPFCandInfoDiffractiveDiffractiveWAnalysisTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<diffractiveAnalysis::DiffractiveAnalysis,
                                                   exclusiveDijetsAnalysis::ExclusiveDijetsAnalysis,
                                                   patTriggerInfo::PATTriggerInfo> DiffractiveExclusiveDijetsAnalysisPATTriggerInfoTTree;
DEFINE_FWK_MODULE(DiffractiveExclusiveDijetsAnalysisPATTriggerInfoTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<diffractiveAnalysis::DiffractiveAnalysis,
                                                   exclusiveDijetsAnalysis::ExclusiveDijetsAnalysis,
                                                   eventInfo::EventInfo,
                                                   patTriggerInfo::PATTriggerInfo> EventInfoDiffractiveExclusiveDijetsAnalysisPATTriggerInfoTTree;

DEFINE_FWK_MODULE(EventInfoDiffractiveExclusiveDijetsAnalysisPATTriggerInfoTTree);

typedef forwardTTreeAnalysis::ForwardTTreeProducer<eventInfo::EventInfo,
                                                   triggerAnalysis::TriggerAnalysis> EventInfoTriggerTTree;

DEFINE_FWK_MODULE(EventInfoTriggerTTree);


typedef forwardTTreeAnalysis::ForwardTTreeProducer<eventInfo::EventInfo,
                                                   zerobiasAnalysis::ZeroBiasAnalysis> EventInfoZeroBiasAnalysisTTree;

DEFINE_FWK_MODULE(EventInfoZeroBiasAnalysisTTree);
