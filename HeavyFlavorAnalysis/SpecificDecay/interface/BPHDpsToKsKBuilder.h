#ifndef HeavyFlavorAnalysis_SpecificDecay_BPHDpsToKsKBuilder_h
#define HeavyFlavorAnalysis_SpecificDecay_BPHDpsToKsKBuilder_h
/** \class BPHDpsToKsKBuilder
 *
 *  Description: 
 *     Class to build D+/Ds- to K0s K+- candidates
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

class BPHDpsToKsKBuilder:
      public BPHDecayToFlyingTrkBuilder<BPHRecoCandidate,
                                        BPHPlusMinusCandidate> {

 public:

  /** Constructor
   */
  BPHDpsToKsKBuilder( const BPHEventSetupWrapper& es,
      const std::vector<BPHPlusMinusConstCandPtr>& k0sCollection,
      const BPHRecoBuilder::BPHGenericCollection*  kaonCollection,
      const reco::BeamSpot* bs ):
   BPHDecayGenericBuilderBase( es ),
   BPHDecayToFlyingCascadeBuilderBase( "K0s",
                                       BPHParticleMasses:: k0sMass,
                                       BPHParticleMasses:: k0sMSigma ),
   BPHDecayToFlyingTrkBuilder( k0sCollection,
                            "Kaon",
                            BPHParticleMasses::kaonMass,
                            BPHParticleMasses::kaonMSigma, kaonCollection ) {
    setFlyingMassRange( 0.00, 2.00 );
    setTrkPtMin    ( 0.7 );
    setTrkEtaMax   ( 3.0 );
    setMassRange   ( 1.5, 2.5 );
    setKinFitProbMin( 0.02 );
    setMassFitRange( 1.6, 2.2 );
    if (bs) {
      setBSForLxy  ( bs );
      setLxySigMin ( 3.0 );
    }
  }

  // deleted copy constructor and assignment operator
  BPHDpsToKsKBuilder           ( const BPHDpsToKsKBuilder& x ) = delete;
  BPHDpsToKsKBuilder& operator=( const BPHDpsToKsKBuilder& x ) = delete;

  /** Destructor
   */
  ~BPHDpsToKsKBuilder() override = default;

  /** Operations
   */
  /// set cuts
  void setKPtMin   ( double  pt ) { setTrkPtMin  (  pt  ); }
  void setKEtaMax  ( double eta ) { setTrkEtaMax ( eta  ); }
  void setK0sMassMin( double   m ) { setFlyingMassMin( m ); }
  void setK0sMassMax( double   m ) { setFlyingMassMax( m ); }

  /// get current cuts
  double getKPtMin   () const { return getTrkPtMin  (); }
  double getKEtaMax  () const { return getTrkEtaMax (); }
  double getK0sMassMin() const { return getFlyingMassMin(); }
  double getK0sMassMax() const { return getFlyingMassMax(); }

  /// setup parameters for BPHRecoBuilder
  void setup( void* parameters ) override {}

};


#endif

