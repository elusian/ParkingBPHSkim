#ifndef PDReducedNtupleWriter_h
#define PDReducedNtupleWriter_h

#include "PDReducedNtupleData.h"
#include "NtuTool/Common/interface/TreeWriter.h"
#include "TFile.h"
#include <string>

class PDReducedNtupleWriter: public PDReducedNtupleData, public TreeWriter {

 public:

  PDReducedNtupleWriter() {
  }
  virtual ~PDReducedNtupleWriter() {
  }

  void open( const std::string& name, const std::string mode = "CREATE" ) {
    TDirectory* current = gDirectory;
    file = new TFile( name.c_str(), mode.c_str() );
    initTree();
    initWrite( file );
    current->cd();
    return;
  }
 
  void close() {
    TreeWriter::close();
    file->Close();
  }

 private:

  TFile* file;

  PDReducedNtupleWriter           ( const PDReducedNtupleWriter& a ) = delete;
  PDReducedNtupleWriter& operator=( const PDReducedNtupleWriter& a ) = delete;

};

#endif

