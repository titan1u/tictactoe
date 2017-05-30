#include <iostream>

#include <string>
/*
                  _..._                                       _..._                          .-'''-.                        
                 .-'_..._''.                                 .-'_..._''.                      '   _    \                      
         .--.  .' .'      '.\                              .' .'      '.\                   /   /` '.   \      __.....__      
         |__| / .'                                        / .'                             .   |     \  '  .-''         '.    
     .|  .--.. '                            .|           . '                            .| |   '      |  '/     .-''"'-.  `.  
   .' |_ |  || |                          .' |_     __   | |                          .' |_\    \     / //     /________\   \ 
 .'     ||  || |                        .'     | .:--.'. | |                        .'     |`.   ` ..' / |                  | 
'--.  .-'|  |. '                       '--.  .-'/ |   \ |. '                       '--.  .-'   '-...-'`  \    .-------------' 
   |  |  |  | \ '.          .             |  |  `" __ | | \ '.          .             |  |                \    '-.____...---. 
   |  |  |__|  '. `._____.-'/             |  |   .'.''| |  '. `._____.-'/             |  |                 `.             .'  
   |  '.'        `-.______ /              |  '.'/ /   | |_   `-.______ /              |  '.'                 `''-...... -'    
   |   /                  `               |   / \ \._,\ '/            `               |   /                                   
   `'-'                                   `'-'   `--'  `"                             `'-'                                    
*/
using namespace std;
enum winResults 
     { 
    computerWin = 0,  
    userWin = 1, 
    Tie = 2, 
    noWin = 3 
 }; 
void displayFunction (int,int*);
winResults winFunction (int*); 
void computerMove (int*);
void humanMove (int*);

/* function prototype */

int main()  
 { 
  winResults winCondition = noWin; 
  const int size = 9; 
  int arr[size]=  {-1,-1,-1,-1,-1,-1,-1,-1,-1 }; 
  int input = 0; 
  while (input == 0 ) { 
  cout << "Press 1 for O and 2 for X   \n"; 
  cin >> input; 
   
    if (input == 1 ) 
    cout << "Human = O  Computer = X \n"; 
    else if (input == 2 ) 
    cout << "Human = X  Computer = O \n"; 
    else  
    input = 0; 
 } /* and while loop*/ 
    displayFunction (input,arr); 
	arr[2]=10;
	displayFunction (input,arr);
    while (winCondition == noWin) { 
	humanMove (arr);
	displayFunction (input,arr);
	winCondition = winFunction (arr);  
	if (winCondition != noWin)
		break;
	computerMove (arr);
	displayFunction (input,arr);
	winCondition =  winFunction (arr);
	
     } /* end while loop */ 
	if (winCondition == Tie)
		 cout << "Tie! \n";
	else if (winCondition == userWin)
		cout << "You won! \n";
	else if (winCondition == computerWin)
		cout << "Computer won. Game over. \n";
		 
 }
void displayFunction (int Selection, int * array_element) {
       cout<<endl;
    cout<<endl;
    char temp1, temp2;
    int count=1;
    if (Selection == 1) {
    temp1 = 'O';
    temp2 = 'X';}
    else {
    temp1 = 'X';
    temp2 = 'O';    
    }
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (array_element[count+j-1] == -1) {
            cout<<"  "<<count+j<<"  |";}
            else if(array_element[count+j-1] == 10){
            cout<<"  "<<temp2<<"  |";}
            else{
            cout<<"  "<<temp1<<"  |";}
        }
        count = count +3;
        cout<<endl;
    }
    cout<<endl;
}
 void computerMove (int* arr)  { 
    cout << "Computer's move." << endl; 
    int x=0; 
    while (arr[x]!=-1) 
    x=rand()%9; 
    arr[x]=10; 
 } 
 
    void humanMove (int* arr)  { 
       cout << "Enter the number representing your move." << endl; 
       int x1 = 1; 
       int firstPass = 1; 
       while (firstPass || arr[x1-1]!=-1)  { 
           if (firstPass==0) 
           cout << "Invalid entry." << endl; 
            
           cin >> x1; 
           firstPass = 0; 
        } 
    arr[x1-1]=1; 
     
         
     } 
/*display function ready*/ 
winResults winFunction (int *arr)  { 
     
    if ((arr[0]==arr[1]) && (arr[1]==arr[2]) && (arr[1] != -1) && (arr[1] == 10)) 
    return computerWin; 
    else if ((arr[0]==arr[1]) && (arr[1]==arr[2]) && (arr[1] != -1) && (arr[1] == 1)) 
    return userWin; 
    else if ((arr[0]==arr[3]) && (arr[3]==arr[6]) && (arr[3] != -1) && (arr[3] == 10)) 
    return computerWin; 
    else if ((arr[0]==arr[3]) && (arr[3]==arr[6]) && (arr[3] != -1) && (arr[3] == 1)) 
    return userWin; 
    else if ((arr[1]==arr[4]) && (arr[4]==arr[7]) && (arr[4] != -1) && (arr[4] == 10)) 
    return computerWin; 
    else if ((arr[1]==arr[4]) && (arr[4]==arr[7]) && (arr[4] != -1) && (arr[4] == 1)) 
    return userWin; 
    else if ((arr[2]==arr[5]) && (arr[2]==arr[8]) && (arr[5] != -1) && (arr[5] == 10)) 
    return computerWin; 
    else if ((arr[2]==arr[5]) && (arr[2]==arr[8]) && (arr[5] != -1) && (arr[5] == 1)) 
    return userWin; 
    else if ((arr[3]==arr[4]) && (arr[4]==arr[5]) && (arr[4] != -1) && (arr[4] == 10)) 
    return computerWin; 
    else if ((arr[3]==arr[4]) && (arr[4]==arr[5]) && (arr[4] != -1) && (arr[4] == 1)) 
    return userWin; 
    else if ((arr[6]==arr[7]) && (arr[7]==arr[8]) && (arr[8] != -1) && (arr[8] == 10)) 
    return computerWin; 
    else if ((arr[6]==arr[7]) && (arr[7]==arr[8]) && (arr[8] != -1) && (arr[8] == 1)) 
    return userWin; 
    else if ((arr[0]==arr[4]) && (arr[0]==arr[8]) && (arr[0] != -1) && (arr[0] == 10)) 
    return computerWin; 
    else if ((arr[0]==arr[4]) && (arr[0]==arr[8]) && (arr[0] != -1) && (arr[0] == 1)) 
    return userWin; 
    else if ((arr[2]==arr[4]) && (arr[2]==arr[6]) && (arr[6] != -1) && (arr[6] == 10)) 
    return computerWin; 
    else if ((arr[2]==arr[4]) && (arr[2]==arr[6]) && (arr[6] != -1) && (arr[6] == 1)) 
    return userWin; 
    for(int x = 0; x< 9; x++)  { 
        if (arr[x] == -1)
        return noWin; 
     } 
    return Tie; 
 }