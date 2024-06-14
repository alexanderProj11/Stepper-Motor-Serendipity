#ifndef HEALTH_MONITORING_H
#define HEALTH_MONITORING_H

void initHealthMonitoring();
float readCurrent();
float readTemperature();
bool checkEmergencyStop();
bool checkHealthStatus();

#endif // HEALTH_MONITORING_H
