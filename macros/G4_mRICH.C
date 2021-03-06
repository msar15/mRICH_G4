#pragma once

#include "GlobalVariables.C"

#include <g4main/PHG4Reco.h>

#include <g4detectors/PHG4mRICHSubsystem.h>
//#include <g4rich/PHG4mRICHSubsystem.h>
/*!
 * \file G4_mRICH.C
 * \brief Aerogel mRICH for EIC detector
 * \author Murad Sarsour
 * \date $Date: 2020/7/2  $
 */

namespace Enable
{
  bool mRICH = false;
  bool mRICH_OVERLAPCHECK = true;
}

void
mRICHInit()
{

}

//-1: single module
// 0: build h-side sectors and e-side wall
// 1: build h-side sectors
// 2: build e-side wall
// 3: build h-side wall
// 4: build h-side wall and e-side wall
// 5: build b-side sectors
// 6: build projected e-side wall

void
mRICHSetup(PHG4Reco* g4Reco, const int detectorSetup = 1, //1: full setup; 0:skeleton 
	   const int mRICHsystemSetup = 6//5//2//-1//
	   )
{

  bool OverlapCheck = Enable::OVERLAPCHECK || Enable::mRICH_OVERLAPCHECK;

  PHG4mRICHSubsystem *mRICH = new PHG4mRICHSubsystem("mRICH",1);
  mRICH->set_int_param("detectorSetup",detectorSetup);
  mRICH->set_int_param("subsystemSetup",mRICHsystemSetup);
  mRICH->UseCalibFiles(PHG4DetectorSubsystem::xml);
  //mRICH->SetCalibrationFileDir(string(getenv("CALIBRATIONROOT")) + string("/mRICH/Geometry/") );
  //mRICH->SetCalibrationFileDir(string("/gpfs/mnt/gpfs02/sphenix/user/sar/ecce/macros/detectors/EICDetector/") );
  mRICH->SetCalibrationFileDir(string("./") );
  mRICH->OverlapCheck(OverlapCheck);

  g4Reco->registerSubsystem(mRICH);
}

void mRICH_Eval(std::string outputfile, int verbosity = 0) {

  gSystem->Load("libfun4all.so");
  gSystem->Load("libg4eval.so");
  Fun4AllServer *se = Fun4AllServer::instance();

  return;
}
