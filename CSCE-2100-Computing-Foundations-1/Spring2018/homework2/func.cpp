#include "prgm.h"

population per;
person one;
infected zom;
susceptible pzom;
recovered heal;

//Constructors
population::population(){
	number_of_people = 0;
}

person::person(){
	contact_rate = 0;
	peak = 0;
	length = 0;
	avg_num_sus = 0;
	avg_num_rec = 0;
}

infected::infected(){
	tran_prob = 0;
	infect_time = 0;
	num_of_infected = 0;
}

susceptible::susceptible(){
	num_of_sus = 0;
}

recovered::recovered(){
	num_of_rec = 0;
	final_num = 0;
}

void population::set_num(int peeps){
	number_of_people = peeps;
}

int population::get_num(int peeps){
	return number_of_people;
}
//Person class Mutators
void person::set_conrate(int rate){
	contact_rate = rate;
}
void person::set_avg(int sus, int rec){
	avg_num_sus = sus;
	avg_num_rec = rec;
}
void person::set_peak(int maxinf){
	peak = maxinf;
}
void person::set_lenght(int dura){
	length = dura;
}
void person::set_days(int dayz){
	day = dayz;
}

//Person class Accessors
int person::get_contact_rate() const{
	return contact_rate;
}
int person::get_avg() const{
	return (avg_num_sus, avg_num_rec);
}
int person::get_peak() const{
	return peak;
}
int person::get_length() const{
	return length;
}
int person::get_day() const{
	return day;
}

//Infected class Mutators
void infected::set_trans(int prob){
	tran_prob = prob;
}
void infected::set_infectt(int time){
	infect_time = time;
}
void infected::set_num_infect(int sick){
	num_of_infected = sick;
}

//Infected Class Accessors
int infected::get_trans() const{
	return tran_prob;
}
int infected::get_infectt() const{
	return infect_time;
}
int infected::get_num_infect() const{
	return num_of_infected;
}

//Susceptible Class Mutators
void susceptible::set_sus(int chance){
	num_of_sus = chance;
}

//Susceptible Class Accessors
int susceptible::get_numof_sus() const
{
	return num_of_sus;
}

//Recoverd Class Mutators
void recovered::set_rec(int revi){
	num_of_rec = revi;
}
void recovered::set_final(int pop){
	final_num = pop;
}

//Recovered Class Accessors
int recovered::get_rec() const{
	return num_of_rec;
}
int recovered::get_final() const{
	return final_num;
}

void student()
{
	//Displace student information
	cout << "+--------------------------------------------------------+\n";
	cout << "|              Computer Science and Engineering          |\n";
	cout << "|               CSCE 2100 - Computer Fundations I        |\n";
	cout << "| Ricardo Alberto Garza rag0175 RicardoGarza3@my.unt.edu |\n";
	cout << "+--------------------------------------------------------+\n";
}

void population::add_data(){
	int suscpet, infect, recover;
	int vacc, trans_prob;
	int contact, sims, infper;

	cout << "Please enter number of Susceptibles: ";
	cin >> suscpet;
	cout << "Please enter number of Infectious: ";
	cin >> infect;
	cout << "Please enter number of Recovered: ";
	cin >> recover;
	cout << "Please enter number of Vaccinated: ";
	cin >> vacc;
	cout << "Please enter contact rate: ";
	cin >> contact;
	cout << "Enter Transmission Probability: ";
	cin >> trans_prob;
	cout << "Enter Infectious Period: ";
	cin >> infper;
	cout << "Enter  number of Simulations: ";
	cin >> sims;

	pzom.set_sus(suscpet);
	zom.set_num_infect(infect);
	zom.set_trans(trans_prob);
	zom.set_infectt(infper);
	heal.set_rec(recover);
	one.set_conrate(contact);

	number_of_people = suscpet + infect + recover + vacc;
	per.set_num(number_of_people);
	//.push_back(one);

	for (int i = 0; i < sims; i++) {
		//srand(time(NULL));
	}
}


/*cout << "Please enter name of file: ";
cin >> infile;

in_stream.open(infile);

//Error Check
if (in_stream.fail())
{
cout << "Input file opening failed.\n";
exit(EXIT_FAILURE);//exit if cannot open file

}
cin.ignore();
for (int i = 0; i < 7; i++) {
getline(in_stream, input);
stemp.push_back(input);
}
for (unsigned int i = 0; i < stemp.size(); i++) {
cout << endl;
cout << stemp[i] << endl << endl;
}
in_stream.close();//close the file*/
