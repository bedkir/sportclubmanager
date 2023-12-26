#pragma once

#include "Group.h"

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
	/// Сводка для CoachAddGroup
	/// </summary>
	public ref class CoachAddGroup : public System::Windows::Forms::Form
	{
	public:
		Form^ prevForm;

		CoachAddGroup(Form^ form)
		{
			InitializeComponent();
			
			this->prevForm = form;

			this->labelGroupNumber->Text = Group::getAmountOfGroups().ToString();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CoachAddGroup()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxSport;
	private: System::Windows::Forms::Label^ labelGroupNumber;
	private: System::Windows::Forms::Button^ buttonCreate;
	private: System::Windows::Forms::Button^ buttonCancel;
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
			this->textBoxSport = (gcnew System::Windows::Forms::TextBox());
			this->labelGroupNumber = (gcnew System::Windows::Forms::Label());
			this->buttonCreate = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(88, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Спорт:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(43, 117);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Номер групи:";
			// 
			// textBoxSport
			// 
			this->textBoxSport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSport->Location = System::Drawing::Point(163, 58);
			this->textBoxSport->Name = L"textBoxSport";
			this->textBoxSport->Size = System::Drawing::Size(100, 24);
			this->textBoxSport->TabIndex = 2;
			// 
			// labelGroupNumber
			// 
			this->labelGroupNumber->AutoSize = true;
			this->labelGroupNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->labelGroupNumber->Location = System::Drawing::Point(160, 117);
			this->labelGroupNumber->Name = L"labelGroupNumber";
			this->labelGroupNumber->Size = System::Drawing::Size(0, 18);
			this->labelGroupNumber->TabIndex = 3;
			// 
			// buttonCreate
			// 
			this->buttonCreate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCreate->Location = System::Drawing::Point(112, 191);
			this->buttonCreate->Name = L"buttonCreate";
			this->buttonCreate->Size = System::Drawing::Size(125, 48);
			this->buttonCreate->TabIndex = 4;
			this->buttonCreate->Text = L"Створити";
			this->buttonCreate->UseVisualStyleBackColor = true;
			this->buttonCreate->Click += gcnew System::EventHandler(this, &CoachAddGroup::buttonCreate_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCancel->Location = System::Drawing::Point(112, 269);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(125, 48);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Відміна";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &CoachAddGroup::buttonCancel_Click);
			// 
			// CoachAddGroup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(347, 390);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonCreate);
			this->Controls->Add(this->labelGroupNumber);
			this->Controls->Add(this->textBoxSport);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"CoachAddGroup";
			this->Text = L"CoachAddGroup";
			this->Load += gcnew System::EventHandler(this, &CoachAddGroup::CoachAddGroup_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CoachAddGroup_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		//CoachAddGroup^ form = gcnew CoachAddGroup(this);
		prevForm->Show();
		this->Close();
	}

	private: System::Void buttonCreate_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		string sport = msclr::interop::marshal_as<std::string>(this->textBoxSport->Text);

		Coach::C.createGroup(sport);

		this->Hide();
		//CoachAddGroup^ form = gcnew CoachAddGroup(this);
		prevForm->ShowDialog();
		this->Close();
	}
};
}
