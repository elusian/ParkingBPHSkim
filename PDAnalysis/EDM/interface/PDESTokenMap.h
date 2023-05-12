#ifndef PDESTokenMap_h
#define PDESTokenMap_h

#include "NtuAnalysis/Write/interface/NtuEDConsumer.h"
#include "HeavyFlavorAnalysis/RecoDecay/interface/BPHAnalyzerTokenWrapper.h"
#include <map>

class PDESTokenMap {
 public:
  template<class Obj,class Rec>
    void insert( const NtuESToken <Obj,Rec>* nt ) {
    BPHESTokenWrapper<Obj,Rec>* bt = new BPHESTokenWrapper<Obj,Rec>;
    bt->token = nt->token;
    tokenMap[nt] = bt;
    return;
  }
  void* operator[]( const void* ntuToken ) {
    auto iter = tokenMap.find( ntuToken );
    return ( iter == tokenMap.end() ? nullptr : iter->second );
  }
 private:
  std::map<const void*,void*> tokenMap;
};

#endif
