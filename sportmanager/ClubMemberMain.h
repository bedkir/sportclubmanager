#pragma once

#include "ClubMember.h"
#include "ClubMemberJoin.h"
#include "ClubMemberGroup.h"

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
	/// ������ ��� ClubMemberMain
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
			BuildOtherGroupsButtons(ClubMember::CM.showAvailableGroups(), "���� ����, � �� ����� ����������");
		}

		void BuildMyGroupsButtons()
		{
			this->myGroupsPanel->Controls->Remove(noMyGroups);

			if (ClubMember::CM.getGroups().size() == 0)
			{
				Label^ newLabel = gcnew Label();
				newLabel->Text = "�� �� �� ���������� �� ����� �����";
				newLabel->Name = "noMyGroups";
				newLabel->Location = Point(0, 0);
				newLabel->Size = System::Drawing::Size(217, 40);
				noMyGroups = newLabel;
				this->myGroupsPanel->Controls->Add(noMyGroups);
			}
			else
			{
				int x = 0;
				int y = 0;
				int h = 40;
				int w = 217;

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

		void BuildOtherGroupsButtons(vector<string> groups, String^ labelText)
		{
			otherGroupsPanel->Controls->Remove(noOtherGroups);

			if (groups.size() == 0)
			{
				Label^ newLabel = gcnew Label();
				newLabel->Text = labelText;
				newLabel->Name = "noOtherGroups";
				newLabel->Location = Point(0, 0);
				newLabel->Size = System::Drawing::Size(217, 40);
				noOtherGroups = newLabel;
				this->otherGroupsPanel->Controls->Add(noOtherGroups);
			}
			else
			{
				int x = 0;
				int y = 0;
				int h = 40;
				int w = 217;

				for (int i = 0; i < groups.size(); i++)
				{
					Button^ newButton = gcnew Button();

					String^ buttonText = gcnew System::String(groups[i].c_str());
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
		/// ���������� ��� ������������ �������.
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
private: System::Windows::Forms::TextBox^ textBoxSearch;
	protected:


	private: System::Windows::Forms::Button^ buttonSearch;
	private: System::Windows::Forms::Panel^ otherGroupsPanel;


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->myGroupsPanel = (gcnew System::Windows::Forms::Panel());
			this->textBoxSearch = (gcnew System::Windows::Forms::TextBox());
			this->buttonSearch = (gcnew System::Windows::Forms::Button());
			this->otherGroupsPanel = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(20, 24);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"���� �����:";
			// 
			// myGroupsPanel
			// 
			this->myGroupsPanel->AutoScroll = true;
			this->myGroupsPanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->myGroupsPanel->Location = System::Drawing::Point(22, 55);
			this->myGroupsPanel->Margin = System::Windows::Forms::Padding(2);
			this->myGroupsPanel->Name = L"myGroupsPanel";
			this->myGroupsPanel->Size = System::Drawing::Size(237, 272);
			this->myGroupsPanel->TabIndex = 1;
			// 
			// textBoxSearch
			// 
			this->textBoxSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSearch->Location = System::Drawing::Point(326, 20);
			this->textBoxSearch->Margin = System::Windows::Forms::Padding(2);
			this->textBoxSearch->Multiline = true;
			this->textBoxSearch->Name = L"textBoxSearch";
			this->textBoxSearch->Size = System::Drawing::Size(160, 31);
			this->textBoxSearch->TabIndex = 2;
			// 
			// buttonSearch
			// 
			this->buttonSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSearch->Location = System::Drawing::Point(490, 20);
			this->buttonSearch->Margin = System::Windows::Forms::Padding(2);
			this->buttonSearch->Name = L"buttonSearch";
			this->buttonSearch->Size = System::Drawing::Size(73, 31);
			this->buttonSearch->TabIndex = 3;
			this->buttonSearch->Text = L"�����";
			this->buttonSearch->UseVisualStyleBackColor = true;
			this->buttonSearch->Click += gcnew System::EventHandler(this, &ClubMemberMain::buttonSearch_Click);
			// 
			// otherGroupsPanel
			// 
			this->otherGroupsPanel->AutoScroll = true;
			this->otherGroupsPanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->otherGroupsPanel->Location = System::Drawing::Point(326, 55);
			this->otherGroupsPanel->Margin = System::Windows::Forms::Padding(2);
			this->otherGroupsPanel->Name = L"otherGroupsPanel";
			this->otherGroupsPanel->Size = System::Drawing::Size(237, 272);
			this->otherGroupsPanel->TabIndex = 4;
			// 
			// ClubMemberMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(592, 336);
			this->Controls->Add(this->otherGroupsPanel);
			this->Controls->Add(this->buttonSearch);
			this->Controls->Add(this->textBoxSearch);
			this->Controls->Add(this->myGroupsPanel);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ClubMemberMain";
			this->Text = L"ClubMemberMain";
			this->Activated += gcnew System::EventHandler(this, &ClubMemberMain::ClubMemberMain_Activated);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void buttonSearch_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		string request = msclr::interop::marshal_as<std::string>(this->textBoxSearch->Text);

		if (request == "")
		{
			DestroyOtherGroupsButtons();
			BuildOtherGroupsButtons(ClubMember::CM.showAvailableGroups(), "���� ����, � �� ����� ����������");
		}
		else
		{
			vector<string> result = ClubMember::CM.searchGroup(request);

			DestroyOtherGroupsButtons();
			BuildOtherGroupsButtons(result, "�� ����� ������� ������ �� ��������");
		}
	}

	void MyGroupButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ thisButton = safe_cast<Button^>(sender);

		this->Hide();
		ClubMemberGroup^ form = gcnew ClubMemberGroup(this, thisButton->Text);
		form->ShowDialog();
	}

	void OtherGroupButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ thisButton = safe_cast<Button^>(sender);

		this->Hide();
		ClubMemberJoin^ form = gcnew ClubMemberJoin(this, thisButton->Text);
		form->ShowDialog();
	}

	private: System::Void ClubMemberMain_Activated(System::Object^ sender, System::EventArgs^ e) 
	{
		DestroyMyGroupsButtons();
		DestroyOtherGroupsButtons();
		BuildMyGroupsButtons();
		BuildOtherGroupsButtons(ClubMember::CM.showAvailableGroups(), "���� ����, � �� ����� ����������");
	}
};
}
