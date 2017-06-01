#include "StdAfx.h"
#include "SQL.h"

#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;


namespace Stefano {

	/// <summary>
	/// Summary for Window
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Window : public System::Windows::Forms::Form
	{
	public:
		Window(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Window()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  vipGBox1;
	protected: 

	private: System::Windows::Forms::NumericUpDown^  vipYear;
	protected: 

	private: System::Windows::Forms::NumericUpDown^  vipMonth;
	private: System::Windows::Forms::NumericUpDown^  vipDay;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  vipGet;
	private: System::Windows::Forms::Label^  label10;



	private: System::Windows::Forms::TextBox^  vipAccount;

	private: System::Windows::Forms::Button^  vipUpdate;
	private: System::Windows::Forms::NumericUpDown^  vipType;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->vipGBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->vipUpdate = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->vipYear = (gcnew System::Windows::Forms::NumericUpDown());
			this->vipType = (gcnew System::Windows::Forms::NumericUpDown());
			this->vipDay = (gcnew System::Windows::Forms::NumericUpDown());
			this->vipMonth = (gcnew System::Windows::Forms::NumericUpDown());
			this->vipGet = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->vipAccount = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->vipGBox1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vipYear))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vipType))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vipDay))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vipMonth))->BeginInit();
			this->SuspendLayout();
			// 
			// vipGBox1
			// 
			this->vipGBox1->Controls->Add(this->groupBox1);
			this->vipGBox1->Controls->Add(this->vipGet);
			this->vipGBox1->Controls->Add(this->label10);
			this->vipGBox1->Controls->Add(this->vipAccount);
			this->vipGBox1->Location = System::Drawing::Point(1, 1);
			this->vipGBox1->Name = L"vipGBox1";
			this->vipGBox1->Size = System::Drawing::Size(160, 215);
			this->vipGBox1->TabIndex = 0;
			this->vipGBox1->TabStop = false;
			this->vipGBox1->Text = L"Controle VIP";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->vipUpdate);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->vipYear);
			this->groupBox1->Controls->Add(this->vipType);
			this->groupBox1->Controls->Add(this->vipDay);
			this->groupBox1->Controls->Add(this->vipMonth);
			this->groupBox1->Location = System::Drawing::Point(6, 87);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(149, 123);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"VIP do Player";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(20, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Tipo de VIP:";
			// 
			// vipUpdate
			// 
			this->vipUpdate->Location = System::Drawing::Point(37, 94);
			this->vipUpdate->Name = L"vipUpdate";
			this->vipUpdate->Size = System::Drawing::Size(75, 23);
			this->vipUpdate->TabIndex = 3;
			this->vipUpdate->Text = L"Atualizar";
			this->vipUpdate->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Término do VIP:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 56);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Dia  \\   Mês   \\  Ano";
			// 
			// vipYear
			// 
			this->vipYear->Location = System::Drawing::Point(91, 72);
			this->vipYear->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3000, 0, 0, 0});
			this->vipYear->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2009, 0, 0, 0});
			this->vipYear->Name = L"vipYear";
			this->vipYear->Size = System::Drawing::Size(53, 20);
			this->vipYear->TabIndex = 0;
			this->vipYear->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2009, 0, 0, 0});
			// 
			// vipType
			// 
			this->vipType->Location = System::Drawing::Point(92, 18);
			this->vipType->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->vipType->Name = L"vipType";
			this->vipType->Size = System::Drawing::Size(36, 20);
			this->vipType->TabIndex = 0;
			this->vipType->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// vipDay
			// 
			this->vipDay->Location = System::Drawing::Point(5, 72);
			this->vipDay->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {31, 0, 0, 0});
			this->vipDay->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->vipDay->Name = L"vipDay";
			this->vipDay->Size = System::Drawing::Size(37, 20);
			this->vipDay->TabIndex = 0;
			this->vipDay->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// vipMonth
			// 
			this->vipMonth->Location = System::Drawing::Point(48, 72);
			this->vipMonth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {31, 0, 0, 0});
			this->vipMonth->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->vipMonth->Name = L"vipMonth";
			this->vipMonth->Size = System::Drawing::Size(37, 20);
			this->vipMonth->TabIndex = 0;
			this->vipMonth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// vipGet
			// 
			this->vipGet->Location = System::Drawing::Point(43, 58);
			this->vipGet->Name = L"vipGet";
			this->vipGet->Size = System::Drawing::Size(75, 23);
			this->vipGet->TabIndex = 3;
			this->vipGet->Text = L"Pegar Infos";
			this->vipGet->UseVisualStyleBackColor = true;
			this->vipGet->Click += gcnew System::EventHandler(this, &Window::vipGet_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(27, 16);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(106, 13);
			this->label10->TabIndex = 2;
			this->label10->Text = L"Account do Jogador:";
			// 
			// vipAccount
			// 
			this->vipAccount->Location = System::Drawing::Point(29, 32);
			this->vipAccount->MaxLength = 10;
			this->vipAccount->Name = L"vipAccount";
			this->vipAccount->Size = System::Drawing::Size(103, 20);
			this->vipAccount->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1, 217);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Recarregar Configs";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Window::button1_Click);
			// 
			// Window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(163, 241);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->vipGBox1);
			this->Name = L"Window";
			this->Text = L"Painel";
			this->vipGBox1->ResumeLayout(false);
			this->vipGBox1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vipYear))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vipType))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vipDay))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vipMonth))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void vipGet_Click(System::Object^  sender, System::EventArgs^  e) 
			 {

			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			CommandSwitch(0,0,64);
		 }
};
}
