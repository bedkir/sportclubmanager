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
	/// Сводка для ClubMemberJoin
	/// </summary>
	public ref class ClubMemberJoin : public System::Windows::Forms::Form
	{
	public:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelGroupName;
	private: System::Windows::Forms::Button^ buttonEnter;
	private: System::Windows::Forms::Button^ buttonCancel;
	public:
		
		Form^ prevForm;

		ClubMemberJoin(Form^ form, String^ group)
		{
			InitializeComponent();
			
			prevForm = form;
			this->labelGroupName->Text = group;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ClubMemberJoin()
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelGroupName = (gcnew System::Windows::Forms::Label());
			this->buttonEnter = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(323, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ви дійсно бажаєте приєднатися до цієї групи:";
			// 
			// labelGroupName
			// 
			this->labelGroupName->AutoSize = true;
			this->labelGroupName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelGroupName->Location = System::Drawing::Point(109, 66);
			this->labelGroupName->Name = L"labelGroupName";
			this->labelGroupName->Size = System::Drawing::Size(0, 18);
			this->labelGroupName->TabIndex = 1;
			// 
			// buttonEnter
			// 
			this->buttonEnter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonEnter->Location = System::Drawing::Point(112, 125);
			this->buttonEnter->Name = L"buttonEnter";
			this->buttonEnter->Size = System::Drawing::Size(123, 47);
			this->buttonEnter->TabIndex = 2;
			this->buttonEnter->Text = L"Приєднатися";
			this->buttonEnter->UseVisualStyleBackColor = true;
			this->buttonEnter->Click += gcnew System::EventHandler(this, &ClubMemberJoin::buttonEnter_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCancel->Location = System::Drawing::Point(112, 193);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(123, 47);
			this->buttonCancel->TabIndex = 3;
			this->buttonCancel->Text = L"Відміна";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &ClubMemberJoin::buttonCancel_Click);
			// 
			// ClubMemberJoin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(345, 272);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonEnter);
			this->Controls->Add(this->labelGroupName);
			this->Controls->Add(this->label1);
			this->Name = L"ClubMemberJoin";
			this->Text = L"ClubMemberJoin";
			this->Load += gcnew System::EventHandler(this, &ClubMemberJoin::ClubMemberJoin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ClubMemberJoin_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void buttonEnter_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		string fullGroupName = msclr::interop::marshal_as<std::string>(this->labelGroupName->Text);

		size_t start = fullGroupName.find_first_not_of(" ");
		size_t end = fullGroupName.find(" ");
		string groupName = fullGroupName.substr(start, end - start);

		ClubMember::CM.enterTheGroup(groupName, fullGroupName);

		this->Hide();
		prevForm->Show();
		this->Close();
	}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		prevForm->Show();
		this->Close();
	}
};
}
