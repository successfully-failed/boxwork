#include <iostream>
#include <string>

//-------------------------------------------------------------------------------|
//				MAIN WORKFLOW OF THE BOX
// (1) External indexer creates and connects ports of boxes with connectors
// and connection setters
// (2) fields of ports are changed
// (3) variables of the box are set with things from ports and internals
// (4) outputfield of the is set 
// (5) connector passes the outputfield to other boxes
//
//-------------------------------------------------------------------------------|
struct variable 
{
	int var_i;
	char var_cr;
	double var_d;
	std::string var_s;
};

class Box 
{
	public:
		Box(){};
		//id of the box
		std::string id;
		//setter function. Takes parameters and modifies fields of chosen variable (var_ch)
		void setter (int var_ch /* vaiable of choice */,int int_ch, char char_ch, double double_ch,std::string string_ch)
		{
			//temporary variable a.k.a. buffer
			variable var_temp;
			var_temp.var_i = int_ch;
			var_temp.var_cr = char_ch;
			var_temp.var_d = double_ch;
			var_temp.var_s = string_ch;
			
			switch(var_ch)
			{
			case 1:
				var1 = var_temp;
			case 2:
				var2 = var_temp;
			case 3:
				var3 = var_temp;
			case 4:
				var4 = var_temp;
			}
		}
		//returns variables to their default state
		void cleaner (int var_chc,int int_ch, char char_ch, double double_ch, std::string string_ch)
		{
			variable var_temp;
			var_temp.var_i = 0;    
			var_temp.var_cr= '0';
			var_temp.var_d = 0;
			var_temp.var_s = "";
			
			switch(var_chc)
			{
			case 1:
				var1 = var_temp;
			case 2:
				var2 = var_temp;
			case 3:
				var3 = var_temp;
			case 4:
				var4 = var_temp;
			}

		}


	private:
	 //variable stored and processed inside a box
		variable var1; //export variable 
		variable var2; //
		variable var3; //import variables
		variable var4; //
		
		//ports, that connect box with others
		class ports
		{
		private:	
			variable inputfield;
			variable outputfield;
		public:
			//methods to use from inside
			void setoutput (variable choice/*one of box's variables*/)
			{
			outputfield = choice;
			*connector = outputfield; 
			}
			variable getinput()
			{
			return inputfield;
			}
			//pointer that connects boxes
			variable* connector = NULL;

			void connection_setter(bool opt, variable other_port)
			{
			connector = & other_port;
			}
		};
		//4 ports 1--output 2,3,4--input
	public:
		ports port1;
		ports port2;
		ports port3;
		ports port4;
};
