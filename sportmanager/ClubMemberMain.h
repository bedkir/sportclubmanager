#pragma once

#include "ClubMember.h"

#include <string>
#include <vector>
#include <msclr/marshal.h>
#include <msclr\marshal_cppstd.h>

using namespace System::Collections::Generic;
using namespace System::Text;

namespace sportmanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ClubMemberMain
	/// </summary>
	public ref class ClubMemberMain : public System::Windows::Forms::Form
	{
	public:
		List<Button^>^ myGroups;
		List<Button^>^ otherGroups;
		Label^ noMyGroups;
		Label^ noOtherGroups;

		ClubMemberMain(void)
		{
			InitializeComponent();

			myGroups = gcnew List<Button^>();
			otherGroups = gcnew List<Button^>();
			
			BuildMyGroupsButtons();
			BuildOtherGroupsButtons();
		}

		void BuildMyGroupsButtons()
		{
			this->myGroupsPanel->Controls->Remove(noMyGroups);

			if (ClubMember::CM.getGroups().size() == 0)
			{
				Label^ newLabel = gcnew Label();
				newLabel->Text = "Ви ще не записались до жодної групи";
				newLabel->Name = "noMyGroups";
				newLabel->Location = Point(0, 0);
				newLabel->Size = System::Drawing::Size(316, 40);
				noMyGroups = newLabel;
				this->myGroupsPanel->Controls->Add(noMyGroups);
			}
			else
			{
				int x = 0;
				int y = 0;
				int h = 40;
				int w = 316;

				for (int i = 0; i < ClubMember::CM.getGroups().size(); i++)
				{
					Button^ newButton = gcnew Button();

					String^ buttonText = gcnew System::String(ClubMember::CM.getGroups()[i].c_str());
					newButton->Text = buttonText;
					newButton->Name = "button" + i.ToString();
					newButton->Location = Point(x, y);
					newButton->Size = System::Drawing::Size(w, h);
					newButton->Click += gcnew EventHandler(this, &ClubMemberMain::MyGroupButton_Click);

					this->myGroupsPanel->Controls->Add(newButton);
					myGroups->Add(newButton);

					y += h + 10;
				}
			}
		}

		void BuildOtherGroupsButtons()
		{
			otherGroupsPanel->Controls->Remove(noOtherGroups);

			if (ClubMember::CM.showAllGroups().size() == 0)
			{
				Label^ newLabel = gcnew Label();
				newLabel->Text = "Немає груп, у які можна записатися";
				newLabel->Name = "noOtherGroups";
				newLabel->Location = Point(0, 0);
				newLabel->Size = System::Drawing::Size(316, 40);
				noOtherGroups = newLabel;
				this->otherGroupsPanel->Controls->Add(noOtherGroups);
			}
			else
			{
				int x = 0;
				int y = 0;
				int h = 40;
				int w = 316;

				for (int i = 0; i < ClubMember::CM.showAllGroups().size(); i++)
				{
					Button^ newButton = gcnew Button();

					String^ buttonText = gcnew System::String(ClubMember::CM.showAllGroups()[i].c_str());
					newButton->Text = buttonText;
					newButton->Name = "button" + i.ToString();
					newButton->Location = Point(x, y);
					newButton->Size = System::Drawing::Size(w, h);
					newButton->Click += gcnew EventHandler(this, &ClubMemberMain::OtherGroupButton_Click);

					this->otherGroupsPanel->Controls->Add(newButton);
					otherGroups->Add(newButton);

					y += h + 10;
				}
			}
		}

		void DestroyMyGroupsButtons()
		{
			for each (Button ^ button in myGroups)
			{
				this->myGroupsPanel->Controls->Remove(button);
			}

			myGroups->Clear();
		}

		void DestroyOtherGroupsButtons()
		{
			for each (Button ^ button in otherGroups)
			{
				this->otherGroupsPanel->Controls->Remove(button);
			}

			otherGroups->Clear();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ClubMemberMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ myGroupsPanel;
	protected:

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ buttonSearch;
	private: System::Windows::Forms::Panel^ otherGroupsPanel;


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
			this->myGroupsPanel = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonSearch = (gcnew System::Windows::Forms::Button());
			this->otherGroupsPanel = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(26, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ваші групи:";
			// 
			// myGroupsPanel
			// 
			this->myGroupsPanel->Location = System::Drawing::Point(30, 72);
			this->myGroupsPanel->Name = L"myGroupsPanel";
			this->myGroupsPanel->Size = System::Drawing::Size(316, 356);
			this->myGroupsPanel->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(435, 26);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(229, 30);
			this->textBox1->TabIndex = 2;
			// 
			// buttonSearch
			// 
			this->buttonSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSearch->Location = System::Drawing::Point(670, 26);
			this->buttonSearch->Name = L"buttonSearch";
			this->buttonSearch->Size = System::Drawing::Size(81, 30);
			this->buttonSearch->TabIndex = 3;
			this->buttonSearch->Text = L"Пошук";
			this->buttonSearch->UseVisualStyleBackColor = true;
			this->buttonSearch->Click += gcnew System::EventHandler(this, &ClubMemberMain::buttonSearch_Click);
			// 
			// otherGroupsPanel
			// 
			this->otherGroupsPanel->Location = System::Drawing::Point(435, 72);
			this->otherGroupsPanel->Name = L"otherGroupsPanel";
			this->otherGroupsPanel->Size = System::Drawing::Size(316, 356);
			this->otherGroupsPanel->TabIndex = 4;
			// 
			// ClubMemberMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(789, 440);
			this->Controls->Add(this->otherGroupsPanel);
			this->Controls->Add(this->buttonSearch);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->myGroupsPanel);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Name = L"ClubMemberMain";
			this->Text = L"ClubMemberMain";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void buttonSearch_Click(System::Object^ sender, System::EventArgs^ e) 
	{

	}

	void MyGroupButton_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}

	void OtherGroupButton_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
};
}
