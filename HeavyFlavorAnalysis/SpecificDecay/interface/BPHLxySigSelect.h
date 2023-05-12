#ifndef HeavyFlavorAnalysis_SpecificDecay_BPHLxySigSelect_h
#define HeavyFlavorAnalysis_SpecificDecay_BPHLxySigSelect_h
/** \class BPHLxySigSelect
 *
 *  Description: 
 *     Class for candidate selection by chisquare (at vertex fit level)
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "HeavyFlavorAnalysis/RecoDecay/interface/BPHVertexSelect.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "HeavyFlavorAnalysis/RecoDecay/interface/BPHDecayVertex.h"
#include "TMath.h"

#include "RecoVertex/VertexTools/interface/VertexDistanceXY.h"
#include "RecoVertex/VertexPrimitives/interface/VertexState.h"

//---------------
// C++ Headers --
//---------------


//              ---------------------
//              -- Class Interface --
//              ---------------------

class BPHLxySigSelect: public BPHVertexSelect {

 public:

  /** Constructor
   */
   BPHLxySigSelect( double lxySig ): lxySigMin( lxySig ) {}

  // deleted copy constructor and assignment operator
  BPHLxySigSelect           ( const BPHLxySigSelect& x ) = delete;
  BPHLxySigSelect& operator=( const BPHLxySigSelect& x ) = delete;

  /** Destructor
   */
  ~BPHLxySigSelect() override = default;

  /** Operations
   */
  /// select vertex
  bool accept( const BPHDecayVertex& cand ) const override {
    if ( lxySigMin < 0.0 ) return true;
    const reco::Vertex& v = cand.vertex();
    if ( v.isFake() ) return false;
    if ( !v.isValid() ) return false;
    
    VertexDistanceXY vdxy;  
    Measurement1D lxy = vdxy.distance(v, VertexState(*bs));

    return ( lxy.significance() >= lxySigMin );
  }

  /// set prob min
  void setLxySigMin( double lxySig ) { lxySigMin = lxySig; return; }
  void setBS( const reco::BeamSpot* bs ) { this->bs = bs; return; }

  /// get current prob min
  double getLxySigMin() const { return lxySigMin; }

 private:

  double lxySigMin;
  const reco::BeamSpot* bs;

};


#endif

