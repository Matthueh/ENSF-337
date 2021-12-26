// File lab7ExC.h
// ENSF 337  LAB 7 - EXERCISE C
// Lab section: B01
// Date completed: 11/13/2020
// By: Matthew Ho(30052684) & Alexander Sembrat(30089188) 


class Clock{
	private:
		int hour;
		int minute;
		int second;
		
		int hms_to_sec(); 
		void sec_to_hms(int sec);
		
		
	public:
		Clock();
		Clock(int s);
		Clock(int h, int m, int s); 
		
		void set_hour(int value);  
		void set_minute(int value);
		void set_second(int value);
		
		int get_hour()const; 
		int get_minute()const;
		int get_second()const;
		
		void increment();		
		void decrement();	
		void add_seconds(int seconds);
}; 