#define H_RPM_MANPSI_TPS_COOLPSI_ID (0x360)

#define H_FUELPSI_OILPSI_DEMAND_WASTE_PSI_ID (0x361)

#define H_SPEED_GEAR_INTANG1_INTANG2_ID (0x370)

#define H_VOLTS_TARGETBOOST_BAROPSI_ID (0x372)

#define H_COOLTEMP_AIRTEMP_FUELTEMP_OILTEMP_ID (0x3E0)

#define H_FUELLEVEL_ID (0x3E2)

/*
Byte 0
Unused

| Byte 1                  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|-------------------------|---|---|---|---|---|---|---|---|
| Gear Switch             |   |   |   |   |   | 1 |   |   |
| Decel Cut Active        |   |   |   |   | 1 |   |   |   |
| Transient Throttle      |   |   |   | 1 |   |   |   |   |
| Brake Switch            |   |   | 1 |   |   |   |   |   |
| Clutch Switch           |   | 1 |   |   |   |   |   |   |

| Byte 2                  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|-------------------------|---|---|---|---|---|---|---|---|
| Anti-Lag Active         |   |   |   |   |   |   |   | 1 |
| Aux RPM Limiter         |   |   |   |   |   | 1 |   |   |
| Flat Shift Switch       |   |   |   | 1 |   |   |   |   |
| Torque Reduction Active |   | 1 |   |   |   |   |   |   |

Byte 3 through 6
Unused

| Byte 7                  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|-------------------------|---|---|---|---|---|---|---|---|
| Check Engine Light      |   |   |   |   |   |   |   | 1 |
| Battery Light           |   |   |   |   |   |   | 1 |   |
*/
#define H_SWITCHES_LIGHTS_ID (0x3E4)
#define H_CHECK_ENGINE (0x80)
#define H_BATTERY_LIGHT (0x40)