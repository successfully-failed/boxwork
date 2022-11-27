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
//
//
// after the line 140 there is propper functioning automated box class, 
// which should be used
//-------------------------------------------------------------------------------|


class Box_Base 
{	//---------------------structures of the class ------------------------------
	struct variable 
	{
		int var_i = 0;
		char var_cr = 'a';
		double var_d = 0.0;
		std::string var_s = "";

		void refresher()
		{
			var_i =0;
			var_cr = 'a';
			var_d = 0.0;
			var_s = "";
		}
	};
	
		//ports, that connect box with others
	class ports
	{
		private:
			
			variable inputfield;
			variable outputfield;
			variable* connector = NULL;
		public:	
			ports()
			{
				inputfield.refresher();
				outputfield.refresher();
				connector =  nullptr; 
			}	
			void setimput (variable choice)	
			{
				choice = inputfield;
			}

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
			

			void connection_setter(bool opt, variable other_port)
			{
				if(opt == true)
				{
					connector = & other_port;
				}
				else 
				{
					connector = nullptr;
				}
			}

			void refresher()
			{
				inputfield.refresher();
				outputfield.refresher();
				connector = nullptr;
			}

			~ports()
			{
				delete connector;
			}

	};

//----------------------------------------Atributes of the class---------------
	public: 
		Box_Base() = default; 
		//id of the box
		std::string id;
		//4 ports 1--output 2,3,4--input
			
	private:
	 //variable stored and processed inside a box
		variable var1; //export variable 
		variable var2; //
		variable var3; //import variables
		variable var4; //
		ports port1;
		ports port2;
		ports port3;
		ports port4;	
//--------------------------------------------mathods of the class-----------------------------
	public:
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
		void cleaner (variable variableofchoice)
		{
			variableofchoice.refresher();
		}




};




//--------------------------------------------To do-----------------------
//the functional class should be able to :
// a) connect to others 
// b) create an interface for the body 
// c) make the interface with the builder -- object that will pass informations like port's adress to others 
//
//



//class Box : public Box_Base {

//}








