# ansi-escape-cpp
ANSI（文字色変更やカーソル操作など）をそのまま、コードを書かずに扱うためのC++用**小規模ライブラリ**です。

## English.ver

This library provides a simple C++ interface for using ANSI escape sequences,
such as text coloring and cursor control, without writing raw escape codes.

## 出来ること。

C++ で ANSI エスケープシーケンスを簡単に扱うための小さなライブラリです。  
カーソル移動や文字色の変更などを、分かりやすい関数で操作できます。

---

## 特徴 (Features)

- カーソルの移動
- 文字色の変更
- ANSI エスケープシーケンスを直接書かずに操作できます。
- 学習用・簡単なツール向けです。

---

## 使い方 (Usage)

下は簡単な使用例です。

```cpp

#include "ANSI_tyuusyou.h"

#include <iostream>
#include <chrono>
#include <thread>

int main()
{
//1行下げて8列右に。
    cursor::set(1, 8);
    for (int i = 0; i < 10; ++i) {
        std::cout << "試行回数";
        color::set(color_All::color_all::Red);
        std::cout << i + 1 << "回" << std::flush;
//color::setで変えた色を元に戻す。
        color::Reset();
        // 約10ミリ秒スレッドを停止
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
// 行頭に戻る際、リセットされた列を
//補正する為の8です。
//右に移動する分しか作っていません。
        Ornament::row_head(8);
    }//for
    return 0;
}//main
```

## 経緯
ライブラリを作ったことが無かった為、実際に作ってみたいと思ったのがきっかけです。また、使う側での視点や利便性など、分かりやすさを体験してみたかったからです。
---

## License
MIT License
