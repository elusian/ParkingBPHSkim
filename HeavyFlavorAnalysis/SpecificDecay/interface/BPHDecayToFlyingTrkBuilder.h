#ifndef HeavyFlavorAnalysis_SpecificDecay_BPHDecayToFlyingTrkBuilder_h
#define HeavyFlavorAnalysis_SpecificDecay_BPHDecayToFlyingTrkBuilder_h
/** \class BPHDecayToFlyingTrkBuilder
 *
 *  Description: 
 *     Class to build a particle decaying to a particle, decaying itself
 *     in cascade, and an additional track, for generic particle types
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHDecayToFlyingTrkBuilderBase.h"
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHDecayConstrainedBuilder.h"
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHDecaySpecificBuilder.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHParticlePtSelect.h"
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHParticleEtaSelect.h"

#include "FWCore/Framework/interface/EventSetup.h"

class BPHEventSetupWrapper;
class BPHParticleNeutralVeto;

//---------------
// C++ Headers --
//---------------
#include <string>
#include <vector>

//              ---------------------
//              -- Class Interface --
//              ---------------------

template <class ProdType, class FlyingType>
class BPHDecayToFlyingTrkBuilder:
      public BPHDecayToFlyingTrkBuilderBase,
      public BPHDecayToFlyingCascadeBuilder<ProdType,FlyingType>,
      public BPHDecaySpecificBuilder<ProdType> {

 public:

  using typename BPHDecayGenericBuilder    <ProdType        >::prod_ptr;
  using typename
        BPHDecayToFlyingCascadeBuilder<ProdType,FlyingType>::flying_ptr;

  /** Constructor
   */
  BPHDecayToFlyingTrkBuilder( const BPHEventSetupWrapper& es,
      const std::string& flyName, double flyMass, double flyMSigma,
      const std::vector<flying_ptr>& flyCollection,
      const std::string& trkName, double trkMass, double trkSigma,
      const BPHRecoBuilder::BPHGenericCollection* trkCollection ):
   BPHDecayGenericBuilderBase( es ),
   BPHDecayToFlyingCascadeBuilderBase( flyName, flyMass, flyMSigma ),
   BPHDecayToFlyingTrkBuilderBase( trkName, trkMass, trkSigma, trkCollection ) {
  }

  // deleted copy constructor and assignment operator
  BPHDecayToFlyingTrkBuilder           ( const BPHDecayToFlyingTrkBuilder& x )
                                      = delete;
  BPHDecayToFlyingTrkBuilder& operator=( const BPHDecayToFlyingTrkBuilder& x )
                                      = delete;

  /** Destructor
   */
  ~BPHDecayToFlyingTrkBuilder() override = default;

 protected:

  BPHDecayToFlyingTrkBuilder(
      const std::vector<flying_ptr>& flyCollection,
      const std::string& trkName, double trkMass, double trkSigma,
      const BPHRecoBuilder::BPHGenericCollection* trkCollection ):
   BPHDecayToFlyingTrkBuilderBase( trkName, trkMass, trkSigma, trkCollection ),
   BPHDecayToFlyingCascadeBuilder<ProdType,
                                  FlyingType>( flyCollection ) {
  }

  void fillRecList() override {
    BPHDecaySpecificBuilder<ProdType>::fillRecList();
    this->fitAndFilter( this->recList );
    return;
  }

};


#endif

