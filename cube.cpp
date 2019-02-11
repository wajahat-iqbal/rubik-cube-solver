#include<iostream>
#include<Windows.h>
#include <ctime>
#include<conio.h>
using namespace std;


char rot[1000];
int  phase[1000];
int s=0;

int user_pointer=0;
void color(int x);
void set_consloe();
void print_steps(int (&cube)[3][3][6]);
void step(int p,char r,int step);
void printCube(int (&cube)[3][3][6]);
void rotatecal(int phase  ,char rot, int (&cube)[3][3][6]);
void input(int (&cube)[3][3][6]);
void instructions();
void make(int (&cube)[3][3][6]);

void final_cube(int (&cube)[3][3][6]);
void compelet_cor(int (&cube)[3][3][6]);
void compelet_mid(int (&cube)[3][3][6]);
void set_top_phase_mid(int (&cube)[3][3][6]);
void set_top_phase_cor(int (&cube)[3][3][6]);
void set_second_layer_cor(int (&cube)[3][3][6]);
void set_first_layer_mid(int (&cube)[3][3][6]);
void set_first_layer_cor(int (&cube)[3][3][6]);
void set_mid(int (&cube)[3][3][6]);
void set_cor(int (&cube)[3][3][6]);
void step(int phase,char rot,int (&cube)[3][3][6]);


int main(){



	int cube[3][3][6];
	color(0);
	int phase;
	char rotation;
	set_consloe();
	instructions();

	int choice;
	cout<<"Enter 1 to Genrate A rendom Cube ::\n"<<
		  "Enter 2 to Enter your Cube \n";
	cin>>choice;

	if(choice==1)make(cube);
	else if(choice==2)input(cube);
	else {cout<<"Invalid Choice"; exit(0); }

	//input(cube);
   // make(cube);
	while(1){
		
         
        cout<<"               Enter Rotation                        "<<endl;
		cout<<endl;
		cout<<endl;
		cin>>phase;
		cin>>rotation;	
        step(phase,rotation,cube);
	
        cout<<endl;
     	 cout<<endl;
		 printCube(cube);
		//print_steps(cube);
		 cout<<endl;
		 cout<<endl;
	


	}

}


void color(int x){
	 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch(x){

	    case 0:

		SetConsoleTextAttribute(hConsole, 7);
		break;
		case 1:
		SetConsoleTextAttribute(hConsole, 13);
		break;
		case 2:
		SetConsoleTextAttribute(hConsole, 12);
		break;
		case 3:
		SetConsoleTextAttribute(hConsole, 10);
		break;
		case 4:
		SetConsoleTextAttribute(hConsole, 9);
		break;
		case 5:
		SetConsoleTextAttribute(hConsole, 14);
		break;

	}
}
void printCube(int (&cube)[3][3][6]){

	cout<<endl;

   cout<<"\t";
      for(int i=0;i<3;i++){
			for(int j=0;j<3;j++) 
			{ 
				
				color(cube[i][j][3]);
				cout<<cube[i][j][3]<<" ";
			
			}
		cout<<endl<<"\t";
		}
	  cout<<endl;



	
		for(int i=0;i<3;i++){
	     
			for(int j=0;j<3;j++) 
			{ 
				color(cube[i][j][1]);
				cout<<cube[i][j][1]<<" ";
			
			}
				cout<<"\t";
			for(int j=0;j<3;j++) 
			{ 
				color(cube[i][j][0]);
				cout<<cube[i][j][0]<<" ";
			
			}
				cout<<"\t";
			for(int j=0;j<3;j++) 
			{ 
				color(cube[i][j][2]);
				cout<<cube[i][j][2]<<" ";
			
			}
				cout<<"\t";cout<<"\t";cout<<"\t";
			for(int j=0;j<3;j++) 
			{ 
				color(cube[i][j][5]);
				cout<<cube[i][j][5]<<" ";
			
			}
				cout<<"\t";
			

	
		
	 cout<<endl;
	}
		
		cout<<endl;

     cout<<"\t";
	  

      for(int i=0;i<3;i++){
			for(int j=0;j<3;j++) 
			{ 
				
				color(cube[i][j][4]);
				cout<<cube[i][j][4]<<" ";
			
			}
		cout<<endl<<"\t";
		}
	  cout<<endl;

	  color(0);

}
void rotatecal(int phase  ,char rot, int (&cube)[3][3][6]){
	
cout<<" "<<phase<<rot<<" ";


		int a[12];
	int temp[3][3];
	switch (phase)
	{
	case 0:
		//white phase 

	

		if (rot=='A' || rot=='a'){

			//Rotating white phase aniclock 
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[2-j][i]=cube[i][j][0];
	        for(int i=0;i<3;i++) for(int j=0;j<3;j++) cube[i][j][0]=temp[i][j];
             for(int i=0;i<3;i++){
				a[i]=cube[i][2][1];
			    a[2+3-i]=cube[0][i][4];
				a[2+3+3-i]=cube[i][0][2];
				a[i+3+3+3]=cube[2][2-i][3];

			}

			for(int i=0;i<3;i++){
				
				cube[i][2][1]=a[i+3+3+3];
			    cube[0][i][4]=a[i];
				cube[i][0][2]=a[i+3];
				cube[2][2-i][3]=a[i+3+3];

		
			}

		
		}
		else if(rot=='C' || rot=='c'){
			  //Rotating white phase clock 
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[j][2-i]=cube[i][j][0];
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) cube[i][j][0]=temp[i][j];
			 for(int i=0;i<3;i++){
				a[i]=cube[i][2][1];
			    a[i+3]=cube[0][i][4];
				a[2+3+3-i]=cube[i][0][2];
				a[2+3+3+3-i]=cube[2][2-i][3];

			}
			for(int i=0;i<3;i++){
				
				cube[i][2][1]=a[i+3];
			    cube[0][i][4]=a[i+3+3];
				cube[i][0][2]=a[i+3+3+3];
				cube[2][2-i][3]=a[i];
		    
			}


		}








		 break;
	case 1:
		
		
		
		if (rot=='A' || rot=='a'){
			//Rotating Red phase aniclock 
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[2-j][i]=cube[i][j][1];
	        for(int i=0;i<3;i++) for(int j=0;j<3;j++) cube[i][j][1]=temp[i][j];
           	  for(int i=0;i<3;i++){
				a[i]=cube[i][0][0];
			    a[i+3]=cube[i][0][4];
				a[2+3+3-i]=cube[i][2][5];
				a[2+3+3+3-i]=cube[i][0][3];

			}
/////////			 for(int i=0;i<12;i++)cout<<a[i];
/////////			 cout<<endl;
			for(int i=0;i<3;i++){
				
				cube[i][0][0]=a[i+3];
				cube[i][0][4]=a[i+3+3];
				cube[i][2][5]=a[i+3+3+3];
				cube[i][0][3]=a[i];

		
			}






		
		}

		else if(rot=='C' || rot=='c'){
			//Rotating Red phase clock
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[j][2-i]=cube[i][j][1];
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) cube[i][j][1]=temp[i][j];
		

			   for(int i=0;i<3;i++){
				a[i]=cube[i][0][0];
			    a[2+3-i]=cube[i][0][4];
				a[2+3+3-i]=cube[i][2][5];
				a[i+3+3+3]=cube[i][0][3];

			}
		///	 for(int i=0;i<12;i++)cout<<a[i];
		///	 cout<<endl;
			for(int i=0;i<3;i++){
				
				cube[i][0][0]=a[i+3+3+3];
			    cube[i][0][4]=a[i];
				cube[i][2][5]=a[i+3];
				cube[i][0][3]=a[i+3+3];

		
			}





		}








		 break;
	case 2:

		//Orange phase


		
		if (rot=='A' || rot=='a'){
			//Rotating Orange phase aniclock 
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[2-j][i]=cube[i][j][2];
	        for(int i=0;i<3;i++) for(int j=0;j<3;j++) cube[i][j][2]=temp[i][j];
          		   for(int i=0;i<3;i++){
				a[i]=cube[i][2][0];
			    a[2+3-i]=cube[i][2][4];
				a[2+3+3-i]=cube[i][0][5];
				a[i+3+3+3]=cube[i][2][3];

			}
			// for(int i=0;i<12;i++)cout<<a[i];
			// cout<<endl;
			for(int i=0;i<3;i++){
				
				cube[i][2][0]=a[i+3+3+3];
			    cube[i][2][4]=a[i];
				cube[i][0][5]=a[i+3];
				cube[i][2][3]=a[i+3+3];

		
			}









		
		}

		else if(rot=='C' || rot=='c'){
			//Rotating Orange phase clock
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[j][2-i]=cube[i][j][2];
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) cube[i][j][2]=temp[i][j];
		

		


			  for(int i=0;i<3;i++){
				a[i]=cube[i][2][0];
			    a[i+3]=cube[i][2][4];
				a[2+3+3-i]=cube[i][0][5];
				a[2+3+3+3-i]=cube[i][2][3];

			}
		/////	 for(int i=0;i<12;i++)cout<<a[i];
		/////	 cout<<endl;
			for(int i=0;i<3;i++){
				
				cube[i][2][0]=a[i+3];
				cube[i][2][4]=a[i+3+3];
				cube[i][0][5]=a[i+3+3+3];
				cube[i][2][3]=a[i];

		
			}
		}










		 break;
	case 3:
		//Green Phase

		
		if (rot=='A' || rot=='a'){
			//Rotating Green phase aniclock 
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[2-j][i]=cube[i][j][3];
	        for(int i=0;i<3;i++) for(int j=0;j<3;j++) cube[i][j][3]=temp[i][j];
             for(int i=0;i<3;i++){
				a[i]=cube[0][i][0];
			    a[i+3]=cube[0][i][2];
				a[i+3+3]=cube[0][i][5];
				a[i+3+3+3]=cube[0][i][1];

			}
	///		 for(int i=0;i<12;i++)cout<<a[i];
		////	 cout<<endl;
			for(int i=0;i<3;i++){
				
				cube[0][i][0]=a[i+3+3+3];
			    cube[0][i][2]=a[i];
				cube[0][i][5]=a[i+3];
				cube[0][i][1]=a[i+3+3];

		
			}
		
		}

		else if(rot=='C' || rot=='c'){
			//Rotating Green phase clock
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[j][2-i]=cube[i][j][3];
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) cube[i][j][3]=temp[i][j];
			  for(int i=0;i<3;i++){
				a[i]=cube[0][i][0];
			    a[i+3]=cube[0][i][2];
				a[i+3+3]=cube[0][i][5];
				a[i+3+3+3]=cube[0][i][1];

			}
	////		 for(int i=0;i<12;i++)cout<<a[i];
//////			 cout<<endl;
			for(int i=0;i<3;i++){
				
				cube[0][i][0]=a[i+3];
				cube[0][i][2]=a[i+3+3];
				cube[0][i][5]=a[i+3+3+3];
				cube[0][i][1]=a[i];

		
			}




		}













		 break;
	case 4:
		//bule phase 


		
		
		if (rot=='A' || rot=='a'){
			//Rotating Blue phase aniclock 
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[2-j][i]=cube[i][j][4];
	        for(int i=0;i<3;i++) for(int j=0;j<3;j++) cube[i][j][4]=temp[i][j];
            
		  for(int i=0;i<3;i++){
				a[i]=cube[2][i][0];
			    a[i+3]=cube[2][i][2];
				a[i+3+3]=cube[2][i][5];
				a[i+3+3+3]=cube[2][i][1];

			}
//////			 for(int i=0;i<12;i++)cout<<a[i];
///////			 cout<<endl;
			for(int i=0;i<3;i++){
				
				cube[2][i][0]=a[i+3];
				cube[2][i][2]=a[i+3+3];
				cube[2][i][5]=a[i+3+3+3];
				cube[2][i][1]=a[i];

		
			}
		}

		else if(rot=='C' || rot=='c'){
			//Rotating Blue phase clock
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[j][2-i]=cube[i][j][4];
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) cube[i][j][4]=temp[i][j];
			

			 for(int i=0;i<3;i++){
				a[i]=cube[2][i][0];
			    a[i+3]=cube[2][i][2];
				a[i+3+3]=cube[2][i][5];
				a[i+3+3+3]=cube[2][i][1];

			}
//////			 for(int i=0;i<12;i++)cout<<a[i];
//////			 cout<<endl;
			for(int i=0;i<3;i++){
				
				cube[2][i][0]=a[i+3+3+3];
			    cube[2][i][2]=a[i];
				cube[2][i][5]=a[i+3];
				cube[2][i][1]=a[i+3+3];

		
			}


		}














		 break;
 	case 5:
		//yellow phase 

		
		
		if (rot=='A' || rot=='a'){
			

				for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[j][2-i]=cube[i][j][5];
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) cube[i][j][5]=temp[i][j];

			//Rotating yellow phase aniclock 
			
             for(int i=0;i<3;i++){
				a[i]=cube[i][0][1];
			    a[2+3-i]=cube[2][i][4];
				a[i+3+3]=cube[i][2][2];
				a[2+3+3+3-i]=cube[0][i][3];

			}

			for(int i=0;i<3;i++){
				
				cube[i][0][1]=a[i+3+3+3];
			    cube[2][i][4]=a[i];
				cube[i][2][2]=a[i+3];
				cube[0][i][3]=a[i+3+3];

		
			}

		
		}
		else if(rot=='C' || rot=='c'){
			  //Rotating yellow phase clock 
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[2-j][i]=cube[i][j][5];
	        for(int i=0;i<3;i++) for(int j=0;j<3;j++) cube[i][j][5]=temp[i][j];
		
			
			 for(int i=0;i<3;i++){
				a[2-i]=cube[i][0][1];
			    a[i+3]=cube[2][i][4];
				a[2+3+3-i]=cube[i][2][2];
				a[i+3+3+3]=cube[0][i][3];

			}
			for(int i=0;i<3;i++){
				
				cube[i][0][1]=a[i+3];
			    cube[2][i][4]=a[i+3+3];
				cube[i][2][2]=a[i+3+3+3];
				cube[0][i][3]=a[i];
		    
			}


		}


		





		 break;



	default:
		break;
	}



}
void step(int p,char r,int step){

	 rot[step]=r;
     phase[step]=p;


}
void print_steps(int (&cube)[3][3][6]){
	int i=0;
	user_pointer=0;
	cout<<endl;
	do{

		system("cls");
		printCube(cube);
		cout<<endl;	
		i=0;
	while(rot[i] =='c' || rot[i] =='a'){
		if(user_pointer==i){
			color(5);
		}
		else{

			color(0);
		}
		cout<<phase[i]<<rot[i]<<"  ";
		i++;

	}
	char ch=_getch();
	if(ch=='\r')user_pointer++;


	}while(i!=user_pointer);
	
}
void set_consloe(){
  CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 24;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

}
void input(int (&cube)[3][3][6]){
			cout<<"               Enter Your Cube                        "<<endl;
	for(int k=0;k<6;k++) 
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)  cin>>cube[i][j][k];

	
        cout<<"               Your cube is                      "<<endl;

		printCube(cube);
}
void instructions(){

	


	  
		cout<<"======================================================"<<endl;
		cout<<"|                        Manual                        "<<endl;
        cout<<"|   white center phase  ==  0  >>  Example  0a and 0c "<<endl;
		cout<<"|   Red center phase    ==  1  >>  Example  1a and 1c "<<endl;
        cout<<"|   Orange center phase ==  2  >>  Example  2a and 2c "<<endl;
		cout<<"|   Green center phase  ==  3  >>  Example  3a and 3c "<<endl;
		cout<<"|   Blue center phase   ==  4  >>  Example  4a and 4c "<<endl;
		cout<<"|   Yellow center phase ==  5  >>  Example  5a and 5c "<<endl;
		cout<<"======================================================"<<endl<<endl;
		cout<<"|	           Rotation Example                      "<<endl;
		cout<<"|	Example 0a  for rotating white phase         "<<endl;
		cout<<"|	anticlockwise                                "<<endl;
		cout<<"|	Example 0c  for rotating white phase         "<<endl;
		cout<<"|	clockwise                                    "<<endl;
		cout<<"======================================================"<<endl<<endl;
		cout<<"|    For Entring Your cube you can select your own     "<<endl;
		cout<<"|   values for different collor for eg                "<<endl;
		cout<<"|"<<endl;
		color(0);
		cout<<"|    white           == 0							 "<<endl;
		color(2);
		cout<<"|    Red             == 2							 "<<endl;
        color(1);
		cout<<"|    Orange/purpple  == 1							  "<<endl;
		color(3);
		cout<<"|    Green           == 3							  "<<endl;
        color(4);
		cout<<"|    Blue            == 4                               "<<endl;
		color(5);
		cout<<"|    Yellow          == 5                                "<<endl;
		color(0);
		cout<<"======================================================"<<endl<<endl;
		cout<<"|                 Instractions                         "<<endl;
		cout<<"|    Hold cube as the white center phase is in         "<<endl;
		cout<<"|     front of you red center is at your left 		 "<<endl;
		cout<<"|       Orange center is at youe right				 "<<endl;
        cout<<"|         green  center is at top						 "<<endl;
		cout<<"|       blue   center  is at bottom					 "<<endl;
        cout<<"|     Yellow side is opposit  to wite center           "<<endl;
	    cout<<"======================================================"<<endl<<endl;

}
void make(int (&cube)[3][3][6]){
	int cub[6][3][3]={ 
	
		 {{0, 0, 0},
		  {0, 0, 0}, 
		  {0, 0, 0} },

		   {{2, 2, 2},
		   {2, 2, 2}, 
		  {2, 2, 2} },

		   {{1, 1, 1},
		   {1, 1, 1}, 
		   {1, 1, 1} },
            
		    {{3, 3, 3},
		    {3, 3, 3}, 
		    {3, 3, 3} },


		   {{4, 4, 4},
		    {4, 4, 4},
		    {4, 4, 4} },

		    {{5, 5, 5},
		     {5, 5, 5}, 
		     {5, 5, 5} }
            
	};
	
	for(int k=0;k<6;k++)
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
	             cube[i][j][k]=cub[k][i][j];


	srand(time(0));

	int n=rand()%10;
for(int i=0;i<n;i++){
	    rotatecal(2,'c',cube);
		rotatecal(5,'a',cube);

		rotatecal(2,'c',cube);
		rotatecal(1,'a',cube);
}
n=rand()%5;
for(int i=0;i<n;i++){
		rotatecal(4,'a',cube);
		rotatecal(5,'c',cube);
		
		rotatecal(3,'c',cube);
		rotatecal(5,'a',cube);
}
n=rand()%5;
for(int i=0;i<n;i++){
		rotatecal(3,'c',cube);
		rotatecal(5,'a',cube);
	
}
n=rand()%5;
for(int i=0;i<n;i++){
		rotatecal(5,'a',cube);
		rotatecal(1,'a',cube);
		rotatecal(5,'a',cube);
		rotatecal(2,'a',cube);
		rotatecal(5,'c',cube);
		rotatecal(0,'a',cube);


}
n=rand()%2;
for(int i=0;i<n;i++){
		rotatecal(0,'a',cube);
		rotatecal(1,'a',cube);
}




printCube(cube);

}

void  final_cube(int (&cube)[3][3][6]){

	while(   cube[0][1][3] != cube[0][0][3] ||cube[0][1][3] != cube[0][2][3] 
	      || cube[1][2][2] != cube[0][2][2] ||cube[1][2][3] != cube[2][2][3] 
		  || cube[1][0][1] != cube[0][0][1] ||cube[1][0][1] != cube[2][0][1]
		  || cube[2][1][4] != cube[2][0][4] ||cube[2][1][4] != cube[2][2][4]
	      ){



        //3
			  //2a 0a 2c 0c

			  if(cube[0][1][3] == cube[0][2][3] && cube[1][2][2] == cube[0][2][2])
			  {

				  rotatecal(5,'c',cube);
			  }
			  else {
				   rotatecal(2,'a',cube);
				   rotatecal(0,'a',cube);
				   rotatecal(2,'c',cube);
				   rotatecal(0,'c',cube);

			  }




	}

}
void compelet_cor(int (&cube)[3][3][6]){

	while(1){


		
		
		  if(  (cube[2][2][5]==cube[1][1][1] || cube[2][2][5]==cube[1][1][5] || cube[2][2][5]==cube[1][1][4] )
	     && (cube[2][0][4]==cube[1][1][1] || cube[2][0][4]==cube[1][1][5] || cube[2][0][4]==cube[1][1][4])
		 && (cube[2][0][1]==cube[1][1][1] || cube[2][0][1]==cube[1][1][5] || cube[2][0][5]==cube[1][1][4]) 
		 &&
		 (  (cube[0][2][5]==cube[1][1][1] || cube[0][2][5]==cube[1][1][5] || cube[0][2][5]==cube[1][1][3] )
	     && (cube[0][0][1]==cube[1][1][1] || cube[0][0][1]==cube[1][1][5] || cube[0][0][1]==cube[1][1][3])
		 && (cube[0][0][3]==cube[1][1][1] || cube[0][0][3]==cube[1][1][5] || cube[0][0][3]==cube[1][1][3] ) )
		 
		 ){
		 //4
		 
			
			//  5a 1c 5c 2a 5a 1a 5c 2c
			 rotatecal(5,'a',cube);
			 rotatecal(1,'c',cube);
			 rotatecal(5,'c',cube);
			 rotatecal(2,'a',cube);
			 rotatecal(5,'a',cube);
			 rotatecal(1,'a',cube);
			 rotatecal(5,'c',cube);
		     rotatecal(2,'c',cube);
		 }
		  else if (  (cube[0][2][5]==cube[1][1][1] || cube[0][2][5]==cube[1][1][5] || cube[0][2][5]==cube[1][1][3] )
	     && (cube[0][0][1]==cube[1][1][1] || cube[0][0][1]==cube[1][1][5] || cube[0][0][1]==cube[1][1][3])
		 && (cube[0][0][3]==cube[1][1][1] || cube[0][0][3]==cube[1][1][5] || cube[0][0][3]==cube[1][1][3] )
		 &&
		 (  (cube[0][0][5]==cube[1][1][2] || cube[0][0][5]==cube[1][1][5] || cube[0][0][5]==cube[1][1][3] )
	     && (cube[0][2][3]==cube[1][1][2] || cube[0][2][3]==cube[1][1][5] || cube[0][2][3]==cube[1][1][3])
		 && (cube[0][2][2]==cube[1][1][2] || cube[0][2][2]==cube[1][1][5] || cube[0][2][2]==cube[1][1][3])  )
		 ){
			 //1

			 // front 1
			 // 5a 3c 5c 4a 5a 3a 5c 4c
	
			 rotatecal(5,'a',cube);
			 rotatecal(3,'c',cube);
			 rotatecal(5,'c',cube);
			 rotatecal(4,'a',cube);
			 rotatecal(5,'a',cube);
			 rotatecal(3,'a',cube);
			 rotatecal(5,'c',cube);
		     rotatecal(4,'c',cube);
		 }

			 
		  else if(  (cube[0][0][5]==cube[1][1][2] || cube[0][0][5]==cube[1][1][5] || cube[0][0][5]==cube[1][1][3] )
	     && (cube[0][2][3]==cube[1][1][2] || cube[0][2][3]==cube[1][1][5] || cube[0][2][3]==cube[1][1][3])
		 && (cube[0][2][2]==cube[1][1][2] || cube[0][2][2]==cube[1][1][5] || cube[0][2][2]==cube[1][1][3])  
		 &&
		 (  (cube[2][0][5]==cube[1][1][2] || cube[2][0][5]==cube[1][1][5] || cube[2][0][5]==cube[1][1][4]) 
	     && (cube[2][2][4]==cube[1][1][2] || cube[2][2][4]==cube[1][1][5] || cube[2][2][4]==cube[1][1][4])
		 && (cube[2][2][2]==cube[1][1][2] || cube[2][2][2]==cube[1][1][5] || cube[2][2][2]==cube[1][1][4])  )
		 )
		 {
			 //3

		
              //front  3
			 /// 5a 2c 5c 1a 5a 2a 5c 1c
			 
			 rotatecal(5,'a',cube);
			 rotatecal(2,'c',cube);
			 rotatecal(5,'c',cube);
			 rotatecal(1,'a',cube);
			 rotatecal(5,'a',cube);
			 rotatecal(2,'a',cube);
			 rotatecal(5,'c',cube);
		     rotatecal(1,'c',cube);
		 }
		
		  else if(  (cube[2][0][5]==cube[1][1][2] || cube[2][0][5]==cube[1][1][5] || cube[2][0][5]==cube[1][1][4]) 
	     && (cube[2][2][4]==cube[1][1][2] || cube[2][2][4]==cube[1][1][5] || cube[2][2][4]==cube[1][1][4])
		 && (cube[2][2][2]==cube[1][1][2] || cube[2][2][2]==cube[1][1][5] || cube[2][2][5]==cube[1][1][4]) 
		 &&  (cube[2][2][5]==cube[1][1][1] || cube[2][2][5]==cube[1][1][5] || cube[2][2][5]==cube[1][1][4] )
	     && (cube[2][0][4]==cube[1][1][1] || cube[2][0][4]==cube[1][1][5] || cube[2][0][4]==cube[1][1][4])
		 && (cube[2][0][1]==cube[1][1][1] || cube[2][0][1]==cube[1][1][5] || cube[2][0][5]==cube[1][1][4]) 
		 
		 
		 
		 )
		 {
         //2
			 
			  // front 2
			  //5a 4c 5c 3a 5a 4a 5c 3c
			 rotatecal(5,'a',cube);
			 rotatecal(4,'c',cube);
			 rotatecal(5,'c',cube);
			 rotatecal(3,'a',cube);
			 rotatecal(5,'a',cube);
			 rotatecal(4,'a',cube);
			 rotatecal(5,'c',cube);
		     rotatecal(3,'c',cube);
             
		 }




		  else  if(  (cube[2][2][5]==cube[1][1][1] || cube[2][2][5]==cube[1][1][5] || cube[2][2][5]==cube[1][1][4] )
	     && (cube[2][0][4]==cube[1][1][1] || cube[2][0][4]==cube[1][1][5] || cube[2][0][4]==cube[1][1][4])
		 && (cube[2][0][1]==cube[1][1][1] || cube[2][0][1]==cube[1][1][5] || cube[2][0][5]==cube[1][1][4])  ){
		 //4
		 
			
			//  5a 1c 5c 2a 5a 1a 5c 2c
			 rotatecal(5,'a',cube);
			 rotatecal(1,'c',cube);
			 rotatecal(5,'c',cube);
			 rotatecal(2,'a',cube);
			 rotatecal(5,'a',cube);
			 rotatecal(1,'a',cube);
			 rotatecal(5,'c',cube);
		     rotatecal(2,'c',cube);
		 }
		  else if (  (cube[0][2][5]==cube[1][1][1] || cube[0][2][5]==cube[1][1][5] || cube[0][2][5]==cube[1][1][3] )
	     && (cube[0][0][1]==cube[1][1][1] || cube[0][0][1]==cube[1][1][5] || cube[0][0][1]==cube[1][1][3])
		 && (cube[0][0][3]==cube[1][1][1] || cube[0][0][3]==cube[1][1][5] || cube[0][0][3]==cube[1][1][3] ) ){
			 //1

			 // front 1
			 // 5a 3c 5c 4a 5a 3a 5c 4c
	
			 rotatecal(5,'a',cube);
			 rotatecal(3,'c',cube);
			 rotatecal(5,'c',cube);
			 rotatecal(4,'a',cube);
			 rotatecal(5,'a',cube);
			 rotatecal(3,'a',cube);
			 rotatecal(5,'c',cube);
		     rotatecal(4,'c',cube);
		 }

			 
		  else if(  (cube[0][0][5]==cube[1][1][2] || cube[0][0][5]==cube[1][1][5] || cube[0][0][5]==cube[1][1][3] )
	     && (cube[0][2][3]==cube[1][1][2] || cube[0][2][3]==cube[1][1][5] || cube[0][2][3]==cube[1][1][3])
		 && (cube[0][2][2]==cube[1][1][2] || cube[0][2][2]==cube[1][1][5] || cube[0][2][2]==cube[1][1][3])  )
		 {
			 //3

		
              //front  3
			 /// 5a 2c 5c 1a 5a 2a 5c 1c
			 
			 rotatecal(5,'a',cube);
			 rotatecal(2,'c',cube);
			 rotatecal(5,'c',cube);
			 rotatecal(1,'a',cube);
			 rotatecal(5,'a',cube);
			 rotatecal(2,'a',cube);
			 rotatecal(5,'c',cube);
		     rotatecal(1,'c',cube);
		 }
		
		  else if(  (cube[2][0][5]==cube[1][1][2] || cube[2][0][5]==cube[1][1][5] || cube[2][0][5]==cube[1][1][4]) 
	     && (cube[2][2][4]==cube[1][1][2] || cube[2][2][4]==cube[1][1][5] || cube[2][2][4]==cube[1][1][4])
		 && (cube[2][2][2]==cube[1][1][2] || cube[2][2][2]==cube[1][1][5] || cube[2][2][5]==cube[1][1][4])  )
		 {
         //2
			 
			  // front 2
			  //5a 4c 5c 3a 5a 4a 5c 3c
			 rotatecal(5,'a',cube);
			 rotatecal(4,'c',cube);
			 rotatecal(5,'c',cube);
			 rotatecal(3,'a',cube);
			 rotatecal(5,'a',cube);
			 rotatecal(4,'a',cube);
			 rotatecal(5,'c',cube);
		     rotatecal(3,'c',cube);
             
		 }else{
	  	 rotatecal(5,'a',cube);
			 rotatecal(4,'c',cube);
			 rotatecal(5,'c',cube);
			 rotatecal(3,'a',cube);
			 rotatecal(5,'a',cube);
			 rotatecal(4,'a',cube);
			 rotatecal(5,'c',cube);
		     rotatecal(3,'c',cube);
		  }














	if(  (  (cube[2][2][5]==cube[1][1][1] || cube[2][2][5]==cube[1][1][5] || cube[2][2][5]==cube[1][1][4]) 
	     && (cube[2][0][4]==cube[1][1][1] || cube[2][0][4]==cube[1][1][5] || cube[2][0][4]==cube[1][1][4])
		 && (cube[2][0][1]==cube[1][1][1] || cube[2][0][1]==cube[1][1][5] || cube[2][0][5]==cube[1][1][4] ) )
		 
			 &&
	     (  (cube[0][2][5]==cube[1][1][1] || cube[0][2][5]==cube[1][1][5] || cube[0][2][5]==cube[1][1][3]) 
	     && (cube[0][0][1]==cube[1][1][1] || cube[0][0][1]==cube[1][1][5] || cube[0][0][1]==cube[1][1][3])
		 && (cube[0][0][3]==cube[1][1][1] || cube[0][0][3]==cube[1][1][5] || cube[0][0][3]==cube[1][1][3])  )



			 &&
	     (  (cube[0][0][5]==cube[1][1][2] || cube[0][0][5]==cube[1][1][5] || cube[0][0][5]==cube[1][1][3])
	     && (cube[0][2][3]==cube[1][1][2] || cube[0][2][3]==cube[1][1][5] || cube[0][2][3]==cube[1][1][3])
		 && (cube[0][2][2]==cube[1][1][2] || cube[0][2][2]==cube[1][1][5] || cube[0][2][2]==cube[1][1][3]) )


			 &&
	     (  (cube[2][0][5]==cube[1][1][2] || cube[2][0][5]==cube[1][1][5] || cube[2][0][5]==cube[1][1][4])
	     && (cube[2][2][4]==cube[1][1][2] || cube[2][2][4]==cube[1][1][5] || cube[2][2][4]==cube[1][1][4])
		 && (cube[2][2][2]==cube[1][1][2] || cube[2][2][2]==cube[1][1][5] || cube[2][2][2]==cube[1][1][4]) )

	  ) return;

	printCube(cube);









		  /*
		 
			if ((  cube[2][2][5]==cube[1][1][1] || cube[2][2][5]==cube[1][1][5] || cube[2][2][5]==cube[1][1][4] 
				|| cube[2][0][4]==cube[1][1][1] || cube[2][0][4]==cube[1][1][5] || cube[2][0][4]==cube[1][1][4]
				|| cube[2][0][1]==cube[1][1][1] || cube[2][0][1]==cube[1][1][5] || cube[2][0][5]==cube[1][1][4]  )	
				&&
				 (  cube[2][0][5]==cube[1][1][2] || cube[2][0][5]==cube[1][1][5] || cube[2][0][5]==cube[1][1][4] 
				 || cube[2][2][4]==cube[1][1][2] || cube[2][2][4]==cube[1][1][5] || cube[2][2][4]==cube[1][1][4]
				 || cube[2][2][2]==cube[1][1][2] || cube[2][2][2]==cube[1][1][5] || cube[2][2][5]==cube[1][1][4]  )
					
					
					)
				 {
					//3
				 }
				 
			else	if ( (  cube[2][0][5]==cube[1][1][2] || cube[2][0][5]==cube[1][1][5] || cube[2][0][5]==cube[1][1][4] 
				 || cube[2][2][4]==cube[1][1][2] || cube[2][2][4]==cube[1][1][5] || cube[2][2][4]==cube[1][1][4]
				 || cube[2][2][2]==cube[1][1][2] || cube[2][2][2]==cube[1][1][5] || cube[2][2][5]==cube[1][1][4]  )	
				&&
				    (  cube[0][0][5]==cube[1][1][2] || cube[0][0][5]==cube[1][1][5] || cube[0][0][5]==cube[1][1][3] 
				   || cube[0][2][3]==cube[1][1][2] || cube[0][2][3]==cube[1][1][5] || cube[0][2][3]==cube[1][1][3]
					 || cube[0][2][2]==cube[1][1][2] || cube[0][2][2]==cube[1][1][5] || cube[0][2][2]==cube[1][1][3]  )
					
					
					)
				 {
					 //3
				 }
		else	if ( (  cube[0][2][5]==cube[1][1][1] || cube[0][2][5]==cube[1][1][5] || cube[0][2][5]==cube[1][1][3] 
	     || cube[0][0][1]==cube[1][1][1] || cube[0][0][1]==cube[1][1][5] || cube[0][0][1]==cube[1][1][3]
		 || cube[0][0][3]==cube[1][1][1] || cube[0][0][3]==cube[1][1][5] || cube[0][0][3]==cube[1][1][3]  )	
				&&
				  (  cube[2][2][5]==cube[1][1][1] || cube[2][2][5]==cube[1][1][5] || cube[2][2][5]==cube[1][1][4] 
				|| cube[2][0][4]==cube[1][1][1] || cube[2][0][4]==cube[1][1][5] || cube[2][0][4]==cube[1][1][4]
				|| cube[2][0][1]==cube[1][1][1] || cube[2][0][1]==cube[1][1][5] || cube[2][0][5]==cube[1][1][4]  ) )
					
					
					)
				 {
					 //3
				 }

				*/













		  /*
              // front 1
			  5a 3c 5c 4a 5a 3a 5c 4c
			  // front 2
			  5a 4c 5c 3a 5a 4a 5c 3c
              //front  3
			  5a 2c 5c 1a 5a 2a 5c 1c
			  //front  4
			  5a 1c 5c 2a 5a 1a 5c 2c

		if(    cube[0][0][1]==cube[1][1][1] && cube[1][1][1]==cube[2][0][1] 
		&& cube[0][2][2]==cube[1][1][2] && cube[1][1][2]==cube[2][2][2] 
	    && cube[0][0][3]==cube[1][1][3] && cube[1][1][3]==cube[0][1][3] 
		&& cube[2][0][4]==cube[1][1][4] && cube[1][1][4]==cube[2][2][4] 
		) break;
		 */
		 



	
		 
		 }
}
void compelet_mid(int (&cube)[3][3][6]){



	while(cube[1][1][1] != cube[1][0][1] ||cube[1][1][2] != cube[1][2][2] ||
	      cube[1][1][3] != cube[0][1][3] ||cube[1][1][4] != cube[2][1][4] ){


	  
			  
		
		
			if((cube[1][1][1] == cube[1][0][1] &&cube[1][1][4] == cube[2][1][4] ) || (cube[1][1][4] == cube[2][1][4] ) )
			{	//front 2
				rotatecal(4,'c',cube);
				rotatecal(5,'a',cube);
				rotatecal(4,'a',cube);
				rotatecal(5,'a',cube);
				rotatecal(4,'c',cube);
				rotatecal(5,'a',cube);
				rotatecal(5,'a',cube);
				rotatecal(4,'a',cube);


			}
            else if((cube[1][1][2] == cube[1][2][2] && cube[1][1][4] == cube[2][1][4]) ||  (cube[1][1][2] == cube[1][2][2]) )
			{
				//front 3

				
					rotatecal(2,'c',cube);
					rotatecal(5,'a',cube);
					rotatecal(2,'a',cube);
					rotatecal(5,'a',cube);
					rotatecal(2,'c',cube);
					rotatecal(5,'a',cube);
					rotatecal(5,'a',cube);
					rotatecal(2,'a',cube);

					

			}
			else if( (cube[1][1][2] == cube[1][2][2] && cube[1][1][3] == cube[0][1][3]) || (cube[1][1][3] == cube[0][1][3]) )
			{
				//front 1
				rotatecal(3,'c',cube);
		rotatecal(5,'a',cube);
		rotatecal(3,'a',cube);
		rotatecal(5,'a',cube);
		rotatecal(3,'c',cube);
		rotatecal(5,'a',cube);
		rotatecal(5,'a',cube);
		rotatecal(3,'a',cube);

		
			}
			else if ((cube[1][1][1] == cube[1][0][1] && cube[1][1][3] == cube[0][1][3]) || (cube[1][1][1] == cube[1][0][1]) ){	// front 4

		rotatecal(1,'c',cube);
		rotatecal(5,'a',cube);
		rotatecal(1,'a',cube);
		rotatecal(5,'a',cube);
		rotatecal(1,'c',cube);
		rotatecal(5,'a',cube);
		rotatecal(5,'a',cube);
		rotatecal(1,'a',cube);

	

				}

			for(int i=0; i<3;i++){

				if ((cube[1][1][1] == cube[1][0][1] && cube[1][1][3] == cube[0][1][3]) ) break;
				else if( (cube[1][1][2] == cube[1][2][2] && cube[1][1][3] == cube[0][1][3]))break;
				else if((cube[1][1][2] == cube[1][2][2] && cube[1][1][4] == cube[2][1][4]) )break;
				else if((cube[1][1][1] == cube[1][0][1] &&cube[1][1][4] == cube[2][1][4]) )break;
				rotatecal(5,'a',cube);
			}
		  
		  
		    
		  if(cube[1][1][1] == cube[1][0][1] && cube[1][1][2] == cube[1][2][2] &&
	      cube[1][1][3] == cube[0][1][3] && cube[1][1][4] == cube[2][1][4] ) 
		  return; 
			
		  printCube(cube);
		  }

}
void set_top_phase_mid(int (&cube)[3][3][6]){
	
	//taking phase 3 on front
	while( cube[1][1][5]!=cube[0][1][5]
	     ||cube[1][1][5]!=cube[1][0][5]
		 ||cube[1][1][5]!=cube[1][2][5]
		 ||cube[1][1][5]!=cube[2][1][5]
	     ){
			 //if the 555

			 if(cube[1][1][5]==cube[0][1][5] && cube[1][1][5]==cube[2][1][5] )
			 {
				  rotatecal(1,'c',cube);
				 rotatecal(3,'c',cube);
				 rotatecal(5,'a',cube);
			      rotatecal(3,'a',cube);
				 rotatecal(5,'c',cube);
				
				 rotatecal(1,'a',cube);

			 }

			//  if   5
			//       5
			//		 5

			 else if(cube[1][1][5]==cube[1][0][5] && cube[1][1][5]==cube[1][2][5]){
				 rotatecal(4,'c',cube);
				 rotatecal(1,'c',cube);
				 rotatecal(5,'a',cube);
			      rotatecal(1,'a',cube);
				 rotatecal(5,'c',cube);
				
				 rotatecal(4,'a',cube);

			 }

			 // 3 on front
			 else if(cube[1][1][5]==cube[1][2][5] && cube[1][1][5]==cube[2][1][5]){

                 rotatecal(3,'c',cube);
				 rotatecal(5,'a',cube);
				 rotatecal(2,'c',cube);
				 rotatecal(5,'c',cube);
				 rotatecal(2,'a',cube);
				 rotatecal(3,'a',cube);
			 }

			 // 2 on front
			 else if(cube[1][1][5]==cube[0][1][5] && cube[1][1][5]==cube[1][2][5]){

                 rotatecal(2,'c',cube);
				 rotatecal(5,'a',cube);
				 rotatecal(4,'c',cube);
				 rotatecal(5,'c',cube);
				 rotatecal(4,'a',cube);
				 rotatecal(2,'a',cube);
			 }

			 //1 on front
			 else if(cube[1][1][5]==cube[2][1][5] && cube[1][1][5]==cube[1][0][5]){

                 rotatecal(1,'c',cube);
				 rotatecal(5,'a',cube);
				 rotatecal(3,'c',cube);
				 rotatecal(5,'c',cube);
				 rotatecal(3,'a',cube);
				 rotatecal(1,'a',cube);
			 }
			 // 4 on front 
			 else if(cube[1][1][5]==cube[1][0][5] && cube[1][1][5]==cube[0][1][5]){

                 rotatecal(4,'c',cube);
				 rotatecal(5,'a',cube);
				 rotatecal(1,'c',cube);
				 rotatecal(5,'c',cube);
				 rotatecal(1,'a',cube);
				 rotatecal(4,'a',cube);
			 }
			  
			 else{
				 rotatecal(3,'c',cube);
				 rotatecal(5,'a',cube);
				 rotatecal(2,'c',cube);
				 rotatecal(5,'c',cube);
				 rotatecal(2,'a',cube);
				 rotatecal(3,'a',cube);
			 }
			
		
			 	
		 }
		 cout<<endl;

}
void set_top_phase_cor(int (&cube)[3][3][6]){

	while(   cube[0][0][5]!=cube[1][1][5]
	      || cube[0][2][5]!=cube[1][1][5]
		  || cube[2][0][5]!=cube[1][1][5]
		  || cube[2][0][5]!=cube[1][1][5]
		 
	      ){
		  
	//3 f
	while(cube[0][2][3]==cube[1][1][5] || cube[0][2][2]==cube[1][1][5] ){
		
		rotatecal(2,'c',cube);
		rotatecal(5,'a',cube);
		rotatecal(2,'a',cube);
		rotatecal(5,'a',cube);
		rotatecal(2,'c',cube);
		rotatecal(5,'a',cube);
		rotatecal(5,'a',cube);
		rotatecal(2,'a',cube);

	}

	//2 f
	while(cube[2][2][2]==cube[1][1][5] || cube[2][2][4]==cube[1][1][5] ){
		rotatecal(4,'c',cube);
		rotatecal(5,'a',cube);
		rotatecal(4,'a',cube);
		rotatecal(5,'a',cube);
		rotatecal(4,'c',cube);
		rotatecal(5,'a',cube);
		rotatecal(5,'a',cube);
		rotatecal(4,'a',cube);


	}

	//4 f
	while(cube[0][2][4]==cube[1][1][5] || cube[2][0][1]==cube[1][1][5] ){
	    rotatecal(1,'c',cube);
		rotatecal(5,'a',cube);
		rotatecal(1,'a',cube);
		rotatecal(5,'a',cube);
		rotatecal(1,'c',cube);
		rotatecal(5,'a',cube);
		rotatecal(5,'a',cube);
		rotatecal(1,'a',cube);


	}

	while(cube[0][0][1]==cube[1][1][5] || cube[0][0][3]==cube[1][1][5] ){
		rotatecal(3,'c',cube);
		rotatecal(5,'a',cube);
		rotatecal(3,'a',cube);
		rotatecal(5,'a',cube);
		rotatecal(3,'c',cube);
		rotatecal(5,'a',cube);
		rotatecal(5,'a',cube);
		rotatecal(3,'a',cube);


	}


	rotatecal(5,'a',cube);
}
		  cout<<endl;
}
void set_second_layer_cor(int (&cube)[3][3][6]){













//set right 
  while (    cube[1][1][1] !=cube[2][1][1] ||cube[1][1][1] !=cube[0][1][1]
		  || cube[1][1][2] !=cube[2][1][2] || cube[1][1][2] !=cube[0][1][2]
		  || cube[1][1][3] !=cube[1][2][3] || cube[1][1][3] !=cube[1][0][3]
		  || cube[1][1][4] !=cube[1][2][4] || cube[1][1][4] !=cube[1][0][4]
		){

			
			
			
	//for 3rd side
	if( (cube[1][2][3]==cube[1][1][1] || cube[1][2][3]==cube[1][1][2] || cube[1][2][3]==cube[1][1][3]  || cube[1][2][3]==cube[1][1][4] )
		&& (cube[0][1][2]==cube[1][1][1] || cube[0][1][2]==cube[1][1][2] || cube[0][1][2]==cube[1][1][3]  || cube[0][1][2]==cube[1][1][4])
		&&cube[1][2][3]!=cube[1][1][3]
		&&cube[0][1][2]!=cube[1][1][2]
		){

//right shift
									   		  rotatecal(5,'a',cube);
									   
									   rotatecal(2,'c',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(2,'a',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(3,'a',cube);
									  
									   rotatecal(5,'a',cube);

									   rotatecal(3,'c',cube);
	}
   //for 1rd side
	if( (cube[0][1][1]==cube[1][1][1] || cube[0][1][1]==cube[1][1][2] || cube[0][1][1]==cube[1][1][3]  || cube[0][1][1]==cube[1][1][4] )
		&& (cube[1][0][3]==cube[1][1][1] || cube[1][0][3]==cube[1][1][2] || cube[1][0][3]==cube[1][1][3]  || cube[1][0][3]==cube[1][1][4])
		&&cube[0][1][1]!=cube[1][1][1]
		&&cube[1][0][3]!=cube[1][1][3]
		){
			  rotatecal(5,'a',cube);
									   
									   rotatecal(3,'c',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(3,'a',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(1,'a',cube);
									  
									   rotatecal(5,'a',cube);

									   rotatecal(1,'c',cube);


	}
//for 2
     if( (cube[2][1][2]==cube[1][1][1] || cube[2][1][2]==cube[1][1][2] || cube[2][1][2]==cube[1][1][3]  || cube[2][1][2]==cube[1][1][4] )
		&& (cube[1][2][4]==cube[1][1][1] || cube[1][2][4]==cube[1][1][2] || cube[1][2][4]==cube[1][1][3]  || cube[1][2][4]==cube[1][1][4])
		&&cube[2][1][2]!=cube[1][1][2]
		&&cube[1][2][4]!=cube[1][1][4]
		){
			                           rotatecal(5,'a',cube);
									   
									   rotatecal(4,'c',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(4,'a',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(2,'a',cube);
									  
									   rotatecal(5,'a',cube);

									   rotatecal(2,'c',cube);

	}
//for 4
     if( (cube[1][0][4]==cube[1][1][1] || cube[1][0][4]==cube[1][1][2] || cube[1][0][4]==cube[1][1][3]  || cube[1][0][4]==cube[1][1][4] )
		&& (cube[2][1][1]==cube[1][1][1] || cube[2][1][1]==cube[1][1][2] || cube[2][1][1]==cube[1][1][3]  || cube[2][1][1]==cube[1][1][4])
		&&cube[1][0][4]!=cube[1][1][4]
		&&cube[2][1][1]!=cube[1][1][1]
		){

 //right shift
									   rotatecal(5,'a',cube);
									   
									   rotatecal(1,'c',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(1,'a',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(4,'a',cube);
									  
									   rotatecal(5,'a',cube);

									   rotatecal(4,'c',cube);
	}






	     
					   if(cube[1][1][1] ==cube[1][0][1]){   
								   if(cube[1][2][5]==cube[1][1][3]){
									   //right shift 

									   rotatecal(5,'a',cube);
									   
									   rotatecal(3,'c',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(3,'a',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(1,'a',cube);
									  
									   rotatecal(5,'a',cube);

									   rotatecal(1,'c',cube);


								   }
								   else if ( cube[1][2][5]==cube[1][1][4] )
								   {
									   //left shit
									    rotatecal(5,'c',cube);
									   
									   rotatecal(4,'a',cube);
									   
									   rotatecal(5,'a',cube);
									   
									   rotatecal(4,'c',cube);
									   
									   rotatecal(5,'a',cube);
									   
									   rotatecal(1,'c',cube);
									  
									   rotatecal(5,'c',cube);

									   rotatecal(1,'a',cube);


								   }
					   }

					     if(cube[1][1][2] ==cube[1][2][2]){   
								   if(cube[1][0][5]==cube[1][1][4]){
									   //right shift
									   rotatecal(5,'a',cube);
									   
									   rotatecal(4,'c',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(4,'a',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(2,'a',cube);
									  
									   rotatecal(5,'a',cube);

									   rotatecal(2,'c',cube);

								   }else if ( cube[1][0][5]==cube[1][1][3] ){

									   //left shit
									    rotatecal(5,'c',cube);
									   
									   rotatecal(3,'a',cube);
									   
									   rotatecal(5,'a',cube);
									   
									   rotatecal(3,'c',cube);
									   
									   rotatecal(5,'a',cube);
									   
									   rotatecal(2,'c',cube);
									  
									   rotatecal(5,'c',cube);

									   rotatecal(2,'a',cube);

								   }
					   }
					
				      if(cube[1][1][3] ==cube[0][1][3]){   
								   if(cube[0][1][5]==cube[1][1][2]){
									   //right shift
									   		   rotatecal(5,'a',cube);
									   
									   rotatecal(2,'c',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(2,'a',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(3,'a',cube);
									  
									   rotatecal(5,'a',cube);

									   rotatecal(3,'c',cube);

								   }else if ( cube[0][1][5]==cube[1][1][1] ){

									   //left shit
									    rotatecal(5,'c',cube);
									   
									   rotatecal(1,'a',cube);
									   
									   rotatecal(5,'a',cube);
									   
									   rotatecal(1,'c',cube);
									   
									   rotatecal(5,'a',cube);
									   
									   rotatecal(3,'c',cube);
									  
									   rotatecal(5,'c',cube);

									   rotatecal(3,'a',cube);

								   }
					   }
					  if(cube[1][1][4] ==cube[2][1][4]){   
								   if(cube[2][1][5]==cube[1][1][1]){
									   //right shift
									   rotatecal(5,'a',cube);
									   
									   rotatecal(1,'c',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(1,'a',cube);
									   
									   rotatecal(5,'c',cube);
									   
									   rotatecal(4,'a',cube);
									  
									   rotatecal(5,'a',cube);

									   rotatecal(4,'c',cube);
								   }else if ( cube[2][1][5]==cube[1][1][2] ){

									   //left shit
									   rotatecal(5,'c',cube);
									   
									   rotatecal(2,'a',cube);
									   
									   rotatecal(5,'a',cube);
									   
									   rotatecal(2,'c',cube);
									   
									   rotatecal(5,'a',cube);
									   
									   rotatecal(4,'c',cube);
									  
									   rotatecal(5,'c',cube);

									   rotatecal(4,'a',cube);

								   }
					   }
					

	 


					  rotatecal(5,'c',cube);










/*

	   if(cube[1][1][1] !=cube[0][1][1]) {
		        int x=0;				
		         while(x<3){
					   if(cube[1][1][1] ==cube[1][0][1]){   
						   if(cube[1][2][5]==cube[1][1][3]){
							   //right shift

						   }else if ( cube[1][2][5]==cube[1][1][4] ){

							   //left shit

						   }
					   }else{
				    rotatecal(5,'c',cube);  //there is extra step
					   }
					   x++;
				 }

	   }
	   if(cube[1][1][2] !=cube[1][2][2]){
		     int x=0;				
		         while(x<3){
					   if(cube[1][1][1] ==cube[1][2][1]){   
						   if(cube[1][0][5]==cube[1][2][3]){

						   }else if (cube[1][0][5]==cube[1][0][4]){

						   }
					   }else{
				    rotatecal(5,'c',cube);
					   x++;
					   }
				 }


	   }
	   if(cube[1][1][3] !=cube[1][2][3]){
		     int x=0;				
		         while(x<3){
					   if(cube[1][1][1] ==cube[1][2][1]){   
						   if(cube[1][0][5]==cube[1][2][3]){

						   }else if (cube[1][0][5]==cube[1][0][4]){

						   }
					   }
				    rotatecal(5,'c',cube);
					   x++;
				 }


	   }
	   if(cube[1][1][4] !=cube[1][2][4]){

		     int x=0;				
		         while(x<3){
					   if(cube[1][1][1] ==cube[1][2][1]){   
						   if(cube[1][0][5]==cube[1][2][3]){

						   }else if (cube[1][0][5]==cube[1][0][4]){

						   }
					   }
				    rotatecal(5,'c',cube);
					   x++;
				 }

	   }




	   */

	}
	cout<<endl;
}
void set_first_layer_mid(int (&cube)[3][3][6]){
	int x=0;
	while(cube[1][2][1] != cube[2][2][1] || cube[1][0][2] != cube[2][2][2] || cube[2][1][3] != cube[2][2][3] || cube[0][1][4] != cube[2][2][4]  ){
		if(x>3){
			s=s-4;
			break; 
		}
		rotatecal(0,'c',cube);
		x++;
		step(0,'c',s);
				   s++;
	}
	if(x<3){
		cout<<"Top layer mid is set ";
		return ;

	}else if(x>3){


            while(cube[1][2][1] != cube[1][1][1] || cube[1][0][2] != cube[1][1][2] || cube[2][1][3] != cube[1][1][3] || cube[0][1][4] != cube[1][1][4]  ){
			

				       x=0;
					   while(cube[0][1][4] != cube[1][1][4]){
						   if(x>3){
							s=s-4;   
							   break;
						   }
						   rotatecal(0,'c',cube);
						   x++;
						   step(0,'c',s);
				   s++;
					   }
					   if(cube[1][0][2] != cube[1][1][2]){
						    if(cube[1][0][2] == cube[1][1][1] || cube[1][2][1]== cube[1][1][2] ){
							   //parrallel change




							 //3a 3a 4c 4c 0c 0c 3c 3c 4c 4c

								rotatecal(3,'a',cube);
								step(3,'a',s);
								rotatecal(3,'a',cube);
								step(3,'a',s);
								rotatecal(4,'c',cube);
								step(4,'c',s);
								rotatecal(4,'c',cube);
								step(4,'c',s);
								rotatecal(0,'c',cube);
								step(0,'c',s);
								rotatecal(0,'c',cube);
								step(0,'c',s);
								rotatecal(3,'c',cube);
								step(3,'c',s);
								rotatecal(3,'c',cube);
								step(3,'c',s);
								rotatecal(4,'c',cube);
								step(4,'c',s);
								rotatecal(4,'c',cube);
								step(4,'c',s);

								if(cube[1][2][1] == cube[1][1][3]  || cube[2][1][3]==cube[1][2][1] ){ 
							
								rotatecal(3,'a',cube);
								step(3,'a',s);
								rotatecal(4,'c',cube);
								step(3,'a',s);
								rotatecal(1,'a',cube);
								step(3,'a',s);
								rotatecal(3,'c',cube);
								step(3,'a',s);
								rotatecal(4,'a',cube);
								step(3,'a',s);
								rotatecal(5,'c',cube);
								step(3,'a',s);
								rotatecal(2,'a',cube);
								step(3,'a',s);
								rotatecal(1,'c',cube);
								step(3,'a',s);
								rotatecal(3,'c',cube);
								step(3,'a',s);
								rotatecal(2,'c',cube);
								step(3,'a',s);
								rotatecal(1,'a',cube);
								step(3,'a',s);
								rotatecal(5,'c',cube);
								step(3,'a',s);
								rotatecal(3,'a',cube);
								step(3,'a',s);
								rotatecal(4,'c',cube);
								step(3,'a',s);
								rotatecal(1,'c',cube);
								step(3,'a',s);
								rotatecal(3,'c',cube);
								step(3,'a',s);
								rotatecal(4,'a',cube);
								 
								}
						   }
							else  if(cube[1][0][2] == cube[1][1][3] ||cube[2][1][3] ==cube[1][1][2]){
							  //cornner chnage 

								//need to make algo 
							
								//3c4a2c3a4c5c2a1c3c2c1a5c3c4a2a3a4c
								rotatecal(3,'c',cube);
								rotatecal(4,'a',cube);
								rotatecal(2,'c',cube);
								rotatecal(3,'a',cube);
								rotatecal(4,'c',cube);
								rotatecal(5,'c',cube);
								rotatecal(2,'a',cube);
								rotatecal(1,'c',cube);
								rotatecal(3,'c',cube);
								rotatecal(2,'c',cube);
								rotatecal(1,'a',cube);
								rotatecal(5,'c',cube);
								rotatecal(3,'c',cube);
								rotatecal(4,'a',cube);
								rotatecal(2,'a',cube);
								rotatecal(3,'a',cube);
								rotatecal(4,'c',cube);
								

								
								if(cube[1][2][1] == cube[1][1][3]  || cube[2][1][3]==cube[1][2][1] ){ 
							
								rotatecal(3,'a',cube);
								rotatecal(4,'c',cube);
								rotatecal(1,'a',cube);
								rotatecal(3,'c',cube);
								rotatecal(4,'a',cube);
								rotatecal(5,'c',cube);
								rotatecal(2,'a',cube);
								rotatecal(1,'c',cube);
								rotatecal(3,'c',cube);
								rotatecal(2,'c',cube);
								rotatecal(1,'a',cube);
								rotatecal(5,'c',cube);
								rotatecal(3,'a',cube);
								rotatecal(4,'c',cube);
								rotatecal(1,'c',cube);
								rotatecal(3,'c',cube);
								rotatecal(4,'a',cube);
								 
								}

						   }
						  
					   }else if (cube[1][2][1] == cube[1][1][3]  || cube[2][1][3]==cube[1][2][1] ){
						       rotatecal(3,'a',cube);
								rotatecal(4,'c',cube);
								rotatecal(1,'a',cube);
								rotatecal(3,'c',cube);
								rotatecal(4,'a',cube);
								rotatecal(5,'c',cube);
								rotatecal(2,'a',cube);
								rotatecal(1,'c',cube);
								rotatecal(3,'c',cube);
								rotatecal(2,'c',cube);
								rotatecal(1,'a',cube);
								rotatecal(5,'c',cube);
								rotatecal(3,'a',cube);
								rotatecal(4,'c',cube);
								rotatecal(1,'c',cube);
								rotatecal(3,'c',cube);
								rotatecal(4,'a',cube);


					   }


				
			}

	}


	cout<<endl;
	}
void set_first_layer_cor(int (&cube)[3][3][6]){





	while(       (cube[0][2][1] != cube[1][1][1] && cube[2][2][1] != cube[1][1][1])   
	        ||   (cube[0][0][2] != cube[1][1][2] && cube[2][0][2] != cube[1][1][2])
	        ||   (cube[2][0][3] != cube[1][1][3] && cube[2][2][3] != cube[1][1][3])
			||   (cube[0][0][4] != cube[1][1][4] && cube[0][2][3] != cube[1][1][4])
	       ){
			   cout<<"..........";
	

			   if((cube[2][0][3]==cube[1][1][4] && cube[0][2][1]==cube[1][1][2]) || cube[2][0][3]==cube[1][1][4] ){

				   rotatecal(1,'a',cube);
				   rotatecal(2,'a',cube);
                   rotatecal(5,'c',cube);
				   rotatecal(5,'c',cube);
                   rotatecal(1,'c',cube);
				   rotatecal(2,'c',cube);


			   }
			   if(cube[2][2][3]==cube[1][1][4] &&  cube[1][1][1]==cube[0][0][2]){

				   rotatecal(1,'c',cube);
				   rotatecal(2,'c',cube);
                   rotatecal(5,'c',cube);
				   rotatecal(5,'c',cube);
                   rotatecal(1,'a',cube);
				   rotatecal(2,'a',cube);
				   // 5a  3c  5c  3a  5c  1a  5a  1c  5a  2c  5c  2a  5c  3a  5a  3c  5c  5c  2a  5a  2c  5a  4c  5c  4a  5c  5a  1c  5c  1a  5c  4a  5a  4c  

			   }
			
			   
			   if(cube[0][0][4]==cube[1][1][1] ||cube[1][1][1]==cube[2][0][3]){

                 
                   rotatecal(3,'c',cube);
				   rotatecal(5,'a',cube);
                   rotatecal(3,'a',cube);

				   rotatecal(4,'a',cube);
                   rotatecal(5,'c',cube);
				   rotatecal(4,'c',cube);

				   rotatecal(3,'c',cube);
				   rotatecal(5,'a',cube);
                   rotatecal(3,'a',cube);
				  // 1a  2a  5c  5c  1c  2c  3c  5a  3a  4a  5c  4c  3c  5a  3a 


			   }
			   if(cube[0][0][2]==cube[1][1][3] ||cube[1][1][3]==cube[0][2][1]){

                   rotatecal(2,'c',cube);
				   rotatecal(5,'a',cube);
                   rotatecal(2,'a',cube);

				   rotatecal(1,'a',cube);
                   rotatecal(5,'c',cube);
				   rotatecal(1,'c',cube);

				   rotatecal(2,'c',cube);
				   rotatecal(5,'a',cube);
                   rotatecal(2,'a',cube);



			   }
			   if(cube[2][2][3]==cube[1][1][2] ||cube[1][1][2]==cube[0][2][4]){

                   rotatecal(4,'c',cube);
				   rotatecal(5,'a',cube);
                   rotatecal(4,'a',cube);

				   rotatecal(3,'a',cube);
                   rotatecal(5,'c',cube);
				   rotatecal(3,'c',cube);

				   rotatecal(4,'c',cube);
				   rotatecal(5,'a',cube);
                   rotatecal(4,'a',cube);



			   }
			   if(cube[2][0][2]==cube[1][1][4] ||cube[1][1][4]==cube[2][2][1]){

                   rotatecal(1,'c',cube);
				   rotatecal(5,'a',cube);
                   rotatecal(1,'a',cube);

				   rotatecal(2,'a',cube);
                   rotatecal(5,'c',cube);
				   rotatecal(2,'c',cube);

				   rotatecal(1,'c',cube);
				   rotatecal(5,'a',cube);
                   rotatecal(1,'a',cube);



			   }



	}


	cout<<endl;
}
void set_mid(int (&cube)[3][3][6]){
	
	
	int rot;
	while(cube[0][1][0]!=cube[1][1][0]  || cube[1][0][0]!=cube[1][1][0]  || cube[2][1][0]!=cube[1][1][0]  || cube[1][2][0]!=cube[1][1][0]  ){

		
	
		
		while(cube[2][1][2]==cube[1][1][0] 
			||cube[2][1][1]==cube[1][1][0]
			||cube[1][2][3]==cube[1][1][0]
			||cube[1][2][4]==cube[1][1][0]
			||cube[1][0][3]==cube[1][1][0]
			||cube[1][0][4]==cube[1][1][0]
			||cube[0][1][2]==cube[1][1][0]
			||cube[0][1][1]==cube[1][1][0]
			){



				
			
	
	   if(cube[2][1][0] !=cube[1][1][0]){
			   if(cube[2][1][2]==cube[1][1][0]){

				   rotatecal(4,'a',cube);
				   step(4,'a',s);
				   s++;
	//	   printCube(cube);
			   }
			   else if(cube[2][1][1]==cube[1][1][0]){

				   rotatecal(4,'c',cube);
		//		   printCube(cube);
			   
			   step(4,'c',s);
				   s++;
			   }
	   }
	 
	   if(cube[1][2][0] !=cube[1][1][0]){
			   if(cube[1][2][3]==cube[1][1][0]){

				   rotatecal(2,'a',cube);
	//			   printCube(cube);

			   step(2,'a',s);
				   s++;
			   }
			   else if(cube[1][2][4]==cube[1][1][0]){

				   rotatecal(2,'c',cube);
	//			   printCube(cube);
			   
			   step(2,'c',s);
				   s++;
			   }
	   }

	    if(cube[1][0][0] !=cube[1][1][0]){
			   if(cube[1][0][3]==cube[1][1][0]){

				   rotatecal(1,'c',cube);
		//		   printCube(cube);

                   step(1,'c',s);
				   s++;

			   }
			   else if(cube[1][0][4]==cube[1][1][0]){

				   rotatecal(1,'a',cube);
	//			   printCube(cube);
			   step(1,'a',s);
				   s++;
			   }
	   }
	
		   if(cube[0][1][0] !=cube[1][1][0]){
			   if(cube[0][1][2]==cube[1][1][0]){

			   rotatecal(3,'c',cube);
	//				   printCube(cube);

			   step(3,'c',s);
				   s++;
			   }
			   else if(cube[0][1][1]==cube[1][1][0]){

				   rotatecal(3,'a',cube);
//			   printCube(cube);
			   step(3,'a',s);
				   s++;
			   }
	   }
	 
		   rotatecal(0,'c',cube);
//		   printCube(cube);
	step(0,'c',s);
				   s++;
		}

	rot=0;
	while(cube[1][2][0] == cube[1][1][0]){
		if(rot>3){
		  cout<<"mid edage are compeletd"<<endl;
			s=s-4;
		  return;
			
		}
		rotatecal(0,'c',cube);
//		printCube(cube);
		rot++;
		step(0,'c',s);
				   s++;
	}

if(cube[1][2][0] != cube[1][1][0]){

		int rot=0;
	    while(cube[0][1][5] != cube[1][1][0]){
		if(rot>3){
		    s=s-4;
			break;

		}
		rotatecal(5,'c',cube);
//		printCube(cube);
		rot++;
		step(5,'c',s);
				   s++;
	}
	
	
	}

	
	while(cube[1][0][5]==cube[1][1][0] || cube[0][1][5]==cube[1][1][0] ||  cube[2][1][5]==cube[1][1][0] || cube[1][2][5]==cube[1][1][0]){
		

		//cout<<cube[1][0][5];
    if(cube[1][2][0] != cube[1][1][0] && cube[1][0][5] == cube[1][1][0]){

         rotatecal(2,'c',cube);
//		 printCube(cube);
		 step(2,'c',s);
				   s++;
		 rotatecal(2,'c',cube);
//		 printCube(cube);
		 step(2,'c',s);
				   s++;
	}else if(cube[1][2][0] == cube[1][1][0]){
		
		rot=0;
	    while(cube[1][2][0] == cube[1][1][0]){
		if(rot>3){
			s=s-4;
			break;}
		rotatecal(0,'c',cube);
//		printCube(cube);
		rot++;
		step(0,'c',s);
				   s++;
		}
		


	}else if(cube[1][0][5] != cube[1][1][0]){

		
		int rot=0;
	    while(cube[1][0][5] != cube[1][1][0]){
		if(rot>3){
			s=s-4;
			break;}
		rotatecal(5,'c',cube);
//	printCube(cube);
		rot++;
		step(5,'c',s);
				   s++;
		}
	





	}else if(cube[1][2][0] == cube[1][1][0] && cube[1][0][5] != cube[1][1][0]){

		rot=0;
	    while(cube[1][2][0] == cube[1][1][0]){
		if(rot>3){
			s=s-4;
			break;
		}
		rotatecal(0,'c',cube);
//	printCube(cube);
		rot++;
		step(0,'c',s);
				   s++;
		}


	    rot=0;
	    while(cube[1][0][5] != cube[1][1][0]){
		if(rot>3){
			s=s-4;
			break;}
		rotatecal(5,'c',cube);
//		printCube(cube);
		rot++;
		step(5,'c',s);
				   s++;

		}
	

	}
	}
	
	 rot=0;
	while(cube[1][0][2] != cube[1][1][0]){
		
		if(rot>3){
			
			s=s-4;
			break;}
	
		rotatecal(0,'c',cube);
		//printCube(cube);
		rot++;
	step(0,'c',s);
				   s++;
	
	}
	if(cube[1][0][2] == cube[1][1][0]){
		rotatecal(2,'c',cube);
	//printCube(cube);

	step(2,'c',s);
				   s++;
	}


	 rot=0;
	while(cube[1][2][2] != cube[1][1][0]){
		
		if(rot>3){
			s=
				s-4;
			break;
		}
	
		rotatecal(5,'c',cube);
//		printCube(cube);
		rot++;
	step(5,'c',s);
				   s++;
	
	}
	if(cube[1][2][2] ==cube[1][1][0]  && cube[1][2][0]){

		rotatecal(2,'c',cube);
//		printCube(cube);

	step(2,'c',s);
				   s++;
	}





	}

	cout<<endl;

}
void set_cor(int (&cube)[3][3][6]){
	s=0;
	while(cube[0][0][0]!=cube[1][1][0] || cube[0][2][0]!=cube[1][1][0]  || cube[2][0][0]!=cube[1][1][0]  || cube[2][2][0]!=cube[1][1][0]  ){

	int rot=0;
	while(cube[2][2][0] == cube[1][1][0]){
		if(rot>3){
		  cout<<"Cornner edage are compeletd"<<endl;
			s=s-4;
		  return;
		}
		rotatecal(0,'c',cube);
		rot++;
		step(0,'c',s);
				   s++;
	}
   

	rot=0;
	   while(cube[2][2][2]!=cube[1][1][0]){
		   
		   if(rot>3){
			s=s-4;   
			   break;
		   }
		   rotatecal(5,'c',cube);
		   rot++;
		   step(5,'c',s);
				   s++;

	   }
	   if(cube[2][2][2]==cube[1][1][0] && cube[2][2][0] !=cube[1][1][0]){
	   rotatecal(5,'a',cube);
	   step(5,'c',s);
				   s++;
	   rotatecal(4,'c',cube);
	   step(4,'c',s);
				   s++;
	   rotatecal(5,'c',cube);
	   step(5,'c',s);
				   s++;
	   rotatecal(4,'a',cube);
	   step(4,'c',s);
				   s++;
	   }
	
	   /////////printCube(cube);
	   if(rot>3){
		   rot=0;
		    while(cube[0][2][2]!=cube[1][1][0]){
		   
		   if(rot>3){
			 s=s-4;
			   break;
		   }
		   rotatecal(5,'c',cube);
		   step(5,'c',s);
				   s++;
		   rot++;

	   }
	   //////////////printCube(cube);


	   }
	    if(cube[0][2][2]==cube[1][1][0] && cube[2][2][0]!=cube[1][1][0]){
	   rotatecal(5,'c',cube);
	   rotatecal(4,'c',cube);
	   rotatecal(5,'a',cube);
	   rotatecal(4,'a',cube);

	               step(5,'c',s);
				   s++;
				   step(4,'c',s);
				   s++;
				   step(5,'a',s);
				   s++;
				   step(4,'a',s);
				   s++;

	   }
      ///////////////////printCube(cube);
	  if(rot>3){

		   rot=0;
		    while(cube[2][0][5]!=cube[1][1][0]){
		   
		   if(rot>3){
			s=s-4;   
			   break;
		   }
		   rotatecal(5,'c',cube);
		   rot++;
		   step(5,'c',s);
				   s++;
	   }
	   ////////////////printCube(cube);
	     if(cube[2][0][5]==cube[1][1][0] && cube[2][2][0]!=cube[1][1][0]){

       rotatecal(4,'c',cube);
       rotatecal(5,'a',cube);
	   rotatecal(5,'a',cube);
	   rotatecal(4,'a',cube);
	  

	    rotatecal(5,'c',cube);
	   rotatecal(4,'c',cube);
	   rotatecal(5,'a',cube);
	   rotatecal(4,'a',cube);
	   
		           step(4,'c',s);
				   s++;
				   step(5,'a',s);
				   s++;
				   step(5,'a',s);
				   s++;
				   step(4,'a',s);
				   s++;
				   step(5,'c',s);
				   step(4,'c',s);
				   s++;
				   step(5,'a',s);
				   s++;
				   step(4,'a',s);
				   s++;
				   s++;
		 
		 
		 }
	/////////////////////printCube(cube);


	

		  if(rot>3){

		   rot=0;
		    while(cube[2][0][2]!=cube[1][1][0]){
		   
		   if(rot>3){
			 s=s-4;
			   
			   break;
		   }
		   rotatecal(0,'c',cube);
		   rot++;
		   step(0,'c',s);
				   s++;
			}
	   }
	   ///////////////////printCube(cube);
	     if(cube[2][0][2]==cube[1][1][0]   ){

       rotatecal(4,'c',cube);
       rotatecal(5,'c',cube);
	   rotatecal(4,'a',cube);

	               step(4,'c',s);
				   s++;
				   step(5,'c',s);
				   s++;
				   step(4,'a',s);
				   s++;


	   }
	//////////////////////////printCube(cube);

	



	
	
		  if(rot>3){

		   rot=0;
		    while(cube[0][0][2]!=cube[1][1][0]){
		   
		   if(rot>3){
			   break;
		       s=s-4;
		   }
		   rotatecal(0,'c',cube);
		   rot++;
		   step(0,'c',s);
				   s++;
	   }
			  }
	   //////////////////////////printCube(cube);
	     if(cube[0][0][2]==cube[1][1][0] ){

       rotatecal(3,'a',cube);
       rotatecal(5,'a',cube);
	   rotatecal(3,'c',cube);
             	   step(3,'a',s);
				   s++;
				   step(5,'a',s);
				   s++;
				   step(3,'c',s);
				   s++;
		 
		 }
	///////////////////////////////printCube(cube);


		





	  }
	}
	cout<<endl;
}
void step(int phase,char rot,int (&cube)[3][3][6]){
if(phase ==-1){
		set_mid(cube);
		

	}
	else if(phase ==-2){
		set_cor(cube);
	
	}
	else if(phase == -3){
	set_first_layer_mid(cube);
	
	}
	else if(phase == -4){
	set_first_layer_cor(cube);
	
	}
	else if(phase == -5){
		set_second_layer_cor(cube);
	}
	else if(phase ==-6){
		 set_top_phase_mid(cube);
	}else if(phase==-7){
		compelet_mid(cube);
				cout<<endl;
	}
	else if(phase == -8){
		compelet_cor(cube);
		
	}
	else if(phase == -9){
         final_cube(cube);
	}
	else 
		rotatecal(phase ,rot, cube);
}

