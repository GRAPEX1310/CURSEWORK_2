#pragma once
#include "VertexList.h"
#include "EdgeList.h"
#include "Solver.h"
#include <msclr\marshal_cppstd.h>

namespace FordFulkersonAlgorithm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Сводка для FordFulkersonAlgorithm
	/// </summary>
	public ref class FordFulkersonAlgorithm : public System::Windows::Forms::Form
	{
	public:
		FordFulkersonAlgorithm(void)
		{
			InitializeComponent();
		}

		VertexList^ vertexList;
		EdgeList^ edgeList;
		bool isPanelMove;
		bool makeConnection;
		Point mousePoint;
		Label^ activelabel;
		Graphics^ g;

	private: System::Windows::Forms::Label^ shiftLabel;

	public:

	private: System::Windows::Forms::PictureBox^ lineBox;
	private: System::Windows::Forms::TextBox^ weightTextBox;
	private: System::Windows::Forms::Label^ weightLabel;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ startVertexTextBox;
	private: System::Windows::Forms::TextBox^ finalVertexTextBox;
	private: System::Windows::Forms::Label^ startEdgeLabel;
	private: System::Windows::Forms::TextBox^ startEdgeTextBox;
	private: System::Windows::Forms::Label^ endEdgeLabel;
	private: System::Windows::Forms::TextBox^ endEdgeTextBox;
	private: System::Windows::Forms::Button^ applyButton;


	public:

	public:

	public:
		bool hasActiveLabel;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FordFulkersonAlgorithm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ checkButton;
	protected:


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ answerLabel;

	private: System::Windows::Forms::Button^ addButton;
	private: System::Windows::Forms::Button^ clearButton;





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
			this->checkButton = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->answerLabel = (gcnew System::Windows::Forms::Label());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->lineBox = (gcnew System::Windows::Forms::PictureBox());
			this->shiftLabel = (gcnew System::Windows::Forms::Label());
			this->weightTextBox = (gcnew System::Windows::Forms::TextBox());
			this->weightLabel = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->startVertexTextBox = (gcnew System::Windows::Forms::TextBox());
			this->finalVertexTextBox = (gcnew System::Windows::Forms::TextBox());
			this->startEdgeLabel = (gcnew System::Windows::Forms::Label());
			this->startEdgeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->endEdgeLabel = (gcnew System::Windows::Forms::Label());
			this->endEdgeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->applyButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lineBox))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label1->Location = System::Drawing::Point(-3, 424);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(792, 147);
			this->label1->TabIndex = 0;
			// 
			// checkButton
			// 
			this->checkButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->checkButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkButton->Location = System::Drawing::Point(318, 522);
			this->checkButton->Name = L"checkButton";
			this->checkButton->Size = System::Drawing::Size(126, 27);
			this->checkButton->TabIndex = 2;
			this->checkButton->Text = L"Проверить";
			this->checkButton->UseVisualStyleBackColor = false;
			this->checkButton->Click += gcnew System::EventHandler(this, &FordFulkersonAlgorithm::checkButton_Click);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(530, 530);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(242, 23);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Результат:";
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(-3, 423);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(792, 1);
			this->label4->TabIndex = 4;
			// 
			// answerLabel
			// 
			this->answerLabel->AutoSize = true;
			this->answerLabel->BackColor = System::Drawing::SystemColors::ControlLight;
			this->answerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->answerLabel->ForeColor = System::Drawing::Color::Black;
			this->answerLabel->Location = System::Drawing::Point(611, 530);
			this->answerLabel->Name = L"answerLabel";
			this->answerLabel->Size = System::Drawing::Size(11, 16);
			this->answerLabel->TabIndex = 5;
			this->answerLabel->Text = L"-";
			// 
			// addButton
			// 
			this->addButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->addButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addButton->Location = System::Drawing::Point(12, 522);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(147, 27);
			this->addButton->TabIndex = 6;
			this->addButton->Text = L"Добавить элемент";
			this->addButton->UseVisualStyleBackColor = false;
			this->addButton->Click += gcnew System::EventHandler(this, &FordFulkersonAlgorithm::addButton_Click);
			// 
			// clearButton
			// 
			this->clearButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->clearButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->clearButton->Location = System::Drawing::Point(165, 522);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(147, 27);
			this->clearButton->TabIndex = 7;
			this->clearButton->Text = L"Очистить";
			this->clearButton->UseVisualStyleBackColor = false;
			this->clearButton->Click += gcnew System::EventHandler(this, &FordFulkersonAlgorithm::clearButton_Click);
			// 
			// lineBox
			// 
			this->lineBox->Location = System::Drawing::Point(0, 0);
			this->lineBox->Name = L"lineBox";
			this->lineBox->Size = System::Drawing::Size(789, 527);
			this->lineBox->TabIndex = 8;
			this->lineBox->TabStop = false;
			// 
			// shiftLabel
			// 
			this->shiftLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->shiftLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->shiftLabel->Location = System::Drawing::Point(646, 454);
			this->shiftLabel->Name = L"shiftLabel";
			this->shiftLabel->Size = System::Drawing::Size(126, 27);
			this->shiftLabel->TabIndex = 9;
			this->shiftLabel->Text = L"Shift";
			this->shiftLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->shiftLabel->Visible = false;
			// 
			// weightTextBox
			// 
			this->weightTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->weightTextBox->Location = System::Drawing::Point(165, 487);
			this->weightTextBox->Name = L"weightTextBox";
			this->weightTextBox->Size = System::Drawing::Size(76, 24);
			this->weightTextBox->TabIndex = 10;
			// 
			// weightLabel
			// 
			this->weightLabel->AutoSize = true;
			this->weightLabel->BackColor = System::Drawing::SystemColors::ControlLight;
			this->weightLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->weightLabel->Location = System::Drawing::Point(16, 490);
			this->weightLabel->Name = L"weightLabel";
			this->weightLabel->Size = System::Drawing::Size(143, 18);
			this->weightLabel->TabIndex = 11;
			this->weightLabel->Text = L"Введите вес ребра:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(44, 458);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(115, 18);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Номер истока: ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(247, 457);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(107, 18);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Номер стока: ";
			// 
			// startVertexTextBox
			// 
			this->startVertexTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->startVertexTextBox->Location = System::Drawing::Point(165, 454);
			this->startVertexTextBox->Name = L"startVertexTextBox";
			this->startVertexTextBox->Size = System::Drawing::Size(76, 24);
			this->startVertexTextBox->TabIndex = 14;
			// 
			// finalVertexTextBox
			// 
			this->finalVertexTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->finalVertexTextBox->Location = System::Drawing::Point(356, 455);
			this->finalVertexTextBox->Name = L"finalVertexTextBox";
			this->finalVertexTextBox->Size = System::Drawing::Size(76, 24);
			this->finalVertexTextBox->TabIndex = 15;
			// 
			// startEdgeLabel
			// 
			this->startEdgeLabel->AutoSize = true;
			this->startEdgeLabel->BackColor = System::Drawing::SystemColors::ControlLight;
			this->startEdgeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->startEdgeLabel->Location = System::Drawing::Point(247, 490);
			this->startEdgeLabel->Name = L"startEdgeLabel";
			this->startEdgeLabel->Size = System::Drawing::Size(112, 18);
			this->startEdgeLabel->TabIndex = 16;
			this->startEdgeLabel->Text = L"Номер начала:";
			// 
			// startEdgeTextBox
			// 
			this->startEdgeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->startEdgeTextBox->Location = System::Drawing::Point(356, 487);
			this->startEdgeTextBox->Name = L"startEdgeTextBox";
			this->startEdgeTextBox->Size = System::Drawing::Size(76, 24);
			this->startEdgeTextBox->TabIndex = 17;
			// 
			// endEdgeLabel
			// 
			this->endEdgeLabel->AutoSize = true;
			this->endEdgeLabel->BackColor = System::Drawing::SystemColors::ControlLight;
			this->endEdgeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->endEdgeLabel->Location = System::Drawing::Point(438, 490);
			this->endEdgeLabel->Name = L"endEdgeLabel";
			this->endEdgeLabel->Size = System::Drawing::Size(104, 18);
			this->endEdgeLabel->TabIndex = 18;
			this->endEdgeLabel->Text = L"Номер конца:";
			// 
			// endEdgeTextBox
			// 
			this->endEdgeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->endEdgeTextBox->Location = System::Drawing::Point(546, 487);
			this->endEdgeTextBox->Name = L"endEdgeTextBox";
			this->endEdgeTextBox->Size = System::Drawing::Size(76, 24);
			this->endEdgeTextBox->TabIndex = 19;
			// 
			// applyButton
			// 
			this->applyButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->applyButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->applyButton->Location = System::Drawing::Point(646, 487);
			this->applyButton->Name = L"applyButton";
			this->applyButton->Size = System::Drawing::Size(126, 27);
			this->applyButton->TabIndex = 20;
			this->applyButton->Text = L"Применить";
			this->applyButton->UseVisualStyleBackColor = false;
			this->applyButton->Click += gcnew System::EventHandler(this, &FordFulkersonAlgorithm::applyButton_Click);
			// 
			// FordFulkersonAlgorithm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->applyButton);
			this->Controls->Add(this->endEdgeTextBox);
			this->Controls->Add(this->endEdgeLabel);
			this->Controls->Add(this->startEdgeTextBox);
			this->Controls->Add(this->startEdgeLabel);
			this->Controls->Add(this->finalVertexTextBox);
			this->Controls->Add(this->startVertexTextBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->weightLabel);
			this->Controls->Add(this->weightTextBox);
			this->Controls->Add(this->shiftLabel);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->answerLabel);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->checkButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lineBox);
			this->KeyPreview = true;
			this->Name = L"FordFulkersonAlgorithm";
			this->Text = L"FordFulkersonAlgorithm";
			this->Load += gcnew System::EventHandler(this, &FordFulkersonAlgorithm::FFA_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FordFulkersonAlgorithm::FFA_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FordFulkersonAlgorithm::FFA_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lineBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma endregion
private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::Label^ label = gcnew System::Windows::Forms::Label();
		label->AutoSize = false;
		label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		label->ForeColor = Color::Black;
		label->Size = System::Drawing::Size(40, 40);
		label->Location = System::Drawing::Point(100, 100);
		label->Text = System::Convert::ToString(vertexList->getSize());
		label->BackColor = System::Drawing::SystemColors::ControlLight;
		label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

		if (hasActiveLabel) {
			activelabel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		}

		activelabel = label;
		hasActiveLabel = true;

		label->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FordFulkersonAlgorithm::customLabel_MouseDown);
		label->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FordFulkersonAlgorithm::customLabel_MouseUp);
		label->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FordFulkersonAlgorithm::customLabel_MouseMove);

		this->Controls->Add(label);
		label->BringToFront();
		bringGeneralControllersToFront();

		Vertex^ cell = gcnew Vertex(vertexList->getSize());
		cell->setLabel(label);

		this->vertexList->addElem(cell);
	}

private: System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < vertexList->getSize(); i++) {
		Controls->Remove(vertexList->getVertex(i)->label);
	}
	for (int i = 0; i < edgeList->getSize(); i++) {
		Controls->Remove(edgeList->getEdge(i)->label);
	}

	vertexList->clear();
	edgeList->clear();

	reDraw(true);
}

private: System::Void checkButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (vertexList->getSize() == 0 || endEdgeLabel->Text->Length == 0 || endEdgeLabel->Text->Length == 0) {
		answerLabel->Text = "-";
		answerLabel->ForeColor = Color::Black;
		return;
	}

	if (edgeList->getSize() == 0) {
		answerLabel->Text = "0";
		answerLabel->ForeColor = Color::Black;
		return;
	}

	int start = stoi(msclr::interop::marshal_as<std::string>(startVertexTextBox->Text));
	int end = stoi(msclr::interop::marshal_as<std::string>(finalVertexTextBox->Text));
	for (int i = 0; i < edgeList->getSize(); i++) {
		if (edgeList->getEdge(i)->weight == -1) {
			answerLabel->Text = "-";
			answerLabel->ForeColor = Color::Black;
			return;
		}
	}
	Solver^ solver = gcnew Solver();
	int result = solver->solve(start, end, vertexList->getSize(), edgeList->getSize(), edgeList->getList());

	answerLabel->Text = msclr::interop::marshal_as<System::String^>(to_string(result));
}

private: System::Void customLabel_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Label^ label = (Label^)sender;

	if (hasActiveLabel && !activelabel->Text->Equals(label->Text)) {
		activelabel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;

		if (makeConnection) {
			addLine(label);

			reDraw(true);
		}

		activelabel = label;
		label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	}
	else {
		hasActiveLabel = true;

		activelabel = label;
		label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

		isPanelMove = true;
		mousePoint = e->Location;
	}
}

private: System::Void customLabel_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (isPanelMove) {
		isPanelMove = false;
	}
}

private: System::Void customLabel_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (isPanelMove) {
		Label^ label = (Label^)sender;
		Vertex^ cell = vertexList->getVertex(stoi(msclr::interop::marshal_as<std::string>(label->Text)));

		label->Top = label->Top + (e->Y - mousePoint.Y);
		label->Left = label->Left + (e->X - mousePoint.X);

		reDraw(true);
	}
}

private: System::Void FFA_Load(System::Object^ sender, System::EventArgs^ e) {
	hasActiveLabel = false;
	makeConnection = false;
	vertexList = gcnew VertexList();
	edgeList = gcnew EdgeList();
	g = lineBox->CreateGraphics();
}

private: System::Void FFA_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Delete && hasActiveLabel) {
		int num = stoi(msclr::interop::marshal_as<std::string>(activelabel->Text));

		Vertex^ cell = vertexList->getVertex(num);

		for (int i = 0; i < vertexList->getSize(); i++) {
			Vertex^ currentCell = vertexList->getVertex(i);

			for (int j = 0; j < currentCell->adjacent.size(); i++) {
				auto edge = currentCell->adjacent[j];
				if (edge->start == num || edge->end == num) {
					currentCell->adjacent.erase(currentCell->adjacent.begin() + j);
				}
			}

			if (currentCell->hasNext && currentCell->getNext()->Equals(cell)) {
				currentCell->hasNext = false;
			}
		}

		if (cell->hasNext) {
			Vertex^ nextCell = cell->getNext();

			nextCell->hasPrev = false;
		}

		vertexList->eraseElem(num);
		for (int i = 0; i < edgeList->getSize(); i++) {
			auto curr = edgeList->getEdge(i);
			if (curr->start == num || curr->end == num) {
				edgeList->eraseElem(i);
			}
		}

		Controls->Remove(activelabel);

		vertexList->renumerate();

		reDraw(true);

		hasActiveLabel = false;
	}
	if (e->KeyCode == Keys::ShiftKey) {
		makeConnection = true;
		shiftLabel->Visible = true;
	}
}

private: System::Void FFA_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::ShiftKey) {
		makeConnection = false;
		shiftLabel->Visible = false;
	}
}

private: void bringGeneralControllersToFront() {
	
	//labels
	label1->BringToFront();
	label3->BringToFront();
	label4->BringToFront();
	label5->BringToFront();
	label6->BringToFront();
	answerLabel->BringToFront();
	weightLabel->BringToFront();
	startEdgeLabel->BringToFront();
	endEdgeLabel->BringToFront();
	shiftLabel->BringToFront();

	//textBoxes
	weightTextBox->BringToFront();
	startVertexTextBox->BringToFront();
	startEdgeTextBox->BringToFront();
	endEdgeTextBox->BringToFront();
	finalVertexTextBox->BringToFront();

	//buttons
	applyButton->BringToFront();
	addButton->BringToFront();
	clearButton->BringToFront();
	checkButton->BringToFront();
}

private: void drawWeight(Vertex^ start, Vertex^ end, int value) {
	int coordX = (start->label->Location.X + end->label->Location.X) / 2;
	int coordY = (start->label->Location.Y + end->label->Location.Y) / 2;

	System::Windows::Forms::Label^ label = gcnew System::Windows::Forms::Label();
	label->AutoSize = true;
	label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	label->ForeColor = Color::Black;
	label->Size = System::Drawing::Size(200, 200);
	label->Location = System::Drawing::Point(coordX, coordY);
	label->Text = System::Convert::ToString(value);
	label->BackColor = System::Drawing::SystemColors::ControlDark;
	label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

	if (hasActiveLabel) {
		activelabel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
	}

	activelabel = label;
	hasActiveLabel = true;

	this->Controls->Add(label);
	label->BringToFront();
	bringGeneralControllersToFront();

	Edge^ edge = gcnew Edge(start->getId(), end->getId(), -1);
	edge->setLabel(label);

	for (int i = 0; i < vertexList->getSize(); i++) {
		if (edge->start == vertexList->getVertex(i)->getId() || edge->end == vertexList->getVertex(i)->getId()) {
			auto vertex = vertexList->getVertex(i);
			vertex->adjacent.push_back(edge);
		}
	}

	edgeList->addElem(edge);
}

private: void addLine(Label^ endLabel) {
	makeConnection = false;
	shiftLabel->Visible = false;
	//достаем номера
	int numActive = stoi(msclr::interop::marshal_as<std::string>(activelabel->Text));
	int numNext = stoi(msclr::interop::marshal_as<std::string>(endLabel->Text));
	//обновляем списки
	vertexList->getVertex(numActive)->nextLabel = endLabel;

	
	auto active = vertexList->getVertex(numActive);
	active->setNext(vertexList->getVertex(numNext));
	active->hasNext = true;

	auto next = vertexList->getVertex(numNext);
	next->setPrev(vertexList->getVertex(numActive));
	next->hasPrev = true;

	drawWeight(vertexList->getVertex(numActive), vertexList->getVertex(numActive)->getNext(), -1);
}

private: void reDraw(bool reDrawEdge) {

	g->Clear(System::Drawing::SystemColors::Control);
	Pen^ pen = gcnew Pen(Color::Black);

	Pen^ specialPen = gcnew Pen(Color::Red);

	for (int i = 0; i < vertexList->getSize(); i++) {
		Vertex^ cell = vertexList->getVertex(i);
		if (cell->hasNext) {
			for (int j = 0; j < cell->adjacent.size(); j++) {
				auto edge = cell->adjacent[j];
				Vertex^ nextCell;
				if (cell->getId() == edge->start) {
					nextCell = vertexList->getVertex(edge->end);
				}
				else if (cell->getId() == edge->end) {
					nextCell = vertexList->getVertex(edge->start);
				}

				g->DrawLine(pen,
					Point(cell->label->Location.X + 20, cell->label->Location.Y + 20),
					Point(nextCell->label->Location.X + 20, nextCell->label->Location.Y + 20));

				int coordX = (cell->label->Location.X + nextCell->label->Location.X) / 2;
				int coordY = (cell->label->Location.Y + nextCell->label->Location.Y) / 2;
				edge->label->Top = coordY;
				edge->label->Left = coordX;
			}
		}
	}
}

private: System::Void applyButton_Click(System::Object^ sender, System::EventArgs^ e) {

	std::string weightString = msclr::interop::marshal_as<std::string>(weightTextBox->Text);
	int weight = stoi(weightString);

	std::string startString = msclr::interop::marshal_as<std::string>(startEdgeTextBox->Text);
	int start = stoi(startString);

	std::string endString = msclr::interop::marshal_as<std::string>(endEdgeTextBox->Text);
	int end = stoi(endString);
	Edge^ edge;
	for (int i = 0; i < edgeList->getSize(); i++) {
		auto current = edgeList->getEdge(i);
		if (current->start == start && current->end == end) {
			current->weight = weight;
			current->label->Text = msclr::interop::marshal_as<System::String^>(to_string(current->weight));
			edge = current;
		}
	}

	for (int i = 0; i < vertexList->getSize(); i++) {
		auto current = vertexList->getVertex(i);
		for (int j = 0; j < current->adjacent.size(); j++) {
			auto edge = current->adjacent[j];

			if ((edge->start == start && edge->end == end) || edge->start == end && edge->end == start) {
				edge->weight = weight;
				edge->label->Text = msclr::interop::marshal_as<System::String^>(to_string(edge->weight));
			}
		}
	}
}
};
}
