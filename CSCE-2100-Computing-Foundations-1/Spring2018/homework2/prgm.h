//#ifdef PRGM_H
//#definePRGM_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;



void student();

class population {
public:
	population();					//Constructor

	void set_num(int peeps);

	int get_num(int peeps);
	void add_data();				//Functions

private:
	int number_of_people;
//	vector<person> ppl;
	/*vector<infected> in;
	vector<susceptible> su;
	vector<recovered> re;*/
};

class person {
public:
	person();						//Constructor

	void set_conrate(int rate);		//Mutators
	void set_avg(int sus, int rec);
	void set_peak(int maxinf);
	void set_lenght(int dura);
	void set_days(int dayz);

	int get_contact_rate() const;	//accessors
	int get_avg() const;
	int get_peak() const;
	int get_length() const;
	int get_day() const;
private:
	int contact_rate;
	int avg_num_sus;				//Susceptibles
	int avg_num_rec;				//Recovered
	int peak;
	int length;
	int day;
};

class infected: person{
public:
	infected();						//Constructor

	void set_trans(int prob);		//Mutators
	void set_infectt(int time);
	void set_num_infect(int sick);

	int get_trans() const;			//Accessor
	int get_infectt() const;
	int get_num_infect() const;
private:
	int tran_prob;
	int infect_time;
	int num_of_infected;
};

class susceptible: person {
public:
	susceptible();					//Constructor

	void set_sus(int chance);		//Mutator

	int get_numof_sus() const;		//Accessor
private:
	int num_of_sus;
};

class recovered: person {
public:
	recovered();					//Constructor

	void set_rec(int revi);			//Mutator
	void set_final(int pop);

	int get_rec() const;			//Accessor
	int get_final() const;
private:
	int num_of_rec;
	int final_num;
};

//#endif