#include<iostream>
#include<cstring>
#include<conio.h>
#include<fstream>
using namespace std;

class transportation
{
	public: void unpack1_names();
	void display1_names();
	int enter_new_trans_names(),op;
	void pack1_names();
	string trans_names,dp1,dp2,b1;
	string a,AD,ph_num,deplace1,deplace2;
	string adult_num,child_num,infant_num;
	string dept_time,arr_time,buff;
	string sn,dmy1,dmy2,total1,total2;
	string number,name,type,run_days,to;
	string arrival_time,from,number2,name2,type2;
	string cost_per_tic,cost_per_tic2,arrival_time2,dept_time2;	
	void enter_new_trans_props(string,string,int);
	void pack1_props(),pack2_props(int),mod_trans(int,string);
	void unpack1_props(),unpack2_pass();
	void display1_props();
}t[100],temp;
int indexnums[20],find_cnt;
class passenger:public transportation
{
	public:
	void search();
	void add_det(string,string,int),trip_type(int);
	void mod_det(string,string),del_det(string,string);
}s;
char charsn(string);
fstream fp;
int file_check(),check2(string,string,string,string),validate(string,string,string,string,string,string);
string display_trans_props(string,string,int),view_trans(char);
void design1(),design2(),design3(),space(),star();int check(string);
void design4(),add_trans(),del_trans(),design5(),updated_table(string);
void view_info(),book_tic(),cancel_tic(),admin();
int main()
{
	int choice,flag1;
	while(1){
	flag1=file_check();
	flag1=file_check();
		if(flag1>1)
		{
			fp.open("passenger.txt",ios::out|ios::app);fp.close();
			design1();
			cin>>choice;
			switch(choice)
			{
				case 1:view_info();break;
				case 2:book_tic();break;
				case 3:cancel_tic();break;
				case 4:admin();break;
				case 5:exit(0);
				default: space();
						 cout<<"Ofcourse I love you! please enter the correct choice :)\n";
						 space();
						 star();
					     cout<<endl;
			}
		}else{
			
	space();
	for(int k=0;k<10;k++)
	{
		cout<<"*";
	}
	cout<<"TRANSPORTATION RESERVATION SYSTEM";
	for(int k=0;k<10;k++)
	{
		cout<<"*";
	}
	cout<<endl;
	space();
	star();
		for(int i=0;i<43;i++)
	{
		cout<<" ";
	}	
	cout<<"[1] ADMIN\n";
		for(int i=0;i<43;i++)
	{
		cout<<" ";
	}	
		cout<<"[2] EXIT\n";space();star();space();cout<<"ENTER THE CHOICE ";cin>>choice;
		switch(choice)
		{
			case 1:admin();break;
			case 2:exit(0);
			default: space();
						 cout<<"Ofcourse I love you! please enter the correct choice :)\n";
						 space();
						 star();
					     cout<<endl;
		}
		}
}
	return 0;
}
int file_check()
{
	int i=0,flag2=1;
	fp.open("transport_names.txt",ios::in);
	if(fp){
		while(fp)
		{
			t[i].unpack1_names();
			i++;
		}flag2=i;
		fp.close();
	}
	else
	{
		fp.open("transport_names.txt",ios::out|ios::app);
		fp.close();
		flag2=1;
	}fp.close();
	return flag2;
}
void transportation::unpack1_names()
{
	string seg;
	getline(fp,sn,'|');
	getline(fp,trans_names,'|');
	getline(fp,seg);
}

void transportation::unpack1_props()
{
	string seg;
	getline(fp,number,'|');
	getline(fp,from,'|');
	getline(fp,to,'|');
	getline(fp,name,'|');
	getline(fp,type,'|');
	getline(fp,run_days,'|');
	getline(fp,dept_time,'|');
	getline(fp,arrival_time,'|');
	getline(fp,cost_per_tic,'|');
	getline(fp,seg);
}
void transportation::unpack2_pass()
{
	string seg;
	getline(fp,sn,'|');
	getline(fp,b1,'|');
	getline(fp,AD,'|');
	getline(fp,dmy1,'|');getline(fp,dmy2,'|');
	getline(fp,deplace1,'|');getline(fp,dp1,'|');
	getline(fp,deplace2,'|');getline(fp,dp2,'|');
	getline(fp,adult_num,'|');
	getline(fp,child_num,'|');
	getline(fp,infant_num,'|');
	getline(fp,ph_num,'|');
	getline(fp,number,'|');getline(fp,number2,'|');
	getline(fp,name,'|');	getline(fp,name2,'|');
	getline(fp,dept_time,'|');getline(fp,dept_time2,'|');
	getline(fp,total1,'|');getline(fp,total2,'|');
	getline(fp,seg);
}
void transportation::display1_names()
{
		for(int i=0;i<43;i++)
	{
		cout<<" ";
	}
	cout<<"   "<<"["+sn+"]"<<"        "<<trans_names<<endl;
}

void transportation::display1_props()
{
	if(number=="")
	{
		return;
	}
	cout<<number<<"    "+from<<"     "+to<<"        "+name<<"       "+type<<"     "+run_days<<"     "+dept_time<<"          "+arrival_time<<"       "+cost_per_tic<<endl;
}
int transportation::enter_new_trans_names()
{
	int i=0;
	space();
	while(1){
		cout<<"enter the new Serial number\t";
	cin>>sn;cout<<endl;space();int a=check(sn);
	if(a)
	{
		cout<<sn<<" "<<"Already exits in your Document folder\n";
		return 0;
	}
	else
	{
		break;
	}
	}
	cout<<"enter the new transpoartation name\t";
	cin>>trans_names;cout<<endl;
	fp.open(sn+".txt",ios::out|ios::app);fp.close();
	design3();space();cout<<"              FILE CREATED SUCCESSFULLY\n";design3();
	return 1;
}

void transportation::enter_new_trans_props(string sn,string trans_names,int c=0){
	space();
	cout<<"Enter "<<trans_names<<" Number\t";
	cin>>number;cout<<endl;space();
	cout<<"Enter "<<trans_names<<" Departure \t";
	cin>>from;cout<<endl;space();
	cout<<"Enter "<<trans_names<<" Destination \t";
	cin>>to;cout<<endl;space();
	cout<<"Enter "<<trans_names<<" Name\t";
	cin>>name;cout<<endl;space();
	cout<<"Enter "<<trans_names<<" Type\t";
	cin>>type;cout<<endl;space();
	cout<<"Enter "<<trans_names<<" Run days\t";
	cin>>run_days;cout<<endl;space();
	cout<<"Enter "<<trans_names<<" Dept_time\t";
	cin>>dept_time;cout<<endl;space();
	cout<<"Enter "<<trans_names<<" Arrival_time\t";
	cin>>arrival_time;cout<<endl;space();
	cout<<"Enter "<<trans_names<<" Price\t";
	cin>>cost_per_tic;cout<<endl;
	int val=validate(sn,from,to,dept_time,name,number);
	if(val!=1){
		cout<<"val value: "<<val<<endl;fp.open(sn+".txt",ios::out|ios::app);
		s.pack1_props();fp.close();
		design3();space();cout<<"              DETAILS ADDED SUCCESSFULLY\n";
		design3();
}
else{
	design3();space();cout<<"              Detail exist!!\n";design3();
}
}
void updated_table(string sn)
{
	cout<<"ROUTE.NO"<<"     DEPARTURE"<<"     DESTINATION"<<"     TRANSP NAME"<<"     TYPE"<<"     RUN DAYS"<<"     DEPARTURE TIME"<<"     ARRIVAL TIME"<<"    PRICE"<<endl;
		int i=0,a;
	fp.open(sn+".txt",ios::in);
			while(fp)
				{ 
					t[i].unpack1_props();
					i++;
				}
				a=i;
				for(int j=0;j<a-1;j++)
			{
				t[j].display1_props();
			}
		cout<<"***********************************************************************************************************************\n";
			fp.close();
}
int validate(string sn,string from,string to,string dept_time,string name,string number){
	int i=0,count,val=0,a;
	fp.open(sn+".txt",ios::in);
	if(fp)
	{
		while(fp)
		{
			t[i].unpack1_props();
			i++;
		}
	}fp.close();count=i;
	for(i=0;i<count-1;i++){
		if(t[i].from==from&&t[i].number==number&&t[i].dept_time!=dept_time||t[i].from==from&&t[i].number!=number&&t[i].dept_time==dept_time)
		{
		val=1;
		}
		if(t[i].from==from&&t[i].number==number&&t[i].dept_time!=dept_time||t[i].from==from&&t[i].to==to&&t[i].number==number&&t[i].dept_time==dept_time)
		{
		val=1;
		}
	}if(count==1){val=0;}
	return val;
}
void transportation::pack1_names()
{
	if(trans_names=="")
	{
		return;
	}
	string buf=sn+"|"+trans_names+"|";
	fp<<buf<<endl;
}


void transportation::pack1_props()
{ 
	if(number=="")
	{
		return;
	}	
	string buf=number+"|"+from+"|"+to+"|"+name+"|"+type+"|"+run_days+"|"+dept_time+"|"+arrival_time+"|"+cost_per_tic+"|";
	fp<<buf<<endl;

}

void transportation::pack2_props(int op1)
{ 
	if(t[op1].ph_num=="")
	{
		return;
	}	
	string f1=a+"|"+b1+"|"+AD+"|"+dmy1+"|"+dmy2+"|"+deplace1+"|"+dp1+"|"+deplace2+"|"+dp2+"|"+adult_num+"|"+child_num+"|"+infant_num+"|";
			string f2=ph_num+"|"+t[op1].number+"|"+number2+"|"+t[op1].name+"|"+name2+"|"+t[op1].dept_time+"|"+dept_time2+"|";	
			string f=f1+f2+total1+"|"+total2+"|";

}


void design1()
{
	space();
	for(int k=0;k<10;k++)
	{
		cout<<"*";
	}
	cout<<"TRANSPORTATION RESERVATION SYSTEM";
	for(int k=0;k<10;k++)
	{
		cout<<"*";
	}
	cout<<endl;
	space();
	star();
		for(int i=0;i<43;i++)
	{
		cout<<" ";
	}	
	cout<<"[1] TICKET INFORMATION\n";
		for(int i=0;i<43;i++)
	{
		cout<<" ";
	}	
		cout<<"[2] BOOK TICKET\n";
			for(int i=0;i<43;i++)
	{
		cout<<" ";
	}	cout<<"[3] CANCEL TICKET\n";
		for(int i=0;i<43;i++)
	{
		cout<<" ";
	}	cout<<"[4] ADMIN\n";
		for(int i=0;i<43;i++)
	{
		cout<<" ";
	}	cout<<"[5] EXIT\n";
	space();
	star();
	space();
	cout<<"enter the choice ";
}


void design2()
{
	space();
	star();
		for(int i=0;i<43;i++)
	{
		cout<<" ";
	}
	cout<<"SERIAL No."<<"  "<<"TRANSPORT NAME"<<endl;
}


void design3()
{
	space();
	star();
}

void design4()
{
	space();
	for(int k=0;k<19;k++)
	{
		cout<<"*";
	}
	cout<<"ADMINISTRATION";
	for(int k=0;k<20;k++)
	{
		cout<<"*";
	}
	cout<<endl;
	space();
	star();
		for(int i=0;i<43;i++)
	{
		cout<<" ";
	}	
	cout<<"[1] VIEW TRANSPORT LIST\n";
		for(int i=0;i<43;i++)
	{
		cout<<" ";
	}	
		cout<<"[2] ADD TRANSPORTATION\n";
			for(int i=0;i<43;i++)
	{
		cout<<" ";
	}	cout<<"[3] MODIFY TRANSPORT LIST\n";
		for(int i=0;i<43;i++)
	{
		cout<<" ";
	}	cout<<"[4] DELETE TRANSPORTATION\n";
		for(int i=0;i<43;i++)
	{
		cout<<" ";
	}	cout<<"[5] BACK\n";
	space();
	star();
	space();
	cout<<"enter the choice ";
}
void design5()
{space();
	cout<<"[1] ADD DETAILS"<<endl;space();
	cout<<"[2] MODIFY DETAILS"<<endl;space();
	cout<<"[3] DELETE DETAILS"<<endl;space();
	cout<<"[4] BACK"<<endl;space();
	cout<<"ENTER THE CHOICE  ";
}
void space()
{
	for(int i=0;i<30;i++)
	   {
			cout<<" ";
	   }
}


void star()
{
	for(int k=0;k<53;k++)
		{
			cout<<"*";
		}
		cout<<endl;	
 } 
 
 
void admin()
{
	int flag1,i=0,count,choice;
	string ch;
	design3();
	cout<<"\n";
	while(1)
	{
		    design4();
			cin>>choice;
			switch(choice)
			{
				case 1:view_trans('0');break;
				case 2:add_trans();break;
				case 3:ch=view_trans('*');
						if(ch=="0"){
						break;
					}s.mod_det("",ch);break;
				case 4:del_trans();break;
				case 5:return;
				default: space();
						 cout<<"Ofcourse I love you! please enter the correct choice :)\n";
						 space();
						 star();
						cout<<endl;		
			}
	}
}
string view_trans(char q='0')
{
	design2();
	string choice,trans_name;
	int i=0,count1,count,a;
	fp.open("transport_names.txt",ios::in);
			while(fp)
				{ 
					t[i].unpack1_names();
					i++;
				}
			count=i;
			for(int j=0;j<count-1;j++)
			{cout<<"\n";
				t[j].display1_names();
			}
			fp.close();
			count1=i;
			if(count1==1)
			{	
			space();cout<<"         LIST IS EMPTY!ADD TRANSPORT DETAILS\n";return "0";
			}
			else{
			while(1)
			{
				space();cout<<"Enter the serial number ";cin>>choice;cout<<endl;
			space();star();int a=check(choice);
			if(a){
					if(q=='*')
				{
					return choice;
				}
					cout<<"ROUTE.NO"<<"     DEPARTURE"<<"     DESTINATION"<<"     TRANSP NAME"<<"     TYPE"<<"     RUN DAYS"<<"     DEPARTURE TIME"<<"     ARRIVAL TIME"<<"    PRICE"<<endl;
					int i=0,a;
	fp.open(choice+".txt",ios::in);
			while(fp)
				{ 
					t[i].unpack1_props();
					i++;
				}
				a=i;
				for(int j=0;j<a-1;j++)
			{
				t[j].display1_props();
			}
		cout<<"***********************************************************************************************************************\n";
			fp.close();
			break;
			}
			else
			{
				space();cout<<choice<<" "<<"Don't exist\n";
			}
			}
		}
		for(i=0;i<count;i++)
		{
			if(t[i].sn==choice)
			{
				trans_name=t[i].trans_names;
			}
		}
		if(q=='0'){
			display_trans_props(choice,trans_name,1);
		}else{return choice;} return "0";
}

void add_trans()
{
	int i=0;
	for(i=0;i<43;i++)
	{
		cout<<" ";
	}
	cout<<"   "<<"ADD"<<"         "<<"[NEW TRANSPORTATION]\n";space();star();
    int a=t[i].enter_new_trans_names();
	fp.open("transport_names.txt",ios::out|ios::app);
	if(a)
	{
		t[i].pack1_names();
	}
	fp.close();
	i++;
}	
string display_trans_props(string sn,string trans_names,int d=0)
{
	int choice;
	while(1)
	{		
	if(d==0){
		updated_table(sn);
	}
	design5();
	cin>>choice;
	switch(choice)
	{
		case 1:s.add_det(sn,trans_names,choice);d=0;
		break;
		case 2:s.mod_det(sn,trans_names);d=0;
		break;
		case 3:s.del_det(sn,trans_names);d=0;
		break;
		case 4:return "0";
		default:space();cout<<"Of course I Love you!! Enter the correct choice :)\n";
		}
	}	
}		
void view_info()
{
	string a=view_trans('1');
	design3();string ph;
	space();cout<<"Enter your phone number"<<endl;space();cin>>ph;
	int i=0,count=0,flag2=0;
	fp.open("passenger.txt",ios::in);
	if(fp)
	{
		while(fp)
		{
			t[i].unpack2_pass();
			i++;
		}
	}fp.close();count=i;
	for(i=0;i<count-1;i++)
	{if(t[i].ph_num==ph&&t[i].sn==a){
		flag2=1;
		cout<<"["<<t[i].b1<<"]"<<endl;
		cout<<"\n1)Departure date "<<t[i].dmy1<<"\t\t\t"<<"2)Departure date "<<t[i].dmy2<<endl;
		cout<<"1)Departure place "<<t[i].deplace1<<"\t\t\t"<<"2)Departure place "<<t[i].dp1<<endl;
		cout<<"1)Destination place "<<t[i].deplace2<<"\t\t\t"<<"2)Destination place "<<t[i].dp2<<endl;
		cout<<"1)Vehicle 1 number "<<t[i].number<<"\t\t\t\t"<<"2)Vehicle 2 number "<<t[i].number2<<endl;
		cout<<"1)Vehicle 1 name "<<t[i].name<<"\t\t\t"<<"2)Vehicle 2 name "<<t[i].name2<<endl;
		cout<<"1)Departure time "<<t[i].dept_time<<"\t\t\t\t"<<"2)Departure time"<<t[i].dept_time2<<endl;
		cout<<"Number of adults "<<t[i].adult_num<<endl;
		cout<<"Number of childrens "<<t[i].child_num<<endl;
		cout<<"Number of Infants "<<t[i].infant_num<<endl;
		cout<<"Total price "<<(stoi(t[i].total1)+stoi(t[i].total2))<<endl;
	}
	}
	if(flag2==0){
		design3();space();cout<<"                     NOT FOUND"<<endl;design3();
	}
}

void book_tic()
{
	int choice;
	while(1){
			space();
			cout<<"(1)ONE WAY\n";space();cout<<"(2)ROUND TRIP\n";space();
			cout<<"(3)BACK\n";space();cout<<"ENTER YOUR CHOICE  ";cin>>choice;
			switch(choice)
			{
				case 1:s.trip_type(1);break;
				case 2:s.trip_type(2);break;
				case 3:return;
				default: space();
						 cout<<"Ofcourse I love you! please enter the correct choice :)\n";
						 space();
						 star();
						cout<<endl;
		}  
	}
}

void cancel_tic()
{
	string a=view_trans('1');
	design3();string ph,f;
	space();cout<<"Enter your phone number"<<endl;space();cin>>ph;
	design3();int i=0,count=0,count2,flag=0,flag1,flag2=0,k=1;
	fp.open("passenger.txt",ios::in);
	if(fp)
	{
		while(fp)
		{
			t[i].unpack2_pass();
			i++;
		}
	}fp.close();count=i;count2=count;
	for(i=0;i<count-1;i++)
	{if(t[i].ph_num==ph&&t[i].sn==a){
		flag2=1;
		cout<<"["<<t[i].b1<<"]"<<endl;
		cout<<"\n1)Departure date "<<t[i].dmy1<<"\t\t\t"<<"2)Departure date "<<t[i].dmy2<<endl;
		cout<<"1)Departure place "<<t[i].deplace1<<"\t\t\t"<<"2)Departure place "<<t[i].dp1<<endl;
		cout<<"1)Destination place "<<t[i].deplace2<<"\t\t\t"<<"2)Destination place "<<t[i].dp2<<endl;
		cout<<"1)Vehicle 1 number "<<t[i].number<<"\t\t\t\t"<<"2)Vehicle 2 number "<<t[i].number2<<endl;
		cout<<"1)Vehicle 1 name "<<t[i].name<<"\t\t\t"<<"2)Vehicle 2 name "<<t[i].name2<<endl;
		cout<<"1)Departure time "<<t[i].dept_time<<"\t\t\t\t"<<"2)Departure time"<<t[i].dept_time2<<endl;
		cout<<"Number of adults "<<t[i].adult_num<<endl;
		cout<<"Number of childrens "<<t[i].child_num<<endl;
		cout<<"Number of Infants "<<t[i].infant_num<<endl;
		cout<<"Total price "<<(stoi(t[i].total1)+stoi(t[i].total2))<<endl;
	}}
	if(flag2!=1){
			design3();space();cout<<"                     NOT FOUND"<<endl;design3();return;
	}
	string serial_num;cout<<"Enter the serial number to delete ";cin>>serial_num;
		for(i=0;i<count2;i++){
			if(t[i].sn==a&&t[i].b1==serial_num&&t[i].ph_num==ph){
		flag=1;flag1=i;
		}}
if(flag==1)
		{fp.open("passenger.txt",ios::out);
			t[flag1].ph_num="",t[flag1].sn="",t[flag1].b1="";
			for(i=0;i<count2-1;i++){
				if(t[i].ph_num!=""&&t[i].sn==a){
						string f1=t[i].sn+"|"+to_string(k)+"|"+t[i].AD+"|"+t[i].dmy1+"|"+t[i].dmy2+"|"+t[i].deplace1+"|"+t[i].dp1+"|"+t[i].deplace2+"|"+t[i].dp2+"|"+t[i].adult_num+"|"+t[i].child_num+"|"+t[i].infant_num+"|";
			string f2=t[i].ph_num+"|"+t[i].number+"|"+t[i].number2+"|"+t[i].name+"|"+t[i].name2+"|"+t[i].dept_time+"|"+t[i].dept_time2+"|";	
			f=f1+f2+t[i].total1+"|"+t[i].total2+"|";
			fp<<f<<endl;k++;
				}
				if(t[i].ph_num!=""&&t[i].sn!=a){
					string f1=t[i].sn+"|"+t[i].b1+"|"+t[i].AD+"|"+t[i].dmy1+"|"+t[i].dmy2+"|"+t[i].deplace1+"|"+t[i].dp1+"|"+t[i].deplace2+"|"+t[i].dp2+"|"+t[i].adult_num+"|"+t[i].child_num+"|"+t[i].infant_num+"|";
			string f2=t[i].ph_num+"|"+t[i].number+"|"+t[i].number2+"|"+t[i].name+"|"+t[i].name2+"|"+t[i].dept_time+"|"+t[i].dept_time2+"|";	
			f=f1+f2+t[i].total1+"|"+t[i].total2+"|";
			fp<<f<<endl;					
				}
				}
			design3();space();cout<<"              TICKET CANCELLED SUCCESSFULLY\n";design3();fp.close();
		}
		else if(flag==0)
		{
				design3();space();cout<<"                     NOT FOUND"<<endl;design3();
		}
}
void transportation::mod_trans(int i,string tn)
{
	int ch,j=0,count=0,srch_flag;;
design3();if(i>0&&i!=9)
{
	while(1)
	{
		space();cout<<"ENTER THE FIELD TO MODIFY\n";
		space();cout<<"(1) "<<tn<<" DEPARTURE\n";
		space();cout<<"(2) "<<tn<<" DESTINATION\n";
		space();cout<<"(3) "<<tn<<" NAME\n";
		space();cout<<"(4) "<<tn<<" TYPE\n";
		space();cout<<"(5) "<<tn<<" RUN DAYS\n";
		space();cout<<"(6) "<<tn<<" ARRIVAL TIME\n";
		space();cout<<"(7) "<<tn<<" PRICE\n";
		space();cout<<"(8) EXIT\n";
		design3();space();
		cout<<"Enter the choice ";cin>>ch;
		switch(ch)
		{
			case 1:space();cout<<"Enter "<<tn<<" new DEPARTURE ";cin>>from;
					 design3();space();cout<<"DETAILS MODIFIED SUCCESSFULLY\n";design3();
				break;
			case 2:space();cout<<"Enter "<<tn<<" new DESTINATION ";cin>>to;
					 design3();space();cout<<"DETAILS MODIFIED SUCCESSFULLY\n";design3();
				break;
			case 3:space();cout<<"Enter "<<tn<<" new NAME ";cin>>name;
					 design3();space();cout<<"DETAILS MODIFIED SUCCESSFULLY\n";design3();
				break;
			case 4:space();cout<<"Enter "<<tn<<" new TYPE ";cin>>type;
					 design3();space();cout<<"DETAILS MODIFIED SUCCESSFULLY\n";design3();
				break;
			case 5:space();cout<<"Enter "<<tn<<" new RUN DAYS ";cin>>run_days;
					 design3();space();cout<<"DETAILS MODIFIED SUCCESSFULLY\n";design3();
				break;
			case 6:space();cout<<"Enter "<<tn<<" new ARRIVAL TIME ";cin>>arrival_time;
					 design3();space();cout<<"DETAILS MODIFIED SUCCESSFULLY\n";design3();
				break;
			case 7:space();cout<<"Enter "<<tn<<" new PRICE ";cin>>cost_per_tic;
					 design3();space();cout<<"DETAILS MODIFIED SUCCESSFULLY\n";design3();
				break;
			case 8:return;
			default: space();
						 cout<<"Ofcourse I love you! please enter the correct choice :)\n";
						 space();
						 star();
						cout<<endl;
		}
	}
	}	else if(i==9){
		string s=tn+".txt";
		int n=s.length();
		char oldname[n+1];strcpy(oldname,s.c_str());
	    while(1)
	    {
	    	space();cout<<"(1) SERIAL NO\n";
		space();cout<<"(2) TRANSPORT NAME\n";
		space();cout<<"(3) EXIT\n";
		design3();space();
		cout<<"Enter the choice ";cin>>ch;
			
  if(ch==1)
		{
			space();cout<<"ENTER THE NEW SERIAL NUMBER ";cin>>sn;
			string a=sn+".txt";
			int b=a.length();
			char newname[b+1];strcpy(newname,a.c_str());
		
			if(rename(oldname,newname)!=0){
				design3();space();cout<<"file not renamed\n";design3();return;
			}
			else
			{
				design3();space();cout<<"serial num changed successfully\n";return;
			}
		}
		else if(ch==2)
		{
			space();cout<<"ENTER THE NEW TRANSPORT NAME ";cin>>trans_names;
			design3();space();cout<<"MODIFIED SUCCESSFULLY\n";design3();break;
		}
	else if(ch==3)
	{
		return;
	}
	else{
		space();cout<<"Ofcourse I love you! please enter the correct choice :)\n";
		space();star();cout<<endl;
	}
		}
		
	}
}


void del_trans()
{
	design3();string fn=view_trans('*')+".txt";
	int b=fn.length(),i=0,count,flag,flag1;
	char newname[b+1];strcpy(newname,fn.c_str());
	fp.open("transport_names.txt",ios::in); 
	if(fp)
		{
			while(fp)
			{
				t[i].unpack1_names();
				i++;
			}fp.close();
		}count=i;
		for(i=0;i<count;i++)
		{
			if(t[i].sn+".txt"==fn)
			{
			  flag=1;flag1=i;
			}
		}
		if(flag==1)
		{
			t[flag1].trans_names="";
		}fp.open("transport_names.txt",ios::out);
		for(i=0;i<count-1;i++)
		{
			t[i].pack1_names();
		}
		fp.close();
	if(remove(newname)!=0)
	{design3();space();
		perror("file deletion failed");design3();
	}
	else
	{
		design3();space();
		cout<<"file deleted successfully\n";design3();
}		
}
int check(string sn_1)
{
	int i=0,flag=0,count;
	fp.open(sn_1+".txt",ios::in);
	if(fp)
	{
		flag=1;
	}
	fp.close();
	return flag;
}

void passenger::add_det(string sn,string trans_name,int c)
{
	s.enter_new_trans_props(sn,trans_name,c);
}

void passenger::mod_det(string sn,string trans_name)
{
	int i=0,count,srch_flag=-1;
	string rt_num,dp,dt;
	design3();if(sn!=""){	
	space();cout<<"ENTER THE ROUTE NUMBER ";cin>>rt_num;
	space();cout<<"ENTER THE DEPARTURE PLACE ";cin>>dp;
	space();cout<<"ENTER THE DESTINATION PLACE ";cin>>dt;
	fp.open(sn+".txt",ios::in);
	if(fp){
		while(fp)
		{
			t[i].unpack1_props();
			i++;
		}
	}fp.close();
	count=i;
	for(i=0;i<count;i++)
	{
		if(t[i].number==rt_num&&t[i].from==dp&&t[i].to==dt){
			srch_flag=i;
		}
	}
	if(srch_flag==-1)
	{
		space();cout<<"NOT FOUND\n";return;
	}else{
		t[srch_flag].mod_trans(i,trans_name);
		fp.open(sn+".txt",ios::out);
		for(i=0;i<count-1;i++)
		{
			t[i].pack1_props();
		}
		fp.close();
	}
}
	else if(sn==""){
		fp.open("transport_names.txt",ios::in);
	if(fp){
		while(fp)
		{
			t[i].unpack1_names();
			i++;
		}
	}fp.close();
	count=i;
	for(i=0;i<count;i++)
	{
		if(t[i].sn==trans_name){
			srch_flag=i;
		}
	}
		t[srch_flag].mod_trans(9,trans_name);
		fp.open("transport_names.txt",ios::out);
		for(i=0;i<count-1;i++)
		{
			t[i].pack1_names();
		}
		fp.close();
	}
	}

void passenger::del_det(string sn,string trans_name)
{
	string rtn,dp,dt;int flag=0,flag1;int i=0,count;space();
	cout<<"ENTER THE "<<trans_name<<" NUMBER TO BE DELETED ";cin>>rtn;space();
	cout<<"ENTER THE "<<trans_name<<" DEPARTURE PLACE ";cin>>dp;space();
	cout<<"ENTER THE "<<trans_name<<" DESTINATION PLACE ";cin>>dt;		
	fp.open(sn+".txt",ios::in);
	while(fp)
		{
			t[i].unpack1_props();
			i++;
			
		}
		fp.close();
		count=i;
		for(i=0;i<count;i++)
		{
		if(t[i].number==rtn&&t[i].from==dp&&t[i].to==dt)
		{
			flag1=i;flag=1;
		} 
	
		}
		if(flag==1)
		{
			t[flag1].number="",t[flag1].from="",t[flag1].to="";
			design3();space();cout<<rtn<<" DELETED SUCCESSFULLY\n";design3();
		}
		else if(flag==0)
		{
			design3();space();cout<<rtn<<" NOT FOUND\n";design3();
		}
		fp.open(sn+".txt",ios::out);
		for(i=0;i<count-1;i++)
		{
			t[i].pack1_props();
		}
		fp.close();
}

void passenger::trip_type(int ans)
{ string dpttime1,dpttime2,d1,d2,d3,d4;int op1,op2;
	if(ans==1)
	{
	    a=view_trans('1');
	    if(a!="0"){
	    	 	while(1){
	    	 		cout<<"Enter the departure place ";cin>>deplace1;
	    	 		op=check2(a,deplace1,"","");d1=deplace1;
			if(op==1){
				break;
			}
			}
		while(1){
	    	 		cout<<"Enter the destination place ";cin>>deplace2;
			op=check2(a,deplace1,deplace2,"");d2=deplace2;
			if(op==1){
			int i=0,count,flag=0; 	
  fp.open(a+".txt",ios::in);
  while(fp)
  {
  	t[i].unpack1_props();i++;
  }fp.close();
  count=i;
  space();cout<<"     TRANSP NAME"<<"     TYPE"<<"     RUN DAYS"<<"     DEPARTURE TIME"<<"     ARRIVAL TIME"<<"    PRICE"<<endl;
  for(i=0;i<count-1;i++)
  {if(t[i].from==deplace1&&t[i].to==deplace2)
  	{
  	space();cout<<"        "<<t[i].name<<"       "+t[i].type<<"     "+t[i].run_days<<"     "+t[i].dept_time<<"          "+t[i].arrival_time<<"       "+t[i].cost_per_tic<<endl;		
	  }
  
  }
				break;
			}
			}
				while(1){
	    	 		cout<<"Enter the departure time ";cin>>dept_time;
			op=check2(a,deplace1,deplace2,dept_time);dpttime1=dept_time;
			if(op>=0){
				cout<<"Enter the departure date(dd/mm/yyyy) ";cin>>dmy1;
				break;
			}
			}		
		cout<<"\n\nCONFIRM BOOKING? [1(yes)/0(no)] ";cin>>op;
		if(op)
		{
			cout<<"ENTER YOUR PHONE NUMBER ";cin>>ph_num;cout<<"AADHAAR NUMBER ";cin>>AD;
		cout<<"NO OF ADULTS ";cin>>adult_num;
		cout<<"NO OF CHILDRENS ";cin>>child_num;
		cout<<"NO OF INFANTS ";cin>>infant_num;
		int a1=0,b=0,c=0;
		fp.open("passenger.txt",ios::in);
		if(fp){
			while(fp){
				t[b].unpack2_pass();b++;
			}
		}fp.close();c=b;
		for(b=0;b<c;b++){
			if(t[b].ph_num==ph_num&&t[b].sn==a){
				++a1;
			}
		}int i=0,count=0;
		fp.open(a+".txt",ios::in);
		 while(fp)
  {
  	t[i].unpack1_props();i++;
  }fp.close();op1=check2(a,d1,d2,dpttime1);
		string b1=to_string(a1+1);
			fp.open("passenger.txt",ios::out|ios::app);
			if(fp)
			{	total1=to_string((stof(adult_num)+stof(child_num)+stof(infant_num))*(stof(t[op1].cost_per_tic)));
				string f1=a+"|"+b1+"|"+AD+"|"+dmy1+"|"+"NULL"+"|"+deplace1+"|"+"NULL"+"|"+deplace2+"|"+"NULL"+"|"+adult_num+"|"+child_num+"|"+infant_num+"|";
			string f2=ph_num+"|"+t[op1].number+"|"+"NULL"+"|"+t[op1].name+"|"+"NULL"+"|"+t[op1].dept_time+"|"+"NULL"+"|";	
			string f=f1+f2+total1+"|"+"0"+"|";
				fp<<f<<endl;	
				design3();
				space();cout<<"              TICKET BOOKED SUCCESSFULLY\n";
				design3();
			}fp.close();
		}
		else{return;}
		}
	}
	else if(ans==2){
		a=view_trans('1');
	    	 	while(1){
	    	 		cout<<"Enter the departure place ";cin>>deplace1;
			op=check2(a,deplace1,"","");buff=deplace1;d1=deplace1;
			if(op==1){
				break;
			}
			}
		while(1){
	    	 		cout<<"Enter the destination place ";cin>>deplace2;
			op=check2(a,deplace1,deplace2,"");d2=deplace2;
			if(op==1){
			int i=0,count,flag=0; 	
  fp.open(a+".txt",ios::in);
  while(fp)
  {
  	t[i].unpack1_props();i++;
  }fp.close();
  count=i;
  space();cout<<"     TRANSP NAME"<<"     TYPE"<<"     RUN DAYS"<<"     DEPARTURE TIME"<<"     ARRIVAL TIME"<<"    PRICE"<<endl;
  for(i=0;i<count-1;i++)
  {if(t[i].from==deplace1&&t[i].to==deplace2)
  	{
  	space();cout<<"        "<<t[i].name<<"       "+t[i].type<<"     "+t[i].run_days<<"     "+t[i].dept_time<<"          "+t[i].arrival_time<<"       "+t[i].cost_per_tic<<endl;		
	  }
  
  }
				break;
			}
			}
				while(1){
	    	 		cout<<"Enter the departure time ";cin>>dept_time;
			op=check2(a,deplace1,deplace2,dept_time);dpttime1=dept_time;
			if(op>=0){
				cout<<"Enter the departure date(dd/mm/yyyy) ";cin>>dmy1;
				break;
			}
			}	cout<<"\n\n";	
			    if(a!="0"){updated_table(a);
	    	 	while(1){
	    	 		cout<<"Enter the departure place ";cin>>dp1;
			op=check2(a,dp1,"","");d3=dp1;
			if(op==1){
				if(dp1==buff){
					cout<<"departure are equal\n";continue;
				}
				break;
			}
			}
		while(1){
	    	 		cout<<"Enter the destination place ";cin>>dp2;
			op=check2(a,dp1,dp2,"");d4=dp2;
			if(op==1){
			int i=0,count,flag=0; 	
  fp.open(a+".txt",ios::in);
  while(fp)
  {
  	t[i].unpack1_props();i++;
  }fp.close();
  count=i;
  space();cout<<"     TRANSP NAME"<<"     TYPE"<<"     RUN DAYS"<<"     DEPARTURE TIME"<<"     ARRIVAL TIME"<<"    PRICE"<<endl;
  for(i=0;i<count-1;i++)
  {if(t[i].from==dp1&&t[i].to==dp2)
  	{
  	space();cout<<"        "<<t[i].name<<"       "+t[i].type<<"     "+t[i].run_days<<"     "+t[i].dept_time<<"          "+t[i].arrival_time<<"       "+t[i].cost_per_tic<<endl;		
	  }
  
  }
				break;
			}
			}
				while(1){
	    	 		cout<<"Enter the departure time ";cin>>dept_time;
			op=check2(a,dp1,dp2,dept_time);dpttime2=dept_time;
			if(op>=0){
				cout<<"Enter the departure date(dd/mm/yyyy) ";cin>>dmy2;
				break;
			}
			}		
		cout<<"\n\nCONFIRM BOOKING? [1(yes)/0(no)] ";cin>>op;
		if(op)
		{
			cout<<"ENTER YOUR PHONE NUMBER ";cin>>ph_num;cout<<"AADHAAR NUMBER ";cin>>AD;
		cout<<"NO OF ADULTS ";cin>>adult_num;
		cout<<"NO OF CHILDRENS ";cin>>child_num;
		cout<<"NO OF INFANTS ";cin>>infant_num;
		int a1=0,b=0,c=0;
		fp.open("passenger.txt",ios::in);
		if(fp){
			while(fp){
				t[b].unpack2_pass();b++;
			}
		}fp.close();c=b;
		for(b=0;b<c;b++){
			if(t[b].ph_num==ph_num&&t[b].sn==a){
				a1++;
				cout<<a1<<endl;
			}
		}int i=0,count=0;
		fp.open(a+".txt",ios::in);
		 while(fp)
  {
  	t[i].unpack1_props();i++;
  }fp.close();count=i;op1=check2(a,d1,d2,dpttime1);op2=check2(a,d3,d4,dpttime2);
	string b1=to_string(a1+1);
			fp.open("passenger.txt",ios::out|ios::app);
			if(fp)
			{	number2=t[op2].number,name2=t[op2].name,type2=t[op2].type,dept_time2=t[op2].dept_time;
			total1=to_string((stof(adult_num)+stof(child_num)+stof(infant_num))*(stof(t[op1].cost_per_tic)));
			total2=to_string((stof(adult_num)+stof(child_num)+stof(infant_num))*(stof(t[op2].cost_per_tic)));
			string f1=a+"|"+b1+"|"+AD+"|"+dmy1+"|"+dmy2+"|"+deplace1+"|"+dp1+"|"+deplace2+"|"+dp2+"|"+adult_num+"|"+child_num+"|"+infant_num+"|";
			string f2=ph_num+"|"+t[op1].number+"|"+number2+"|"+t[op1].name+"|"+name2+"|"+t[op1].dept_time+"|"+dept_time2+"|";	
			string f=f1+f2+total1+"|"+total2+"|";
			fp<<f<<endl;
			design3();
			space();cout<<"              TICKET BOOKED SUCCESSFULLY\n";
			design3();
			}fp.close();
		}
		else{return;}
		}
}
}
int check2(string a,string deplace1,string deplace2,string dept_time)
{
  int i=0,count,flag=0; 	
  fp.open(a+".txt",ios::in);
  while(fp)
  {
  	t[i].unpack1_props();i++;
  }fp.close();
  count=i;
  for(i=0;i<count-1;i++)
  {
  	if(deplace2==""&&dept_time==""){
	  if(t[i].from==deplace1)
  	{
  		flag=1;
	  }
	  }
	  if(deplace1!=""&&deplace2!=""&&dept_time==""){
	  if(t[i].from==deplace1&&t[i].to==deplace2)
  	{
  		flag=1;
	  }
	  }
	if(deplace2!=""&&dept_time!=""&&deplace1!="")
	{
		if(t[i].dept_time==dept_time&&t[i].from==deplace1&&t[i].to==deplace2){flag=i;
		return flag;break;
	  }
	}
  }
  if(flag==1)
  {
  	perror("found");return flag;
  }else{
  	cout<<"Not found\n";flag=-1;
  }
  return flag;
}
