#ifndef HeavyFlavorAnalysis_SpecificDecay_BPHD0ToKPiBuilder_h
#define HeavyFlavorAnalysis_SpecificDecay_BPHD0ToKPiBuilder_h
/** \class BPHD0ToKPiBuilder
 *
 *  Description: 
 *     Class to build D0 to K+ pi- candidates
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHDecayToTkpTknSymChargeBuilder.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHDecayGenericBuilderBase.h"
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHParticleMasses.h"
#include "HeavyFlavorAnalysis/RecoDecay/interface/BPHRecoBuilder.h"
#include "HeavyFlavorAnalysis/RecoDecay/interface/BPHRecoCandidate.h"
#include "HeavyFlavorAnalysis/RecoDecay/interface/BPHPlusMinusCandidate.h"

#include "FWCore/Framework/interface/EventSetup.h"

class BPHEventSetupWrapper;

//---------------
// C++ Headers --
//---------------
#include <string>
#include <vector>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class BPHD0ToKPiBuilder: public BPHDecayToTkpTknSymChargeBuilder {

 public:

  /** Constructor
   */
  BPHD0ToKPiBuilder( const BPHEventSetupWrapper& es,
       const BPHRecoBuilder::BPHGenericCollection* posCollection,
       const BPHRecoBuilder::BPHGenericCollection* negCollection,
       const reco::BeamSpot* bs ):
   BPHDecayGenericBuilderBase( es ),
   BPHDecayToTkpTknSymChargeBuilder( es, "Kaon", BPHParticleMasses::kaonMass,
                                                 BPHParticleMasses::kaonMSigma,
                                         "Pion", BPHParticleMasses::pionMass,
                                                 BPHParticleMasses::pionMSigma,
                                     posCollection, negCollection,
                                     BPHParticleMasses::D0Mass ) {
    setTrk1PtMin ( 0.7 );
    setTrk2PtMin ( 0.7 );
    setTrk1EtaMax( 3.0 );
    setTrk2EtaMax( 3.0 );
    setMassRange ( 1.6, 2.1 );
    setProbMin   ( 0.0 );
    if (bs) {
      setBSForLxy  ( bs );
      setLxySigMin ( 3.0 );
    }
  }

  // deleted copy constructor and assignment operator
  BPHD0ToKPiBuilder           ( const BPHD0ToKPiBuilder& x ) = delete;
  BPHD0ToKPiBuilder& operator=( const BPHD0ToKPiBuilder& x ) = delete;

  /** Destructor
   */
  ~BPHD0ToKPiBuilder() override = default;

  /** Operations
   */
  /// set cuts
  void setPiPtMin ( double  pt ) { setTrk1PtMin (  pt ); }
  void setPiEtaMax( double eta ) { setTrk1EtaMax( eta ); }
  void setKPtMin  ( double  pt ) { setTrk2PtMin (  pt ); }
  void setKEtaMax ( double eta ) { setTrk2EtaMax( eta ); }
  void setPtMin   ( double  pt ) { setTrk1PtMin (  pt );
                                   setTrk2PtMin (  pt ); }
  void setEtaMax  ( double eta ) { setTrk1EtaMax( eta );
                                   setTrk2EtaMax( eta ); }

  /// get current cuts
  double getPiPtMin () const { return getTrk1PtMin (); }
  double getPiEtaMax() const { return getTrk1EtaMax(); }
  double getKPtMin  () const { return getTrk2PtMin (); }
  double getKEtaMax () const { return getTrk2EtaMax(); }

};


#endif

