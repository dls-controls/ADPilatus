#ifndef PilatusDetectorParamSet_H
#define PilatusDetectorParamSet_H

#include "asynParamSet.h"

#define PilatusDelayTimeString      "DELAY_TIME"
#define PilatusThresholdString      "THRESHOLD"
#define PilatusThresholdApplyString "THRESHOLD_APPLY"
#define PilatusThresholdAutoApplyString "THRESHOLD_AUTO_APPLY"
#define PilatusEnergyString         "ENERGY"
#define PilatusArmedString          "ARMED"
#define PilatusResetPowerString     "RESET_POWER"
#define PilatusResetPowerTimeString "RESET_POWER_TIME"
#define PilatusImageFileTmotString  "IMAGE_FILE_TMOT"
#define PilatusBadPixelFileString   "BAD_PIXEL_FILE"
#define PilatusNumBadPixelsString   "NUM_BAD_PIXELS"
#define PilatusFlatFieldFileString  "FLAT_FIELD_FILE"
#define PilatusMinFlatFieldString   "MIN_FLAT_FIELD"
#define PilatusFlatFieldValidString "FLAT_FIELD_VALID"
#define PilatusGapFillString        "GAP_FILL"
#define PilatusWavelengthString     "WAVELENGTH"
#define PilatusEnergyLowString      "ENERGY_LOW"
#define PilatusEnergyHighString     "ENERGY_HIGH"
#define PilatusDetDistString        "DET_DIST"
#define PilatusDetVOffsetString     "DET_VOFFSET"
#define PilatusBeamXString          "BEAM_X"
#define PilatusBeamYString          "BEAM_Y"
#define PilatusFluxString           "FLUX"
#define PilatusFilterTransmString   "FILTER_TRANSM"
#define PilatusStartAngleString     "START_ANGLE"
#define PilatusAngleIncrString      "ANGLE_INCR"
#define PilatusDet2thetaString      "DET_2THETA"
#define PilatusPolarizationString   "POLARIZATION"
#define PilatusAlphaString          "ALPHA"
#define PilatusKappaString          "KAPPA"
#define PilatusPhiString            "PHI"
#define PilatusPhiIncrString        "PHI_INCR"
#define PilatusChiString            "CHI"
#define PilatusChiIncrString        "CHI_INCR"
#define PilatusOmegaString          "OMEGA"
#define PilatusOmegaIncrString      "OMEGA_INCR"
#define PilatusOscillAxisString     "OSCILL_AXIS"
#define PilatusNumOscillString      "NUM_OSCILL"
#define PilatusPixelCutOffString    "PIXEL_CUTOFF"
#define PilatusThTemp0String        "TH_TEMP_0"
#define PilatusThTemp1String        "TH_TEMP_1"
#define PilatusThTemp2String        "TH_TEMP_2"
#define PilatusThHumid0String       "TH_HUMID_0"
#define PilatusThHumid1String       "TH_HUMID_1"
#define PilatusThHumid2String       "TH_HUMID_2"
#define PilatusTvxVersionString     "TVXVERSION"
#define PilatusCbfTemplateFileString "CBFTEMPLATEFILE"
#define PilatusHeaderStringString   "HEADERSTRING"

/** Pilatus detector param set */
class pilatusDetectorParamSet : public virtual asynParamSet {
public:
    pilatusDetectorParamSet() {
        this->add(PilatusDelayTimeString, asynParamFloat64, &PilatusDelayTime);
        this->add(PilatusThresholdString, asynParamFloat64, &PilatusThreshold);
        this->add(PilatusThresholdApplyString, asynParamInt32, &PilatusThresholdApply);
        this->add(PilatusThresholdAutoApplyString, asynParamInt32, &PilatusThresholdAutoApply);
        this->add(PilatusEnergyString, asynParamFloat64, &PilatusEnergy);
        this->add(PilatusArmedString, asynParamInt32, &PilatusArmed);
        this->add(PilatusResetPowerString, asynParamInt32, &PilatusResetPower);
        this->add(PilatusResetPowerTimeString, asynParamInt32, &PilatusResetPowerTime);
        this->add(PilatusImageFileTmotString, asynParamFloat64, &PilatusImageFileTmot);
        this->add(PilatusBadPixelFileString, asynParamOctet, &PilatusBadPixelFile);
        this->add(PilatusNumBadPixelsString, asynParamInt32, &PilatusNumBadPixels);
        this->add(PilatusFlatFieldFileString, asynParamOctet, &PilatusFlatFieldFile);
        this->add(PilatusMinFlatFieldString, asynParamInt32, &PilatusMinFlatField);
        this->add(PilatusFlatFieldValidString, asynParamInt32, &PilatusFlatFieldValid);
        this->add(PilatusGapFillString, asynParamInt32, &PilatusGapFill);
        this->add(PilatusWavelengthString, asynParamFloat64, &PilatusWavelength);
        this->add(PilatusEnergyLowString, asynParamFloat64, &PilatusEnergyLow);
        this->add(PilatusEnergyHighString, asynParamFloat64, &PilatusEnergyHigh);
        this->add(PilatusDetDistString, asynParamFloat64, &PilatusDetDist);
        this->add(PilatusDetVOffsetString, asynParamFloat64, &PilatusDetVOffset);
        this->add(PilatusBeamXString, asynParamFloat64, &PilatusBeamX);
        this->add(PilatusBeamYString, asynParamFloat64, &PilatusBeamY);
        this->add(PilatusFluxString, asynParamFloat64, &PilatusFlux);
        this->add(PilatusFilterTransmString, asynParamFloat64, &PilatusFilterTransm);
        this->add(PilatusStartAngleString, asynParamFloat64, &PilatusStartAngle);
        this->add(PilatusAngleIncrString, asynParamFloat64, &PilatusAngleIncr);
        this->add(PilatusDet2thetaString, asynParamFloat64, &PilatusDet2theta);
        this->add(PilatusPolarizationString, asynParamFloat64, &PilatusPolarization);
        this->add(PilatusAlphaString, asynParamFloat64, &PilatusAlpha);
        this->add(PilatusKappaString, asynParamFloat64, &PilatusKappa);
        this->add(PilatusPhiString, asynParamFloat64, &PilatusPhi);
        this->add(PilatusPhiIncrString, asynParamFloat64, &PilatusPhiIncr);
        this->add(PilatusChiString, asynParamFloat64, &PilatusChi);
        this->add(PilatusChiIncrString, asynParamFloat64, &PilatusChiIncr);
        this->add(PilatusOmegaString, asynParamFloat64, &PilatusOmega);
        this->add(PilatusOmegaIncrString, asynParamFloat64, &PilatusOmegaIncr);
        this->add(PilatusOscillAxisString, asynParamOctet, &PilatusOscillAxis);
        this->add(PilatusNumOscillString, asynParamInt32, &PilatusNumOscill);
        this->add(PilatusPixelCutOffString, asynParamInt32, &PilatusPixelCutOff);
        this->add(PilatusThTemp0String, asynParamFloat64, &PilatusThTemp0);
        this->add(PilatusThTemp1String, asynParamFloat64, &PilatusThTemp1);
        this->add(PilatusThTemp2String, asynParamFloat64, &PilatusThTemp2);
        this->add(PilatusThHumid0String, asynParamFloat64, &PilatusThHumid0);
        this->add(PilatusThHumid1String, asynParamFloat64, &PilatusThHumid1);
        this->add(PilatusThHumid2String, asynParamFloat64, &PilatusThHumid2);
        this->add(PilatusTvxVersionString, asynParamOctet, &PilatusTvxVersion);
        this->add(PilatusCbfTemplateFileString, asynParamOctet, &PilatusCbfTemplateFile);
        this->add(PilatusHeaderStringString, asynParamOctet, &PilatusHeaderString);
    }

protected:
    int PilatusDelayTime;
    #define FIRST_PILATUS_PARAM PilatusDelayTime
    int PilatusThreshold;
    int PilatusThresholdApply;
    int PilatusThresholdAutoApply;
    int PilatusEnergy;
    int PilatusArmed;
    int PilatusResetPower;
    int PilatusResetPowerTime;
    int PilatusImageFileTmot;
    int PilatusBadPixelFile;
    int PilatusNumBadPixels;
    int PilatusFlatFieldFile;
    int PilatusMinFlatField;
    int PilatusFlatFieldValid;
    int PilatusGapFill;
    int PilatusWavelength;
    int PilatusEnergyLow;
    int PilatusEnergyHigh;
    int PilatusDetDist;
    int PilatusDetVOffset;
    int PilatusBeamX;
    int PilatusBeamY;
    int PilatusFlux;
    int PilatusFilterTransm;
    int PilatusStartAngle;
    int PilatusAngleIncr;
    int PilatusDet2theta;
    int PilatusPolarization;
    int PilatusAlpha;
    int PilatusKappa;
    int PilatusPhi;
    int PilatusPhiIncr;
    int PilatusChi;
    int PilatusChiIncr;
    int PilatusOmega;
    int PilatusOmegaIncr;
    int PilatusOscillAxis;
    int PilatusNumOscill;
    int PilatusPixelCutOff;
    int PilatusThTemp0;
    int PilatusThTemp1;
    int PilatusThTemp2;
    int PilatusThHumid0;
    int PilatusThHumid1;
    int PilatusThHumid2;
    int PilatusTvxVersion;
    int PilatusCbfTemplateFile;
    int PilatusCbfTemplateTransfer;
    int PilatusHeaderString;
};

#endif  // PilatusDetectorParamSet_H
