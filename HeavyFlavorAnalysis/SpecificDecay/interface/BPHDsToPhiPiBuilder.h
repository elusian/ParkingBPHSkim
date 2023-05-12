#ifndef HeavyFlavorAnalysis_SpecificDecay_BPHDsToPhiPiBuilder_h
#define HeavyFlavorAnalysis_SpecificDecay_BPHDsToPhiPiBuilder_h
/** \class BPHDsToPhiPiBuilder
 *
 *  Description: 
 *     Class to build Ds+- to Phi Pi+ - candidates
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHDecayToResTrkBuilder.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHDecayGenericBuilderBase.h"
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHDecayConstrainedBuilderBase.h"
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

class BPHDsToPhiPiBuilder:
      public BPHDecayToResTrkBuilder<BPHRecoCandidate,
                                     BPHPlusMinusCandidate> {

 public:

  /** Constructor
   */
  BPHDsToPhiPiBuilder( const BPHEventSetupWrapper& es,
      const std::vector<BPHPlusMinusConstCandPtr>& phiCollection,
      const BPHRecoBuilder::BPHGenericCollection*  piCollection,
      const reco::BeamSpot* bs ):
   BPHDecayGenericBuilderBase( es, nullptr ),
   BPHDecayConstrainedBuilderBase( "Phi", BPHParticleMasses::phiMass,
                                          BPHParticleMasses::phiMWidth ),
   BPHDecayToResTrkBuilder( phiCollection,
                            "Pion",
                            BPHParticleMasses::pionMass,
                            BPHParticleMasses::pionMSigma, piCollection ) {
    setResMassRange( 1.00, 1.04 );
    setTrkPtMin    ( 0.7 );
    setTrkEtaMax   ( 3.0 );
    setMassRange   ( 1.50, 2.40 );
    setProbMin     ( 0.02 );
    setMassFitRange( 1.60, 2.30 );    
    setConstr( true );

    if (bs) {
      setBSForLxy  ( bs );
      setLxySigMin ( 3.0 );
    }
  }

  // deleted copy constructor and assignment operator
  BPHDsToPhiPiBuilder           ( const BPHDsToPhiPiBuilder& x ) = delete;
  BPHDsToPhiPiBuilder& operator=( const BPHDsToPhiPiBuilder& x ) = delete;

  /** Destructor
   */
  ~BPHDsToPhiPiBuilder() override = default;

  /** Operations
   */
  /// set cuts
  void setPiPtMin     ( double  pt ) { setTrkPtMin  (  pt ); }
  void setPiEtaMax    ( double eta ) { setTrkEtaMax ( eta ); }
  void setPhiMassMin( double   m ) { setResMassMin(   m ); }
  void setPhiMassMax( double   m ) { setResMassMax(   m ); }

  /// get current cuts
  double getPiPtMin     () const { return getTrkPtMin  (); }
  double getPiEtaMax    () const { return getTrkEtaMax (); }
  double getPhiMassMin() const { return getResMassMin(); }
  double getPhiMassMax() const { return getResMassMax(); }

  /// setup parameters for BPHRecoBuilder
  void setup( void* parameters ) override {}

};


#endif

