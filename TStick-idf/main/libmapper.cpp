#include "TStick.h"

mpr_dev libmapper_dev;
mpr_sig sigRawCapsense;
mpr_sig sigRawGyroX;
mpr_sig sigRawGyroY;
mpr_sig sigRawGyroZ;
mpr_sig sigRawAcclX;
mpr_sig sigRawAcclY;
mpr_sig sigRawAcclZ;
mpr_sig sigRawMagnX;
mpr_sig sigRawMagnY;
mpr_sig sigRawMagnZ;
mpr_sig sigRawFSR;
mpr_sig sigRawPiezo;
mpr_sig sigQuarternion1;
mpr_sig sigQuarternion2;
mpr_sig sigQuarternion3;
mpr_sig sigQuarternion4;
mpr_sig sigYaw;
mpr_sig sigPitch;
mpr_sig sigRoll;
mpr_sig sigMagGyro;
mpr_sig sigMagAccl;
mpr_sig sigMagMagn;
mpr_sig sigButton;
mpr_sig sigLongButton;
mpr_sig sigDoubleButton;
mpr_sig sigtouchAll;
mpr_sig sigtouchTop;
mpr_sig sigtouchMiddle;
mpr_sig sigtouchBottom;
mpr_sig sigBrush;
mpr_sig sigRub;
mpr_sig sigMultiBrush;
mpr_sig sigMultiRub;
mpr_sig sigShakeXYZ;
mpr_sig sigJabXYZ;

void initLibmapper() {
  Serial.println("Starting libmapper...");
  char namespaceBuffer[30];
  snprintf(namespaceBuffer, (sizeof(namespaceBuffer) - 1), "TStick_%i",
           Tstick.id);
  libmapper_dev = mpr_dev_new(namespaceBuffer, 0);

  int rawCapsenseMin[(nCapsenses * 16)] = {0};
  int rawCapsenseMax[(nCapsenses * 16)];
  for (int i = 0; i < (nCapsenses * 16); ++i) {
    rawCapsenseMax[i] = 1;
  }
  float rawGyroMin[1] = {-34.90659f}, rawGyroMax[1] = {34.90659f};
  float rawAcclMin[1] = {-32767.0f}, rawAcclMax[1] = {32767.0f};
  float rawMagnMin[1] = {-32767.0f}, rawMagnMax[1] = {32767.0f};
  int rawFSRMin[1] = {0}, rawFSRMax[1] = {4095};
  int rawPiezoMin[1] = {0}, rawPiezoMax[1] = {1023};
  float quarternionMin[1] = {-1.0f}, quarternionMax[1] = {1.0f};
  float magMin[1] = {0.0f}, magMax[1] = {1.7320508f};  // sqrt(3)
  int buttonMin[1] = {0}, buttonMax[1] = {1};
  float yprMin[1] = {-180.0f}, yprMax[1] = {180.0f};
  float genericMin[1] = {0.0f}, genericMax[1] = {100.0f};

  sigRawCapsense =
      mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "raw/capsense", (nCapsenses * 16),
                  MPR_INT32, 0, rawCapsenseMin, rawCapsenseMax, 0, 0, 0);
  sigRawGyroX = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "raw/gyro/X", 1,
                            MPR_FLT, 0, rawGyroMin, rawGyroMax, 0, 0, 0);
  sigRawGyroY = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "raw/gyro/Y", 1,
                            MPR_FLT, 0, rawGyroMin, rawGyroMax, 0, 0, 0);
  sigRawGyroZ = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "raw/gyro/Z", 1,
                            MPR_FLT, 0, rawGyroMin, rawGyroMax, 0, 0, 0);
  sigRawAcclX = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "raw/accl/X", 1,
                            MPR_FLT, 0, rawAcclMin, rawAcclMax, 0, 0, 0);
  sigRawAcclY = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "raw/accl/Y", 1,
                            MPR_FLT, 0, rawAcclMin, rawAcclMax, 0, 0, 0);
  sigRawAcclZ = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "raw/accl/Z", 1,
                            MPR_FLT, 0, rawAcclMin, rawAcclMax, 0, 0, 0);
  sigRawMagnX = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "raw/magn/X", 1,
                            MPR_FLT, 0, rawMagnMin, rawMagnMax, 0, 0, 0);
  sigRawMagnY = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "raw/magn/Y", 1,
                            MPR_FLT, 0, rawMagnMin, rawMagnMax, 0, 0, 0);
  sigRawMagnZ = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "raw/magn/Z", 1,
                            MPR_FLT, 0, rawMagnMin, rawMagnMax, 0, 0, 0);
  sigRawFSR = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "raw/fsr", 1, MPR_INT32,
                          0, rawFSRMin, rawFSRMax, 0, 0, 0);
  sigRawPiezo = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "raw/piezo", 1,
                            MPR_INT32, 0, rawPiezoMin, rawPiezoMax, 0, 0, 0);
  sigQuarternion1 =
      mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "quarternion/1", 1, MPR_FLT, 0,
                  quarternionMin, quarternionMax, 0, 0, 0);
  sigQuarternion2 =
      mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "quarternion/2", 1, MPR_FLT, 0,
                  quarternionMin, quarternionMax, 0, 0, 0);
  sigQuarternion3 =
      mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "quarternion/3", 1, MPR_FLT, 0,
                  quarternionMin, quarternionMax, 0, 0, 0);
  sigQuarternion4 =
      mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "quarternion/4", 1, MPR_FLT, 0,
                  quarternionMin, quarternionMax, 0, 0, 0);
  sigYaw = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "euler/yaw", 1, MPR_FLT, 0,
                       yprMin, yprMax, 0, 0, 0);
  sigPitch = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "euler/pitch", 1, MPR_FLT,
                         0, yprMin, yprMax, 0, 0, 0);
  sigRoll = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "euler/roll", 1, MPR_FLT, 0,
                        yprMin, yprMax, 0, 0, 0);
  sigMagGyro = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "gyro/magnitude", 1,
                           MPR_FLT, 0, magMin, magMax, 0, 0, 0);
  sigMagAccl = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "accl/magnitude", 1,
                           MPR_FLT, 0, magMin, magMax, 0, 0, 0);
  sigMagMagn = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "magn/magnitude", 1,
                           MPR_FLT, 0, magMin, magMax, 0, 0, 0);
  sigButton = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "button/short", 1,
                          MPR_INT32, 0, buttonMin, buttonMax, 0, 0, 0);
  sigLongButton = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "button/long", 1,
                              MPR_INT32, 0, buttonMin, buttonMax, 0, 0, 0);
  sigDoubleButton = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "button/double", 1,
                                MPR_INT32, 0, buttonMin, buttonMax, 0, 0, 0);
  sigBrush = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "instrument/brush", 1,
                         MPR_FLT, 0, genericMin, genericMax, 0, 0, 0);
  sigRub = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "instrument/rub", 1, MPR_FLT,
                       0, genericMin, genericMax, 0, 0, 0);
  sigMultiBrush =
      mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "instrument/multibrush", 4,
                  MPR_FLT, 0, genericMin, genericMax, 0, 0, 0);
  sigMultiRub = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "instrument/multirub",
                            3, MPR_FLT, 0, genericMin, genericMax, 0, 0, 0);
  sigShakeXYZ = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "instrument/shakexyz",
                            3, MPR_FLT, 0, genericMin, genericMax, 0, 0, 0);
  sigJabXYZ = mpr_sig_new(libmapper_dev, MPR_DIR_OUT, "instrument/jabxyz", 3,
                          MPR_FLT, 0, genericMin, genericMax, 0, 0, 0);
}

void updateLibmapper() {
  mpr_dev_poll(libmapper_dev, 0);

  // mpr_sig_set_value(sigRawCapsense, 0, sizeof(RawData.touchStrips),
  // MPR_INT32,
  //                   RawData.touchStrips);
  mpr_sig_set_value(sigRawFSR, 0, 1, MPR_FLT, &RawData.fsr);
  mpr_sig_set_value(sigRawPiezo, 0, 1, MPR_FLT, &RawData.piezo);
  mpr_sig_set_value(sigRawAcclX, 0, 1, MPR_FLT, &RawData.accl[0]);
  mpr_sig_set_value(sigRawAcclY, 0, 1, MPR_FLT, &RawData.accl[1]);
  mpr_sig_set_value(sigRawAcclZ, 0, 1, MPR_FLT, &RawData.accl[2]);
  mpr_sig_set_value(sigRawGyroX, 0, 1, MPR_FLT, &RawData.gyro[0]);
  mpr_sig_set_value(sigRawGyroY, 0, 1, MPR_FLT, &RawData.gyro[1]);
  mpr_sig_set_value(sigRawGyroZ, 0, 1, MPR_FLT, &RawData.gyro[2]);
  mpr_sig_set_value(sigRawMagnX, 0, 1, MPR_FLT, &RawData.magn[0]);
  mpr_sig_set_value(sigRawMagnY, 0, 1, MPR_FLT, &RawData.magn[1]);
  mpr_sig_set_value(sigRawMagnZ, 0, 1, MPR_FLT, &RawData.magn[2]);
  mpr_sig_set_value(sigQuarternion1, 0, 1, MPR_FLT, &RawData.quat[0]);
  mpr_sig_set_value(sigQuarternion2, 0, 1, MPR_FLT, &RawData.quat[1]);
  mpr_sig_set_value(sigQuarternion3, 0, 1, MPR_FLT, &RawData.quat[2]);
  mpr_sig_set_value(sigQuarternion4, 0, 1, MPR_FLT, &RawData.quat[3]);
  mpr_sig_set_value(sigMagGyro, 0, 1, MPR_FLT, &RawData.magGyro);
  mpr_sig_set_value(sigMagAccl, 0, 1, MPR_FLT, &RawData.magAccl);
  mpr_sig_set_value(sigMagMagn, 0, 1, MPR_FLT, &RawData.magMagn);
  mpr_sig_set_value(sigButton, 0, 1, MPR_INT32, &RawData.buttonShort);
  mpr_sig_set_value(sigLongButton, 0, 1, MPR_INT32, &RawData.buttonLong);
  mpr_sig_set_value(sigDoubleButton, 0, 1, MPR_INT32, &RawData.buttonDouble);
  mpr_sig_set_value(sigYaw, 0, 1, MPR_FLT, &InstrumentData.ypr[0]);
  mpr_sig_set_value(sigPitch, 0, 1, MPR_FLT, &InstrumentData.ypr[1]);
  mpr_sig_set_value(sigRoll, 0, 1, MPR_FLT, &InstrumentData.ypr[2]);
  mpr_sig_set_value(sigtouchAll, 0, 1, MPR_FLT, &InstrumentData.touchAll);
  mpr_sig_set_value(sigtouchTop, 0, 1, MPR_FLT, &InstrumentData.touchTop);
  mpr_sig_set_value(sigtouchMiddle, 0, 1, MPR_FLT, &InstrumentData.touchMiddle);
  mpr_sig_set_value(sigtouchBottom, 0, 1, MPR_FLT, &InstrumentData.touchBottom);
  mpr_sig_set_value(sigBrush, 0, 1, MPR_FLT, &InstrumentData.brush);
  mpr_sig_set_value(sigRub, 0, 1, MPR_FLT, &InstrumentData.rub);
  mpr_sig_set_value(sigMultiBrush, 0, 4, MPR_FLT, RawData.touchStrips);
  mpr_sig_set_value(sigMultiRub, 0, 3, MPR_FLT, RawData.touchStrips);
  mpr_sig_set_value(sigShakeXYZ, 0, 3, MPR_FLT, RawData.touchStrips);
  mpr_sig_set_value(sigJabXYZ, 0, 3, MPR_FLT, RawData.touchStrips);
}
