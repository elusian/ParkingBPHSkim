
#ifndef NtuAnalysis_Write_NtuEDMWriteSteering_h
#define NtuAnalysis_Write_NtuEDMWriteSteering_h

#include "NtuAnalysis/Common/interface/NtuAnalyzerUtil.h"

#include "NtuTool/EDM/interface/EDMTreeWriter.h"

#include "FWCore/Framework/interface/Event.h"

#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "NtuAnalysis/Write/interface/NtuEDConsumer.h"
#include "NtuTool/EDM/interface/EDProducerWrapper.h"

#include <string>
#include <iostream>
#include <fstream>

//
// class declaration
//

template <class T>
class NtuEDMWriteSteering: public EDMTreeWriter,
                           public NtuEDConsumer<EDProducerWrapper>,
                           public T,
                           public virtual NtuAnalyzerUtil {

 public:

  explicit NtuEDMWriteSteering( const edm::ParameterSet& ps );
  ~NtuEDMWriteSteering() override;

  void beginJob() override;
  void endJob() override;

 private:

  // dummy copy constructor and assignment
  NtuEDMWriteSteering           ( const NtuEDMWriteSteering& c ) = delete;
  NtuEDMWriteSteering& operator=( const NtuEDMWriteSteering& c ) = delete;

  int analyzedFile;
  std::string histName;

  void beginRun( const edm::Run  & run, const edm::EventSetup& es ) override;
  void endRun(   const edm::Run  & run, const edm::EventSetup& es ) override;
  bool fill(     const edm::Event&  ev, const edm::EventSetup& es ) override;

};

#include "NtuAnalysis/Write/interface/NtuEDMWriteSteering.hpp"

#endif // NtuAnalysis_Write_NtuEDMWriteSteering_h
