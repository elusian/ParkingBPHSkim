#ifndef PDReducedNtupleData_h
#define PDReducedNtupleData_h

#include "NtuTool/Common/interface/TreeWrapper.h"

class PDReducedNtupleData: public virtual TreeWrapper {

 public:

  PDReducedNtupleData() {
  }
  virtual ~PDReducedNtupleData() {
  }

  void initTree() {
    treeName = "PDreducedTree";
    setBranch( "idMuon", &idMuon, "idMuon/I", &b_idMuon );
    setBranch( "idJet" , &idJet ,  "idJet/I", &b_idJet  );
    setBranch( "angle" , &angle ,  "angle/F", &b_angle  );
  }

  int   idMuon;
  int   idJet;
  float angle;
  TBranch* b_idMuon;
  TBranch* b_idJet;
  TBranch* b_angle;

 private:

  PDReducedNtupleData           ( const PDReducedNtupleData& a ) = delete;
  PDReducedNtupleData& operator=( const PDReducedNtupleData& a ) = delete;

};

#endif

