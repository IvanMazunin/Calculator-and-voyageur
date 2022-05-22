#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <list>
#include <stack>
#include <string>
const double PI = 3.14159265358979323846;
const double E = 2.71828182845904523536;

namespace Калькулятор {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button_1;
	private: System::Windows::Forms::Button^ button_2;
	private: System::Windows::Forms::Button^ button_3;
	private: System::Windows::Forms::Button^ button_4;
	private: System::Windows::Forms::Button^ button_5;
	private: System::Windows::Forms::Button^ button_6;
	private: System::Windows::Forms::Button^ button_7;
	private: System::Windows::Forms::Button^ button_8;
	private: System::Windows::Forms::Button^ button_9;
	private: System::Windows::Forms::Button^ button_0;
	private: System::Windows::Forms::Button^ button_AC;
	private: System::Windows::Forms::Button^ button_plus;
	private: System::Windows::Forms::Button^ button_minus;
	private: System::Windows::Forms::Button^ button_umn;
	private: System::Windows::Forms::Button^ button_del;
	private: System::Windows::Forms::Button^ button_go;
	private: System::Windows::Forms::Button^ button_point;
	private: System::Windows::Forms::Button^ button_deg;
	private: System::Windows::Forms::Button^ button_sqrt;
	private: System::Windows::Forms::Button^ button_log;
	private: System::Windows::Forms::Button^ button_ln;
	private: System::Windows::Forms::Button^ button_fact;
	private: System::Windows::Forms::Button^ button_inv;
	private: System::Windows::Forms::Button^ button_tan;
	private: System::Windows::Forms::Button^ button_cos;
	private: System::Windows::Forms::Button^ button_sin;
	private: System::Windows::Forms::Button^ button_ans;
	private: System::Windows::Forms::Button^ button_e;
	private: System::Windows::Forms::Button^ button_left;
	private: System::Windows::Forms::Button^ button_right;

	private: System::Windows::Forms::Button^ button_p;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button_rad;
	private: System::Windows::Forms::TextBox^ textBox3;

	private: System::Windows::Forms::Button^ button_perc;
	private:
		bool rad = false;
		String^ str = "0";
		String^ Ans = "0";
		String^ number = "0";
	public:
		void setNumber(String^ abc) {
			this->number = this->number + abc;
		}
		String^ getNumber() {
			return this->number;
		}
		void clearNumber() {
			this->number = "";
		}
		void setRad(bool rad) {
			this->rad = rad;
		}
		bool getRad() {
			return this->rad;
		}
		void clearStr() {
			this->str = "";
		}
		void setAns(String^ abc) {
			this->Ans = abc;
		}
		String^ getAns() {
			return this->Ans;
		}
		void setStr(String^ abc) {
			this->str = this->str + abc;
		}
		String^ getStr() {
			return this->str;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button_1 = (gcnew System::Windows::Forms::Button());
			this->button_2 = (gcnew System::Windows::Forms::Button());
			this->button_3 = (gcnew System::Windows::Forms::Button());
			this->button_4 = (gcnew System::Windows::Forms::Button());
			this->button_5 = (gcnew System::Windows::Forms::Button());
			this->button_6 = (gcnew System::Windows::Forms::Button());
			this->button_7 = (gcnew System::Windows::Forms::Button());
			this->button_8 = (gcnew System::Windows::Forms::Button());
			this->button_9 = (gcnew System::Windows::Forms::Button());
			this->button_0 = (gcnew System::Windows::Forms::Button());
			this->button_AC = (gcnew System::Windows::Forms::Button());
			this->button_plus = (gcnew System::Windows::Forms::Button());
			this->button_minus = (gcnew System::Windows::Forms::Button());
			this->button_umn = (gcnew System::Windows::Forms::Button());
			this->button_del = (gcnew System::Windows::Forms::Button());
			this->button_go = (gcnew System::Windows::Forms::Button());
			this->button_point = (gcnew System::Windows::Forms::Button());
			this->button_deg = (gcnew System::Windows::Forms::Button());
			this->button_sqrt = (gcnew System::Windows::Forms::Button());
			this->button_log = (gcnew System::Windows::Forms::Button());
			this->button_ln = (gcnew System::Windows::Forms::Button());
			this->button_fact = (gcnew System::Windows::Forms::Button());
			this->button_inv = (gcnew System::Windows::Forms::Button());
			this->button_tan = (gcnew System::Windows::Forms::Button());
			this->button_cos = (gcnew System::Windows::Forms::Button());
			this->button_sin = (gcnew System::Windows::Forms::Button());
			this->button_ans = (gcnew System::Windows::Forms::Button());
			this->button_e = (gcnew System::Windows::Forms::Button());
			this->button_left = (gcnew System::Windows::Forms::Button());
			this->button_right = (gcnew System::Windows::Forms::Button());
			this->button_p = (gcnew System::Windows::Forms::Button());
			this->button_rad = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button_perc = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::LightBlue;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Cursor = System::Windows::Forms::Cursors::No;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 23, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(185, 45);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(424, 40);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"0";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox1->WordWrap = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::LightBlue;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(185, 28);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(58, 20);
			this->textBox2->TabIndex = 40;
			this->textBox2->Text = L"Deg";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button_1
			// 
			this->button_1->BackColor = System::Drawing::Color::SaddleBrown;
			this->button_1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button_1->Location = System::Drawing::Point(271, 227);
			this->button_1->Name = L"button_1";
			this->button_1->Size = System::Drawing::Size(80, 35);
			this->button_1->TabIndex = 0;
			this->button_1->Text = L"1";
			this->button_1->UseVisualStyleBackColor = false;
			this->button_1->Click += gcnew System::EventHandler(this, &MyForm::button_1_Click);
			// 
			// button_2
			// 
			this->button_2->BackColor = System::Drawing::Color::SaddleBrown;
			this->button_2->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button_2->Location = System::Drawing::Point(357, 227);
			this->button_2->Name = L"button_2";
			this->button_2->Size = System::Drawing::Size(80, 35);
			this->button_2->TabIndex = 2;
			this->button_2->Text = L"2";
			this->button_2->UseVisualStyleBackColor = false;
			this->button_2->Click += gcnew System::EventHandler(this, &MyForm::button_2_Click);
			// 
			// button_3
			// 
			this->button_3->BackColor = System::Drawing::Color::SaddleBrown;
			this->button_3->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button_3->Location = System::Drawing::Point(443, 227);
			this->button_3->Name = L"button_3";
			this->button_3->Size = System::Drawing::Size(80, 35);
			this->button_3->TabIndex = 3;
			this->button_3->Text = L"3";
			this->button_3->UseVisualStyleBackColor = false;
			this->button_3->Click += gcnew System::EventHandler(this, &MyForm::button_3_Click);
			// 
			// button_4
			// 
			this->button_4->BackColor = System::Drawing::Color::SaddleBrown;
			this->button_4->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button_4->Location = System::Drawing::Point(271, 186);
			this->button_4->Name = L"button_4";
			this->button_4->Size = System::Drawing::Size(80, 35);
			this->button_4->TabIndex = 4;
			this->button_4->Text = L"4";
			this->button_4->UseVisualStyleBackColor = false;
			this->button_4->Click += gcnew System::EventHandler(this, &MyForm::button_4_Click);
			// 
			// button_5
			// 
			this->button_5->BackColor = System::Drawing::Color::SaddleBrown;
			this->button_5->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15));
			this->button_5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button_5->Location = System::Drawing::Point(357, 186);
			this->button_5->Name = L"button_5";
			this->button_5->Size = System::Drawing::Size(80, 35);
			this->button_5->TabIndex = 5;
			this->button_5->Text = L"5";
			this->button_5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button_5->UseVisualStyleBackColor = false;
			this->button_5->Click += gcnew System::EventHandler(this, &MyForm::button_5_Click);
			// 
			// button_6
			// 
			this->button_6->BackColor = System::Drawing::Color::SaddleBrown;
			this->button_6->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_6->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button_6->Location = System::Drawing::Point(443, 186);
			this->button_6->Name = L"button_6";
			this->button_6->Size = System::Drawing::Size(80, 35);
			this->button_6->TabIndex = 6;
			this->button_6->Text = L"6";
			this->button_6->UseVisualStyleBackColor = false;
			this->button_6->Click += gcnew System::EventHandler(this, &MyForm::button_6_Click);
			// 
			// button_7
			// 
			this->button_7->BackColor = System::Drawing::Color::SaddleBrown;
			this->button_7->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_7->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button_7->Location = System::Drawing::Point(271, 143);
			this->button_7->Name = L"button_7";
			this->button_7->Size = System::Drawing::Size(80, 35);
			this->button_7->TabIndex = 7;
			this->button_7->Text = L"7";
			this->button_7->UseVisualStyleBackColor = false;
			this->button_7->Click += gcnew System::EventHandler(this, &MyForm::button_7_Click);
			// 
			// button_8
			// 
			this->button_8->BackColor = System::Drawing::Color::SaddleBrown;
			this->button_8->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_8->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button_8->Location = System::Drawing::Point(357, 143);
			this->button_8->Name = L"button_8";
			this->button_8->Size = System::Drawing::Size(80, 35);
			this->button_8->TabIndex = 8;
			this->button_8->Text = L"8";
			this->button_8->UseVisualStyleBackColor = false;
			this->button_8->Click += gcnew System::EventHandler(this, &MyForm::button_8_Click);
			// 
			// button_9
			// 
			this->button_9->BackColor = System::Drawing::Color::SaddleBrown;
			this->button_9->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_9->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button_9->Location = System::Drawing::Point(443, 143);
			this->button_9->Name = L"button_9";
			this->button_9->Size = System::Drawing::Size(80, 35);
			this->button_9->TabIndex = 9;
			this->button_9->Text = L"9";
			this->button_9->UseVisualStyleBackColor = false;
			this->button_9->Click += gcnew System::EventHandler(this, &MyForm::button_9_Click);
			// 
			// button_0
			// 
			this->button_0->BackColor = System::Drawing::Color::SaddleBrown;
			this->button_0->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_0->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button_0->Location = System::Drawing::Point(357, 266);
			this->button_0->Name = L"button_0";
			this->button_0->Size = System::Drawing::Size(80, 35);
			this->button_0->TabIndex = 10;
			this->button_0->Text = L"0";
			this->button_0->UseVisualStyleBackColor = false;
			this->button_0->Click += gcnew System::EventHandler(this, &MyForm::button_0_Click);
			// 
			// button_AC
			// 
			this->button_AC->BackColor = System::Drawing::Color::Chocolate;
			this->button_AC->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_AC->Location = System::Drawing::Point(529, 102);
			this->button_AC->Name = L"button_AC";
			this->button_AC->Size = System::Drawing::Size(80, 35);
			this->button_AC->TabIndex = 11;
			this->button_AC->Text = L"AC";
			this->button_AC->UseVisualStyleBackColor = false;
			this->button_AC->Click += gcnew System::EventHandler(this, &MyForm::button_AC_Click);
			// 
			// button_plus
			// 
			this->button_plus->BackColor = System::Drawing::Color::Chocolate;
			this->button_plus->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_plus->Location = System::Drawing::Point(529, 143);
			this->button_plus->Name = L"button_plus";
			this->button_plus->Size = System::Drawing::Size(80, 35);
			this->button_plus->TabIndex = 12;
			this->button_plus->Text = L"+";
			this->button_plus->UseVisualStyleBackColor = false;
			this->button_plus->Click += gcnew System::EventHandler(this, &MyForm::button_plus_Click);
			// 
			// button_minus
			// 
			this->button_minus->BackColor = System::Drawing::Color::Chocolate;
			this->button_minus->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_minus->Location = System::Drawing::Point(529, 184);
			this->button_minus->Name = L"button_minus";
			this->button_minus->Size = System::Drawing::Size(80, 35);
			this->button_minus->TabIndex = 13;
			this->button_minus->Text = L"-";
			this->button_minus->UseVisualStyleBackColor = false;
			this->button_minus->Click += gcnew System::EventHandler(this, &MyForm::button_minus_Click);
			// 
			// button_umn
			// 
			this->button_umn->BackColor = System::Drawing::Color::Chocolate;
			this->button_umn->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_umn->Location = System::Drawing::Point(529, 225);
			this->button_umn->Name = L"button_umn";
			this->button_umn->Size = System::Drawing::Size(80, 35);
			this->button_umn->TabIndex = 14;
			this->button_umn->Text = L"x";
			this->button_umn->UseVisualStyleBackColor = false;
			this->button_umn->Click += gcnew System::EventHandler(this, &MyForm::button_umn_Click);
			// 
			// button_del
			// 
			this->button_del->BackColor = System::Drawing::Color::Chocolate;
			this->button_del->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Bold));
			this->button_del->Location = System::Drawing::Point(529, 266);
			this->button_del->Name = L"button_del";
			this->button_del->Size = System::Drawing::Size(80, 35);
			this->button_del->TabIndex = 15;
			this->button_del->Text = L"÷";
			this->button_del->UseVisualStyleBackColor = false;
			this->button_del->Click += gcnew System::EventHandler(this, &MyForm::button_del_Click);
			// 
			// button_go
			// 
			this->button_go->BackColor = System::Drawing::Color::SteelBlue;
			this->button_go->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_go->Location = System::Drawing::Point(443, 266);
			this->button_go->Name = L"button_go";
			this->button_go->Size = System::Drawing::Size(80, 35);
			this->button_go->TabIndex = 16;
			this->button_go->Text = L"=";
			this->button_go->UseVisualStyleBackColor = false;
			this->button_go->Click += gcnew System::EventHandler(this, &MyForm::button_go_Click);
			// 
			// button_point
			// 
			this->button_point->BackColor = System::Drawing::Color::Chocolate;
			this->button_point->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_point->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button_point->Location = System::Drawing::Point(271, 266);
			this->button_point->Name = L"button_point";
			this->button_point->Size = System::Drawing::Size(80, 35);
			this->button_point->TabIndex = 17;
			this->button_point->Text = L".";
			this->button_point->UseVisualStyleBackColor = false;
			this->button_point->Click += gcnew System::EventHandler(this, &MyForm::button_point_Click);
			// 
			// button_deg
			// 
			this->button_deg->BackColor = System::Drawing::Color::Chocolate;
			this->button_deg->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_deg->Location = System::Drawing::Point(185, 266);
			this->button_deg->Name = L"button_deg";
			this->button_deg->Size = System::Drawing::Size(80, 35);
			this->button_deg->TabIndex = 18;
			this->button_deg->Text = L"^";
			this->button_deg->UseVisualStyleBackColor = false;
			this->button_deg->Click += gcnew System::EventHandler(this, &MyForm::button_deg_Click);
			// 
			// button_sqrt
			// 
			this->button_sqrt->BackColor = System::Drawing::Color::Chocolate;
			this->button_sqrt->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_sqrt->Location = System::Drawing::Point(185, 227);
			this->button_sqrt->Name = L"button_sqrt";
			this->button_sqrt->Size = System::Drawing::Size(80, 35);
			this->button_sqrt->TabIndex = 19;
			this->button_sqrt->Text = L"√";
			this->button_sqrt->UseVisualStyleBackColor = false;
			this->button_sqrt->Click += gcnew System::EventHandler(this, &MyForm::button_sqrt_Click);
			// 
			// button_log
			// 
			this->button_log->BackColor = System::Drawing::Color::Chocolate;
			this->button_log->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_log->Location = System::Drawing::Point(185, 184);
			this->button_log->Name = L"button_log";
			this->button_log->Size = System::Drawing::Size(80, 35);
			this->button_log->TabIndex = 20;
			this->button_log->Text = L"log";
			this->button_log->UseVisualStyleBackColor = false;
			this->button_log->Click += gcnew System::EventHandler(this, &MyForm::button_log_Click);
			// 
			// button_ln
			// 
			this->button_ln->BackColor = System::Drawing::Color::Chocolate;
			this->button_ln->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_ln->Location = System::Drawing::Point(185, 143);
			this->button_ln->Name = L"button_ln";
			this->button_ln->Size = System::Drawing::Size(80, 35);
			this->button_ln->TabIndex = 21;
			this->button_ln->Text = L"ln";
			this->button_ln->UseVisualStyleBackColor = false;
			this->button_ln->Click += gcnew System::EventHandler(this, &MyForm::button_ln_Click);
			// 
			// button_fact
			// 
			this->button_fact->BackColor = System::Drawing::Color::Chocolate;
			this->button_fact->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_fact->Location = System::Drawing::Point(185, 102);
			this->button_fact->Name = L"button_fact";
			this->button_fact->Size = System::Drawing::Size(80, 35);
			this->button_fact->TabIndex = 22;
			this->button_fact->Text = L"!";
			this->button_fact->UseVisualStyleBackColor = false;
			this->button_fact->Click += gcnew System::EventHandler(this, &MyForm::button_fact_Click);
			// 
			// button_inv
			// 
			this->button_inv->BackColor = System::Drawing::Color::Chocolate;
			this->button_inv->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_inv->Location = System::Drawing::Point(99, 266);
			this->button_inv->Name = L"button_inv";
			this->button_inv->Size = System::Drawing::Size(80, 35);
			this->button_inv->TabIndex = 23;
			this->button_inv->Text = L"inv";
			this->button_inv->UseVisualStyleBackColor = false;
			this->button_inv->Click += gcnew System::EventHandler(this, &MyForm::button_inv_Click);
			// 
			// button_tan
			// 
			this->button_tan->BackColor = System::Drawing::Color::Chocolate;
			this->button_tan->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_tan->Location = System::Drawing::Point(99, 225);
			this->button_tan->Name = L"button_tan";
			this->button_tan->Size = System::Drawing::Size(80, 35);
			this->button_tan->TabIndex = 24;
			this->button_tan->Text = L"tan";
			this->button_tan->UseVisualStyleBackColor = false;
			this->button_tan->Click += gcnew System::EventHandler(this, &MyForm::button_tan_Click);
			// 
			// button_cos
			// 
			this->button_cos->BackColor = System::Drawing::Color::Chocolate;
			this->button_cos->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_cos->Location = System::Drawing::Point(99, 186);
			this->button_cos->Name = L"button_cos";
			this->button_cos->Size = System::Drawing::Size(80, 35);
			this->button_cos->TabIndex = 25;
			this->button_cos->Text = L"cos";
			this->button_cos->UseVisualStyleBackColor = false;
			this->button_cos->Click += gcnew System::EventHandler(this, &MyForm::button_cos_Click);
			// 
			// button_sin
			// 
			this->button_sin->BackColor = System::Drawing::Color::Chocolate;
			this->button_sin->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_sin->Location = System::Drawing::Point(99, 143);
			this->button_sin->Name = L"button_sin";
			this->button_sin->Size = System::Drawing::Size(80, 35);
			this->button_sin->TabIndex = 26;
			this->button_sin->Text = L"sin";
			this->button_sin->UseVisualStyleBackColor = false;
			this->button_sin->Click += gcnew System::EventHandler(this, &MyForm::button_sin_Click);
			// 
			// button_ans
			// 
			this->button_ans->BackColor = System::Drawing::Color::Chocolate;
			this->button_ans->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_ans->Location = System::Drawing::Point(13, 266);
			this->button_ans->Name = L"button_ans";
			this->button_ans->Size = System::Drawing::Size(80, 35);
			this->button_ans->TabIndex = 27;
			this->button_ans->Text = L"Ans";
			this->button_ans->UseVisualStyleBackColor = false;
			this->button_ans->Click += gcnew System::EventHandler(this, &MyForm::button_ans_Click);
			// 
			// button_e
			// 
			this->button_e->BackColor = System::Drawing::Color::Chocolate;
			this->button_e->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_e->Location = System::Drawing::Point(13, 227);
			this->button_e->Name = L"button_e";
			this->button_e->Size = System::Drawing::Size(80, 35);
			this->button_e->TabIndex = 28;
			this->button_e->Text = L"e";
			this->button_e->UseVisualStyleBackColor = false;
			this->button_e->Click += gcnew System::EventHandler(this, &MyForm::button_e_Click);
			// 
			// button_left
			// 
			this->button_left->BackColor = System::Drawing::Color::Chocolate;
			this->button_left->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_left->Location = System::Drawing::Point(271, 102);
			this->button_left->Name = L"button_left";
			this->button_left->Size = System::Drawing::Size(80, 35);
			this->button_left->TabIndex = 31;
			this->button_left->Text = L"(";
			this->button_left->UseVisualStyleBackColor = false;
			this->button_left->Click += gcnew System::EventHandler(this, &MyForm::button_left_Click);
			// 
			// button_right
			// 
			this->button_right->BackColor = System::Drawing::Color::Chocolate;
			this->button_right->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_right->Location = System::Drawing::Point(357, 102);
			this->button_right->Name = L"button_right";
			this->button_right->Size = System::Drawing::Size(80, 35);
			this->button_right->TabIndex = 32;
			this->button_right->Text = L")";
			this->button_right->UseVisualStyleBackColor = false;
			this->button_right->Click += gcnew System::EventHandler(this, &MyForm::button_right_Click);
			// 
			// button_p
			// 
			this->button_p->BackColor = System::Drawing::Color::Chocolate;
			this->button_p->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_p->Location = System::Drawing::Point(13, 186);
			this->button_p->Name = L"button_p";
			this->button_p->Size = System::Drawing::Size(80, 35);
			this->button_p->TabIndex = 39;
			this->button_p->Text = L"π";
			this->button_p->UseVisualStyleBackColor = false;
			this->button_p->Click += gcnew System::EventHandler(this, &MyForm::button_p_Click);
			// 
			// button_rad
			// 
			this->button_rad->BackColor = System::Drawing::Color::Chocolate;
			this->button_rad->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_rad->Location = System::Drawing::Point(13, 143);
			this->button_rad->Name = L"button_rad";
			this->button_rad->Size = System::Drawing::Size(80, 35);
			this->button_rad->TabIndex = 41;
			this->button_rad->Text = L"Rad";
			this->button_rad->UseVisualStyleBackColor = false;
			this->button_rad->Click += gcnew System::EventHandler(this, &MyForm::button_rad_Click);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::LightBlue;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(239, 28);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(370, 20);
			this->textBox3->TabIndex = 42;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// button_perc
			// 
			this->button_perc->BackColor = System::Drawing::Color::Chocolate;
			this->button_perc->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_perc->Location = System::Drawing::Point(443, 102);
			this->button_perc->Name = L"button_perc";
			this->button_perc->Size = System::Drawing::Size(80, 35);
			this->button_perc->TabIndex = 44;
			this->button_perc->Text = L"%";
			this->button_perc->UseVisualStyleBackColor = false;
			this->button_perc->Click += gcnew System::EventHandler(this, &MyForm::button_perc_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SandyBrown;
			this->ClientSize = System::Drawing::Size(627, 369);
			this->Controls->Add(this->button_perc);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button_rad);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button_p);
			this->Controls->Add(this->button_right);
			this->Controls->Add(this->button_left);
			this->Controls->Add(this->button_e);
			this->Controls->Add(this->button_ans);
			this->Controls->Add(this->button_sin);
			this->Controls->Add(this->button_cos);
			this->Controls->Add(this->button_tan);
			this->Controls->Add(this->button_inv);
			this->Controls->Add(this->button_fact);
			this->Controls->Add(this->button_ln);
			this->Controls->Add(this->button_log);
			this->Controls->Add(this->button_sqrt);
			this->Controls->Add(this->button_deg);
			this->Controls->Add(this->button_point);
			this->Controls->Add(this->button_go);
			this->Controls->Add(this->button_del);
			this->Controls->Add(this->button_umn);
			this->Controls->Add(this->button_minus);
			this->Controls->Add(this->button_plus);
			this->Controls->Add(this->button_AC);
			this->Controls->Add(this->button_0);
			this->Controls->Add(this->button_9);
			this->Controls->Add(this->button_8);
			this->Controls->Add(this->button_7);
			this->Controls->Add(this->button_6);
			this->Controls->Add(this->button_5);
			this->Controls->Add(this->button_4);
			this->Controls->Add(this->button_3);
			this->Controls->Add(this->button_2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button_1);
			this->MaximumSize = System::Drawing::Size(643, 408);
			this->MinimumSize = System::Drawing::Size(643, 408);
			this->Name = L"MyForm";
			this->Text = L"Калькулятор";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_1->Text;
		setStr(button_1->Text);
		setNumber(button_1->Text);
		textCheck();
	}
	private: System::Void button_2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_2->Text;
		setStr(button_2->Text);
		setNumber(button_2->Text);
		textCheck();
	}
	private: System::Void button_3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_3->Text;
		setStr(button_3->Text);
		setNumber(button_3->Text);
		textCheck();
	}
	private: System::Void button_4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_4->Text;
		setStr(button_4->Text);
		setNumber(button_4->Text);
		textCheck();
	}
	private: System::Void button_5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_5->Text;
		setStr(button_5->Text);
		setNumber(button_5->Text);
		textCheck();
	}
	private: System::Void button_6_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_6->Text;
		setStr(button_6->Text);
		setNumber(button_6->Text);
		textCheck();
	}
	private: System::Void button_7_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_7->Text;
		setStr(button_7->Text);
		setNumber(button_7->Text);
		textCheck();
	}
	private: System::Void button_8_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_8->Text;
		setStr(button_8->Text);
		setNumber(button_8->Text);
		textCheck();
	}
	private: System::Void button_9_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_9->Text;
		setStr(button_9->Text);
		setNumber(button_9->Text);
		textCheck();
	}
	private: System::Void button_0_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_0->Text;
		setStr(button_0->Text);
		setNumber(button_0->Text);
		textCheck();
	}
	private: System::Void button_AC_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 23, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		textBox1->Text = "0";
		textBox3->Text = "";
		clearStr();
		setStr("0");
		clearNumber();
		setNumber("0");
		
	}
	private: System::Void button_plus_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "ERROR") { textBox1->Text = "0"; clearStr(); }
		textBox1->Text = textBox1->Text + " " + button_plus->Text + " ";
		clearNumber();
		textCheck();
		setStr(" + ");
	}
	private: System::Void button_minus_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "ERROR") { textBox1->Text = "0"; clearStr(); }
		textBox1->Text = textBox1->Text + " " + button_minus->Text + " ";
		clearNumber();
		textCheck();
		setStr(" - ");
	}
	private: System::Void button_umn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "ERROR") { textBox1->Text = "0"; clearStr(); }
		textBox1->Text = textBox1->Text + " " + button_umn->Text + " ";
		clearNumber();
		textCheck();
		setStr(" * ");
	}
	private: System::Void button_del_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "ERROR") { textBox1->Text = "0"; clearStr(); }
		textBox1->Text = textBox1->Text + " " + button_del->Text + " ";
		clearNumber();
		textCheck();
		setStr(" / ");
	}
	//////////////////////////////////////////
	private: System::Void button_go_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 23, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		
		if (getStr() != "0" && getStr() != "ERROR" && getStr() != "A " && getStr() != "")
		{
			textBox3->Text = textBox1->Text + " = ";
			String^ str = go(strChange(MarshalString(getStr())).c_str());
			if (str == "ERROR")
			{
	
				textBox1->Text = "ERROR";
				setAns("0");
				clearStr();
				clearNumber();
			}
			else
			{
				
				textBox1->Text = str;
				setAns(textBox1->Text);
				clearStr();
				clearNumber();
				setStr("A ");
			}
		}
	}
	///////////////////////////////////////////
	private: System::Void button_point_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "ERROR") { textBox1->Text = "0"; clearStr(); }
		textBox1->Text = textBox1->Text + button_point->Text;
		setStr(button_point->Text);
		setNumber(button_point->Text);
		textCheck();
	}
	private: System::Void button_deg_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_deg->Text;
		clearNumber();
		textCheck();
		setStr(" ^ ");
	}
	private: System::Void button_sqrt_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_sqrt->Text + "(";
		clearNumber();
		textCheck();
		setStr(" v ( ");
	}
	private: System::Void button_log_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_log->Text + "(";
		clearNumber();
		textCheck();
		setStr(" q ( ");
	}
	private: System::Void button_ln_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		clearNumber();
		textCheck();
		textBox1->Text = textBox1->Text + button_ln->Text + "(";
		setStr(" l ( ");
	}
	private: System::Void button_fact_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_fact->Text;
		clearNumber();
		textCheck();
		setStr(" ! ");
	}
	private: System::Void button_inv_Click(System::Object^ sender, System::EventArgs^ e) {
		if (button_sin->Text == L"sin") { button_sin->Text = L"asin"; button_cos->Text = L"acos"; button_tan->Text = L"atan"; }
		else { button_sin->Text = L"sin"; button_cos->Text = L"cos"; button_tan->Text = L"tan"; }
	}
	private: System::Void button_tan_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_tan->Text + "(";
		if (button_tan->Text == "tan") setStr(" t ( ");
		else setStr(" d ( ");
		clearNumber();
		textCheck();
	}
	private: System::Void button_sin_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_sin->Text + "(";
		if (button_sin->Text == "sin") setStr(" s ( ");
		else setStr(" z ( ");
		clearNumber();
		textCheck();
	}
	private: System::Void button_cos_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_cos->Text + "(";
		if (button_cos->Text == "cos") setStr(" c ( ");
		else setStr(" g ( ");
		clearNumber();
		textCheck();
	}
	private: System::Void button_ans_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + " " + button_ans->Text + " ";
		if (getAns() == "0") textBox3->Text = "Ans = 0";
		setStr(" A ");
		clearNumber();
		textCheck();
	}
	private: System::Void button_e_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_e->Text;
		setStr(" e ");
		clearNumber();
		textCheck();
	}
	private: System::Void button_left_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_left->Text;
		setStr(" ( ");
		clearNumber();
		textCheck();
	}
	private: System::Void button_right_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_right->Text;
		setStr(" ) ");
		clearNumber();
		textCheck();
	}
	
	private: System::Void button_p_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "0" || textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_p->Text;
		setStr(" p ");
		clearNumber();
		textCheck();
	}
	private: System::Void button_rad_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox2->Text == L"Deg") 
		{	
			button_rad->Text = L"Deg";
			textBox2->Text = L"Rad";
			setRad(true);
			button_rad->BackColor = System::Drawing::Color::SaddleBrown;
		}
		else 
		{ 
			button_rad->Text = L"Rad";
			textBox2->Text = L"Deg"; 
			setRad(false);
			button_rad->BackColor = System::Drawing::Color::Chocolate;
		}
	}
	private: System::Void button_perc_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "ERROR") { textBox1->Text = ""; clearStr(); }
		textBox1->Text = textBox1->Text + button_perc->Text;
		setStr(" % ");
		clearNumber();
		textCheck();
	}
	void textCheck()
	{
		static int max = 24;
		static int k = 23;
		static int p = 12;
		string number = MarshalString(getNumber());
		if (number[0] == '.') number = "0" + number;
		if (number == "") number = "0";
		string str = MarshalString(textBox1->Text);
		if (max < 50 && number.length() < 17 && abs(stod(number)) < pow(2,32))
		{ 
			if (str.length() > max)
			{
				max = max + 4;
				k = k - 2;
				textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", k , System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				if (k % 3 == 0) --p;
				textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", p, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
			}
		}
		else
		{

			max = 22;
			k = 23;
			p = 12;
			textBox1->Text = "ERROR";
			clearStr();
			clearNumber();
			textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 23, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
		}
	}	
	string MarshalString(String^ s) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		string os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
		return os;
	}
	string toRound(double a) {
		string str = to_string(a);
		int k = 0;
		int p = 0;
		int i = str.find(".");
		if (i != -1)
		{
			for (i + 1; i < str.length(); i++)
			{
				if (str[i] = '0') k++;
				if (str[i] = '9') p++;
			}
			if (p > 3 || k > 3) return to_string(round(a));
		}
		else return str;
	}
	string strChange(string s) {
		while (s.find("  ") != -1) s.erase(s.find("  "), 1);
		if (s[0] == ' ') s.erase(0, 1);
		if (s[0] == '+') s.erase(0, 1);
		if (s[s.length() - 1] != ' ') s = s + " ";
		return s;
	}
	int Priority(char s) {
		switch (s) {
		case '(': return 0; break;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		case '^': return 3;
		case 's': case 'c': case 't': case 'q': case 'l': case 'g': case 'z': case 'd':  return 4; break;
		case '!': case 'v': case '%': return 5;
		default: break;
		}
	}
	list<string> toPostfix(string infix)
	{
		stack<string> a;
		bool unary = true;
		list<string> result;
		int j = 1;
		while (infix.size() != 0)
		{
			string s = infix.substr(0, infix.find(' '));
			infix.erase(0, infix.find(' ') + 1);
			if (((s == "-") || (s == "+")) && (unary == true))
			{
				if (s == "-") result.push_back("|");
			}
			else
				if (s == "A")
				{
					result.push_back(MarshalString(getAns()));
					unary = false;
				}
				else
					if ((s[0] >= '0') && (s[0] <= '9') || (s == "p") || (s == "e") || ((s != "-") && (s[0] == '-')))
					{
						result.push_back(s); 
						unary = false;
					}
					else
						if (s == "(") {
							a.push(s); unary = true;
						}
						else
						{
							unary = false;
							if (s == ")")
							{
								if (!a.empty())
								{
									string tmp = a.top();
									a.pop();
									int i = 0;
									while (tmp != "(" && result.back() != "ERROR")
									{
										result.push_back(tmp);
										if (!a.empty())
										{
											tmp = a.top();
											a.pop();
										}
										else result.push_back("ERROR");;
									}
								}
								else result.push_back("ERROR");
							}
							else
							{
								while (!a.empty() && Priority(a.top()[0]) >= Priority(s[0]))
									if (Priority(a.top()[0] != -1 && Priority(s[0]) != -1))
									{
										result.push_back(a.top());
										a.pop();
									}
									else result.push_back("ERROR");
								a.push(s);
							}
						}
		}
		while (!a.empty())
		{
			result.push_back(a.top());
			a.pop();
		}
		return(result);
	}

	string factorial(string s) {
		if (stod(s) == 0) return "1";
		double result = 1;
		for (int i = 2; i <= stod(s); i++) {
			result *= i;
			if (result > pow(2, 32)) return "ERROR";
		}
		return to_string(result);
	}

	double degtorad(string s) {
		return stod(s) * PI / 180;
	}
	double radtodeg(string s) {
		return stod(s) / PI * 180;
	}

	string doSimpleMath(char s, string a, string b) {
		switch (s) {
		case '+': return to_string(stod(a) + stod(b));
		case '-': return to_string(stod(a) - stod(b));
		case '*': return to_string(stod(a) * stod(b));
		case '/': return to_string(stod(a) / stod(b));
		case '^': return to_string(pow(stod(a), stod(b)));
		}
	}
	string doHardMath(char s, string a, bool rad) {
		switch (s) {
		case 'c':
			if (rad == false) return to_string(cos(degtorad(a)));
			else return to_string(cos(stod(a)));
		case 's':
			if (rad == false) return to_string(sin(degtorad(a)));
			else return to_string(sin(stod(a)));
		case 't':
			if (rad == false)
				if ((abs((int)stod(a)) - 90) % 180 == 0) return "ERROR";
				else return to_string(tan(degtorad(a)));
			else
				if ((abs((int)radtodeg(a)) - 90) % 180 == 0) return "ERROR";
				else return to_string(tan(stod(a)));
		case 'q':
			if (stod(a) < 0) return "ERROR";
			else return to_string(log10(stod(a)));
		case 'l':
			if (stod(a) < 0) return "ERROR";
			else return to_string(log(stod(a)));
		case '!':
			if (stod(a) != trunc(stod(a)) || stod(a) < 0) return "ERROR";
			else return factorial(a);
		case 'v':
			if (stod(a) < 0) return "ERROR";
			else return to_string(sqrt(stod(a)));
		case '%': return to_string((stod(a)) / 100);
		case 'g':
			if (stod(a) < -1 || stod(a) > 1) return "ERROR";
			else
				if (rad == false) return toRound(radtodeg(to_string(acos(stod(a)))));
				else return to_string(acos(stod(a)));
		case 'z':
			if (stod(a) < -1 || stod(a) > 1) return "ERROR";
			else
				if (rad == false) return toRound(radtodeg(to_string(asin(stod(a)))));
				else return to_string(asin(stod(a)));
		case 'd':
			if (rad == false)
				return toRound(radtodeg(to_string(atan(stod(a)))));
			else return to_string(atan(stod(a)));

		}
	}
	string toInfix(list<string>postfix) {
		stack<string> b;
		string result = "";
		bool rad = getRad();
		bool prov = false;
		bool unary = false;
		int j = 1;
		int k = 0;
		while (!postfix.empty()) {
			string tmp = postfix.front();
			postfix.pop_front();
			for (int i = 0; i < tmp.length(); i++) if (tmp[i] == '.') k++;
			if (k > 1) return "ERROR"; else k = 0;
			if (tmp == ".") return "ERROR";
			if (tmp == "p") b.push(to_string(PI));
			else
				if (tmp == "e") b.push(to_string(E));
				else
					if (tmp == "|") unary = true;
					else
						if ((tmp[0] >= '0' && tmp[0] <= '9') || ((tmp != "-") && (tmp[0] == '-')))
						{
							if (tmp[0] == '0' && tmp[1] != '.' && tmp != "0") return "ERROR";
							else
								if (unary == true)
								{
									b.push("-" + tmp);
									unary = false;
								}
								else b.push(tmp);
						}
						else
							if ((tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/" || tmp == "^") && !b.empty())
							{
								prov = true;
								string op2 = b.top();
								b.pop();
								if (!b.empty())
								{
									string op1 = b.top();
									b.pop();
									result = doSimpleMath(tmp[0], op1, op2);
									b.push(result);
								}
								else return "ERROR";
							}
							else
								if ((tmp == "c" || tmp == "s" || tmp == "t" || tmp == "l" || tmp == "q" || tmp == "g" || tmp == "z" || tmp == "d" || tmp == "!" || tmp == "%" || tmp == "v") && !b.empty())
								{
									prov = true;
									string op = b.top();
									b.pop();
									result = doHardMath(tmp[0], op, rad);
									if (result != "ERROR") b.push(result);
									else return "ERROR";
								}
								else return "ERROR";
		}
		string tmp = b.top();
		b.pop();
		if (!prov || !b.empty()) return "ERROR";
		if (stod(tmp) == -0) tmp = "0";
		return tmp;
	}
	String^ go(string S) {
		list<string> A;

		A = toPostfix(S);
		string str = toInfix(A);
		while (!A.empty()) A.pop_back();
		if (str != "ERROR")
		{
			while (str[str.length() - 1] == '0' && str != "0")
				str.erase(str.length() - 1, 1);
			if (str[str.length() - 1] == '.') str.erase(str.length() - 1, 1);
		}

		return gcnew String(str.c_str());
	}
};
}
