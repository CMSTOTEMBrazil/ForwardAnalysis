#flake8: noqa

'''
>>-------------------------<<-
Diffractive W NTuple Producer
>>-------------------------<<

Goal:
Produce your diffractive W ntuple. 

Usage:
    cmsRun DiffractiveWPATTupleMultiple.py

Example:
    cmsRun DiffractiveWPATTupleMulticrab.py Run=data_MuonP1 condition=B

Optional arguments:
    Run = data_MuonP1, data_MuonP2, data_ElectronP1, data_ElectronP2, MC_none, MC_none_W, MC_PU, MC_FlatWeight or MC_FlatWeight_and_PU 
    condition = A or B for Castor remove channels depending of Run. If any, no conditions.
Authors: D. Figueiredo, R. Arciadiacono and N. Cartiglia
'''

import FWCore.ParameterSet.Config as cms
import os, sys
import atexit

from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
options.register('Run','data_MuonP1',VarParsing.multiplicity.singleton, VarParsing.varType.string,"Option to Run: data or MC.")
options.register('condition','A',VarParsing.multiplicity.singleton, VarParsing.varType.string,"Channels CASTOR conditions.")
options.parseArguments()

process = cms.Process("Analysis")

class config: pass
config.verbose = True
config.writeEdmOutput = False
config.outputTTreeFile = 'DiffractiveWDataPATTuple.root'
config.runPATSequences = True
config.comEnergy = 7000.0
config.trackAnalyzerName = 'trackHistoAnalyzer'
config.trackTagName = 'analysisTracks'
config.NumberOfEvents = -1

#
# Define Options to Run
#
######################################################################################

if options.Run == "data_MuonP1":
  print("")
  print("###################")
  print("Data Muon 2010 P1")
  print("###################")
  print("")
  config.globalTagNameData = 'GR_R_42_V23::All'
  config.TriggerOn = True
  triggerlist = 'HLT_Mu9','HLT_Mu9_v*','HLT_DoubleMu3'
  l1list = 'L1_ZeroBias','L1_SingleEG5'
  config.runOnMC = False
  config.runPUMC = False
  config.runGen = False
  config.sys = False

elif options.Run == "data_MuonP2":
  print("")
  print("###################")
  print("Data Muon 2010 P2")
  print("###################")
  print("")
  config.globalTagNameData = 'GR_R_42_V23::All'
  config.TriggerOn = True
  triggerlist = 'HLT_Mu15','HLT_Mu15_v*','HLT_DoubleMu5_v*'
  l1list = 'L1_ZeroBias','L1_SingleEG5'
  config.runOnMC = False
  config.runPUMC = False
  config.runGen = False
  config.sys = False

elif options.Run == "data_ElectronP1":
  print("")
  print("#######################")
  print("Data Electron 2010 P1")
  print("#######################")
  print("")
  config.globalTagNameData = 'GR_R_42_V23::All'
  config.TriggerOn = True
  triggerlist = 'HLT_Photon10_L1R','HLT_Photon15_Cleaned_L1R','HLT_Ele15_SW_CaloEleId_L1R','HLT_Ele17_SW_CaloEleId_L1R','HLT_Ele17_SW_TightEleId_L1R','HLT_Ele22_SW_TighterCaloIdIsol_L1R_v1','HLT_Ele22_SW_TighterCaloIdIsol_L1R_v2'
  l1list = 'L1_ZeroBias','L1_SingleEG5'
  config.runOnMC = False
  config.runPUMC = False
  config.runGen = False
  config.sys = False

elif options.Run == "data_ElectronP2":
  print("")
  print("#######################")
  print("Data Electron 2010 P2")
  print("#######################")
  print("")
  config.globalTagNameData = 'GR_R_42_V23::All'
  config.TriggerOn = True
  triggerlist = 'HLT_Photon10_L1R','HLT_Photon15_Cleaned_L1R','HLT_Ele15_SW_CaloEleId_L1R','HLT_Ele17_SW_CaloEleId_L1R','HLT_Ele17_SW_TightEleId_L1R','HLT_Ele22_SW_TighterCaloIdIsol_L1R_v1','HLT_Ele22_SW_TighterCaloIdIsol_L1R_v2' 
  l1list = 'L1_ZeroBias','L1_SingleEG5'
  config.runOnMC = False
  config.runPUMC = False
  config.runGen = False
  config.sys = False

elif options.Run == "MC_FlatWeight_and_PU":
  print("")
  print("#####################")
  print("MC Flat Weight and PU")
  print("#####################")
  print("")
  config.globalTagNameMC = 'START42_V17D::All'
  config.TriggerOn = False
  triggerlist = 'no_trigger','no_trigger'
  l1list = 'no_trigger','no_trigger'
  config.runOnMC = True
  config.runPUMC = True
  config.runGen = True
  config.sys = False

elif options.Run == "MC_FlatWeight":
  print("")
  print("##############")
  print("MC Flat Weight")
  print("##############")
  print("")
  config.globalTagNameMC = 'START42_V17D::All'
  config.TriggerOn = False
  triggerlist = 'no_trigger','no_trigger'
  l1list = 'no_trigger','no_trigger'
  config.runOnMC = True
  config.runPUMC = False
  config.runGen = True
  config.sys = False

elif options.Run == "MC_PU":
  print("")
  print("#####")
  print("MC PU")
  print("#####")
  print("")
  config.globalTagNameMC = 'START42_V17D::All'
  config.TriggerOn = False
  triggerlist = 'no_trigger','no_trigger'
  l1list = 'no_trigger','no_trigger'
  config.runOnMC = True
  config.runPUMC = True
  config.runGen = False
  config.sys = False

elif options.Run == "MC_none":
  print("")
  print("#######")
  print("MC None")
  print("#######")
  print("")
  config.globalTagNameMC = 'START42_V17D::All'
  config.TriggerOn = False
  triggerlist = 'no_trigger','no_trigger'
  l1list = 'no_trigger','no_trigger'
  config.runOnMC = True
  config.runPUMC = False
  config.runGen = False
  config.sys = False

else:
  print("")
  print("") 
  raise RuntimeError, "Unknown option. EXIT! YOU NEED TO SETUP WITH ONE OF THE CORRECT OPTIONS."
  print("")


print("")
print(">>> Input Options:")
print("Run with MC: %s" % config.runOnMC)
print("Run MC with Pile Up: %s" % config.runPUMC)
print("Run MC with Flat Weight: %s" % config.runGen)
print("Run with Trigger: %s" % config.TriggerOn)
print("Run with Energy Scale: %s" % config.sys)
if not config.runOnMC: 
   print("Data Global Tag: " + config.globalTagNameData)
else:
   print("MC Global Tag: " + config.globalTagNameMC)  
print("")

#
# Define Triggers and Input Files
#
######################################################################################

if config.runOnMC:
    config.l1Paths = (l1list)
    config.hltPaths =(triggerlist)
    config.inputFileName = 'root://eoscms.cern.ch//store/user/dmf/SamplesDebugCMSSW428/PomwigWRECO42X.root'

else:
    config.l1Paths = (l1list)
    config.hltPaths = (triggerlist)
    config.inputFileName = 'root://eoscms.cern.ch//store/user/dmf/SamplesDebugCMSSW428/MuRunA2010.root'   

#
# CMSSW Main Code
#
######################################################################################

process.load('FWCore.MessageService.MessageLogger_cfi')

process.options = cms.untracked.PSet(
        wantSummary = cms.untracked.bool(False),
        SkipEvent = cms.untracked.vstring('ProductNotFound')
        )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(config.NumberOfEvents) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring( 'file:%s' % config.inputFileName )
)


#
# Output
#
######################################################################################

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string(config.outputTTreeFile))

#
# Detector Conditions and Scales
#
######################################################################################

process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.GeometryExtended_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

#
# Global Tag Input
#
######################################################################################

if config.runOnMC: process.GlobalTag.globaltag = config.globalTagNameMC
else: process.GlobalTag.globaltag = config.globalTagNameData

process.load('JetMETCorrections.Configuration.DefaultJEC_cff')
process.load('RecoJets.Configuration.RecoPFJets_cff')
process.load('RecoJets.Configuration.RecoJets_cff')
process.load('CommonTools/RecoAlgos/HBHENoiseFilterResultProducer_cfi')

#
# PAT Sequences
#
######################################################################################

if config.runPATSequences:
    from ForwardAnalysis.Skimming.addPATSequences import addPATSequences
    addPATSequences(process,config.runOnMC)

    if config.runOnMC:
	process.patTrigger.addL1Algos = cms.bool( False )
	process.patJets.addTagInfos   = cms.bool( False )
    else:
	process.patTrigger.addL1Algos = cms.bool( True )
	process.patJets.addTagInfos   = cms.bool( True )   

from ForwardAnalysis.Utilities.addCastorRecHitCorrector import addCastorRecHitCorrector
addCastorRecHitCorrector(process)

#
# Remove PAT MCMatching for Data
#
######################################################################################

# load the standard PAT config
process.load("PhysicsTools.PatAlgos.patSequences_cff")

# load the coreTools of PAT
from PhysicsTools.PatAlgos.tools.coreTools import *

#if not config.runOnMC: 
#    removeMCMatching(process, ['All'])

#
# PAT Muons and Electrons WorkFlow
#
######################################################################################

from PhysicsTools.PatAlgos.mcMatchLayer0.electronMatch_cfi import *
from TrackingTools.TransientTrack.TransientTrackBuilder_cfi import *
from PhysicsTools.PatAlgos.producersLayer1.electronProducer_cfi import *

from PhysicsTools.PatAlgos.mcMatchLayer0.muonMatch_cfi import *
from TrackingTools.TransientTrack.TransientTrackBuilder_cfi import *
from PhysicsTools.PatAlgos.producersLayer1.muonProducer_cfi import *

#process.patElectrons.pvSrc="goodOfflinePrimaryVertices"
#process.patMuons.pvSrc="goodOfflinePrimaryVertices"

if not config.runOnMC:

    process.makePatElectrons = cms.Sequence(
        patElectrons
    )

    process.makePatMuons = cms.Sequence(
         patMuons
    )

else:
    process.makePatElectrons = cms.Sequence(
         electronMatch *
         patElectrons
    )

    process.makePatMuons = cms.Sequence(
         muonMatch*
         patMuons
    )


#
# PAT Isolation Variables
#
######################################################################################

#from PhysicsTools.PatAlgos.tools.muonTools import *
#addMuonUserIsolation(process)

#from PhysicsTools.PatAlgos.tools.electronTools import *
#addElectronUserIsolation(process)


#
# PAT MET Variables
#
######################################################################################

# load the coreTools of PAT
from PhysicsTools.PatAlgos.tools.metTools import *
addTcMET(process,'TC')
addPfMET(process,'PF')


from PhysicsTools.PatAlgos.producersLayer1.metProducer_cfi import patMETs
process.patpfMet = patMETs.clone(
    metSource = cms.InputTag('pfMet'),
    addMuonCorrections = cms.bool(False), #false
    addGenMET    = cms.bool(False)
)


#
# Open Common Modules
#
######################################################################################

process.load("ForwardAnalysis.DiffractiveWAnalysis.diffractiveWAnalysisSequences_cff")
process.pfCandidateNoiseThresholds.src = "pfNoPileUpPFlow"
process.tracksTransverseRegion.JetTag = "selectedPatJetsPFlow"

#
# Import PSET for each Module
#
######################################################################################

from ForwardAnalysis.ForwardTTreeAnalysis.DiffractiveAnalysis_cfi import DiffractiveAnalysis
from ForwardAnalysis.DiffractiveWAnalysis.DiffractiveWAnalysis_cfi import DiffractiveWAnalysis
from ForwardAnalysis.ForwardTTreeAnalysis.PFCandInfo_cfi import PFCandInfo

#from ForwardAnalysis.ForwardTTreeAnalysis.PATTriggerInfo_cfi import PATTriggerInfo

#PATTriggerInfo.L1AlgoBitName =  config.l1Paths 
#PATTriggerInfo.HLTAlgoBitName = config.hltPaths
#PATTriggerInfo.runALLTriggerPath = True

#
# Define Filter
#
######################################################################################

process.diffractiveWFilter = cms.EDFilter("diffractiveWFilterSimple",
                             muonTag = cms.untracked.InputTag("muons"),
                             electronTag = cms.untracked.InputTag("gsfElectrons"),
                             metTag = cms.untracked.InputTag("pfMet"),
                             patmetTag = cms.untracked.InputTag("patpfMet")
                             )


#
# Define Analyzers
#
######################################################################################

process.diffractiveWHLTFilter.HLTPaths = config.hltPaths

process.diffractiveWAnalysisTTree = cms.EDAnalyzer("EventInfoDiffractiveDiffractiveWAnalysisTTree",
        EventInfo = cms.PSet(
                    RunOnData = cms.untracked.bool(not config.runOnMC),
                    RunWithMCPU = cms.untracked.bool(config.runPUMC),
                    RunWithWeightGen = cms.untracked.bool(config.runGen)
        ),
        DiffractiveAnalysis = DiffractiveAnalysis,
        DiffractiveWAnalysis = DiffractiveWAnalysis
        )

process.diffractiveWAnalysisTTree.DiffractiveWAnalysis.hltPaths = config.hltPaths
process.diffractiveWAnalysisTTree.DiffractiveAnalysis.hltPath = ''
process.diffractiveWAnalysisTTree.DiffractiveAnalysis.trackTag = 'analysisTracks'
process.diffractiveWAnalysisTTree.DiffractiveAnalysis.vertexTag = "goodOfflinePrimaryVertices"
process.diffractiveWAnalysisTTree.DiffractiveAnalysis.particleFlowTag = "pfCandidateNoiseThresholds"
process.diffractiveWAnalysisTTree.DiffractiveAnalysis.jetTag = "selectedPatJetsPFlow"
process.diffractiveWAnalysisTTree.DiffractiveAnalysis.accessCastorInfo = False
process.diffractiveWAnalysisTTree.DiffractiveAnalysis.accessZDCInfo = False

if options.condition=="A":
     print("")
     print(">>>> RunA Castor Conditions")
     print("")
     process.diffractiveWAnalysisTTree.DiffractiveWAnalysis.RunA = True
     process.diffractiveWAnalysisTTree.DiffractiveWAnalysis.RunB = False

elif options.condition=="B":
     print("")
     print(">>>> RunB Castor Conditions")
     print("")
     process.diffractiveWAnalysisTTree.DiffractiveWAnalysis.RunA = False
     process.diffractiveWAnalysisTTree.DiffractiveWAnalysis.RunB = True
else:
     print("")
     print(">>>> Full Castor")
     print("")
     process.diffractiveWAnalysisTTree.DiffractiveWAnalysis.RunA = False
     process.diffractiveWAnalysisTTree.DiffractiveWAnalysis.RunB = False 

if config.runOnMC:
     process.diffractiveWAnalysisTTree.DiffractiveWAnalysis.RunMC = True
     process.diffractiveWAnalysisTTree.DiffractiveWAnalysis.fCGeVCastor = 0.9375
     process.diffractiveWAnalysisTTree.DiffractiveWAnalysis.castorHitsTag = "castorreco"
     process.diffractiveWAnalysisTTree.DiffractiveAnalysis.castorRecHitTag ="castorreco"

else:
     process.diffractiveWAnalysisTTree.DiffractiveWAnalysis.RunMC = False
     process.diffractiveWAnalysisTTree.DiffractiveWAnalysis.fCGeVCastor = 0.015
     process.diffractiveWAnalysisTTree.DiffractiveWAnalysis.castorHitsTag = "castorRecHitCorrector"
     process.diffractiveWAnalysisTTree.DiffractiveAnalysis.castorRecHitTag = "castorRecHitCorrector"

#
# Define MC Access
#
######################################################################################

if config.runOnMC:
     process.diffractiveWAnalysisTTree.DiffractiveAnalysis.accessMCInfo = True
     process.gen_step = cms.Path(process.genChargedParticles+
                              process.genProtonDissociative*process.edmNtupleMxGen+
                              process.genStableParticles*
                              process.etaMaxGen+process.etaMinGen*
                              process.edmNtupleEtaMaxGen+process.edmNtupleEtaMinGen)

else:
     process.diffractiveWAnalysisTTree.DiffractiveAnalysis.accessMCInfo = False

#
# Clone Shifted Up and Down
#
######################################################################################

process.diffractiveWAnalysisTTreePFShiftedUp = process.diffractiveWAnalysisTTree.clone()
process.diffractiveWAnalysisTTreePFShiftedUp.DiffractiveAnalysis.particleFlowTag = "pfCandidateNoiseThresholdsShiftedUp"
process.diffractiveWAnalysisTTreePFShiftedUp.DiffractiveAnalysis.edmNtupleEtaMaxTag = "edmNtupleEtaMaxShiftedUp"
process.diffractiveWAnalysisTTreePFShiftedUp.DiffractiveAnalysis.edmNtupleEtaMinTag = "edmNtupleEtaMinShiftedUp"
process.diffractiveWAnalysisTTreePFShiftedUp.DiffractiveWAnalysis.pfTag = "pfCandidateNoiseThresholdsShiftedUp"

process.diffractiveWAnalysisTTreePFShiftedDown = process.diffractiveWAnalysisTTree.clone() 	 
process.diffractiveWAnalysisTTreePFShiftedDown.DiffractiveAnalysis.particleFlowTag = "pfCandidateNoiseThresholdsShiftedDown" 	 
process.diffractiveWAnalysisTTreePFShiftedDown.DiffractiveAnalysis.edmNtupleEtaMaxTag = "edmNtupleEtaMaxShiftedDown" 	 
process.diffractiveWAnalysisTTreePFShiftedDown.DiffractiveAnalysis.edmNtupleEtaMinTag = "edmNtupleEtaMinShiftedDown" 	 
process.diffractiveWAnalysisTTreePFShiftedDown.DiffractiveWAnalysis.pfTag = "pfCandidateNoiseThresholdsShiftedDown"

#
# Run Path. 
# If TriggerOn = True (Run with trigger)
#
######################################################################################

process.pat_Producer = cms.Path(process.makePatElectrons + process.makePatMuons + process.patpfMet) # process.patpfMet do not work with data.
process.castor_step = cms.Path(process.castorSequence)

if config.sys:

   print(">> With Energy Scale.")
   if config.TriggerOn:
       print(">> With Trigger.")
       process.analysis_diffractiveDiffractiveWAnalysisPATTriggerInfoTTree_step = cms.Path(
       process.analysisSequencesShiftedUp + process.analysisSequencesShiftedDown + process.analysisSequences + process.eventSelectionHLT + 
       process.diffractiveWAnalysisTTreePFShiftedUp + process.diffractiveWAnalysisTTreePFShiftedDown + process.diffractiveWFilter + process.diffractiveWAnalysisTTree)

   else:
       print(">> No Trigger.") 
       process.analysis_diffractiveDiffractiveWAnalysisPATTriggerInfoTTree_step = cms.Path(
       process.analysisSequencesShiftedUp + process.analysisSequencesShiftedDown + process.analysisSequences + process.eventSelection +
       process.diffractiveWAnalysisTTreePFShiftedUp + process.diffractiveWAnalysisTTreePFShiftedDown + process.diffractiveWFilter + process.diffractiveWAnalysisTTree)

else:

   print(">> No Energy Scale.")
   if config.TriggerOn:
       print(">> With Trigger.")
       process.analysis_diffractiveDiffractiveWAnalysisPATTriggerInfoTTree_step = cms.Path(
       process.analysisSequences + process.diffractiveWFilter + process.eventSelectionHLT + process.diffractiveWAnalysisTTree)

   else:
       print(">> No Trigger.")
       process.analysis_diffractiveDiffractiveWAnalysisPATTriggerInfoTTree_step = cms.Path(
       process.analysisSequences + process.diffractiveWFilter + process.eventSelection + process.diffractiveWAnalysisTTree)
