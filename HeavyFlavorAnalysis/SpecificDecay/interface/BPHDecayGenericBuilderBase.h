#ifndef HeavyFlavorAnalysis_SpecificDecay_BPHDecayGenericBuilderBase_h
#define HeavyFlavorAnalysis_SpecificDecay_BPHDecayGenericBuilderBase_h
/** \class BPHDecayGenericBuilderBase
 *
 *  Description: 
 *     Class to build a generic decay applying selections to the
 *     reconstructed particle
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------


//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHMassSelect.h"
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHChi2Select.h"
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHMassFitSelect.h"
#include "HeavyFlavorAnalysis/SpecificDecay/interface/BPHLxySigSelect.h"

class BPHEventSetupWrapper;

//---------------
// C++ Headers --
//---------------


//              ---------------------
//              -- Class Interface --
//              ---------------------

class BPHDecayGenericBuilderBase {

 public:

  /** Constructor
   */
  BPHDecayGenericBuilderBase();
  BPHDecayGenericBuilderBase( const BPHEventSetupWrapper& es,
       BPHMassFitSelect* mfs = new BPHMassFitSelect( -2.0e+06, -1.0e+06 ) );

  // deleted copy constructor and assignment operator
  BPHDecayGenericBuilderBase           ( const BPHDecayGenericBuilderBase& x ) = delete;
  BPHDecayGenericBuilderBase& operator=( const BPHDecayGenericBuilderBase& x ) = delete;

  /** Destructor
   */
  virtual ~BPHDecayGenericBuilderBase();

  /** Operations
   */
  /// set cuts
  void setMassMin   ( double m );
  void setMassMax   ( double m );
  void setMassRange ( double mMin, double mMax );
  void setProbMin   ( double p );
  void setMassFitMin( double m );
  void setMassFitMax( double m );
  void setMassFitRange( double mMin, double mMax );
  void setLxySigMin(double lxySigMin);
  void setBSForLxy(const reco::BeamSpot* bs);

  /// get current cuts
  double getMassMin   () const { return massSel->getMassMin(); }
  double getMassMax   () const { return massSel->getMassMax(); }
  double getProbMin   () const { return chi2Sel->getProbMin(); }
  double getMassFitMin() const { return mFitSel->getMassMin(); }
  double getMassFitMax() const { return mFitSel->getMassMax(); }
  double getLxySigMin() const { return lxySigSel->getLxySigMin(); }

  /// track min p difference
  void   setMinPDiff( double mpd ) { minPDiff = mpd; }
  double getMinPDiff() { return minPDiff; }

 protected:

  const BPHEventSetupWrapper* evSetup;

  BPHMassSelect   * massSel;
  BPHChi2Select   * chi2Sel;
  BPHMassFitSelect* mFitSel;
  BPHLxySigSelect * lxySigSel;

  double minPDiff;
  bool outdated;

  virtual void fillRecList() = 0;

};


#endif

