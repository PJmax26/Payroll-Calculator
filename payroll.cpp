#include <iostream>
using namespace std;

class Employee {
	public:
		string name;
		int hours_worked;
		int hourly_rate;
		float tax_rate;
		int gross_pay;
		double cashout;
		double tax_amount;
		double ssc_rate = 0.06;
		double const_tax_rate = 0.03;
		double welfare_rate = 0.02;
		double total_extra_deduction_rate;
		double net_pay;

	void person_info(){
		
	}
	
	void calc_gross_pay(){
		if(hours_worked > 40){
			hourly_rate = 7500;
		}
		else if(hours_worked > 0 && hours_worked <= 40){
			hourly_rate = 5000;
		}
		
		else if (hours_worked == 0){
			cout << "Employee did not work for the week";
		}
		
		gross_pay = hours_worked * hourly_rate;
		cout << "Grosspay: GHC" << gross_pay << endl;
	}
	
	void calc_tax(){
		if(gross_pay < 125001){
			gross_pay = gross_pay;
			cout << "There is no tax on your payment" << endl;
			tax_amount = 0;
			cashout =  gross_pay;
		}
		else if(gross_pay >= 125001 && gross_pay <= 250000){
			tax_amount = 0.05*gross_pay;
			cashout =  gross_pay - tax_amount;
			cout << "Tax rate is 5%" << endl;
		}
		else if(gross_pay >= 250001 && gross_pay <= 1750000){
			tax_amount = 0.1*gross_pay;
			cashout =  gross_pay - tax_amount;
			cout << "Tax rate is 10%" << endl;
		}
		else if(gross_pay >= 1750001 && gross_pay <= 2750000){
			tax_amount = 0.15*gross_pay;
			cashout =  gross_pay - tax_amount;
			cout << "Tax rate is 15%" << endl;
		}
		else if(gross_pay >= 2750001 && gross_pay <= 5000000){
			tax_amount = 0.2*gross_pay;
			cashout =  gross_pay - tax_amount;
			cout << "Tax rate is 20%" << endl;
		}
		else if(gross_pay > 5000000){
			tax_amount = 0.3*gross_pay;
			cashout =  gross_pay - tax_amount;
			cout << "Tax rate is 30%" << endl;
		}
		
		cout << "Tax to pay: GHC" << tax_amount << endl;
		cout << "Remaining Grosspay: GHC" << cashout << endl;
	}

	void extra_deductions(){
		total_extra_deduction_rate = ssc_rate + const_tax_rate + welfare_rate;
		net_pay = cashout - (total_extra_deduction_rate * cashout);
		cout << "Social Security Contribution Amount: GHC" << ssc_rate * cashout << endl;
		cout << "Constituency Amount: GHC" << const_tax_rate * cashout << endl;
		cout << "Welfare Contribution Amount: GHC" << welfare_rate * cashout << endl;

		cout << "NetPay: GHC" << net_pay << endl;
	}
};

int main(){
	
	Employee person;
	
	cout << "Enter Name of Employee: ";
	getline(cin, person.name);
	
	cout << "Enter number of hours worked by employee in a week: ";
	cin >> person.hours_worked;
	
	
	cout << "Employee: " << person.name << endl;
	cout << "Hours worked(weekly): " << person.hours_worked << endl << endl;
	
	
	person.calc_gross_pay();
	cout << "..." << endl << endl;
	person.calc_tax();
	person.extra_deductions();
	
	return 0;
}