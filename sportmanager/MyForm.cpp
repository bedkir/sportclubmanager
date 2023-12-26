#include "MyForm.h"
#include "Group.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(/*array<String^>^ args*/)
{
	Group::setAmountOfGroups();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	sportmanager::MyForm form;
	Application::Run(% form);
}
