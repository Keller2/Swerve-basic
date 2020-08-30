/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>
#include <rev/CANSparkMax.h>
#include <rev/CANEncoder.h>
#include <frc/smartdashboard/SmartDashboard.h>
double speed1;
double turntodegree;
double turndegrees;
double turntospeed;
void Robot::RobotInit()
{
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
  Motor2.reset(new rev::CANSparkMax(1, rev::CANSparkMaxLowLevel::MotorType::kBrushless));
  Motor1.reset(new rev::CANSparkMax(2, rev::CANSparkMaxLowLevel::MotorType::kBrushless));
  controller.reset(new frc::Joystick(0));
}

void Robot::RobotPeriodic()
{
  double turndegrees = Motor1->GetEncoder().GetPosition();
}

void Robot::AutonomousInit()
{
  m_autoSelected = m_chooser.GetSelected();

  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom)
  {
  }
  else
  {
  }
}

void Robot::AutonomousPeriodic()
{
  if (m_autoSelected == kAutoNameCustom)
  {
  }
  else
  {
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic()
{

  speed1 = controller->GetRawAxis(0);
  Motor1->Set(speed1);
  turntodegree = controller->GetRawAxis(1);
  turntospeed = turntospeed / 2;
  std::cout << turndegrees << "rotations" << std::endl;
  Motor2->Set(turntospeed);
  /* if (turntodegree > turndegrees)
  {
    Motor2->Set(turntospeed);
  }
  if (turntodegree < turndegrees)
  {
    Motor2->Set(turntospeed);
  }
  */
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif
