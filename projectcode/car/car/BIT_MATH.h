/*
 * BIT_MATH1.h
 *
 * Created: 2/9/2022 8:36:58 PM
 *  Author: erwien
 */ 


#ifndef BIT_MATH1_H_
#define BIT_MATH1_H_
#define SET_BIT(REG,BIT)	REG |= (1<<BIT)
#define CLR_BIT(REG,BIT)	REG &= ~(1<<BIT)
#define TOGGLE_BIT(REG,BIT) REG ^= (1<<BIT)
#define GET_BIT(REG,BIT)	((REG>>BIT)&0b00000001)




#endif /* BIT_MATH1_H_ */