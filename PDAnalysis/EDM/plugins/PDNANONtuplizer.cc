#include "PDAnalysis/EDM/interface/PDEDMToNtuple.h"
#include "NtuAnalysis/Write/interface/NtuNANOWriteSteering.h"

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/MakerMacros.h"

class PDNANONtuplizer: public NtuNANOWriteSteering<PDEDMToNtuple> {

 public:

  explicit PDNANONtuplizer( const edm::ParameterSet& ps ):
    NtuNANOWriteSteering<PDEDMToNtuple>( ps ) {
  }

};


//define this as a plug-in
DEFINE_FWK_MODULE( PDNANONtuplizer );
