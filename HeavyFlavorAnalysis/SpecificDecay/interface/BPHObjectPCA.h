#ifndef HeavyFlavorAnalysis_SpecificDecay_BPHObjectPCA_h
#define HeavyFlavorAnalysis_SpecificDecay_BPHObjectPCA_h

#include "DataFormats/TrackReco/interface/Track.h"

#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "TrackingTools/PatternTools/interface/TwoTrackMinimumDistance.h"

#include "HeavyFlavorAnalysis/RecoDecay/interface/BPHRecoCandidate.h"



GlobalTrajectoryParameters traj(const reco::Track& trk, const MagneticField* magneticField) {
  return GlobalTrajectoryParameters( trk.vertex(), trk.momentum(), TrackCharge( trk.charge() ), magneticField );
}

GlobalTrajectoryParameters traj(BPHRecoConstCandPtr cand, const MagneticField* magneticField) {
  math::XYZVector p3 = cand.p4().Vect();
  return GlobalTrajectoryParameters( cand.vertex().position(), p3, TrackCharge( trk.charge() ), magneticField );
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
