/*
 * EXINT.h
 *
 * Created: 8/4/2022 1:35:23 PM
 * Author: bedoa
 */ 


#ifndef EXINT_H_
#define EXINT_H_

void INT_INIT(EXINTCFG cfg);
void intcallback(EXINTS interrupt,void(*ptof)(void));
void INIT_GI(EXINT_STATE);



#endif /* EXINT_H_ */