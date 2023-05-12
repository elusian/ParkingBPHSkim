#!/bin/sh

if [ -z ${CMSSW_BASE} ] ; then
  echo "CMSSW_BASE not defined; run \"cmsenv\" before"
  exit
fi

cat << END_OF_INPUT > ${CMSSW_BASE}/src/PDAnalysis/Ntu/bin/PDAnalyzerUtil.h
#ifndef PDAnalysis_Ntu_PDAnalyzerUtil_h
#define PDAnalysis_Ntu_PDAnalyzerUtil_h
#include "PDAnalysis/Ntu/interface/PDNtupleBranch.h"
#include "NtuAnalysis/Common/interface/NtuInterface.h"
class PDAnalyzerUtil: public NtuInterface< PDNtupleBranch<WrapperBase> > {
 public:
  PDAnalyzerUtil() {}
  ~PDAnalyzerUtil() override {}
 protected:
  void setupNtuple() {
     initTree();
  }
  void beginJob() override {
    NtuInterface< PDNtupleBranch<WrapperBase> >::beginJob();
  }
 private:
  // dummy copy constructor and assignment
  PDAnalyzerUtil           ( const PDAnalyzerUtil& ) = delete;
  PDAnalyzerUtil& operator=( const PDAnalyzerUtil& ) = delete;
};
#endif // PDAnalysis_Ntu_PDAnalyzerUtil_h
END_OF_INPUT

cat << END_OF_INPUT > ${CMSSW_BASE}/src/PDAnalysis/Ntu/bin/PDAnalyzer.h
#ifndef PDAnalysis_Ntu_PDAnalyzer_h
#define PDAnalysis_Ntu_PDAnalyzer_h
#include "PDAnalyzerUtil.h"
#include <iostream>
class PDAnalyzer: public virtual PDAnalyzerUtil {
 public:
  PDAnalyzer() {
    std::cout << "new PDAnalyzer" << std::endl;
    setUserParameter( "verbose", "f" );
  }
  ~PDAnalyzer() override {}
  void beginJob() override {
    PDAnalyzerUtil::beginJob();
    getUserParameter( "verbose", verbose );
  }
  void reset() override {
#  if UTIL_USE == FULL
    autoReset();
#endif
  }
  bool analyze( int entry, int event_file, int event_tot ) override {
    if ( verbose ) {
      std::cout << " +++++++++++++++++++++++++++ " << std::endl;
      std::cout << "entry: "
                << entry << " " << event_file << " " << event_tot << std::endl;
      std::cout << "run: " <<   runNumber << " , "
                << "evt: " << eventNumber << std::endl;
    }
    else {
      if ( !( event_tot % 10000 ) && event_tot )
        std::cout << event_file << " " << event_tot << std::endl;
    }
    return true;
  }
  bool verbose;
 private:
  PDAnalyzer           ( const PDAnalyzer& ) = delete;
  PDAnalyzer& operator=( const PDAnalyzer& ) = delete;
};
#endif // PDAnalysis_Ntu_PDAnalyzer_h
END_OF_INPUT

cat << END_OF_INPUT > ${CMSSW_BASE}/src/PDAnalysis/Ntu/bin/PDAnalyzerUtil.cc
#include "PDAnalysis/Ntu/bin/PDAnalyzerUtil.h"
END_OF_INPUT

cat << END_OF_INPUT > ${CMSSW_BASE}/src/PDAnalysis/Ntu/bin/PDAnalyzer.cc
#include "PDAnalysis/Ntu/bin/PDAnalyzer.h"
END_OF_INPUT

rm -f PDAnalysis/Ntu/bin/TMPReducedNtuple*
rm -f PDAnalysis/Ntu/bin/reducedAnalyze.cc

export BUILDFILETMP="PDAnalysis/Ntu/bin/BuildFile_"`date +%s`
grep -v reducedAnalyze PDAnalysis/Ntu/bin/BuildFile.xml > ${BUILDFILETMP}
rm PDAnalysis/Ntu/bin/BuildFile.xml
mv ${BUILDFILETMP} PDAnalysis/Ntu/bin/BuildFile.xml

