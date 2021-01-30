#include "MyForm.h"

using namespace TestCLR;
using namespace System;

void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	MyForm::textBox1->Text = "Hello World";
};
