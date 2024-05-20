#include "FordFulkersonAlgorithm.h"

using namespace System;

using namespace System::Windows::Forms;

[STAThreadAttribute]

void Main(cli::array<String^>^ args) {

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	FordFulkersonAlgorithm::FordFulkersonAlgorithm MyForm;

	Application::Run(% MyForm);

}