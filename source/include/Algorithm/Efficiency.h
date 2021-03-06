#ifndef EFFICIENCY_HH
#define EFFICIENCY_HH

#include <iostream>
#include <cmath>
#include <vector>

#include "CaloObject/CaloLayer.h"
#include "CaloObject/CaloCluster.h"
#include "CaloObject/CaloGeom.h"
#include "Algorithm/Tracking.h"
#include "Algorithm/Distance.h"

namespace algorithm{

 
  
  struct EfficiencyParameterSetting{
    float maxRadius;
    bool semiDigitalReadout;
    bool printDebug;
    caloobject::GeomParameterSetting geometry;
    algorithm::TrackingParameterSetting trackingParams;
  EfficiencyParameterSetting() : maxRadius(25.0) ,
                                 semiDigitalReadout(true) ,
                                 printDebug(false)
                                 {;}
  };


  class Efficiency {
  public:
    Efficiency(){;}
    ~Efficiency(){;}
    
    inline void SetEfficiencyParameterSetting(EfficiencyParameterSetting params){settings=params;}
    inline CLHEP::Hep3Vector &getExpectedPosition(){return expectedPos;}
    void Run(caloobject::CaloLayer *layer, std::vector<caloobject::CaloCluster2D*> &clusters);

  private:
    EfficiencyParameterSetting settings;
    CLHEP::Hep3Vector expectedPos;
  };
}
#endif
