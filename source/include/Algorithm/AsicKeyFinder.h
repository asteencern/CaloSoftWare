#ifndef ASICKEYFINDER_HH
#define ASICKEYFINDER_HH

#include <iostream>
#include <vector>

#include <CLHEP/Vector/ThreeVector.h>

namespace algorithm{

  enum TestBeamSetUp
  {
    sdhcal,
    siwecal_nov2015
  };
  
  struct AsicKeyFinderParameterSetting{
    std::vector<int> keyFactors;
    int nPadX;// number of pads in x direction per layer
    int nPadY;// number of pads in y direction per layer
    int asicNPad;// number of pads in x or y direction per asic (assuming a square)
    float layerGap;// gap size (in mm) between 2 layers
    float padSize;
    TestBeamSetUp setup;
    float ecalGap; //gap between ecal sensors
    bool printDebug;
  AsicKeyFinderParameterSetting() : nPadX(96),
                                    nPadY(96),
                                    asicNPad(8),
                                    layerGap(26.131),
                                    padSize(10.408),
                                    setup(sdhcal),
                                    ecalGap(0.1),
                                    printDebug(false)
    {
      keyFactors.push_back(1);
      keyFactors.push_back(12);
      keyFactors.push_back(1000);
    }
  };


  class AsicKeyFinder {
  public:
    AsicKeyFinder(){;}
    ~AsicKeyFinder(){;}
    
    inline void SetAsicKeyFinderParameterSetting(AsicKeyFinderParameterSetting params){settings=params;}
    int BuildAsicKey(int i, int j, int k);//{return i*settings.keyFactor.at(0);}
    int FindAsicKey(CLHEP::Hep3Vector vec);

  private:
    AsicKeyFinderParameterSetting settings;
  };
}
#endif
