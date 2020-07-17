/* OlxAPI.h : C header file for the OlxAPI.DLL
   Copyright (c) 1987-2020 Advanced Systems for Power Engineering, Inc. (ASPEN).
   All rights reserved. 
*/

#pragma once

// To be shipped with OneLiner V14 only
#define OLRXAPI_OK                        1
#define OLRXAPI_FAILED                    0
#define OLRXAPI_FAILURE                   0
#define OLRXAPI_DATAFILEANOMALIES         2
#define OLRXAPI_STATE_UNINITIALIZED       0
#define OLRXAPI_STATE_INITIALIZED         1
#define OLRXAPI_STATE_SCRIPTINITIALIZED   2
///
#define OLXAPI_OK                        1
#define OLXAPI_FAILED                    0
#define OLXAPI_FAILURE                   0
#define OLXAPI_DATAFILEANOMALIES         2
#define OLXAPI_STATE_UNINITIALIZED       0
#define OLXAPI_STATE_INITIALIZED         1
#define OLXAPI_STATE_SCRIPTINITIALIZED   2

// Object type codes
#define TC_NOTHING 0
#define TC_BUS 1
#define TC_LOAD 2
#define TC_LOADUNIT 3
#define TC_SHUNT 4
#define TC_SHUNTUNIT 5
#define TC_GEN 6
#define TC_GENUNIT 7
#define TC_SVD 8
#define TC_BRANCH 9
#define TC_LINE 10
#define TC_XFMR 11
#define TC_XFMR3 12
#define TC_PS 13
#define TC_SCAP 14
#define TC_MU 15
#define TC_AREA 16
#define TC_ZONE 17
#define TC_NOTE 18
#define TC_SYS 19
#define TC_RLYGROUP 20
#define TC_RLYOC 21
#define TC_RLYOCG 21
#define TC_RLYOCP 22
#define TC_RLYDS 23
#define TC_RLYDSG 23
#define TC_RLYDSP 24
#define TC_FUSE 25
#define TC_PF 26
#define TC_SC 27
#define TC_SWITCH 28
#define TC_RECLSR 29
#define TC_RECLSRP 29
#define TC_RECLSRG 30
#define TC_SCHEME 31
#define TC_BREAKER 32
#define TC_CCGEN 33
#define TC_RLYD 34
#define TC_RLYV 35
#define TC_PILOT 36
#define TC_ZCORRECT 37
#define TC_BLOB 38
#define TC_DCLINE2 39
#define TC_LINEKINK 40
#define TC_RLYLINK 41
#define TC_LTC 42
#define TC_LTC3 43
#define TC_SETTINGS 44
#define TC_COUNT 44
#define TC_PICKED 100
#define TC_PICKED1 100
#define TC_PICKED2 101
#define TC_PICKED3 102

// Special obj handles
#define HND_SYS 1
#define HND_PF 2
#define HND_SC 3

#define VT_STRING 1
#define VT_DOUBLE 2
#define VT_INTEGER 3
#define VT_ARRAYSTRING 4
#define VT_ARRAYDOUBLE 5
#define VT_ARRAYINT 6


// Parameter tokens
// 100s: string
// 200s: double
// 300s: integers
// 400s: arrays of strings (tab delimited)
// 500s: arrays of doubles
// 600s: arrays of integers
#define BUS_sName 101
#define BUS_sLocation 102
#define BUS_sComment 103
#define GU_sID 104
#define GU_sOnDate 105
#define GU_sOffDate 106
#define SU_sID 107
#define SU_sOnDate 108
#define SU_sOffDate 109
#define LU_sID 110
#define LU_sOnDate 111
#define LU_sOffDate 112
#define BUS_dKVnominal 201
#define BUS_dKVP 202
#define BUS_dAngleP 203
#define BUS_dSPCx 204
#define BUS_dSPCy 205
#define LD_dPload 206
#define LD_dQload 207
#define GE_dScheduledV 208
#define GE_dRefAngle 209
#define GE_dScheduledP 210
#define GE_dScheduledQ 211
#define GE_dPgen 212
#define GE_dQgen 213
#define GE_dVSourcePU 214
#define GE_dCurrLimit1 215
#define GE_dCurrLimit2 216
#define SV_dVmax 217
#define SV_dVmin 218
#define SV_dB 219
#define GU_dMVArating 220
#define GU_dRz 221
#define GU_dXz 222
#define GU_dMVA 223
#define GU_dPmin 224
#define GU_dPmax 225
#define GU_dQmin 226
#define GU_dQmax 227
#define GU_dSchedP 228
#define GU_dSchedQ 229
#define SU_dG 230
#define SU_dB 231
#define SU_dG0 232
#define SU_dB0 233
#define LU_dPload 234
#define LU_dQload 235
#define BUS_nNumber 301
#define BUS_nArea 302
#define BUS_nZone 303
#define BUS_nTapBus 304
#define BUS_nSubGroup 305
#define BUS_nSlack 306
#define BUS_nVisible 307
#define LD_nActive 308
#define LD_nBusHnd 309
#define GE_nCtrlBusHnd 310
#define GE_nSlack 311
#define GE_nActive 312
#define GE_nFixedPQ 313
#define GE_nBusHnd 314
#define GU_nOnline 315
#define GU_nGenHnd 316
#define GU_vdR 503
#define GU_vdX 504
#define SV_nActive 316
#define SV_nCtrlBusHnd 317
#define SV_nCtrlMode 318
#define SV_vnNoStep 619
#define SV_nBusHnd 320
#define SH_nBusHnd 321
#define SU_nOnline 322
#define SU_nShuntHnd 323
#define SU_n3WX 323
#define LU_nOnline 324
#define LU_nLoadHnd 325
#define LU_vdMW 501
#define LU_vdMVAR 502
#define SV_vdBinc 505
#define SV_vdB0inc 506
#define BR_nType 301
#define BR_nHandle 302
#define BR_nBus1Hnd 303
#define BR_nBus2Hnd 304
#define BR_nBus3Hnd 305
#define BR_nRlyGrp1Hnd 306
#define BR_nRlyGrp2Hnd 307
#define BR_nRlyGrp3Hnd 308
#define BR_nInService 309
#define SY_sFComment 101
#define SY_dBaseMVA 202
#define SY_nNObus 303
#define SY_nNOgen 304
#define SY_nNOload 305
#define SY_nNOshunt 306
#define SY_nNOline 307
#define SY_nNOseriescap 308
#define SY_nNOxfmr 309
#define SY_nNOxfmr3 310
#define SY_nNOps 311
#define SY_nNOmutual  312
#define SY_nNOswitch  313,
#define SY_nNOloadUnit 314
#define SY_nNOsvd 315
#define SY_nNOrlyOCP 316
#define SY_nNOrlyOCG 317
#define SY_nNOrlyDSP 318
#define SY_nNOrlyDSG 319
#define SY_nNOrlyD 320
#define SY_nNOrlyV 321
#define SY_nNOfuse 322
#define SY_nNOrecloserG 323
#define SY_nNOrecloserP 324
#define SY_nNOshuntUnit 325
#define SY_nNOccgen 326
#define SY_nNObreaker 327
#define SY_nNOscheme 328
#define SY_nNOIED 329
#define LN_sName 101
#define LN_sID 102
#define LN_sLengthUnit 103
#define LN_sType 104
#define LN_sOnDate 105
#define LN_sOffDate 106
#define LN_dR 201
#define LN_dX 202
#define LN_dR0 203
#define LN_dX0 204
#define LN_dG1 205
#define LN_dB1 206
#define LN_dG2 207
#define LN_dB2 208
#define LN_dG10 209
#define LN_dB10 210
#define LN_dG20 211
#define LN_dB20 212
#define LN_dLength 213
#define LN_nBus1Hnd 301
#define LN_nBus2Hnd 302
#define LN_nRlyGr1Hnd 303
#define LN_nRlyGr2Hnd 304
#define LN_nInService 305
#define LN_nMuPairHnd 306
#define LN_vdRating 501
#define XR_sName 101
#define XR_sID 102
#define XR_sCfgP 103
#define XR_sCfgS 104
#define XR_sCfgST 105
#define XR_sCfg1 103
#define XR_sCfg2 104
#define XR_sCfg2T 105
#define XR_sOnDate 106
#define XR_sOffDate 107
#define XR_dRG1 201
#define XR_dXG1 202
#define XR_dRG2 203
#define XR_dXG2 204
#define XR_dRGN 205
#define XR_dXGN 206
#define XR_dMVA 207
#define XR_dPriTap 208
#define XR_dSecTap 209
#define XR_dTap1 210
#define XR_dTap2 211
#define XR_dR 212
#define XR_dX 213
#define XR_dB 214
#define XR_dR0 215
#define XR_dX0 216
#define XR_dB0 217
#define XR_dMinTap 218
#define XR_dMaxTap 219
#define XR_dMaxVW 220
#define XR_dMinVW 221
#define XR_dLTCstep 222
#define XR_dG1 223
#define XR_dB1 224
#define XR_dG2 225
#define XR_dB2 226
#define XR_dG10 227
#define XR_dB10 228
#define XR_dG20 229
#define XR_dB20 230
#define XR_dMVA1 231
#define XR_dMVA2 232
#define XR_dMVA3 233
#define XR_dBaseMVA 234
#define XR_dLTCCenterTap 235
#define XR_nBus1Hnd 301
#define XR_nBus2Hnd 302
#define XR_nLTCCtrlBusHnd 303
#define XR_nMetered 304
#define XR_nInService 305
#define XR_nLTCside 306
#define XR_nLTCtype 307
#define XR_nAuto 308
#define XR_nRlyGr1Hnd 309
#define XR_nRlyGr2Hnd 310
#define XR_nLTCPriority 311
#define XR_nLTCGanged 312
#define X3_sName 101
#define X3_sID 102
#define X3_sCfgP 103
#define X3_sCfgS 104
#define X3_sCfgT 105
#define X3_sCfgST 106
#define X3_sCfgTT 107
#define X3_sCfg1 103
#define X3_sCfg2 104
#define X3_sCfg3 105
#define X3_sCfg2T 106
#define X3_sCfg3T 107
#define X3_sOnDate 108
#define X3_sOffDate 109
#define X3_dPriTap 201
#define X3_dSecTap 202
#define X3_dTerTap 203
#define X3_dTap1 204
#define X3_dTap2 205
#define X3_dTap3 206
#define X3_dRps 207
#define X3_dXps 208
#define X3_dR0ps 209
#define X3_dX0ps 210
#define X3_dRpt 211
#define X3_dXpt 212
#define X3_dR0pt 213
#define X3_dX0pt 214
#define X3_dRst 215
#define X3_dXst 216
#define X3_dR0st 217
#define X3_dX0st 218
#define X3_dB 219
#define X3_dB0 220
#define X3_dRG1 221
#define X3_dRG2 222
#define X3_dRG3 223
#define X3_dXG1 224
#define X3_dXG2 225
#define X3_dXG3 226
#define X3_dRGN 227
#define X3_dXGN 228
#define X3_dMVA1 229
#define X3_dMVA2 230
#define X3_dMVA3 231
#define X3_dBaseMVA 232
#define X3_dLTCCenterTap 233
#define X3_dMinVW 234
#define X3_dMaxVW 235
#define X3_dMinTap 236
#define X3_dMaxTap 237
#define X3_dLTCstep 238
#define X3_nInService 301
#define X3_nBus1Hnd 302
#define X3_nBus2Hnd 303
#define X3_nBus3Hnd 304
#define X3_nAuto 305
#define X3_nFictBusNo 306
#define X3_nRlyGr1Hnd 307
#define X3_nRlyGr2Hnd 308
#define X3_nRlyGr3Hnd 309
#define X3_nLTCPriority 310
#define X3_nLTCGanged 311
#define XR3_nLTCCtrlBusHnd 312
#define PS_sName 101
#define PS_sID 102
#define PS_sOnDate 103
#define PS_sOffDate 104
#define PS_dAngle 201
#define PS_dR 202
#define PS_dX 203
#define PS_dB 204
#define PS_dR0 205
#define PS_dX0 206
#define PS_dB0 207
#define PS_dR2 208
#define PS_dX2 209
#define PS_dB2 210
#define PS_dAngleMax 211
#define PS_dAngleMin 212
#define PS_dMWmax 213
#define PS_dMWmin 214
#define PS_dMVA1 215
#define PS_dMVA2 216
#define PS_dMVA3 217
#define PS_nInService 318
#define PS_nBus1Hnd 319
#define PS_nBus2Hnd 320
#define PS_nControlMode 321
#define PS_nRlyGr1Hnd 322
#define PS_nRlyGr2Hnd 323
#define SC_sName 101
#define SC_sID 102
#define SC_sOnDate 103
#define SC_sOffDate 104
#define SC_dX 201
#define SC_dR 202
#define SC_dX0 203
#define SC_dR0 204
#define SC_dIpr 205
#define SC_nBus1Hnd 306
#define SC_nBus2Hnd 307
#define SC_nInService 308
#define SC_nSComp 309
#define SC_nRlyGr1Hnd 310
#define SC_nRlyGr2Hnd 311
#define MU_dFrom1 201
#define MU_dFrom2 202
#define MU_dTo1 203
#define MU_dTo2 204
#define MU_dX 205
#define MU_dR 206
#define MU_nHndLine1 307
#define MU_nHndLine2 308
#define MU_nOrient1 309
#define MU_nOrient2 310
#define MU_vdX 511
#define MU_vdR 512
#define MU_vdFrom1 513
#define MU_vdFrom2 514
#define MU_vdTo1 515
#define MU_vdTo2 516
#define RG_sNote 101
#define RG_dBreakerTime 201
#define RG_nInService 302
#define RG_nBranchHnd 303
#define RG_nPrimaryHnd 304
#define RG_nBackupHnd 305
#define RG_nTripLogicHnd 306
#define RG_nReclLogicHnd 307
#define RG_nOps 308
#define RG_vdRecloseInt 501
#define OG_sID 101
#define OG_sAssetID 102
#define OG_sType 103
#define OG_sComment 104
#define OG_sLibrary 105
#define OP_sID 106
#define OP_sAssetID 107
#define OP_sType 108
#define OP_sComment 109
#define OP_sLibrary 110
#define FS_sID 111
#define FS_sAssetID 112
#define FS_sType 113
#define FS_sComment 114
#define FS_sLibrary 115
#define OG_dCT 201
#define OG_dTap 202
#define OG_dTDial 203
#define OG_dInst 204
#define OG_dInstDelay 205
#define OG_dTimeAdd 206
#define OG_dTimeMult 207
#define OG_dTimeAdd2 208
#define OG_dTimeMult2 209
#define OG_dResetTime 210
#define OP_dCT 211
#define OP_dTap 212
#define OP_dTDial 213
#define OP_dInst 214
#define OP_dInstDelay 215
#define OP_dTimeAdd 216
#define OP_dTimeMult 217
#define OP_dTimeAdd2 218
#define OP_dTimeMult2 219
#define OP_dVCtrlRestPcnt 220
#define OP_dResetTime 221
#define OP_nRlyGrHnd 301
#define OG_nRlyGrHnd 302
#define OG_nInService 303
#define OG_nDirectional 304
#define OG_nIDirectional 305
#define OG_nPolar 306
#define OG_nFlatDelay 307
#define OG_nDCOffset 308
#define OG_nSignalOnly 309
#define OP_nInService 310
#define OP_nDirectional 311
#define OP_nIDirectional 312
#define OP_nPolar 313
#define OP_nByCTConnect 314
#define OP_nFlatDelay 315
#define OP_nDCOffset 316
#define OP_nSignalOnly 317
#define OP_nVoltControl 318
#define FS_nRlyGrHnd 319
#define FS_nInService 320
#define FS_nCurve 321
#define OG_vdDirSetting 501
#define OP_vdDirSetting 502
#define DG_sID 101
#define DG_sAssetID 102
#define DG_sType 103
#define DG_sDSType 104
#define DG_sComment 105
#define DG_sLibrary 106
#define DG_sParam 107
#define DP_sID 108
#define DP_sAssetID 109
#define DP_sType 110
#define DP_sDSType 111
#define DP_sComment 112
#define DP_sLibrary 113
#define DP_sParam 114
#define DG_dCT 201
#define DG_dVT 202
#define DG_dKmag 203
#define DG_dKang 204
#define DG_dMinI 205
#define DP_dCT 206
#define DP_dVT 207
#define DP_dMinI 208
#define DG_nInService 301
#define DG_nRlyGrHnd 302
#define DG_nParamCount 303
#define DG_nSignalOnly 304
#define DP_nInService 305
#define DP_nRlyGrHnd 306
#define DP_nParamCount 307
#define DP_nSignalOnly 308
#define DG_vdParams 501
#define DG_vParams 402
#define DG_vParamLabels 403
#define DG_vdDelay 504
#define DG_vdReach 505
#define DG_vdReach1 506
#define DP_vdParams 507
#define DP_vParams 408
#define DP_vParamLabels 409
#define DP_vdDelay 510
#define DP_vdReach 511
#define DP_vdReach1 512
#define CP_sID 101
#define CP_sAssetID 102
#define CP_sTypeFast 103
#define CP_sTypeSlow 104
#define CP_sComment 105
#define CP_sLibrary 106
#define CG_sID 107
#define CG_sAssetID 108
#define CG_sTypeFast 109
#define CG_sTypeSlow 110
#define CG_sComment 111
#define CG_sLibrary 112
#define CP_dPickupF 201
#define CP_dPickupS 202
#define CP_dTimeAddF 203
#define CP_dTimeAddS 204
#define CP_dTimeMultF 205
#define CP_dTimeMultS 206
#define CP_dMinTF 207
#define CP_dMinTS 208
#define CP_dHiAmps 209
#define CP_dHiAmpsDelay 210
#define CP_dRecIntvl1 211
#define CP_dRecIntvl2 212
#define CP_dRecIntvl3 213
#define CP_dIntrTime 214
#define CG_dPickupF 215
#define CG_dPickupS 216
#define CG_dTimeAddF 217
#define CG_dTimeAddS 218
#define CG_dTimeMultF 219
#define CG_dTimeMultS 220
#define CG_dMinTF 221
#define CG_dMinTS 222
#define CG_dHiAmps 223
#define CG_dHiAmpsDelay 224
#define CG_dRecIntvl1 225
#define CG_dRecIntvl2 226
#define CG_dRecIntvl3 227
#define CG_dIntrTime 228
#define CP_nInService 301
#define CP_nTotalOps 302
#define CP_nFastOps 303
#define CP_nCurveInUse 304
#define CP_nTAddAppl 305
#define CP_nTMultAppl 306
#define CP_nRlyGrHnd 307
#define CG_nInService 308
#define CG_nTotalOps 309
#define CG_nFastOps 310
#define CG_nCurveInUse 311
#define CG_nTAddAppl 312
#define CG_nTMultAppl 313
#define CG_nRlyGrHnd 314
#define FT_dXPt 201
#define FT_dRPt 202
#define FT_dXNt 203
#define FT_dRNt 204
#define FT_dXZt 205
#define FT_dRZt 206
#define FT_dRt 207
#define FT_dXt 208
#define FT_dXR 209
#define FT_dMVA 210
#define FT_dXRANSI 211
#define FT_nNOfaults 301
#define SW_sID 101
#define SW_sName 102
#define SW_sOnDate 103
#define SW_sOffDate 104
#define SW_dRating 201
#define SW_nBus1Hnd 301
#define SW_nBus2Hnd 302
#define SW_nRlyGrHnd1 303
#define SW_nRlyGrHnd2 304
#define SW_nInService 305
#define SW_nStatus 306
#define SW_nDefault 307
#define CC_sOnDate 101
#define CC_sOffDate 102
#define CC_dMVArating 201
#define CC_dVmax 202
#define CC_dVmin 203
#define CC_nVloc 301
#define CC_nInService 302
#define CC_vdV 501
#define CC_vdI 502
#define CC_vdAng 503
#define RD_sID 101
#define RD_sAssetID 102
#define RD_sTLCCurvePh 103
#define RD_sTLCCurveI0 104
#define RD_sTLCCurveI2 105
#define RV_sID 106
#define RV_sAssetID 107
#define RV_sOVCurve 108
#define RV_sUVCurve 109
#define RD_dCTR1 201
#define RD_dPickupPh 202
#define RD_dPickup3I0 203
#define RD_dPickup3I2 204
#define RD_dTLCTDDelayPh 205
#define RD_dTLCTDDelayI0 206
#define RD_dTLCTDDelayI2 207
#define RV_dCTR 208
#define RV_dOVTPickup 209
#define RV_dOVTDelay 210
#define RV_dOVIPickup 211
#define RV_dUVTPickup 212
#define RV_dUVTDelay 213
#define RV_dUVIPickup 214
#define RD_nRlyGrpHnd 301
#define RD_nLocalCTHnd1 302
#define RD_nRmeDevHnd1 303
#define RD_nRmeDevHnd2 304
#define RD_nSignalOnly 305
#define RD_nInService 306
#define RV_nRlyGrpHnd 307
#define RV_nSignalOnly 308
#define RV_nVoltOperate 309
#define RV_nInService 310
#define BK_sID 101
#define BK_sEquipGrp1 102
#define BK_sEquipGrp2 103
#define BK_dRating1 201
#define BK_dRating2 202
#define BK_dCPT1 203
#define BK_dCPT2 204
#define BK_dCycles 205
#define BK_dOperatingKV 206
#define BK_dRatedKV 207
#define BK_dK 208
#define BK_dNACD 209
#define BK_nRatingType 301
#define BK_nTotalOps1 302
#define BK_nTotalOps2 303
#define BK_nDontDerate 304
#define BK_nInService 305
#define BK_nInterrupt1 306
#define BK_nInterrupt2 307
#define BK_nBusHnd 308
#define BK_vdRecloseInt1 501
#define BK_vdRecloseInt2 502
#define BK_vnG1DevHnd 603
#define BK_vnG1OutageHnd 604
#define BK_vnG2DevHnd 605
#define BK_vnG2OutageHnd 606
#define LS_sID 101
#define LS_sAssetID 102
#define LS_sScheme 103
#define LS_sEquation 104
#define LS_sVariables 105
#define LS_nSignalOnly 301
#define LS_nInService 302
#define LS_nRlyGrpHnd 303

#define SF_LAST -1
#define SF_NEXT -2
#define SF_FIRST 1
#define SF_PREV -4

// API functions declarations; To be shipped with OneLiner V14 only
int __stdcall OlrxAPIBoundaryEquivalent( char *szEquFileName, int *nBusList, double *dFltOpt );
int __stdcall OlrxAPIComputeRelayTime( int nRelayHnd,
   double *dCurMag, double *dCurAng,   // 3 phases plus two neutral currents
   double *dVMag, double *dVAng,       // 3 phases voltages
   double dVpreMag, double dVpreAng,
   double *pTime, char *szDevice );
int __stdcall OlrxAPIDeleteEquipment( int nDeviceHnd );
int __stdcall OlrxAPIDoBreakerRating(
   int* nScope,         //[1]: 0-IEEE;1-IEC
                        //[2]: 0-All;1-Area;2-Zone;3-Selected
                        //[3]: Area or zone number
                        //...: or list of bus hnd terminated with -1
   double dThreshold,   // Rating threshold
   double dOutputOpt,   // 0.0- all; 1.0-Overduty only; else- screening threshold
   int nOptionalReport, // Bit1-Detailed sim result; Bit2-Name plate data; 
                        // Bit3-Conn equipment list
   char* szReportTXT,
   char* szReportCSV,
   char* szConfigFile );
int __stdcall OlrxAPIDoFault( int nDevHnd, int *nFltConn,
   double *dFltOpt, int *nOutageOpt, int *nOutageLst,
   double dFltR, double dFltX, int nFlag );
int __stdcall OlrxAPIDoSteppedEvent( int nDevHnd, double *dFltOpt, int *nDevOpt, long nTiers );
int __stdcall OlrxAPIEquipmentType( int nDevHnd );
const char* __stdcall OlrxAPIErrorString();
const char* __stdcall OlrxAPIFaultDescription( int nFltIdx );
int __stdcall OlrxAPIFindBusByName( const char* pszBusName, double dKV, int* pDeviceHnd );
int __stdcall OlrxAPIFindBusByName( const char* pszBusName, double dKV, int* pDeviceHnd );
int __stdcall OlrxAPIFindBusNo( int nBusNo );
int __stdcall OlrxAPIFindEquipmentByTag( char *szTags, int nDevType, int *pnHnd );
const char* __stdcall OlrxAPIFullBranchName( int nBranchHnd );
const char* __stdcall OlrxAPIFullBusName( int nBusHnd );
const char* __stdcall OlrxAPIFullRelayName( int nRelayHnd );
int __stdcall OlrxAPIGetBusEquipment( int nBusHnd, int nType, int* pDeviceHnd );
int __stdcall OlrxAPIGetData( int nDeviceHnd, int nParam, void *pOutput );
int __stdcall OlrxAPIGetEquipment( int nType, int *pDeviceHnd );
int __stdcall OlrxAPIGetLogicScheme( int nRlyGrHnd, long * pSchemeHnd );
int __stdcall OlrxAPIGetRelay( int nRlyGrHnd, int *pRelayHnd );
const char* __stdcall OlrxAPIGetObjJournalRecord( int nDeviceHnd );
const char* __stdcall OlrxAPIGetObjMemo( int nDeviceHnd );
const char* __stdcall OlrxAPIGetObjTags( int nDeviceHnd );
const char* __stdcall OlrxAPIGetOlrFileName();
int __stdcall OlrxAPIGetPSCVoltage( int nDeviceHnd, double *dOut1, double *dOut2, int nStyle );
int __stdcall OlrxAPIGetRelay( int nHndRlyGroup, int* nHndRelay );
int __stdcall OlrxAPIGetRelayTime( int nRelayHnd, double dFactor, double *pTime, char* szDevice, int nTripOnly );
int __stdcall OlrxAPIGetSCCurrent( int nDeviceHnd, double *dOut1, double *dOut2, int nStyle );
int __stdcall OlrxAPIGetSCVoltage( int nDeviceHnd, double *dOut1, double *dOut2, int nStyle );
int __stdcall OlrxAPIGetSteppedEvent( int nStep, double *dTime, double *dCurrent,
   int *nUserEvent, char* szEventDesc, char* szFaultDesc );
int __stdcall OlrxAPILoadDataFile( char *szFilePath, int bReadOnly );
int __stdcall OlrxAPIMakeOutageList( int nHandle, int nMxTiers, int nWantedBrType,
   int *vnList, int *pnListLen );
int __stdcall OlrxAPINextBusByName( int* pDeviceHnd );
int __stdcall OlrxAPINextBusByNumber( int* pDeviceHnd );
int __stdcall OlrxAPIPickFault( int nFltIndex, int nWantedTiers );
int __stdcall OlrxAPIPostData( int nDeviceHnd );
const char* __stdcall OlrxAPIPrintObj1LPF( int nHandle );
int __stdcall OlrxAPIReadChangeFile( char *szPathname );
int __stdcall OlrxAPIRun1LPFCommand( char *szBuf );
/* Run OneLiner/PowerFlow command
   szBuf is a XML string, or full path name to XML file, containing a XML node
   - Node name: OneLiner command
   - Node attributes and text: required command parameters
   
   Returns:
        OLXAPI_FAILURE: Failure
        OLXAPI_OK     : Success. Excepted when noted below

   Command: ARCFLASHCALCULATOR - Faults | Arc-flash hazard calculator
   Attributes:
         REPORTPATHNAME	(*) Full pathname of report file.
         APPENDREPORT            [0] Append to existing report 0-No;1-Yes
         OUTFILETYPE 	[2] Output file type 1- TXT; 2- CSV
         SELECTEDOBJ	Arcflash bus. Must  have one of following values
                  "PICKED " 	the highlighted bus on the 1-line diagram
                  "'BNAME1                ,KV1;’BNAME2’,KV2;..."  Bus name and nominal kV.
         TIERS	[0] Number of tiers around selected object. This attribute is ignored if SELECTEDOBJ is not found.
         AREAS	[0-9999] Comma delimited list of area numbers and ranges to check relaygroups agains backup.
                        This attribute is ignored if SELECTEDOBJ is found.
         ZONES	[0-9999] Comma delimited list of zone numbers and ranges to check relaygroups agains backup.
                     This attribute is ignored if AREAS or SELECTEDOBJ are found.
         KVS	[0-999] Comma delimited list of KV levels and ranges to check relaygroups agains backup.
                     This attribute is ignored if SELECTEDOBJ is found.
         TAGS	Comma delimited list of bus tags. This attribute is ignored if SELECTEDOBJ is found.
         EQUIPMENTCAT	(*) Equipment category: 0-Switch gear; 1- Cable; 2- Open air; 3- MCC                s and panelboards 1kV or lower
         GROUNDED	(*) Is the equipment grounded 0-No; 1-Yes
         ENCLOSED	(*) Is the equipment inside enclosure 0-No; 1-Yes
         CONDUCTORGAP	(*) Conductor gap in mm
         WORKDIST	(*) Working distance in inches
         ARCDURATION	Arc duration calculation method. Must have one of following values:
                  "FIXED" 	Use fixed duration
                  "FUSE " 	Use fuse curve
                  "FASTEST" 	Use fastest trip time of device in vicinity
                  "DEVICE" 	Use trip time of specified device
                  "SEA" 	Use stepped-event analysis
         ARCTIME	Arc duration in second. Must be present when ARCDURATION="FIXED"
         FUSECURVE	Fuse curve for arc duration calculation. Must be present when ARCDURATION=" FUSECURVE"
         BRKINTTIME	Breaker interrupting time in cycle. Must be present when ARCDURATION=" FASTEST" and "DEVICE"
         DEVICETIERS	[1] Number of tiers. Must be present when ARCDURATION=" FASTEST" and ="SEA"
         DEVICE	String  with location of the relaygroup and the relay name
                  "BNO1;                BNAME1                ;KV1;BNO2;                BNAME2                ;KV2;                CKT                ;BTYP; RELAY_ID; ".
                  Format description of these fields are is in OneLiner help section 10.2.
         ARCTIMELIMIT	[1] Perform no energy calculation when arc duration time is longer than 2 seconds

   Command: BUSFAULTSUMMARY : Faults | Bus fault summary
   Attributes:
      REPORTPATHNAME= (*) full valid path to report file
      BASELINECASE= pathname of base-line bus fault summary report in CSV format
      === Only when BASELINECASE is specified
      DIFFBASE= Basis for computing current deviation: [MAX3PH1LG] or MAXPHGND
      FLAGPCNT= [15] Current deviation percent threshold.
      === Only when BASELINECASE is not specified
      BUSLIST= Bus list, one on each row in format 'BusName',kV
      BUSNOLIST= Bus number list, coma delimited.
                  This attribute is ignored when BUSLIST is specified
      === Only when no BUSLIST and BUSNOLIST is  specified
      XGND= Fault reactance X
      RGND= Fault resistance R
      NOTAP= Exclude tap buses: [1]-TRUE; 0-FALSE
      PERUNITV= Report voltage in PU
      PERUNIT= Report current in PU
      AREAS= Area number range
      ZONES= Zone number range. This attribute is ignored when AREAS is specified
      BUSNOS= Additional bus number range
      KVS= Additional bus kV range
      TAGS= Additional tag filter
      TIERS= check lines in vicinity within this tier number
      AREAS= Check all lines in area range
      ZONES= Check all lines in zone range
      KVS=   Additional KV filter

   Command: CHECKRELAYOPERATIONPRC023 - Check | Relay loadability
   Attributes:
      REPORTPATHNAME= (*) full valid pathname of report file
      REPORTCOMMENT= Report comment string. 255 char or shorter
      SELECTEDOBJ=
            PICKED Check devices in selected relaygroup
            BNO1;'BNAME1';KV1;BNO2;'BNAME2';KV2;'CKT';BTYP;  location string of branch to check(OneLiner Help section 10.2)
      TIERS= check relaygroups in vicinity within this tier number
      AREAS= Check all relaygroups in area range
      ZONES= Check all relaygroups in zone range
      KVS=   Additional KV filter
      TAGS=  Additional tag filter
      USETAGFLAG= [0]-AND;[1]-OR
      DEVICETYPE= [OCP DSP] Devide type to check. Space delimited
      APPENDREPORT=	Append report file: 0-False; [1]-True
      LINERATINGTYPE=	[3] Line rating to use: 0-first; 1-second; 2-Third;	3-Fourth
      XFMRRATINGTYPE=	[2] Transformer rating to use: 0-MVA1; 1-MVA2; 2-MVA3
      FWRLOADLONLY= [0] Consider load in forward direction only
      VOLTAGEPU= [0.85] Per unit voltage
      LINECURRMULT= [1.5] Line load current multiplier
      XFMRCURRMULT= [1.5] Transformer load current multiplier
      PFANGLE= [30] Power factor angle

   Command: CHECKRELAYOPERATIONPRC026 - run Check | Relay performance in stable power swing (PRC-026-1)
   Attributes:
      REPORTPATHNAME= (*) full valid pathname of report file
      REPORTCOMMENT= Report comment string. 255 char or shorter
      SELECTEDOBJ=
            PICKED Check devices in selected relaygroup
            BNO1;'BNAME1';KV1;BNO2;'BNAME2';KV2;'CKT';BTYP;  location string of line to check(Help section 10.2)
      TIERS= check relaygroups in vicinity within this tier number
      AREAS= Check all relaygroups in area range
      ZONES= Check all relaygroups in zone range
      KVS=   Additional KV filter
      TAGS=  Additional tag filter
      DEVICETYPE= [OCP DSP] Devide type to check. Space delimited
      APPENDREPORT=	Append report file: 0-False; [1]-True
      SEPARATIONANGLE=	[120] System separation angle for stable power swing calculation
      DELAYLIMIT= [15] Report violation if relay trips faster than this limit (in cycles)
      CURRMULT= [1.0] Current multiplier to apply in relay trip checking

   Command: CHECKPRIBACKCOORD - Check | Primary/back relay coordination
   Attributes:
         REPORTPATHNAME  (*) Full pathname of report file.
         OUTFILETYPE     [2] Output file type 1- TXT; 2- CSV
         SELECTEDOBJ	Relay group to check against its backup. Must  have one of following values
         PICKED      the highlighted relaygroup on the 1-line diagram
         "BNO1;'BNAME1';KV1;BNO2;'BNAME2';KV2;'CKT';BTYP;"  location string of the relaygroup. Format description is in OneLiner help section 10.2.
         TIERS	[0] Number of tiers around selected object. This attribute is ignored if SELECTEDOBJ is not found.
         AREAS	[0-9999] Comma delimited list of area numbers and ranges to check relaygroups agains backup.
         ZONES	[0-9999] Comma delimited list of zone numbers and ranges to check relaygroups agains backup. This attribute is ignored if AREAS is found.
         KVS	0-999] Comma delimited list of KV levels and ranges to check relaygroups agains backup. This attribute is ignored if SELECTEDOBJ is found.
         TAGS	Comma delimited list of tags to check relaygroups agains backup. This attribute is ignored if SELECTEDOBJ is found.
         COORDTYPE	Coordination type to check. Must  have one of following values
         "0"	OC backup/OC primary (Classical)
         "1"	OC backup/OC primary (Multi-point)
         "2"	DS backup/OC primary
         "3"	OC backup/DS primary
         "4"	DS backup/DS primary
         "5"	OC backup/Recloser primary
         "6"	All types/All types
         LINEPERCENT	Percent interval for sliding intermediate faults. This attribute is ignored if COORDTYPE is 0 or 5.
         RUNINTERMEOP	1-true; 0-false. Check  intermediate faults with end-opened. This attribute is ignored if COORDTYPE is 0 or 5.
         RUNCLOSEIN	1-true; 0-false. Check close-in fault. This attribute is ignored if COORDTYPE is 0 or 5.
         RUNCLOSEINEOP	1-true; 0-false. Check close-in fault with end-opened. This attribute is ignored if COORDTYPE is 0 or 5.
         RUNLINEEND	1-true; 0-false. Check line-end fault. This attribute is ignored if COORDTYPE is 0 or 5.
         RUNREMOTEBUS	1-true; 0-false. Check remote bus fault. This attribute is ignored if COORDTYPE is 0 or 5.
         RELAYTYPE	Relay types to check: 1-Ground; 2-Phase; 3-Both.
         FAULTTYPE	Fault  types to check: 1-3LG; 2-2LG; 4-1LF; 8-LL; or sum of values for desired selection
         OUTPUTALL	1- Include all cases in report; 0- Include only flagged cases in report
         MINCTI	Lower limit of acceptable CTI range
         MAXCTI	Upper limit of acceptable CTI range
         OUTRLYPARAMS	Include relay settings in report: 0-None; 1-OC;2-DS;3-Both
         OUTAGELINES	Run line outage contingency: 0-False; 1-True
         OUTAGEXFMRS	Run transformer outage contingency: 0-False; 1-True
         OUTAGEMULINES	Run mutual line outage contingency: 0-False; 1-True. Ignored if OUTAGEMULINES=0
         OUTAGEMULINESGND		Run mutual line outage and grounded contingency: 0-False; 1-True. Ignored if OUTAGEMULINES=0
         OUTAGE2LINES	Run double line outage contingency: 0-False; 1-True. Ignored if OUTAGEMULINES=0
         OUTAGE1LINE1XFMR	Run double line and transformer outage contingency: 0-False; 1-True. Ignored if OUTAGEMULINES=0 or OUTAGEXFMRS =0
         OUTAGE2XFMRS	Run double and transformer outage contingency: 0-False; 1-True. Ignored if OUTAGEXFMRS =0
         OUTAGE3SOURCES	Outage only  3 strongest sources: 0-False; 1-True. Ignored if OUTAGEMULINES=0 and OUTAGEXFMRS =0

   Command: CHECKRELAYOPERATIONSEA - Check | Relay operation using stepped-events
   Attributes:
         REPORTPATHNAME	(*) Full pathname of folder for report files.
         REPORTCOMMENT		Additional comment string to include in all checking report files
         SELECTEDOBJ	Check line with selected relaygroup. Must  have one of following values
         "PICKED " 	the highlighted relaygroup on the 1-line diagram
         "BNO1;'BNAME1';KV1;BNO2;'BNAME2';KV2;'CKT';BTYP;"  location string of  the relaygroup. Format description is in OneLiner help section 10.2.
         TIERS	[0] Number of tiers around selected object. This attribute is ignored if SELECTEDOBJ is not found.
         AREAS	[0-9999] Comma delimited list of area numbers and ranges.
         ZONES	[0-9999] Comma delimited list of zone numbers and ranges. This attribute is ignored if AREAS is found.
         KVS	[0-999] Comma delimited list of KV levels and ranges. This attribute is ignored if SELECTEDOBJ is found.
         TAGS	Comma delimited list of tags. This attribute is ignored if SELECTEDOBJ is found.
         DEVICETYPE	Space delimited list of relay type types to take into consideration in stepped-events: OCG, OCP, DSG, DSP, LOGIC, VOLTAGE, DIFF
         FAULTTYPE	Space delimited list of fault  types to take into consideration in stepped-events: 1LF, 3LG
         OUTAGELINES	Run line outage contingency: 0-False; 1-True
         OUTAGEXFMRS	Run transformer outage contingency: 0-False; 1-True
         OUTAGEMULINES	Run mutual line outage contingency: 0-False; 1-True. Ignored if OUTAGEMULINES=0
         OUTAGEMULINESGND		Run mutual line outage and grounded contingency: 0-False; 1-True. Ignored if OUTAGEMULINES=0
         OUTAGE2LINES	Run double line outage contingency: 0-False; 1-True. Ignored if OUTAGEMULINES=0
         OUTAGE1LINE1XFMR	Run double line and transformer outage contingency: 0-False; 1-True. Ignored if OUTAGEMULINES=0 or OUTAGEXFMRS =0
         OUTAGE2XFMRS	Run double and transformer outage contingency: 0-False; 1-True. Ignored if OUTAGEXFMRS =0
         OUTAGE3SOURCES	Outage only  3 strongest sources: 0-False; 1-True. Ignored if OUTAGEMULINES=0 and OUTAGEXFMRS =0

   Command: SETGENREFANGLE - Network | Set generator reference angle
   Attributes:
         REPORTPATHNAME	Full pathname of folder for report files.
         REFERENCEGEN	Bus name and kV of reference generator in format: 'BNAME', KV.
         EQUSOURCEOPTION	Option for calculating reference angle of equivalent sources. Must have one of the following values
         [ROTATE] 	apply delta angle of existing reference gen
         SKIP   	Leave unchanged. This option will be in effect automatically when old reference is not valid
         ASGEN  	Use angle computed for regular generator

   Command: CHECKRELAYSETTINGS - Check | Relay settings
   Attributes:
      SELECTEDOBJ=
            PICKED Check line with selected relaygroup
            BNO1;'BNAME1';KV1;BNO2;'BNAME2';KV2;'CKT';BTYP;  location string of line to check(Help section 10.2)
      TIERS= check lines in vicinity within this tier number
      AREAS= Check all lines in area range
      ZONES= Check all lines in zone range
      KVS=   Additional KV filter
      TAGS=  Additional tag filter
      REPORTPATHNAME= (*) full valid path to report folder with write access
      REPORTCOMMENT= Report comment string. 255 char or shorter
      FAULTTYPE= 1LG, 3LG. Fault type to check. Space delimited
      DEVICETYPE= OCG, OCP, DSG, DSP, LOGIC, VOLTAGE, DIFF Devide type to check. Space delimited
      OUTAGELINES	Run Line outage contingency: 0-False; 1-True
      OUTAGEXFMRS	Run transformer outage contingency: 0-False; 1-True
      OUTAGE3SOURCES= 1 or 0 Outage only 3 strongest sources
      OUTAGEMULINES= 1 or 0 Outage mutually coupled lines
      OUTAGEMULINESGND= 1 or 0 Outage and ground ends of mutually coupled lines
      OUTAGE2LINES= 1 or 0 Double outage lines
      OUTAGE1LINE1XFMR= 1 or 0 Double outage line and transformer
      OUTAGE2XFMR= 1 or 0 Double outage transformers

   Command: EXPORTNETWORK = File | Export network data
   Attributes:
      FORMAT     = Output format: [DXT]-ASPEN DXT; PSSE-PSS/E Raw and Seq
      SCOPE      =  Export scope: [0]-Entire network; 1-Area number; 2- Zone number
      AREANO     =  Export area number
      ZONENO	  =  Export zone number
      INCLUDETIES=  Include ties: [0]-False; 1-True
      ====DXT export only:
      DXTPATHNAME= (*) full valid pathname of ouput DXT file
      ====PSSE export only:
      RAWPATHNAME= (*) full valid pathname of ouput RAW file
      SEQPATHNAME= (*) full valid pathname of ouput SEQ file
      PSSEVER	  =  [33] PSS/E version
      X3MIDBUSNO =  [18000] First fictitious bus number for 3-w transformer mid point
      NEWBUSNO   =  [15000] First bus number for buses with no bus number

   Command EXPORTRELAY - Relay | Export relay
   Attributes:
      FORMAT     =  Output format: [RAT]-ASPEN RAT;
      SCOPE      =  Export scope: [0]-Entire network; 1-Area number; 2- Zone number; 3-Invicinity of a bus
      AREANO     =  Export area number (*required when SCOPE=1)
      ZONENO	  =  Export zone number (*required when SCOPE=2)
      SELECTEDOBJ=  Selected bus (*required when SCOPE=3). Must be a string with following content
                     PICKED - Selected bus on the 1-line diagram
                     'BusName' kV - Bus name in single quotes and kV separated by space
      TIERS      =  [0] Number of tiers (ignored when SCOPE<>3)
      DEVICETYPE =  Device type to export. Comma delimied list of the following:
                     OC: Overcurrent
                     DS: Distance
                     RC: Recloser
                     VR: Voltage relay
                     DIFF: Differential relay
                     SCHEME: Logic scheme
                     COORDPAIR: Coorination pair
                     [OC,DS,RC,VR,DIFF,COORDPAIR,SCHEME]
      LASTCHANGEDDATE =  [01-01-1986] Cutoff last changed date
      RATPATHNAME= (*) full valid pathname of ouput RAT file

   Command: INSERTTAPBUS - Network | Bus | Insert tap bus
   Attributes:
      BUSNAME1=	(*) Line bus 1 name
      BUSNAME2=	(*) Line bus 2 name
      KV=	(*) Line kV
      CKTID=	(*) Line circuit ID
      PERCENT=	(*) Percent distance to tap from bus 1 (must be between 0-100)
      TAPBUSNAME=	(*) Tap bus name

   Command: SAVEDATAFILE - File | Save and File | Save as
   Attributes:
      PATHNAME     = Name or full pathname of new OLR file for File | Save as command.
                     If only file name is given, file will be saved in the folder
                     where the current OLR file is located.
                     If no attribute is specified, the File | Save command will be executed.

   Command SAVEFLTSPEC - Save desc and spec of faults in the result buffer to XML or CSV files
   Attributes:
      REPORTPATHNAME= (*) output file pathname
      APPEND= [0]: overwrite existing file; 1: Append to existing file; 
      FORMAT= output file format [0]: XML; 1: CSV
      CLEARPREV= Clear previous results flag to be recorded in the XML output
                  [0]: no; 1: yes; 
      RANGE= Comma delimited list of fault index numbers and ranges(e.g. 1,3,5-10)
             Default: save all faults in the results buffer

   Command SAVEFLTSPEC - Save desc and spec of faults in the result buffer to XML or CSV files
   Attributes:
         REPORTPATHNAME= (*)Output file pathname
         APPEND= [0]: overwrite existing file; 1: Append to existing file; 
         FORMAT= output file format [0]: XML; 1: CSV
         CLEARPREV= Clear previous results flag to be recorded in the XML output
                     [0]: no; 1: yes; 
         RANGE= Comma delimited list of fault index numbers and ranges(e.g. 1,3,5-10)
               Default: save all faults in the results buffer

   Command SIMULATEFAULT - Run OneLiner command FAULTS  | BATCH COMMAND & FAULT SPEC FILE | EXECUTE COMMAND
   Attributes: 
         <FAULT> The <SIMULATEFAULT> XML node must contain one or more children nodes <FAULT>, 
                  one for each fault case to be simulated. 
         <FLTSPEC>  Each of the <FAULT> nodes can include up to 40 fault specifications to be 
                  simulated in the case. Fault specification string in the format described in 
                  OneLiner’s user manual APPENDIX I:  FAULT SPECIFICATION FILE 
                  must be included as the text of children nodes <FLTSPEC>. 
         FLTSPCVS= Alternatively, a tab-delimited list of all the fault spec strings can be entered as 
                  the attribute "FLTSPCVS" in the <FAULT> node. 
         CLEARPREV= Clear previous result buffer flag [0]: no; 1: yes; 
   Returns:
         OLXAPI_FAILURE: Failure
         NOfault       : Total number of faults in the solution buffer
   Remark:
         When NOfault is not the value you expected, call OlxAPIErrorString() for details of simulation error

*/
int __stdcall OlrxAPISaveDataFile( char *szFilePath );
int __stdcall OlrxAPISetData( int nDeviceHnd, int nParam, void *pVal );
const char* __stdcall OlrxAPISetObjMemo( int nDeviceHnd, char *szT );
const char* __stdcall OlrxAPISetObjTags( int nDeviceHnd, char *szT );
int __stdcall OlrxAPIVersionInfo( char *szBuf );

// API functions declarations;
int __stdcall OlxAPIBoundaryEquivalent( char *szEquFileName, int *nBusList, double *dFltOpt );
int __stdcall OlxAPIComputeRelayTime( int nRelayHnd,
   double *dCurMag, double *dCurAng,   // 3 phases plus two neutral currents
   double *dVMag, double *dVAng,       // 3 phases voltages
   double dVpreMag, double dVpreAng,
   double *pTime, char *szDevice );
int __stdcall OlxAPIDeleteEquipment( int nDeviceHnd );
int __stdcall OlxAPIDoBreakerRating(
   int* nScope,         //[1]: 0-IEEE;1-IEC
                        //[2]: 0-All;1-Area;2-Zone;3-Selected
                        //[3]: Area or zone number
                        //...: or list of bus hnd terminated with -1
   double dThreshold,   // Rating threshold
   double dOutputOpt,   // 0.0- all; 1.0-Overduty only; else- screening threshold
   int nOptionalReport, // Bit1-Detailed sim result; Bit2-Name plate data; 
                        // Bit3-Conn equipment list
   char* szReportTXT,
   char* szReportCSV,
   char* szConfigFile );
int __stdcall OlxAPIDoFault( int nDevHnd, int *nFltConn,
   double *dFltOpt, int *nOutageOpt, int *nOutageLst,
   double dFltR, double dFltX, int nFlag );
int __stdcall OlxAPIDoSteppedEvent( int nDevHnd, double *dFltOpt, int *nDevOpt, long nTiers );
int __stdcall OlxAPIEquipmentType( int nDevHnd );
const char* __stdcall OlxAPIErrorString();

const char* __stdcall OlxAPIFaultDescriptionEx( 
   // Return description string of a fault in the simulation results buffer.
   int nFltIdx,      // Index number of fault case.
   int nOpt );       // Output flag:
                     // [0] Fault description string only
                     // 1   Plus FLTSPCVS on the last line
                     // 2   Plus FLTOPTSTR on the last line
                     //     See SIMULATEFAULT for details of FLTSPCVS and FLTOPTSTR 

const char* __stdcall OlxAPIFaultDescription( int nFltIdx );
int __stdcall OlxAPIFindBusByName( const char* pszBusName, double dKV, int* pDeviceHnd );
int __stdcall OlxAPIFindBusByName( const char* pszBusName, double dKV, int* pDeviceHnd );
int __stdcall OlxAPIFindBusNo( int nBusNo );
int __stdcall OlxAPIFindEquipmentByTag( char *szTags, int nDevType, int *pnHnd );
const char* __stdcall OlxAPIFullBranchName( int nBranchHnd );
const char* __stdcall OlxAPIFullBusName( int nBusHnd );
const char* __stdcall OlxAPIFullRelayName( int nRelayHnd );
int __stdcall OlxAPIGetBusEquipment( int nBusHnd, int nType, int* pDeviceHnd );
int __stdcall OlxAPIGetData( int nDeviceHnd, int nParam, void *pOutput );
int __stdcall OlxAPIGetEquipment( int nType, int *pDeviceHnd );
int __stdcall OlxAPIGetLogicScheme( int nRlyGrHnd, long * pSchemeHnd );
int __stdcall OlxAPIGetRelay( int nRlyGrHnd, int *pRelayHnd );
const char* __stdcall OlxAPIGetObjJournalRecord( int nDeviceHnd );
const char* __stdcall OlxAPIGetObjMemo( int nDeviceHnd );
const char* __stdcall OlxAPIGetObjTags( int nDeviceHnd );
const char* __stdcall OlxAPIGetOlrFileName();
int __stdcall OlxAPIGetPSCVoltage( int nDeviceHnd, double *dOut1, double *dOut2, int nStyle );
int __stdcall OlxAPIGetRelayTime( int nRelayHnd, double dFactor, double *pTime, char* szDevice, int nTripOnly );
int __stdcall OlxAPIGetSCCurrent( int nDeviceHnd, double *dOut1, double *dOut2, int nStyle );
int __stdcall OlxAPIGetSCVoltage( int nDeviceHnd, double *dOut1, double *dOut2, int nStyle );
int __stdcall OlxAPIGetSteppedEvent( int nStep, double *dTime, double *dCurrent,
   int *nUserEvent, char* szEventDesc, char* szFaultDesc );
int __stdcall OlxAPILoadDataFile( char *szFilePath, int bReadOnly );
int __stdcall OlxAPIMakeOutageList( int nHandle, int nMxTiers, int nWantedBrType, int *vnList, int *pnListLen );
/* Purpose: Return list of neighboring branches that can be used as outage list 
            in the DoFault function on a bus, branch or relay group.
   Parameters:
      nHandle      [in] Handle number of a bus, relay group or branch.
      nMaxTiers    [in] Number of tiers (must be positive) 
      nWantedTypes [in] Branch type. Sum of one or more following values: 1- Line; 
                   2- 2-winding transformer; 4- Phase shifter; 8- 3-winding transformer; 
                   16- Switch;
      vnList       [out] outage list (with zero in the last element).
      pnListLen    [in] Length of vnList array
                   [out] Number of outage branches found.
   Return value: 
      0               Failure
      1               Success
   Remarks: Call this function with NULL in place of vnList to determine the 
            number of outage branches found within the number of tiers specified.
*/
int __stdcall OlxAPINextBusByName( int* pDeviceHnd );
int __stdcall OlxAPINextBusByNumber( int* pDeviceHnd );
int __stdcall OlxAPIPickFault( int nFltIndex, int nWantedTiers );
int __stdcall OlxAPIPostData( int nDeviceHnd );
const char* __stdcall OlxAPIPrintObj1LPF( int nHandle );
int __stdcall OlxAPIReadChangeFile( char *szPathname );
int __stdcall OlxAPIRun1LPFCommand( char *szBuf );
int __stdcall OlxAPISaveDataFile( char *szFilePath );
int __stdcall OlxAPISetData( int nDeviceHnd, int nParam, void *pVal );
const char* __stdcall OlxAPISetObjMemo( int nDeviceHnd, char *szT );
const char* __stdcall OlxAPISetObjTags( int nDeviceHnd, char *szT );
int __stdcall OlxAPIVersionInfo( char *szBuf );

#define pszPSTTYLogFileName "PowerScriptTTYLog.txt"
