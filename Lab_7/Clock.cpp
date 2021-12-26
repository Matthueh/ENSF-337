// File Clock.cpp
// ENSF 337  LAB 7 - EXERCISE C
// Lab section: B01
// Date completed: 11/13/2020
// By: Matthew Ho(30052684) & Alexander Sembrat(30089188) 

#include "Lab7Clock.h"

Clock::Clock(int s) //when only given seconds
{
	if(s < 0)
	{
		hour = 0;
		minute = 0;
		second = 0;
	}
	else
	{
		hour = s/3600;
		s = s - hour*3600;
	
		if(hour > 23)
		{
			hour = hour - 24*(hour/24);
		}

		minute = s/60;
		s = s - minute*60;
		second = s;
	}
}//constructor

Clock::Clock(int h, int m, int s){
	
	if(h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59)
	{
		hour = 0;
		minute = 0;
		second = 0;
	}
	else
	{
		hour = h;
		minute = m;
		second = s;
	}
	
}//constructor 

Clock::Clock()
{
	hour = 0;
	minute = 0;
	second = 0;
}

void Clock::set_hour(int value)//setter functions
{
	if(value <  24 && value >= 0)
	{
		hour = value;
	}
}

void Clock::set_minute(int value)
{
	if(value < 60 && value >= 0 )
	{
		minute = value;
	}
}

void Clock::set_second(int value)
{

	if(value < 60 && value >= 0)
	{
		second = value;
	}

}

int Clock::get_hour()const //getter functions
{
	return hour;
}

int Clock::get_minute()const
{
	return minute;
}

int Clock::get_second()const
{
	return second;
}


int Clock::hms_to_sec()
{
	int sec = 0;
	sec = sec + this->hour*3600; 
	sec = sec + this->minute*60;
	sec = sec + this->second;
	return sec;
}

void Clock::sec_to_hms(int seconds)
{
	this->hour = seconds/3600;
	seconds = seconds - this->hour*3600; 
	
	if(this->hour > 23)
	{
		this->hour = this->hour - 24*(this->hour/24);
	}
	
	this->minute = seconds/60;
	seconds = seconds - this->minute*60;
	this->second = seconds;
	
}

void Clock::increment()
{
	second++;
	
	if(second >59)
	{
		second = 0;
		minute++;
	}
	if(minute > 59)
	{
		minute = 0;
		hour++;
	}
	if(hour > 23)
	{
		hour = hour - 24; 
	}
}

void Clock::decrement()
{
	second--;
	
	if(second < 0)
	{
		second = 59;
		minute--;
	}
	if(minute < 0)
	{
		minute = 59;
		hour--;
	}
	if(hour < 0)
	{
		hour = hour + 24;
	}
}

void Clock::add_seconds(int seconds)
{
	seconds = seconds + Clock::hms_to_sec();
	Clock::sec_to_hms(seconds);
}


