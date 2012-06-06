import FWCore.ParameterSet.Config as cms

# Settings
class config: pass
config.verbose = True
config.writeEdmOutput = False
config.runOnMC = False
config.runPATSequences = False
config.usePAT = False
config.globalTagNameData = 'GR_R_52_V7::All'
#config.globalTagNameData = 'GR_R_42_V19::All' 
#config.instLumiROOTFile='/storage2/eliza/lumibyXing_Cert_160404-176023_7TeV_PromptReco_Collisions11_JSON.root'
config.globalTagNameMC = 'START42_V14A::All'
config.comEnergy = 8000.0
config.trackAnalyzerName = 'trackHistoAnalyzer'
config.trackTagName = 'analysisTracks'
##PAT INFO does not using Asterisk, yet.

if config.runOnMC:
    #config.l1Paths = ('ALL')
    config.l1Paths = ('L1_ZeroBias','L1_BptxMinus_NotBptxPlus','L1_SingleJet30U')
    config.hltPaths =('HLT_Jet30_v1','HLT_Jet30_v2','HLT_Jet30_v3','HLT_Jet30_v4','HLT_Jet30_v5','HLT_Jet30_v6')
else:
    #config.l1Paths = ('L1_ZeroBias','L1_BptxMinus_NotBptxPlus','L1_SingleJet30U')
    #config.hltPaths = ('HLT_ExclDiJet30U_HFOR_v1','HLT_DiJetAve100U_v1')
    config.l1Paths = ('L1_SingleJet36','L1_SingleJet16','L1_DoubleJetC56')
    #config.hltPaths = ('HLT_ExclDiJet60_HFOR_v*','HLT_ExclDiJet60_HFAND_v*','HLT_Jet60_v*' )
    config.hltPaths = ('HLT_PFJet40_v*','HLT_L1SingleJet16_v*','HLT_DiPFJetAve80_v*','HLT_L1SingleJet36_v*','HLT_ExclDiJet80_HFAND_v*','HLT_ExclDiJet35_HFAND_v*','HLT_ExclDiJet35_HFOR_v*')

config.outputTTreeFile = 'forwardQCDTTreeAnalysis.root'

if config.runOnMC:
    config.inputFileName = '/storage2/eliza/samples_test/QCD_Pt-15to30_TuneZ2_7TeV_pythia6AODSIMS_3.root'# MC
else:
    config.inputFileName = 'rfio:/castor/cern.ch/cms/store/data/Run2012A/Jet/RAW/v1/000/193/336/6CE0FC0F-7995-E111-BC9D-001D09F2B2CF.root'
        #'rfio:/castor/cern.ch/cms/store/data/Run2012A/Jet/RAW/v1/000/193/686/D80B9D30-5999-E111-8DAF-003048D2BC4C.root',
        #'rfio:/castor/cern.ch/cms/store/data/Run2012A/Jet/RAW/v1/000/193/676/8CF36755-3C99-E111-B084-0025B3203898.root'
        #'rfio:/castor/cern.ch/cms/store/data/Run2012A/Jet/RECO/PromptReco-v1/000/190/895/BCF66AEE-2685-E111-8B36-BCAEC518FF62.root'

process = cms.Process("Analysis")

process.load('FWCore.MessageService.MessageLogger_cfi')

process.options = cms.untracked.PSet(
	wantSummary = cms.untracked.bool(True),
	SkipEvent = cms.untracked.vstring('ProductNotFound')
	)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10000) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring( 'file:%s' % config.inputFileName )
    #duplicateCheckMode = cms.untracked.string('noDuplicateCheck')
)


#---------------------------------------------------------------------------------
# Output
process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string(config.outputTTreeFile))



process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.GeometryExtended_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'GR_R_52_V7::All'
process.load('JetMETCorrections.Configuration.DefaultJEC_cff')
process.load('CommonTools/RecoAlgos/HBHENoiseFilterResultProducer_cfi')
###Fragmento do menu de 2012
process.load('ForwardAnalysis.ForwardTTreeAnalysis.HLT2012_cff')

# create the jetMET HLT reco path
process.DoHLTJets = cms.Path(
    process.HLTBeginSequence +
    process.HLTRecoJetSequenceAK5Corrected +
    process.HLTRecoJetSequenceAK5L1FastJetCorrected +
    process.HLTRecoMETSequence 
)
##############################
if config.runPATSequences:
    from ForwardAnalysis.Skimming.addPATSequences import addPATSequences
    addPATSequences(process,config.runOnMC)

    if config.runOnMC:
	process.patTrigger.addL1Algos = cms.bool( False )
	process.patJets.addTagInfos   = cms.bool( False )
    else:
	process.patTrigger.addL1Algos = cms.bool( True )
	process.patJets.addTagInfos   = cms.bool( True )   



from ForwardAnalysis.ForwardTTreeAnalysis.addCastorRecHitCorrector import addCastorRecHitCorrector
addCastorRecHitCorrector(process)

#process.load("ForwardAnalysis.ForwardTTreeAnalysis.exclusiveDijetsAnalysisSequences_cff")
#######################################################################################################################
# Analysis modules
#--------------------------------
## from ForwardAnalysis.Utilities.countsAnalyzer_cfi import countsAnalyzer
## if not config.runOnMC:
##     process.load('ForwardAnalysis.Utilities.lumiWeight_cfi')
##     process.lumiWeight.rootFileName = cms.string(config.instLumiROOTFile)

## if not config.runOnMC:
##     process.eventWeightSequence = cms.Sequence(process.lumiWeight) 
##     process.eventWeight_step = cms.Path(process.eventWeightSequence)
############################################################################################################## 
#process.pfCandidateNoiseThresholds.src = "pfNoPileUpPFlow"
#process.tracksTransverseRegion.JetTag = "selectedPatJetsPFlow"

########################################################################

#from ForwardAnalysis.ForwardTTreeAnalysis.DiffractiveAnalysis_cfi import DiffractiveAnalysis
#from ForwardAnalysis.ForwardTTreeAnalysis.ExclusiveDijetsAnalysis_cfi import ExclusiveDijetsAnalysis
from ForwardAnalysis.ForwardTTreeAnalysis.PATInfo_cfi import PATInfo
from ForwardAnalysis.ForwardTTreeAnalysis.dijetsTriggerAnalysis_cfi import DijetsTriggerAnalysis  
#PATInfo.L1AlgoBitName =  config.l1Paths 
#PATInfo.HLTAlgoBitName = config.hltPaths 
PATInfo.runALLTriggerPath = True

process.dijetsTriggerAnalysisTTree = cms.EDAnalyzer("DijetsTriggerAnalysisTTree",
        DijetsTriggerAnalysis = DijetsTriggerAnalysis,
        #PATInfo = PATInfo 
        )

process.patInfoTTree = cms.EDAnalyzer("PATInfoTTree",
	PATInfo = PATInfo
	)
#process.diffractiveAnalysisTTree = cms.EDAnalyzer("DiffractiveAnalysisTTree",
#	DiffractiveAnalysis = DiffractiveAnalysis
#	)
#process.diffractiveAnalysisPATInfoTTree = cms.EDAnalyzer("DiffractiveAnalysisPATInfoTTree",
#	DiffractiveAnalysis = DiffractiveAnalysis,
#	PATInfo = PATInfo
#	)
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree = cms.EDAnalyzer("DiffractiveExclusiveDijetsAnalysisPATInfoTTree",
#	DiffractiveAnalysis = DiffractiveAnalysis,
#        ExclusiveDijetsAnalysis = ExclusiveDijetsAnalysis,
#	PATInfo = PATInfo
#	)
#process.diffractiveAnalysisTTree.DiffractiveAnalysis.hltPath = ''
#process.diffractiveAnalysisPATInfoTTree.DiffractiveAnalysis.hltPath = ''
process.load('HLTrigger/HLTfilters/hltHighLevel_cfi')
process.hltHighLevel.TriggerResultsTag =cms.InputTag("TriggerResults","","HLT")
process.hltHighLevel.HLTPaths = ['HLT_ExclDiJet80_HFAND_v*','HLT_ExclDiJet35_HFAND_v*','HLT_ExclDiJet35_HFOR_v*','HLT_L1SingleJet16_v*','HLT_DiPFJetAve80_v*','HLT_L1SingleJet36_v*']
process.hltHighLevel.andOr = True # True = OR, False = AND



#process.exclusiveDijetsHLTFilter.HLTPaths = ['HLT_ExclDiJet80_HFAND_v*','HLT_ExclDiJet35_HFAND_v*','HLT_ExclDiJet35_HFOR_v*','HLT_L1SingleJet16_v*','HLT_DiPFJetAve80_v*','HLT_L1SingleJet36_v*']

#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.DiffractiveAnalysis.hltPath = ''
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.DiffractiveAnalysis.trackTag = 'analysisTracks'
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.DiffractiveAnalysis.vertexTag = "offlinePrimaryVertices"
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.DiffractiveAnalysis.particleFlowTag = "pfCandidateNoiseThresholds"
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.DiffractiveAnalysis.jetTag = "selectedPatJetsPFlow"

#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.ExclusiveDijetsAnalysis.hltPaths = config.hltPaths 
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.ExclusiveDijetsAnalysis.TrackTag = 'analysisTracks'
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.ExclusiveDijetsAnalysis.VertexTag = "offlinePrimaryVertices"
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.ExclusiveDijetsAnalysis.ParticleFlowTag = "pfCandidateNoiseThresholds"
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.ExclusiveDijetsAnalysis.JetTag = "selectedPatJetsPFlow"
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.ExclusiveDijetsAnalysis.JetNonCorrTag = "ak5PFJets"
#if config.runOnMC:
#     process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.ExclusiveDijetsAnalysis.AccessMCInfo = True
#else:
#     process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.ExclusiveDijetsAnalysis.AccessMCInfo = False 
#########################################################################
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF0 = process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.clone()
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF0.DiffractiveAnalysis.energyThresholdHF = 0.0
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF1 = process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.clone()
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF1.DiffractiveAnalysis.energyThresholdHF = 1.0
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF2 = process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.clone()
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF2.DiffractiveAnalysis.energyThresholdHF = 2.0
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF3 = process.diffractiveExclusiveDijetsAnalysisPATInfoTTree.clone()
#process.diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF3.DiffractiveAnalysis.energyThresholdHF = 3.0


##########################################################################
if config.runOnMC:
  process.gen_step = cms.Path(process.genChargedParticles+
                              process.genProtonDissociative*process.edmNtupleMxGen+
                              process.genStableParticles*
                              process.etaMaxGen+process.etaMinGen*
                              process.edmNtupleEtaMaxGen+process.edmNtupleEtaMinGen)


#process.analysis_reco_step = cms.Path(process.analysisSequences)
#process.castor_step = cms.Path(process.castorSequence)
#process.analysis_patInfoTTree_step = cms.Path(process.patInfoTTree)
#process.analysis_diffractiveAnalysisTTree_step = cms.Path(process.diffractiveAnalysisTTree)
process.analysis_dijetsTriggerAnalysisPATInfoTTree_step = cms.Path(process.hltHighLevel + process.dijetsTriggerAnalysisTTree)
process.schedule = cms.Schedule( process.DoHLTJets, process.analysis_dijetsTriggerAnalysisPATInfoTTree_step)
#process.analysis_diffractiveAnalysisPATInfoTTree_step = cms.Path(process.diffractiveAnalysisPATInfoTTree)
#process.analysis_diffractiveExclusiveDijetsAnalysisPATInfoTTree_step = cms.Path(process.eventSelectionHLT+
#                                                                                process.diffractiveExclusiveDijetsAnalysisPATInfoTTree+
#                                                                                process.diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF0+
#                                                                                process.diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF1+
#                                                                                process.diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF2+
#                                                                                process.diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF3)
#process.analysis_diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF0_step = cms.Path(process.diffractiveExclusiveDijetsAnalysisPATInfoTTree_HF0)

#process.analysis_diffractiveAnalysisPATInfoTTree_step = cms.Path(process.diffractiveAnalysisPATInfoTTree)
#process.analysis_diffractiveExclusiveDijetsAnalysisPATInfoTTree_step = cms.Path(process.diffractiveExclusiveDijetsAnalysisPATInfoTTree)
