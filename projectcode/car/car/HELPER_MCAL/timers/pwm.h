/*
 * pwm.h
 *
 * Created: 8/12/2022 1:43:35 AM
 *  Author: bedoa
 */ 


#ifndef PWM_H_
#define PWM_H_

void oc0pwmgenerator(float Foc0,char percentage);
void oc0fastpwm(void);
void oc0pcpwm(void);



#endif /* PWM_H_ */