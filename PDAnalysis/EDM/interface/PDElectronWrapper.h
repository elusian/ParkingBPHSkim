#ifndef PDElectronWrapper_H
#define PDElectronWrapper_H
/** \class PDElectronWrapper
 *
 *  Description: 
 *
 *
 *  $Date: 2019-03-21 16:28:56 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------


//------------------------------------
// Collaborating Class Declarations --
//------------------------------------


//---------------
// C++ Headers --
//---------------
#include <iostream>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class PDElectronWrapper {

 public:

  /** Constructor
   */
 PDElectronWrapper( const pat::Electron* electron = 0 ): ptr( electron ) {}

  /** Destructor
   */
  virtual ~PDElectronWrapper() {}

  /** Operations
   */

  float full5x5_e1x5             () { return
   ptr->full5x5_e1x5(); }
  float full5x5_e2x5Bottom       () { return
   ptr->full5x5_e2x5Bottom(); }
  float full5x5_e2x5Left         () { return
   ptr->full5x5_e2x5Left(); }
  float full5x5_e2x5Max          () { return
   ptr->full5x5_e2x5Max(); }
  float full5x5_e2x5Right        () { return
   ptr->full5x5_e2x5Right(); }
  float full5x5_e2x5Top          () { return
   ptr->full5x5_e2x5Top(); }
  float full5x5_e5x5             () { return
   ptr->full5x5_e5x5(); }
  float full5x5_eBottom          () { return
   ptr->full5x5_eBottom(); }
  float full5x5_eLeft            () { return
   ptr->full5x5_eLeft(); }
  float full5x5_eRight           () { return
   ptr->full5x5_eRight(); }
  float full5x5_eTop             () { return
   ptr->full5x5_eTop(); }
  float full5x5_hcalOverEcal     () { return
   ptr->full5x5_hcalOverEcal(); }
  float full5x5_hcalOverEcalValid() { return
   ptr->full5x5_hcalOverEcalValid(); }
  float full5x5_r9               () { return
   ptr->full5x5_r9(); }
  float full5x5_sigmaEtaEta      () { return
   ptr->full5x5_sigmaEtaEta(); }
  float full5x5_sigmaIetaIeta    () { return
   ptr->full5x5_sigmaIetaIeta(); }
  float full5x5_sigmaIphiIphi    () { return
   ptr->full5x5_sigmaIphiIphi(); }

  bool  isSeedSaturated          () { return
   ptr->isSeedSaturated(); }

 private:

  // private copy and assigment constructors
  PDElectronWrapper           ( const PDElectronWrapper& x );
  PDElectronWrapper& operator=( const PDElectronWrapper& x );

  const pat::Electron* ptr;

};

//#include "PDAnalysis/EDM/interface/PDElectronWrapper.hpp"

#endif // PDElectronWrapper_H

