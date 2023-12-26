#pragma once
#include "LogIn.h"
#include "SignUp.h"

namespace sportmanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ buttonLogIn;
	private: System::Windows::Forms::Button^ buttonRegistration;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonLogIn = (gcnew System::Windows::Forms::Button());
			this->buttonRegistration = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonLogIn
			// 
			this->buttonLogIn->CausesValidation = false;
			this->buttonLogIn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonLogIn->Location = System::Drawing::Point(187, 95);
			this->buttonLogIn->Name = L"buttonLogIn";
			this->buttonLogIn->Size = System::Drawing::Size(130, 47);
			this->buttonLogIn->TabIndex = 1;
			this->buttonLogIn->Text = L"¬х≥д в акаунт";
			this->buttonLogIn->UseVisualStyleBackColor = true;
			this->buttonLogIn->Click += gcnew System::EventHandler(this, &MyForm::buttonLogIn_Click);
			// 
			// buttonRegistration
			// 
			this->buttonRegistration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonRegistration->Location = System::Drawing::Point(187, 175);
			this->buttonRegistration->Name = L"buttonRegistration";
			this->buttonRegistration->Size = System::Drawing::Size(130, 47);
			this->buttonRegistration->TabIndex = 2;
			this->buttonRegistration->Text = L"–еЇстрац≥€";
			this->buttonRegistration->UseVisualStyleBackColor = true;
			this->buttonRegistration->Click += gcnew System::EventHandler(this, &MyForm::buttonRegistration_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(511, 315);
			this->Controls->Add(this->buttonRegistration);
			this->Controls->Add(this->buttonLogIn);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"¬х≥д";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void buttonLogIn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		LogIn^ logForm = gcnew LogIn();
		logForm->ShowDialog();
		this->Close();
	}

	private: System::Void buttonRegistration_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		SignUp^ regForm = gcnew SignUp();
		regForm->ShowDialog();
		this->Close();
	}
	};
}
