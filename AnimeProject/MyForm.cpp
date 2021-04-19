#include "MyForm.h"
#include "Header.h"




using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]



void main(array<String^>^ args) {

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	AnimeProject::MyForm frm;
	Application::Run(% frm);



}





