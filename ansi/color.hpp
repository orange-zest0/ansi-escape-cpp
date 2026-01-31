#ifndef ANSI_tyuusyou_h
#define ANSI_tyuusyou_h



#include <functional>
#include <unordered_map>



namespace color_All
{
	
	enum class color_all{Black, Red, Green, Yellow, Blue, Magenta, Cyan, White, Not};

	}
	
namespace clear_Select
{
	
	enum class clear_select{cursor_rowE,rowHE_cursor, row_all, cursor_screenE, screenHE_cursor, screen_all};

	}
		
	


namespace color_in{


class Color_write
{	
private:

std::unordered_map<color_All::color_all, std::function<void()>> Add_color;

public:


Color_write();

virtual ~Color_write()=default;


virtual void  Color_write_select(const color_All::color_all name);



  void  Color_select(const color_All::color_all name);


void Color_clear();

};



class Color_back : public Color_write
{	
	private:
	 std::unordered_map<color_All::color_all, std::function<void()>> Add_color;

	public:
   //コンストラクタ
	Color_back();

	
	void  Color_write_select(const color_All::color_all name)  override;
	

};



class Cursor
{
	private:
	
	
	public:
	
	
	void  cursor_select( int down_row, int Right=-1, int up_row=-1, int Left=-1);
	
	//行先頭処理の時に、カーソルを戻すための処理
//	EXCはexclusive(専用)の頭二文字
	void  cursor_select_row_EXC(int Right);
	

//使えない可能性があります。
	int& save_hoji();

	//使えない可能性があります。
	void save( int text_number);

	//使えない可能性があります。
	void paste();

	void cursor_Left_up();
	
	
	};
	
	
	class Others
	{
		private:
		std::unordered_map<clear_Select::clear_select,std::function<void()>> clear_Se;
		public:
		
		Others();
		
		
			void row_delete();
		
		void Down_line_class();
	
		void clear_screen_and_row(const clear_Select::clear_select& CLEAR);
	
		void row_Head();
	
	};
	
}//namespace_in
	

		

namespace color{
	
	void set(const color_All::color_all& name, color_All::color_all all_color=color_All::color_all::Not);

	void back(const color_All::color_all& name);

	void Reset();
		
	}//namespace

namespace cursor{
	
	void set( int down_row, int Right=-1, int up_row=-1, int Left=-1,bool Back=false);
	
		void cursor_left_up();

		
		void Save(int number=-1);
	
		void Paste();
	
	}//namespace
	
namespace Ornament{
	
	void down_line();

	void clear_Screen_row( clear_Select::clear_select CLEAR_GIVE);

	void row_head(int Right_row_Exc=-1);
	
	void row_delete();

	}//namespace





#endif
