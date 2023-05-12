#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

#include "PDAnalyzerUtil.h"

PDAnalyzerUtil::PDAnalyzerUtil() {

  // User parameters are set as names associated to a string,
  // see PDAnalyzer.cc for more details.
  setUserParameter( "use_hltlist"  , "false" );
  setUserParameter( "use_hlts"     , "true"  );
  setUserParameter( "use_hlto"     , "false" );
  setUserParameter( "use_hltm"     , "false" );
  setUserParameter( "use_bspot"    , "true"  );
  setUserParameter( "use_met"      , "true"  );
  setUserParameter( "use_muons"    , "true"  );
  setUserParameter( "use_electrons", "true"  );
  setUserParameter( "use_taus"     , "false" );
  setUserParameter( "use_jets"     , "true"  );
  setUserParameter( "use_tags"     , "true"  );
  setUserParameter( "use_info"     , "false" );
  setUserParameter( "use_pflow"    , "true"  );
  setUserParameter( "use_tracks"   , "true"  );
  setUserParameter( "use_trkper"   , "true"  );
  setUserParameter( "use_pvts"     , "true"  );
  setUserParameter( "use_svts"     , "true"  );
  setUserParameter( "use_tkips"    , "true"  );
  setUserParameter( "use_vtxps"    , "true"  );
  setUserParameter( "use_vrel"     , "true"  );
  setUserParameter( "use_puwgt"    , "false" );
  setUserParameter( "use_gen"      , "false" );
  setUserParameter( "use_gpj"      , "false" );

  setUserParameter( "use_hlto_sphe"     , "true"  );
  setUserParameter( "use_hlto_cart"     , "false" );
  setUserParameter( "use_muons_sphe"    , "true"  );
  setUserParameter( "use_muons_cart"    , "false" );
  setUserParameter( "use_electrons_sphe", "true"  );
  setUserParameter( "use_electrons_cart", "false" );
  setUserParameter( "use_taus_sphe"     , "true"  );
  setUserParameter( "use_taus_cart"     , "false" );
  setUserParameter( "use_jets_sphe"     , "true"  );
  setUserParameter( "use_jets_cart"     , "false" );
  setUserParameter( "use_pflow_sphe"    , "true"  );
  setUserParameter( "use_pflow_cart"    , "false" );
  setUserParameter( "use_tracks_sphe"   , "true"  );
  setUserParameter( "use_tracks_cart"   , "false" );
  setUserParameter( "use_vtxps_sphe"    , "true"  );
  setUserParameter( "use_vtxps_cart"    , "false" );
  setUserParameter( "use_gen_sphe"      , "true"  );
  setUserParameter( "use_gen_cart"      , "false" );
  setUserParameter( "use_gpj_sphe"      , "true"  );
  setUserParameter( "use_gpj_cart"      , "false" );

  setUserParameter( "jetNDauMin",  "1" );
  setUserParameter( "jetNDauMax",  "999999999" );
  setUserParameter( "jetNHFMin" , "-999999999.999" );
  setUserParameter( "jetNHFMax" ,  "0.99" );
  setUserParameter( "jetNEFMin" , "-999999999.999" );
  setUserParameter( "jetNEFMax" ,  "0.99" );
  setUserParameter( "jetCHFMin" ,  "0.0" );
  setUserParameter( "jetCHFMax" ,  "999999999.999" );
  setUserParameter( "jetCEFMin" , "-999999999.999" );
  setUserParameter( "jetCEFMax" ,  "0.99" );
  setUserParameter( "jetNCHMin" ,  "0" );
  setUserParameter( "jetNCHMax" ,  "999999999" );
  setUserParameter( "jetEtaCut" , "2.4" );

  setUserParameter( "muoChiMin"    , "10.0" );
  setUserParameter( "muoPixHitMin" , "0" );
  setUserParameter( "muoMuoHitMin" , "0" );
  setUserParameter( "muoNTkLayMin" , "5" );
  setUserParameter( "muoNMatchMin" , "1" );
  setUserParameter( "muoDbMax"     , "0.2" );
  setUserParameter( "muoDzMax"     , "0.5" );

}


PDAnalyzerUtil::~PDAnalyzerUtil() {
}


void PDAnalyzerUtil::setupNtuple() {

  // User parameters are retrieved by using their names;
  // see PDAnalyzer.cc for more details.
  getUserParameter( "use_hltlist"  , use_hltlist   );
  getUserParameter( "use_hlts"     , use_hlts      );
  getUserParameter( "use_hlto"     , use_hlto      );
  getUserParameter( "use_hltm"     , use_hltm      );
  getUserParameter( "use_bspot"    , use_bspot     );
  getUserParameter( "use_met"      , use_met       );
  getUserParameter( "use_muons"    , use_muons     );
  getUserParameter( "use_electrons", use_electrons );
  getUserParameter( "use_taus"     , use_taus      );
  getUserParameter( "use_jets"     , use_jets      );
  getUserParameter( "use_tags"     , use_tags      );
  getUserParameter( "use_info"     , use_info      );
  getUserParameter( "use_pflow"    , use_pflow     );
  getUserParameter( "use_tracks"   , use_tracks    );
  getUserParameter( "use_trkper"   , use_trkper    );
  getUserParameter( "use_pvts"     , use_pvts      );
  getUserParameter( "use_svts"     , use_svts      );
  getUserParameter( "use_tkips"    , use_tkips     );
  getUserParameter( "use_vrel"     , use_vrel      );
  getUserParameter( "use_vtxps"    , use_vtxps     );
  getUserParameter( "use_puwgt"    , use_puwgt     );
  getUserParameter( "use_gen"      , use_gen       );
  getUserParameter( "use_gpj"      , use_gpj       );
//  if ( !use_jets ) use_svts = false;
  if ( !use_svts ) use_tkips =
                   use_vtxps =
                   use_vrel  = false;
  getUserParameter( "use_hlto_sphe"     , use_hlto_sphe      );
  getUserParameter( "use_hlto_cart"     , use_hlto_cart      );
  getUserParameter( "use_muons_sphe"    , use_muons_sphe     );
  getUserParameter( "use_muons_cart"    , use_muons_cart     );
  getUserParameter( "use_electrons_sphe", use_electrons_sphe );
  getUserParameter( "use_electrons_cart", use_electrons_cart );
  getUserParameter( "use_taus_sphe"     , use_taus_sphe      );
  getUserParameter( "use_taus_cart"     , use_taus_cart      );
  getUserParameter( "use_jets_sphe"     , use_jets_sphe      );
  getUserParameter( "use_jets_cart"     , use_jets_cart      );
  getUserParameter( "use_pflow_sphe"    , use_pflow_sphe     );
  getUserParameter( "use_pflow_cart"    , use_pflow_cart     );
  getUserParameter( "use_tracks_sphe"   , use_tracks_sphe    );
  getUserParameter( "use_tracks_cart"   , use_tracks_cart    );
  getUserParameter( "use_vtxps_sphe"    , use_vtxps_sphe     );
  getUserParameter( "use_vtxps_cart"    , use_vtxps_cart     );
  getUserParameter( "use_gen_sphe"      , use_gen_sphe       );
  getUserParameter( "use_gen_cart"      , use_gen_cart       );
  getUserParameter( "use_gpj_sphe"      , use_gpj_sphe       );
  getUserParameter( "use_gpj_cart"      , use_gpj_cart       );

  getUserParameter( "muoChiMin"    , muoChiMin    );
  getUserParameter( "muoPixHitMin" , muoPixHitMin );
  getUserParameter( "muoMuoHitMin" , muoMuoHitMin );
  getUserParameter( "muoNTkLayMin" , muoNTkLayMin );
  getUserParameter( "muoNMatchMin" , muoNMatchMin );
  getUserParameter( "muoDbMax"     , muoDbMax     );
  getUserParameter( "muoDzMax"     , muoDzMax     );

  // The function "initTree()" is defined in PDNtupleBranch ,
  // it uses the boolean flags to choose which TTree branches are
  // actually written/read to/from the ntuple file.
  initTree();

  return;

}


void PDAnalyzerUtil::beginJob() {

  NtuInterface< PDNtupleBranch<WrapperBase> >::beginJob();

  // User parameters are retrieved by using their names;
  // see PDAnalyzer.cc for more details.
  getUserParameter( "jetNDauMin", jetNDauMin );
  getUserParameter( "jetNDauMax", jetNDauMax );
  getUserParameter( "jetNHFMin" , jetNHFMin );
  getUserParameter( "jetNHFMax" , jetNHFMax );
  getUserParameter( "jetNEFMin" , jetNEFMin );
  getUserParameter( "jetNEFMax" , jetNEFMax );
  getUserParameter( "jetCHFMin" , jetCHFMin );
  getUserParameter( "jetCHFMax" , jetCHFMax );
  getUserParameter( "jetCEFMin" , jetCEFMin );
  getUserParameter( "jetCEFMax" , jetCEFMax );
  getUserParameter( "jetNCHMin" , jetNCHMin );
  getUserParameter( "jetNCHMax" , jetNCHMax );
  getUserParameter( "jetEtaCut" , jetEtaCut );

  return;

}

/*
// redefine "getEntry" to update HLT path lists when necessary
// not fully working
bool PDAnalyzerUtil::getEntry( int ientry ) {
  if ( currentEvBase != 0 ) return false;
  if ( currentEvent  != 0 ) return false;
  getHeader( ientry );
  if ( use_hltlist ) {
    b_nHLTPaths->GetEntry( ientry );
    process( b_nHLTPaths, ientry );
    if ( nHLTPaths ) {
      b_hltCode->GetEntry( ientry );
      b_hltName->GetEntry( ientry );
      process( b_hltCode, ientry );
      process( b_hltName, ientry );
      PDEnumString::resetTrigMap();
      int iHLT;
      for ( iHLT = 0; iHLT < nHLTPaths; ++iHLT )
            PDEnumString::findTrigPath( hltName->at( iHLT ), false,
                                        hltCode->at( iHLT ) );
      PDEnumString::revertTrigMap();
    }
  }
  if ( skipList != find( runNumber, eventNumber ) )
       return preSelect( ientry );
  else return false;
}
*/

// Optional: pre-selection, with minimal data process 
// before full ntuple entry reading
bool PDAnalyzerUtil::preSelect( int ientry ) {
/*
  // example of preselection
  // get number of muons
  getEntry( b_nMuons, ientry );
  process( b_nMuons, ientry );
  std::cout << nMuons  << " muons" << std::endl;
  // skip events with no muons
  if ( !nMuons ) return false;
*/
  currentTree()->GetEntry( ientry );
  return true;
}


bool PDAnalyzerUtil::goodJet( unsigned int iJet ) {
  if ( iJet >= jetPF->size() ) return false;
  if ( jetPF->at( iJet ) ) {
    if ( jetNDau->at( iJet ) <= jetNDauMin ) return false;
    if ( jetNEF ->at( iJet ) >  jetNEFMax  ) return false;
    if ( jetNHF ->at( iJet ) >  jetNHFMax  ) return false;
    if ( fabs( jetEta->at( iJet ) ) <= jetEtaCut ) {
      if ( jetNCH->at( iJet ) <= jetNCHMin ) return false;
      if ( jetCEF->at( iJet ) >  jetCEFMax ) return false;
      if ( jetCHF->at( iJet ) <= jetCHFMin ) return false;
    }
  }
  return true;
}

/*
bool PDAnalyzerUtil::goodMu( unsigned int iMuon ) {
  if ( muoNormChi2   ->at( iMuon ) >= muoChiMin    ) return false;
  if ( muoNumPixHits ->at( iMuon ) <= muoPixHitMin ) return false;
  if ( muoNumMuHits  ->at( iMuon ) <= muoMuoHitMin ) return false;
//  if ( muoNumTkLayers->at( iMuon ) <= muoNTkLayMin ) return false;
  if ( muoNumMatches ->at( iMuon ) <= muoNMatchMin ) return false;
  if ( muoDb         ->at( iMuon ) >= muoDbMax     ) return false;
//  if ( muoDz                ->at( iMuon ) >= muoDzMax     ) return false;
}
*/

bool PDAnalyzerUtil::hlt( PDEnumString::trigPath path ) {
  if ( chkNewEvent( lastHLT ) ) {
    hfMap.clear();
    int iHLT;
    for ( iHLT = 0; iHLT < nHLTStatus; ++iHLT )
          hfMap[hltPath->at( iHLT )] = hltAccept->at( iHLT );
  }
  return hfMap[path];
}


std::vector<PDNtupleData::number>* PDAnalyzerUtil::userInfo(
                                   PDEnumString::recoObject r, int t ) {
  if ( chkNewEvent( lastInfo ) ) {
    uiMap.clear();
    int iUI;
    for ( iUI = 0; iUI < nUserInfo; ++iUI ) {
      int ot = useObjType ->at( iUI );
      int oi = useObjIndex->at( iUI );
      int it = useInfoType->at( iUI );
      std::vector<number>& v = uiMap[ot][it];
      if ( v.size() == 0 ) {
        switch ( ot ) {
        case PDEnumString::recJet:
          v.resize( nJets     , 0.0 );
          break;
        case PDEnumString::recMuon:
          v.resize( nMuons    , 0.0 );
          break;
        case PDEnumString::recElectron:
          v.resize( nElectrons, 0.0 );
          break;
        case PDEnumString::recTau:
          v.resize( nTaus     , 0.0 );
          break;
        case PDEnumString::idElectron:
          v.resize( nElectrons, 0.0 );
          break;
        }
      }
      v[oi] = useInfoValue->at( iUI );
    }
  }
  std::map< int,std::map< int,std::vector<number> > >::iterator r_iter =
                                                       uiMap.find( r );
  std::map< int,std::map< int,std::vector<number> > >::iterator r_iend =
                                                       uiMap.end();
  if ( r_iter != r_iend ) {
    std::map< int,std::vector<number> >& tmp = r_iter->second;
    std::map< int,std::vector<number> >::iterator t_iter = tmp.find( t );
    std::map< int,std::vector<number> >::iterator t_iend = tmp.end();
    if ( t_iter != t_iend ) return ( &( t_iter->second ) );
  }
  return 0;
}


const std::vector<int>& PDAnalyzerUtil::muonTracks(
                                        PDEnumString::trackType type ) {
  if ( chkNewEvent( lastMuTrk ) ) {
    muTrkMap.clear();
    muTrkMap[0                         ].resize( nMuons, -1 );
    muTrkMap[PDEnumString::muInner     ].resize( nMuons, -1 );
    muTrkMap[PDEnumString::muStandalone].resize( nMuons, -1 );
    muTrkMap[PDEnumString::muGlobal    ].resize( nMuons, -1 );
    muTrkMap[PDEnumString::muBest      ].resize( nMuons, -1 );
    muTrkMap[PDEnumString::muPF        ].resize( nMuons, -1 );
    muTrkMap[PDEnumString::muReco      ].resize( nMuons, -1 );
    int iMu;
    for ( iMu = 0; iMu < nMuons; ++iMu ) {
      int iTk = muoTrk->at( iMu );
      while ( iTk >= 0 ) {
        if ( trkType-> at( iTk ) & PDEnumString::muInner      )
                          muTrkMap[PDEnumString::muInner      ][iMu] = iTk;
        if ( trkType-> at( iTk ) & PDEnumString::muStandalone )
                          muTrkMap[PDEnumString::muStandalone ][iMu] = iTk;
        if ( trkType-> at( iTk ) & PDEnumString::muGlobal     )
                          muTrkMap[PDEnumString::muGlobal     ][iMu] = iTk;
        if ( trkType-> at( iTk ) & PDEnumString::muBest       )
                          muTrkMap[PDEnumString::muBest       ][iMu] = iTk;
        if ( trkType-> at( iTk ) & PDEnumString::muPF         )
                          muTrkMap[PDEnumString::muPF         ][iMu] = iTk;
        if ( trkType-> at( iTk ) & PDEnumString::muReco       )
                          muTrkMap[PDEnumString::muReco       ][iMu] = iTk;
        iTk = trkNext->at( iTk );
      }
    }
  }
  return muTrkMap[type];
}


const std::vector<int>& PDAnalyzerUtil::pfCandFromJet( int iJet ) {
  return listFromObject( iJet, pfcJet, pfjMap, lastPFCJet );
}


const std::vector<int>& PDAnalyzerUtil::tracksFromJet( int iJet ) {
  return listFromObject( iJet, trkJet, tkjMap, lastTrkJet );
}


const std::vector<int>& PDAnalyzerUtil::tracksFromPV( int iPV ) {
  return listFromObject( iPV, trkPVtx, tkpMap, lastTrkPV );
}


const std::vector<int>& PDAnalyzerUtil::tracksFromSV( int iSV ) {
  if ( chkNewEvent( lastTrkSV ) ) {
    tksMap.clear();
    int iVtxPs;
    for ( iVtxPs = 0; iVtxPs < nVtxPs; ++iVtxPs ) {
      int iTkIPs = tvpTip->at( iVtxPs );
      int jSV = tipSVtx->at( iTkIPs );
      std::vector<int>& tracks = tksMap[jSV];
      if ( !tracks.size() ) tracks.reserve( 10 );
      tracks.push_back( tipTrk->at( iTkIPs ) );
    }
  }
  return tksMap[iSV];
}


const std::vector<int>& PDAnalyzerUtil::daugSVsFromVtx( int iVtx, int mode ) {
  if ( chkNewEvent( lastSubVtx ) ) {
    subMap.clear();
    int iVtxRel;
    for ( iVtxRel = 0; iVtxRel < nVtxRel; ++iVtxRel ) {
      std::vector<int>& vtxsub = subMap[vtrType->at( iVtxRel )]
                                       [vtrMoth->at( iVtxRel )];
      if ( !vtxsub.size() ) vtxsub.reserve( 10 );
      vtxsub.push_back( vtrDaug->at( iVtxRel ) );
      std::vector<int>& vtxall = subMap[-1]
                                       [vtrMoth->at( iVtxRel )];
      if ( !vtxall.size() ) vtxall.reserve( 20 );
      vtxall.push_back( vtrDaug->at( iVtxRel ) );
    }
  }
  return subMap[mode][iVtx];
}


const std::vector<int>& PDAnalyzerUtil::motherVtxsToSV( int iVtx, int mode ) {
  if ( chkNewEvent( lastSubInv ) ) {
    subInv.clear();
    int iVtxRel;
    for ( iVtxRel = 0; iVtxRel < nVtxRel; ++iVtxRel ) {
      std::vector<int>& vtxmot = subInv[vtrType->at( iVtxRel )]
                                       [vtrDaug->at( iVtxRel )];
      if ( !vtxmot.size() ) vtxmot.reserve( 10 );
      vtxmot.push_back( vtrMoth->at( iVtxRel ) );
      std::vector<int>& vtxall = subInv[-1]
                                       [vtrDaug->at( iVtxRel )];
      if ( !vtxall.size() ) vtxall.reserve( 20 );
      vtxall.push_back( vtrMoth->at( iVtxRel ) );
    }
  }
  return subInv[mode][iVtx];
}


const PDAnalyzerUtil::PVInfo& PDAnalyzerUtil::pvForSV( int iSV,
                                                       int mode, int type ) {
  if ( chkNewEvent( lastPVForSV ) ) pvToSVMap.clear();
  std::vector<PVInfo>& pvs = pvToSVMap[mode][type];
  if ( pvs.empty() ) pvs.resize( nSVertices );
  PVInfo& pvi = pvs[iSV];
  int& pvr = pvi.fromReco;
  int& pvn = pvi.refitted;
  if ( pvr < -100 ) {
    if ( type < 0 ) {
      const std::vector<int>& pvm = motherVtxsToSV( iSV, mode );
      pvr = ( pvm.empty() ? -1 : pvm.front() );
      return pvi;
    }
    pvr = -1;
    const std::vector<int>& rfv = motherVtxsToSV( iSV, PDEnumString::vtrRefit );
    for ( int irf: rfv ) {
      if ( svtType->at( irf ) == type ) {
        const std::vector<int>& pvm = motherVtxsToSV( irf, mode );
        if ( !pvm.empty() ) {
          pvn = irf;
          pvr = pvm.front();
          return pvi;
        }
      }
    }
  }
  return pvi;
}


int PDAnalyzerUtil::muonTrack( int iMu, PDEnumString::trackType type ) {
  return muonTracks( type )[iMu];
}


int PDAnalyzerUtil::tagSVJet( int iJet ) {
  if ( chkNewEvent( lastJetSV ) ) {
    jsvList.clear();
    jsvList.resize( nJets, -1 );
    int iSV;
    for ( iSV = 0; iSV < nSVertices; ++iSV ) {
      if ( svtType->at( iSV ) != PDEnumString::svtTagInfo ) continue;
      jsvList[svtJet->at( iSV )] = iSV;
    }
  }
  return jsvList[iJet];
}


bool PDAnalyzerUtil::pfCandJetRel( int iPF, int iJet ) {
  return comesFromObject( iPF, iJet, pfcJet, pfjRelMap, lRelPFCJet );
}


bool PDAnalyzerUtil::tracksJetRel( int iTk, int iJet ) {
  return comesFromObject( iTk, iJet, trkJet, tkjRelMap, lRelTrkJet );
}


bool PDAnalyzerUtil::tracksPVRel( int iTk, int iPV ) {
  return comesFromObject( iTk, iPV, trkPVtx, tkpRelMap, lRelTrkPV );
}


bool PDAnalyzerUtil::tracksSVRel( int iTk, int iSV ) {
  if ( chkNewEvent( lRelTrkSV ) ) {
    tksRelMap.clear();
    int nRel = nVtxPs;
    while ( nRel-- ) {
      int iTkIPs = tvpTip->at( nRel );
      std::vector<bool>& rels = tksRelMap[tipSVtx->at( iTkIPs )];
      if ( !rels.size() ) rels.resize( nTracks, false );
      rels[tipTrk ->at( iTkIPs )] = true;
    }
  }
  return tksRelMap[iSV].at( iTk );
}


bool PDAnalyzerUtil::subVtxSVRel( int daugSV, int mothVtx, int mode ) {
  if ( chkNewEvent( lRelSubSV ) ) {
    subRelMap.clear();
    int nRel = nVtxRel;
    while ( nRel-- ) {
      std::vector<bool>& rels = subRelMap[vtrType->at( nRel )]
                                         [vtrMoth->at( nRel )];
      if ( !rels.size() ) rels.resize( nSVertices, false );
      rels[ vtrDaug->at( nRel )] = true;
    }
  }
  std::vector<bool>& rels = subRelMap[mode][mothVtx];
  return ( rels.empty() ? false : rels.at( daugSV ) );
}


int PDAnalyzerUtil::findSVtx( int trkIndex, int prevSVtx ) {
  int svtIndex;
  int tipIndex;
  int tvpIndex;
  for ( tvpIndex = 0; tvpIndex < nVtxPs; ++tvpIndex ) {
    tipIndex = tvpTip->at( tvpIndex );
    if ( tipIndex < 0 ) continue;
    if ( ( ( svtIndex = tipSVtx->at( tipIndex ) ) > prevSVtx ) &&
         (              tipTrk ->at( tipIndex )  == trkIndex ) )
       return svtIndex;
  }
  return -1;
}


const std::vector<int>& PDAnalyzerUtil::sVtsWithTrack( int trkIndex ) {
  if ( chkNewEvent( lastVtsTk ) ) {
    vtkMap.clear();
    int iVtxPs;
    for ( iVtxPs = 0; iVtxPs < nVtxPs; ++iVtxPs ) {
      int iTkIPs = tvpTip->at( iVtxPs );
      int itk = tipTrk->at( iTkIPs );
      std::vector<int>& svts = vtkMap[itk];
      if ( !svts.size() ) svts.reserve( 10 );
      svts.push_back( tipSVtx->at( iTkIPs ) );
    }
  }
  return vtkMap[trkIndex];
}


int PDAnalyzerUtil::ipIndex( int iTk, int iSV ) {
  if  ( chkNewEvent( lastIp ) ) {
    ipMap.clear();
    int iTkIPs;
    for( iTkIPs = 0; iTkIPs < nTkIPs; ++iTkIPs ) {
      ipMap[tipTrk->at( iTkIPs )][tipSVtx->at( iTkIPs )] = iTkIPs;
    }
  }
  std::map< int,std::map<int,int> >::const_iterator t_iter = ipMap.find( iTk );
  std::map< int,std::map<int,int> >::const_iterator t_iend = ipMap.end();
  if ( t_iter == t_iend ) return -1;
  const std::map<int,int>& vMap = t_iter->second;
  std::map<int,int>::const_iterator v_iter = vMap.find( iSV );
  std::map<int,int>::const_iterator v_iend = vMap.end();
  if ( v_iter == v_iend ) return -1;
  return v_iter->second;
}


int PDAnalyzerUtil::vpIndex( int iTk, int iSV ) {
  if  ( chkNewEvent( lastVp ) ) {
    vpMap.clear();
    int iVtxPs;
    for ( iVtxPs = 0; iVtxPs < nVtxPs; ++iVtxPs ) {
      int iTkIPs = tvpTip->at( iVtxPs );
      vpMap[tipTrk->at( iTkIPs )][tipSVtx->at( iTkIPs )] = iVtxPs;
    }
  }
  std::map< int,std::map<int,int> >::const_iterator t_iter = vpMap.find( iTk );
  std::map< int,std::map<int,int> >::const_iterator t_iend = vpMap.end();
  if ( t_iter == t_iend ) return -1;
  const std::map<int,int>& vMap = t_iter->second;
  std::map<int,int>::const_iterator v_iter = vMap.find( iSV );
  std::map<int,int>::const_iterator v_iend = vMap.end();
  if ( v_iter == v_iend ) return -1;
  return v_iter->second;
}


const std::string& PDAnalyzerUtil::svtName( int i ) {
  return PDEnumString::findVertexType( svtType->at( i ) );
}


PDNtupleData::number PDAnalyzerUtil::dX( int iTk ) {
  number px;
  number py;
  if ( trkVtxPx->size() ) {
    px = trkVtxPx->at( iTk );
    py = trkVtxPy->at( iTk );
  }
  else {
    px = trkPx->at( iTk );
    py = trkPy->at( iTk );
  }
  number pm = modCart( px, py, 0 );
  return -trkDxy->at( iTk ) * py / pm;
}


PDNtupleData::number PDAnalyzerUtil::dY( int iTk ) {
  number px;
  number py;
  if ( trkVtxPx->size() ) {
    px = trkVtxPx->at( iTk );
    py = trkVtxPy->at( iTk );
  }
  else {
    px = trkPx->at( iTk );
    py = trkPy->at( iTk );
  }
  number pm = modCart( px, py, 0 );
  return  trkDxy->at( iTk ) * px / pm;
}


PDNtupleData::number PDAnalyzerUtil::dX( int iTk, number vx, number vy ) {
  number px;
  number py;
  if ( trkVtxPx->size() ) {
    px = trkVtxPx->at( iTk );
    py = trkVtxPy->at( iTk );
  }
  else {
    px = trkPx->at( iTk );
    py = trkPy->at( iTk );
  }
  number pq = modSqua( px, py, 0 );
  number pm = sqrt( pq );
  return ( ( ( ( bsX - vx ) * py ) + ( ( vy - bsY ) * px ) ) * py / pq ) -
         ( trkDxy->at( iTk ) * py / pm );
}


PDNtupleData::number PDAnalyzerUtil::dY( int iTk, number vx, number vy ) {
  number px;
  number py;
  if ( trkVtxPx->size() ) {
    px = trkVtxPx->at( iTk );
    py = trkVtxPy->at( iTk );
  }
  else {
    px = trkPx->at( iTk );
    py = trkPy->at( iTk );
  }
  number pq = modSqua( px, py, 0 );
  number pm = sqrt( pq );
  return ( ( ( ( bsY - vy ) * px ) + ( ( vx - bsX ) * py ) ) * px / pq ) +
         ( trkDxy->at( iTk ) * px / pm );
}


PDNtupleData::number PDAnalyzerUtil::dZ( int iTk, number vx, number vy,
                                                  number vz ) {
  number px;
  number py;
  number pz;
  if ( trkVtxPx->size() ) {
    px = trkVtxPx->at( iTk );
    py = trkVtxPy->at( iTk );
    pz = trkVtxPz->at( iTk );
  }
  else {
    px = trkPx->at( iTk );
    py = trkPy->at( iTk );
    pz = trkPz->at( iTk );
  }
  number pq = modSqua( px, py, 0 );
  return ( ( ( py * ( vy - bsY ) ) + ( px * ( vx - bsX ) ) ) * pz / pq ) +
         trkDz->at( iTk ) + bsZ - vz;
}


PDNtupleData::number PDAnalyzerUtil::dXY( int iTk, number vx, number vy ) {
  number px;
  number py;
  if ( trkVtxPx->size() ) {
    px = trkVtxPx->at( iTk );
    py = trkVtxPy->at( iTk );
  }
  else {
    px = trkPx->at( iTk );
    py = trkPy->at( iTk );
  }
  number pq = modSqua( px, py, 0 );
  number pm = sqrt( pq );
  number dx = ( vx - bsX ) * py / pm;
  number dy = ( vy - bsY ) * px / pm;
  number d1 = trkDxy->at( iTk );
  number xy = sqrt( ( dx * dx ) +     ( dy * dy ) - ( 2 * dx * dy )
                  + ( d1 * d1 ) + ( 2 * d1 * dx ) - ( 2 * d1 * dy ) );
  return ( ( px * dY( iTk, vx, vy ) ) - ( py * dX( iTk, vx, vy ) ) > 0 ?
           xy : -xy );
}


int PDAnalyzerUtil::dSign( int iTk, number px, number py ) {
  return ( ( ( dX( iTk ) * px ) +
             ( dY( iTk ) * py ) ) > 0 ? 1 : -1 );
}


int PDAnalyzerUtil::dSign( int iTk, number px, number py,
                                      number vx, number vy ) {
  return ( ( ( dX( iTk, vx, vy ) * px ) +
             ( dY( iTk, vx, vy ) * py ) ) > 0 ? 1 : -1 );
}


float PDAnalyzerUtil::jetCharge( int iJet, float k ) {
  const std::vector<int>& pfs = pfCandFromJet( iJet );
  int n = pfs.size();
  if ( !n ) return 0.0;
  float sumQ = 0.0;
  float sumF = 0.0;
  while ( n-- ) {
    int id = pfs[n];
    int q = pfcCharge->at( id );
    if ( !q ) continue;
    float fact = pow( pfcPt->at( id ), k );
    sumF += fact;
    sumQ += fact * q;
  }
  return sumQ / sumF;
}


float PDAnalyzerUtil::sVtxCharge( int iSV, float k ) {
  const std::vector<int>& tks = tracksFromSV( iSV );
  int n = tks.size();
  if ( !n ) return 0.0;
  float sumQ = 0.0;
  float sumF = 0.0;
  while ( n-- ) {
    int id = tks[n];
    int q = trkCharge->at( id );
    float fact = pow( trkPt->at( id ), k );
    sumF += fact;
    sumQ += fact * q;
  }
  return sumQ / sumF;
}


const std::vector<int>& PDAnalyzerUtil::listFromObject(
                        int iObj, std::vector<int>* pObj,
                        std::map< int, std::vector<int> >& objMap,
                        Id& lastEID ) {
  if ( chkNewEvent( lastEID ) ) {
    objMap.clear();
    int iProd;
    int nProd = pObj->size();
    for ( iProd = 0; iProd < nProd; ++iProd ) {
      int jObj = pObj->at( iProd );
      std::vector<int>& prods = objMap[jObj];
      if ( !prods.size() ) prods.reserve( 10 );
      prods.push_back( iProd );
    }
  }
  return objMap[iObj];
}


bool PDAnalyzerUtil::comesFromObject(
                     int iProd, int iObj, std::vector<int>* pObj,
                     std::map< int,std::vector<bool> >& objMap,
                     Id& lastEID ) {
  if ( chkNewEvent( lastEID ) ) {
    objMap.clear();
    int nProd = pObj->size();
    while ( nProd-- ) {
      std::vector<bool>& prods = objMap[pObj->at( nProd )];
      if ( !prods.size() ) prods.resize( pObj->size(), false );
      prods[nProd] = true;
    }
  }
  return objMap[iObj].at( iProd );
}


void PDAnalyzerUtil::grAssoc() {
  if ( (   runNumber == lastAssoc.  run ) &&
       ( eventNumber == lastAssoc.event ) ) return;
  lastAssoc.  run =   runNumber;
  lastAssoc.event = eventNumber;
  static float ptFactor = 12.0;
  pfcGenP.resize( nPF );
  genReco.resize( nGenP );
  std::vector< std::map<float,int> > rgMap( nPF );
  std::vector< std::map<float,int> > grMap( nGenP );
  int iPF;
  int iGenP;
  int cha;
  float pt;
  float pc;
  float eta;
  float phi;
  float distR;
  float distP;
  for ( iPF = 0; iPF < nPF; ++iPF ) {
    cha = pfcCharge->at( iPF );
    pt  = pfcPt    ->at( iPF );
    eta = pfcEta   ->at( iPF );
    phi = pfcPhi   ->at( iPF );
    for ( iGenP = 0; iGenP < nGenP; ++iGenP ) {
      if ( genCharge->at( iGenP ) != cha ) continue;
      distR = dRSqua( eta, phi, genEta->at( iGenP ), genPhi->at( iGenP ) );
      pc = genPt->at( iGenP );
      distP = ptFactor * fabs( pt - pc ) / ( pt + pc );
      rgMap[iPF][ distR + distP ] = iGenP;
    }
    std::map<float,int>::iterator iter = rgMap[iPF].begin();
    std::cout << iPF << " : " << iter->first << " " << iter->second << std::endl;
    ++iter;
    std::cout << iPF << " : " << iter->first << " " << iter->second << std::endl;
    ++iter;
    std::cout << iPF << " : " << iter->first << " " << iter->second << std::endl;
    ++iter;
    std::cout << iPF << " : " << iter->first << " " << iter->second << std::endl;
    pfcGenP[iPF] = ( rgMap[iPF].size() ?
                     rgMap[iPF].begin()->second : -1 );
  }
  for ( iGenP = 0; iGenP < nGenP; ++iGenP ) {
    cha = genCharge->at( iGenP );
    pt  = genPt    ->at( iGenP );
    eta = genEta   ->at( iGenP );
    phi = genPhi   ->at( iGenP );
    for ( iPF = 0; iPF < nPF; ++iPF ) {
      if ( pfcCharge->at( iPF ) != cha ) continue;
      distR = dRSqua( eta, phi, pfcEta->at( iPF ), pfcPhi->at( iPF ) );
      pc = pfcPt->at( iPF );
      distP = ptFactor * fabs( pt - pc ) / ( pt + pc );
      grMap[iGenP][ distR + distP ] = iPF;
    }
    genReco[iGenP] = ( grMap[iGenP].size() ?
                       grMap[iGenP].begin()->second : -1 );
  }
  int ichk;
  for ( iPF = 0; iPF < nPF; ++iPF ) {
    iGenP = pfcGenP[iPF];
    if ( iGenP < 0 ) continue;
    if ( ( ichk = genReco[iGenP] ) != iPF ) {
      std::cout << "pfc mismatch: "
                << iPF   << " -> "
                << iGenP << "(" << rgMap[iPF  ].begin()->first << ") -> "
                << ichk  << "(" << grMap[iGenP].begin()->first << ")"
                << std::endl;
    }
  }
  for ( iGenP = 0; iGenP < nGenP; ++iGenP ) {
    iPF = genReco[iGenP];
    if ( iPF < 0 ) continue;
    if ( ( ichk = pfcGenP[iPF] ) != iGenP ) {
      std::cout << "gen mismatch: "
                << iGenP << " -> "
                << iPF   << "(" << grMap[iGenP].begin()->first << ") -> "
                << ichk  << "(" << rgMap[iPF  ].begin()->first << ")"
                << std::endl;
    }
  }
  return;
}


bool PDAnalyzerUtil::chkNewEvent( Id& eID ) {
  bool flag = (   runNumber != eID.run ) ||
              ( eventNumber != eID.event );
  eID.  run =   runNumber;
  eID.event = eventNumber;
  return flag;
}

