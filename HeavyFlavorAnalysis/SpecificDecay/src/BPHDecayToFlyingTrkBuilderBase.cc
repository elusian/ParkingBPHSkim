/*
 *  See header file for a description of this class.
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHDecayToFlyingTrkBuilderBase.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHDecayGenericBuilderBase.h"
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHParticleNeutralVeto.h"
#include "HeavyFlavorAnalysis/RecoDecay/interface/BPHRecoBuilder.h"
#include "HeavyFlavorAnalysis/RecoDecay/interface/BPHPlusMinusCandidate.h"
#include "HeavyFlavorAnalysis/RecoDecay/interface/BPHRecoCandidate.h"

//---------------
// C++ Headers --
//---------------
using namespace std;

//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
BPHDecayToFlyingTrkBuilderBase::BPHDecayToFlyingTrkBuilderBase(
    const BPHEventSetupWrapper& es,
    const string& flyName, double flyMass, double flyMSigma,
    const string& trkName, double trkMass, double trkSigma,
    const BPHRecoBuilder::BPHGenericCollection* trkCollection ):
 BPHDecayGenericBuilderBase( es, nullptr ),
 BPHDecayToFlyingCascadeBuilderBase( flyName, flyMass, flyMSigma ),
 tName( trkName ),
 tMass( trkMass ),
 tSigma( trkSigma ),
 tCollection( trkCollection ),
 tknVeto( new BPHParticleNeutralVeto ),
 ptSel  ( new BPHParticlePtSelect (   0.0 ) ),
 etaSel ( new BPHParticleEtaSelect( 100.0 ) ) {
}


BPHDecayToFlyingTrkBuilderBase::BPHDecayToFlyingTrkBuilderBase(
    const string& trkName, double trkMass, double trkSigma,
    const BPHRecoBuilder::BPHGenericCollection* trkCollection ):
 tName( trkName ),
 tMass( trkMass ),
 tSigma( trkSigma ),
 tCollection( trkCollection ),
 tknVeto( new BPHParticleNeutralVeto ),
 ptSel  ( new BPHParticlePtSelect (   0.0 ) ),
 etaSel ( new BPHParticleEtaSelect( 100.0 ) ) {
}

//--------------
// Destructor --
//--------------
BPHDecayToFlyingTrkBuilderBase::~BPHDecayToFlyingTrkBuilderBase() {
  delete tknVeto;
  delete   ptSel;
  delete  etaSel;
}

//--------------
// Operations --
//--------------

/// set cuts
void BPHDecayToFlyingTrkBuilderBase::setTrkPtMin( double pt ) {
  outdated = true;
  ptSel->setPtMin( pt );
  return;
}


void BPHDecayToFlyingTrkBuilderBase::setTrkEtaMax( double eta ) {
  outdated = true;
  etaSel->setEtaMax( eta );
  return;
}

/// build candidates
void BPHDecayToFlyingTrkBuilderBase::fill( BPHRecoBuilder& brb,
                                        void* parameters ) {

  brb.setMinPDiffererence( minPDiff );
  addFlyCollection( brb );
  int i;
  int n = tCollection->size();
  tCollectSel1.clear();
  tCollectSel1.reserve( n );
  for ( i = 0; i < n; ++i ) {
    const reco::Candidate& cand = tCollection->get( i );
    if ( cand.charge() != 0 ) tCollectSel1.push_back( &cand );
  }
  vector<const reco::Candidate*>* dv = &tCollectSel1;
  vector<const reco::Candidate*>* sv = &tCollectSel2;
  if (  ptSel->getPtMin () >= 0.0 ) {
    swap( sv, dv );
    filter( sv, dv, ptSel );
  }
  if ( etaSel->getEtaMax() >= 0.0 ) {
    swap( sv, dv );
    filter( sv, dv, etaSel );
  }
  brb.add( tName, 
           BPHRecoBuilder::createCollection( *dv,
                                             this->tCollection->searchList() ),
                                             tMass, tSigma );

  if ( massSel->getMassMax() >= 0.0 )
  brb.filter( *massSel );
  if ( chi2Sel->getProbMin() >= 0.0 )
  brb.filter( *chi2Sel );
  if ( lxySigSel->getLxySigMin() >= 0.0 )
  brb.filter( *lxySigSel );
  if ( mFitSel->getMassMax() >= 0.0 )
  brb.filter( *mFitSel );

  setup( parameters );

  return;

}

