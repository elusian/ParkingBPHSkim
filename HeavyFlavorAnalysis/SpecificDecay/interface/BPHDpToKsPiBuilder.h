#ifndef HeavyFlavorAnalysis_SpecificDecay_BPHDpToKsPiBuilder_h
#define HeavyFlavorAnalysis_SpecificDecay_BPHDpToKsPiBuilder_h
/** \class BPHDpToKsPiBuilder
 *
 *  Description: 
 *     Class to build D+- to K0s Pi+- candidates
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

class BPHDpToKsPiBuilder:
      public BPHDecayToFlyingTrkBuilder<BPHRecoCandidate,
                                        BPHPlusMinusCandidate> {

 public:

  /** Constructor
   */
  BPHDpToKsPiBuilder( const BPHEventSetupWrapper& es,
      const std::vector<BPHPlusMinusConstCandPtr>& k0sCollection,
      const BPHRecoBuilder::BPHGenericCollection*  pionCollection ):
   BPHDecayGenericBuilderBase( es ),
   BPHDecayToFlyingCascadeBuilderBase( "K0s",
                                       BPHParticleMasses:: k0sMass,
                                       BPHParticleMasses:: k0sMSigma ),
   BPHDecayToFlyingTrkBuilder( k0sCollection,
                            "Pion",
                            BPHParticleMasses::pionMass,
                            BPHParticleMasses::pionMSigma, pionCollection ) {
    setFlyingMassRange( 0.00, 2.00 );
    setTrkPtMin    ( 0.0 );
    setTrkEtaMax   ( 3.0 );
    setMassRange   ( 1.5, 2.4 );
    setProbMin     ( 0.02 );
    setMassFitRange( 1.6, 2.1 );
  }

  // deleted copy constructor and assignment operator
  BPHDpToKsPiBuilder           ( const BPHDpToKsPiBuilder& x ) = delete;
  BPHDpToKsPiBuilder& operator=( const BPHDpToKsPiBuilder& x ) = delete;

  /** Destructor
   */
  ~BPHDpToKsPiBuilder() override = default;

  /** Operations
   */
  /// set cuts
  void setPiPtMin   ( double  pt ) { setTrkPtMin  (  pt  ); }
  void setPiEtaMax  ( double eta ) { setTrkEtaMax ( eta  ); }
  void setK0sMassMin( double   m ) { setFlyingMassMin( m ); }
  void setK0sMassMax( double   m ) { setFlyingMassMax( m ); }

  /// get current cuts
  double getPiPtMin   () const { return getTrkPtMin  (); }
  double getPiEtaMax  () const { return getTrkEtaMax (); }
  double getK0sMassMin() const { return getFlyingMassMin(); }
  double getK0sMassMax() const { return getFlyingMassMax(); }

  /// setup parameters for BPHRecoBuilder
  void setup( void* parameters ) override {}

};


#endif

