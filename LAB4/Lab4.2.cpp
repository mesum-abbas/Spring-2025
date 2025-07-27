#include <iostream>
#include <cstring>
using namespace std;

class account {
	private:
		int account_no;
		long account_bal;
		int security_code;
		
	static int account_count;
	public :
		account(int acc_no,long acc_bal,int sec_code){
			account_no = acc_no;
			account_bal = acc_bal;
			security_code = sec_code;
			account_count++;
		}
		
		void displayaccount() const {
			cout<< "ACCOUNT NO "<<account_no<<endl;
			cout<< "ACCOUNT BALANCE "<<account_bal<<endl;
			cout<< "SECURITY CODE "<<security_code<<endl;
		}
		static int getaccount(){
			return account_count;
		}
		
};
int account :: account_count = 0;

int main(){
	cout<<"THE CODE IS WRITTEN BY MESUM ABBAS CT-238"<<endl;
	account acc1(23,78000,41);
	account acc2(24,90000,100);
	cout<<"Account 1"<<endl;
	acc1.displayaccount();
	cout<<"Account 2"<<endl;
	acc2.displayaccount();
	
	cout<<"NO of accounts are "<< account::getaccount()<<endl;
	
}
