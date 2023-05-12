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
