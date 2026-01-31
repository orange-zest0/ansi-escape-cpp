#include "ANSI_tyuusyou.h"



#include <iostream>
#include <unordered_map>



namespace color_in{


Color_write::Color_write():
Add_color{
	{color_All::color_all::Black,[](){std::cout<<"\x1b[30m";}}
	,{color_All::color_all::Red,[](){std::cout<<"\x1b[31m";}}
	,{color_All::color_all::Green,[](){std::cout<<"\x1b[32m";}}
	,{color_All::color_all::Yellow,[](){std::cout<<"\x1b[33m";}}
	,{color_All::color_all::Blue,[](){std::cout<<"\x1b[34m";}}
	,{color_All::color_all::Magenta,[](){std::cout<<"\x1b[35m";}}
	,{color_All::color_all::Cyan,[](){std::cout<<"\x1b[36m";}}
	,{color_All::color_all::White,[](){std::cout<<"\x1b[37m";}}
	
	}
	
    {}
    


//virtualは宣言で付けているので定義では書かなくて良い。
 void  Color_write::Color_write_select(const color_All::color_all name)
{
if(Add_color.count(name))Add_color[name]();
	
	else
	{
		//赤
	std::cout<<"\x1b[31m";	std::cout<<"\nその文字色は出せません。\n";
	std::cout<<"\x1b[0m";	
		}
	
	
}//Color_write_select



  void  Color_write::Color_select(const color_All::color_all name)
{

	Color_write_select(name);
	
	}


void Color_write::Color_clear()
{
	std::cout<<"\033[0m";
	}



   //コンストラクタ
	Color_back::Color_back():
Add_color{
	{color_All::color_all::Black,[](){std::cout<<"\x1b[40m";}}
	,{color_All::color_all::Red,[](){std::cout<<"\x1b[41m";}}
	,{color_All::color_all::Green,[](){std::cout<<"\x1b[42m";}}
	,{color_All::color_all::Yellow,[](){std::cout<<"\x1b[43m";}}
	,{color_All::color_all::Blue,[](){std::cout<<"\x1b[44m";}}
	,{color_All::color_all::Magenta,[](){std::cout<<"\x1b[45m";}}
	,{color_All::color_all::Cyan,[](){std::cout<<"\x1b[46m";}}
	,{color_All::color_all::White,[](){std::cout<<"\x1b[47m";}}
	}	
	
	{}
	
	void  Color_back::Color_write_select(const color_All::color_all name)  {
	
if(Add_color.count(name))Add_color[name]();
else
{
	//赤
	std::cout<<"\x1b[31m";
	std::cout<<"\nその背景色は出せません。\n";
    std::cout<<"\x1b[0m";
}
	
	}//Color_write_select
	
	
	void  Cursor::cursor_select( int down_row, int Right, int up_row, int Left)
{
	
	do{
		if(down_row>0){
		std::cout<<"\033["<<down_row<<"B"<<std::flush;
		   
		}//if

//呼び出すときに0を使えなくなってしまう。
	   if(Right>0){
		std::cout<<"\033["<<Right<<"C"<<std::flush;
		   
		}

		
		if(up_row>0){
		std::cout<<"\033["<<up_row<<"A"<<std::flush;
		   
		}
//仕様により、Rightを0とすると、内部的に1と補正される事があります。Leftを1としても、abs(Right-Left)=0と処理され、動かない事があります。なので、もし動かないなど、バグがでた時はLeftを2としてください。すると、abs(Right-Left)=1から1と処理され狙いとあった動きになります。
		if(Left>0){
		std::cout<<"\033["<<Left<<"D"<<std::flush;
		}//if
	}while(false);//do
	
	
}//Color_write_select

void  Cursor::cursor_select_row_EXC(int Right)
{
	if(Right>-1 ){
		std::cout<<"\033["<<Right<<"C"<<std::flush;
		   
		}//if
	}

//使えない可能性があります。
	int& Cursor::save_hoji()
	{
		//静的初期化でゼロになります。
		static int S;
	
		return S;
		}
	
	
	//使えない可能性があります。
	void Cursor::save( int text_number)
	{
		
		
		this->save_hoji()=text_number;
		std::cout<<"\033[s";
	//	return this->save_hoji()=text_number;
		}
	//使えない可能性があります。
	void Cursor::paste()
	{
	int test=save_hoji();
		
	std::cout<<"\033[u";
		if(test!=-1){
		std::cout<<"\033["<<test<<"C";
		}//if
	}
	void Cursor::cursor_Left_up()
		{
			
		std::cout<<"\033[H";	
			
			}

	
	
	
		
Others::Others():
		clear_Se{
{clear_Select::clear_select::cursor_rowE,[](){std::cout<<"\033[0K";}},			
{clear_Select::clear_select::rowHE_cursor,[](){std::cout<<"\033[1K ";}},			
{clear_Select::clear_select::row_all,[](){std::cout<<"\033[2K ";}},			
{clear_Select::clear_select::cursor_screenE,[](){std::cout<<"\033[0J";}},			
{clear_Select::clear_select::screenHE_cursor,[](){std::cout<<"\033[1J  ";}},		
{clear_Select::clear_select::screen_all,[](){std::cout<<"\033[2J  ";}}
		}
		{}
		
		void Others::row_delete()
		{
			std::cout<<"\033[2K";
			}
		
		void Others::Down_line_class()
		{
			std::cout<<"\033[4m";
			}
		void Others::clear_screen_and_row(const clear_Select::clear_select& CLEAR)
		{
			
		if(clear_Se.count(CLEAR))clear_Se[CLEAR]();	
			
			}//clear_screen_and_row
		void Others::row_Head()
		{
			std::cout<<"\r"<<std::flush;
			
			}//row_head
	
	

	
 static Others& others_kansuu()
{
	//何回呼んでも一回だけ初期化
	static Others O;
	
	return O;
	}		
	
	
static Cursor& cursor_kansuu()
{
	//何回呼んでも一回だけ初期化
	static Cursor C;
	
	return C;
	}	

	static Color_write& write_and_back(bool Back)
	{
	
        static Color_write W;
		static Color_back B;
		
			if(Back)return B;
		return W;
		}//write_and_back
		
}//namespace_in
		

namespace color{
	
	void set(const color_All::color_all& name, color_All::color_all all_color)
	{
	
color_in::write_and_back(false).Color_select(name);
if(color_All::color_all::Not!=all_color)
{
		color_in::write_and_back(true).Color_select(all_color);
		
		}//if
		
		}//set
		void back(const color_All::color_all& name)
	{
		
color_in::write_and_back(true).Color_select(name);
		
		}
	void Reset()
	{
		color_in::write_and_back(false).Color_clear();
		
		}	
		
		
	
	}//namespace

namespace cursor{
	
	void set( int down_row,int Right, int up_row, int Left,bool Back)
	{
		
		
color_in::cursor_kansuu().cursor_select(down_row,Right,up_row,Left);
		
		}
		void cursor_left_up()
	{
	
color_in::cursor_kansuu().cursor_Left_up();
		
		}
		
		void Save(int number)
		{
			
		color_in::cursor_kansuu().save(number);	
			
			
			}
		
		void Paste()
		{
			
			color_in::cursor_kansuu().paste();	
			
			}
	
	}//namespace
	
namespace Ornament{
	
	void down_line()
	{
	
color_in::others_kansuu().Down_line_class();
		
		}
		void clear_Screen_row( clear_Select::clear_select CLEAR_GIVE)
	{
		
color_in::others_kansuu().clear_screen_and_row(CLEAR_GIVE);
		
		}
//ヘッダで-1をつけてデフォルトになってます
	void row_head(int Right_row_Exc)
	{
		
color_in::others_kansuu().row_Head();
//行の先頭に戻してから元々動かしていたカーソル分動かしたい場合使う。
color_in::cursor_kansuu().cursor_select_row_EXC(Right_row_Exc);
		
		}	
	
	void row_delete()
	{
color_in::others_kansuu().row_delete();
		}
	
	}//namespace
