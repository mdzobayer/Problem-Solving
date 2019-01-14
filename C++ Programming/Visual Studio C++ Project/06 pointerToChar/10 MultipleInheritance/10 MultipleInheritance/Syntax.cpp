class StopWatch
{
public:
	double GetTime()
	{
		// Returns seconds, tenths, hundredths
	}
private:
	int seconds;
	int hundredths;
};

struct time
{
	int hh, mm;
};

class Clock
{
public:
	time GetTime()
	{
		// Return hh:mm
	}
private:
	int hh;
	int mm;
};

class Chronometer : public Clock, public StopWatch
{
public:
	// inheritance all public members of Clock & Stopwatch
	void Display()
	{
		// GetTime();			Error for return type
		StopWatch::GetTime();
		Clock::GetTime();
	}
};