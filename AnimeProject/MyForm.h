#pragma once
#include "Header.h"
#include <msclr\marshal_cppstd.h>
#include <chrono>

//Citation: Program was built in CLR using 
//the tutorial found at youtube.com/watch?v=HcxlYkU8aY0
namespace AnimeProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	unordered_map<string, AnimeNode*> animeList;
	vector<User*> userList;
	vector<string> prevWatched;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			readPrevWatchedFile(&prevWatched);
			readAnimeFile(&animeList);
			readUserFile(&userList);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ ShowTypeDropDown;

	private: System::Windows::Forms::Label^ ShowTitleLabel;
	private: System::Windows::Forms::Label^ GenreLabel;
	private: System::Windows::Forms::Label^ StudioLabel;
	private: System::Windows::Forms::Label^ ReleaseDateLabel;
	private: System::Windows::Forms::Label^ ShowTypeLabel;
	private: System::Windows::Forms::ComboBox^ GenreDropDown;

	private: System::Windows::Forms::TextBox^ ShowTitleBox;
	private: System::Windows::Forms::TextBox^ StudioTitleBox;
	private: System::Windows::Forms::ComboBox^ comboBox3;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;


	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ GenreRating;
	private: System::Windows::Forms::ComboBox^ StudioRating;
	private: System::Windows::Forms::ComboBox^ DateRating;
	private: System::Windows::Forms::ComboBox^ TypeRating;





	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ BuildListButton;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ List1;
	private: System::Windows::Forms::Label^ List2;
	private: System::Windows::Forms::Label^ List3;
	private: System::Windows::Forms::Label^ List4;
	private: System::Windows::Forms::Label^ List5;
	private: System::Windows::Forms::Label^ List6;
	private: System::Windows::Forms::Label^ List7;
	private: System::Windows::Forms::Label^ List8;
	private: System::Windows::Forms::Label^ List9;
	private: System::Windows::Forms::Label^ List10;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::ComboBox^ DataType;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ TimeBox;
	private: System::Windows::Forms::Label^ MillisSecBox;
	private: System::Windows::Forms::CheckBox^ EnglishCheck;














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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ShowTypeDropDown = (gcnew System::Windows::Forms::ComboBox());
			this->ShowTitleLabel = (gcnew System::Windows::Forms::Label());
			this->GenreLabel = (gcnew System::Windows::Forms::Label());
			this->StudioLabel = (gcnew System::Windows::Forms::Label());
			this->ReleaseDateLabel = (gcnew System::Windows::Forms::Label());
			this->ShowTypeLabel = (gcnew System::Windows::Forms::Label());
			this->GenreDropDown = (gcnew System::Windows::Forms::ComboBox());
			this->ShowTitleBox = (gcnew System::Windows::Forms::TextBox());
			this->StudioTitleBox = (gcnew System::Windows::Forms::TextBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->GenreRating = (gcnew System::Windows::Forms::ComboBox());
			this->StudioRating = (gcnew System::Windows::Forms::ComboBox());
			this->DateRating = (gcnew System::Windows::Forms::ComboBox());
			this->TypeRating = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->BuildListButton = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->List1 = (gcnew System::Windows::Forms::Label());
			this->List2 = (gcnew System::Windows::Forms::Label());
			this->List3 = (gcnew System::Windows::Forms::Label());
			this->List4 = (gcnew System::Windows::Forms::Label());
			this->List5 = (gcnew System::Windows::Forms::Label());
			this->List6 = (gcnew System::Windows::Forms::Label());
			this->List7 = (gcnew System::Windows::Forms::Label());
			this->List8 = (gcnew System::Windows::Forms::Label());
			this->List9 = (gcnew System::Windows::Forms::Label());
			this->List10 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->DataType = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->TimeBox = (gcnew System::Windows::Forms::Label());
			this->MillisSecBox = (gcnew System::Windows::Forms::Label());
			this->EnglishCheck = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Impact", 27.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Maroon;
			this->label1->Location = System::Drawing::Point(176, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(277, 45);
			this->label1->TabIndex = 0;
			this->label1->Text = L"RECOMMEND.IME";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// ShowTypeDropDown
			// 
			this->ShowTypeDropDown->BackColor = System::Drawing::Color::Plum;
			this->ShowTypeDropDown->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ShowTypeDropDown->FormattingEnabled = true;
			this->ShowTypeDropDown->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"TV", L"Movie", L"Music", L"OVA", L"ONA",
					L"Special"
			});
			this->ShowTypeDropDown->Location = System::Drawing::Point(115, 330);
			this->ShowTypeDropDown->Name = L"ShowTypeDropDown";
			this->ShowTypeDropDown->Size = System::Drawing::Size(121, 23);
			this->ShowTypeDropDown->TabIndex = 1;
			this->ShowTypeDropDown->Text = L"Select Show Type";
			this->ShowTypeDropDown->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// ShowTitleLabel
			// 
			this->ShowTitleLabel->AutoSize = true;
			this->ShowTitleLabel->BackColor = System::Drawing::Color::Transparent;
			this->ShowTitleLabel->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ShowTitleLabel->ForeColor = System::Drawing::Color::DarkRed;
			this->ShowTitleLabel->Location = System::Drawing::Point(15, 138);
			this->ShowTitleLabel->Name = L"ShowTitleLabel";
			this->ShowTitleLabel->Size = System::Drawing::Size(77, 20);
			this->ShowTitleLabel->TabIndex = 2;
			this->ShowTitleLabel->Text = L"Show Title:";
			// 
			// GenreLabel
			// 
			this->GenreLabel->AutoSize = true;
			this->GenreLabel->BackColor = System::Drawing::Color::Transparent;
			this->GenreLabel->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GenreLabel->ForeColor = System::Drawing::Color::Brown;
			this->GenreLabel->Location = System::Drawing::Point(15, 183);
			this->GenreLabel->Name = L"GenreLabel";
			this->GenreLabel->Size = System::Drawing::Size(51, 20);
			this->GenreLabel->TabIndex = 3;
			this->GenreLabel->Text = L"Genre:";
			// 
			// StudioLabel
			// 
			this->StudioLabel->AutoSize = true;
			this->StudioLabel->BackColor = System::Drawing::Color::Transparent;
			this->StudioLabel->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StudioLabel->ForeColor = System::Drawing::Color::Firebrick;
			this->StudioLabel->Location = System::Drawing::Point(15, 235);
			this->StudioLabel->Name = L"StudioLabel";
			this->StudioLabel->Size = System::Drawing::Size(53, 20);
			this->StudioLabel->TabIndex = 4;
			this->StudioLabel->Text = L"Studio:";
			// 
			// ReleaseDateLabel
			// 
			this->ReleaseDateLabel->AutoSize = true;
			this->ReleaseDateLabel->BackColor = System::Drawing::Color::Transparent;
			this->ReleaseDateLabel->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ReleaseDateLabel->ForeColor = System::Drawing::Color::IndianRed;
			this->ReleaseDateLabel->Location = System::Drawing::Point(15, 283);
			this->ReleaseDateLabel->Name = L"ReleaseDateLabel";
			this->ReleaseDateLabel->Size = System::Drawing::Size(98, 20);
			this->ReleaseDateLabel->TabIndex = 5;
			this->ReleaseDateLabel->Text = L"Release Date:";
			// 
			// ShowTypeLabel
			// 
			this->ShowTypeLabel->AutoSize = true;
			this->ShowTypeLabel->BackColor = System::Drawing::Color::Transparent;
			this->ShowTypeLabel->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ShowTypeLabel->ForeColor = System::Drawing::Color::Salmon;
			this->ShowTypeLabel->Location = System::Drawing::Point(15, 331);
			this->ShowTypeLabel->Name = L"ShowTypeLabel";
			this->ShowTypeLabel->Size = System::Drawing::Size(79, 20);
			this->ShowTypeLabel->TabIndex = 6;
			this->ShowTypeLabel->Text = L"Show Type:";
			// 
			// GenreDropDown
			// 
			this->GenreDropDown->BackColor = System::Drawing::Color::Plum;
			this->GenreDropDown->DisplayMember = L"Fantasy";
			this->GenreDropDown->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GenreDropDown->ForeColor = System::Drawing::Color::Black;
			this->GenreDropDown->FormattingEnabled = true;
			this->GenreDropDown->Items->AddRange(gcnew cli::array< System::Object^  >(15) {
				L"Comedy", L"Supernatural ", L"Romance", L"Shounen",
					L"Parody", L"Seinen", L"Drama", L"Slice of Life", L"School", L"Game", L"Josei", L"Adventure", L"Action", L"Sci-Fi", L"Ecchi"
			});
			this->GenreDropDown->Location = System::Drawing::Point(115, 182);
			this->GenreDropDown->Name = L"GenreDropDown";
			this->GenreDropDown->Size = System::Drawing::Size(121, 23);
			this->GenreDropDown->TabIndex = 7;
			this->GenreDropDown->Text = L"Select Genre";
			this->GenreDropDown->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::GenreDropDown_SelectedIndexChanged);
			// 
			// ShowTitleBox
			// 
			this->ShowTitleBox->BackColor = System::Drawing::Color::Plum;
			this->ShowTitleBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ShowTitleBox->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ShowTitleBox->ForeColor = System::Drawing::Color::Black;
			this->ShowTitleBox->Location = System::Drawing::Point(115, 138);
			this->ShowTitleBox->Name = L"ShowTitleBox";
			this->ShowTitleBox->Size = System::Drawing::Size(97, 21);
			this->ShowTitleBox->TabIndex = 8;
			this->ShowTitleBox->TextChanged += gcnew System::EventHandler(this, &MyForm::ShowTitleBox_TextChanged);
			// 
			// StudioTitleBox
			// 
			this->StudioTitleBox->BackColor = System::Drawing::Color::Plum;
			this->StudioTitleBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->StudioTitleBox->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StudioTitleBox->Location = System::Drawing::Point(115, 235);
			this->StudioTitleBox->Name = L"StudioTitleBox";
			this->StudioTitleBox->Size = System::Drawing::Size(97, 21);
			this->StudioTitleBox->TabIndex = 9;
			// 
			// comboBox3
			// 
			this->comboBox3->BackColor = System::Drawing::Color::Plum;
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Spring", L"Summer", L"Fall", L"Winter" });
			this->comboBox3->Location = System::Drawing::Point(115, 281);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(62, 23);
			this->comboBox3->TabIndex = 10;
			this->comboBox3->Text = L"Season";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Maroon;
			this->label2->Location = System::Drawing::Point(15, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(300, 20);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Enter Terms to Assist with Recommendations";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Maroon;
			this->label3->Location = System::Drawing::Point(22, 406);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 20);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Data Structure:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Maroon;
			this->label4->Location = System::Drawing::Point(416, 92);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(121, 20);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Rank Importance";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::DarkRed;
			this->label6->Location = System::Drawing::Point(310, 154);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 20);
			this->label6->TabIndex = 18;
			this->label6->Text = L"Genre:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Brown;
			this->label7->Location = System::Drawing::Point(310, 206);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(53, 20);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Studio:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Firebrick;
			this->label8->Location = System::Drawing::Point(310, 254);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(98, 20);
			this->label8->TabIndex = 20;
			this->label8->Text = L"Release Date:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::IndianRed;
			this->label9->Location = System::Drawing::Point(310, 302);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(79, 20);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Show Type:";
			// 
			// GenreRating
			// 
			this->GenreRating->BackColor = System::Drawing::Color::Plum;
			this->GenreRating->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GenreRating->FormattingEnabled = true;
			this->GenreRating->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"0 - no preference", L"1", L"2", L"3", L"4" });
			this->GenreRating->Location = System::Drawing::Point(420, 154);
			this->GenreRating->Name = L"GenreRating";
			this->GenreRating->Size = System::Drawing::Size(121, 23);
			this->GenreRating->TabIndex = 23;
			this->GenreRating->Text = L"Rating 1-4";
			// 
			// StudioRating
			// 
			this->StudioRating->BackColor = System::Drawing::Color::Plum;
			this->StudioRating->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StudioRating->FormattingEnabled = true;
			this->StudioRating->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"0 - no preference", L"1", L"2", L"3", L"4" });
			this->StudioRating->Location = System::Drawing::Point(420, 209);
			this->StudioRating->Name = L"StudioRating";
			this->StudioRating->Size = System::Drawing::Size(121, 23);
			this->StudioRating->TabIndex = 24;
			this->StudioRating->Text = L"Rating 1-4";
			// 
			// DateRating
			// 
			this->DateRating->BackColor = System::Drawing::Color::Plum;
			this->DateRating->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DateRating->FormattingEnabled = true;
			this->DateRating->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"0 - no preference", L"1", L"2", L"3", L"4" });
			this->DateRating->Location = System::Drawing::Point(420, 253);
			this->DateRating->Name = L"DateRating";
			this->DateRating->Size = System::Drawing::Size(121, 23);
			this->DateRating->TabIndex = 25;
			this->DateRating->Text = L"Rating 1-4";
			// 
			// TypeRating
			// 
			this->TypeRating->BackColor = System::Drawing::Color::Plum;
			this->TypeRating->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TypeRating->FormattingEnabled = true;
			this->TypeRating->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"0 - no preference", L"1", L"2", L"3", L"4" });
			this->TypeRating->Location = System::Drawing::Point(420, 302);
			this->TypeRating->Name = L"TypeRating";
			this->TypeRating->Size = System::Drawing::Size(121, 23);
			this->TypeRating->TabIndex = 26;
			this->TypeRating->Text = L"Rating 1-4";
			this->TypeRating->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::TypeRating_SelectedIndexChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Maroon;
			this->label10->Location = System::Drawing::Point(293, 381);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(228, 20);
			this->label10->TabIndex = 27;
			this->label10->Text = L"Add Shows You Have Already Seen:";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Plum;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox1->Location = System::Drawing::Point(297, 409);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(102, 21);
			this->textBox1->TabIndex = 28;
			this->textBox1->Text = L"Enter Show";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Impact", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::MediumSlateBlue;
			this->button1->Location = System::Drawing::Point(430, 409);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(60, 23);
			this->button1->TabIndex = 29;
			this->button1->Text = L"ADD";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// BuildListButton
			// 
			this->BuildListButton->BackColor = System::Drawing::Color::LightCyan;
			this->BuildListButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->BuildListButton->Font = (gcnew System::Drawing::Font(L"Impact", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BuildListButton->ForeColor = System::Drawing::Color::Firebrick;
			this->BuildListButton->Location = System::Drawing::Point(170, 460);
			this->BuildListButton->Name = L"BuildListButton";
			this->BuildListButton->Size = System::Drawing::Size(215, 58);
			this->BuildListButton->TabIndex = 30;
			this->BuildListButton->Text = L"BUILD MY LIST!";
			this->BuildListButton->UseVisualStyleBackColor = false;
			this->BuildListButton->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Impact", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Chocolate;
			this->label11->Location = System::Drawing::Point(601, 49);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(243, 37);
			this->label11->TabIndex = 32;
			this->label11->Text = L"WATCH THESE NEXT:";
			this->label11->Click += gcnew System::EventHandler(this, &MyForm::label11_Click);
			// 
			// List1
			// 
			this->List1->AutoSize = true;
			this->List1->BackColor = System::Drawing::Color::Transparent;
			this->List1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->List1->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->List1->Location = System::Drawing::Point(622, 115);
			this->List1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->List1->Name = L"List1";
			this->List1->Size = System::Drawing::Size(26, 25);
			this->List1->TabIndex = 33;
			this->List1->Text = L"1. ";
			// 
			// List2
			// 
			this->List2->AutoSize = true;
			this->List2->BackColor = System::Drawing::Color::Transparent;
			this->List2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->List2->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->List2->Location = System::Drawing::Point(622, 157);
			this->List2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->List2->Name = L"List2";
			this->List2->Size = System::Drawing::Size(26, 25);
			this->List2->TabIndex = 34;
			this->List2->Text = L"2.";
			// 
			// List3
			// 
			this->List3->AutoSize = true;
			this->List3->BackColor = System::Drawing::Color::Transparent;
			this->List3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->List3->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->List3->Location = System::Drawing::Point(622, 200);
			this->List3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->List3->Name = L"List3";
			this->List3->Size = System::Drawing::Size(26, 25);
			this->List3->TabIndex = 35;
			this->List3->Text = L"3.";
			// 
			// List4
			// 
			this->List4->AutoSize = true;
			this->List4->BackColor = System::Drawing::Color::Transparent;
			this->List4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->List4->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->List4->Location = System::Drawing::Point(622, 244);
			this->List4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->List4->Name = L"List4";
			this->List4->Size = System::Drawing::Size(28, 25);
			this->List4->TabIndex = 36;
			this->List4->Text = L"4. ";
			// 
			// List5
			// 
			this->List5->AutoSize = true;
			this->List5->BackColor = System::Drawing::Color::Transparent;
			this->List5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->List5->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->List5->Location = System::Drawing::Point(622, 286);
			this->List5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->List5->Name = L"List5";
			this->List5->Size = System::Drawing::Size(26, 25);
			this->List5->TabIndex = 37;
			this->List5->Text = L"5.";
			// 
			// List6
			// 
			this->List6->AutoSize = true;
			this->List6->BackColor = System::Drawing::Color::Transparent;
			this->List6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->List6->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->List6->Location = System::Drawing::Point(622, 326);
			this->List6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->List6->Name = L"List6";
			this->List6->Size = System::Drawing::Size(26, 25);
			this->List6->TabIndex = 38;
			this->List6->Text = L"6.";
			// 
			// List7
			// 
			this->List7->AutoSize = true;
			this->List7->BackColor = System::Drawing::Color::Transparent;
			this->List7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->List7->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->List7->Location = System::Drawing::Point(622, 366);
			this->List7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->List7->Name = L"List7";
			this->List7->Size = System::Drawing::Size(23, 25);
			this->List7->TabIndex = 39;
			this->List7->Text = L"7.";
			// 
			// List8
			// 
			this->List8->AutoSize = true;
			this->List8->BackColor = System::Drawing::Color::Transparent;
			this->List8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->List8->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->List8->Location = System::Drawing::Point(622, 403);
			this->List8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->List8->Name = L"List8";
			this->List8->Size = System::Drawing::Size(26, 25);
			this->List8->TabIndex = 40;
			this->List8->Text = L"8.";
			this->List8->Click += gcnew System::EventHandler(this, &MyForm::label17_Click);
			// 
			// List9
			// 
			this->List9->AutoSize = true;
			this->List9->BackColor = System::Drawing::Color::Transparent;
			this->List9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->List9->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->List9->Location = System::Drawing::Point(622, 442);
			this->List9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->List9->Name = L"List9";
			this->List9->Size = System::Drawing::Size(26, 25);
			this->List9->TabIndex = 41;
			this->List9->Text = L"9.";
			// 
			// List10
			// 
			this->List10->AutoSize = true;
			this->List10->BackColor = System::Drawing::Color::Transparent;
			this->List10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->List10->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->List10->Location = System::Drawing::Point(622, 479);
			this->List10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->List10->Name = L"List10";
			this->List10->Size = System::Drawing::Size(33, 25);
			this->List10->TabIndex = 42;
			this->List10->Text = L"10.";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::Plum;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::Black;
			this->textBox2->Location = System::Drawing::Point(183, 281);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(42, 21);
			this->textBox2->TabIndex = 43;
			this->textBox2->Text = L"Year";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// DataType
			// 
			this->DataType->BackColor = System::Drawing::Color::Plum;
			this->DataType->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DataType->FormattingEnabled = true;
			this->DataType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Tree", L"Heap" });
			this->DataType->Location = System::Drawing::Point(135, 403);
			this->DataType->Name = L"DataType";
			this->DataType->Size = System::Drawing::Size(90, 23);
			this->DataType->TabIndex = 44;
			this->DataType->Text = L"Select Data";
			this->DataType->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged_1);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button2->Font = (gcnew System::Drawing::Font(L"Impact", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::MediumSlateBlue;
			this->button2->Location = System::Drawing::Point(496, 409);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(60, 23);
			this->button2->TabIndex = 45;
			this->button2->Text = L"REMOVE";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// TimeBox
			// 
			this->TimeBox->AutoSize = true;
			this->TimeBox->BackColor = System::Drawing::Color::Transparent;
			this->TimeBox->Font = (gcnew System::Drawing::Font(L"Impact", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TimeBox->Location = System::Drawing::Point(689, 513);
			this->TimeBox->Name = L"TimeBox";
			this->TimeBox->Size = System::Drawing::Size(121, 16);
			this->TimeBox->TabIndex = 46;
			this->TimeBox->Text = L"Time To Compute (ms): ";
			// 
			// MillisSecBox
			// 
			this->MillisSecBox->AutoSize = true;
			this->MillisSecBox->BackColor = System::Drawing::Color::Transparent;
			this->MillisSecBox->Font = (gcnew System::Drawing::Font(L"Impact", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MillisSecBox->Location = System::Drawing::Point(816, 513);
			this->MillisSecBox->Name = L"MillisSecBox";
			this->MillisSecBox->Size = System::Drawing::Size(15, 17);
			this->MillisSecBox->TabIndex = 47;
			this->MillisSecBox->Text = L"0";
			// 
			// EnglishCheck
			// 
			this->EnglishCheck->AutoSize = true;
			this->EnglishCheck->BackColor = System::Drawing::Color::Transparent;
			this->EnglishCheck->Font = (gcnew System::Drawing::Font(L"Impact", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EnglishCheck->ForeColor = System::Drawing::Color::Firebrick;
			this->EnglishCheck->Location = System::Drawing::Point(850, 65);
			this->EnglishCheck->Name = L"EnglishCheck";
			this->EnglishCheck->Size = System::Drawing::Size(96, 21);
			this->EnglishCheck->TabIndex = 48;
			this->EnglishCheck->Text = L"View English";
			this->EnglishCheck->UseVisualStyleBackColor = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(984, 561);
			this->Controls->Add(this->EnglishCheck);
			this->Controls->Add(this->MillisSecBox);
			this->Controls->Add(this->TimeBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->DataType);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->List10);
			this->Controls->Add(this->List9);
			this->Controls->Add(this->List8);
			this->Controls->Add(this->List7);
			this->Controls->Add(this->List6);
			this->Controls->Add(this->List5);
			this->Controls->Add(this->List4);
			this->Controls->Add(this->List3);
			this->Controls->Add(this->List2);
			this->Controls->Add(this->List1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->BuildListButton);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->TypeRating);
			this->Controls->Add(this->DateRating);
			this->Controls->Add(this->StudioRating);
			this->Controls->Add(this->GenreRating);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->StudioTitleBox);
			this->Controls->Add(this->ShowTitleBox);
			this->Controls->Add(this->GenreDropDown);
			this->Controls->Add(this->ShowTypeLabel);
			this->Controls->Add(this->ReleaseDateLabel);
			this->Controls->Add(this->StudioLabel);
			this->Controls->Add(this->GenreLabel);
			this->Controls->Add(this->ShowTitleLabel);
			this->Controls->Add(this->ShowTypeDropDown);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Recommend.ime";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void ShowTitleBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	bool showEnglish;
	if (EnglishCheck->Checked == true) {
		showEnglish = false;
	}
	else if (EnglishCheck->Checked == false) {
		showEnglish = true;
	}
	String^ title = ShowTitleBox -> Text;
	String^ studio = StudioTitleBox->Text;
	String^ genre = GenreDropDown->Text;
	String^ date = comboBox3->Text + " " + textBox2->Text;
	String^ type = ShowTypeDropDown->Text;
	String^ rating1 = GenreRating->Text;
	if (rating1 == "0 - no preference" || rating1 == "Rating 1-4") {
		rating1 = "0";
	}
	String^ rating2 = StudioRating->Text;
	if (rating2 == "0 - no preference" || rating2 == "Rating 1-4") {
		rating2 = "0";
	}
	String^ rating3 = DateRating->Text;
	if (rating3 == "0 - no preference" || rating3 == "Rating 1-4") {
		rating3 = "0";
	}
	String^ rating4 = TypeRating->Text;
	if (rating4 == "0 - no preference" || rating4 == "Rating 1-4") {
		rating4 = "0";
	}

	bool tree_dataType =  false;
	bool heap_dateType = false;
	if (DataType->Text == "Tree") {
		tree_dataType = true;
		heap_dateType = false;
	}
	else if (DataType->Text == "Heap") {
		tree_dataType = false;
		heap_dateType = true;
	}
	else {
		List1->Text = "Please enter in a data structure";
		List2->Text = "";
		List3->Text = "";
		List4->Text = "";
		List5->Text = "";
		List6->Text = "";
		List7->Text = "";
		List8->Text = "";
		List9->Text = "";
		List10->Text = "";
	}

	//converts input from String ^ to string

	std::string str_title = msclr::interop::marshal_as<std::string>(title);
	std::string str_studio = msclr::interop::marshal_as<std::string>(studio);
	std::string str_genre = msclr::interop::marshal_as<std::string>(genre);
	std::string str_date = msclr::interop::marshal_as<std::string>(date);
	std::string str_type = msclr::interop::marshal_as<std::string>(type);
	std::string str_rat1 = msclr::interop::marshal_as<std::string>(rating1);
	std::string str_rat2 = msclr::interop::marshal_as<std::string>(rating2);
	std::string str_rat3 = msclr::interop::marshal_as<std::string>(rating3);
	std::string str_rat4 = msclr::interop::marshal_as<std::string>(rating4);

	int int_rate1 = stoi(str_rat1);
	int int_rate2 = stoi(str_rat2);
	int int_rate3 = stoi(str_rat3);
	int int_rate4 = stoi(str_rat4);

	if (heap_dateType == true || tree_dataType == true) {
		if (title == "") {
			List1->Text = "Please enter in a title";
			List2->Text = "";
			List3->Text = "";
			List4->Text = "";
			List5->Text = "";
			List6->Text = "";
			List7->Text = "";
			List8->Text = "";
			List9->Text = "";
			List10->Text = "";
		}
		//get top 10
		else {
			unordered_map<string, double> recommendations = recommendationForInput(str_title, &animeList, &userList, &prevWatched);
			
			//start timer
			std::clock_t    start;
			start = std::clock();
			


			recommendations = adjustRecommendations(&recommendations, &animeList, str_type, str_genre, str_studio, str_date, int_rate4, int_rate1, int_rate2, int_rate3);
			if (recommendations.size() < 1) {
				List1->Text = "Title not found";
				List2->Text = "";
				List3->Text = "";
				List4->Text = "";
				List5->Text = "";
				List6->Text = "";
				List7->Text = "";
				List8->Text = "";
				List9->Text = "";
				List10->Text = "";
			}
			else if (heap_dateType == true) {
				MinHeap* heap = new MinHeap();
				heap = generateRecommendHeap(&recommendations, &animeList);
				vector<AnimeNode*> outputVect = heap->outputSortedList();
				//std::map<double, AnimeNode*> topTenMap = generateRecommendHeap(&recommendations, &animeList);
				//auto it = topTenMap.end();
				//it--;
				List1->Text = "1. " + gcnew String(outputVect[0]->getName(showEnglish).c_str());
				//it--;
				List2->Text = "2. " + gcnew String(outputVect[1]->getName(showEnglish).c_str());
				//it--;
				List3->Text = "3. " + gcnew String(outputVect[2]->getName(showEnglish).c_str());
				//it--;
				List4->Text = "4. " + gcnew String(outputVect[3]->getName(showEnglish).c_str());
				//it--;
				List5->Text = "5. " + gcnew String(outputVect[4]->getName(showEnglish).c_str());
				//it--;
				List6->Text = "6. " + gcnew String(outputVect[5]->getName(showEnglish).c_str());
				//it--;
				List7->Text = "7. " + gcnew String(outputVect[6]->getName(showEnglish).c_str());
				//it--;
				List8->Text = "8. " + gcnew String(outputVect[7]->getName(showEnglish).c_str());
				//it--;
				List9->Text = "9. " + gcnew String(outputVect[8]->getName(showEnglish).c_str());
				//it--;
				List10->Text = "10. " + gcnew String(outputVect[9]->getName(showEnglish).c_str());
				//it--;
				//topTenMap.clear();
				
				//end timer
				int time = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
				std::string str_time = std::to_string(time);
				MillisSecBox->Text = gcnew String(str_time.c_str());

			}

			else if (tree_dataType == true) {
				BinarySearchTree* tree = new BinarySearchTree();
				tree = generateRecommendTree(&recommendations, &animeList);


				queue<AnimeNode*> q = tree->generateTopTen();
				List1->Text = "1. " + gcnew String(q.front()->getName(showEnglish).c_str());
				q.pop();
				List2->Text = "2. " + gcnew String(q.front()->getName(showEnglish).c_str());
				q.pop();
				List3->Text = "3. " + gcnew String(q.front()->getName(showEnglish).c_str());
				q.pop();
				List4->Text = "4. " + gcnew String(q.front()->getName(showEnglish).c_str());
				q.pop();
				List5->Text = "5. " + gcnew String(q.front()->getName(showEnglish).c_str());
				q.pop();
				List6->Text = "6. " + gcnew String(q.front()->getName(showEnglish).c_str());
				q.pop();
				List7->Text = "7. " + gcnew String(q.front()->getName(showEnglish).c_str());
				q.pop();
				List8->Text = "8. " + gcnew String(q.front()->getName(showEnglish).c_str());
				q.pop();
				List9->Text = "9. " + gcnew String(q.front()->getName(showEnglish).c_str());
				q.pop();
				List10->Text = "10. " + gcnew String(q.front()->getName(showEnglish).c_str());
				while (!q.empty()) {
					q.pop();
				}

			//end timer
				int time = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
				std::string str_time = std::to_string(time);
				MillisSecBox->Text = gcnew String(str_time.c_str());
				
			}
		}
	}

	
	

	
	





	





}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label17_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void GenreDropDown_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {


}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void comboBox1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ input = textBox1->Text;
	std::string str_input = msclr::interop::marshal_as<std::string>(input);
	string value = findID(str_input, &animeList);
	if (value != "") {
		writePrevWatchedFile(&prevWatched, value, true);
		textBox1->Text = "Success!";
	}
	else {
		textBox1->Text = "Not Found...";
	}
}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	String^ input = textBox1->Text;
	std::string str_input = msclr::interop::marshal_as<std::string>(input);
	string value = findID(str_input, &animeList);
	if (value != "") {
		writePrevWatchedFile(&prevWatched, value, false);
		textBox1->Text = "Removed!";
	}
	else {
		textBox1->Text = "Not Found...";
	}
}
private: System::Void TypeRating_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
