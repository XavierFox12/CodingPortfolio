/* program: clockType.h
   Programmer: Xavier Fox
   Date: 20 Jan. 2015
   Purpose: sets the clockType class definitions
*/

class clockType
{
private:
	int hr;
	int min;
	int sec;

public:
	void setTime(int hours, int minutes, int seconds);
	void setHours(int hours);
	void setMinutes(int minutes);
	void setSeconds(int seconds);
	void getTime(int& hours, int& minutes, int& seconds) const;
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;
	void printTime () const;
	void incrementSeconds();
	void incrementMinutes();
	void incrementHours();
	bool equalTime(const clockType& otherClock) const;
	clockType(int hours, int minutes, int seconds);
	clockType();
};