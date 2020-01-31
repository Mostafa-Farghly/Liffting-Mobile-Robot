/*
 * micro_config.h
 *
 *	Description: File include Micro-controller libraries and clock speed
 *  Created on: Jan 29, 2020
 *  Author: Mostafa Alaa
 */

#ifndef CONFIG_MICRO_CONFIG_H_
#define CONFIG_MICRO_CONFIG_H_

#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif

#include <avr/io.h>

#endif /* CONFIG_MICRO_CONFIG_H_ */
