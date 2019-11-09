// studentType.h

#include <string>

using namespace std;

class studentType
{
private:
	string firstName;
	string lastName;
	char courseGrade;
	int testScore;
	int programmingScore;
	double GPA;

public:
	void setData(string fn, string ln, int tScore, int prgScore, double gpa);
	void setFirstName(string fn);
	void setLastName(string ln);
	void setGrade();
	void setTestScore(int tScore);
	void setProgScore(int prgScore);
	void setGPA(double gpa);
	string getFirstName() const;
	string getLastName() const;
	char getGrade() const;
	int getTestScore() const;
	int getProgScore() const;
	double getGPA() const;
	void print() const;
	studentType(string fn="", string ln="", int tScore=0, int prgScore=0,
				double gpa=0.0, char grade=' ');
};