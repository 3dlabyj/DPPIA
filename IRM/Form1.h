#pragma once

namespace IRM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;

	DWORD t1, t2;

	int PictureNum = 0;
	char FilesName[1000][1000];

	int m = 0;

	char buff[20];
	std::string Asbuff;

	int H_Min = 80;
	int H_Max = 160;
	int diff_Gate = 50;
	int minarea = 600;
	int S_Gate = 10;

	IplImage *comparedImg; //對比圖
	IplImage *comparedImg_Plant; //差異圖
	IplImage *comparedImg_Plant_Ab;
	IplImage *InputImg; //輸入圖
	IplImage *DiffImg; //差異圖
	IplImage *DiffImg_Edge;
	IplImage *FinalImg;
	IplImage *tmp;

	
	
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* contour = 0;
	
	int * differencePoint;
	int state = 0 ;

	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	protected: 









	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::PictureBox^  pictureBox3;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;








	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Label^  labTime;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  labError;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;




	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->labTime = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->labError = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->InitialDirectory = L"C:\\Users\\Wunpig\\Desktop\\TestPic\\Demo";
			this->openFileDialog1->Multiselect = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"標楷體", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(498, 8);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(143, 32);
			this->label4->TabIndex = 24;
			this->label4->Text = L"輸入影像";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox3->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox3->Location = System::Drawing::Point(504, 43);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(480, 270);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 23;
			this->pictureBox3->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"標楷體", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(10, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 32);
			this->label1->TabIndex = 20;
			this->label1->Text = L"對比影像";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(16, 43);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(480, 270);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 19;
			this->pictureBox1->TabStop = false;
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 27;
			this->listBox1->Location = System::Drawing::Point(1018, 43);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(169, 166);
			this->listBox1->TabIndex = 39;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"標楷體", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(1018, 226);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(169, 43);
			this->button1->TabIndex = 38;
			this->button1->Text = L"開始";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// labTime
			// 
			this->labTime->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labTime->AutoSize = true;
			this->labTime->Font = (gcnew System::Drawing::Font(L"標楷體", 24));
			this->labTime->Location = System::Drawing::Point(1012, 281);
			this->labTime->Name = L"labTime";
			this->labTime->Size = System::Drawing::Size(111, 32);
			this->labTime->TabIndex = 47;
			this->labTime->Text = L"時間：";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"標楷體", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(1000, 349);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(239, 32);
			this->label5->TabIndex = 55;
			this->label5->Text = L"異常判定結果：";
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox5->Location = System::Drawing::Point(1006, 386);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(480, 270);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 54;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &Form1::pictureBox5_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"標楷體", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(498, 349);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(207, 32);
			this->label3->TabIndex = 52;
			this->label3->Text = L"兩者差異影像";
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox4->Location = System::Drawing::Point(504, 386);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(480, 270);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 51;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &Form1::pictureBox4_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"標楷體", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(10, 349);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(303, 32);
			this->label2->TabIndex = 49;
			this->label2->Text = L"對比影像之植栽區域";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Location = System::Drawing::Point(16, 386);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(480, 270);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 48;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Form1::pictureBox2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->BackColor = System::Drawing::SystemColors::Info;
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"標楷體", 18));
			this->groupBox1->Location = System::Drawing::Point(1193, 43);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(293, 270);
			this->groupBox1->TabIndex = 58;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"參數調整";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"標楷體", 18));
			this->button2->Location = System::Drawing::Point(23, 211);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(227, 40);
			this->button2->TabIndex = 58;
			this->button2->Text = L"參數更新";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"標楷體", 13));
			this->textBox4->Location = System::Drawing::Point(160, 177);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(90, 28);
			this->textBox4->TabIndex = 66;
			this->textBox4->Text = L"500";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"標楷體", 13));
			this->textBox1->Location = System::Drawing::Point(160, 38);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(90, 28);
			this->textBox1->TabIndex = 59;
			this->textBox1->Text = L"150";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"標楷體", 16));
			this->label9->Location = System::Drawing::Point(19, 183);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(142, 22);
			this->label9->TabIndex = 65;
			this->label9->Text = L"面積門檻值：";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"標楷體", 16));
			this->label6->Location = System::Drawing::Point(19, 44);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(142, 22);
			this->label6->TabIndex = 60;
			this->label6->Text = L"色調值上限：";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"標楷體", 13));
			this->textBox2->Location = System::Drawing::Point(160, 81);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(90, 28);
			this->textBox2->TabIndex = 61;
			this->textBox2->Text = L"90";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"標楷體", 16));
			this->label7->Location = System::Drawing::Point(19, 87);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(142, 22);
			this->label7->TabIndex = 62;
			this->label7->Text = L"色調值下限：";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"標楷體", 13));
			this->textBox3->Location = System::Drawing::Point(160, 128);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(90, 28);
			this->textBox3->TabIndex = 63;
			this->textBox3->Text = L"20";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"標楷體", 16));
			this->label8->Location = System::Drawing::Point(19, 134);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(142, 22);
			this->label8->TabIndex = 64;
			this->label8->Text = L"差異門檻值：";
			// 
			// labError
			// 
			this->labError->AutoSize = true;
			this->labError->Font = (gcnew System::Drawing::Font(L"標楷體", 24));
			this->labError->Location = System::Drawing::Point(1226, 349);
			this->labError->Name = L"labError";
			this->labError->Size = System::Drawing::Size(79, 32);
			this->labError->TabIndex = 59;
			this->labError->Text = L"　　";
			// 
			// timer1
			// 
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1520, 701);
			this->Controls->Add(this->labError);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->labTime);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"植栽災害辨識模組";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if(openFileDialog1->ShowDialog()==System::Windows::Forms::DialogResult::OK)
				 {
					 if(PictureNum !=0)
					 {
						PictureNum = 0;
						this->listBox1->Items->Clear();
						delete [] differencePoint;
					 }
					 

					 //讀取影像路徑
					 for each(String^ file in openFileDialog1->FileNames)
					 {						 
						 sprintf(FilesName[PictureNum], "%s",  file);
						 String^ fileName = Path::GetFileNameWithoutExtension(file);
						 this->listBox1->Items->Add(fileName);
						 PictureNum++;
					 }				 

					 t1 = GetTickCount();
				 
					 //讀取第一張圖為背景圖
					 comparedImg = cvLoadImage(FilesName[0]);

					 differencePoint = new int[comparedImg->imageSize];

					 cutPlantandComparing(comparedImg,0);

					 //其餘為比較圖
					 if (PictureNum > 1)
					 {
						 InputImg = cvLoadImage(FilesName[1]);
						 cutPlantandComparing(InputImg,1);

						 pictureBox3->Image  = gcnew System::Drawing::Bitmap
						 (InputImg->width,InputImg->height,InputImg->widthStep,
						 System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) InputImg->imageData);
						 pictureBox3->Refresh();

						 listBox1->SelectedIndex = 1;
					 }
					 
					 pictureBox1->Image  = gcnew System::Drawing::Bitmap
						 (comparedImg->width,comparedImg->height,comparedImg->widthStep,
						 System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) comparedImg->imageData);
					 pictureBox1->Refresh();

					 

					 float time = (float)t2 -t1;
					 
					 labTime->Text = "執行時間：﹝" + Convert::ToString(time) +"ms﹞";
				 }
			 }
		
			 private: Void cutPlantandComparing(IplImage *src,int mode)
			 {
				 if(mode == 1){t1 = GetTickCount();}

				 IplImage  *Proces = cvCloneImage(src);
				 DiffImg = cvCreateImage(cvGetSize(comparedImg),IPL_DEPTH_8U,3);
				 cvSet(DiffImg, cvScalar(255,255,255));

				 uchar Blue , Green , Red;

				 for (int i = 0 ; i < Proces->height ; i++)
				 {
					 for (int j = 0 ; j < Proces->widthStep ; j = j + 3)
					 {
						 Blue = Proces->imageData[i*Proces->widthStep+j];
						 Green = Proces->imageData[i*Proces->widthStep+j+1];
						 Red = Proces->imageData[i*Proces->widthStep+j+2];

						 double H , S ;
						 double V;

						 uchar var_Min = min(Blue,Green);
						 var_Min = min(var_Min,Red);
						 uchar var_Max = max(Blue,Green);
						 var_Max = max(var_Max,Red);
						 uchar del = var_Max - var_Min;

						 if (del == 0)
						 {
							 H = 0;
							 S = 0;
						 }else
						 {
							 V = ((double)var_Max)/255;
							 if (var_Max == Red){ H = 60 * (Green - Blue)/del; }
							 if (var_Max == Green){ H = 120 + 60 * (Blue - Red)/del; }
							 if (var_Max == Blue){ H = 240 + 60 * (Red - Green)/del; }							 
						 }

						 if(var_Max == 0)
						 {
							 S = 0;
						 }else
						 {
							 S = (((double)del)/((double)var_Max))*100;
						 }

						 if(mode == 1)
						 {
							 if(differencePoint[i*Proces->widthStep+j] != 0)
								 {
									 if ((H < H_Min || H > H_Max) && abs(H - differencePoint[i*Proces->widthStep+j]) > diff_Gate)
									 {
										DiffImg->imageData[i*Proces->widthStep+j] = Blue;
										DiffImg->imageData[i*Proces->widthStep+j+1] = Green;
										DiffImg->imageData[i*Proces->widthStep+j+2] = Red;
									 }else
									 {
										DiffImg->imageData[i*Proces->widthStep+j] = 255;
										DiffImg->imageData[i*Proces->widthStep+j+1] = 255;
										DiffImg->imageData[i*Proces->widthStep+j+2] = 255;
									}
								 }
						 }

						 if (H > H_Min && H < H_Max && S >10)
						 {
							 if (mode ==0)
							 {
								differencePoint[i*Proces->widthStep+j] = H;
							 } 					 

						 } 
						 else
						 {
							 Proces->imageData[i*Proces->widthStep+j] = 255;
							 Proces->imageData[i*Proces->widthStep+j+1] = 255;
							 Proces->imageData[i*Proces->widthStep+j+2] = 255;

							 if (mode ==0)
							 {
								differencePoint[i*Proces->widthStep+j] = 0;
							 }
						 }						 
					 }
				 }

				 if (mode == 0)
				 {
					 comparedImg_Plant = cvCreateImage(cvGetSize(Proces),IPL_DEPTH_8U,3);

					 comparedImg_Plant = cvCloneImage(Proces);

					 pictureBox2->Image  = gcnew System::Drawing::Bitmap
						 (comparedImg_Plant->width,comparedImg_Plant->height,comparedImg_Plant->widthStep,
						 System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) comparedImg_Plant->imageData);
					 pictureBox2->Refresh();

					 cvSaveImage("comparedImg_Plant.jpg",comparedImg_Plant);
				 } 
				 else
				 {
					 t2 = GetTickCount();

					 DiffImg_Edge = cvCreateImage(cvGetSize(DiffImg),IPL_DEPTH_8U,1);

					 cvCvtColor(comparedImg,DiffImg_Edge,CV_BGR2GRAY);

					 cvSaveImage("comparedImg_PlantGRAY.jpg",DiffImg_Edge);

					 FinalImg = cvCloneImage(src);

					 cvMorphologyEx(DiffImg,DiffImg,tmp,NULL,CV_MOP_OPEN,1);

					 cvSmooth(DiffImg,DiffImg);

					 /*cvNamedWindow("Show Image",1);
					 cvShowImage("Show Image",DiffImg);*/

					 cvCvtColor(DiffImg,DiffImg_Edge,CV_BGR2GRAY);

					 cvCanny( DiffImg_Edge, DiffImg_Edge, 150, 300);

					 //cvSaveImage("DiffImg_Edge.jpg",DiffImg_Edge);

					 int contour_num = cvFindContours(DiffImg_Edge, storage, &contour, sizeof(CvContour), CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE );  
				     
					 CvSeq *_contour = contour;   
					 double maxarea = 0;  
					 
					 m = 0;

					 comparedImg_Plant_Ab = cvCloneImage(comparedImg_Plant);
					   
					 for( ; contour != 0; contour = contour->h_next )    
					 {    
  
						 double tmparea = fabs(cvContourArea(contour));  
						 if(tmparea < minarea)     
						 {    
							 cvSeqRemove(contour, 0); // 删除面积小于设定值的轮廓
  
							 continue;  
						 }    
						 
						 m++;  
						 
						 CvScalar color = CV_RGB( 255, 0, 0 );  
  
						 cvDrawContours(FinalImg, contour, color, color, -1, 2, 8);//绘制外部和内部的轮廓
						 cvDrawContours(comparedImg_Plant_Ab, contour, color, color, -1, 2, 8);
						 cvDrawContours(DiffImg, contour, color, color, -1, 2, 8);

						 labError->Text = "發生異常";
						 timer1->Enabled = true;

						 pictureBox2->Image  = gcnew System::Drawing::Bitmap
						 (comparedImg_Plant_Ab->width,comparedImg_Plant_Ab->height,comparedImg_Plant_Ab->widthStep,
						 System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) comparedImg_Plant_Ab->imageData);
					 }

					 if(m ==0)
					 {
						 labError->Text = "無異常";
						 labError->ForeColor = System::Drawing::Color::Black;

						 pictureBox2->Image  = gcnew System::Drawing::Bitmap
						 (comparedImg_Plant->width,comparedImg_Plant->height,comparedImg_Plant->widthStep,
						 System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) comparedImg_Plant->imageData);
					 }

					 pictureBox4->Image  = gcnew System::Drawing::Bitmap
						 (DiffImg->width,DiffImg->height,DiffImg->widthStep,
						 System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) DiffImg->imageData);
					 pictureBox4->Refresh();

					 pictureBox5->Image  = gcnew System::Drawing::Bitmap
						 (FinalImg->width,FinalImg->height,FinalImg->widthStep,
						 System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) FinalImg->imageData);
					 pictureBox5->Refresh();

					 pictureBox2->Refresh();

					 cvSaveImage("comparedImg_Plant.jpg",comparedImg_Plant_Ab);

					 //cvSaveImage("DiffImg.jpg",DiffImg);

					 cvSaveImage("FinalImg.jpg",FinalImg);
				 }
				 cvReleaseImage(&Proces);
				 cvReleaseImage(&DiffImg);
			 }
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 timer1->Enabled = false;

			 if (listBox1->SelectedIndex >=0)
			 {
				 InputImg = cvLoadImage(FilesName[listBox1->SelectedIndex]);

				 cutPlantandComparing(InputImg,1);

				 pictureBox3->Image  = gcnew System::Drawing::Bitmap
					 (InputImg->width,InputImg->height,InputImg->widthStep,
					 System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) InputImg->imageData);
				 pictureBox3->Refresh();
			 }
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 timer1->Enabled = false;
			 H_Max = Int32::Parse(textBox1->Text);
			 H_Min = Int32::Parse(textBox2->Text);
			 diff_Gate = Int32::Parse(textBox3->Text);
			 minarea = Int32::Parse(textBox4->Text);

			 cutPlantandComparing(comparedImg,0);
			 
			 if(PictureNum > 1)
			 {
				cutPlantandComparing(InputImg,1);
			 }		 
		 }
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
		 {
			 cvReleaseImage(&comparedImg);
			 cvReleaseImage(&comparedImg_Plant);
			 cvReleaseImage(&InputImg);
			 
			 cvReleaseImage(&DiffImg_Edge);
			 cvReleaseImage(&FinalImg);
			 cvReleaseMemStorage(&storage);
		 }
private: System::Void pictureBox5_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 cvNamedWindow("FinalImg");
			 cvShowImage("FinalImg", FinalImg);
		 }
private: System::Void pictureBox4_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 cvNamedWindow("DiffImg");
			 cvShowImage("DiffImg", DiffImg);
		 }
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 cvNamedWindow("comparedImg_Plant");

			 if(m == 0)
			 {
				 cvShowImage("comparedImg_Plant", comparedImg_Plant);
			 }
			 else{ cvShowImage("comparedImg_Plant", comparedImg_Plant_Ab); }
			 
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
		 {
			 switch(state)
			 {
				 case 0:
					 labError->ForeColor = System::Drawing::Color::Red;
					 state = 1;
					 break;
				 case 1:
					 labError->ForeColor = System::Drawing::Color::Black;
					 state = 0;
					 break;
			 }
			 
		 }
};
}

