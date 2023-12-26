#pragma once

#include "CoachAddGroup.h"

#include <vector>

namespace sportmanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для CoachMain
	/// </summary>
	public ref class CoachMain : public System::Windows::Forms::Form
	{
	public:
		CoachMain(void)
		{
			InitializeComponent();
			
			BuildButtons();
		}

		void BuildButtons()
		{
			vector<string> groups = Coach::C.getGroups();

			if (groups.size() == 0)
			{
				Label^ newLabel = gcnew Label();
				newLabel->Text = "У Вас ще не має груп";
				newLabel->Name = "labelNoGroups";
				newLabel->Location = Point(0, 0);
				newLabel->Size = System::Drawing::Size(384, 40);
				this->groupsPanel->Controls->Add(newLabel);
			}
			else
			{
				int x = 0;
				int y = 0;
				int h = 40;
				int w = 384;

				for (int i = 0; i < groups.size(); i++)
				{
					Button^ newButton = gcnew Button();
					string group = groups[i];
					String^ buttonText = gcnew System::String(group.c_str());

					newButton->Text = buttonText;
					newButton->Name = "button" + i.ToString();
					newButton->Location = Point(x, y);
					newButton->Size = System::Drawing::Size(w, h);

					newButton->Click += gcnew EventHandler(this, &CoachMain::GroupButton_Click);

					this->groupsPanel->Controls->Add(newButton);

					y += h + 10;
				}
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CoachMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ groupsPanel;

	private: System::Windows::Forms::Button^ buttonAddGroup;

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
			this->groupsPanel = (gcnew System::Windows::Forms::Panel());
			this->buttonAddGroup = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(145, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(187, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Список Ваших груп:";
			// 
			// groupsPanel
			// 
			this->groupsPanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupsPanel->Location = System::Drawing::Point(40, 47);
			this->groupsPanel->Name = L"groupsPanel";
			this->groupsPanel->Size = System::Drawing::Size(384, 377);
			this->groupsPanel->TabIndex = 1;
			// 
			// buttonAddGroup
			// 
			this->buttonAddGroup->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonAddGroup->Location = System::Drawing::Point(165, 443);
			this->buttonAddGroup->Name = L"buttonAddGroup";
			this->buttonAddGroup->Size = System::Drawing::Size(140, 40);
			this->buttonAddGroup->TabIndex = 2;
			this->buttonAddGroup->Text = L"Створити групу";
			this->buttonAddGroup->UseVisualStyleBackColor = true;
			this->buttonAddGroup->Click += gcnew System::EventHandler(this, &CoachMain::buttonAddGroup_Click);
			// 
			// CoachMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 510);
			this->Controls->Add(this->buttonAddGroup);
			this->Controls->Add(this->groupsPanel);
			this->Controls->Add(this->label1);
			this->Name = L"CoachMain";
			this->Text = L"CoachMain";
			this->Activated += gcnew System::EventHandler(this, &CoachMain::CoachMain_Activated);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonAddGroup_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		CoachAddGroup^ form = gcnew CoachAddGroup(this);
		form->ShowDialog();
		//this->Close();
		//delete this;
	}

	void GroupButton_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}

private: System::Void CoachMain_Activated(System::Object^ sender, System::EventArgs^ e) 
{
	BuildButtons();
}
};
}
