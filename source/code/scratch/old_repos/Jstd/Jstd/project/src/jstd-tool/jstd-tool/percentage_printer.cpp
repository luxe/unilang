#include "percentage_printer.hpp"
#include "utilities.hpp"


//constructor
Percentage_Printer::Percentage_Printer(std::string const& task, int (*function_to_get_number_of_steps)() )
  : m_task(task)
  , m_current_step(0)

	{
		m_line_printer.Refresh_Current_Line(m_task + " [" + std::to_string(m_current_step) + "/???] 0% ");
		m_number_of_steps = function_to_get_number_of_steps();
		m_line_printer.Refresh_Current_Line(m_task + " [" + std::to_string(m_current_step) + "/" + std::to_string(m_number_of_steps) + "] 0% ");

	}

//transformers
void Percentage_Printer::Update() {
	++m_current_step;
	if (m_current_step == m_number_of_steps+1) {
		Print_End_Message();
	}else if (m_current_step > m_number_of_steps+1){
		std::cerr << "overstepped your percentage for " <<  m_task <<  "!\n";
		exit(EXIT_FAILURE);
	}else{
		int percentage = (static_cast<float>(m_current_step)/static_cast<float>(m_number_of_steps)) * 100.0;
		m_line_printer.Refresh_Current_Line(m_task + " [" + std::to_string(m_current_step) + "/" + std::to_string(m_number_of_steps) + "] " + std::to_string(percentage) + "% ");
	}

	return;
}
void Percentage_Printer::Print_End_Message() {
	int real_size = m_task.size() + 11;
	m_line_printer.End_Current_Line(m_task + " [" + colorize_forground("COMPLETE", 118) + "]", real_size);
	return;
}
