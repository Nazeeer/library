#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////CheckId()
bool checkId(char param[10]){
	fstream r;
	r.open("library_3Mz.txt", ios::in);
	
	string line;
	bool checkExist = 0;
	
	while(getline(r,line)){
		string preID =  line.substr(0,line.find("|"));
		if(preID == param){
			checkExist = 1;
			break;
		}
	}
	return checkExist;	
}
//////////////////////////////////////////////////////////////////////////////////insert()
void insert (){
		fstream f;
		char ID[10], name[25], Cost[10], shelf_no[10], Date[11] , ch[2];
		f.open ("library_3Mz.txt", ios :: app) ;
		do{
		cout << "Enter product ID                      : "; cin.getline(ID, 10 ) ;
		cout << "Enter product Name                    : "; cin.getline(name, 25 ) ;
		cout << "Enter product Cost                    : "; cin.getline(Cost, 10 );
		cout << "Enter product Shelf no                : "; cin.getline(shelf_no, 10 ) ;
		cout << "Enter production Date (DD-MM-YYYY)    : "; cin.getline(Date, 11 ) ;
		if(!checkId(ID)){
			f << ID << "|" << name << "|" << Cost << "|" << shelf_no << "|" << Date << "\n";
			cout << "The product is successtully inserted \n ";
		}else{
			cout << "There is a problem while inserting (Duplicated ID) \n";	
		}
		cout << " Do you want add more products (Y/N) \n";
		cin.getline(ch, 2);
	}while( ch[0] == 'y' || ch[0] == 'Y');
	f.close();
}
/////////////////////////////////////////////////////////////////////////////////display()
void Display(){
	fstream f;
	char ID[10], name[25], Cost[10], shelf_no[10], Date[11];
	f.open ("Library_3Mz.txt", ios :: in) ;
	cout << "##########################################################################################\n";
	cout << "#                                  my store                                              #\n";
	cout << "##########################################################################################\n";
	cout << left << setw(11) << "#ID "<<setw(25) <<" #Name "<<setw(11) << "  #Cost" << 
	setw(11)<< "   #Shelf_No" << setw(16) << "   #Production Date  \n";
	cout << "##########################################################################################\n";	
	while (!f.eof()) {
		f.getline (ID,10 ,'|');
		f.getline (name, 25 ,'|');
		f.getline (Cost, 10 , '|');
		f.getline (shelf_no, 10 ,'|');
		f.getline (Date, 11);
	  if(int(ID[0] != 0)) {
	cout << "#" << left << setw(11) << ID << "#" <<setw(25) << name << "#" << setw(11) << Cost << 
	"#" << setw(11) << shelf_no << "#" << setw(16) << Date << "          #" <<"  \n" ;
	cout <<"##########################################################################################\n";
	}
	}
	f.close();
}
//////////////////////////////////////////////////////////////////////////////////search()
void Search(){
	char ID[10] , name[25] , Cost[10] , shelf_no[10] , date[11] , ID_R[10] , name_R[25] , OP[2] , x[2];
	bool FOUND;
	fstream f;
	do{
		FOUND = false;
		f.open("library_3Mz.txt" , ios::in);
		cout << "-------------------------------------\n";
		cout<< "#To Search By ID  : 1 #\n" << "#To Search By Name  :  2 #\n";
		cout << "-------------------------------------\n";
		
		
		 while (!(OP[0] == '1' || OP[0] == '2')){
				cout << "Enter option : ";
			cin.getline(OP,2);
			if(!(OP[0] == '1' || OP[0] == '2'))
				cout << "\a";
		}
		switch (OP[0])
		{
			case '1':
				cout << "Enter Product's ID :";cin.getline(ID , 10);
				break;
			case '2':
				cout << "Enter Product's Name :";cin.getline(name , 25);
				break;
		}
		while (!f.eof()) {
			f.getline(ID_R , 10 , '|');
			f.getline(name_R , 25 , '|');
			f.getline(Cost , 10 , '|');
			f.getline(shelf_no , 10 , '|');
			f.getline(date , 11 );
			if ((strcmp(ID , ID_R) == 0 && OP[0] == '1' ) || (strcmp(name , name_R) == 0 && OP[0] == '2')) {
				cout << "-------------------------------------\n"; // \n
				cout << left << setw(11) << "#ID " << setw(25) << " #Name " << setw(11) << " #Cost " << setw(11) << " #Shelf_No " 
				<< setw(16) << " #Production Date #\n" ;
				cout << "-------------------------------------\n";
				cout << "#" << left << setw (11) << ID_R << "#" << setw (25) << name_R << "#" << setw(11) << Cost << 
				"#" << setw(11) << shelf_no << "#" << setw(16) << date <<"          #\n";
				cout << "--------------------------------------------------------------------------------------------------------\n";
				
					FOUND = true;
					break;
			}
		}
		if (!FOUND) {
			cout << "Product Not Found !\n";
		}
		cout << "Do Want To Search About Another Product(y) ?\n";cin.getline(x , 2);
		f.close();
	} while (x[0] == 'y' || x[0] == 'Y');
}
//////////////////////////////////////////////////////////////////////////////////delete()
void Delete(){
	char ID[10] , name[25], cost[10], shelf_no[10], date[11], ID_R[10], name_R[25], op[2], x[2];
	bool found;
	fstream f,t;
	do{
		found=false;
		f.open("library_3Mz.txt", ios::in);//read
		t.open("T.txt", ios::app);//append
		cout<<"-------------------------------------\n";
		cout<<"#To Delete By ID       : 1 #\n"<<"#To Delete By Name      : 2 #\n";
		cout<<"-------------------------------------\n";
		do{
			cout<< "Enter Option : ";cin.getline(op,2);
			if (!(op[0]=='1' || op[0] == '2'))
				cout<<"\a";
		} while(!(op[0] == '1'||op[0]=='2'));
		switch (op[0])
		{
			case '1':
				cout<<"Enter product is ID : ";cin.getline(ID,10);
				break;
			case '2':
				cout<<"Enter product is Name : ";cin.getline(name,25);
				break;	
		}
		
		while(!f.eof()){
			f.getline(ID_R,10,     '|');
			f.getline(name_R,25,   '|'  );
			f.getline(cost,10,     '|');
			f.getline(shelf_no,10, '|'   );
			f.getline(date,11);
			if (int(ID_R[0])==0){
				continue;
			}
			if(strcmp(ID,ID_R) == 0 && op[0]=='1'||strcmp(name,name_R)==0 && op[0]=='2'){
				found = true;
				continue;
			}
		t << ID_R << "|" << name_R << "|" << cost << "|" <<shelf_no << "|" <<date <<"\n";
		}if (!found){
			cout<<"Product Not Found !\n";
		}
		else{
			cout<<" Product Successfully Deleted !\n";
		}
		cout<<"do you want delete another product {y} ? \n";cin.getline(x,2);
		f.close();
		t.close();
		remove("library_3Mz.txt");
		rename("T.txt","library_3Mz.txt");
	}while (x[0]=='y' || x[0]=='y');
}
////////////////////////////////////////////////////////////////////////////////////main()
int main(int argc, char** argv) {
	char c[2];	
	bool flag = true;
	fstream f;
	f.open("library_3Mz.txt", ios :: app);
	f.close();
	do{
		cout<<"-------------------------------------\n"
			<<"welcome to library_3Mz program\n"
			<<"-------------------------------------\n"
			<<"to Insert                  enter :- 1\n"
			<<"to Display                 enter :- 2\n"
			<<"to search                  enter :- 3\n"
			<<"to Delete                  enter :- 4\n"
			<<"to exit                    enter :- 5\n"
			<<"-------------------------------------\n";
			cout<<"enter your choice : "; cin.getline(c,2);
			switch(c[0]){
				case '1':
					insert();
					break;
				case '2':
					Display();
					break;
				case '3':
					Search();
					break;
				case '4':
					Delete();
					break;
				case '5':
					flag= false;
					cout<<"thanks to use our program \n";
					break;
				default :
					cout<<"\a choose number between  ( 1 -  5 )";
			}
			
			
	} while( flag );
	return 0;
}


