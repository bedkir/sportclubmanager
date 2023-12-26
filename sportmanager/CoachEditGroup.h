#pragma once

#include "Coach.h"

#include <string>
#include <vector>
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
	/// Сводка для CoachEditGroup
	/// </summary>
	public ref class CoachEditGroup : public System::Windows::Forms::Form
	{
	public:
		Form^ prevForm;
	private: System::Windows::Forms::TextBox^ textBoxSearch;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ buttonSort;
	private: System::Windows::Forms::Button^ buttonBack;
	private: System::Windows::Forms::Panel^ membersPanel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ labelGroupName;
	private: System::Windows::Forms::Label^ labelLogin;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::Label^ labelSurname;
	private: System::Windows::Forms::Label^ labelBirthYear;
	private: System::Windows::Forms::Button^ buttonDeleteMember;
	public:
		String^ groupName;

		CoachEditGroup(Form^ form, String^ group)
		{
			InitializeComponent();
			
			prevForm = form;
			groupName = group;

			BuildButtons();
			this->labelGroupName->Text = groupName;
		}


		void BuildButtons()
		{
			string group = msclr::interop::marshal_as<std::string>(this->labelGroupName->Text);

			vector<string> members = Coach::C.openGroup(group);

			if (members.size() == 0)
			{

			}
			else
			{
				int x = 0;
				int y = 0;
				int h = 40;
				int w = 266;
			}
		}


		void SetActive(bool act)
		{
			this->buttonDeleteMember->Enabled = act;
			this->labelLogin->Text = "";
			this->labelName->Text = "";
			this->labelSurname->Text = "";
			this->labelBirthYear->Text = "";
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CoachEditGroup()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->textBoxSearch = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->buttonSort = (gcnew System::Windows::Forms::Button());
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->membersPanel = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->labelGroupName = (gcnew System::Windows::Forms::Label());
			this->labelLogin = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->labelSurname = (gcnew System::Windows::Forms::Label());
			this->labelBirthYear = (gcnew System::Windows::Forms::Label());
			this->buttonDeleteMember = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxSearch
			// 
			this->textBoxSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSearch->Location = System::Drawing::Point(56, 71);
			this->textBoxSearch->Multiline = true;
			this->textBoxSearch->Name = L"textBoxSearch";
			this->textBoxSearch->Size = System::Drawing::Size(266, 32);
			this->textBoxSearch->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(328, 71);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 32);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Пошук";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// buttonSort
			// 
			this->buttonSort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSort->Location = System::Drawing::Point(328, 109);
			this->buttonSort->Name = L"buttonSort";
			this->buttonSort->Size = System::Drawing::Size(97, 32);
			this->buttonSort->TabIndex = 2;
			this->buttonSort->Text = L"Сортувати";
			this->buttonSort->UseVisualStyleBackColor = true;
			// 
			// buttonBack
			// 
			this->buttonBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonBack->Location = System::Drawing::Point(328, 147);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(97, 32);
			this->buttonBack->TabIndex = 3;
			this->buttonBack->Text = L"Назад";
			this->buttonBack->UseVisualStyleBackColor = true;
			// 
			// membersPanel
			// 
			this->membersPanel->Location = System::Drawing::Point(56, 109);
			this->membersPanel->Name = L"membersPanel";
			this->membersPanel->Size = System::Drawing::Size(266, 348);
			this->membersPanel->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(491, 116);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 18);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Логін:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(503, 163);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 18);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Ім\'я:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(463, 209);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 18);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Прізвище:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(418, 262);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(122, 18);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Рік народження:";
			// 
			// labelGroupName
			// 
			this->labelGroupName->AutoSize = true;
			this->labelGroupName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelGroupName->Location = System::Drawing::Point(167, 26);
			this->labelGroupName->Name = L"labelGroupName";
			this->labelGroupName->Size = System::Drawing::Size(0, 18);
			this->labelGroupName->TabIndex = 9;
			// 
			// labelLogin
			// 
			this->labelLogin->AutoSize = true;
			this->labelLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelLogin->Location = System::Drawing::Point(557, 116);
			this->labelLogin->Name = L"labelLogin";
			this->labelLogin->Size = System::Drawing::Size(0, 18);
			this->labelLogin->TabIndex = 10;
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelName->Location = System::Drawing::Point(557, 163);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(0, 18);
			this->labelName->TabIndex = 11;
			// 
			// labelSurname
			// 
			this->labelSurname->AutoSize = true;
			this->labelSurname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelSurname->Location = System::Drawing::Point(557, 209);
			this->labelSurname->Name = L"labelSurname";
			this->labelSurname->Size = System::Drawing::Size(0, 18);
			this->labelSurname->TabIndex = 12;
			// 
			// labelBirthYear
			// 
			this->labelBirthYear->AutoSize = true;
			this->labelBirthYear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelBirthYear->Location = System::Drawing::Point(557, 262);
			this->labelBirthYear->Name = L"labelBirthYear";
			this->labelBirthYear->Size = System::Drawing::Size(0, 18);
			this->labelBirthYear->TabIndex = 13;
			// 
			// buttonDeleteMember
			// 
			this->buttonDeleteMember->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonDeleteMember->Location = System::Drawing::Point(485, 330);
			this->buttonDeleteMember->Name = L"buttonDeleteMember";
			this->buttonDeleteMember->Size = System::Drawing::Size(126, 51);
			this->buttonDeleteMember->TabIndex = 14;
			this->buttonDeleteMember->Text = L"Видалити учня";
			this->buttonDeleteMember->UseVisualStyleBackColor = true;
			// 
			// CoachEditGroup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 469);
			this->Controls->Add(this->buttonDeleteMember);
			this->Controls->Add(this->labelBirthYear);
			this->Controls->Add(this->labelSurname);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->labelLogin);
			this->Controls->Add(this->labelGroupName);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->membersPanel);
			this->Controls->Add(this->buttonBack);
			this->Controls->Add(this->buttonSort);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBoxSearch);
			this->Name = L"CoachEditGroup";
			this->Text = L"CoachEditGroup";
			this->Load += gcnew System::EventHandler(this, &CoachEditGroup::CoachEditGroup_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CoachEditGroup_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
