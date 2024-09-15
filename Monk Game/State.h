#pragma once
#include "pch.h"

class State
{
public:
	State();
	virtual ~State();

	// Getters
	const bool& getQuit() const { return this->quit; }

	// Setters
	void setQuit(bool quit) { this->quit = quit; }


	virtual void updateState() = 0;

	template<typename T>
	bool inputValid(T& input, const string msg)
	{
		cout << endl << msg;
		cin >> input;

		if (cin.good() == false)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input, Please try again! " << endl;
			system("pause");
			return false;
		}
		return true;
	}
private:
	bool quit;

};

