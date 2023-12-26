#pragma once

namespace sportmanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SignUp
	/// </summary>
	public ref class SignUp : public System::Windows::Forms::Form
	{
	public:
		SignUp(void)
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
		~SignUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBoxLogin;
	private: System::Windows::Forms::TextBox^ textBoxSecPassword;
	private: System::Windows::Forms::TextBox^ textBoxPassword;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::TextBox^ textBoxSurname;
	private: System::Windows::Forms::TextBox^ textBoxBirthYear;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButtonMember;

	private: System::Windows::Forms::RadioButton^ radioButtonCoach;
	private: System::Windows::Forms::Button^ buttonSignUp;




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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSecPassword = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSurname = (gcnew System::Windows::Forms::TextBox());
			this->textBoxBirthYear = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonCoach = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonMember = (gcnew System::Windows::Forms::RadioButton());
			this->buttonSignUp = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(138, 66);
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
			this->label2->Location = System::Drawing::Point(122, 118);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Пароль:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 176);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(175, 18);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Підтвердження паролю:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(154, 237);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 18);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Ім\'я";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(110, 286);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 18);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Прізвище:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(65, 335);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(122, 18);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Рік народження:";
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxLogin->Location = System::Drawing::Point(205, 67);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(100, 24);
			this->textBoxLogin->TabIndex = 6;
			// 
			// textBoxSecPassword
			// 
			this->textBoxSecPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxSecPassword->Location = System::Drawing::Point(205, 176);
			this->textBoxSecPassword->Name = L"textBoxSecPassword";
			this->textBoxSecPassword->Size = System::Drawing::Size(100, 24);
			this->textBoxSecPassword->TabIndex = 7;
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxPassword->Location = System::Drawing::Point(205, 118);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(100, 24);
			this->textBoxPassword->TabIndex = 8;
			// 
			// textBoxName
			// 
			this->textBoxName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxName->Location = System::Drawing::Point(205, 234);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(100, 24);
			this->textBoxName->TabIndex = 9;
			// 
			// textBoxSurname
			// 
			this->textBoxSurname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSurname->Location = System::Drawing::Point(205, 286);
			this->textBoxSurname->Name = L"textBoxSurname";
			this->textBoxSurname->Size = System::Drawing::Size(100, 24);
			this->textBoxSurname->TabIndex = 10;
			// 
			// textBoxBirthYear
			// 
			this->textBoxBirthYear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxBirthYear->Location = System::Drawing::Point(205, 332);
			this->textBoxBirthYear->Name = L"textBoxBirthYear";
			this->textBoxBirthYear->Size = System::Drawing::Size(100, 24);
			this->textBoxBirthYear->TabIndex = 11;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButtonCoach);
			this->groupBox1->Controls->Add(this->radioButtonMember);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(367, 118);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 100);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			// 
			// radioButtonCoach
			// 
			this->radioButtonCoach->AutoSize = true;
			this->radioButtonCoach->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->radioButtonCoach->Location = System::Drawing::Point(6, 59);
			this->radioButtonCoach->Name = L"radioButtonCoach";
			this->radioButtonCoach->Size = System::Drawing::Size(75, 22);
			this->radioButtonCoach->TabIndex = 1;
			this->radioButtonCoach->Text = L"Тренер";
			this->radioButtonCoach->UseVisualStyleBackColor = true;
			this->radioButtonCoach->CheckedChanged += gcnew System::EventHandler(this, &SignUp::radioButton2_CheckedChanged);
			// 
			// radioButtonMember
			// 
			this->radioButtonMember->AutoSize = true;
			this->radioButtonMember->Checked = true;
			this->radioButtonMember->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->radioButtonMember->Location = System::Drawing::Point(6, 23);
			this->radioButtonMember->Name = L"radioButtonMember";
			this->radioButtonMember->Size = System::Drawing::Size(68, 22);
			this->radioButtonMember->TabIndex = 0;
			this->radioButtonMember->TabStop = true;
			this->radioButtonMember->Text = L"Учень";
			this->radioButtonMember->UseVisualStyleBackColor = true;
			this->radioButtonMember->CheckedChanged += gcnew System::EventHandler(this, &SignUp::radioButton1_CheckedChanged);
			// 
			// buttonSignUp
			// 
			this->buttonSignUp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSignUp->Location = System::Drawing::Point(391, 269);
			this->buttonSignUp->Name = L"buttonSignUp";
			this->buttonSignUp->Size = System::Drawing::Size(143, 53);
			this->buttonSignUp->TabIndex = 13;
			this->buttonSignUp->Text = L"Зареєструватися";
			this->buttonSignUp->UseVisualStyleBackColor = true;
			// 
			// SignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(601, 407);
			this->Controls->Add(this->buttonSignUp);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBoxBirthYear);
			this->Controls->Add(this->textBoxSurname);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->textBoxSecPassword);
			this->Controls->Add(this->textBoxLogin);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"SignUp";
			this->Text = L"SignUp";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (this->radioButtonCoach->Checked)
		{
			label6->Enabled = false;
			textBoxBirthYear->Enabled = false;
		}
		else
		{
			label6->Enabled = true;
			textBoxBirthYear->Enabled = true;
		}
	}
};
}
