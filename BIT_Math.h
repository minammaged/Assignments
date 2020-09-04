/*
 * BIT_Math.h
 *
 * Created: 8/20/2020 2:10:46 AM
 *  Author: Mina
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,BIT)  (REG |= (1<<BIT))
#define CLR_BIT(REG,BIT)  (REG &=~ (1<<BIT))
#define Toggle_BIT(REG,BIT) (REG ^= (1<<BIT))
#define GET_BIT(REG,BIT)  ((REG >> BIT) & (0X01))



#endif /* BIT_MATH_H_ */