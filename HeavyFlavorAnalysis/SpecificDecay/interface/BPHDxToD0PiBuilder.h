#ifndef HeavyFlavorAnalysis_SpecificDecay_BPHDxToD0PiBuilder_h
#define HeavyFlavorAnalysis_SpecificDecay_BPHDxToD0PiBuilder_h
/** \class BPHDxToD0PiBuilder
 *
 *  Description: 
 *     Class to build D*+- to D0 Pi+- candidates
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHDecayToFlyingTrkBuilder.h"

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

class BPHDxToD0PiBuilder:
      public BPHDecayToFlyingTrkBuilder<BPHRecoCandidate,
                                        BPHPlusMinusCandidate> {

 public:

  /** Constructor
   */
  BPHDxToD0PiBuilder( const BPHEventSetupWrapper& es,
      const std::vector<BPHPlusMinusConstCandPtr>& d0Collection,
      const BPHRecoBuilder::BPHGenericCollection*  pionCollection,
      const reco::BeamSpot* bs ):
   BPHDecayGenericBuilderBase( es ),
   BPHDecayToFlyingCascadeBuilderBase( "D0",
                                       BPHParticleMasses:: D0Mass,
                                       BPHParticleMasses:: D0MSigma ),
   BPHDecayToFlyingTrkBuilder( d0Collection,
                            "Pion",
                            BPHParticleMasses::pionMass,
                            BPHParticleMasses::pionMSigma, pionCollection ) {
    setFlyingMassRange( 0.00, 2.00 );
    setTrkPtMin    ( 0.2 );
    setTrkEtaMax   ( 3.0 );
    setMassRange   ( 1.5, 2.4 );
    setKinFitProbMin( 0.02 );
    setMassFitRange( 1.7, 2.2 );
    if (bs) {
      setBSForLxy  ( bs );
      setLxySigMin ( 3.0 );
    }
    // TODO: trk-d0 PCA
  }

  // deleted copy constructor and assignment operator
  BPHDxToD0PiBuilder           ( const BPHDxToD0PiBuilder& x ) = delete;
  BPHDxToD0PiBuilder& operator=( const BPHDxToD0PiBuilder& x ) = delete;

  /** Destructor
   */
  ~BPHDxToD0PiBuilder() override = default;

  /** Operations
   */
  /// set cuts
  void setPiPtMin   ( double  pt ) { setTrkPtMin  (  pt  ); }
  void setPiEtaMax  ( double eta ) { setTrkEtaMax ( eta  ); }
  void setD0MassMin( double   m ) { setFlyingMassMin( m ); }
  void setD0MassMax( double   m ) { setFlyingMassMax( m ); }

  /// get current cuts
  double getPiPtMin   () const { return getTrkPtMin  (); }
  double getPiEtaMax  () const { return getTrkEtaMax (); }
  double getD0MassMin() const { return getFlyingMassMin(); }
  double getD0MassMax() const { return getFlyingMassMax(); }

  /// setup parameters for BPHRecoBuilder
  void setup( void* parameters ) override {}

};


#endif

