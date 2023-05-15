#ifndef HeavyFlavorAnalysis_SpecificDecay_BPHObjectPCA_h
#define HeavyFlavorAnalysis_SpecificDecay_BPHObjectPCA_h

#include "DataFormats/TrackReco/interface/Track.h"

#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "TrackingTools/PatternTools/interface/TwoTrackMinimumDistance.h"

#include "HeavyFlavorAnalysis/RecoDecay/interface/BPHRecoCandidate.h"



GlobalTrajectoryParameters traj(const reco::Track& trk, const MagneticField* magneticField) {
  GlobalPoint v(trk.vx(), trk.vy(), trk.vz());
  GlobalVector p3(trk.px(), trk.py(), trk.pz());
  return GlobalTrajectoryParameters( v, p3, TrackCharge( trk.charge() ), magneticField );
}

GlobalTrajectoryParameters traj(BPHRecoConstCandPtr cand, const MagneticField* magneticField) {
  auto vertex = cand->vertex().position();
  GlobalPoint v(vertex.x(), vertex.y(), vertex.z());
  auto p4 = cand->p4();
  GlobalVector p3(p4.px(), p4.py(), p4.pz());
  return GlobalTrajectoryParameters( v, p3, TrackCharge( cand->composite().charge() ), magneticField );
}

template <typename T, typename U>
float minimum_distance(const T& obj1, const U& obj2, const MagneticField* magneticField) {
  auto traj1 = traj(obj1, magneticField);
  auto traj2 = traj(obj2, magneticField);
  
  TwoTrackMinimumDistance ttmd;
  bool state = ttmd.calculate( traj1, traj2);
  
  if (not state) return -1;
  
  return ttmd.distance();
}

#endif
