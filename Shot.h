#pragma once
#include <string>
using namespace std;



class Shot
{

private:
	string shotname;
	char shotCode;
	char pattern;
	int range;
	int amount;

public:
	Shot();
	~Shot();
	bool useShot();

	string getShotName();
	void setShotName(string input);

	char getShotCode();
	void setShotCode(char input);

	char getPattern();
	void setPattern(char input);

	int getRange();
	void setRange(int input);

	int getAmount();
	void setAmount(int input);

};
