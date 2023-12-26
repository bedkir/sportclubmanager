#pragma once

#include "Coach.h"
#include "ClubMember.h"

#include <string>
#include <msclr/marshal.h>
#include <msclr\marshal_cppstd.h>

namespace sportmanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для LogIn
	/// </summary>
	public ref class LogIn : public System::Windows::Forms::Form
	{
	public:
		LogIn()
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~LogIn()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxLogin;
	private: System::Windows::Forms::TextBox^ textBoxPassword;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButtonCoach;
	private: System::Windows::Forms::RadioButton^ radioButtonMember;
	private: System::Windows::Forms::Button^ buttonLogIn;
	private: System::Windows::Forms::Label^ labelWarning;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonMember = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonCoach = (gcnew System::Windows::Forms::RadioButton());
			this->buttonLogIn = (gcnew System::Windows::Forms::Button());
			this->labelWarning = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(93, 103);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Логін:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(77, 167);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Пароль:";
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxLogin->Location = System::Drawing::Point(148, 100);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(100, 24);
			this->textBoxLogin->TabIndex = 2;
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxPassword->Location = System::Drawing::Point(148, 164);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->PasswordChar = '*';
			this->textBoxPassword->Size = System::Drawing::Size(100, 24);
			this->textBoxPassword->TabIndex = 3;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButtonMember);
			this->groupBox1->Controls->Add(this->radioButtonCoach);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(289, 100);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(146, 100);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			// 
			// radioButtonMember
			// 
			this->radioButtonMember->AutoSize = true;
			this->radioButtonMember->Checked = true;
			this->radioButtonMember->Location = System::Drawing::Point(6, 23);
			this->radioButtonMember->Name = L"radioButtonMember";
			this->radioButtonMember->Size = System::Drawing::Size(68, 22);
			this->radioButtonMember->TabIndex = 1;
			this->radioButtonMember->TabStop = true;
			this->radioButtonMember->Text = L"Учень";
			this->radioButtonMember->UseVisualStyleBackColor = true;
			// 
			// radioButtonCoach
			// 
			this->radioButtonCoach->AutoSize = true;
			this->radioButtonCoach->Location = System::Drawing::Point(6, 63);
			this->radioButtonCoach->Name = L"radioButtonCoach";
			this->radioButtonCoach->Size = System::Drawing::Size(75, 22);
			this->radioButtonCoach->TabIndex = 0;
			this->radioButtonCoach->Text = L"Тренер";
			this->radioButtonCoach->UseVisualStyleBackColor = true;
			// 
			// buttonLogIn
			// 
			this->buttonLogIn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonLogIn->Location = System::Drawing::Point(183, 233);
			this->buttonLogIn->Name = L"buttonLogIn";
			this->buttonLogIn->Size = System::Drawing::Size(127, 37);
			this->buttonLogIn->TabIndex = 5;
			this->buttonLogIn->Text = L"Увійти";
			this->buttonLogIn->UseVisualStyleBackColor = true;
			this->buttonLogIn->Click += gcnew System::EventHandler(this, &LogIn::buttonLogIn_Click);
			// 
			// labelWarning
			// 
			this->labelWarning->AutoSize = true;
			this->labelWarning->ForeColor = System::Drawing::Color::Red;
			this->labelWarning->Location = System::Drawing::Point(164, 273);
			this->labelWarning->Name = L"labelWarning";
			this->labelWarning->Size = System::Drawing::Size(174, 13);
			this->labelWarning->TabIndex = 6;
			this->labelWarning->Text = L"Сталася помилка, перевірте дані";
			this->labelWarning->Visible = false;
			// 
			// LogIn
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(469, 335);
			this->Controls->Add(this->labelWarning);
			this->Controls->Add(this->buttonLogIn);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->textBoxLogin);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"LogIn";
			this->Text = L"LogIn";
			this->Load += gcnew System::EventHandler(this, &LogIn::LogIn_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LogIn_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void buttonLogIn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		string login = msclr::interop::marshal_as<std::string>(this->textBoxLogin->Text);
		string password = msclr::interop::marshal_as<std::string>(this->textBoxPassword->Text);
		bool result;

		if (this->radioButtonCoach->Checked)
			result = Coach::C.SignIn(login, password);
		else
			result = ClubMember::CM.SignIn(login, password);

		if (!result)
		{
			this->labelWarning->Visible = true;
		}
	}
};
}
