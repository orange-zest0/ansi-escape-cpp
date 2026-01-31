#include "ANSI_tyuusyou.h"


#include <iostream>
#include <chrono>
#include <thread>


int main(int argc, char *argv[])
{
	
		cursor::set(1,8);
	for(int i=0;i<1000;++i){

    
		std::cout<<"試行回数";
		color::set(color_All::color_all::Red);
		
		std::cout<<i+1<<"回"<<std::flush;
         
				
			color::Reset();		
	
	
			//約10ms止める命令。			
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
//行を先頭に戻すと、初期で移動した8列分が無くなってしまうので、row_headで初期で移動した分を書いて下さい。そうすることで、同じ位置に戻ります。
//今回は右に移動するプログラムしか書いていませんので、必要に応じて追加してください。    
		Ornament::row_head(8);		
	}
return 0;
}
