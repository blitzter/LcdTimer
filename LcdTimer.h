/*
 * LcdTimer.h
 *
 *  Created on: Jun 29, 2013
 *      Author: blitzter
 */

#ifndef LCDTIMER_H_
#define LCDTIMER_H_
//#include "Arduino.h"
#include <ILI9225G.h>
#include <DS1302.h>

class LcdTimer {
public:
	Time currentTime;
	Time newTime;
	short mode;
	LcdTimer(int cl_en, int cl_io, int cl_clk, int lcd_cs, int lcd_rs,
			int lcd_rst, int lcd_mosi, int lcd_clk);
	virtual ~LcdTimer();
	void initLcdClock();
	void initRTC();
	void initLCD();
	void handleCommand(int cmd);
	void refresh();
	void refreshClock();
	void printTime(short level);
	String getDay(int day);
	String getMonthThree(int month);
private:
	ILI9225G *lcd;
	DS1302 *rtc;
};

#endif /* LCDTIMER_H_ */
