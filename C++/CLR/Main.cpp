
#include "MyForm.h"

using namespace System::Windows;
using namespace System::Windows::Controls;
using namespace System::Windows::Media;

[System::STAThreadAttribute]

int main(array<System::String^>^args)
{
	//Application^ ap = gcnew Application();
	TestCLR::MyForm^ w = gcnew TestCLR::MyForm();
	//DataGrid ^dg = gcnew DataGrid();
	//dg->Background = Brushes::Yellow;
	w->ShowDialog();
	//ap->Run();
	return 0;
}