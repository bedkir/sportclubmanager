#pragma once

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
	/// Сводка для ClubMemberGroup
	/// </summary>
	public ref class ClubMemberGroup : public System::Windows::Forms::Form
	{
		Form^ prevForm;

	public:
		ClubMemberGroup(Form^ form, String^ group)
		{
			InitializeComponent();
			
			prevForm = form;
			this->labelGroupName->Text = group;

			string fullGroupName = msclr::interop::marshal_as<std::string>(this->labelGroupName->Text);
			size_t start = fullGroupName.find_first_not_of(" ");
			size_t end = fullGroupName.find(" ");
			string groupName = fullGroupName.substr(start, end - start);

			Group g = ClubMember::CM.groupInfo(groupName);

			this->labelCoach->Text = gcnew System::String(g.getCoach().c_str());

			int x = 0;
			int y = 0;
			int h = 40;
			int w = 184;
			for (int i = 0; i < g.getMembers().size(); i++)
			{
				Label^ newLabel = gcnew Label();
				newLabel->Text = gcnew System::String(g.getMembers()[i].c_str());
				newLabel->Name = "member" + i.ToString();
				newLabel->Location = Point(x, y);
				newLabel->Size = System::Drawing::Size(w, h);
				this->panelMembers->Controls->Add(newLabel);

				y += h + 10;
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ClubMemberGroup()
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
	private: System::Windows::Forms::Label^ labelGroupName;
	private: System::Windows::Forms::Label^ labelCoach;
	private: System::Windows::Forms::Panel^ panelMembers;
	private: System::Windows::Forms::Button^ buttonLeave;
	private: System::Windows::Forms::Button^ buttonBack;

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
			this->labelGroupName = (gcnew System::Windows::Forms::Label());
			this->labelCoach = (gcnew System::Windows::Forms::Label());
			this->panelMembers = (gcnew System::Windows::Forms::Panel());
			this->buttonLeave = (gcnew System::Windows::Forms::Button());
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(44, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Група:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(35, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Тренер:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(55, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 18);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Учні:";
			// 
			// labelGroupName
			// 
			this->labelGroupName->AutoSize = true;
			this->labelGroupName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelGroupName->Location = System::Drawing::Point(102, 42);
			this->labelGroupName->Name = L"labelGroupName";
			this->labelGroupName->Size = System::Drawing::Size(0, 18);
			this->labelGroupName->TabIndex = 3;
			// 
			// labelCoach
			// 
			this->labelCoach->AutoSize = true;
			this->labelCoach->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelCoach->Location = System::Drawing::Point(102, 90);
			this->labelCoach->Name = L"labelCoach";
			this->labelCoach->Size = System::Drawing::Size(0, 18);
			this->labelCoach->TabIndex = 4;
			// 
			// panelMembers
			// 
			this->panelMembers->AutoScroll = true;
			this->panelMembers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panelMembers->Location = System::Drawing::Point(105, 138);
			this->panelMembers->Name = L"panelMembers";
			this->panelMembers->Size = System::Drawing::Size(204, 246);
			this->panelMembers->TabIndex = 5;
			// 
			// buttonLeave
			// 
			this->buttonLeave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonLeave->Location = System::Drawing::Point(348, 138);
			this->buttonLeave->Name = L"buttonLeave";
			this->buttonLeave->Size = System::Drawing::Size(126, 45);
			this->buttonLeave->TabIndex = 6;
			this->buttonLeave->Text = L"Покинути групу";
			this->buttonLeave->UseVisualStyleBackColor = true;
			this->buttonLeave->Click += gcnew System::EventHandler(this, &ClubMemberGroup::buttonLeave_Click);
			// 
			// buttonBack
			// 
			this->buttonBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonBack->Location = System::Drawing::Point(348, 211);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(126, 45);
			this->buttonBack->TabIndex = 7;
			this->buttonBack->Text = L"Повернутися";
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew System::EventHandler(this, &ClubMemberGroup::buttonBack_Click);
			// 
			// ClubMemberGroup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(502, 396);
			this->Controls->Add(this->buttonBack);
			this->Controls->Add(this->buttonLeave);
			this->Controls->Add(this->panelMembers);
			this->Controls->Add(this->labelCoach);
			this->Controls->Add(this->labelGroupName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ClubMemberGroup";
			this->Text = L"ClubMemberGroup";
			this->Load += gcnew System::EventHandler(this, &ClubMemberGroup::ClubMemberGroup_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ClubMemberGroup_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void buttonLeave_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		string fullGroupName = msclr::interop::marshal_as<std::string>(this->labelGroupName->Text);
		size_t start = fullGroupName.find_first_not_of(" ");
		size_t end = fullGroupName.find(" ");
		string groupName = fullGroupName.substr(start, end - start);

		ClubMember::CM.deleteMember(groupName, ClubMember::CM.getLogin(), ClubMember::CM.getName(), ClubMember::CM.getSurname());

		this->Hide();
		prevForm->Show();
		this->Close();
	}

	private: System::Void buttonBack_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		prevForm->Show();
		this->Close();
	}
};
}
