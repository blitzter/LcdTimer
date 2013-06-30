/*
 * LcdTimer.cpp
 *
 *  Created on: Jun 29, 2013
 *      Author: blitzter
 */

#include "LcdTimer.h"

LcdTimer::LcdTimer(int cl_en, int cl_io, int cl_clk, int lcd_cs, int lcd_rs,
		int lcd_rst, int lcd_mosi, int lcd_clk) {

	this->rtc = new DS1302(cl_en, cl_io, cl_clk);
	this->lcd = new ILI9225G(lcd_cs, lcd_rs, lcd_rst, lcd_mosi, lcd_clk);
	initRTC();
	initLCD();
	this->mode = 0;
	printTime(5);
}

LcdTimer::~LcdTimer() {

}

void LcdTimer::initLcdClock() {
}

void LcdTimer::initRTC() {
	this->rtc->write_protect(false);
	this->rtc->halt(false);
}

void LcdTimer::initLCD() {
	this->lcd->begin();
	this->lcd->clearScreen(WHITE);
	lcd->printString("HOUR", 12, 6, BLACK, WHITE, 1);
	lcd->printString("MINUTE", 70, 6, BLACK, WHITE, 1);
	lcd->printString("SECOND", 128, 6, BLACK, WHITE, 1);
}

void LcdTimer::handleCommand(int cmd) {
}

void LcdTimer::refresh() {
	switch (this->mode) {
	case 0:
		refreshClock();
		break;
	}
}

void LcdTimer::refreshClock() {
	short level = 0;
	this->newTime = rtc->time();
	if (this->newTime.sec == this->currentTime.sec) {
		return;
	}
	if (this->newTime.min == this->currentTime.min) {
		printTime(level);
		return;
	}
	level++;
	if (this->newTime.hr == this->currentTime.hr) {
		printTime(level);
		return;
	}
	level++;
	if (this->newTime.date == this->currentTime.date) {
		printTime(level);
		return;
	}
	level++;
	if (this->newTime.mon == this->currentTime.mon) {
		printTime(level);
		return;
	}
	level++;
	if (this->newTime.yr == this->currentTime.yr) {
		printTime(level);
		return;
	}
	this->currentTime = this->newTime;
}

void LcdTimer::printTime(short level) {
	switch (level) {
	case 5:
		lcd->printNumber(this->newTime.yr, 4, 102, 64, BLACK, WHITE, 3);
		/* no break */
	case 4:
		lcd->printString(getMonthThree(this->newTime.mon), 46, 64, BLACK, WHITE,
				3);
		/* no break */
	case 3:
		lcd->printNumber(this->newTime.date, 2, 12, 64, BLACK, WHITE, 3);
		lcd->printString(getDay(this->newTime.day), 12, 90, BLACK, WHITE, 3);
		/* no break */
	case 2:
		lcd->printNumber(this->newTime.hr, 2, 2, 18, BLACK, WHITE, 5);
		/* no break */
	case 1:
		lcd->printNumber(this->newTime.min, 2, 60, 18, BLACK, WHITE, 5);
		/* no break */
	case 0:
		lcd->printNumber(this->newTime.sec, 2, 118, 18, BLACK, WHITE, 5);
	}

}

String LcdTimer::getDay(int day) {
	switch (day) {
	case 1:
		return String("Sunday   ");
	case 2:
		return String("Monday   ");
	case 3:
		return String("Tuesday  ");
	case 4:
		return String("Wednesday");
	case 5:
		return String("Thursday ");
	case 6:
		return String("Friday   ");
	case 7:
		return String("Saturday ");
	}
}

String LcdTimer::getMonthThree(int month) {
	switch (month) {
	case 1:
		return String("JAN");
	case 2:
		return String("FEB");
	case 3:
		return String("MAR");
	case 4:
		return String("APR");
	case 5:
		return String("MAY");
	case 6:
		return String("JUN");
	case 7:
		return String("JUL");
	case 8:
		return String("AUG");
	case 9:
		return String("SEP");
	case 10:
		return String("OCT");
	case 11:
		return String("NOV");
	case 12:
		return String("DEC");
	}
}
