#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

struct info
	 {  char name[15] ;
	    char fname[15];
	    char dob[11];
	    char email[26]; 
	    char add[20];
	    int rank;
	    char category[10];
	    char phone[15];
	    char state[10];
	 }s;

bool myfunction(const  info  &a, const info &b) 
	{ return a.rank < b.rank ;
	}

void sorting()
	{  vector<info> records;
	   ifstream fin; 
	   int i;
	   fin.open("DATA.txt",ios::in|ios::binary);
	   while(fin.read(reinterpret_cast <char *> (&s),sizeof(info)))
	     {  records.push_back(s);
	     }
	   fin.close();
	   std::sort(records.begin(),records.end(),myfunction);
	   ofstream fout("DATA.txt",ios::out|ios::binary);
	   for(i=0;i<records.size();i++)
	    { fout.write(reinterpret_cast<char*>(&records[i]),sizeof(info));
	    }
	   fout.close();
	}

int convert_d_od()
	{   ifstream f("DATA.TXT",ios::in|ios::binary);
	    ofstream f1("DELHI.TXT",ios::out|ios::binary);

	    ofstream f2("OD.TXT",ios::out|ios::binary);

	    int i;
	    while(f.read(reinterpret_cast <char *> (&s),sizeof(info)))
	      {     
		 if(!(strcmpi(s.state,"Delhi")))
		    { f1.write(reinterpret_cast <char *> (&s),sizeof(info));
		    }
		 else
		    {  f2.write(reinterpret_cast <char *> (&s),sizeof(info));
		    }
	      }
	    f.close();
	    f1.close();
	    f2.close();
	    return 0;
	}

int convert_d_cat()
	{
	    ifstream f("DELHI.TXT",ios::in|ios::binary);
	    ofstream f1 ("DST.TXT",ios::out|ios::binary);
	    ofstream f2("DSC.TXT",ios::out|ios::binary);
	    ofstream f3 ("DGEN.TXT",ios::out|ios::binary);
	    ofstream f4 ("DOBC.TXT",ios::out|ios::binary); 
	    while(f.read(reinterpret_cast <char*>(&s),sizeof(info)))
	     {  
		if(!strcmpi(s.category,"ST"))  
		   { f1.write(reinterpret_cast<char*>(&s),sizeof(info));
		   }
		else if(!strcmpi(s.category,"SC")) 
		   { f2.write( reinterpret_cast<char*>(&s),sizeof(info));
		   }
		else if((!strcmpi(s.category,"General")) ||(!strcmpi(s.category,"gen")))
		   { f3.write( reinterpret_cast<char*>(&s),sizeof(info));
		   }
		else if(!strcmpi(s.category,"OBC"))  
		   { f4.write(reinterpret_cast<char*>(&s),sizeof(info));
		   }
	     }
	    f.close();
	    f1.close();
	    f2.close();
	    f3.close();
	    f4.close();
	    return 0;
	}

int convert_od_cat()
	{
	    ifstream f("OD.TXT",ios::in|ios::binary);
	    ofstream f1 ("ODST.TXT",ios::out|ios::binary);
	    ofstream f2("ODSC.TXT",ios::out|ios::binary);
	    ofstream f3 ("ODGEN.TXT",ios::out|ios::binary);
	    ofstream f4 ("ODOBC.TXT",ios::out|ios::binary); 
	    while(f.read(reinterpret_cast <char*>(&s),sizeof(info)))
	     {  
		if(!strcmpi(s.category,"ST"))  
		   { f1.write(reinterpret_cast<char*>(&s),sizeof(info));
		   }
		else if(!strcmpi(s.category,"SC")) 
		   { f2.write( reinterpret_cast<char*>(&s),sizeof(info));
		   }
		else if((!strcmpi(s.category,"General")) ||(!strcmpi(s.category,"gen")))
		   { f3.write( reinterpret_cast<char*>(&s),sizeof(info));
		   }
		else if(!strcmpi(s.category,"OBC"))  
		   { f4.write(reinterpret_cast<char*>(&s),sizeof(info));
		   }
	     }
	    f.close();
	    f1.close();
	    f2.close();
	    f3.close();
	    f4.close();
	    return 0;
	}

int main()
	{   sorting();
	    convert_d_od();
	    convert_d_cat();    
	    convert_od_cat();    
	return 0;
	}




